#include"TList.h"

TCyclicList::TCyclicList() {
	FictHeadLink = new TLink(0, -1);
	FictHeadLink->pNext = FictHeadLink;
}

TCyclicList::TCyclicList(const TCyclicList& List) {
	FictHeadLink = new TLink(0, -1);
	FictHeadLink->pNext = FictHeadLink;
	TLink* tmp = List.FictHeadLink->pNext;
	while (tmp != List.FictHeadLink) {
		Push(tmp->Ratio, tmp->DegConvol);
		tmp = tmp->pNext;
	}
}

TCyclicList::~TCyclicList() {
	while (!IsEmpty()) {
		Del(FictHeadLink->pNext);
	}
	delete FictHeadLink;
}

void TCyclicList::Del(TLink* adr) {
	if (adr == FictHeadLink) {
		std::cout << "Head link cannot be deleted" << std::endl;
		return;
	}
	TLink* tmp = FictHeadLink;
	while (tmp->pNext != adr) {
		tmp = tmp->pNext;
	}
	tmp->pNext = adr->pNext;
	delete adr;
}

void TCyclicList::Push(int _Ratio, int _DegConvol) {
	if (_Ratio == 0) {
		return;
	}
	TLink* tmp = new TLink(_Ratio, _DegConvol);
	TLink* place = FictHeadLink;
	while (place->pNext->DegConvol > _DegConvol) {
		place = place->pNext;
	}
	if (place->pNext->DegConvol == _DegConvol) {
		place->pNext->Ratio += tmp->Ratio;
		if (place->pNext->Ratio == 0) {
			Del(place->pNext);
		}
	}
	else {
		tmp->pNext = place->pNext;
		place->pNext = tmp;
	}
}

void TCyclicList::Sum1(TCyclicList* List) {
	TLink *flag1 = FictHeadLink->pNext, *flag2 = List->FictHeadLink->pNext, *tmp = new TLink();
	while ((flag1 != FictHeadLink) || (flag2 != List->FictHeadLink)) {
		if (flag1->DegConvol == flag2->DegConvol) { 
			flag1 = flag1->pNext;
			Push(flag2->Ratio, flag2->DegConvol);
			flag2 = flag2->pNext;
		}
		else if (flag1->DegConvol > flag2->DegConvol) {
			flag1 = flag1->pNext;
		}
		else {
			Push(flag2->Ratio, flag2->DegConvol);
			tmp = flag2;
			flag2 = flag2->pNext;
			List->Del(tmp);
		}
	}
}

void TCyclicList::Sum2(TCyclicList* List1, TCyclicList* List2) {
	TCyclicList* LocalRes = new TCyclicList();
	TLink* flag1 = List1->FictHeadLink->pNext, * flag2 = List2->FictHeadLink->pNext;
	while ((flag1 != List1->FictHeadLink) || (flag2 != List2->FictHeadLink)) {
		if (flag1->DegConvol == flag2->DegConvol) {
			LocalRes->Push(flag1->Ratio + flag2->Ratio, flag1->DegConvol);
			flag1 = flag1->pNext;
			flag2 = flag2->pNext;
		}
		else if (flag1->DegConvol > flag2->DegConvol) {
			LocalRes->Push(flag1->Ratio, flag1->DegConvol);
			flag1 = flag1->pNext;
		}
		else if (flag1->DegConvol < flag2->DegConvol) {
			LocalRes->Push(flag2->Ratio, flag2->DegConvol);
			flag2 = flag2->pNext;
		}
	}
	while (!IsEmpty()) {
		Del(FictHeadLink->pNext);
	}
	while (!LocalRes->IsEmpty()) {
		Push(LocalRes->FictHeadLink->pNext->Ratio, LocalRes->FictHeadLink->pNext->DegConvol);
		LocalRes->Del(LocalRes->FictHeadLink->pNext);
	}
}

bool TCyclicList::IsEmpty() {
	return FictHeadLink->pNext == FictHeadLink;
}


std::ostream& operator <<(std::ostream& os, const TCyclicList& List) {
	TCyclicList tmp(List);
	int DegX = tmp.FictHeadLink->pNext->DegConvol / 100, DegY = tmp.FictHeadLink->pNext->DegConvol % 100 / 10, DegZ = tmp.FictHeadLink->pNext->DegConvol % 10;
	if (tmp.FictHeadLink->pNext->DegConvol < 0) { os << 0; return os; }
	if (tmp.FictHeadLink->pNext->DegConvol == 0) { os << tmp.FictHeadLink->pNext->Ratio; return os; }
	if (tmp.FictHeadLink->pNext->Ratio == -1) {
		os << "-";
	}
	else if (tmp.FictHeadLink->pNext->Ratio != 1) os << tmp.FictHeadLink->pNext->Ratio;
	if (DegX == 1) os << "x";
	else if (DegX > 1) os << "(x^" << DegX << ")";
	if ((DegX != 0) && ((DegY != 0) || (DegZ != 0))) os << "*";
	if (DegY == 1) os << "y";
	else if (DegY > 1) os << "(y^" << DegY << ")";
	if ((DegY != 0) && (DegZ != 0)) os << "*";
	if (DegZ == 1) os << "z";
	else if (DegZ > 1) os << "(z^" << DegZ << ")";
	tmp.FictHeadLink->pNext = tmp.FictHeadLink->pNext->pNext;
	DegX = tmp.FictHeadLink->pNext->DegConvol / 100;
	DegY = tmp.FictHeadLink->pNext->DegConvol % 100 / 10;
	DegZ = tmp.FictHeadLink->pNext->DegConvol % 10;
	while (tmp.FictHeadLink->pNext != tmp.FictHeadLink) {
		if (tmp.FictHeadLink->pNext->Ratio > 0) {
			os << " +";
		}
		else {
			os << " -";
			tmp.FictHeadLink->pNext->Ratio = -tmp.FictHeadLink->pNext->Ratio;
		}
		if (tmp.FictHeadLink->pNext->DegConvol == 0) { os << " " << tmp.FictHeadLink->pNext->Ratio; return os; }
		std::cout << " ";
		if (tmp.FictHeadLink->pNext->Ratio != 1) os << tmp.FictHeadLink->pNext->Ratio;
		if (DegX == 1) os << "x";
		else if (DegX > 1) os << "(x^" << DegX << ")";
		if ((DegX != 0) && ((DegY != 0) || (DegZ != 0))) os << "*";
		if (DegY == 1) os << "y";
		else if (DegY > 1) os << "(y^" << DegY << ")";
		if ((DegY != 0) && (DegZ != 0)) os << "*";
		if (DegZ == 1) os << "z";
		else if (DegZ > 1) os << "(z^" << DegZ << ")";
		tmp.FictHeadLink->pNext = tmp.FictHeadLink->pNext->pNext;
		DegX = tmp.FictHeadLink->pNext->DegConvol / 100;
		DegY = tmp.FictHeadLink->pNext->DegConvol % 100 / 10;
		DegZ = tmp.FictHeadLink->pNext->DegConvol % 10;
	}
	return os;
}