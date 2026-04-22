#include "Complex.h"
#include <iostream>

using namespace std;

void Complex::assignHelper(double real, double img) {
	(*this).real = real;
	this->img = img;
}

Complex::Complex() {
	assignHelper(0.0, 0.0);
	cout << "No argument constructor for Complex class is called" << endl;
}

/*
Complex::Complex(double real, double img) {
	assignHelper(real, img);
	cout << "Custom constructor for Complex class is called" << endl;
}
*/
Complex::~Complex() {
	cout << "Destructor for Complex class is called" << endl;
}

//Accessors
double Complex::getReal() {
	return real;
}

double Complex::getImg() {
	return img;
}

void Complex::print() {
	cout << real;
	if (img >= 0) {
		cout << "+";
	}
	cout << img << "i" << endl;
}

//Mutators
void Complex::setReal(double real) {
	this->real = real;
}

void Complex::setImg(double img) {
	this->img = img;
}

void Complex::assign(double real, double img) {
	assignHelper(real, img);
}

double Complex::getModulusValue() {
	return sqrt(pow(real, 2) + pow(img, 2));
}

double Complex::getAmplitudeValue() {
	if (real == 0) {
		return 1.571;
	}

	return -atan(img / real);
}

Complex& Complex::operator+(const Complex& complex2) {
	Complex temp;
	temp.real = this->real + complex2.real;
	temp.img = this->img + complex2.img;

	return temp;
}

bool Complex::operator>(const Complex& complex2) {
	//Not 100% sure about logic

	return this->real > complex2.real && this->img > complex2.img;
}