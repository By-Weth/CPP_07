#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
private:
    T*              _elements;
    unsigned int    _size;

public:
    // Orthodox Canonical Form
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    // Member functions
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    unsigned int size() const;

    // Exception class
    class OutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Index out of bounds";
        }
    };
};

#include "Array.tpp"

#endif
