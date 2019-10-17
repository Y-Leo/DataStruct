#include<iostream>
#include<assert.h>
using namespace std;

//�鲢
void MergeData(int *arr, int left, int mid, int right, int *temp){
	int temp_index = left;
	int left_L = left;
	int left_R = mid;
	int right_L = mid;
	int right_R = right;
	while (left_L<left_R && right_L<right_R)
	{
		if (arr[left_L]<arr[right_L])
		{
			temp[temp_index++] = arr[left_L++];

		}
		else
		{
			temp[temp_index++] = arr[right_L++];
		}

	}
	while (left_L<left_R)
	{
		temp[temp_index++] = arr[left_L++];
	}
	while (right_L<right_R)
	{
		temp[temp_index++] = arr[right_L++];
	}

}
//����
//void *memcpy(void*dest, const void *src, size_t n);
//��srcָ���ַΪ��ʼ��ַ������n���ֽڵ����ݸ��Ƶ���destָ���ַΪ��ʼ��ַ�Ŀռ��ڡ�
void _MergeSort(int *arr, int left, int right, int *temp){
	if ((right - left)>1)
	{
		int mid = left + ((right - left) >> 1);
		_MergeSort(arr, left, mid, temp);
		_MergeSort(arr, mid, right, temp);
		MergeData(arr, left, mid, right, temp);
		memcpy(arr + left, temp + left, sizeof(int)*(right - left));
	}


}
//�ݹ�
void MergeSort(int *arr, int size){
	int *temp = (int *)malloc(size*sizeof(arr[0]));
	if (temp == NULL)
	{
		assert(0);
		return;
	}
	_MergeSort(arr, 0, size, temp);
	free(temp);
}
//�ǵݹ�
void MergeSort_Nor(int *arr, int size){
	int *temp = (int *)malloc(size*sizeof(arr[0]));
	if (temp == NULL)
	{
		assert(0);
		return;
	}
	int i = 0;
	int gap = 1;
	while (gap<size)
	{
		for (i = 0; i < size; i += 2 * gap){
			int left = i;
			int mid = left + gap;
			int right = mid + gap;
			if (mid>size)
			{
				mid = size;
			}
			if (right>size)
			{
				right = size;
			}
			MergeData(arr, left, mid, right, temp);
		}
		memcpy(arr, temp, size*sizeof(arr[0]));
		gap = gap * 2;
	}
	free(temp);
}
int main(){
	int array[] = { 2, 0, -4, 9234, 0, 2, 8, 1, 1, -5 };
	int size = sizeof(array) / sizeof(array[0]);
	MergeSort(array, size);
	//MergeSort_Nor(array, size);
	for (auto e : array)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}

