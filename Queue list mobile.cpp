#include<iostream>
#include<string>
using namespace std;

class queue {
    struct node {
        string brand;
        string model_name;
        int stock;
        float price;
        node* next;
    }*front, *rear;

public:
    queue();
    void insert_queue(string brand, string model_name, int stock, float price);
    void del_queue();
    void display();
};

queue::queue() {
    front = rear = NULL;
}

void queue::insert_queue(string brand, string model_name, int stock, float price) {
    node* temp = new node;
    temp->brand = brand;
    temp->model_name = model_name;
    temp->stock = stock;
    temp->price = price;
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
        cout << "Queue is empty";
    } else {
        node* temp;
        temp = front;
        cout << "\nDeleted mobile details:\n";
        cout << "Brand: " << temp->brand << "\nModel Name: " << temp->model_name
             << "\nStock: " << temp->stock << "\nPrice: " << temp->price << endl;
        front = front->next;
        delete temp;
    }
}

void queue::display() {
    if (front == NULL) {
        cout << "Queue is empty";
    } else {
        node* temp = front;
        while (temp != NULL) {
            cout << "\nBrand: " << temp->brand;
            cout << "\nModel Name: " << temp->model_name;
            cout << "\nStock: " << temp->stock;
            cout << "\nPrice: " << temp->price << endl;
            temp = temp->next;
        }
    }
}

int main() {
    queue q;
    q.insert_queue("Apple", "iPhone 14", 10, 999.99);
    q.insert_queue("Samsung", "Galaxy S22", 8, 799.99);
    q.insert_queue("OnePlus", "OnePlus 11", 5, 599.99);
    q.insert_queue("Google", "Pixel 7", 3, 699.99);
    cout << "The mobile details in the queue are:" << endl;
    q.display();
    q.del_queue();
    cout << "\nNow the mobile details in the queue are:" << endl;
    q.display();

    return 0;
}
