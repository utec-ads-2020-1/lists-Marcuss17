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
            this->nodes++;
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
            while(this->head != nullptr){
				auto aux = this->head;
				this->head= this->head->next;
				delete aux;	
			}

			this->tail = this->head;
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
            return "Linked List";
        }

        void merge(LinkedList<T>& secondLinked){
            this->nodes += secondLinked.size();
            auto secondHead = secondLinked.head;
            auto aux = this->tail;
            aux->next = secondHead;
            secondHead->prev = aux;
            this->tail = secondLinked.tail;

            sort();

            while(secondLinked.head != nullptr){
                secondLinked.head = secondLinked.head->next;
            }

            secondLinked.clear();
        }
};

#endif