#include<iostream>
using namespace std;
#include<assert.h>
#include<malloc.h>

//ͳ�����Ԫ�ص�λ��
int GetMaxValue_BitCount(int* arr,int size)
{
	int i = 0;
	int count = 1;
	int ret = 10;
	for(i = 0; i < size; i++)
	{
		while (arr[i] >= ret)
		{
			count++;
			ret *= 10;
		}
	}
	return count;
}

void _RadixSort(int* arr, int size, int *temp)
{
	int Max_BitCount = GetMaxValue_BitCount(arr, size);
	//��ÿ��Ͱ��Ԫ�صĸ���
	int count[10] = { 0 };
	//��ÿ��Ͱ����ʼ��ַ
	int start_Addr[10] = { 0 };
	int i = 0;
	int ret = 1;
	int index = 0;
	while (Max_BitCount)
	{
		//ͳ�Ƹ���
		for (i = 0; i < size; i++)
		{
			count[arr[i] / ret % 10]++;
		}
		//ͳ�Ƶ�ַ
		for (i = 1; i < 10; i++)
		{
			start_Addr[i] = start_Addr[i - 1] + count[i - 1];
		}
		//����Ԫ�ص���ʱ�ռ���
		for (i = 0; i < size; i++)
		{
			int Addr = arr[i] / ret % 10;
			temp[start_Addr[Addr]++] = arr[i];
		}
		//����Ԫ��
		memcpy(arr, temp, size*sizeof(arr[0]));
		ret *= 10;
		Max_BitCount--;
	}
}

void RadixSort(int*arr, int size)
{
	int *temp =(int*) malloc(size*sizeof(arr[0]));
	if (temp == NULL)
	{
		assert(0);
		return;
	}
	_RadixSort(arr, size, temp);
	free(temp);
}

int main()
{
	int array[] = { 2, 34, 56, 63, -1, 0, 1, 2, -1, -3 };
	int size = sizeof(array) / sizeof(array[0]);

	RadixSort(array, size);

	for (auto e : array)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}