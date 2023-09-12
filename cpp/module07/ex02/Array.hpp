#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>

template <typename T>
class Array
{
	private:
		T*				_arr;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& object);
		Array&	operator=(const Array& other_arr);
		virtual ~Array();

		T& operator[](unsigned int idx) const;
		unsigned int size() const;
};

template <typename T>
Array<T>::Array(): _size(0) 
{
	this->_arr = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n): _size(n)
{
	this->_arr = new T[n];
}

template <typename T>
Array<T>::Array(const Array& object): _size(object._size)
{
	this->_arr = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_arr[i] = object._arr[i];
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& other_arr)
{
	if (this == &other_arr)
		return *this;
	
	delete[] this->_arr;
	this->_arr = new T[other_arr._size];
	this->_size = other_arr._size;
	for (unsigned int i = 0; i < this->_size; i++)
		this->_arr[i] = other_arr._arr[i];
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->_arr;
}

template <typename T>
T&	Array<T>::operator[](const unsigned int idx) const
{
	if (idx < 0 || idx >= this->_size)
		throw std::out_of_range("Invalid index");
	return this->_arr[idx];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}

#endif