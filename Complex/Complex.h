#ifndef COMPLEX_H__
#define COMPLEX_H__ 
#include <iostream>
#include <math.h>

class Complex {

	friend std::ostream & operator<< (std::ostream &os, const Complex &c);

	friend const Complex operator+ (const Complex &c1, const Complex &c2);
	friend const Complex operator+ (const Complex &c, double real);
	friend const Complex operator+ (double real, const Complex &c);

	friend const Complex operator- (const Complex &c1, const Complex &c2);
	friend const Complex operator- (const Complex &c, double real);
	friend const Complex operator- (double real, const Complex &c);

	friend const Complex operator* (const Complex &c1, const Complex &c2);
	friend const Complex operator* (const Complex &c, double real);
	friend const Complex operator* (double real, const Complex &c);

	friend const Complex operator/ (const Complex &c1, const Complex &c2);
	friend const Complex operator/ (const Complex &c, double real);
	friend const Complex operator/ (double real, const Complex &c);

public:
	Complex(double real = 0.0, double img = 0.0);
	~Complex();
	Complex(const Complex &c);
	Complex & operator= (const Complex &c);
	Complex & operator= (double real);

	void setComplex(double real, double img) { real_ = real; img_ = img; }
	void setReal(double real) { real_ = real; }
	void setImg(double img) { img_ = img; }

	double getReal() const { return real_; }
	double getImg() const { return img_; }
	double getMod() const;
private:
	double real_;
	double img_;
};

#endif  /*COMPLEX_H__*/
