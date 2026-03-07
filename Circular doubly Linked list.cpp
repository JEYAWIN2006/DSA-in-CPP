#include <iostream>

using namespace std;
class listadt
{
struct node
{
    int data;
    node* next;
    node* prev;
}*front,*rear;
public:
    listadt()
    {
    	front=rear=NULL;
	}
    void insert_end(int x);
    void delete_element(int x);
    void display();
};
void listadt::insert_end(int x)
{
        node* temp = new node;
        if (front == NULL) 
		{
            front = temp;
            front->next = front;
            front->prev = front;
        }
		else
		{
            node* rear = front->prev;
            temp->next = front;
            temp->prev = rear;
            rear->next = temp;
            front->prev = temp;
        }
    }
void listadt::delete_element(int x)
{
        if (front == NULL) 
		{
		return;
        }
        node* temp = front;
        do {
            if (temp->data == x) 
			{
                if (temp->next == temp)
				{
                    delete temp;
                    front = NULL;
                }
				else
				{
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
  void listadt::display()
  {
        if (front == NULL) return;

        node* temp = front;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
int main() {
    listadt list;

    list.insert_end(10);
    list.insert_end(20);
    list.insert_end(30);
    list.insert_end(40);
    list.delete_element(20);
    list.display();
    return 0;
}

