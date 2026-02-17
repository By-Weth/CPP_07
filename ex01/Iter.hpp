/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascoal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 01:14:33 by mpascoal          #+#    #+#             */
/*   Updated: 2026/02/17 01:14:36 by mpascoal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

// Version for non-const functions (can modify elements)
template <typename T>
void iter(T* array, size_t length, void (*func)(T&))
{
	if (array == NULL || func == NULL)
		return;
	
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

// Version for const functions (read-only)
template <typename T>
void iter(T* array, size_t length, void (*func)(const T&))
{
	if (array == NULL || func == NULL)
		return;
	
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

#endif
