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
        Node* next;
        Node* prev;

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
        int* ll_size;
        T* head;
        T* tails;
    public:
        Double_LList();
        void addFirst(T* node);
        void addLast(T* node);
        void insertAt(T* node, int pos);
        T* removeFirst();
        T* removeLast();
        T* removeAt(int pos);
        void interator();
        bool exist(T* data);
        int size();

        //LIFO ~ push: add to stack, pop: remove from stack
        void push(T* node);
        T* pop();
        //FIFO ~ enqueue: add, dequeue: remove
        void enqueue(T* node);
        T* dequeue();
        ~Double_LList();
};

template <class T>
Double_LList<T>::Double_LList() {
    this->head = NULL:
    this->tail = NULL;
    this->ll_size = 0;
}

template <class T>
void Double_LList<T>::addFirst(T* node) {
    node->next = NULL;
    node->prev = NULL;

    if (this->head == NULL) {
        this->head = node;
        this->tail = this->head;
        this->ll_size++;
    }
    else {
        this->head->prev = node;
        node->next = this->head;
        this->head = node;
        this->ll_size++;
    }
}

template <class T>
void Double_LList<T>::addLast(T* node) {
    node->next = NULL;
    node->prev = NULL;

    if (this->head == NULL) {
        this->head = node;
        this->tail = this->head;
        this->ll_size++;
    }
    else {
        this->tail->next = node;
        node->prev = this->tail;
        this->tail = node;
        this->ll_size++;
    }
}

template <class T>
void Double_LList<T>::insertAt(T* node, int pos) {
    node->next = NULL;
    node->prev = NULL;

    T* temp = this->head;

    if (pos == 0) {
        this->addFirst(node);
    }
    else if (pos == this->ll_size) {
        this->addLast(node);
    }
    else if (pos > this->ll_size){
        cout << "Err: Range out of bound." << endl;
    }
    else {
        for (int i = 0; i <= pos; i++, temp = temp->next) {
            node->prev = temp->prev;
            node->next = temp;
            temp->prev->next = node;
            temp->prev = node;
        }
    }
}

template <class T>
T* Double_LList<T>::removeFirst() {

}

template <class T>
T* Double_LList<T>::removeLast() {

}

template <class T>
T* Double_LList<T>::removeAt(int pos) {

}

template <class T>
void Double_LList<T>::interator() {

}

template <class T>
bool Double_LList<T>::exist(T* data) {

}

template <class T>
int Double_LList<T>::size() {
    return this->ll_size;
}

template <class T>
void Double_LList<T>::push(T* node) {
    this->addLast(node);
}

template <class T>
T* Double_LList<T>::pop() {
    return this->removeLast();
}

template <class T>
void Double_LList<T>::enqueue(T* node) {
    this->addLast(node);
}

template <class T>
T* Double_LList<T>::dequeue() {
    return this->removeFirst();
}

template <class T>
Double_LList<T>::~Double_LList() {}

int main() {
    Double_LList<Node<string>> list;

    list.addLast(new Node<string>("something"));
    cout << "\ntrying something out" << endl;

    return 0;
}