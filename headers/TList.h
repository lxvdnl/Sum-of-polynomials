#pragma once
#include<iostream>

class TCyclicList{
private:
	class TLink
	{
	public:
		int Ratio;
		int DegConvol;
		TLink* pNext;
		TLink(int _Ratio = 0, int _DegConvol = -1, TLink* _pNext = NULL) : Ratio(_Ratio), DegConvol(_DegConvol), pNext(_pNext) {};
	};
	TLink* FictHeadLink;
public:
	TCyclicList();
	TCyclicList(const TCyclicList&);
	~TCyclicList();

	void Del(TLink*);
	void Push(int, int);
	void Sum1(TCyclicList*);
	void Sum2(TCyclicList*, TCyclicList*);

	bool IsEmpty();

	friend std::ostream& operator <<(std::ostream&, const TCyclicList&);
};