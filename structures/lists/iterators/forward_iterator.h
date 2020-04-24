#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "../node.h"

// TODO: Implement all methods
template <typename T> 
class ForwardIterator {
    private:
       Node<T> *current;

    public:
    
        ForwardIterator(){
            current = nullptr;
        };

        ForwardIterator(Node<T>* it){
            current = it;
        };

        ForwardIterator<T> operator=(ForwardIterator<T>);

        bool operator!=(ForwardIterator<T> it){
            if(it.current != current){
                return true;
            }
            return false;
        }

        ForwardIterator<T> operator++(){
            

        }

        T operator*(){
            return current->data;
        }
};

#endif