#include<iostream>
using namespace std;
class listadt
{
	struct node
	{
		int data;
		node *next;
		node *Prev;
	}*head;
	public:
		listadt()
		{
			head=NULL;
		}
		void insert_end(int);
		void insert_beg(int);
		void insert_pos(int,int);
		void delete_element(int);
		void display();		
};
void listadt::insert_end(int x)
{
	node *temp,*r;
	if(head==NULL)
	{
		temp=new node;
		temp->data=x;
		temp->next=NULL;
		temp->Prev=NULL;
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
		r->Prev=temp;
		temp->next=r;
	}
}
void listadt::insert_beg(int x)
{
	node *temp;
	temp=new node;
	temp->data=x;
	temp->next=head;
	temp->Prev=NULL;
	head=temp;
}
void listadt::insert_pos(int x,int pos)
{
	node *temp,*r;
	temp=head;
	for(int i=1;i<(pos-1);i++)
	{
	temp=temp->next;
    }
	r=new node;
	r->data=x;
	r->next=temp->next;
	temp->next=r;
	r->next->Prev=r;
}
void listadt::delete_element(int x)
{
    node *temp = head;
    if (head != NULL && head->data == x) 
	{
        node *temp = head;
        head = head->next;
        if (head != NULL) 
		{
            head->Prev = NULL;
        }
        delete temp;
        return;
    }

    while (temp != NULL) 
	{
        if (temp->data == x) 
		{
            if (temp->Prev != NULL) 
			{
                temp->Prev->next = temp->next;
            }
            if (temp->next != NULL) 
			{
                temp->next->Prev = temp->Prev;
            }
            delete temp;
            return;
        }
        temp = temp->next;
    }
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
	cout<<"Insert at end (33,44,55):  ";
	ob.insert_end(33);
	ob.insert_end(44);
	ob.insert_end(55);
	ob.display();
	cout<<" \n";
	cout<<" \n";
	cout<<"Insert at beg (22,11,10):   ";
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
	cout<<"After deletion (55):   ";
	ob.delete_element(55);
	ob.display();
	return 0;
}
