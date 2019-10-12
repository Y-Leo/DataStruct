//÷±Ω”—°‘Ò≈≈–Ú
#include<iostream>
using namespace std;

void swap(int *a, int *b){
	int ret = 0;
	ret = *a;
	*a = *b;
	*b = ret;
}

void SelectionSort(int* arr, int size)
{
	int left = 0;
	int right = size - 1;
	int i = 0;
	while (left<right)
	{
		int MinIndex = left;
		int MaxIndex = left;
		for (i = left; i <= right; i++)
		{
			if (arr[MinIndex]>arr[i])
				MinIndex = i;
			if (arr[MaxIndex]<arr[i])
				MaxIndex = i;
		}
		swap(&arr[left], &arr[MinIndex]);
		if (MaxIndex == left)
		{
			MaxIndex = MinIndex;
		}
		swap(&arr[right], &arr[MaxIndex]);
		left++;
		right--;
	}
}

int main()
{
	int array[] = { 1, 24, 345, -1, 0, 24, 121, 0, -1, 1 };
	int size = sizeof(array) / sizeof(array[0]);

	SelectionSort(array, size);

	for (auto e : array)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}
