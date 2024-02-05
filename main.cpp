#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>

#include "Matrix.h"
#include "Tensor.h"
#include "Complex.h"

using namespace std;

int main()
{
	Matrix <Complex> T(2, 2);
	T.set(0, 0, Complex(1, 2));
	T.set(0, 1, Complex(3, 4));
	T.set(1, 0, Complex(5, 6));
	T.set(1, 1, Complex(7, 8));

	cout << T;

	Matrix <int> N(2, 2, 1);
	Matrix <Complex> M;
	cout << '\n' << N;
	M = T + N;
	cout << '\n' << M;

	return 0;
}
