/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascoal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:27:35 by mpascoal          #+#    #+#             */
/*   Updated: 2026/02/17 10:27:37 by mpascoal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
#include <cstdlib>
#include <ctime>

template <typename T>
class Array
{
private:
	T*				_elements;
	unsigned int	_size;

public:
	// Orthodox Canonical Form
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	// Operators
	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;

	// Member functions
	unsigned int size() const;

	// Exception class
	class OutOfBoundsException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return "Index out of bounds";
		}
	};
};

# include "Array.tpp"

#endif
