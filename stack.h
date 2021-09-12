#include "circulararray.h"

template <typename T>
class StackArray : public CircularArray<T> {
    public:
        StackArray() : CircularArray<T>() {};

        StackArray(int size) : CircularArray<T>(size) {}
        
        void push(T value) : push_back(value) {}

        T pop() : pop_back() {}

        /*
        T top() {
            return array[back];
        }
        */

        ~StackArray() : ~CircularArray<T>() {}
};