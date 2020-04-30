#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../node.h"

// TODO: Implement all methods
template <typename T> 
class BidirectionalIterator {
    private:
        Node<T> *current;

    public:
        BidirectionalIterator(){
            current = nullptr;
        }

        BidirectionalIterator(Node<T>* it){
            current = it;
        }

        BidirectionalIterator<T> operator=(BidirectionalIterator<T> it2){
            it2.current =  current;
            // sin return?
        }

        bool operator!=(BidirectionalIterator<T> it2){
            return !(it2.current == current);
        }

        BidirectionalIterator<T> operator++(){
            if( current == nullptr){
                throw string("No more elements in the list. Cant go forward.");
            }
            current = current->next;
            // sin return?
        }

        BidirectionalIterator<T> operator--(){
            if(current == nullptr){
                throw string("No more elements in the list. Cant go backwards.");
            }
            current = current->prev;
            // sin return?
        }

        T operator*(){
            // Si current es null?
            return current->data;
        }
};

#endif