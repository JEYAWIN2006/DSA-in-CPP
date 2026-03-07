#include<iostream>
using namespace std;
#define max 20
class listadt
{
	int a[max];
	int data,index;
	public:
		listadt()
		{
			index=-1;
		}
		void insert_end();
		void insert_beg();
		void insert_pos();
		void delete_element();
		void display();
};
void listadt::insert_end()
{
	if(index==max-1)
	{
		cout<<"List is full";
	}
	else
	{
		cout<<"Enter the element:";
		cin>>data;
		index++;
		a[index]=data;
	}
}
void listadt::insert_beg()
{
	if(index==max-1)
	{
		cout<<"list is full"<<endl;
	}
	else
	{
		cout<<"Enter the data to be inserted at beg:";
		cin>>data;
		for(int i=index;i>=0;i--)
		a[i+1]=a[i];
		a[0]=data;
		index++;
    } 
}
void listadt::insert_pos()
{
	if(index==max-1)
	{
		cout<<"List is full";
		
	}
	else
	{
		int pos;
		cout<<"Enter the data to be inserted and position:";
		cin>>data>>pos;
		for(int i=index;i>=(pos-1);i--)
			a[i+1]=a[i];
		a[pos-1]=data;
		index++;
	    
	}
}
void listadt::delete_element()
{
	if(index==-1)
	{
		cout<<"List is empty";
		
	}
	else
	{
		cout<<"Enter the element to be dlt:";
		cin>>data;
		for(int i=0;i<=index;i++)
		{
			if(a[i]==data)
			{
				while(i<=index)
				{
					a[i]=a[i+1];
					i++;
				}
			}
		}
	a[index]=0;
	index--;
	}
}
void listadt::display()
{
	for(int i=0;i<=index;i++)
	cout<<a[i]<<" ";
    cout<<"\n";	
}
main()
{
	listadt ob;
	ob.insert_end();
	ob.insert_end();
	ob.insert_end();
    ob.display();
	ob.insert_beg();
	ob.display();
	ob.insert_pos();
	ob.display();
	ob.delete_element();
	ob.display();
}
