#pragma once
#include <iostream>
#include <clocale>
#include "Vector.h"

class Matrix {
private:
	Vector* mtr = nullptr;
	int n = 0; // lines
	int m = 0; // columns
public:
	// constructors
	Matrix();
	Matrix(const int n, const int m);
	Matrix(const Vector* matrix, const int n, const int m);
	Matrix(const Matrix& matrix); // copy constructor
	~Matrix();	// destructor

	//operators
	Matrix& operator=(const Matrix& matrix);
	Matrix& operator+=(const Matrix& matrix);
	Matrix operator+(const Matrix& matrix)const;
	Matrix operator-(const Matrix& matrix)const;
	Matrix operator-();
	Matrix operator*(const double k)const;
	Matrix operator/(const double k)const;
	Matrix operator*(const Matrix& matrix)const;
	
	Matrix transpose();
	double determinant()const;
	double find_det()const;
	void set_elem(const int n, const int m, const double val);
	void print()const;

};
