#pragma once

#ifndef _TENSOR_
#define _TENSOR_

#include <stdio.h>
#include <iostream>

template <typename T>
class Tensor
{
public:
	Tensor() : r(0), ms(0), s(nullptr), mas(nullptr) { }
	Tensor(size_t, const size_t*);
	Tensor(size_t, const size_t*, const T*);

	// Перегрузка оператора ">>" для ввода тензора через консоль.
	// Полностью перезаписывает тензор с введёнными порядком, размерами и
	// элементами
	friend std::istream& operator>> (std::istream& in, Tensor& tensor)
	{
		size_t  r;
		size_t* s = nullptr;
		size_t  ms = 0;
		T* mas = nullptr;

		std::cout << "\n--------- Start insert tensor {\n";
		std::cout << "Enter rang: ";
		in >> r;


		if (r > 0)
		{
			ms = 1;
			s = (size_t*) new size_t[r];

			for (size_t i = 0; i < r; i++)
			{
				std::cout << "Enter size of [" << (i + 1) << "] dimenstion: ";
				in >> s[i];
				ms *= s[i];
			}

			// Выделение динамической памяти
			mas = (T*) new T[ms];

			// Заполнение динамической памяти
			for (size_t i = 0; i < ms; i++)
			{
				for (int j = r - 1; j >= 0; j--)
				{
					size_t Vn_1 = 1; // V(n-1), n-1 объём тензора
					for (size_t n = 0; n < j; n++)
						Vn_1 *= s[n];

					std::cout << "[" << (floor(i / Vn_1) - floor(i / (Vn_1 * s[j])) * s[j]) << "]";
				}
				std::cout << ": ";

				in >> mas[i];
			}
		}

		// Перезапись тензора
		tensor.~Tensor();
		tensor.r = r;
		tensor.s = s;
		tensor.ms = ms;
		tensor.mas = mas;

		std::cout << "--------- } End insert tensor\n";

		return in;
	}

	// Перегрузка оператора "<<" для вывода тензора в консоль.
	// Выводит тензор
	friend std::ostream& operator<< (std::ostream& out, const Tensor& tensor)
	{
		const T* mas = tensor.mas;
		const size_t* s = tensor.s;
		size_t r = tensor.r;
		size_t ms = tensor.ms;

		if (r > 0)
		{
			int i = 0;
			while (i < ms)
			{
				if (i - floor(i / s[0]) * s[0] == 0)
				{
					if (floor(i / s[0]) - floor(i / (s[0] * s[1])) * s[1] == 0)
					{
						out << '\n';
						for (size_t j = r - 1; j > 1; j--)
						{
							size_t Vn_1 = 1; // V(n-1), n-1 объём тензора
							for (size_t n = 0; n < j; n++)
								Vn_1 *= s[n];

							out << "["
								<< (floor(i / Vn_1) - floor(i / (Vn_1 * s[j])) * s[j])
								<< "]";
						}
						if (r > 2) out << ":\n";
					}
					out << '\t';
				}

				out << std::setw(4)
					<< mas[i]
					<< ' ';

				if (i - floor(i / s[0]) * s[0] == s[0] - 1)
					out << '\n';


				i++;
			}
		}
		return out;
	}

	~Tensor();

private:
	T*      mas;  // Массив данных тензора
	size_t* s;    // Массив размерностей тензора
	size_t  ms;   // Размер массива данных
	size_t  r;    // Порядок тензора
};

#include "Tensor.inl"

#endif //_TENSOR_