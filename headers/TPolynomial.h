#pragma once
#include"TList.h"

class TPolynomial {
	TCyclicList Polynomial;
public:
	TPolynomial() = default;
	~TPolynomial() = default;

	void BuidPolynomial();
	void Sum1(TPolynomial*);
	void Sum2(TPolynomial*, TPolynomial*);

	friend std::ostream& operator <<(std::ostream&, const TPolynomial&);
};