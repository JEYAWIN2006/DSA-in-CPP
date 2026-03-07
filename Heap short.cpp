#include<iostream>
#define leftchild(i) (2*(i)+1)
using namespace std;
class heapsort
{   public:
	void percdown(int A[],int i,int N)
	{
		int child;
		int temp;
		for(temp=A[i];leftchild(i)<N;i=child)
		{
			child=leftchild(i);
			if(child!=N-1&&A[child+1]>A[child])
				child++;
		    if (temp<A[child])
		    	A[i]=A[child];
		    else
		    	break;
		}
		A[i]=temp;
	}
	void Heapsort(int A[],int N)
	{
		int i;
		for(i=N/2;i>=0;i--)
			perdown(A,i,N);
		for(i=N-1;i>0;i--)
		{
			swap(A[0],A[i]);
			perdown(A,0,i);
		}
	}
	
};
int main()
{
	int n,a[100];
	heapsort h;
    cout<<"Enter the number of element:";
    cin>>n;
    cout<<"Enter the element for an array:";
    for(int i=0;i<n;i++)
    	cin>>a[i];
    	
	int N=n;
	h.Heapsort(a,N);
    cout<<"Sorted array:";
	for(int i=0;i<N;i++)
		cout<<a[i]<<" ";
	
}
