#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

// TODO: Implement all methods
template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {}

        T front(){
            return this->head->data;
        }

        T back(){
            return this->tail->data;
        }

        void push_front(T element){
            Node<T>* newNode = new Node<T>();
			newNode->data = element;
            newNode->prev = nullptr;
            if(this->head == nullptr && this->tail == nullptr){
                newNode->next = nullptr;
                this->tail = newNode;
            }else{
                auto aux = this->head;
                aux->prev = newNode;
                newNode->next = aux;
            }
            this->head = newNode;
			this->nodes++;
        }

        void push_back(T element){
            Node<T>* newNode = new Node<T>();
			newNode->data = element;
            newNode->next = nullptr;
            if(this->head == nullptr && this->tail == nullptr){
                newNode->prev = nullptr;
                this->head = newNode;
            }else{
                auto aux = this->tail;
                aux->next = newNode;
                newNode->prev = aux;
            }
            this->tail = newNode;
            this->node++;
        }

        void pop_front(){
            auto aux = this->head;
            this->head = this->head->next;
            this->head->prev = nullptr;
            delete aux;
            this->nodes--;
        }

        void pop_back(){
            auto aux = this->tail;
            this->tail = this->tail->prev;
            this->tail->next = nullptr;
            delete aux;
            this->nodes--;

        }

        T operator[](int index){
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
            return this->nodess;
        }

        void clear(){
            while(this->head != nullptr){
				auto aux = this->head;
				his->head= this->head->next;
				delete aux;	
			}

			this->tail = this->head;
			this->nodes = 0;
        }
        
        void sort(){
            auto aux = this->head;
			for(int i = 0; i <= size()-2; i++){
				auto aux2 = aux->next;
				for(int j = 1; j <= size()-1; j++){
					if(aux-> data > aux2->data){
						swap(aux->data, aux2->data);
					}
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

        BidirectionalIterator<T> begin();
	    BidirectionalIterator<T> end();

        string name() {
            return "Linked List";
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
        void merge(LinkedList<T>& secondLinked){
            this->nodes += secondLinked.size();
            auto secondHead = secondLinked.head;
            this->tail->next = secondHead;
            secondHead.prev = this->tail;

            sort();

            while(secondLinked.head != nullptr){
                secondLinked.head = secondLinked.head->next;
            }

            secondLinked.clear();
        }
};

#endif