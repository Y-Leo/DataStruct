#include<iostream>
#include<assert.h>
using namespace std;

int GetMaxValue(int *arr, int size){
	int i = 0;
	int max = arr[0];
	for (i = 1; i < size; i++)
	{
		if (arr[i]>max)
			max = arr[i];
	}
	return max;

}
int GetMinValue(int *arr, int size){
	int i = 0;
	int min = arr[0];
	for (i = 1; i < size; i++)
	{
		if (arr[i]<min)
			min = arr[i];
	}
	return min;

}
void _Count_Sort(int *arr, int *temp, int size, int ret, int min){
	int i = 0;
	int index = 0;
	//统计个数
	for (i = 0; i < size; i++)
	{
		temp[arr[i] - min]++;
	}
	//回收,把temp里的数据回收到原空间里
	for (i = 0; i <ret; i++)
	{
		while (temp[i]--)
		{
			arr[index++] = i + min;
		}
	}
	free(temp);
}
void Count_Sort(int *arr, int size){
	int max = GetMaxValue(arr, size);
	int min = GetMinValue(arr, size);
	int ret = max - min + 1;
	int *temp = (int *)malloc(ret*sizeof(arr[0]));
	if (temp == NULL)
	{
		assert(0);
		return;
	}
	//memset作用是在一段内存块中填充某个给定的值，它是对较大的结构体或数组进行清零操作的一种最快方法
	memset(temp, 0, ret*sizeof(int));
	_Count_Sort(arr, temp, size, ret, min);
}
int main(){
	int array[] = { 3, 4, -3, 2, 0, 2, 6, -5, 4, 7 };
	int size = sizeof(array) / sizeof(array[0]);
	Count_Sort(array, size);
	for (auto e:array)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}

