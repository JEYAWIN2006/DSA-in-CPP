
#include<iostream>
using namespace std;
int tablesize;
class hashing
{
	struct node
	{
		int element;
		node *next;
	}**list;
	public:
	int hash(int key)
	{
		return(key%tablesize);
	}
	void initializetable(int size)
	{
		int i;
		tablesize=size;
		list=new node*[tablesize];
		for(i=0;i<tablesize;i++)
			list[i]=NULL;
	}
	node* find(int key)
	{
		node *h;
		h=list[hash(key)];
		while(h!=NULL && h->element)
			h=h->next;
		return h;	
	}
	void insert(int key)
	{
		node *pos,*temp,*h;
		pos=find(key);
		if(pos==NULL)
		{
			temp=new node;
			h=list[hash(key)];
			temp->next=h;
			temp->element=key;
			list[hash(key)]=temp;
		}
	}
	void search(int key)
	{
		node *p;
		p=find(key);
		if(p==NULL)
			cout<<"Element not found";
		else
			cout<<"Element is present";	
	}
	void deletion(int key)
	{
		node *h,*temp;
		h=list[hash(key)];
		if(h!=NULL && h->element==key)
		{
			list[hash(key)]=h->next;
			delete(h);
		}
		else
		{
			temp=find(key);
			if(temp!=NULL)
			{
				h=list[hash(key)];
				while(h->next!=temp)
					h=h->next;
				h->next=temp->next;
				delete(temp);	
			}
			else
				cout<<"Element not found";
		}
	}
void display() 
{
    node *temp;
    if(temp==NULL)
    {
    	cout<<"NULL";
	}
	else
	{
    for (int i = 0; i < tablesize; i++) 
	{
        temp = list[i];
        cout << "Index " << i << ": ";  
		 
            while (temp != NULL) 
			{
                cout << temp->element << "-> "; 
                temp = temp->next; 
            }
    		cout<<"NULL";
			cout<<endl;	    
    }
	}
}
};
int main()
{
	hashing hs;
	hs.initializetable(10);
	hs.insert(4);
	hs.insert(9);
	hs.insert(16);
	hs.insert(25);
	hs.insert(49);
	hs.insert(64);
	hs.insert(81);	
	hs.display();
	return 0;
}