#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)

int BinarySearch(int arr[],int right,int n)
{
	
	int left = 0;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (n == arr[mid])
		{
			return mid;
		}
		else if (n < arr[mid])
		{
			right = mid - 1;
		}
		else if (n > arr[mid])
		{
			left = mid + 1;
		}
	}
	return -1;
}


int main()
{
	int n = 0;
	int arr[10] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
	int num = sizeof(arr) / sizeof(arr[0]);
	printf("请输入要查找的数：");
	scanf("%d", &n);
	if (BinarySearch(arr, num, n) != -1)
	{
		printf("恭喜你，找到了！%d的下标为：%d\n", n, BinarySearch(arr, num, n));
	}
	else
	{
		printf("很抱歉，未找到！");
	}
	system("pause");
	return 0;
}