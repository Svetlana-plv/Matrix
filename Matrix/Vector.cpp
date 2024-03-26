#include <iostream>
#include <clocale>
#include "Vector.h"

Vector::Vector() {
	n = 1;
	coord = new double[n];
	this->coord[0] = 0;
}

Vector::Vector(int n) {
	this->n = n;
	coord = new double[n];
	for (int i = 0; i < n; i++) {
		this->coord[i] = 0;
	}
}

Vector::Vector(const double* const arr, const int n) {
	this->n = n;
	coord = new double[n];
	for (int i = 0; i < n; i++) {
		this->coord[i] = arr[i];
	}
}

Vector::Vector(const Vector& b) : n(b.n) {
	this->coord = new double[this->n];
	for (int i = 0; i < this->n; i++) this->coord[i] = b.coord[i];
};

Vector& Vector::operator=(const Vector& v) {
	if (&v == this) return *this;
	this->n = v.n;
	delete[] this->coord;
	this->coord = new double[n];
	for (int i = 0; i < this->n; i++) {
		this->coord[i] = v.coord[i];
	}
	return *this;
}

Vector& Vector::operator+=(const Vector& v) {
	if (this->n != v.n) throw std::invalid_argument("The size of vectors do not match!");
	for (int i = 0; i < n; i++) {
		this->coord[i] += v.coord[i];
	}
	return *this;
}

void Vector::print()const {
	for (int i = 0; i < n; i++) {
		cout << coord[i] << " ";
	}
	std::cout << std::endl;
}

Vector Vector::operator+(const Vector& b) const {
	Vector a(n);
	for (int i = 0; i < n; i++) {
		a.coord[i] = this->coord[i] + b.coord[i];
	}
	return a;
}

Vector Vector::operator-(const Vector& b)const {
	Vector a(n);
	for (int i = 0; i < n; i++) {
		a.coord[i] = this->coord[i] - b.coord[i];
	}
	return a;
}

Vector Vector::operator-()const {
	Vector a(n);
	for (int i = 0; i < n; i++) {
		a.coord[i] = -this->coord[i];
	}
	return a;
}

Vector Vector::operator*(const double k) const {
	Vector a(n);
	for (int i = 0; i < n; i++) {
		a.coord[i] = this->coord[i] * k;
	}
	return a;
}

Vector Vector::operator/(const double k) const {
	if(k==0) throw std::invalid_argument("Dividion by zero!");
	Vector a(n);
	for (int i = 0; i < n; i++) {
		a.coord[i] = this->coord[i] / k;
	}
	return a;
}

double Vector::get_elem(int ind) {
	return coord[ind];
}

void Vector::set_elem(int ind, double value) {
	coord[ind] = value;
}

double Vector::operator[](int ind)const {
	return coord[ind];
}

double& Vector::operator[](int ind) {
	return coord[ind];
}

double Vector::dot_product(const Vector b) const {
	return (*this).sum_square(b);
}

double Vector::norm() const {
	return sqrt((*this).sum_square((*this)));
}

double Vector::dist(const Vector b) const {
	Vector c(n);
	c = (*this) - b;
	return sqrt(c.sum_square(c));
}

Vector::~Vector() {
	delete[] coord;
}

double Vector::sum_square(const Vector b) const {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += this->coord[i] * b.coord[i];
	}
	return sum;
}