#include<iostream>
using namespace std;

//元素集合接近有序时,直接插入排序效率较高.
//直接插入排序,顺序查找
void Insertion_Sort(int* arr, int n)
{
	int i = 0, flag = 0, step = 0;
	for (i = 1; i < n; i++)
	{
		flag = arr[i];
		step = i - 1;
		while (step >= 0 && flag<arr[step])
		{
			arr[step + 1] = arr[step];
			step--;
		}
		arr[step + 1] = flag;
	}
}

//直接插入排序，二分查找
void Insert_Sort_Second(int* arr,int size)
{
	int left = 0;
	int right = size - 1;
	int mid = 0;
	int i = 0;
	int key = 0;
	for (i = 1; i < size; i++)
	{
		key = arr[i];
		left = 0;
		right = i - 1;
		//二分查找寻找待插入元素的位置
		while (left <= right)
		{
			mid = (left + right) >> 1;//   >>1  相当于  /2
			if (key<arr[mid])
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		//搬移left位置以后的元素
		right = i - 1;
		while (right >= left)
		{
			arr[right + 1] = arr[right];
			right--;
		}
		//插入元素
		arr[left] = key;
	}

}

int main()
{
	int array[] = { 0, -1, 3, 12, 12, -2, 1, 0, 5345, -2 };
	int size = sizeof(array) / sizeof(array[0]);  

	//Insertion_Sort(array, size);
	Insert_Sort_Second(array,size);


	//范围for循环打印数组
	for (auto e : array)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}