#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include "Complex.h"

Complex::Complex()
{
    re = 0;
    im = 0;
}

Complex::Complex(double r)
{
    re = r;
    im = 0;
}

Complex::Complex(double r, double i)
{
    re = r;
    im = i;
}

double Complex::real()
{
    return  re;
}

double  Complex::imag()
{
    return im;
}

void Complex::read()
{
    scanf("%lf + i%lf", &re, &im);
}

void Complex::print()
{
    printf("%lf + i%lf", re, im);
}

Complex Complex::conjugate()
{
    return Complex(re, -im);
}

double Complex::modulus()
{
    return sqrt(pow(re, 2) + pow(im, 2));
}

double Complex::arg_rad()
{
    return atan2(re, im);
}

double Complex::arg_deg()
{
    return (arg_rad() * 180) / M_PI;
}

//operadores

Complex Complex::operator + (Complex& c)
{
    Complex res;

    res.re = re + c.re;
    res.im = im + c.im;

    return res;
}

Complex Complex::operator - (Complex& c)
{
    Complex res;

    res.re = re - c.re;
    res.im = im - c.im;

    return res;
}

Complex Complex::operator-()
{
    return Complex(-re, -im);
}

Complex Complex::operator * (Complex& c)
{
    Complex res;

    res.re = re * c.re - im * c.im;
    res.im = re * c.im + im * c.re;

    return res;
}

Complex Complex::operator* (double k)
{
    return Complex(re * k, im * k);
}

Complex Complex::operator / (Complex& c) 
{
    Complex conj = c.conjugate();
    
    Complex num = (*this) * conj;
    Complex denom = c * conj;

    return num / denom.re;
}

Complex Complex::operator / (double k)
{
    return Complex(re / k, im / k);
}

Complex Complex::operator += (Complex& c)
{
    return (*this) + c;
}

Complex Complex::operator*= (Complex& c)
{
    return (*this) * c;
}