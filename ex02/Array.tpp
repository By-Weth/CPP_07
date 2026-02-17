/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascoal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:27:45 by mpascoal          #+#    #+#             */
/*   Updated: 2026/02/17 10:27:48 by mpascoal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

// ============================================================
//                     CONSTRUCTORS
// ============================================================

template <typename T>
Array<T>::Array() : _elements(NULL), _size(0)
{
	std::cout << "Array: Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _elements(NULL), _size(n)
{
	std::cout << "Array: Parametric constructor called (size: " << n << ")" << std::endl;
	
	if (n > 0)
		_elements = new T[n]();
}

template <typename T>
Array<T>::Array(const Array& other) : _elements(NULL), _size(other._size)
{
	std::cout << "Array: Copy constructor called" << std::endl;
	
	if (_size > 0)
	{
		_elements = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_elements[i] = other._elements[i];
	}
}

// ============================================================
//                       DESTRUCTOR
// ============================================================

template <typename T>
Array<T>::~Array()
{
	std::cout << "Array: Destructor called" << std::endl;
	
	if (_elements != NULL)
		delete[] _elements;
}

// ============================================================
//                   ASSIGNMENT OPERATOR
// ============================================================

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	std::cout << "Array: Assignment operator called" << std::endl;
	
	if (this != &other)
	{
		if (_elements != NULL)
			delete[] _elements;
		
		_size = other._size;
		
		if (_size > 0)
		{
			_elements = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_elements[i] = other._elements[i];
		}
		else
		{
			_elements = NULL;
		}
	}
	
	return *this;
}

// ============================================================
//                   SUBSCRIPT OPERATORS
// ============================================================

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _elements[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _elements[index];
}

// ============================================================
//                    MEMBER FUNCTIONS
// ============================================================

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

#endif
