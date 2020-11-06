#pragma once
#ifndef _Stack_
#define _Stack_

#include <iostream>

using namespace std;

template <class T>
class TStack
{
protected:
    int length;
    T* x;
    int ind; //вершина стека
public:
    TStack(int size);
    TStack(const TStack<T>& S);
    virtual ~TStack();

    TStack<T>& operator =(const TStack<T>& S);

    void Push(T dannye); //положить
    T Get(); //взять из вершины и удалить, либо посмотреть  и удалить вершину

    template <class T1>
    friend ostream& operator<< (ostream& ostr, const TStack<T1>& S);
    template <class T1>
    friend istream& operator>> (istream& istr, TStack<T1>& S);

    int GetLength();
    int GetInd();
};

template <class T>
inline TStack<T>::TStack(int size)
{
    if (size < 0)
        throw exception();
    this->length = size;
    x = new T[length];
    for (int i = 0; i < length; i++)
        x[i] = 0;
    this->ind = 0;
}

template <class T>
inline TStack<T>::TStack(const TStack<T>& S)
{
    this->length = S.length;
    this->ind = S.ind;
    x = new T[length];
    for (int i = 0; i < length; i++)
        x[i] = S.x[i];
}

template <class T>
inline TStack<T>::~TStack()
{
    if (x != NULL)
        delete[] x;
    else throw exception();
    x = NULL;
    this->length = 0;
    this->ind = 0;
}


template <class T>
inline TStack<T>& TStack<T>::operator =(const TStack<T>& S)
{
    if (this == &S)
        return *this;
    if (length != S.length)
    {
        delete[] x;
        x = new T[S.length];
    }
    this->length = S.length;
    this->ind = S.ind;
    for (int i = 0; i < length; i++)
        x[i] = S.x[i];
    return *this;
}

template<class T>
inline void TStack<T>::Push(T dannye)
{
    if (ind >= length)
        throw exception();
    x[ind] = dannye;
    ind++;
}

template<class T>
inline T TStack<T>::Get()
{
    if (ind == 0)
        throw exception();
    T d = x[ind - 1];
    ind--;
    return d;
}



template <class T1>
ostream& operator<< (ostream& ostr, const TStack<T1>& A) 
{
    for (int i = 0; i < A.ind; i++)
    {
        ostr << A.x[i] << endl;
    }
    return ostr;
}

template <class T1>
istream& operator >> (istream& istr, TStack<T1>& A) 
{
    int count;
    istr >> count; //количество элементов, которое хотим положить
    for (int i = 0; i < count; i++)
    {
        T1 d;
        istr >> d;
        A.Push(d);
    }
    return istr;
}

template <class T>
int TStack<T>::GetLength()
{
    return length;
}

template <class T>
int TStack<T>::GetInd()
{
    return ind;
}

#endif //_Stack_