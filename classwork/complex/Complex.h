#pragma once

//#ifndef COMPLEX_H
//#define COMPLEX_H
class Complex
{
private:
	double real;
	double img;

	void assignHelper(double real, double img);

public:
	//Constructors & destructor
	Complex();
	//Complex(double real, double img);
	Complex(double r, double i) :real(r), img(i) {};		//Constructor - Base member initialization 
	~Complex();

	//Accessors
	double getReal();
	double getImg();
	void print();

	//Mutators
	void setReal(double real);
	void setImg(double img);
	void assign(double real, double img);

	//Utility or Operational functions
	double getModulusValue();
	double getAmplitudeValue();

	//Operator functions
	Complex& operator+(const Complex& complex2);
	bool operator>(const Complex& complex2);

};

//#endif // !COMPLEX_H