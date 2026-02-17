/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascoal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:27:53 by mpascoal          #+#    #+#             */
/*   Updated: 2026/02/17 10:27:55 by mpascoal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

int main(int, char**)
{
	std::cout << "\n=== Array Template Tests ===\n" << std::endl;

	// Test 1: Empty array
	std::cout << "Test 1: Empty array" << std::endl;
	{
		Array<int> empty;
		std::cout << "Size: " << empty.size() << std::endl;
	}

	// Test 2: Array initialization and access
	std::cout << "\nTest 2: Array initialization and access" << std::endl;
	{
		Array<int> numbers(5);
		
		for (unsigned int i = 0; i < numbers.size(); i++)
			numbers[i] = i * 10;
		
		std::cout << "Values: ";
		for (unsigned int i = 0; i < numbers.size(); i++)
			std::cout << numbers[i] << " ";
		std::cout << std::endl;
	}

	// Test 3: Deep copy (copy constructor and assignment)
	std::cout << "\nTest 3: Deep copy" << std::endl;
	{
		Array<int> original(3);
		original[0] = 100;
		original[1] = 200;
		original[2] = 300;
		
		Array<int> copy(original);
		copy[0] = 999;
		
		std::cout << "Original[0]: " << original[0] << " (should be 100)" << std::endl;
		std::cout << "Copy[0]: " << copy[0] << " (should be 999)" << std::endl;
	}

	// Test 4: Exception handling
	std::cout << "\nTest 4: Exception handling" << std::endl;
	{
		Array<int> numbers(5);
		
		try
		{
			numbers[2] = 42;
			std::cout << "Valid access [2]: " << numbers[2] << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
		
		try
		{
			numbers[10] = 99;
			std::cout << "Should not print this!" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception caught [10]: " << e.what() << std::endl;
		}
	}

	// Test 5: Different types
	std::cout << "\nTest 5: Different types" << std::endl;
	{
		Array<std::string> strings(3);
		strings[0] = "Hello";
		strings[1] = "World";
		strings[2] = "!";
		
		std::cout << "Strings: ";
		for (unsigned int i = 0; i < strings.size(); i++)
			std::cout << strings[i] << " ";
		std::cout << std::endl;
	}

	std::cout << "\n=== All tests completed ===\n" << std::endl;
	return 0;
}
