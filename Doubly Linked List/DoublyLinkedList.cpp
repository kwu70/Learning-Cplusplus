#include <iostream>
#include <sstream>
using namespace std;

/*
template <class T>
struct Node {
    T data;
    struct Node* next;
    struct Node* prev;
};*/

template <class T>
class Node {
        T data;
    public:
        Node *next;
        Node *prev;

        Node(T data);
        T getData();
        string toString();
        ~Node();
};

//constructor, initializes Node class
template <class T>
Node<T>::Node(T data) {
    this->data = data;
}

template <class T>
T Node<T>::getData() {
    return this->data;
}

template <class T>
string Node<T>::toString() {
    Stringstream s;
    s << this->getData();
    return s.str();
}

//destructor, free up memory for contructor after program ends
template <class T>
Node<T>::~Node() {}

/* ----------------------------------------------------- */

template <class T>
class Double_LList {
    private:
        T *head;
        T *tails;
        int *ll_size;
    public:
        Double_LList();
        void add_head(T val);
        void add_tail(int val);
        void delete_head(int val);
        void delete_tail(int val);
        void search(int val);
        int size();
        ~Double_LList();
};

template <class T>
Double_LList<T>::Double_LList() {
    this->head = NULL:
    this->tail = NULL;
    this->ll_size = 0;
}

template <class T>
void Double_LList<T>::add_head(T val) {

}

template <class T>
void Double_LList<T>::add_tail(int val) {

}

template <class T>
void Double_LList<T>::delete_head(int val) {

}

template <class T>
void Double_LList<T>::delete_tail(int val) {

}

template <class T>
int Double_LList<T>::size() {

}


int main() {
    cout << "\ntrying something out" << endl;

    return 0;
}