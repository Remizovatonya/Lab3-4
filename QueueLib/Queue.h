#pragma once
#ifndef _Stack_
#define _Stack_

#include <iostream>

using namespace std;

template <class T>
class TQueue
{
protected:
    int length;
    T* x;
    int ind; //вершина стека
    int end; //конец очереди
    int count;
public:
    TQueue(int size = 0);
    virtual ~TQueue();

    TQueue<T>& operator =(const TQueue<T>& Q);

    void Push(T dannye); //положить
    T Get(); //взять из вершины и удалить, либо посмотреть  и удалить вершину

    template <class T1>
    friend ostream& operator<< (ostream& ostr, const TQueue<T1>& Q);
    template <class T1>
    friend istream& operator>> (istream& istr, TQueue<T1>& Q);

    int GetLength();
    int GetInd();
};

template <class T>
inline TQueue<T>::TQueue(int size)
{
    if (size < 0)
        throw exception();
    this->length = size;
    x = new T[length];
    for (int i = 0; i < length; i++)
        x[i] = 0;
    this->ind = 0;
    this->end = 0;
    this->count = 0;
}

template <class T>
inline TQueue<T>::~TQueue()
{
    if (x != NULL)
        delete[] x;
    else throw exception();
    x = NULL;
    this->length = 0;
    this->ind = 0;
    this->end = 0;
    this->count = 0;
}


template <class T>
inline TQueue<T>& TQueue<T>::operator =(const TQueue<T>& S)
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
    this->end = S.end;
    this->count = S.count;
    for (int i = 0; i < length; i++)
        x[i] = S.x[i];
    return *this;
}

template<class T>
inline void TQueue<T>::Push(T dannye)
{
    if (count >= length)
        throw exception();
    x[end] = dannye;
    end = (end + 1) % length;
}

template<class T>
inline T TQueue<T>::Get()
{
    if (count == 0)
        throw exception();
    T d = x[ind];
    ind = (ind + 1) % length; //зацикливание
    return d;
}



template <class T1>
ostream& operator<< (ostream& ostr, const TQueue<T1>& Q)
{
    for (int i = Q.ind; i < Q.end; i++)
    {
        ostr << Q.x[i] << endl;
    }
    return ostr;
}

template <class T1>
istream& operator >> (istream& istr, TQueue<T1>& Q)
{
    int count;
    istr >> count; //количество элементов, которое хотим положить
    for (int i = 0; i < count; i++)
    {
        T1 d;
        istr >> d;
        Q.Push(d);
    }
    return istr;
}

template <class T>
int TQueue<T>::GetLength()
{
    return length;
}

template <class T>
int TQueue<T>::GetInd()
{
    return ind;
}

#endif //_Stack_