#include <iostream>
#include <clocale>
#include "Vector.h"
#include "Matrix.h"

// constructors
Matrix::Matrix() {
	n = 1;
	m = 1;
	mtr = new Vector[n];
	Vector a;
	mtr[0] = a;
}

Matrix::Matrix(const int n, const int m) {
	this->m = m;
	this->n = n;
	this->mtr = new Vector[n];
	for (int i = 0; i < n; i++) {
		Vector a(m);
		this->mtr[i] = a;
	}
}

Matrix::Matrix(const Vector* matrix, const int n, const int m) {
	this->m = m;
	this->n = n;
	this->mtr = new Vector[n];
	for (int i = 0; i < n; i++) this->mtr[i] = matrix[i];
	
}

// copy constructor
Matrix::Matrix(const Matrix& matrix) {
	this->m = matrix.m;
	this->n = matrix.n;
	mtr = new Vector[this->n];
	for (int i = 0; i < n; i++) this->mtr[i] = matrix.mtr[i];

}

//operators
Matrix& Matrix::operator=(const Matrix& matrix) {
	if (this == &matrix) return *this;
	this->m = matrix.m;
	this->n = matrix.n;
	delete[] this->mtr;
	this->mtr = new Vector[this->n];
	for (int i = 0; i < this->n; i++) {
		this->mtr[i] = matrix.mtr[i];
	}
	return *this;
}

Matrix& Matrix::operator+=(const Matrix& matrix) {
	if (this->n != matrix.n or this->m != matrix.m) throw std::invalid_argument("The size of matrices do not match!");
	for (int i = 0; i < this->n; i++) {
		this->mtr[i] += matrix.mtr[i];
	}
	return *this;
}

Matrix Matrix::operator+(const Matrix& matrix)const {
	if (this->n != matrix.n or this->m != matrix.m) throw std::invalid_argument("The size of matrices do not match!");
	Matrix a(this->n, this->m);
	for (int i = 0; i < this->n; i++) a.mtr[i] = this->mtr[i] + matrix.mtr[i];
	return a;
}

Matrix Matrix::operator-(const Matrix& matrix)const {
	if (this->n != matrix.n or this->m != matrix.m) throw std::invalid_argument("The size of matrices do not match!");
	Matrix a(this->n, this->m);
	for (int i = 0; i < this->n; i++) a.mtr[i] = this->mtr[i] - matrix.mtr[i];
	return a;
}

Matrix Matrix::operator-() {
	(*this) = (*this) * (-1);
	return *this;
}

Matrix Matrix::operator*(const double k)const {
	Matrix a(this->n, this->m);
	for (int i = 0; i < this->n; i++) { 
		a.mtr[i] = this->mtr[i] * k;
	}
	return a;
}

Matrix Matrix::operator/(const double k)const {
	if (k == 0) throw std::invalid_argument("Dividion by zero!");
	Matrix a(this->n, this->m);
	for (int i = 0; i < this->n; i++) {
		a.mtr[i] = this->mtr[i] / k;
	}
	return a;
}

Matrix Matrix::operator*(const Matrix& matrix)const {
	Matrix a(this->n, this->n);
	for (int i = 0; i < this->n; i++) {
		for (int j = 0; j < this->n; j++) {
			double sum = 0;
			for (int k = 0; k < this->n; k++) {
				sum += this->mtr[i][k] * matrix.mtr[k][j];
			}
			a.mtr[i][j] = sum;
		}
	}
	return a;
}

//transposition
Matrix Matrix::transpose() {
	Matrix a(this->n, this->m);
	a = (*this);
	delete[] this->mtr;
	this->n = a.m;
	this->m = a.n;
	this->mtr = new Vector[this->n];
	for (int i = 0; i < this->n; i++) {
		Vector v(this->m);
		this->mtr[i] = v;
		for (int j = 0; j < this->m; j++) {
			this->mtr[i][j] = a.mtr[j][i];
		}
	}
	return *this;
}

// determinant
double Matrix::determinant()const {
	if (n!=m) throw std::invalid_argument("The matrix is not square!");
	return (*this).find_det();
}

//  теорема лапласа, разложение по 0 столбцу
double Matrix::find_det()const {
	if (n == 1) return this->mtr[0][0];
	else if (n == 2) return this->mtr[0][0]* this->mtr[1][1]- this->mtr[1][0] * this->mtr[0][1];
	else {
		double det = 0;
		// i - номер строки в 0 столбце
		for (int i = 0; i < n; i++) {
			Matrix tmp(n-1, n-1);
			int l = 0;
			// l - номер строки в миноре
			// column - номер столбца в миноре
			// line - номер строки в мaтрице
			for (int line = 0; line < n; line++) {
				if (line == i) continue;
				for (int column = 0; column < n - 1; column++) {
					tmp.mtr[l][column] = this->mtr[line][column+1];
				}
				l++;
			}
			//tmp.print();
			det += this->mtr[i][0] * pow(-1, i)*tmp.find_det();
		}
		return det;
	}
}

void Matrix::set_elem(const int n, const int m, const double val) {
	(this->mtr[n])[m] = val;
}

// destructor
Matrix::~Matrix() {
	delete[] mtr;
}

// print
void Matrix::print()const {
	for (int i = 0; i < n; i++) {
		this->mtr[i].print();
	}
	std::cout << std::endl;
};
