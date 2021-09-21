#include "circulararray.h"

template <typename T>
class StackArray : public CircularArray<T> {
    public:        
        void push(T value){
            push_front(value);
        }

        T pop(){
            return pop_front();
        }

        T top() {
            return array[front];
        }
};