//冒泡排序
#include<iostream>
using namespace std;

void BubbleSort(int* arr, int n)
{
	int i , j , temp =0;

	//两层循环让相邻的两个数不断比较
	for (i=0; i < n - 1; i++)
	{
		for (j=0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
int main()
{
	int array[] = { 1, 34, 654, -1, 3242, 0, 2, 1, -1, 20 };
	int num = sizeof(array) / sizeof(array[0]);

	BubbleSort(array, num);

	//范围for循环打印数组
	for (auto e: array)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}