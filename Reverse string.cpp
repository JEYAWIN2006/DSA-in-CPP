#include <iostream>
#define max 100
using namespace std;
class stack 
{
    char a[max];
    int top;
public:
    stack()
	{
        top = -1;
    }
    void push(char x);
    char pop();
    void reverse(char str[]);
};
void stack::push(char x)
{
    if (top == max - 1) 
	{
        cout << "Stack is full" << endl;
    }
	 else 
	{
        top++;
        a[top] = x;
    }
}
char stack::pop() 
{
    if (top == -1)
	{
        cout << "Stack is empty" << endl;
        return 0;
    } 
	else
	{
        char data = a[top];
        top--;
        return data;
    }
}
void stack::reverse(char str[]) 
{
    
    int len = 0;
    while (str[len] != 0) 
	{
        len++;
    }
    for (int i = 0; i < len / 2; i++) 
	{
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
    
} 
int main() 
{
    stack s;
    s.reverse(s.push("Delton"));
    cout << "Reversed string: " <<str<<endl;
    return 0;
}
