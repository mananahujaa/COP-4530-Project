//
//  main.cpp
//  PP0
//
//  Created by Manan Ahuja on 2/4/23 with Arwin Swapna
//

#include <iostream>
#include <string>
using namespace std;



class CakeStore  //Parent class for the cake store
{
public:
    string name;            //name of the order
    void set_name(){
        cin>>name;
    }
    string get_name(){
        return name;
    }
    double weight;          // weight of cake
    void set_weight(){
        cin>>weight;
    }
    double get_weight(){
        return weight;
    }
    string icing_color;     // color of icing for identification
    void set_icing(){
        cin>>icing_color;
    }
    string get_icing(){
        return icing_color;
    }
};

class cake : public CakeStore       //Inherit attributes from cake store into each indv cake
{
public:
   
    string flavor;                  //add flavor
    void set_flavor(){
        cin>>flavor;
    }
    string get_flavor(){
        return flavor;
    }
    
    string occassion_phrase;
    void set_occassion(){       // add occassion of the cake if any
        cin>>occassion_phrase;
    }
    string get_occassion(){
        return occassion_phrase;
    }
};


template <typename E>

class SCake { // singly linked list node
private:
E elem; // linked list element value
SCake<E>* next; // next item in the list
};

template <typename E>
class CakeLinkedList{ // a singly linked list
public:
CakeLinkedList(); // empty list constructor
~CakeLinkedList(); // destructor
bool empty() const; // is list empty?
const E& front() const; // return front element
void addFront(const E& e); // add to front of list
void removeFront();       // remove front item list
private:
SCake<E>* head; // head of the list
};

// constructor
template <typename E>
CakeLinkedList<E>::CakeLinkedList() : head(NULL) { }

// is list empty?
template <typename E>
bool CakeLinkedList<E>::empty() const {
return head == NULL;
}

// return front element
template <typename E>
const E& CakeLinkedList<E>::front() const {
return head->elem;
}

// destructor
template <typename E>
CakeLinkedList<E>::~CakeLinkedList() {
while (!empty()) removeFront();
}

// add to front of list
template <typename E>
void CakeLinkedList<E>::addFront(const E& e) {
SCake<E>* v = new SCake<E>; // create new node
v->elem = e; // store data
v->next = head; // head now follows v
head = v; // v is now the head
}

// remove front item
template <typename E>
void CakeLinkedList<E>::removeFront() {
SCake<E>* old = head; // save current head
head = old->next; // skip over old head
delete old; // delete the old head
}

int main() {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
