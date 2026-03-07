#include <iostream>
using namespace std;

class MergeSort 
{
public:
    void sort(int a[], int size) 
	{
        int tempArray[20];
        mergeSort(a, tempArray, 0, size - 1);
        
    }

    void printArray(int a[], int size) 
	{
        for (int i = 0; i < size; i++) 
		{
            cout << a[i] << " ";
        }
        cout << endl;
    }

private:
    void merge(int a[], int tempArray[], int lPos, int rPos, int rightEnd)
	{
        int i, leftEnd, numElements, tempPos;

        leftEnd = rPos - 1;
        tempPos = lPos;
        numElements = rightEnd - lPos + 1;
		while (lPos <= leftEnd && rPos <= rightEnd)
	   {
            if (a[lPos] <= a[rPos])
                tempArray[tempPos++] = a[lPos++];
            else
                tempArray[tempPos++] = a[rPos++];
        }
        while (lPos <= leftEnd)
            tempArray[tempPos++] = a[lPos++];
               while (rPos <= rightEnd)
            tempArray[tempPos++] = a[rPos++];
        for (i = 0; i < numElements; i++, rightEnd--)
            a[rightEnd] = tempArray[rightEnd];
    }

    void mergeSort(int a[], int tempArray[], int left, int right) 
	{
        if (left < right) 
		{
            int center = (left + right) / 2;
            mergeSort(a, tempArray, left, center); 
            mergeSort(a, tempArray, center + 1, right); 
            merge(a, tempArray, left, center + 1, right); 
        }
    }
};

int main()
{
    const int size = 10; 
    int a[size] = {38, 27, 43, 3, 9, 82, 10, 15, 29, 49};
    MergeSort ms;
    cout << "Original array: ";
    ms.printArray(a, size);
    ms.sort(a, size); 
    cout << "Sorted array: ";
    ms.printArray(a, size);
    return 0;
}

