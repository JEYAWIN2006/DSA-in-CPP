#include<iostream>
#define max 20
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
		void push(int x);
		char pop();
		void display();
};
void stack::push(int x)
{
	if(top==max-1)
		cout<<"Stack is Full"<<endl;
	else
	{
		top++;
		a[top]=x;
	}
}
char stack::pop()
{
	if(top==-1)
		cout<<"Stack is Empty"<<endl;
	else
	{
		int data=a[top];
		a[top]=0;
		top--;
		return data;
	}
}
void stack::display()
{
	cout<<"The answer is "<<a[top];
}
int main()
{
	stack s;
	int x,y;
	char e[20];
	cout<<"Enter the Expression:";
	cin>>e;
	for(int i=0;e[i]!='\0';i++)
	{
		if(e[i]>='0'&&e[i]<='9')
		{
			s.push(e[i]-'0');     
		}
		else
		{
			x=s.pop();
			y=s.pop();
			if(e[i]=='+')
				s.push(x+y);
			else if(e[i]=='-')
				s.push(x-y);
			else if(e[i]=='*')
				s.push(x*y);
			else if(e[i]=='/')
				s.push(x/y);
		}
	}
	s.display();
	return 0;
}
