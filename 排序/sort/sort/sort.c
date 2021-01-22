#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



//��������
void Swap(int* arr, int pos1, int pos2)
{
	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}
//��������,ʱ�临�Ӷ�o��n^2��
void insertSort(int* arr, int n)
{
	//�����һ����������,�����ٲ���
	//δ��������ݣ�[1,n) --> [1,n-1]
	for (int i = 1; i < n; i++)
	{
		//���������ݵ����һ��λ����ǰ����
		int end = i - 1;
		//�����������
		int data = arr[i];
		while (end >= 0 && arr[end] >= data)
		{
			//�����������ƶ�
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = data;
	}
}


//ϣ������
void shellSort(int* arr, int n)
{
	//gap��ͬ���������ڼ��
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//���һ�����򣬼��������1����֤�������ݶ���ͬһ��
		//һ��ϣ������
		for (int i = gap; i < n; i++)
		{
			//���������ݵ����һ��λ����ǰ����
			int end = i - gap;
			//�����������
			int data = arr[i];
			while (end >= 0 && arr[end] >= data)
			{
				//�����������ƶ�
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = data;
		}
	}
}


//ѡ������
void selectSort1(int* arr, int n)
{
	for (int i = 0; i <= n - 1; i++)
	{
		int key = i;
		for (int j = i + 1; j <= n - 1; j++)
		{
			if (arr[j] < arr[key])
				key = j;
		}
		if (key != i)
		{
			int tmp = arr[i];
			arr[i] = arr[key];
			arr[key] = tmp;
		}
	}
}


//ѡ������
void selectSort2(int* arr, int n)
{
	//��δ���������������ֵ����ŵ�δ�������ʼλ��
	//δ��������䣺[start,end]
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		//�ҵ���Сֵ��λ��
		int minIdx = start;
		int i;
		for (i = start + 1; i <= end; i++)
		{
			if (arr[i] < arr[minIdx])
				minIdx = i;
		}
		//����Сֵ�濪ʼ��λ��
		Swap(arr, start, minIdx);
		//ʣ���δ��������䣺[start+1,end]
		++start;
	}
}


//ѡ������
void selectSort3(int* arr, int n)
{
	int start = 0;
	int end = n - 1;
	//ÿ�δ�δ����������ҵ�һ�����ֵ��һ����Сֵ
	//��Сֵ����ͷ�������ֵ����β��
	//�����Ĵ�������һ��
	while (start < end)
	{
		int minIdx = start;
		int maxIdx = start;

		//�ҵ����ֵ����Сֵ
		for (int j = start + 1; j <= end; j++)
		{
			if (arr[j] < arr[minIdx])
				minIdx = j;
			if (arr[j] > arr[maxIdx])
				maxIdx = j;
		}
		//��Сֵ����ͷ��
		Swap(arr, start, minIdx);

		//�ж����ֵ��λ���Ƿ�����ʼλ��:��Ҫ�ı�һ����ţ����򽻻�ֻ�ǽ���ֵ��û�н������
		//����maxIdx�������startλ�ã�������ʱ���õ�������Сֵ
		if (maxIdx == start)
			maxIdx = minIdx;

		Swap(arr, end, maxIdx);
		start++;
		end--;
	}
}


//������
//���µ���
void shiftDown(int* arr, int n, int parent)
{
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child + 1] > arr[child])
			child++;
		if (arr[child] > arr[parent])
		{
			Swap(arr, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}
//���򣺽����
void heapSort(int* arr, int n)
{
	//����,�����һ����Ҷ�ӽ�㿪ʼ���µ���
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		shiftDown(arr, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(arr, end, 0);
		shiftDown(arr, end, 0);
		--end;
	}
}



//ð������
void bubbleSort(int* arr, int n)
{
	//����Ԫ�ؽ��бȽ�
	//ÿһ�α����ķ�Χ��0����δ�������ݵ����һ��λ��
	int end = n;
	//һ��Ԫ�ؾͲ��������ˣ�������Ӧ��λ��
	while (end > 1)
	{
		//flag,��ǣ����������������˵���ź��ˣ�����
		int flag = 0;
		//һ��ð������
		//for(int i=0;i<end-1;i++)
		for (int i = 1; i < end; i++)
		{
			if (arr[i - 1] > arr[i])
			{
				//��������
				Swap(arr, i - 1, i);
				flag = 1;
			}
		}
		if (!flag)
			break;
		//����n-1��
		end--;
	}
}



//hoare���������򣬲��ȶ�
//��������ʱ��û���Ż�ʱ�����ܻᵼ��ջ���o��n^2����ջ�ĵ��ò���Լ�������ݵĸ���n
//���һ�λ���
int partion1(int* arr, int begin, int end)
{
	//ѡ���׼ֵ
	int key = arr[begin];
	int start = begin;
	while (begin < end)
	{
		//�Ӻ���ǰ����С�ڻ�׼ֵ��λ��
		while (begin < end && arr[end] >= key)
			--end;
		//��ǰ����Ҵ��ڻ�׼ֵ��λ��
		while (begin < end && arr[begin] <= key)
			++begin;
		//����
		Swap(arr, begin, end);
	}
	//������׼ֵ������λ�õ�����
	Swap(arr, start, begin);
	//����������λ�ã����ػ���֮�󣬻�׼ֵ����λ��
	return begin;
}
//�ݹ����һ�λ���
void quickSort1(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//div��һ�λ���֮�󣬻�׼ֵ��λ��
	int div = partion1(arr, begin, end);
	//���������ֽ��п�������
	//[begin,div-1]
	//[div+1��end]
	quickSort1(arr, begin, div - 1);
	quickSort1(arr, div + 1, end);
}


//�Ż���Ŀ�������
//��������ʱ���Ż��󻮷ּƽϾ���o��nlogn����ջ�ĵ��ò���logn
//ѡǰ�к�λ�õ��м�ֵΪ��׼ֵ
int getMid(int* arr, int begin, int end)
{
	int mid = begin + (end - begin) / 2;
	//mid < begin
	if (arr[begin] > arr[mid])
	{
		if (arr[mid] > arr[end])   //end < mid < begin
			return mid;
		else if (arr[begin] > arr[end])   //mid < end < begin
			return end;
		else                       //mid < begin <end
			return begin;
	}
	else
	{
		//begin < mid
		if (arr[mid] < arr[end])   //begin < mid < end
			return mid;
		else if (arr[begin] < arr[end])   //begin < end < mid
			return end;
		else                         //end < begin < mid
			return begin;
	}
}
//���һ�λ���
int partion2(int* arr, int begin, int end)
{
	//��ȡ��׼ֵ��λ��
	int mid = getMid(arr, begin, end);
	//�ѻ�׼ֵ������ʼλ��
	Swap(arr, begin, mid);
	int key = arr[begin];
	int start = begin;
	while (begin < end)
	{
		//�Ӻ���ǰ����С�ڻ�׼ֵ��λ��
		while (begin < end && arr[end] >= key)
			--end;
		//��ǰ����Ҵ��ڻ�׼ֵ��λ��
		while (begin < end && arr[begin] <= key)
			++begin;
		//����
		Swap(arr, begin, end);
	}
	//������׼ֵ������λ�õ�����
	Swap(arr, start, begin);
	//����������λ�ã����ػ���֮�󣬻�׼ֵ����λ��
	return begin;
}
//�ݹ����һ�λ���
void quickSort2(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//div��һ�λ���֮�󣬻�׼ֵ��λ��
	int div = partion2(arr, begin, end);
	//���������ֽ��п�������
	//[begin,div-1]
	//[div+1��end]
	quickSort2(arr, begin, div - 1);
	quickSort2(arr, div + 1, end);
}



//�ڿӷ���������
int partion3(int* arr, int begin, int end)
{
	//ѡ���׼ֵ
	int mid = getMid(arr, begin, end);
	Swap(arr, begin, mid);

	//��һ��ֵ��Ϊ��׼ֵ����һ��λ��Ϊ��ʶ�Ŀӵ�λ��
	int key = arr[begin];
	while (begin < end)
	{
		//�Ӻ���ǰ����С�ڻ�׼ֵ��λ��
		while (begin < end && arr[end] >= key)
			--end;
		//���
		arr[begin] = arr[end];
		//��ǰ����Ҵ��ڻ�׼ֵ��λ��
		while (begin < end && arr[begin] <= key)
			++begin;
		//���
		arr[end] = arr[begin];
	}
	arr[begin] = key;
	return begin;
}
//�ݹ����һ�λ���
void quickSort3(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//div��һ�λ���֮�󣬻�׼ֵ��λ��
	int div = partion3(arr, begin, end);
	//���������ֽ��п�������
	//[begin,div-1]
	//[div+1��end]
	quickSort3(arr, begin, div - 1);
	quickSort3(arr, div + 1, end);
}



//ǰ��ָ�뷨��������
//prev:��һ��С�ڻ�׼ֵ��λ��,cur:��һ��С�ڻ�׼ֵ��λ��
//��cur�ߵ�һ��С�ڻ�׼ֵ��λ�ã����ж�prev��cur�Ƿ�����
//�������������[prev,cur]��ֵ����С�ڻ�׼ֵ��ֵ������prev��cur
//���������������[prev,cur]��ֵ���д��ڵ��ڻ�׼ֵ��ֵ������prev�����ݽ���������cur
int partion4(int* arr, int begin, int end)
{
	int mid = getMid(arr, begin, end);
	Swap(arr, begin, mid);

	//��һ��С�ڻ�׼ֵ��λ��
	int prev = begin;
	//��һ��С�ڻ�׼ֵ��λ��
	int cur = begin + 1;
	int key = arr[begin];
	while (cur <= end)
	{
		//��cur�ߵ���һ��С�ڻ�׼ֵ��λ�ã��ж�prev��cur�Ƿ�����
		if (arr[cur] < key && ++prev != cur)
		{
			//���������������ݣ�prev��cur
			Swap(arr, prev, cur);
		}
		++cur;
	}
	Swap(arr, begin, prev);
	return prev;
}
//�ݹ����һ�λ���
void quickSort4(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//div��һ�λ���֮�󣬻�׼ֵ��λ��
	int div = partion4(arr, begin, end);
	//���������ֽ��п�������
	//[begin,div-1]
	//[div+1��end]
	quickSort4(arr, begin, div - 1);
	quickSort4(arr, div + 1, end);
}


//������������������һ���ģ�����СС���Ż�
void quickSort(int* arr, int begin, int end)
{
	if (begin >= end)
		return;

	//С�����Ż�
	if (end - begin < 10)
	{
		//��������
		insertSort(arr + begin, end - begin + 1);
	}
	else
	{
		//div��һ�λ���֮�󣬻�׼ֵ��λ��
		int div = partion4(arr, begin, end);
		//���������ֽ��п�������
		//[begin,div-1]
		//[div+1��end]
		quickSort4(arr, begin, div - 1);
		quickSort4(arr, div + 1, end);
	}
}



//
////�ǵݹ��������
////˳����Žӿ�
//void quickSortNor1(int* arr, int n)
//{
//	//����һ��˳������滮������
//	seqList sq;
//	initseqList(&sq);
//	//���ȱ�����������
//	//���ȷ��ң��ٷ���[0,n-1]
//	seqListPushBack(&sq, n - 1);
//	seqListPushBack(&sq, 0);
//	//����˳���������������
//	while (!seqListEmpty(&sq))
//	{
//		//ȡ��һ������
//		int left = seqListBack(&sq);
//		seqListpopBack(&sq);
//		int right = seqListBack(&sq);
//		seqListpopBack(&sq);
//
//		//��������[left,right]
//		int div = partion1(arr, left, right);
//
//		//�������������������[left,div-1]
//		if (left < div - 1)
//		{
//			seqListPushBack(&sq, div - 1);
//			seqListPushBack(&sq, left);
//		}
//		//[div+1,right]
//		if (div + 1 < right)
//		{
//			seqListPushBack(&sq, right);
//			seqListPushBack(&sq, div + 1);
//		}
//	}
//}
//
//
//
////���д�Žӿ�
//void quickSortNor2(int* arr, int n)
//{
//	//�����жӣ����滮������
//	Queue q;
//	queueInit(&q);
//	//���ȱ���[0��n-1]����
//	//�����Ƚ��ȳ��������󣬺�����
//	queuePush(&q, 0);
//	queuePush(&q, n-1);
//	//����˳���������������
//	while (!queueEmpty(&q))
//	{
//		//ȡ��һ������
//		int left = queueFront(&q);
//		queuePop(&q);
//		int right = queueFront(&q);
//		queuePop(&q);
//
//		//��������[left,right]
//		int div = partion1(arr, left, right);
//
//		//�������������������[left,div-1]
//		if (left < div - 1)
//		{
//			queuePush(&q, left);
//			queuePush(&q, div-1);
//		}
//		//[div+1,right]
//		if (div + 1 < right)
//		{
//			queuePush(&q, div + 1);
//			queuePush(&q, right);
//		}
//	}
//}



//�鲢����
//�鲢���ϲ�����������У���������������������
      //�ֽ⣺�����ݰ���λ�ã�����ķֳ����������У�һֱ����������ֻ��һ������
	  //�ϲ�����������������н��кϲ�������Ĺ����У���Ҫo��n���ĸ����ռ�
void merge(int* arr, int begin, int mid, int end, int* tmp)
{
	//����
	//�����䣺[begin,mid],[mid+1],end]
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;

	//�����ռ����ʼλ��
	int idx = begin;

	//�ϲ���������
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] <= arr[begin2])
			tmp[idx++] = arr[begin1++];
		else
			tmp[idx++] = arr[begin2++];
	}
	//�ж��Ƿ���Ϊ�ϲ���Ԫ�أ������ʣ��Ԫ�أ���ʣ��Ԫ��ȫ������tmp����Ӧλ��
	if (begin1 <= end1)
		memcpy(tmp + idx, arr + begin1, sizeof(int) * (end1 - begin1 + 1));
	if (begin2 <= end2)
		memcpy(tmp + idx, arr + begin2, sizeof(int) * (end2 - begin2 + 1));

	//�ϲ�֮��Ąÿ����Ű�������Ķ�Ӧ����
	memcpy(arr + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}
void _mergeSort(int* arr, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	
	int mid = begin + (end - begin) / 2;

	//���Ⱥϲ�������
	_mergeSort(arr, begin, mid, tmp);
	_mergeSort(arr, mid + 1, end, tmp);

	//�ϲ����������������[begin,mid],[mid+1,end]
	merge(arr, begin, mid, end, tmp);
}
void mergeSort(int* arr, int n)
{
	//���븨���ռ�
	int* tmp = (int*)malloc(sizeof(int) * n);
	_mergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}


//�ǵݹ飬�鲢����
//Ҫ�ϲ��ĵ�һ������begin: idx ,     end: idx + step - 1
//Ҫ�ϲ��ĵڶ�������begin: idx + step,    end: idx + 2 * step - 1  
//idx += 2 * step
//step*=2
void mergeSortNor(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	//�����еĲ���
	int step = 1;
	while (step < n)
	{
		for (int idx = 0; idx < n; idx += 2 * step)
		{
			//�ҵ��������ϲ�������������[begin,mid],[mid+1,end]
			int begin = idx;
			int mid = idx + step - 1;

			//�ж��Ƿ���ڵڶ���������
			if (mid >= n - 1)
				//�����ڵڶ���������
				continue;

			int end = idx + 2 * step - 1;
			//�жϵڶ����������Ƿ�Խ��
			if (end >= n)
				end = n - 1;

			//�ϲ�
			merge(arr, begin, mid, end, tmp);
		}
		//���²���
		step *= 2;
	}
}


//�ǱȽ����򣬼�������
//ʱ�临�Ӷȣ�O��Max(n,range)),  �ռ临�Ӷȣ�O(range)
//�����Χ�ر����˷ѿռ�޴�
void countSort(int* arr, int n)
{
	//�ҵ�������Сֵ
	int max, min;
	min = max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	//���㷶Χ
	int range = max - min + 1;
	//�½�һ���������飬��ʼ��Ϊ0
	int* countArr = (int*)calloc(range, sizeof(int));

	//����
	for (int i = 0; i < n; i++)
	{
		countArr[arr[i] - min]++;
	}

	//�����������飬����
	int idx = 0;
	for (int i = 0; i < range; i++)
	{
		while (countArr[i]--)
		{
			arr[idx++] = i + min;
		}
	}
}




void printArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


void testinsertSort()
{
	int arr[] = { 1,2,5,6,4,8,9,3,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	insertSort(arr, sz);
	printArr(arr, sz);
}



void testshellSort()
{
	int arr[] = { 1,2,5,6,4,8,9,3,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	shellSort(arr, sz);
	printArr(arr, sz);
}


void testselectSort1()
{
	int arr[] = { 1,2,5,6,4,8,9,3,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	selectSort1(arr, sz);
	printArr(arr, sz);
}


void testselectSort2()
{
	int arr[] = { 1,2,5,6,4,8,9,3,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	selectSort2(arr, sz);
	printArr(arr, sz);
}


void testselectSort3()
{
	int arr[] = { 1,2,5,6,4,8,9,3,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	selectSort3(arr, sz);
	printArr(arr, sz);
}


void testheapSort()
{
	int arr[] = { 1,2,5,6,4,8,9,3,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr, sz);
	printArr(arr, sz);
}


void testbubbleSort()
{
	int arr[] = { 1,2,5,6,4,8,9,3,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, sz);
	printArr(arr, sz);
}


void testquickSort1()
{
	int arr[] = { 1,2,5,6,4,8,9,3,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	quickSort1(arr, 0, sz - 1);
	printArr(arr, sz);
}


void testquickSort2()
{
	int arr[] = { 1,2,5,6,4,8,9,3,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	quickSort2(arr, 0, sz - 1);
	printArr(arr, sz);
}


void testquickSort3()
{
	int arr[] = { 1,2,5,6,4,8,9,3,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	quickSort3(arr, 0, sz - 1);
	printArr(arr, sz);
}


void testquickSort4()
{
	int arr[] = { 1,2,5,6,4,8,9,3,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	quickSort4(arr, 0, sz - 1);
	printArr(arr, sz);
}


void testmergeSort()
{
	int arr[] = { 1,2,5,6,4,8,9,3,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr, sz);
	printArr(arr, sz);
}

void testmergeSortNor()
{
	int arr[] = { 1,2,5,6,4,8,9,3,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	mergeSortNor(arr, sz);
	printArr(arr, sz);
}


void testcountSort()
{
	int arr[] = { 1,2,5,6,4,8,9,3,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	countSort(arr, sz);
	printArr(arr, sz);
}


void test()
{
	int n;
	printf("��������\n");
	scanf("%d", &n);
	//��������������
	srand(time(NULL));

	//��̬���������������
	int* arr = (int*)malloc(sizeof(int) * n);
	int* copy1 = (int*)malloc(sizeof(int) * n);
	int* copy2 = (int*)malloc(sizeof(int) * n);
	int* copy3 = (int*)malloc(sizeof(int) * n);
	int* copy4 = (int*)malloc(sizeof(int) * n);
	int* copy5 = (int*)malloc(sizeof(int) * n);
	int* copy6 = (int*)malloc(sizeof(int) * n);
	int* copy7 = (int*)malloc(sizeof(int) * n);
	int* copy8 = (int*)malloc(sizeof(int) * n);
	int* copy9 = (int*)malloc(sizeof(int) * n);
	int* copy10 = (int*)malloc(sizeof(int) * n);
	int* copy11 = (int*)malloc(sizeof(int) * n);
	int* copy12 = (int*)malloc(sizeof(int) * n);
	int* copy13 = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}

	//������������鿽������һ����
	memcpy(copy1, arr, sizeof(int) * n);
	memcpy(copy2, arr, sizeof(int) * n);
	memcpy(copy3, arr, sizeof(int) * n);
	memcpy(copy4, arr, sizeof(int) * n);
	memcpy(copy5, arr, sizeof(int) * n);
	memcpy(copy6, arr, sizeof(int) * n);
	memcpy(copy7, arr, sizeof(int) * n);
	memcpy(copy8, arr, sizeof(int) * n);
	memcpy(copy9, arr, sizeof(int) * n);
	memcpy(copy10, arr, sizeof(int) * n);
	memcpy(copy11, arr, sizeof(int) * n);
	memcpy(copy12, arr, sizeof(int) * n);
	memcpy(copy13, arr, sizeof(int) * n);

	time_t begin = clock();
	insertSort(copy1, n);
	time_t end = clock();
	printf("insertSort: %lld\n", end - begin);

	begin = clock();
	shellSort(copy2, n);
	end = clock();
	printf("shellSort: %lld\n", end - begin);

	begin = clock();
	selectSort1(copy3, n);
	end = clock();
	printf("selectSort1: %lld\n", end - begin);

	begin = clock();
	selectSort2(copy4, n);
	end = clock();
	printf("selectSort2: %lld\n", end - begin);

	begin = clock();
	selectSort3(copy5, n);
	end = clock();
	printf("selectSort3: %lld\n", end - begin);

	begin = clock();
	heapSort(copy6, n);
	end = clock();
	printf("heapSort: %lld\n", end - begin);

	begin = clock();
	bubbleSort(copy7, n);
	end = clock();
	printf("bubbleSort: %lld\n", end - begin);

	//����Ŀ���
	begin = clock();
	quickSort1(copy8, 0, n - 1);
	end = clock();
	printf("����quickSort1: %lld\n", end - begin);

	////����Ŀ���
	//begin = clock();
	//quickSort1(copy8, 0, n-1);
	//end = clock();
	//printf("����quickSort1: %lld\n", end - begin);

	begin = clock();
	quickSort2(copy9, 0, n - 1);
	end = clock();
	printf("�Ż�������quickSort2: %lld\n", end - begin);

	begin = clock();
	quickSort2(copy9, 0, n - 1);
	end = clock();
	printf("�Ż�������quickSort2: %lld\n", end - begin);

	begin = clock();
	quickSort3(copy10, 0, n - 1);
	end = clock();
	printf("quickSort3: %lld\n", end - begin);

	begin = clock();
	quickSort4(copy11, 0, n - 1);
	end = clock();
	printf("quickSort4: %lld\n", end - begin);

	begin = clock();
	mergeSort(copy12, 0, n );
	end = clock();
	printf("mergeSort: %lld\n", end - begin);

	begin = clock();
	mergeSortNor(copy13, 0, n );
	end = clock();
	printf("mergeSortNor: %lld\n", end - begin);
}

int main()
{
	//testinsertSort();
	//testshellSort();
	//testselectSort1();
	//testselectSort2();
	//testselectSort3();
	//testheapSort();
	//testbubbleSort();
	//testquickSort1();
	//testquickSort2();
	//testquickSort3();
	//testquickSort4();
	//testmergeSort();
	//testmergeSortNor();
	testcountSort();

	
	//test();
	return 0;
}