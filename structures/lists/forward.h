#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"


template <typename T>
class ForwardList : public List<T> {
	public:
	ForwardList() : List<T>(){};

		T front(){
		return this->head->data;
		};

        T back(){
			return this->tail->data;
		};

        void push_front(T element){
			Node<T>* newNode = new Node<T>();
			newNode->data = element;
			newNode->next = this->head;
			this->head = newNode;
			this->nodes++;
		};

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
		};

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
		};
	
        T operator[](int index){
			int ind = 0;
			auto aux = this->head;
			while(ind != index){
				aux = aux->next;	
				ind++;
			}
			return aux->data;
		};
	
        bool empty(){
			return this->nodes == 0;
		};

        int size(){
			return this->nodes;
		};

        void clear(){	
		while(this->head->next != nullptr){
			auto aux2 = this->head;
			this->head= this->head->next;
			delete aux2;	
		}

		this->head = nullptr;
		this->tail = nullptr;

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

			auto aux = this->head;
			while(aux->next != nullptr){
				aux = aux->next;
			}

			auto secondHead = secondForward.head;
			aux->next = secondHead;

			while(secondForward.head->next != nullptr){
				secondForward.head = secondForward.head->next;
			}

			sort();
			secondForward.clear();
		};
};

#endif
