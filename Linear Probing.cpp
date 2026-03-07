#include<iostream>
using namespace std;
#define True 1
#define False 0
#define tablesize 10
class linearprobing
{
	struct node
	{
		int data;
		int occupied;
    };
	node*list[tablesize];
public:
	void initialize()
{
	int i;
	for(i=0;i<tablesize;i++)
	{
		list[i]=new node;
		list[i]->data=-1;
		list[i]->occupied=False;
	}
}
int hash(int val)
{
	return val%tablesize;
}
void insert(int val)
{
	int position,count=0;
	position=hash(val);
	while(list[position]->occupied==True && count<tablesize)
	{
		position=hash(position+1);
		count++;
	}
	if(count>=tablesize)
		cout<<"Hash Table is full";
	else
	{
		list[position]->data=val;
		list[position]->occupied=True;
	}		
}
int find(int val)
{
	int position=hash(val);
	int count=0;
	while(list[position]->data!=val && count<tablesize)
	{
		position=hash(position+1);
		count++;
	}
	if(count>=tablesize)
		return -1;
	else
		return position;	
}
void deletion(int val)
{
    int position=find(val);
	if(position==-1)
		cout<<"Element not found";
	else
	{
		list[position]->data=-1;
		list[position]->occupied=False;
	}		
}
void display() 
{
    node *temp;
    for (int i = 0; i <tablesize; i++) 
	{
        temp = list[i];
        cout << "Index " << i << ": ";  
		cout << temp->data << "-> ";
		cout << temp->occupied << " ";
		cout<<endl;   
            
	}
}

};
int main()
{ 
	linearprobing lp;
	lp.initialize();
	lp.insert(89);
	lp.insert(18);
	lp.insert(49);
	lp.insert(58);
	lp.insert(69);
	lp.display();
	cout<<"After deleting 89"<<endl;
	lp.deletion(89);
	lp.display();
	return 0;	
}




