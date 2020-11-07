#pragma once
#ifndef _Queue_
#define _Queue_

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
    int count; //количество элементов в очереди
public:
    TQueue(int size = 0);
    TQueue(const TQueue<T>& Q);
    virtual ~TQueue();

    TQueue<T>& operator =(const TQueue<T>& Q);
    bool operator ==(const TQueue<T>& Q) const;
    bool operator !=(const TQueue<T>& Q) const;

    void Push(T dannye); //положить
    T Get(); //взять из вершины и удалить, либо посмотреть  и удалить вершину
    bool IsEmpty();
    bool IsFull();

    template <class T1>
    friend ostream& operator<< (ostream& ostr, const TQueue<T1>& Q);
    template <class T1>
    friend istream& operator>> (istream& istr, TQueue<T1>& Q);

    int GetLength();
    int GetInd();
    int GetEnd();
    int GetCount();
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
inline TQueue<T>::TQueue(const TQueue<T>& Q)
{
    this->length = Q.length;
    this->ind = Q.ind;
    this->end = Q.end;
    this->count = Q.count;
    x = new T[length];
    for (int i = 0; i < length; i++)
        x[i] = Q.x[i];
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
inline TQueue<T>& TQueue<T>::operator =(const TQueue<T>& Q)
{
    if (this == &Q)
        return *this;
    if (length != Q.length)
    {
        delete[] x;
        x = new T[Q.length];
    }
    this->length = Q.length;
    this->ind = Q.ind;
    this->end = Q.end;
    this->count = Q.count;
    for (int i = 0; i < length; i++)
        x[i] = Q.x[i];
    return *this;
}

template<class T>
inline bool TQueue<T>::operator==(const TQueue<T>& Q) const
{
    if (length != Q.length || ind != Q.ind || end != Q.end || count != Q.count)
        return false;
    for (int i = ind; i != end; i = (i + 1) % Q.length)
        if (x[i] != Q.x[i])
            return false;
    return true;
}

template<class T>
inline bool TQueue<T>::operator!=(const TQueue<T>& Q) const
{
    if (length != Q.length || ind != Q.ind || end != Q.end || count != Q.count)
        return true;
    for (int i = ind; i != end; i = (i + 1) % Q.length)
        if (x[i] != Q.x[i])
            return true;
    return false;
}

template<class T>
inline void TQueue<T>::Push(T dannye)
{
    if (this->IsFull())
        throw exception();
    this->x[end] = dannye;
    this->end = (this->end + 1) % length; //зацикливание
    count++;
}

template<class T>
inline T TQueue<T>::Get()
{
    if (this->IsEmpty())
        throw exception();
    T d = x[ind];
    this->ind = (ind + 1) % length; //зацикливание
    count--;
    return d;
}

template<class T>
inline bool TQueue<T>::IsEmpty()
{
    if (count == 0)
        return true;
    else return false;
}

template<class T>
inline bool TQueue<T>::IsFull()
{
    if (count == length)
        return true;
    else return false;
}

template <class T1>
ostream& operator<< (ostream& ostr, const TQueue<T1>& Q)
{
    for (int i = Q.ind; i != Q.end; i = (i + 1) % Q.length)
    {
        ostr << Q.x[i] << " ";
    }
    return ostr;
}

template <class T1>
istream& operator >> (istream& istr, TQueue<T1>& Q)
{
    if (Q.IsFull())
        throw "Queue is full";
    int count;
    istr >> count; //количество элементов, которое хотим положить
    if (Q.count + count > Q.length)
             throw exception();
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

template <class T>
int TQueue<T>::GetEnd()
{
    return end;
}

template <class T>
int TQueue<T>::GetCount()
{
    return count;
}

#endif //_Queue_