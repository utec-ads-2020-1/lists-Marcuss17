#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

// TODO: Implement all methods
template <typename T>
class ForwardList : public List<T> {
	public:
	ForwardList() : List<T>(){};
	
		T front(){
		return this->head->data;
		};

        T back(){
			auto aux = this->head;
			while(aux->next != nullptr){
				aux = aux->next;
			}
			return aux->data;
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
			}else{
				auto aux = this->head;
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
			cout << current->data << endl;
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
			auto aux = this->head;
			while(aux->next != nullptr){
				auto aux2 = aux;
				delete aux2;
				aux = aux->next;	
			}
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
			return this->head;
		}
		ForwardIterator<T> end(){
			auto aux = this->head;
			while(aux->next != nullptr){
				aux = aux->next;
			}
			return aux;
		}

        string name() {
            return "Forward List";
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
        void merge(ForwardList<T>& secondForward){
			auto secondBeg = secondForward->head;
			auto aux = this->head;
			while(aux->next != nullptr){
				aux = aux->next;
			}

			aux->next = secondBeg;
		};
};

#endif
