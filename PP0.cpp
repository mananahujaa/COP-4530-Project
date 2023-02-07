//
//  main.cpp
//  PP0
//
//  Created by Manan Ahuja on 2/4/23 with Arwin Swapna
//

#include <iostream>
#include <string>
using namespace std;

template <typename E>

class cake{
private:
   
    string name;
    double weight;
    string icing_color;
    string flavor;
    string occassion_phrase;
    
};


template <typename E>

class SNode { // singly linked list node
private:
E elem; // linked list element value
SNode<E>* next; // next item in the list
friend class SLinkedList<E>; // provide SLinkedList access
};

template <typename E>
class SLinkedList { // a singly linked list
public:
SLinkedList(); // empty list constructor
~SLinkedList(); // destructor
bool empty() const; // is list empty?
const E& front() const; // return front element
void addFront(const E& e); // add to front of list
void removeFront();       // remove front item list
private:
SNode<E>* head; // head of the list
};

// constructor
template <typename E>
SLinkedList<E>::SLinkedList() : head(NULL) { }

// is list empty?
template <typename E>
bool SLinkedList<E>::empty() const {
return head == NULL;
}

// return front element
template <typename E>
const E& SLinkedList<E>::front() const {
return head->elem;
}

// destructor
template <typename E>
SLinkedList<E>::~SLinkedList() {
while (!empty()) removeFront();
}

// add to front of list
template <typename E>
void SLinkedList<E>::addFront(const E& e) {
SNode<E>* v = new SNode<E>; // create new node
v->elem = e; // store data
v->next = head; // head now follows v
head = v; // v is now the head
}

// remove front item
template <typename E>
void SLinkedList<E>::removeFront() {
SNode<E>* old = head; // save current head
head = old->next; // skip over old head
delete old; // delete the old head
}

int main() {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
