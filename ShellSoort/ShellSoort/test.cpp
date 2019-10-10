#include<iostream>
using namespace std;

void ShellSort(int* arr, int size)
{
	int i = 0;
	int key = 0;
	int end = 0;
	int gap = 3;
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			key = arr[i];
			end = i - gap;
			while (end >= 0 && key<arr[end])
			{
				arr[end + gap] = arr[end];
				end = end - gap;
			}
			arr[end + gap] = key;
		}
		gap--;
	}
}


int main()
{
	int array[] = { 1, 3, 4, 1, -1, 0, 2323, 0, 1, 342 };
	int size = sizeof(array) / sizeof(array[0]);

	ShellSort(array, size);
	//范围for循环打印数组元素
	for (auto e : array)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}