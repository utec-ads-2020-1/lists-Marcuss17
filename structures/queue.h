#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

#define MAX 1000 

// TODO: Implement all methods
template <typename T>
class queue {
    T* data;
    int top;
    int capacity;

    public:
        queue(int size = MAX){
	    capacity = size;
	    data = new T[capacity];
	    top = -1;
        }

	~queue(){
	    delete[] data;
	    cout << "Queue deleted!\n";
	};   		

	void push(T element){
	    if(top+1 == MAX){
	        cerr << "The queue is full!\n";
	    }else{
	        top++;
		data[top] = element;	
	    }
	}

	void pop(){
	    if(empty()){
	        cerr << "The queue is empty!\n";
	    }else{
	        top--;
		for(int i = 0; i <= top; i++){
		    data[i] = data[i+1];
		}
	    }	
	}

	int front(){
	    if(empty()){
	        throw string("Queue empty!");
	    }
	    return data[0];	
	}

    	int back(){
	    if(empty()){
		throw string("Queue empty!");
	    }
	    return data[top];
	}

	int size(){
	    return top+1;
	}

	bool empty(){
	    if(top == -1){ return true;}
	    else{return false;}
	}
};

#endif
