#include<iostream>
using namespace std;
class quicksorting
{
public:
void swap(int *a, int *b) 
{ 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
}
void quicksort(int a[],int left,int right)
{
	if(left<right)
	{
		int i,j,pivot;
		pivot=a[right];
		i=left;
		j=right-1;
		for(; ;)
		{
			while(a[i]<pivot){i++;}
			while(a[j]>pivot){j--;}
			if(i<j)
				swap(&a[i],&a[j]);
			else
				break;	
		}
		swap(&a[i],&a[right]);
		quicksort(a,left,i-1);
		quicksort(a,i+1,right);
	}
}

		
};
int main()
{
    quicksorting q;
    int n,a[100];
    cout<<"Enter the numberof elements";
    cin>>n;
    cout<<"Enter the element of an array";
    for(int i=0;i<n;i++)
    	cin>>a[i];	
    q.quicksort(a,0,n-1);
    for (int i=0; i<n; i++)
        cout << a[i] << " ";
    cout << endl;
	return 0;
}
