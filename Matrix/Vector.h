#pragma once
#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

class Vector {
private:
	double* coord = nullptr;
	int n=0;

public:
	// constructors
	Vector(); 
	Vector(int n);
	Vector(const double* const arr, const int n);
	Vector(const Vector& b); // copy constructor
	~Vector(); // destructor

	//operators
	Vector& operator=(const Vector& v);
	Vector& operator+=(const Vector& v);
	Vector operator+(const Vector& b) const;
	Vector operator-(const Vector& b)const;
	Vector operator-()const;
	Vector operator*(const double k) const;
	Vector operator/(const double k) const;
	double operator[](int ind)const;
	double& operator[](int ind);

	// get, set
	double get_elem(int ind);
	void set_elem(int ind, double value);

	double dot_product(const Vector b)const;
	double norm()const;
	double dist(const Vector b)const;
	void print()const;

private:
	double sum_square(const Vector b)const;
};