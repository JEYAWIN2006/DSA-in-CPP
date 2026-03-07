#include<iostream>
using namespace std;

class queue {
    struct node {
        int data;
        node* next;
    }*front, *rear;

public:
    queue();
    void insert_queue(int x);
    int del_queue();
    void display();
};
queue::queue() {
    front = rear = NULL;
}
void queue::insert_queue(int x) {
    node* temp = new node;
    temp->data = x;
    temp->next = NULL;

    if (front == NULL) {
        front = rear = temp;
        rear->next = front; 
    } else {
        rear->next = temp;   
        rear = temp;         
        rear->next = front;  
    }
}
int queue::del_queue() {
    if (front == NULL) {
        cout << "Queue is empty\n";
        return -1;
    } else {
        int x;
        if (front == rear) {
            x = front->data;
            delete front;
            front = rear = NULL;  
        } else {
            node* temp = front;
            x = temp->data;
            front = front->next;    
            rear->next = front;     
            delete temp;
        }
        return x;
    }
}
void queue::display() {
    if (front == NULL) {
        cout << "Queue is empty\n";
    } else {
        node* temp = front;
        cout << "The elements in the circular queue are:\n";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);  
        cout << endl;
    }
}

int main() {
    queue q;
    q.insert_queue(55);
    q.insert_queue(65);
    q.insert_queue(75);
    q.insert_queue(85);
    q.insert_queue(95);
    q.display();
    int j = q.del_queue();
    cout << "The deleted element in the queue is: " << j << endl;
    q.display();
    q.insert_queue(105);
    q.insert_queue(115);
    cout << "After inserting more elements, the queue is:\n";
    q.display();

    return 0;
}
