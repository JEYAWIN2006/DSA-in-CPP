#include<iostream>
#define max 10
using namespace std;
class stack
{
	int a[max];
	int top;
	public:
		stack()
		{
			top=-1;
		}
		void push(int  x);
		int pop();
		void display();
};
void stack::push(int x)
{
	if(top==max-1)
	{
	cout<<"stack is full"<<endl;
    }
	else
	{
		top++;
		a[top]=x;
	}
}
int stack::pop()
{
	if(top==-1)
	cout<<"stack is empty";
	else
	{
	int data=a[top];
	top--;
	return data;
	}
}
void stack::display()
{
    if (top == -1)
    {
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
main()
{
	stack s;
	cout<<"Stack elements are:";
	s.push(10);
	s.push(20);
	s.display();
	int i=s.pop();
	cout<<"\npopped element is:"<<i;
}
