#include <iostream>
#include <clocale>
#include "Vector.h"
#include "Matrix.h"

int main(){
	int n = 4;
	int m = 4;
	// creating an object
	Matrix a;
	std::cout << "Matrix a:" << std::endl;
	a.print();
	Matrix b(n, m);
	std::cout << "Matrix b:" << std::endl;
	b.print();

	Vector* mtr = new Vector[n];
	double* arr = new double[m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[j] = i+j;
		}
		Vector v(arr, m);
		mtr[i] = v;
	}
	Matrix c(mtr, n, m);
	std::cout << "Matrix c:" << std::endl;
	c.print();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[j] = i + j+1;
		}
		Vector v(arr, m);
		mtr[i] = v;
	}
	Matrix d(mtr, n, m);
	std::cout << "Matrix d:" << std::endl;
	d.print();
	// operator=
	std::cout << "a=b" << std::endl;
	a = b;
	std::cout << "Matrix a:" << std::endl;
	a.print();
	// operator+=
	a += c += d;
	std::cout << "a += c += d" << std::endl;
	std::cout << "Matrix a:" << std::endl;
	a.print();
	std::cout << "Matrix d:" << std::endl;
	d.print();
	std::cout << "Matrix c:" << std::endl;
	c.print();
	// operator*
	b = c * 3;
	std::cout << "b = c * 3" << std::endl;
	std::cout << "Matrix b:" << std::endl;
	b.print();
	// operator/
	b = b / 3;
	std::cout << "b = b / 3" << std::endl;
	std::cout << "Matrix b:" << std::endl;
	c.set_elem(0, 1, 0);
	b.print();
	std::cout << "Transposing the matrix c:" << std::endl;
	// transposition
	c.print();
	c.transpose();
	c.print();

	// operator* matrix
	d = b * c;
	std::cout << "d = b * c" << std::endl;
	std::cout << "Matrix d:" << std::endl;
	d.print();

	// unary operator-
	-b;
	std::cout << "-b" << std::endl;
	std::cout << "Matrix b:" << std::endl;
	b.print();

	// determinant
	Matrix matr(n, m);
	matr.set_elem(0, 0, 1);
	matr.set_elem(1, 0, 1);
	matr.set_elem(2, 0, 5);
	matr.set_elem(0, 1, 1);
	matr.set_elem(1, 1, 3);
	matr.set_elem(1, 2, 1);
	matr.set_elem(2, 2, 2);
	matr.set_elem(3, 2, 2);
	matr.set_elem(2, 3, 5);
	std::cout << "Matrix matr:" << std::endl;
	matr.print();
	double det = matr.determinant();
	std::cout << "Determinant matr:" << std::endl;
	std::cout << det << std::endl;
	delete[] mtr;
	delete[] arr;
	return 0;
}