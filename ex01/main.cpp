#include "Iter.hpp"
#include <iostream>
#include <string>

// Template function for printing (const - read-only)
template <typename T>
void print(const T& elem)
{
	std::cout << elem << " ";
}

// Function to increment integers (non-const - modifies)
void increment(int& n)
{
	n++;
}

// Function to make strings uppercase (non-const - modifies)
void toUpperCase(std::string& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
	}
}

// Function to display strings (const - read-only)
void displayString(const std::string& str)
{
	std::cout << "[" << str << "] ";
}

// Function to double values (non-const - modifies)
void doubleValue(double& d)
{
	d *= 2.0;
}

// Template function to display with type info (const - read-only)
template <typename T>
void displayWithType(const T& elem)
{
	std::cout << "Value: " << elem << std::endl;
}

int main()
{
	std::cout << "=== Test 1: Array of integers (read-only) ===" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	std::cout << "Original: ";
	iter(intArray, 5, print<int>);
	std::cout << std::endl;
	
	std::cout << "\n=== Test 2: Array of integers (modify) ===" << std::endl;
	std::cout << "Before increment: ";
	iter(intArray, 5, print<int>);
	std::cout << std::endl;
	
	iter(intArray, 5, increment);
	
	std::cout << "After increment:  ";
	iter(intArray, 5, print<int>);
	std::cout << std::endl;
	
	std::cout << "\n=== Test 3: Array of doubles ===" << std::endl;
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::cout << "Original: ";
	iter(doubleArray, 5, print<double>);
	std::cout << std::endl;
	
	iter(doubleArray, 5, doubleValue);
	
	std::cout << "After doubling: ";
	iter(doubleArray, 5, print<double>);
	std::cout << std::endl;
	
	std::cout << "\n=== Test 4: Array of strings (read-only) ===" << std::endl;
	std::string stringArray[] = {"hello", "world", "cpp", "templates"};
	std::cout << "Original strings: ";
	iter(stringArray, 4, displayString);
	std::cout << std::endl;
	
	std::cout << "\n=== Test 5: Array of strings (modify) ===" << std::endl;
	iter(stringArray, 4, toUpperCase);
	std::cout << "After uppercase: ";
	iter(stringArray, 4, displayString);
	std::cout << std::endl;
	
	std::cout << "\n=== Test 6: Array of chars ===" << std::endl;
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	std::cout << "Characters: ";
	iter(charArray, 5, print<char>);
	std::cout << std::endl;
	
	std::cout << "\n=== Test 7: Template function with different types ===" << std::endl;
	std::cout << "Integers:" << std::endl;
	int nums[] = {10, 20, 30};
	iter(nums, 3, displayWithType<int>);
	
	std::cout << "Strings:" << std::endl;
	std::string words[] = {"ONE", "TWO", "THREE"};
	iter(words, 3, displayWithType<std::string>);
	
	std::cout << "\n=== All tests completed successfully! ===" << std::endl;
	
	return 0;
}
