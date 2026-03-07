#include <iostream>
#define max 100
using namespace std;
class insertion 
{
public:
    void insertion_sort(int a[], int N) 
	{
        int i, pass, temp;
        for (pass = 1; pass < N; pass++) 
		{
            temp = a[pass];
            for (i = pass; i > 0 && a[i - 1] > temp; i--) 
			{
                a[i] = a[i - 1];
            }
            a[i] = temp;
        }
    }

    void swap(int &a, int &b)
	{
        int temp = a;
        a = b;
        b = temp;
    }
};

int main() 
{
    insertion si;
    int arr1[max];
    int N1;

    cout << "Enter Size of array: ";
    cin >> N1;
    cout << "Enter the array elements: ";
    for (int i = 0; i < N1; i++)
        cin >> arr1[i];

    si.insertion_sort(arr1, N1);

    cout << "After the insertion sort: ";
    for (int i = 0; i < N1; i++)
        cout << arr1[i] << " ";
    cout << endl;

    return 0;
}
