////////////////////////////////////////////////////////////
template <typename T>
Tensor<T>::Tensor(size_t rang, const size_t* size) : r(rang), ms(1)
{
	s = (size_t*) new size_t[r];

	for (size_t i = 0; i < r; i++)
	{
		s[i] = size[i];
		ms *= size[i];
	}

	mas = (T*) new T[ms];

	for (size_t i = 0; i < ms; i++)
		mas[i] = 0;
}

////////////////////////////////////////////////////////////
template <typename T>
Tensor<T>::Tensor(size_t rang, const size_t* size, const T* mas) : Tensor(rang, size)
{
	for (size_t i = 0; i < ms; i++)
		this->mas[i] = mas[i];
}

////////////////////////////////////////////////////////////
template <typename T>
Tensor<T>::~Tensor()
{
	delete[] mas;
	delete[] s;
}