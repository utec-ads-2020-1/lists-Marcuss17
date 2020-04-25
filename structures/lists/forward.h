#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"


template <typename T>
class ForwardList : public List<T> {
	public:
	ForwardList() : List<T>(){};

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
	    newNode->next = this->head;
	    this->head = newNode;
            if(this->tail == nullptr){
                this->tail = newNode;
            }
	    this->nodes++;
	}

        void push_back(T element){
	    Node<T>* newNode = new Node<T>();
	    newNode->data = element;
	    newNode->next = nullptr;
	    if(this->head == nullptr){
		this->head = newNode;
		this->tail = newNode;
	    }else{
		auto aux = this->head;
		this-> tail = newNode;
		while(aux->next != nullptr){
		    aux = aux->next;	
		}
	        aux->next = newNode;
	    }	
	    this->nodes++;
	}

        void pop_front(){
	    auto aux = this->head;
	    this->head = this->head->next;
	    delete aux;
	    this->nodes--;
	}

        void pop_back(){
	    auto aux = this->head;
	    Node<T>* current;

	    while(aux->next != nullptr){
		current = aux;
		aux = aux->next;
	    }

	    current->next= nullptr;
	    this->tail = current;
	    delete aux;
			
	    this->nodes--;
	}
	
        T operator[](int index){
	    if(empty()){
                throw string("The list is empty!");
            }
			
            if(index > size()-1 || index < 0){
                throw string("Check your index");
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
	    auto it = this->head;
	    auto current = this->head;
	    while(it->next!= nullptr){
		current = it;
		it = it->next;
	    }

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
	

    	ForwardIterator<T> begin(){
	    ForwardIterator<T> it(this->head);
	    return it;
	}

	ForwardIterator<T> end(){
	    ForwardIterator<T> it(this->tail->next);
	    return it;
	}

        string name() {
            return "Forward List";
        }
        

        void merge(ForwardList<T>& secondForward){
	    this->nodes += secondForward.size();
            auto secondHead = secondForward.head;
	    auto aux = this->tail;
	    aux->next = secondHead;
	    this->tail = secondForward.tail;


            sort();

            while(secondForward.head != nullptr){
                secondForward.head = secondForward.head->next;
	    }
            secondForward.clear();
	}
};

#endif
