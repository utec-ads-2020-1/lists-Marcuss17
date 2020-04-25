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
        }

        ForwardIterator(Node<T>* it){
            current = it;
        }

        ForwardIterator<T> operator=(ForwardIterator<T> it2){
            it2.current = current;
        }

        bool operator!=(ForwardIterator<T> it){
            //Returns true if it.current and current are not 
            //pointing the same position
            return !(it.current == current);
        }

        ForwardIterator<T> operator++(){
            if( current == nullptr){
                throw string("No more elements in the list. Cant go forward.");
            }
            current = current->next;
        }

        T operator*(){
            return current->data;
        }
};

#endif