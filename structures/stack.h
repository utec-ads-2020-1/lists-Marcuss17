#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

#define MAX 1000 

//: Implement all methods
template <typename T>
class stack {
	T* data;
	int top;
	int capacity;

public:

	stack(int size = MAX){
            capacity = size;
            data = new T[capacity];
            top = -1;
        };

	~stack(){ 
            delete[] data;
            cout << "Stack deleted!";
        };   		

	void push(T element){
            if(top+1 == MAX){
                cerr << "The stack is full!\n";
            }else{
                top++;
                data[top] = element;
            }
        };

	void pop(){
            if(empty()){
                cerr << "The Stack is empty!\n";
            }else{
                top--;
            }
        };

	int returnTop(){
        if(empty()){
            throw string("Stack is empty!");
        }
            return data[top];
        };

	int size(){
            return top+1;
        };

	bool empty(){
            if(top == -1){
                return true;
            }else{
                return false;
            }
        };
};

#endif
