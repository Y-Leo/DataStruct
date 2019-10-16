
//¶ÑÅÅĞò
#include<iostream>
using namespace std;

//½»»»
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

//½¨¶Ñ
void Heap_build(int array[], int root, int length)
{
	int lchild = root * 2 + 1;
	if (lchild < length)
	{
		int flag = lchild;
		int rchild = lchild + 1;
		if (rchild < length)
		{
			if (array[rchild] > array[flag])
			{
				flag = rchild;
			}
		}
		if (array[root] < array[flag])
		{
			Swap(array[root], array[flag]);
			Heap_build(array, flag, length);
		}
	}
}

//¶ÑÅÅĞò
void HeapSort(int array[], int len)
{
	for (int i = len / 2; i >= 0; i--)
	{
		Heap_build(array, i, len);
	}

	for (int j = len - 1; j > 0; --j)
	{
		Swap(array[0], array[j]);
		Heap_build(array, 0, j);
	}

}


int main()
{
	int array[] = { 1, 34, 34, 0, 121, 1, -1, -5, 13123, 0 };
	int size = sizeof(array) / sizeof(array[0]);

	HeapSort(array, size);

	//·¶Î§forÑ­»·±éÀú´òÓ¡Êı×é
	for (auto e : array)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}