#include<iostream>
#define max 100
using namespace std;
class queue
{
	int a[max];
	int front,rear;
	public:
		queue();
		void insert_queue(int x);
		int delete_queue( );
		void display();
};
queue::queue()
{
	front=-1;
	rear=-1;
}
void queue::insert_queue(int x)
{
	if(rear==max-1)
	{
		cout<<"Queue is full";
	}
	else 
	{
		rear++;
		a[rear]=x;
		if(front==-1)
		{
			front=0;
			rear=0;
		}
	}
}
int queue::delete_queue( )
{
	if(front==-1 && rear==-1)
	{
		cout<<"Queue is empty";
	}
		
	else
	{
		int data=a[front];
		front++;
		return data;
		front=rear=-1;
	}
}
void queue::display()
{
	for(int i=front;i<rear+1;i++)
	{
		cout<<endl<<a[i];
	}
}
main()
{
	queue q;
	q.insert_queue(5);
	q.insert_queue(6);
	q.insert_queue(7);
	q.insert_queue(8);
	q.insert_queue(9);
	cout<<"The elements in queue are"<<endl;
	q.display();
	int j=q.delete_queue();
	cout<<endl<<"The deleted element in queue is:"<<j;
	cout<<endl<<"Now the elements in queue are"<<endl;
	q.display();
}
