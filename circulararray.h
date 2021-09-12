#include <iostream>
using namespace std;

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;
    
public:
    CircularArray();
    CircularArray(int _capacity);
    virtual ~CircularArray();
    void push_front(T data);
    void push_back(T data);
    void insert(T data, int pos);
    T pop_front();
    T pop_back();
    bool is_full();
    bool is_empty();
    int size();
    void clear();
    T &operator[](int);
    void sort();
    bool is_sorted();
    void reverse();
    string to_string(string sep=" ");

private:
    int next(int);
    int prev(int);
};

template <class T>
CircularArray<T>::CircularArray()
{
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index)
{
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return (index + 1) % capacity;
}

template <class T>
bool CircularArray<T>::is_full()
{
    return next(back) == front;
}

template <class T>
bool CircularArray<T>::is_empty()
{
    return (back == -1 && front == -1);
}

template <class T>
int CircularArray<T>::size()
{
    if (is_empty()) return 0;
    if (is_full()) return capacity;
    int itr = front; 
    int n = 1;
    while (array[next(itr)] != 0)
    {
        n += 1;
    }
    return n;
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    string result = ""; 
    int n = size();
    int j = 0;
    for (int i = front; j < n; i = next(i), j++)
        result += std::to_string((*this)[i]) + sep;
    return result;    
}

template <class T>
void CircularArray<T>::push_front(T data)
{
    if (is_full())
    {
        throw "Error";    
    }
    else
    {
        if (front == -1)
        {
            front = back = 0;
        }
        else
        {
            front = prev(front);
        }
        array[front] = data;
    }
}

template <class T>
void CircularArray<T>::push_back(T data)
{
    if (is_full())
    {
        throw "Error";
    }
    else
    {
        if (back == -1)
        {
            back = front = 0;
        }
        else
        {
            back = next(back);
        }
        array[back] = data; 
    }     
}

template <class T>
void CircularArray<T>::insert(T data, int pos)
{
    if (is_empty())
    {
        back = 0;
        front = 0;
    }
    if (is_full())
    {
        throw "Error";
    }
    else if (pos < capacity)
    {
        array[pos] = data;
    }  
}

template <class T>
T CircularArray<T>::pop_front()
{
    if (is_empty())
    {
        throw "Error";
    }
    else
    {
        T temp = array[front];
        array[front] = 0;
        front = next(front);  
        return temp;
    }
}

template <class T>
T CircularArray<T>::pop_back()
{
    if (is_empty())
    {
        throw "Error";
    }
    else
    {
        T temp = array[back];
        array[back] = 0;
        back = prev(back);  
        return temp;
    }
}

template <class T>
void CircularArray<T>::clear()
{
    delete[] array;
    array = new T[capacity];
}

template <class T>
T& CircularArray<T>::operator[](int a)
{
    return array[a];
}

template <class T>
void CircularArray<T>::sort()
{
    int n = size();
    int k;
    int l;
    int j; 
    for (k = 0; k < n-1; k++)
    {
        for (j = front, l = 0; l < n-k-1; j = next(j), l++)
        {
            if (array[j] > array[next(j)]) 
            {
                T temp = array[j]; 
                array[j] = array[next(j)]; 
                array[next(j)] = temp; 
            }
        }
    }
}

template <class T>
bool CircularArray<T>::is_sorted()
{
    int n = size();
    if (n == 0 || n == 1)
    {
        return true;
    }
    int l;
    for (int i = next(front), l = 1; l < n; i = next(i), l++)
    {
        if (array[prev(i)] > array[i])
        {
            return false;
        }
    }
    return true;
}

template <class T>
void CircularArray<T>::reverse()
{
    int i;
    int j = back;
    for (i = front; i != j; i = next(i))
    {
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        if (prev(j) != i)
        {
            j = prev(j);
        }
    }    
}
