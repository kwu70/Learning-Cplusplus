#include <iostream>
#include <sstream>
#include "DoublyLinkedList.cpp"

using namespace std;

int main() {
    Double_LList<Node<string>> list;
    Double_LList<Node<int>> numList;

    Node<string>* n = new Node<string>("1 something");
    Node<string>* n2 = new Node<string>("2 for you");
    Node<string>* n3 = new Node<string>("3 for me");

    /**
     *  Issues still need fixing:
     *  1. removeAt() when range is out of bound
     *  2. removing empty list
     * 
     *  Both currently just terminate program
     * /

    /* test stack */
    cout << endl;
    list.push(n);
    list.push(n2);
    list.push(n3);
    cout << "Current size: " << list.size() << endl;
    list.printAll();
    cout << "test exist(): " << list.exist(new Node<string>("3 for me")) << endl;
    cout << "Test peekStack(): " << list.peekStack()->toString() << endl;
    cout << "Test pop(): " << list.pop()->toString() << endl;
    cout << "test exist(): " << list.exist(new Node<string>("3 for me")) << endl;
    cout << "Test pop(): " << list.pop()->toString() << endl;
    cout << "Test pop(): " << list.pop()->toString() << endl;
    cout << "Current size: " << list.size() << endl;
    cout << endl;

    /* test queue */
    list.enqueue(new Node<string>("Apple"));
    list.enqueue(new Node<string>("Watermelon"));
    list.enqueue(new Node<string>("Dragon Fruit"));
    
    cout << "Current size: " << list.size() << endl;
    list.printAll();
    cout << " *peekQueue(): " << list.peekQueue()->toString() << endl;
    cout << "Test dequeue(): " << list.dequeue()->toString() << endl;
    cout << " *peekQueue(): " << list.peekQueue()->toString() << endl;
    cout << "Test dequeue(): " << list.dequeue()->toString() << endl;
    cout << "Current size: " << list.size() << endl;
    list.enqueue(new Node<string>("Lychee"));
    list.enqueue(new Node<string>("Logan"));
    cout << " *peekQueue(): " << list.peekQueue()->toString() << endl;
    cout << "Test dequeue(): " << list.dequeue()->toString() << endl;
    cout << " *peekQueue(): " << list.peekQueue()->toString() << endl;
    cout << "Test dequeue(): " << list.dequeue()->toString() << endl;
    cout << " *peekQueue(): " << list.peekQueue()->toString() << endl;
    cout << "Test dequeue(): " << list.dequeue()->toString() << endl;
    cout << "Current size: " << list.size() << endl;
    cout << endl;

    /* test insertAt(), removeAt() */
    numList.addFirst(new Node<int>(1));
    numList.addFirst(new Node<int>(2));
    numList.addFirst(new Node<int>(3));
    numList.printAll();
    cout << "Current size: " << numList.size() << endl;
    numList.addLast(new Node<int>(4));
    numList.addLast(new Node<int>(5));
    numList.addLast(new Node<int>(6));
    numList.printAll();
    cout << "Current size: " << numList.size() << endl;
    numList.insertAt(new Node<int>(7), 0);
    numList.insertAt(new Node<int>(8), 2);
    numList.insertAt(new Node<int>(9), 5);
    //testing if adding fails
    numList.insertAt(new Node<int>(10), 10);
    cout << endl;
    numList.printAll();
    cout << "Current size: " << numList.size() << endl;
    cout << "peek: " << numList.peekStack()->toString() << endl;
    cout << endl;

    //test removeAt()
    cout << "Test removeAt(idx 3): " << numList.removeAt(3)->toString() << endl;
    numList.printAll();
    cout << "Current size: " << numList.size() << endl;
    // ******************************** issue when removing larger/less than size
    //cout << " *Test out of range: " << numList.removeAt(-20)->toString() << endl;
    cout << "Test removeAt(idx 4): " << numList.removeAt(4)->toString() << endl;
    cout << "Test removeAt(idx 5): " << numList.removeAt(5)->toString() << endl;
    numList.printAll();
    cout << "Current size: " << numList.size() << endl;
    numList.insertAt(new Node<int>(213), 3);
    numList.insertAt(new Node<int>(432), 4);
    numList.insertAt(new Node<int>(54), 5);
    numList.printAll();
    cout << "Current size: " << numList.size() << endl;
    cout << "Test removeAt(): " << numList.removeAt(8)->toString() << endl;
    cout << "Test removeAt(): " << numList.removeAt(7)->toString() << endl;
    cout << "Test removeAt(): " << numList.removeAt(0)->toString() << endl;
    cout << "Test removeAt(): " << numList.removeAt(1)->toString() << endl;
    cout << endl;
    numList.printAll();
    cout << "Current size: " << numList.size() << endl;
    cout << "Test removeAt(idx 0): " << numList.removeAt(0)->toString() << endl;
    cout << "Test removeAt(idx 1): " << numList.removeAt(1)->toString() << endl;
    cout << endl;
    numList.printAll();
    cout << "Current size: " << numList.size() << endl;
    cout << "peek: " << numList.peekStack()->toString() << endl;
    cout << "Test removeAt(2): " << numList.removeAt(2)->toString() << endl;
    cout << "Test removeAt(1): " << numList.removeAt(1)->toString() << endl;
    cout << "Test removeAt(0): " << numList.removeAt(0)->toString() << endl;
    //test remove on empty list
    // ************************** ISSUE HERE
    //cout << "Test removeAt(): " << numList.removeFirst()->toString() << endl;
    numList.printAll();
    cout << "Current size: " << numList.size() << endl;
    cout << endl;

    //test add/remove together while list is not empty
    numList.addLast(new Node<int>(50));
    numList.addLast(new Node<int>(324));
    numList.addLast(new Node<int>(435));
    numList.printAll();
    cout << "Test removeAt(2): " << numList.removeAt(2)->toString() << endl;
    cout << "Test removeAt(0): " << numList.removeAt(0)->toString() << endl;
    numList.addLast(new Node<int>(76));
    numList.addLast(new Node<int>(93));
    numList.printAll();
    cout << "Test removeAt(1): " << numList.removeAt(1)->toString() << endl;
    cout << "Test removeAt(0): " << numList.removeAt(0)->toString() << endl;
    cout << "Test removeAt(2): " << numList.removeAt(0)->toString() << endl;    
    
    cout << endl;
    numList.printAll();
    cout << "test exist(): " << list.exist(new Node<string>("Watermelon")) << endl;

    cout << "Size: " << numList.size() << endl;

    return 0;
}