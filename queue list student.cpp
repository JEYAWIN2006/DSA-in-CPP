#include<iostream>
#include<string>
using namespace std;

class queue {
    struct node {
        string student_name;
        int roll_no;
        string class_name;
        float marks;

        node* next;
    }*front, *rear;

public:
    queue();
    void insert_queue(string student_name, int roll_no, string class_name, float marks);
    void del_queue();
    void display();
};

queue::queue() {
    front = rear = NULL;
}
void queue::insert_queue(string student_name, int roll_no, string class_name, float marks) {
    node* temp = new node;
    temp->student_name = student_name;
    temp->roll_no = roll_no;
    temp->class_name = class_name;
    temp->marks = marks;
    temp->next = NULL;

    if (front == NULL) {
        front = temp;
        rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}
void queue::del_queue() {
    if (front == NULL) {
        cout << "Queue is empty\n";
    } else {
        node* temp = front;
        cout << "\nDeleted Student details:\n";
        cout << "Name: " << temp->student_name << "\nRoll No: " << temp->roll_no
             << "\nClass: " << temp->class_name << "\nMarks: " << temp->marks << endl;

        front = front->next;
        delete temp;
    }
}


void queue::display() {
    if (front == NULL) {
        cout << "Queue is empty\n";
    } else {
        node* temp = front;
        while (temp != NULL) {
            cout << "\nStudent details:\n";
            cout << "Name: " << temp->student_name;
            cout << "\nRoll No: " << temp->roll_no;
            cout << "\nClass: " << temp->class_name;
            cout << "\nMarks: " << temp->marks << endl;
            temp = temp->next;
        }
    }
}

int main() {
    queue q;
    q.insert_queue("John Doe", 101, "10th", 85.5);
    q.insert_queue("Jane Smith", 102, "10th", 90.2);
    q.insert_queue("Mike Johnson", 103, "10th", 78.9);
    cout << "The students in the queue are:" << endl;
    q.display();
    q.del_queue();
    cout << "\nNow the students in the queue are:" << endl;
    q.display();

    return 0;
}
