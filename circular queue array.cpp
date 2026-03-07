#include<iostream>
#define MAX 5 
using namespace std;

class queue {
    int front, rear;
    int arr[MAX];

public:
    queue();
    void insert_queue(int x);
    int del_queue();
    void display();
};

queue::queue() {
    front = rear = -1; 
}
void queue::insert_queue(int x) {
    if ((rear + 1) % MAX == front) {
        cout << "Queue is full\n";
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX; 
        arr[rear]= x; 
    }
}
int queue::del_queue() {
    if (front == -1) {
        cout << "Queue is empty\n";
        return -1;
    } else {
        int x = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX; 
        }
        return x;
    }
}
void queue::display() {
    if (front == -1) {
        cout << "Queue is empty\n";
    } else {
        int i = front;
        cout << "The elements in the queue are:\n";
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX;
        }
        cout << arr[rear] << " "; 
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
    cout << "The elements in the circular queue are:\n";
    q.display();
    int j = q.del_queue();
    cout << "The deleted element in the queue is: " << j << endl;
    cout << "Now the elements in the queue are:\n";
    q.display();
    q.insert_queue(105);
    q.insert_queue(115);
    cout << "After inserting more elements, the queue is:\n";
    q.display();

    return 0;
}
