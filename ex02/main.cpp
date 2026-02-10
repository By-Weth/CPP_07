#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    std::cout << "=== Test 1: Default Constructor ===" << std::endl;
    {
        Array<int> empty;
        std::cout << "Empty array size: " << empty.size() << std::endl;
    }

    std::cout << "\n=== Test 2: Parametric Constructor ===" << std::endl;
    {
        Array<int> numbers(MAX_VAL);
        std::cout << "Array size: " << numbers.size() << std::endl;
    }

    std::cout << "\n=== Test 3: Initialize and Access Elements ===" << std::endl;
    {
        Array<int> numbers(5);
        std::cout << "Array size: " << numbers.size() << std::endl;
        
        // Preencher array
        for (unsigned int i = 0; i < numbers.size(); i++) {
            numbers[i] = i * 10;
        }
        
        // Exibir array
        std::cout << "Array contents: ";
        for (unsigned int i = 0; i < numbers.size(); i++) {
            std::cout << numbers[i] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n=== Test 4: Copy Constructor (Deep Copy) ===" << std::endl;
    {
        Array<int> original(3);
        original[0] = 100;
        original[1] = 200;
        original[2] = 300;
        
        Array<int> copy(original);
        
        std::cout << "Original: ";
        for (unsigned int i = 0; i < original.size(); i++) {
            std::cout << original[i] << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Copy: ";
        for (unsigned int i = 0; i < copy.size(); i++) {
            std::cout << copy[i] << " ";
        }
        std::cout << std::endl;
        
        // Modificar cópia
        copy[0] = 999;
        
        std::cout << "After modifying copy[0] = 999:" << std::endl;
        std::cout << "Original[0]: " << original[0] << std::endl;
        std::cout << "Copy[0]: " << copy[0] << std::endl;
    }

    std::cout << "\n=== Test 5: Assignment Operator (Deep Copy) ===" << std::endl;
    {
        Array<int> original(3);
        original[0] = 10;
        original[1] = 20;
        original[2] = 30;
        
        Array<int> assigned(5);
        assigned = original;
        
        std::cout << "Original size: " << original.size() << std::endl;
        std::cout << "Assigned size: " << assigned.size() << std::endl;
        
        std::cout << "Original: ";
        for (unsigned int i = 0; i < original.size(); i++) {
            std::cout << original[i] << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Assigned: ";
        for (unsigned int i = 0; i < assigned.size(); i++) {
            std::cout << assigned[i] << " ";
        }
        std::cout << std::endl;
        
        // Modificar assigned
        assigned[1] = 777;
        
        std::cout << "After modifying assigned[1] = 777:" << std::endl;
        std::cout << "Original[1]: " << original[1] << std::endl;
        std::cout << "Assigned[1]: " << assigned[1] << std::endl;
    }

    std::cout << "\n=== Test 6: Out of Bounds Exception ===" << std::endl;
    {
        Array<int> numbers(5);
        
        try {
            std::cout << "Accessing valid index [2]..." << std::endl;
            numbers[2] = 42;
            std::cout << "Success! Value: " << numbers[2] << std::endl;
        } catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        
        try {
            std::cout << "Accessing invalid index [10]..." << std::endl;
            numbers[10] = 99;
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        try {
            std::cout << "Accessing invalid index on empty array..." << std::endl;
            Array<int> empty;
            empty[0] = 1;
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }

    std::cout << "\n=== Test 7: Array of Strings ===" << std::endl;
    {
        Array<std::string> strings(3);
        strings[0] = "Hello";
        strings[1] = "World";
        strings[2] = "!";
        
        std::cout << "String array: ";
        for (unsigned int i = 0; i < strings.size(); i++) {
            std::cout << strings[i] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n=== Test 8: Array of Floats ===" << std::endl;
    {
        Array<float> floats(4);
        for (unsigned int i = 0; i < floats.size(); i++) {
            floats[i] = i * 3.14f;
        }
        
        std::cout << "Float array: ";
        for (unsigned int i = 0; i < floats.size(); i++) {
            std::cout << floats[i] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n=== Test 9: Large Array (Subject Test) ===" << std::endl;
    {
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        
        // Scope para testar destrutor
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                delete[] mirror;
                return 1;
            }
        }
        
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Exception caught (negative index): " << e.what() << '\n';
        }
        
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Exception caught (out of bounds): " << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        
        delete[] mirror;
        std::cout << "Large array test passed!" << std::endl;
    }

    std::cout << "\n=== All Tests Completed ===" << std::endl;
    return 0;
}
