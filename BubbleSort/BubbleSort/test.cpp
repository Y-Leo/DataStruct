//ð������
#include<iostream>
using namespace std;

void BubbleSort(int* arr, int n)
{
	int i , j , temp =0;

	//����ѭ�������ڵ����������ϱȽ�
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

	//��Χforѭ����ӡ����
	for (auto e: array)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}