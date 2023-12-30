/*
A linked list is a data structure in C++ that consists of a sequence of nodes
Each node contains a value and a pointer to the next node in the list. 
The first node in the list is called the head, and the last node is called the tail.
In C++, a linked list can be implemented using a class or a struct that defines the node 
structure, along with functions that allow you to manipulate the list, such as adding or
removing nodes.

*/


#include <iostream>

// Node class for a singly linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

// Singly linked list class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor to free allocated memory
    ~LinkedList() {
        clear();
    }

    // Insert a new node at the beginning of the list
    void insertFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
 
    // Insert a new node at the end of the list
    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    // Display the elements of the list
    void display() {
        Node* current = head;

        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }

        std::cout << "nullptr" << std::endl;
    }

    // Remove all elements from the list
    void clear() {
        Node* current = head;
        Node* nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }

        head = nullptr;
    }
};

int main() {
    LinkedList myList;

    // Insert elements at the front
    myList.insertFront(3);
    myList.insertFront(2);
    myList.insertFront(1);

    // Insert elements at the end
    myList.insertEnd(4);
    myList.insertEnd(5);

    // Display the linked list
    std::cout << "Linked List: ";
    myList.display();  // Linked List: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr

    // Clear the linked list
    myList.clear();

    return 0;
}
