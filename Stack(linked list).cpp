#include<iostream>
using namespace std;
class stack
{
	struct node
	{
	int data;
	node *next;
    }*top;
    public:
    	stack()
    	{
    		top=NULL;
		}
		void push(int x);
		int pop();
		void display();
};
void stack::push(int x)
{
	node *temp;
	temp=new node;
	temp->data=x;
	temp->next=top;
	top=temp;
}
int stack::pop()
{
	if(top==NULL)
	  cout<<"Stack is empty";
	else
	{
		node *temp;
		int x=top->data;
		temp=top;
		top=top->next;
		delete temp;
		return x;
	}
}
void stack::display()
{
    if (top == NULL)
    {
        return;
    }
    node *temp = top;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
	stack s;
	cout<<"Stack elements are:";
	s.push(10);
	s.push(20);
	s.display();
	int i=s.pop();
	cout<<"\nThe popped Elements is:"<<i;
}
