#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

// Construtor padrão - cria array vazio
template <typename T>
Array<T>::Array() : _elements(NULL), _size(0) {
    std::cout << "Array default constructor called" << std::endl;
}

// Construtor com tamanho - cria array com n elementos inicializados por padrão
template <typename T>
Array<T>::Array(unsigned int n) : _elements(NULL), _size(n) {
    std::cout << "Array parametric constructor called (size: " << n << ")" << std::endl;
    if (n > 0) {
        _elements = new T[n]();  // () inicializa com valores padrão
    }
}

// Construtor de cópia - deep copy
template <typename T>
Array<T>::Array(const Array& other) : _elements(NULL), _size(other._size) {
    std::cout << "Array copy constructor called" << std::endl;
    if (_size > 0) {
        _elements = new T[_size];
        for (unsigned int i = 0; i < _size; i++) {
            _elements[i] = other._elements[i];
        }
    }
}

// Operador de atribuição - deep copy
template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    std::cout << "Array assignment operator called" << std::endl;
    if (this != &other) {
        // Libera memória antiga
        if (_elements != NULL) {
            delete[] _elements;
        }
        
        // Copia novo tamanho e aloca nova memória
        _size = other._size;
        if (_size > 0) {
            _elements = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                _elements[i] = other._elements[i];
            }
        } else {
            _elements = NULL;
        }
    }
    return *this;
}

// Destrutor
template <typename T>
Array<T>::~Array() {
    std::cout << "Array destructor called" << std::endl;
    if (_elements != NULL) {
        delete[] _elements;
    }
}

// Operador de acesso [] - versão não-const
template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size) {
        throw OutOfBoundsException();
    }
    return _elements[index];
}

// Operador de acesso [] - versão const
template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size) {
        throw OutOfBoundsException();
    }
    return _elements[index];
}

// Retorna o tamanho do array
template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

#endif
