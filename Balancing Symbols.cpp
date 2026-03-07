#include<iostream>
#define max 100
using namespace std;
class stack
{
	int a[max];
	public:
		int top;
		stack()
		{
			top=-1;
		}
		void push(int x);
		int pop();
		char check();
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
int stack::pop()
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
char stack::check()
{
	return a[top];
}
int main()
{
	stack s;
	char e[30];
	cout<<"Enter the Expression:";
	cin>>e;
	for(int i=0;e[i]!='\0';i++)
	{
		if(e[i]=='('||e[i]=='['||e[i]=='{')
			s.push(e[i]);
		else if(e[i]==')')
		{
			if(s.check()=='(')
				s.pop();
			else
			{
				s.top=1;
				break;
			}
		}
		else if(e[i]=='}')
		{
			if(s.check()=='{')
				s.pop();
			else
			{
				s.top=1;
				break;
			}
		}
		else if(e[i]==']')
		{
			if(s.check()=='[')
				s.pop();
			else
			{
				s.top=1;
				break;
			}
		}
	}
	if(s.top==-1)
		cout<<"It is a Balanced Expression";
	else
		cout<<"Not a Balanced Expression";
	return 0;
}
