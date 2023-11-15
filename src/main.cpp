#include<iostream>

#include"TPolynomial.h"

int main() {
	std::cout << "Sum polynomials in two ways using lists\n\n";
	TPolynomial a, b, c;
	bool flag_out = false, flag_out_2 = false;
	short input;
	char* for_a = new char[500], *for_b = new char[500];
	std::cout << "Enter first polynomial: " << std::endl;
	a.BuidPolynomial();
	std::cout << "\nEnter second polynomial: " << std::endl;
	b.BuidPolynomial();
	while (!flag_out) {
		std::cout << "\nEnter 1 to add polynomials and write the result into the first polynomial (the first polynomial will be erased) | 2 - to write the amount into a separate variable: ";
		std::cin >> input;
		switch (input) {
		case 1:
			a.Sum1(&b);
			std::cout << "First term (result): " << a << std::endl;
			std::cout << "Second term: " << b << std::endl;
			break;
		case 2:
			c.Sum2(&a,&b);			
			std::cout << "First term: " << a << std::endl;
			std::cout << "Second term: " << b << std::endl;
			std::cout << "Result:" << c << std::endl;
			break;
		default:
			flag_out = true;
		}
	}
	return 0;
}