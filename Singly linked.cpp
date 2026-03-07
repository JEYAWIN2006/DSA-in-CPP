#include<iostream>
using namespace std;
class listadt
{
	struct node
	{
		int data;
		node *next;
	}*head;
	public:
		listadt()
		{
			head=NULL;
		}
		void insert_end(int);
		void insert_beg(int);
		void insert_pos(int,int);
		int Islast(node *);
		void display();
		
node* find_Prev(int x)
{
	node* temp;
	temp=head;
	while(temp->next!=NULL&&temp->next->data!=x)
	{
		temp=temp->next;
	}
	return temp;
}		
void delete_element(int x)
{
	node *temp,*Prev;
	Prev=find_Prev(x);
	if(Prev->next!=NULL)
	{
		temp=Prev->next;
		Prev->next=temp->next;
		delete temp;
	}
}
void delete_elemenet_beg(int x)
{
	node *temp,*prev;
	if(head->data==x)
	{
		temp=head;
		head=temp->next;
		delete temp;
	}
	else
	{
		temp=prev->next;
		prev->next=temp->next;
		delete temp;
	}
}
};
void listadt::insert_end(int x)
{
	node *temp,*r;
	if(head==NULL)
	{
		temp=new node;
		temp->data=x;
		temp->next=NULL;
		head=temp;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		temp=temp->next;
		r=new node;
		r->data=x;
		r->next=NULL;
		temp->next=r;
	}
}
void listadt::insert_beg(int x)
{
	node *temp,*r;
	temp=new node;
	temp->data=x;
	temp->next=head;
	head=temp;
}
void listadt::insert_pos(int x,int pos)
{
	node *temp,*r;
	temp=head;
	for(int i=1;i<(pos-1);i++)
	temp=temp->next;
	r=new node;
	r->data=x;
	r->next=temp->next;
	temp->next=r;
}
int listadt::Islast(node *temp)
{
	if(temp->next==NULL)
		return 1;
	else
		return 0;
}
void listadt::display()
{
	node *temp;
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
main()
{
	listadt ob;
	cout<<"Insert at end (33,44,55):   ";
	ob.insert_end(33);
	ob.insert_end(44);
	ob.insert_end(55);
	ob.display();
	cout<<" \n";
	cout<<" \n";
	cout<<"Insert at beg(22,11,10):   ";
	ob.insert_beg(22);
	ob.insert_beg(11);
	ob.insert_beg(10);
	ob.display();
	cout<<" \n";
	cout<<" \n";
	cout<<"Insert at pos (9 at 2),(8 at 3),(5 at 4):   ";
	ob.insert_pos(9,2);
	ob.insert_pos(8,3);
	ob.insert_pos(5,4);
	ob.display();
	cout<<" \n";
	cout<<" \n";
	cout<<"After delete (33):   ";
	ob.delete_element(33);
	ob.display();
}
