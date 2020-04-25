#include <iostream>
#include "linked.h"

using namespace std;

void print(LinkedList<int>);

int main(){
    LinkedList<int> linkedList;
    try{
        linkedList.front();
    }catch(string& e){
        cout << e << endl;
    }

    linkedList.push_back(5);
    linkedList.push_back(6);
    linkedList.push_front(7);
    linkedList.push_front(10);

    cout << "Printing front element: " << linkedList.front() << endl;
    cout << "Printing back element: " << linkedList.back() << endl;
    cout << "Poping an element in the front." << endl;  
    linkedList.pop_front();
    cout << "Printing new front element: ";
    cout << linkedList.front() << endl; 
    cout << "Poping an element in the back." << endl; 
    linkedList.pop_back();
    cout << "Printing new back element: ";
    cout << linkedList.back() << endl;
    cout << "Pushing back elements again." << endl;
    linkedList.push_back(6);
    linkedList.push_front(10);

    cout << "Size: " << linkedList.size() << endl;
    try{
        cout << linkedList[5] << endl;
    }catch(string& e){
        cout << e << endl;
    }

    cout << "Accessing fourth position in the list: " << linkedList[3] << endl;

    cout << "Is list empty? " << linkedList.empty() << endl;

    cout << "The size of the list is: " << linkedList.size() << endl;

    cout << "-----Sorting list-----" << endl;
    linkedList.sort();
    print(linkedList);
    cout << "-----Reversing list-----" << endl;
    linkedList.reverse();
    print(linkedList);
    auto it = linkedList.begin();
    cout << "The list begins with: " << *it << endl;

    LinkedList<int> secondLinked;
    secondLinked.push_back(12);
    secondLinked.push_back(15);
    secondLinked.push_back(13);

    linkedList.merge(secondLinked);
    cout << "-----Mergin lists-----" << endl;
    print(linkedList);

    cout << "Last element in the merged list is: " << linkedList[5] << endl;
	cout << "Size of the merged list is:" << linkedList.size() << endl;
	cout << "The new tail hast this element: " << linkedList.back() << endl;

    return 0;
}


void print(LinkedList<int> list){
    for(int i = 0; i < list.size(); i++){
        cout << list[i] << " ";
    }
    cout << endl;
}