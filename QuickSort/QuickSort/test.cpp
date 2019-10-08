
//˫���������
#include<iostream>
using namespace std;

void QuickSort(int* arr,int left, int right)
{
	if (left > right)
	{
		return;
	}
	int i = left;
	int j = right;
	//����ߵ�Ϊ׼����
	int flag = arr[left];
	while (i != j)
	{
		//���Ҳ��ҵ�һ���ȱ��С��ֵ
		while (arr[j] > flag && i < j)
		{
			j--;
		}
		//������ҵ�һ���ȱ�Ǵ��ֵ
		while (arr[i] <= flag && i < j)
		{
			i++;
		}
		//�����ҵ���ֵ,ʹ���С,�ұߴ�
		int temp = 0;
		if (i<j)
		{
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}//���whileѭ��,��ʱi=j

	//����׼����������ֵ,������ֵ��λ
	arr[left] = arr[i];
	arr[i] = flag;

	//����ֵ��,�Ҳ�����ݷֱ��������(�ݹ�)
	QuickSort(arr, left, i - 1);
	QuickSort(arr, i + 1, right);

}

int main()
{
	int array[10] = { 879, 1, 34, 45, -123, 34, 5, 0, 45, 1 };
	QuickSort(array,0,9);

	//��Χforѭ����ӡ����
	for (auto e:array)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}
