#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class MyVector
{
public:
    MyVector();
    MyVector(size_t size);
    MyVector(std::initializer_list<T> lst);
    MyVector(const MyVector<T>& vec);
    ~MyVector();

    void clear();
    void addElement(T& element);
    void popElement(size_t key);
    T& getElement(size_t key);
    size_t getSize();

    class Iterator;
    Iterator begin();
    Iterator end();

private:
    size_t mSize;
    T* mBuffer;
};

template <typename T>
MyVector<T>::MyVector() : mSize{ 0 }, mBuffer{ nullptr }
{
}

template <typename T>
MyVector<T>::MyVector(size_t size) : mSize{ size }, mBuffer{ new T[size] }
{
    for (int i = 0; i < mSize; i++)
    {
        mBuffer[i] = 0;
    }
}

template <typename T>
MyVector<T>::MyVector(std::initializer_list<T> lst) : mSize{ lst.size() }, mBuffer{ new T[lst.size()] }
{
    std::copy(lst.begin(), lst.end(), this->mBuffer);
}


template <typename T>
MyVector<T>::MyVector(const MyVector<T>& vec)
    : mSize(vec.mSize)
    , mBuffer( new T[vec.mSize])
{
    mBuffer = vec.mBuffer;
}

template <typename T>
MyVector<T>::~MyVector()
{
    mSize = 0;
    delete[] mBuffer;
}

template<typename T>
inline void MyVector<T>::clear()
{
    mSize = 0;
}

template <typename T>
void MyVector<T>::addElement(T& element)
{
    T* result = new T[mSize + 1];
    for (size_t i = 0; i < mSize; i++)
    {
        result[i] = mBuffer[i];
    }
    result[mSize++] = element;
    mBuffer = result;

}

template <typename T>
void MyVector<T>::popElement(size_t key)
{
    if ((key >= 0) && (key < mSize))
    {
        T* result = new T[--mSize];
        bool flag = false;
        for (int i = 0; i < mSize; i++)
        {
            if (i == key)
                flag = true;
            result[i] = mBuffer[i + flag];
        }
        mBuffer = result;
    }
    else
        throw std::out_of_range{ "Вихід за межі вектора!" };
}

template <typename T>
T& MyVector<T>::getElement(size_t key)
{
    if ((key >= 0) && (key < mSize))
        return *(mBuffer + key);
    else 
        throw std::out_of_range{ "Вихід за межі вектора!" };
}

template <typename T>
size_t MyVector<T>::getSize()
{
    return mSize;
}

template <typename T>
class MyVector<T>::Iterator
{
public:
    Iterator(T* ptr);

    Iterator& operator++(); 
    Iterator& operator--(); 
    Iterator& operator++(int);
    Iterator& operator--(int);
    T& operator*();
    friend int operator-(Iterator i1, Iterator i2) { return i1.mPtr - i2.mPtr; }
    bool operator==(const Iterator& iter);
    bool operator!=(const Iterator& iter);
private:
    T* mPtr;
};

template <typename T>
MyVector<T>::Iterator::Iterator(T* ptr) : mPtr{ ptr }
{
}


template <typename T>
typename MyVector<T>::Iterator& MyVector<T>::Iterator::operator++()
{
    this->mPtr++;
    return *this;
}

template <typename T>
typename MyVector<T>::Iterator& MyVector<T>::Iterator::operator--()
{
    this->mPtr--;
    return *this;
}


template <typename T>
typename MyVector<T>::Iterator& MyVector<T>::Iterator::operator++(int)
{
    this->mPtr++;
    return *this;
}

template <typename T>
typename MyVector<T>::Iterator& MyVector<T>::Iterator::operator--(int)
{
    this->mPtr--;
    return *this;
}

template <typename T>
T& MyVector<T>::Iterator::operator*()
{
    return *this->mPtr;
}

template <typename T>
bool MyVector<T>::Iterator::operator==(const Iterator& iter)
{
    return this->mPtr == iter.mPtr;
}

template <typename T>
bool MyVector<T>::Iterator::operator!=(const Iterator& iter)
{
    return this->mPtr != iter.mPtr;
}

template <typename T>
typename MyVector<T>::Iterator MyVector<T>::begin()
{
    return MyVector<T>::Iterator{ this->mBuffer };
}

template <typename T>
typename MyVector<T>::Iterator MyVector<T>::end()
{
    return MyVector<T>::Iterator{ this->mBuffer + this->mSize };
}
