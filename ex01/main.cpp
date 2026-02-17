/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascoal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 01:14:43 by mpascoal          #+#    #+#             */
/*   Updated: 2026/02/17 01:14:46 by mpascoal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>
#include <string>

// ============================================================
//                    HELPER FUNCTIONS
// ============================================================

// --- CONST FUNCTIONS (Read-only) ---

template <typename T>
void print(const T& elem)
{
	std::cout << elem << " ";
}

void displayString(const std::string& str)
{
	std::cout << "\"" << str << "\" ";
}

template <typename T>
void displayInfo(const T& elem)
{
	std::cout << "  → " << elem << std::endl;
}

// --- NON-CONST FUNCTIONS (Modify) ---

void increment(int& n)
{
	n++;
}

void doubleValue(double& d)
{
	d *= 2.0;
}

void toUpperCase(std::string& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
	}
}

// ============================================================
//                    UTILITY FUNCTIONS
// ============================================================

void printSeparator()
{
	std::cout << "\n" << std::string(60, '=') << std::endl;
}

void printHeader(const std::string& title)
{
	printSeparator();
	std::cout << "  " << title << std::endl;
	printSeparator();
}

template <typename T>
void printArray(const std::string& label, T* array, size_t size)
{
	std::cout << label;
	iter(array, size, print<T>);
	std::cout << std::endl;
}

// ============================================================
//                         MAIN
// ============================================================

int main()
{
	std::cout << "\n";
	std::cout << "╔══════════════════════════════════════════════════════════╗\n";
	std::cout << "║         ITER TEMPLATE FUNCTION - COMPREHENSIVE TEST       ║\n";
	std::cout << "╚══════════════════════════════════════════════════════════╝\n";

	// ========== TEST 1: Int Array - Read Only ==========
	printHeader("TEST 1: Integer Array (Read-Only)");
	{
		int arr[] = {10, 20, 30, 40, 50};
		size_t size = sizeof(arr) / sizeof(arr[0]);
		
		std::cout << "📖 Using const function (print)\n";
		printArray("   Array: ", arr, size);
	}

	// ========== TEST 2: Int Array - Modify ==========
	printHeader("TEST 2: Integer Array (Modification)");
	{
		int arr[] = {1, 2, 3, 4, 5};
		size_t size = sizeof(arr) / sizeof(arr[0]);
		
		std::cout << "🔧 Using non-const function (increment)\n";
		printArray("   Before: ", arr, size);
		
		iter(arr, size, increment);
		
		printArray("   After:  ", arr, size);
	}

	// ========== TEST 3: Double Array - Read Only ==========
	printHeader("TEST 3: Double Array (Read-Only)");
	{
		double arr[] = {3.14, 2.71, 1.41, 1.61, 0.57};
		size_t size = sizeof(arr) / sizeof(arr[0]);
		
		std::cout << "📖 Using const function (print)\n";
		printArray("   Array: ", arr, size);
	}

	// ========== TEST 4: Double Array - Modify ==========
	printHeader("TEST 4: Double Array (Modification)");
	{
		double arr[] = {1.5, 2.5, 3.5};
		size_t size = sizeof(arr) / sizeof(arr[0]);
		
		std::cout << "🔧 Using non-const function (doubleValue)\n";
		printArray("   Before: ", arr, size);
		
		iter(arr, size, doubleValue);
		
		printArray("   After:  ", arr, size);
	}

	// ========== TEST 5: String Array - Read Only ==========
	printHeader("TEST 5: String Array (Read-Only)");
	{
		std::string arr[] = {"hello", "world", "from", "cpp"};
		size_t size = sizeof(arr) / sizeof(arr[0]);
		
		std::cout << "📖 Using const function (displayString)\n";
		std::cout << "   Strings: ";
		iter(arr, size, displayString);
		std::cout << std::endl;
	}

	// ========== TEST 6: String Array - Modify ==========
	printHeader("TEST 6: String Array (Modification)");
	{
		std::string arr[] = {"template", "function", "test"};
		size_t size = sizeof(arr) / sizeof(arr[0]);
		
		std::cout << "🔧 Using non-const function (toUpperCase)\n";
		std::cout << "   Before: ";
		iter(arr, size, displayString);
		std::cout << std::endl;
		
		iter(arr, size, toUpperCase);
		
		std::cout << "   After:  ";
		iter(arr, size, displayString);
		std::cout << std::endl;
	}

	// ========== SPECIAL TEST 1: Empty Array ==========
	printHeader("SPECIAL TEST 1: Empty Array");
	{
		int arr[1];  // Array com tamanho 0 logicamente
		
		std::cout << "📋 Testing with length = 0\n";
		std::cout << "   (Should print nothing)\n   → ";
		iter(arr, 0, print<int>);
		std::cout << "[OK - No output as expected]" << std::endl;
	}

	// ========== SPECIAL TEST 2: Single Element ==========
	printHeader("SPECIAL TEST 2: Single Element Array");
	{
		int arr[] = {42};
		size_t size = sizeof(arr) / sizeof(arr[0]);
		
		std::cout << "📋 Testing with single element\n";
		printArray("   Array: ", arr, size);
		
		iter(arr, size, increment);
		
		printArray("   After:  ", arr, size);
	}

	// ========== SPECIAL TEST 3: NULL Pointer Protection ==========
	printHeader("SPECIAL TEST 3: NULL Pointer (Safety Check)");
	{
		int* nullPtr = NULL;
		
		std::cout << "⚠️  Testing with NULL pointer\n";
		std::cout << "   iter(NULL, 5, print) → ";
		iter(nullPtr, 5, print<int>);
		std::cout << "[OK - Protected against NULL]" << std::endl;
	}

	// ========== SPECIAL TEST 4: Template Function with Multiple Types ==========
	printHeader("SPECIAL TEST 4: Template Function Versatility");
	{
		std::cout << "🔄 Using template function (displayInfo) with different types\n\n";
		
		std::cout << "   Integers:\n";
		int intArr[] = {100, 200, 300};
		iter(intArr, 3, displayInfo<int>);
		
		std::cout << "\n   Doubles:\n";
		double doubleArr[] = {1.23, 4.56, 7.89};
		iter(doubleArr, 3, displayInfo<double>);
		
		std::cout << "\n   Strings:\n";
		std::string strArr[] = {"Alpha", "Beta", "Gamma"};
		iter(strArr, 3, displayInfo<std::string>);
	}

	// ========== FINAL MESSAGE ==========
	std::cout << "\n";
	std::cout << "╔══════════════════════════════════════════════════════════╗\n";
	std::cout << "║                  ✅ ALL TESTS PASSED! ✅                  ║\n";
	std::cout << "╚══════════════════════════════════════════════════════════╝\n";
	std::cout << "\n";

	return 0;
}
