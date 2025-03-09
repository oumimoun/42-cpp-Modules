#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
private:
    T *elements;
    unsigned int _size;

public:
    Array() : elements(NULL), _size(0)
    {
    }

    Array(unsigned int n) : _size(n)
    {
        elements = new T[n]();
    }

    Array(const Array &other) : _size(other._size)
    {
        elements = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
        {
            elements[i] = other.elements[i];
        }
    }

    Array &operator=(const Array &other)
    {
        if (this != &other)
        {
            _size = other._size;
            delete[] elements;
            elements = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
            {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    T &operator[](unsigned int index)
    {
        if (index >= _size)
            throw std::out_of_range("Index is out of bounds");
        return elements[index];
    }

    const T &operator[](unsigned int index) const
    {
        if (index >= _size)
            throw std::out_of_range("Index is out of bounds");
        return elements[index];
    }

    unsigned int size() const
    {
        return _size;
    }

    ~Array()
    {
        delete[] elements;
    }

};

#endif