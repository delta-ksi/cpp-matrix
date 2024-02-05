// Конструктор, создающий матрицу (m x n) и заполняющий её элементы 0-ми.
template <typename T>
Matrix<T>::Matrix(size_t _m, size_t _n) : m(_m), n(_n)
{
	// Выделение динамической памяти
	M = (T**) new T* [m];
	for(size_t i = 0; i < m; i++)
		M[i] = (T*) new T[n];

	// Заполнение элементов матрицы 0-ми
	for(size_t i = 0; i < m; i++)
		for(size_t j = 0; j < n; j++)
			M[i][j] = 0;
}

// Конструктор, создающий матрицу (m x n) и заполняющий её элементы значением k
template <typename T>
Matrix<T>::Matrix(size_t _m, size_t _n, T k) : Matrix(_m, _n)
{
	// Заполнение элемнтов матрицы значением k
	for(size_t i = 0; i < m; i++)
		for(size_t j = 0; j < n; j++)
		M[i][j] = k;
}

// Конструктор, создающий матрицу (m x n) и заполняющий её элементами переданного массива
template <typename T>
Matrix<T>::Matrix(size_t _m, size_t _n, T* mas) : Matrix(_m, _n)
{
	for(size_t i = 0; i < m; i++)
		for(size_t j = 0; j < n; j++)
		M[i][j] = mas[i * n + j];
}

// Конструктор, создающий копию матрицы matrix
template <typename T>
Matrix<T>::Matrix(const Matrix& matrix) : Matrix(matrix.m, matrix.n)
{
	// Копирование элементов матрицы matrix
	for(size_t i = 0; i < m; i++)
		for(size_t j = 0; j < n; j++)
		M[i][j] = matrix.M[i][j];
}

// Деструктор класса Matrix
// Удаляет всю выделенную динамическую память
template <typename T>
Matrix<T>::~Matrix()
{
	// Удаление памяти столбцов
	if(n > 0)
		for(size_t i = 0; i < m; i++)
		delete[] M[i];
	// Удаление памяти строк
	if(m > 0)
		delete[] M;
}

// Возвращает элемент M[i][j] из матрицы
// @ При неправильно введённых индексах и пустой матрице ничего не возвращает
template <typename T>
T Matrix<T>::get(size_t i, size_t j) const
{
	// Проверка на пустоту матрицы
	if((m > 0) && (n > 0))
	{
		// Проверка на правильность введённых индексов
		if(i < m&& j < n)
			// Возвращение значения
			return M[i][j];
		else
			std::cout << "\nError: Invalid indexes!\n";
	}
	else
		std::cout << "\nError: Matrix is empty!\n";
}

// Устанавливает в элемент M[i][j] из матрицы значение value
// @ При неправильно введённых индексах и пустой матрице ничего не делает
template <typename T>
void Matrix<T>::set(size_t i, size_t j, T value)
{
	// Проверка на пустоту матрицы
	if((m > 0) && (n > 0))
	{
		// Проверка на правильность введённых индексов
		if(i < m&& j < n)
			// Присваивание значения
			M[i][j] = value;
		else
			std::cout << "\nWarrning: Invalid indexes!\n";
	}
	else
		std::cout << "\nWarrning: Matrix is empty!\n";

}

// Возвращает i-ю строку матрицы
// @ При неправильно введённых индексах и пустой матрице ничего не возвращает
template <typename T>
Matrix<T> Matrix<T>::getRow(size_t i) const
{
	// Проверка на пустоту матрицы
	if((m > 0) && (n > 0))
	{
		// Проверка на правильность введённого индекса
		if(i < m)
		{
			// Результирующая матрица-строка
			Matrix <T> result(1, n);

			// Заполнение результирующей матрицы-строки
			for(size_t q = 0; q < n; q++)
				result.M[0][q] = M[i][q];

			return result;
		}
		else
			std::cout << "\nError: Invalid index!\n";
	}
	else
		std::cout << "\nError: Matrix is empty!\n";
}

// Возвращает j-й столбец матрицы
// @ При неправильно введённых индексах и пустой матрице ничего не возвращает
template <typename T>
Matrix<T> Matrix<T>::getCol(size_t j) const
{
	// Проверка на пустоту матрицы
	if((m > 0) && (n > 0))
	{
		// Проверка на правильность введённого индекса
		if(j < n)
		{
			// Результирующая матрица-строка
			Matrix <T> result(m, 1);

			// Заполнение результирующей матрицы-строки
			for(size_t p = 0; p < m; p++)
				result.M[p][0] = M[p][j];

			return result;
		}
		else
			std::cout << "\nError: Invalid index!\n";
	}
	else
		std::cout << "\nError: Matrix is empty!\n";
}

// Удаляет строку из матрицы.
// При неправильно введённом индексе или пустой матрице,
// ничего не делает.
template <typename T>
void  Matrix<T>::delRow(size_t i)
{
	// Проверка на пустоту матрицы
	if((m > 0) && (n > 0))
	{
		// Проверка на правильность введённых индексов
		if(i < m)
		{
			// Замена всех строк ниже i-й включительно,
			// с [p]-й на нижнюю [p + 1]-ю
			for(size_t p = i; p < m - 1; p++)
				for(size_t q = 0; q < n; q++)
				M[p][q] = M[p + 1][q];

			// Удаление памяти последней строки
			delete[] M[m - 1];

			//Уменьшение кол-во строк на 1
			m--;
		}
		else
			std::cout << "\nWarrning: Invalid index!\n";
	}
	else
		std::cout << "\nWarrning: Matrix is empty!\n";
}

// Удаляет столбец из матрицы.
// При неправильно введённом индексе или пустой матрице,
// ничего не делает.
template <typename T>
void  Matrix<T>::delCol(size_t j)
{
	// Проверка на пустоту матрицы
	if((m > 0) && (n > 0))
	{
		// Проверка на правильность введённых индексов
		if(j < n)
		{
			// Замена всех столбцов правее j-го включительно,
			// с [q]-го на правый [q + 1]-й
			for(size_t p = 0; p < m; p++)
				for(size_t q = j; q < n - 1; q++)
				M[p][q] = M[p][q + 1];

			// Перезапись всех строк матрицы.
			// Необходима, т.к. иначе удалить
			// последний столбец невозможно,
			// т.к. указатель указывает на
			// массив всей строки,
			// а элемент этого массива не
			// указатель!
			for(size_t p = 0; p < m; p++)
			{
				// Копия p-й строки матрицы
				// без последнего элемента
				T* copy = (T*)new T[n - 1];

				// Заполнение копирующей строки
				for(size_t q = 0; q < n - 1; q++)
					copy[q] = M[p][q];

				// Удаление p-й строки матрицы
				delete[] M[p];

				// Перезапись p-й строки матрицы
				M[p] = copy;
			}
			n--;
		}
		else
			std::cout << "\nWarrning: Invalid index!\n";
	}
	else
		std::cout << "\nWarrning: Matrix is empty!\n";
}

// Изменяет размер матрицы
// @ Удаляет всю память до изменения размера
template <typename T>
void Matrix<T>::resize(size_t _m, size_t _n)
{
	// Удаляем память матрицы
	this->~Matrix();

	// Меняем размеры
	m = _m;
	n = _n;

	// Выделение динамической памяти
	M = (T**)new T * [m];
	for(size_t i = 0; i < m; i++)
		M[i] = (T*)new T[n];

	// Заполнение элемнтов матрицы 0
	for(size_t i = 0; i < m; i++)
		for(size_t j = 0; j < n; j++)
		M[i][j] = 0;
}

// Возвращает i-й j-й минор матрицы.
// @ При неправильно введённых индексах и пустой матрице ничего не возвращает
template <typename T>
T Matrix<T>::minor(size_t i, size_t j) const
{
	// Проверка на пустоту матрицы
	if((m > 0) && (n > 0))
	{
		// Проверка на то что матрица квадратна
		if(m == n)
		{
			// Проверка на правильность введённых индексов
			if((i < m) && (j < n))
			{
				// Матрица копия матрицы слева
				Matrix <T> copy(*this);

				// Удалени i-й строки и j-го столбца
				copy.delRow(i);
				copy.delCol(j);

				// Возвращение детерминанта итоговой матрицы,
				// что по сути являтеся минором
				return copy.det();
			}
			else
				std::cout << "\nError: Invalid index!\n";
		}
		else
			std::cout << "\nError: Matrix must be square!\n";
	}
	else
		std::cout << "\nError: Matrix is empty!\n";
}

// Возвращает i-ое j-ое алгебраическое дополнение матрицы
// @ При неправильно введённых индексах и пустой матрице ничего не возвращает
template <typename T>
T Matrix<T>::alg(size_t i, size_t j) const
{
	// Проверка на пустоту матрицы
	if((m > 0) && (n > 0))
	{
		// Проверка на то что матрица квадратна
		if(m == n)
		{
			// Проверка на правильность введённых индексов
			if((i < n) && (j < m))
			{
				T result = this->minor(i, j) * pow(-1., i + j);
				return result;
			}
			else
				std::cout << "\nError: Invalid index!\n";
		}
		else
			std::cout << "\nError: Matrix must be square!\n";
	}
	else
		std::cout << "\nError: Matrix is empty!\n";
}

// Возвращает детерминант матрицы.
// Если матрица является пустой
// или не является квадратной, возвращает 0.
template <typename T>
T Matrix<T>::det() const
{
	// Значение детерминанта
	T det = 0;
	// Проверка на пустоту матрицы
	if((m > 0) && (n > 0))
	{
		// Проверка на то что матрица квадратна
		if(m == n)
		{
			if(m == 1) return M[0][0];
			if(m == 2) return M[0][0] * M[1][1] - M[0][1] * M[1][0];
			for(size_t j = 0; j < m; j++)
				det += M[0][j] * alg(0, j);
		}
		else
			std::cout << "\nWarrning: Matrix must be square!\n";
	}
	else
		std::cout << "\nWarrning: Matrix is empty!\n";

	return det;
}

// Транспонирует матрицу.
// Если матрица будет пустой, то ничего не делает.
template <typename T>
void Matrix<T>::transp()
{
	// Проверка на пустоту матрицы
	if((m > 0) && (n > 0))
	{
		// Матрица копия матрицы слева
		Matrix <T> copy(*this);

		this->~Matrix();

		m = copy.n;
		n = copy.m;

		// Выделение динамической памяти
		// с транспонированными размерами
		M = (T**)new T * [m];
		for(size_t i = 0; i < m; i++)
			M[i] = (T*)new T[n];

		// Заполнение матрицы из её копии
		for(size_t i = 0; i < m; i++)
			for(size_t j = 0; j < n; j++)
			M[i][j] = copy.M[j][i];
	}
	else
		std::cout << "\nWarrning: Matrix is empty!\n";
}

// Возвращает транспонированую матрицу.
// Если матрица будет пустой, то вернёт исходную (пустую) матрицу.
template <typename T>
Matrix<T> Matrix<T>::getTransp() const
{
	// Проверка на пустоту матрицы
	if((m > 0) && (n > 0))
	{
		// Результирующая матрица с
		// транспонированными размерами
		Matrix <T> result(n, m);

		// Заполнение результирующей матрицы
		for(size_t i = 0; i < result.m; i++)
			for(size_t j = 0; j < result.n; j++)
			result.M[i][j] = M[j][i];

		return result;
	}
	else
	{
		std::cout << "\nWarrning: Matrix is empty!\n";
		return* this;
	}
}

// Возвращает обратную матрицу
// Если матрица будет пустой,
// то вернёт исходную (пустую) матрицу.
//
// ЕСЛИ МАТРИЦА ОБЯВЛЕНА С ЦЕЛОЧИСЛИННЫМИ ЭЛЕМЕНТАМИ,
// ТО БУДЕТ ВОЗВРВАЩЕНА ОБРАТНАЯ МАТРИЦА С ОКРУГЛЕНИЕМ
// ДО ЦЕЛОГО
// @ Не возвращает ничего если матрица не квадратная
template <typename T>
Matrix<T> Matrix<T>::getInverse() const
{
	// Проверка на пустоту матрицы
	if((m > 0) && (n > 0))
	{
		if(m == n)
		{
			// Детерминант матрицы
			T det = this->det();

			// Проверка на не равенство 0-ю
			// детерминанта
			if(det != 0)
			{
				// Результирующая матрица
				Matrix <T> result(m, n);

				// Заполнение результирующей матрицы
				// алгебраическими дополнениями
				for(size_t i = 0; i < m; i++)
					for(size_t j = 0; j < n; j++)
					result.M[i][j] = this->alg(i, j);

				// Транспонируем результирующйю матрицу
				result.transp();

				// Деление результирующей матрицы на
				// детерминант исходной
				result /= det;

				return result;
			}
			else
				std::cout << "\nError: Determinant of matrix must not be zero!\n";
		}
		else
			std::cout << "\nError: Matrix must be square!\n";
	}
	else
		std::cout << "\nError: Matrix is empty!\n";

}

// Оператор "+".  Складывает матрицы
template <typename T1, typename T2>
Matrix<T1> operator+ (const Matrix<T1>& left, const Matrix<T2>& right)
{
	// Проверка на соответсвие размеров матриц
	if((left.m == right.m) && (left.n == right.n))
	{
		// Результирующая матрица
		Matrix <T1> result(left.m, left.n);

		// Заполнение результирующей матрицы сложением элементов
		for(size_t i = 0; i < result.m; i++)
			for(size_t j = 0; j < result.n; j++)
				result(i, j) = left(i, j) + right(i, j);

		return result;
	}
	else
		std::cout << "The dimensions of the matrices do not match!\n";
}

// Оператор "-".  Вычитает матрицы
template <typename T>
Matrix<T> Matrix<T>::operator- (const Matrix & matrix) const
{
	// Проверка на соответсвие размеров матриц
	if((m == matrix.m) && (n == matrix.n))
	{
		// Результирующая матрица
		Matrix <T> result(m, n);

		// Заполнение результирующей матрицы вычитанием элементов
		for(size_t i = 0; i < result.m; i++)
			for(size_t j = 0; j < result.n; j++)
			result.M[i][j] = M[i][j] - matrix.M[i][j];
		return result;
	}
	else
		std::cout << "The dimensions of the matrices do not match!\n";
}

// Оператор "*".  Умножает матрицу на число (Только в таком порядке!)
template <typename T>
Matrix<T> Matrix<T>::operator* (const T value) const
{
	// Проверка на пустоту матрицы слева
	if((m > 0) && (n > 0))
	{
		// Результирующая матрица
		Matrix <T> result(m, n);

		// Заполнение результирующей матрицы умножением
		// элемента матрицы на число
		for(size_t i = 0; i < result.m; i++)
			for(size_t j = 0; j < result.n; j++)
			result.M[i][j] = M[i][j] * value;
		return result;
	}
	else
		return* this;
}

// Оператор "*".  Перемножает матрицы (По правилу перемножения матриц)
template <typename T>
Matrix<T> Matrix<T>::operator* (const Matrix& matrix) const
{
	// Проверка на пустоту матрицы слева
	if((m > 0) && (n > 0))
	{
		// Проверка на пустоту матрицы справа
		if((matrix.m != 0) && (matrix.n != 0)) {
			// Проверка на соответвие размеров матриц:
			// Кол-во столбцов n левой должно равнятся
			// кол-ву строк matrix.m правой
			if(n == matrix.m)
			{
				// Результирующая матрица
				Matrix <T> result(m, matrix.n);

				// Заполнение результирующей матрицы
				// в соответсвие с правилом перемножения матриц
				for(size_t i = 0; i < result.m; i++)
					for(size_t j = 0; j < result.n; j++)
					for(size_t p = 0; p < n; p++)
					result.M[i][j] += M[i][p] * matrix.M[p][j];
				return result;
			}
		}
		return* this;
	}
	else
		return* this;
}

// Оператор "/".  Делит матрицу на число (Только в таком порядке!)
template <typename T>
Matrix<T> Matrix<T>::operator / (const T value) const
{
	// Проверка на пустоту матрицы
	if((m > 0) && (n > 0))
	{
		// Результирующая матрица
		Matrix <T> result(m, n);

		// Заполнение результирующей матрицы делением
		// элемента матрицы на число
		for(size_t i = 0; i < result.m; i++)
			for(size_t j = 0; j < result.n; j++)
			result.M[i][j] = T(M[i][j] / value);
		return result;
	}
	else
		return* this;
}

// Оператор "+=". Складывает матрицы и присваивает слева
template <typename T>
Matrix<T>& Matrix<T>::operator += (const Matrix & matrix)
{
	// Проверка на соответсвие размеров матриц
	if((m == matrix.m) && (n == matrix.n))
	{
		// Заполнение матрицы сложением элементов
		for(size_t i = 0; i < m; i++)
			for(size_t j = 0; j < n; j++)
			M[i][j] = M[i][j] + matrix.M[i][j];
		return* this;
	}
	else
		std::cout << "\nError: Dimensions of matrices must match!\n";
}

// Оператор "-=". Вычитает матрицы и присваивает слева
template <typename T>
Matrix<T>& Matrix<T>::operator -= (const Matrix & matrix)
{
	// Проверка на соответсвие размеров матриц
	if((m == matrix.m) && (n == matrix.n))
	{
		// Заполнение матрицы вычитанием элементов
		for(size_t i = 0; i < m; i++)
			for(size_t j = 0; j < n; j++)
			M[i][j] = M[i][j] - matrix.M[i][j];
		return* this;
	}
	else
		std::cout << "The dimensions of the matrices don't match!\n";
}

// Оператор "*=". Уможает матрицу на число и присваивает слева
template <typename T>
Matrix<T>& Matrix<T>::operator *= (const T value)
{
	// Проверка на пустоту матрицы
	if((m > 0) && (n > 0))
	{
		// Заполнение матрицы умножением элементов
		// на число
		for(size_t i = 0; i < m; i++)
			for(size_t j = 0; j < n; j++)
			M[i][j] = M[i][j] * value;
	}
	return* this;
}

// Оператор "*=". Перемножает матрицы и присваивает слева
template <typename T>
Matrix<T>& Matrix<T>::operator *= (const Matrix & matrix)
{
	// Проверка на пустоту матрицы слева
	if((m > 0) && (n > 0))
		// Проверка на пустоту матрицы справа
		if((matrix.m > 0) && (matrix.n > 0))
		// Проверка на соответвие размеров матриц:
		// Кол-во столбцов n левой должно равнятся
		// кол-ву строк matrix.m правой
		if(n == matrix.m)
	{
		// Матрица копия матрицы слева
		Matrix <T> copy(*this);

		// Уничтожение динамической памяти
		// матрицы слева
		this->~Matrix();

		// Смена размеров матрицы слева
		m = copy.m;
		n = matrix.n;

		// Выделение динамической памяти
		// для матрицы слева
		M = (T**)new T * [m];
		for(size_t i = 0; i < m; i++)
			M[i] = (T*)new T[n];

		// Заполняем матрицу нулями
		for(size_t i = 0; i < m; i++)
			for(size_t j = 0; j < n; j++)
			M[i][j] = 0;

		// Заполнение матрицы слева в
		// соответсвие с правилом умножения матриц
		for(size_t i = 0; i < m; i++)
			for(size_t j = 0; j < n; j++)
			for(size_t p = 0; p < copy.n; p++)
			M[i][j] += copy.M[i][p] * matrix.M[p][j];

		// @ Нужен ли деструктор copy или нет?
	}
	else
	{ /* @ Избавление от ошибки размерности матриц */
	}
	return* this;
}

// Оператор "/=". Делит матрицу на число и присваивает слева
template <typename T>
Matrix<T>& Matrix<T>::operator /= (const T value)
{
	// Проверка на пустоту матрицы
	if((m > 0) && (n > 0))
	{
		// Заполнение результирующей матрицы делением
		// элемента матрицы на число
		for(size_t i = 0; i < m; i++)
			for(size_t j = 0; j < n; j++)
			M[i][j] = T(M[i][j] / value);
	}
	return* this;
}

// Оператор "++". Постфиксный икремент. Эквивалентен прибавлению ко всем элементам 1-ы
template <typename T>
Matrix<T> Matrix<T>::operator++(int)
{
	// Проверка на пустоту матрицы
	if((m > 0) && (n > 0))
	{
		// Прибавление ко всем элементам матрицы 1-ы
		for(size_t i = 0; i < m; i++)
			for(size_t j = 0; j < n; j++)
			M[i][j] = M[i][j]++;
	}
	return* this;
}

// Оператор "++". Префиксный икремент. Эквивалентен прибавлению ко всем элементам 1-ы
template <typename T>
Matrix<T>& Matrix<T>::operator++()
{
	// Проверка на пустоту матрицы
	if((m > 0) && (n > 0))
	{
		// Прибавление ко всем элементам матрицы 1-ы
		for(size_t i = 0; i < m; i++)
			for(size_t j = 0; j < n; j++)
			M[i][j] = ++M[i][j];
	}
	return* this;
}

// Оператор "--". Постфиксный декремент. Эквивалентен вычитанию из всех элементов 1-ы
template <typename T>
Matrix<T> Matrix<T>::operator--(int)
{
	// Проверка на пустоту матрицы
	if((m != 0) && (n != 0))
	{
		// Вычитание из всех элементов матрицы 1-ы
		for(size_t i = 0; i < m; i++)
			for(size_t j = 0; j < n; j++)
			M[i][j] = M[i][j]--;
	}
	return* this;
}

// Оператор "--". Префиксный декремент. Эквивалентен вычитанию из всех элементов 1-ы
template <typename T>
Matrix<T>& Matrix<T>::operator--()
{
	// Проверка на пустоту матрицы
	if((m > 0) && (n > 0))
	{
		// Вычитание из всех элементов матрицы 1-ы
		for(size_t i = 0; i < m; i++)
			for(size_t j = 0; j < n; j++)
			M[i][j] = --M[i][j];
	}
	return* this;
}

// Оператор "=".  Приравнивает матрицы
template <typename T>
Matrix<T> Matrix<T>::operator = (const Matrix & matrix)
{
	// Уничтожение динамической памяти
	// матрицы слева
	this->~Matrix();

// Смена размеров матрицы слева
m = matrix.m;
n = matrix.n;

// Выделение динамической памяти
// для матрицы слева
M = (T**)new T * [m];
for(size_t i = 0; i < m; i++)
	M[i] = (T*)new T[n];

// Присваивание элементов матрицы слева
// к элементам матрицы справа
for(size_t i = 0; i < m; i++)
	for(size_t j = 0; j < n; j++)
		M[i][j] = matrix.M[i][j];

return* this;
}

// Оператор "[]". Даёт доступ к i строке
// Не имеет защиты от выхода за предела по стобцам!
// @ В будущем перенести в private
template <typename T>
T* Matrix<T>::operator[](size_t i)
{
	// Проверка на пустоту матрицы
	if((m > 0) && (n > 0))
	{
		// Проверка правильность
		// введённого индекса
		if(i < m)
			return M[i];
		else
		{
			std::cout << "Invalid index!\n";
			return 0;
		}
	}
	else
	{
		std::cout << "Matrix is empty!\n";
		return 0;
	}
}

// Перегрузка оператора "()".
// Обращение к элементам матрицы с проверкой индексов.
// Если индексы указаны неправильно, остановит
// программу с ошибкой.
template <typename T>
T& Matrix<T>::operator()(size_t i, size_t j) const
{
	// Проверка на пустоту матрицы
	if((m > 0) && (n > 0))
	{
		// Проверка на правильность
		// введённых индексов
		if((i < m) && (j < n))
		{
			return M[i][j];
		}
		else
			std::cout << "Invalid indexes!\n";
	}
	else
		std::cout << "Matrix is empty!\n";

	return** M;
}

template <typename T>
Matrix<T> randM(size_t m, size_t n, T min, T max)
{
	srand(time(0));
	Matrix<T> result(m, n);

	for(size_t i = 0; i < m; i++)
		for(size_t j = 0; j < n; j++)
		result(i, j) = min + ((max - min) * (rand() / 32766.f));

	return result;
}

// Функция произведения кронекера.
// Если одна из двух матриц или все пустые,
// то функция вернёт пустую матрицу.
template <typename T>
Matrix<T> kron(const Matrix<T>& A, const Matrix<T>& B)
{
	// Копируем размеры матриц для удобства
	size_t m_A = A.getNumRow();
	size_t n_A = A.getNumCol();
	size_t m_B = B.getNumRow();
	size_t n_B = B.getNumCol();

	// Проверка на пустоту первой матрицы
	if((m_A > 0) && (n_A > 0))
	{
		if((m_B > 0) && (n_B > 0))
		{
			// Результирующая матрица
			size_t m_R = m_A * m_B;
			size_t n_R = n_A * n_B;
			Matrix<T> result(m_R, n_R);

			// Заполнение результирующей матрицы в соответствие
			// с произведением кронекера
			for(size_t i = 0; i < m_R; i++)
				for(size_t j = 0; j < n_R; j++)
				result(i, j) = A.get(size_t(i / m_B), size_t(j / n_B)) * B.get(i % m_B, j % n_B);

			return result;
		}
		else
		{
			std::cout << "Second matrix is empty!\n";
			return B;
		}
	}
	else
	{
		std::cout << "First matrix is empty!\n";
		return A;
	}
}


// Функция прямого произведения матриц
template <typename T>
Matrix<T> x(const Matrix<T>& A, const Matrix<T>& B)
{
	// Копируем размеры матриц для удобства
	size_t m_A = A.getNumRow();
	size_t n_A = A.getNumCol();
	size_t m_B = B.getNumRow();
	size_t n_B = B.getNumCol();

	// Проверка на пустоту первой матрицы
	if((m_A > 0) && (n_A > 0))
	{
		if((m_B > 0) && (n_B > 0))
		{
			if((m_A == m_B) && (n_A == n_B))
			{
				// Результирующая матрица
				Matrix<T> result(m_A, n_A);

				// Заполнение результирующей матрицы в соответствие
				// с прямым произведением матриц
				for(size_t i = 0; i < m_A; i++)
					for(size_t j = 0; j < n_A; j++)
					result(i, j) = A.get(i, j) * B.get(i, j);

				return result;
			}
			else
				std::cout << "\nError: Dimensions of matrices must match!\n";
		}
		else
		{
			std::cout << "\nWarrning: Second matrix is empty!\n";
			return B;
		}
	}
	else
	{
		std::cout << "\nWarrning: First matrix is empty!\n";
		return A;
	}
}

// Функция возвращающая сумму по столбцам, строкам и всех элементов
// dim::row - сумма по строкам (вернёт вектор столбец)
// dim::col - сумма по стобцам (вернёт вектор строку)
// dim::all - сумма всех элементов (вернёт матрицу 1х1)
// Если матрица пустая, то вернёт пустую матрицу
template <typename T>
Matrix<T> sum(const Matrix<T>& A, dim _dim)
{
	// Запись размеров матрицы для удобства
	size_t m_A = A.getNumRow();
	size_t n_A = A.getNumCol();

	// Проверка на размеры матрицы
	if((m_A > 0) && (n_A > 0))
	{
		// Результирующая матрица
		Matrix<T> result;

		// Переключение между вариантами суммирования
		switch (_dim)
		{
		case dim::row:
			result.resize(m_A, 1);
			for(size_t i = 0; i < m_A; i++)
				for(size_t j = 0; j < n_A; j++)
				result(i, 0) += A.get(i, j);
			break;
		case dim::col:
			result.resize(1, n_A);
			for(size_t i = 0; i < m_A; i++)
				for(size_t j = 0; j < n_A; j++)
				result(0, j) += A.get(i, j);
			break;
		case dim::all:
			result.resize(1, 1);
			for(size_t i = 0; i < m_A; i++)
				for(size_t j = 0; j < n_A; j++)
				result(0, 0) += A.get(i, j);
			break;
		}

		return result;
	}
	else
	{
		std::cout << "\nWarnning: Matrix is empty!\n";
		return A;
	}
}

//
template <typename T>
Matrix<T> sqrt(const Matrix<T>& A)
{
	// Запись размеров матрицы для удобства
	size_t m_A = A.getNumRow();
	size_t n_A = A.getNumCol();

	// Проверка на пустоту матрицы
	if((m_A > 0) && (n_A > 0))
	{
		// Результирующая матрица
		Matrix<T> result(m_A, n_A);

		for(size_t i = 0; i < m_A; i++)
			for(size_t j = 0; j < n_A; j++)
		{
			// Проверка на положительность элемента
			assert(A.get(i, j) >= 0);
			result(i, j) = sqrt(A.get(i, j));
		}
		return result;
	}
	else
	{
		std::cout << "\nWarrning: Matrix is empty!\n";
		return A;
	}
}