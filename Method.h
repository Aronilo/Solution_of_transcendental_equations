#pragma once

struct Method {
	static double f(double x);
	static double df(double x);
	static double d2f(double x);
	static double method_half(double (*f)(double), double a, double b, double eps);
	static double chord_method(double (*f)(double), double a, double b, double eps);
	static double method_newton(double (*f)(double), double a, double b, double eps);
};
// Диалоговое окно Method