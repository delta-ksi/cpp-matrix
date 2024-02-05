#pragma once

#ifndef _COMPLEX_
#define _COMPLEX_

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <math.h>

class Complex
{
public:
																				// КОНСТРУКТОРЫ КЛАССА Complex
	Complex();																	// Конструктор по умолчанию
	Complex(int);																// Конструктор для перевода int в Complex
	Complex(double);															// Конструктор для перевода double в Complex
	Complex(double, double);													// Конструктор по действительной и мнимой части
	Complex(const Complex&);													// Копирующий конструктор

																				// МЕТОДЫ КЛАССА Complex
	double  r()		const;														// Метод возвращающий действительную часть
	double  i()		const;														// Метод возвращающий мнимую часть
	double  abs()	const;														// Метод возвращающий абсолютное значение
	Complex c()		const;														// Метод возвращающий комплексно сопряжённое

	friend Complex			operator+	(const Complex&, const Complex&);		// Оператор сложения
	friend Complex			operator-	(const Complex&, const Complex&);		// Оператор вычитания
	friend Complex			operator*	(const Complex&, const Complex&);		// Оператор умножения
	friend Complex			operator/	(const Complex&, const Complex&);		// Оператор деления
	friend Complex&			operator+=	(const Complex&, const Complex&);		// Оператор сложение с присваением
	friend Complex&			operator-=	(const Complex&, const Complex&);		// Оператор вычитание с присваением
	friend Complex&			operator*=	(const Complex&, const Complex&);		// Оператор умножения с присваением
	friend Complex&			operator/=	(const Complex&, const Complex&);		// Оператор деления с присваением
	friend bool				operator==	(const Complex&, const Complex&);		// Логические оператор равно
	friend bool				operator!=	(const Complex&, const Complex&);		// Логические оператор не равно
	friend bool				operator>	(const Complex&, const Complex&);		// Логические оператор больше (по абсолютному значению)
	friend bool				operator<	(const Complex&, const Complex&);		// Логические оператор меньше (по абсолютному значению)

	// explicit operator int() const { return ; }

	friend std::istream&	operator>>	(std::istream& in, Complex& z);			// Оператор ввода
	friend std::ostream&	operator<<	(std::ostream& out, const Complex& z);	// Оператор вывода

private:
	/////////////////////////////////////////////////
	// Member data
	/////////////////////////////////////////////////
	double m_real;
	double m_imag;
};

#endif // !_COMPLEX_