// Method.cpp: файл реализации
//

#include "pch.h"
#include "Solution_of_transcendental_equations.h"
#include "Method.h"
#include "afxdialogex.h"
#include <stdexcept>
using namespace std;

double Method::f(double x) {
	return exp(-x) - 2 * sqrt(x);
}

double Method::df(double x)
{
	return -exp(-x) - 1 / sqrt(x);
}

double Method::d2f(double x) {
	return exp(-x) + 1 / (2 * pow(x, 2.0 / 3));
}

double Method::method_half(double (*f)(double), double a, double b, double eps) {
	double c = 0;
	while ((b - a) / 2 > eps) {
		c = (a + b) / 2;
		if ((f(a) * f(c)) > 0) a = c;
		else b = c;
	}
	return c;
}

double Method::chord_method(double (*f)(double), double a, double b, double eps) {
	double t = 0;
	while (fabs(b - a) >= eps) {
		t = a + (f(b) * (b - a)) / (f(b) - f(a));
		if (f(a) * f(t) < 0) {
			b = t;
		}
		else if (f(t) * f(b) < 0) {
			a = t;
		}
		else
			return t;
	}
	return t;
}


double Method::method_newton(double (*f)(double), double a, double b, double eps) {
	double x0 = 0, xn = 0;
	if (a > b) 
	{
		x0 = a;
		a = b;
		b = x0;
	}
	if (f(a) * f(b) > 0) // если знаки функции на краях отрезка одинаковые, то здесь нет корня
		throw std::invalid_argument("");
	else
	{
		if (f(a) * d2f(a) > 0) x0 = a; // для выбора начальной точки проверяем f(x0)*d2f(x0)>0 ?
		else x0 = b;
		xn = x0 - f(x0) / df(x0); // считаем первое приближение
		while (fabs(x0 - xn) > eps) // пока не достигнем необходимой точности, будет продолжать вычислять
		{
			x0 = xn;
			xn = x0 - f(x0) / df(x0); // непосредственно формула Ньютона
		}
	}
	return xn;
}
// Диалоговое окно Method
