/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:12:04 by srapin            #+#    #+#             */
/*   Updated: 2024/03/20 18:02:27 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
	private:
		T*			_arr;
		unsigned int _size;
	protected:
		T* getArray() const {return (_arr);};

	public:
		Array() : _arr(new T[0]()), _size(0)  {};
		Array(unsigned int n) : _arr(new T[n]()), _size(n)  {};
        ~Array() {delete[] _arr;};
		
        Array(const Array& other);
        Array &operator=(const Array& other);

		T& operator[](unsigned int i);
		unsigned int size() const {return _size;};
		
		class OutOfRange : public std::exception
		{
			public:
				const char *what() const throw() {return "Array: Exception: index out of bounds";};
		};
		
};


template <typename T>
Array<T>::Array(const Array<T>& other) : _arr(new T(other.size())), _size(other.size()) {
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	delete[] _arr;
	_size = other.size();
	_arr = new T[_size];
	for (int i = 0; i < _size; i++)
		_arr[i] = other.getArray()[i];
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= _size || i < 0)
		throw Array<T>::OutOfRange();
	return _arr[i];
}

#endif