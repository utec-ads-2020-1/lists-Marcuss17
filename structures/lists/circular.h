#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

// TODO: Implement all methods
template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

        T front(){
            if(empty()){
                throw string("List is empty!");
            }
            return this->head->data;
        }

        T back(){
            if(empty()){
                throw string("List is empty!");
            }
            return this->tail->data;
        }

        void push_front(T element){
            Node<T>* newNode = new Node<T>();
            if(this->head == nullptr && this->tail == nullptr){
                this->tail = newNode;
                this->head = newNode;
            }else{
                auto aux = this->head;
                aux->prev = newNode;
                newNode->next = aux;
                this->head = newNode;
            }

            this->head->prev = this->tail;
            this->tail->next = this->head;

            this->nodes++;
        }
        void push_back(T element){
            Node<T>* newNode = new Node<T>();
            if(this->head == nullptr && this->tail == nullptr){
                this->tail = newNode;
                this->head = newNode;
            }else{
                auto aux = this->tail;
                aux->next = newNode;
                newNode->prev = aux;
                this->tail = newNode;
            }
            this->head->prev = this->tail;
            this->tail->next = this->head;

            this->nodes++;
        }

        void pop_front(){
            auto aux = this->head;
            this->head = this->head->next;
            this->head->prev = this->tail;
            this->tail->next = this->head;
            delete aux;
            this->nodes--;
        }
        void pop_back(){
            auto aux = this->tail;
            this->tail = this->tail->prev;
            this->head->prev = this->tail;
            this->tail->next = this->head;
            delete aux;
            this->nodes--;
        }

        T operator[](int index){
            if(empty()){
                throw string("The list is empty!");
            }
            if(index > size()-1 || index < 0){
                throw string("Error in the index, check it!");
            }
            int ind = 0;
	    auto aux = this->head;
	    while(ind != index){
		aux = aux->next;	
		ind++;
	    }
	    return aux->data;
        }

        bool empty(){
            return this->nodes == 0;
        }

        int size(){
            return this->nodes;
        }

        void clear(){
            while(this->head != this->tail){
                auto aux = this->head;
                this->head = this->head->next;
                delete aux;
            }
            auto aux2 = this->head;
            this->head = nullptr;
            this->tail = this->head;
            delete aux2;
            this->nodes = 0;
        }

        void sort(){
            auto current = this->tail->prev;
	    auto aux = this->head;
	    auto aux2 = this->head;
	    while(aux != current){
	        aux2 = this->head;
		while(aux2 != this->tail){
		    if(aux2->data > aux2->next->data){
		        swap(aux2->data,aux2->next->data);
		    }
		    aux2 = aux2->next;
	        }
	        aux = aux->next;
	    }
        }

        void reverse(){
            for(int i = 0; i < size()-1; i++){
	        auto aux = this->head;
		for(int j = 0; j < size()-1-i; j++){
		    swap(aux->data, aux->next->data);
		    aux = aux->next;
		}
            }
        }

        BidirectionalIterator<T> begin(){
            BidirectionalIterator<T> it(this->head);
            return it;
        }

	BidirectionalIterator<T> end(){
            BidirectionalIterator<T> it(this->tail->next);
            return it;
        }

        string name() {
            return "Circular Linked List";
        }

        /**
         * Merges x into the list by transferring all of its elements at their respective 
         * ordered positions into the container (both containers shall already be ordered).
         * 
         * This effectively removes all the elements in x (which becomes empty), and inserts 
         * them into their ordered position within container (which expands in size by the number 
         * of elements transferred). The operation is performed without constructing nor destroying
         * any element: they are transferred, no matter whether x is an lvalue or an rvalue, 
         * or whether the value_type supports move-construction or not.
        */
        void merge(CircularLinkedList<T>& secondCircular){
            this->nodes += secondCircular.size();
            auto secondHead = secondCircular.head;
            auto aux = this->tail;
            aux->next = secondHead;
            secondHead->prev = aux;
            this->tail = secondCircular.tail;
            this->head->prev = this->tail;
            this->tail->next = this->head;

            while(secondCircular.head != secondCircular.tail){
                secondCircular.head = secondCircular.head->next;
            }

            secondCircular.clear();
        }
};

#endif
