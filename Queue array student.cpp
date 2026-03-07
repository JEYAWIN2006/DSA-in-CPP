#include<iostream>
#include<string>
#define max 100
using namespace std;

class StudentQueue {
    string name[max];
    int roll_no[max];
    string class_name[max];
    float marks[max];
    int front, rear;
    
public:
    StudentQueue() {
        front = -1;
        rear = -1;
    }
    
    void insert_student(string n, int r, string c, float m) {
        if (rear == max - 1) {
            cout << "Queue is full" << endl;
        } else {
            rear++;
            name[rear] = n;
            roll_no[rear] = r;
            class_name[rear] = c;
            marks[rear] = m;
            if (front == -1 && rear == 0) {
                front = 0;
                rear = 0;
            }
        }
    }
    
    void delete_student() {
        if (front == -1 && rear == -1) {
            cout << "Queue is empty" << endl;
        } else if (front == rear) {
            cout << "\nDeleted student details:\n";
            display_student(front);
            front = rear = -1;
        } else {
            cout << "\nDeleted student details:\n";
            display_student(front);
            front++;
        }
    }
    
    void display_student(int i) 
	{
        cout << "\nName: " << name[i];
        cout << "\nRoll No: " << roll_no[i];
        cout << "\nClass: " << class_name[i];
        cout << "\nMarks: " << marks[i] << endl;
    }
    
    void display_queue() {
        if (front == -1) 
		{
            cout << "Queue is empty" << endl;
        } else {
            for (int i = front; i <= rear; i++) {
                display_student(i);
            }
        }
    }
};

int main() 
{
    StudentQueue sq;
    sq.insert_student("John Doe", 101, "10th", 85.5);
    sq.insert_student("Jane Smith", 102, "10th", 90.2);
    sq.insert_student("Mike Johnson", 103, "10th", 78.9);
    
    cout << "The students in the queue are:" << endl;
    sq.display_queue();
    
    sq.delete_student();
    
    cout << "\nNow the students in the queue are:" << endl;
    sq.display_queue();
    
    return 0;
}
