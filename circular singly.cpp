#include<iostream>
using namespace std;
class listadt
{
	struct node
	{
		int data;
		node *next;
	}*front,*rear;
	public:
		listadt()
		{
			front=rear=NULL;
		}
		void insert_end(int);
		void insert_beg(int);
		void insert_pos(int,int);
		void display();
		
void delete_element(int x)
{
	node *prev,*temp;
	prev=find_prev(x);
	temp=prev->next;
	prev->next=temp->next;
	delete temp;
}
node* find_prev(int x)
{
	node *temp;
	temp=front;
	while(temp->next!=front&&temp->next->data!=x)
	{
		temp=temp->next;
	}
	return temp;
}
};
void listadt::insert_end(int x)
{
	node *temp;
	temp=new node;
	temp->data=x;
	if(front==NULL)
	{
		temp->next=temp;
		front=rear=temp;
	}
	else
	{
		rear->next=temp;
		temp->next=front;
		rear=temp;
	}
}
void listadt::insert_beg(int x)
{
    node *temp = new node;
    temp->data = x;
    if (front == NULL) 
	{
        temp->next = temp;
        front = rear = temp;
    }
	else
	{
        temp->next = front;
        rear->next = temp;
        front = temp;
    }
}
void listadt::insert_pos(int x, int position) 
{
    node *temp = new node;
    temp->data = x;

    if (front == NULL) 
	{
	        temp->next = temp;
            front = rear = temp;
    }

    if (position == 1) 
	{
        insert_beg(x);
        return;
    }

    node *current = front;
    int count = 1;

    while (count < position - 1 && current->next != front) {
        current = current->next;
        count++;
    }

    if (count == position - 1) 
	{
        temp->next = current->next;
        current->next = temp;
        if (temp->next == front) 
		{
            rear = temp;
        }
    } 
	else 
	{
        delete temp;
    }
}
void listadt::display()
{
    if (front == NULL)
	{
        return;
    }

    node *temp = front;
    do
	{
        cout << temp->data << " ";
        temp = temp->next;
    }
while (temp != front);
}
main()
{
	listadt ob;
	ob.insert_end(66);
	ob.insert_end(55);
	ob.insert_end(44);
	ob.insert_beg(22);
	ob.insert_beg(11);
	ob.insert_pos(10,2);
	ob.insert_pos(33,3);
	ob.delete_element(33);
	ob.display();
}
