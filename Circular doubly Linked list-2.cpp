#include <iostream>

using namespace std;

struct node {
    int data;
    node* next;
    node* prev;

    node(int data) : data(data), next(NULL), prev(NULL) {}
}*front,*rear;

class listadt {
public:
    listadt() 
    {
    	front=rear=NULL;
	}

   
    void insertEnd(int data) {
        node* newnode = new node(data);
        if (front == NULL) {
            front = newnode;
            front->next = front;
            front->prev = front;
        } else {
            node* rear = front->prev;
            newnode->next = front;
            newnode->prev = rear;
            rear->next = newnode;
            front->prev = newnode;
        }
    }
 void deletenode(int value) {
        if (front == NULL) return;

        node* temp = front;
        do {
            if (temp->data == value) {
                if (temp->next == temp) {
                    
                    delete temp;
                    front = NULL;
                } else {
                    
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;

                    if (temp == front) {
                        front = temp->next;
                    }
                    delete temp;
                }
                return;
            }
            temp = temp->next;
        } while (temp != front);
    }

    
    void display() {
        if (front == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        node* temp = front;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);

        cout << endl;
    }

   
    ~listadt() {
        if (front == NULL) return;

        node* current = front;
        node* temp;
        do {
            temp->next = current->next;
            delete current;
            current = temp->next;
        } while (current != front);
    }
};

int main() {
    listadt list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);
    list.insertEnd(50);
    list.deletenode(20);

    cout << "List elements: ";
    list.display();

    return 0;
}

