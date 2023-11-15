#include"TPolynomial.h"

void TPolynomial::BuidPolynomial() {
	int input = -1, _Ratio = 0, _DegConvol = 0, tmp = 0;
	bool flag_out = false;
	while (!flag_out) {
		std::cout << "Create a monomial - 1, stop (any number): ";
		std::cin >> input;
		switch (input) {
		case 1:
			std::cout << "Enter odds: ";
			std::cin >> _Ratio;
			if (_Ratio == 0) break;
			std::cout << "Enter degrees separated by spaces (x, y, z)" << std::endl;
			std::cin >> tmp;
			if (tmp > 9) {
				std::cout << "Degree can't be greater then 9" << std::endl;
				_DegConvol = -1;
				break;
			}
			else if (tmp < 0) {
				std::cout << "Degree can't be less then 0" << std::endl;
				_DegConvol = -1;
				break;
			}
			_DegConvol = tmp * 100;
			std::cin >> tmp;
			if (tmp > 9) {
				std::cout << "Degree can't be greater then 9" << std::endl;
				_DegConvol = -1;
				break;
			}
			else if (tmp < 0) {
				std::cout << "Degree can't be less then 0" << std::endl;
				_DegConvol = -1;
				break;
			}
			_DegConvol += tmp * 10;
			std::cin >> tmp;
			if (tmp > 9) {
				std::cout << "Degree can't be greater then 9" << std::endl;
				_DegConvol = -1;
				break;
			}
			else if (tmp < 0) {
				std::cout << "Degree can't be less then 0" << std::endl;
				_DegConvol = -1;
				break;
			}
			_DegConvol += tmp;
			if (_Ratio == 0) { _Ratio = -1; }
			Polynomial.Push(_Ratio, _DegConvol);
			_Ratio = 0;
			_DegConvol = 0;
			break;
		default:
			flag_out = true;
		}
	}
}

void TPolynomial::Sum1(TPolynomial* _Polynomial) {
	Polynomial.Sum1(&_Polynomial->Polynomial);
}

void TPolynomial::Sum2(TPolynomial* _Polynomial1, TPolynomial* _Polynomial2) {
	Polynomial.Sum2(&_Polynomial1->Polynomial, &_Polynomial2->Polynomial);
}

std::ostream& operator <<(std::ostream& os, const TPolynomial& _Polynomial) {
	os << _Polynomial.Polynomial;
	return os;
}