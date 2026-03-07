o#include<iostream>
using namespace std;
class queue
{
	struct node
	{
		int data;
		node *next;
	}*front,*rear;
	public:
		queue();
		void insert_queue(int x);
		int del_queue();
		void display();
};
queue::queue()
{
	front=rear=NULL;
}
void queue::insert_queue(int x)
{
	node *temp;
	temp=new node;
	temp->data=x;
	temp->next=NULL;
	if(front==NULL)
	{
		front=temp;
		rear=temp;
	}
	else
	{
		rear->next=temp;
		rear=temp;
	}
}
int queue::del_queue()
{
	if(front==NULL)
	{
		cout<<"Queue is empty";
	}
	else
	{
		node *temp;
		int x=front->data;
		temp=front;
		front=front->next;
		delete temp;
		return x;
	}
}
void queue::display()
{
	node *temp;
	temp=front;
	while(temp!=NULL)
	{
		cout<<endl<<temp->data<<" ";
		temp=temp->next;	
	}	
}
main()
{
	queue q;
	q.insert_queue(55);
	q.insert_queue(65);
	q.insert_queue(75);
	q.insert_queue(85);
	q.insert_queue(95);
	q.insert_queue(105);
	q.insert_queue(115);
	cout<<"The elements in queue are"<<endl;
	q.display();
	int j=q.del_queue();
	cout<<endl<<"The deleted element in queue is:"<<j;
	cout<<endl<<"Now the elements in queue are"<<endl;
	q.display();
}
