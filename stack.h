#include "circulararray.h"

template <typename T>
class StackArray : public CircularArray<T> {
    public:
        StackArray() : CircularArray<T>() {};

        void push(T value) {
            push_back(value);
        }

        T top() {
            return array[back];
        }

        T pop() {
            return pop_back();
        }

        ~StackList() {
            delete[] array;
        }
};