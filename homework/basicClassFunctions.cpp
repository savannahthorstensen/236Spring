/*(Program)
a. Create a multiplication operator function for the Complex class
in Program 11.8 that multiplies two complex numbers. Use the
relationship that (a + bi) x (c + di) = (ac - bd) + (ad + bc) i.
b. Include the function constructed for Exercise 4a in a complete C++ program.

(Program)
a. Construct a swap () function for the Complex class used in Program 11.8 that
swaps the values in two complex number objects. The function should have the
following header line: void Complex:: swap (Complex& b)
b. Include the function constructed for Exercise 5a in a complete C++ program.
c. Change the parameter declaration in the function prototype and header for
the swap () function written for Exercise Ja to const Complex&. Compile the
program to determine the error messages the compiler returns.
*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Complex
{
private:
    double real;
    double imaginary;
    string *name;

public:
    // constructors and destructor
    Complex();
    Complex(double real, double imaginary);
    Complex(const Complex &complex2);
    ~Complex();

    //functions
    void printValues();
    void assignValues(double real, double imaginary);
    double getAbsolute();
    inline double getImaginary();

    //operators
    Complex operator+(const Complex &complex2);
    Complex operator*(const Complex &complex2);
    bool operator==(const Complex &complex2);
    Complex operator=(const Complex &complex2);

    //swap
    void swap(Complex &complex2);
};

//implemntation

Complex::Complex()
{
    real = 0;
    imaginary = 0;
    name = new string("__DEFAULT__");
}

Complex::Complex(double real, double imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
    name = new string("__CUSTOM__");
}

Complex::Complex(const Complex &complex2)
{
    this->real = complex2.real;
    this->imaginary = complex2.imaginary;
    this->name = new string(*complex2.name);
}

Complex::~Complex()
{
    if (name != nullptr)
    {
        delete name;
        name = nullptr;
    }
}

void Complex::printValues()
{
    string imaginarySign = "+";
    if (imaginary < 0)
    {
        imaginarySign = "-";
    }

    cout << real;
    if (imaginary != 0)
    {
        cout << imaginarySign << abs(imaginary) << "i";
    }
    cout << endl;
}

void Complex::assignValues(double real, double imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}

double Complex::getAbsolute()
{
    double absolute = sqrt(pow(real, 2) + pow(imaginary, 2));
    return (int)(absolute * 100) / 100.0;
}

inline double Complex::getImaginary()
{
    return imaginary;
}

//operator +
Complex Complex::operator+(const Complex &complex2)
{
    Complex temp;
    temp.real = this->real + complex2.real;
    temp.imaginary = this->imaginary + complex2.imaginary;
    return temp;
}

//operator *
Complex Complex::operator*(const Complex &complex2)
{
    Complex temp;
    temp.real = (this->real * complex2.real) - (this->imaginary * complex2.imaginary);
    temp.imaginary = (this->real * complex2.imaginary) + (this->imaginary * complex2.real);
    return temp;
}

//operator ==
bool Complex::operator==(const Complex &complex2)
{
    return this->real == complex2.real && this->imaginary == complex2.imaginary;
}

// operator =
Complex Complex::operator=(const Complex &complex2)
{
    this->real = complex2.real;
    this->imaginary = complex2.imaginary;

    if (this->name != nullptr)
    {
        delete this->name;
    }
    this->name = new string(*complex2.name);

    return *this;
}

// swap function
void Complex::swap(Complex &complex2)
{
    Complex temp(*this);

    this->real = complex2.real;
    this->imaginary = complex2.imaginary;

    complex2.real = temp.real;
    complex2.imaginary = temp.imaginary;

    // swap name pointer
    string *tempName = this->name;
    this->name = complex2.name;
    complex2.name = tempName;
}


int main()
{
    Complex c1(2, 3);
    Complex c2(4, 5);

    cout << "c1: ";
    c1.printValues();

    cout << "c2: ";
    c2.printValues();

    // Test multiplication
    Complex result = c1 * c2;
    cout << "\nMultiplication result: ";
    result.printValues();

    // Test swap
    c1.swap(c2);
    cout << "\nAfter swap:" << endl;

    cout << "c1: ";
    c1.printValues();

    cout << "c2: ";
    c2.printValues();

    return 0;
}