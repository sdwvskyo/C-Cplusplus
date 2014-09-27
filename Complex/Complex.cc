#include "Complex.h"

using namespace std;

Complex::Complex(double real, double img)
	: real_(real), img_(img)
{

}

Complex::~Complex()
{
	
}

Complex::Complex(const Complex &c)
{
	real_ = c.real_;
	img_= c.img_;
}

Complex & Complex::operator= (const Complex &c)
{
	real_ = c.real_;
	img_ = c.img_;
	return *this;
}

Complex & Complex::operator= (double real)
{
	real_ = real;
	return *this;
}


double Complex::getMod() const
{
	return sqrt(real_*real_ + img_*img_);
}

std::ostream & operator<< (std::ostream &os, const Complex &c)
{
	return os << c.real_ << "+" << c.img_ << "i";
}

const Complex operator+ (const Complex &c1, const Complex &c2)
{
	return Complex(c1.real_ + c2.real_, c1.img_ + c2.img_);
}

const Complex operator+ (const Complex &c, double real)
{
	return c + Complex(real);
}

const Complex operator+ (double real, const Complex &c)
{
	return Complex(real) + c;
}

const Complex operator- (const Complex &c1, const Complex &c2)
{
	return Complex(c1.real_ - c2.real_, c1.img_ - c2.img_);
}

const Complex operator- (const Complex &c, double real)
{
	return c - Complex(real);
}

const Complex operator- (double real, const Complex &c)
{
	return Complex(real) - c;
}

const Complex operator* (const Complex &c1, const Complex &c2)
{
	return Complex(c1.real_ * c2.real_, c1.img_ * c2.img_);
}

const Complex operator* (const Complex &c, double real)
{
	return c * Complex(real);
}

const Complex operator* (double real, const Complex &c)
{
	return Complex(real) * c;
} 

const Complex operator/ (const Complex &c1, const Complex &c2)
{
	return Complex(c1.real_ / c2.real_, c1.img_ / c2.img_);
}

const Complex operator/ (const Complex &c, double real)
{
	return c / Complex(real);
}

const Complex operator/ (double real, const Complex &c)
{
	return Complex(real) / c;
}

