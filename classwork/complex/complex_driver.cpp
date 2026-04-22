#include "Complex.h"
#include <iostream>

using namespace std;

int main() {
//int complexDriverMain() {
	Complex c1;
	c1.print();
	c1.assign(2.3, 4.4);
	c1.print();
	c1.setReal(5.3);
	c1.print();
	cout << "c1.img: " << c1.getImg() << endl;
	//c1.~Complex(); //Destructor can be called just like any other function 
					//but we don't need to do it cause it will be called automatically when object is destroyed


	Complex c2(1.1, -8.5);
	c2.print();

	cout << "Modulus for c2: " << c2.getModulusValue() << ", Amplitude for c2: " << c2.getAmplitudeValue() << endl;

	Complex* c3 = new Complex();
	c3->setReal(-5.4);
	c3->print(); // or (*c3).print();
	delete c3;

	Complex c4 = c1 + c2;
	//Complex c4 = c1.operator+(c2);

	if (c1 > c2) {
		cout << "c1 is greater than c2" << endl;
	}
	else {
		cout << "c1 is NOT greater than c2" << endl;
	}

	c4.print();


	char* test = NULL;
	char* test2 = nullptr;
	char* test3 = new char[10];
	delete[] test3;

	if (test3 == nullptr) {
		cout << "Empty c-string" << endl;
	}

	return 0;
}