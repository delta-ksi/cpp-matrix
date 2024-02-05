#pragma once

#ifndef _MATRIX_
#define _MATRIX_

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <ctime>
#include <cassert>

template <typename T>
class Matrix
{
public:
	// КОНСТРУКТОРЫ КЛАССА Matrix
	Matrix() : m(0), n(0), M(nullptr) { }                 // Конструктор по умолчанию
	Matrix(size_t, size_t);                               // Конструктор, создающий матрицу (m x n) и заполняющий её элементы 0
	Matrix(size_t, size_t, T);                            // Конструктор, создающий матрицу (m x n) и заполняющий её элементы значением k
	Matrix(size_t, size_t, T*);                           // Конструктор, создающий матрицу (m x n) и заполняющий её элементами переданного массива
	Matrix(const Matrix&);                                // Конструктор, создающий копию матрицы matrix

														  // МЕТОДЫ КЛАССА Matrix
	T         get(size_t, size_t) const;                  // Возвращает элемент M[i][j] из матрицы
	void      set(size_t, size_t, T);                     // Устанавливает в элемент M[i][j] из матрицы значение value
	Matrix    getRow(size_t) const;                       // Возвращает i-ю строку матрицы
	Matrix    getCol(size_t) const;                       // Возвращает j-й столбец матрицы
	void      delRow(size_t);                             // Удаляет строку из матрицы
	void      delCol(size_t);                             // Удаляет столбец из матрицы
	void      resize(size_t, size_t);                     // Изменяет размер матрицы
	T         minor(size_t, size_t) const;                // Возвращает i-й j-й минор матрицы
	T         alg(size_t, size_t) const;                  // Возвращает i-ое j-ое алгебраическое дополнение матрицы
	T         det() const;                                // Возвращает детерминант матрицы
	void      transp();                                   // Транспонирует матрицу
	Matrix    getTransp() const;                          // Возвращает транспонированную матрицу
	Matrix    getInverse() const;                         // Возвращает обратную матрицу

														  // Возвращает количество строк матрицы
	size_t getNumRow() const
	{ return m; }
	// Возвращает количество столбцов матрицы
	size_t getNumCol() const
	{ return n; }

	// ОПЕРАТОРЫ КЛАССА Matrix
	Matrix  operator+  (const Matrix&) const;             // Оператор "+".  Складывает матрицы
	Matrix  operator-  (const Matrix&) const;             // Оператор "-".  Вычитает матрицы
	Matrix  operator*  (const T)       const;             // Оператор "*".  Уможает матрицу на число (Только в таком порядке!)
	Matrix  operator*  (const Matrix&) const;             // Оператор "*".  Перемножает матрицы (По правилу перемножения матриц)
	Matrix  operator/  (const T)       const;             // Оператор "/".  Делит матрицу на число (Только в таком порядке!)
	Matrix& operator+= (const Matrix&);                   // Оператор "+=". Складывает матрицы и присваивает слева
	Matrix& operator-= (const Matrix&);                   // Оператор "-=". Вычитает матрицы и присваивает слева
	Matrix& operator*= (const T value);                   // Оператор "*=". Умножает матрицу на число и присваивает слева
	Matrix& operator*= (const Matrix&);                   // Оператор "*=". Перемножает матрицы и присваивает слева
	Matrix& operator/= (const T);                         // Оператор "/=". Делит матрицу на число и присваивает слева
	Matrix  operator++ (int);                             // Оператор "++". Постфиксный икремент. Эквивалентен прибавлению ко всем элементам 1-ы
	Matrix& operator++ ();                                // Оператор "++". Префиксный икремент. Эквивалентен прибавлению ко всем элементам 1-ы
	Matrix  operator-- (int);                             // Оператор "--". Постфиксный декремент. Эквивалентен вычитанию из всех элементов 1-ы
	Matrix& operator-- ();                                // Оператор "--". Префиксный декремент. Эквивалентен вычитанию из всех элементов 1-ы
	Matrix  operator=  (const Matrix&);                   // Оператор "=".  Приравнивает матрицы

	//[[deprecated]]                                      // Оператор "[]". Даёт доступ к i строке (Не имеет защиты от выхода за предела по стобцам!)
	T* operator[] (size_t);                               // Объявлен deprecate, при ОСОБОМ желании, им можно воспользоваться сняв его.
	T& operator() (size_t, size_t) const;                       // Перегрузка оператора "()". Обращение к элементам матрицы с проверкой индексов

														  // ДРУЖЕСТВЕННЫЕ ФУНКЦИИ КЛАССА Matrix (Определены здесь, т.к. класс - шаблонный)

	// Перегрузка оператора ">>" для ввода матрицы через консоль.
	// Полностью перезаписывает мартрицу с введёнными размерами и
	// элементами
	friend std::istream& operator>> (std::istream& in, Matrix& matrix)
	{
		// Новые размеры матрицы, которые
		// введёт пользователь
		size_t m, n;
		T** M = nullptr;

		std::cout << "\n------- Start insert matrix {\n";
		std::cout << "Enter number of rows: ";
		in >> m;
		std::cout << "Enter number of columns: ";
		in >> n;

		if ((m > 0) && (n > 0))
		{
			// Выделение динамической памяти
			M = (T**) new T * [m];
			for (size_t i = 0; i < m; i++)
				M[i] = (T*) new T[n];

			// Заполнение динамической памяти
			for (size_t i = 0; i < m; i++)
				for (size_t j = 0; j < n; j++)
				{
					std::cout << "[" << (i + 1) << "][" << (j + 1) << "]: ";
					in >> M[i][j];
				}
		}

		// Перезапись матрицы
		matrix.~Matrix();
		matrix.M = M;
		matrix.m = m;
		matrix.n = n;

		std::cout << "------- } End insert matrix\n\n";

		return in;
	}

	// Перегрузка оператора "<<" для вывода матрицы в консоль.
	// Выводит матрицу
	friend std::ostream& operator<< (std::ostream& out, const Matrix& matrix)
	{
		for (size_t i = 0; i < matrix.m; i++)
		{
			out << "|";
			for (size_t j = 0; j < matrix.n; j++)
			{
				out << std::setiosflags(std::ios::fixed)
					<< std::setiosflags(std::ios::showpoint)
					<< std::setprecision(2)
					<< std::setw(5)
					<< matrix.M[i][j];
			}
			out << " |" << '\n';
		}
		return out;
	}

	template <typename T1, typename T2>
	friend Matrix<T1> operator+  (const Matrix<T1>& left, const Matrix<T2>& right);

	~Matrix();

private:
	////////////////////////////////////////////////////////////
	// Member data
	////////////////////////////////////////////////////////////
	T**     M;  // Указатель на динамический двумерный массив
	size_t  m;  // Количество строк
	size_t  n;  // Количество столбцов
};

template <typename T1, typename T2>
Matrix<T1>  operator+  (const Matrix<T1>& left, const Matrix<T2>& right);

template <typename T> Matrix<T> randM(size_t, size_t, T, T);                    // Функция возвращающая рандомно заполненую матрицу
template <typename T> Matrix<T> kron(const Matrix<T>&, const Matrix<T>&);       // Функция произведения кронекера
template <typename T> Matrix<T> x(const Matrix<T>&, const Matrix<T>&);          // Функция прямого произведения матриц
template <typename T> Matrix<T> _(const Matrix<T>&, const Matrix<T>&);          // Функция прямого произведения матриц

enum class dim { row, col, all };

template <typename T> Matrix<T> sum(const Matrix<T>&, dim);                     // Функция возвращающая сумму по столбцам, строкам и всех элементов
template <typename T> Matrix<T> sqrt(const Matrix<T>&);                         // Функция возвращающая квадратный корень из всех значений

#include "Matrix.inl"

#endif //_Matrix_