#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
int cmp_int(const void *p1, const void *p2)
{
	const int *_p1 = (const int *)p1;
	const int *_p2 = (const int *)p2;
	if (*_p1 > *_p2)
	return 1;
	else if (*_p1 < *_p2)
	return -1;
	else
	return 0;
}

char cmp_char(const void *p1, const void *p2)
{
	const char *_p1 = (const char *)p1;
	const char *_p2 = (const char *)p2;
	if (*_p1 > *_p2)
		return 1;
	else if (*_p1 < *_p2)
		return -1;
	else
		return 0;
}

float cmp_float(const void *p1, const void *p2)//两个double类型不能直接比较大小,会有精度丢失
{
	const float *_p1 = (const float *)p1;
	const float *_p2 = (const float *)p2;
	if (*_p1 > *_p2)
		return -1;
	else if (*_p1 < *_p2)
		return 1;
	else
		return 0;
}

void swap(char *x, char *y, int size)
{
	while (size--)
	{
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
		x++, y++;
	}
}

typedef int(*cmp_t)(const void *, const void*);

void my_bubble(void *base, int num, int size, cmp_t cmp)
{
	int i = 0;
	char *_base = (char*)base;
	for (; i < num - 1; i++)
	{
		int j = 0;
		int flag = 0;
		for (; j < num - 1 - i; j++)
		{
			if (cmp(_base + j*size, _base + (j + 1)*size) > 0)
			{
				flag = 1;
				swap(_base + j*size, _base + (j + 1)*size, size);
			}
			if (flag == 0)
			{
				break;
			}
		}
	}
}
int main()
{
	int arr0[] = { 1, 2, 3, 4, 654, 3, 2, 4, 3556, 452, 32, 4 };
	int len0 = sizeof(arr0) / sizeof(arr0[0]);
	char arr1[] = { 'c', 'd', 'y', 'd', 's', 'd', 'w', 'i', 'i', 'k' };
	int len1 = sizeof(arr1) / sizeof(arr1[0]);
	float arr2[] = { 0.3, 0.1, 0.67, 0.232, 57.0, 0.6, 0.0 };
	int len2 = sizeof(arr2) / sizeof(arr2[0]);
	int i = 0;
	my_bubble(arr0, len0, sizeof(int), &cmp_int); //对于函数指针（指向函数的指针），直接传入函数名和函数名进行&运算都是可以的，
	//因为在调用函数时也是取的函数的地址
	my_bubble(arr1, len1, sizeof(char), cmp_char);
	my_bubble(arr2, len2, sizeof(float), cmp_float);
	for (i = 0; i < len0; i++)
	{
		printf("%d ", arr0[i]);
	}
	printf("\n");
	for (i = 0; i < len1; i++)
	{
		printf("%c ", arr1[i]);
	}
	printf("\n");
	for (i = 0; i < len2; i++)
	{
		printf("%lf ", arr2[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}