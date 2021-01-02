#define _CRT_SECURE_NO_WARNINGS

////С������ȡ����ǰ�᣺��������������һ���ѣ����ܵ�����
////1.�����Һ�����ѡ��һ����Сֵ��
////2.��ǰ��Ҫ���������ݺ���Сֵ���бȽϣ�������Сֵ������Сֵ���н�������ȡ����λ�ü���ִ�е�һ����
////С�ڵ�����Сֵ������������
//void shiftDown(int* arr, int n, int curpos)
//{
//	//����
//	int child = curpos * 2 + 1;
//	//����С��n�ż������бȽ�
//	while (child < n)
//	{
//		//�����Һ������ҵ�һ����Сֵ��λ��,Ҫ��֤�Һ��Ӵ��ڲ��ܱȽ�
//		if (child + 1 < n && arr[child+1] < arr[child])
//			child++;
//		//��Ҫ���������ݺ���Сֵ���бȽ�
//		if (arr[child] < arr[curpos])
//		{
//			int tmp = arr[child];
//			arr[child] = arr[curpos];
//			arr[curpos] = tmp;
//			//���µ�ǰ��Ҫ������λ�úͺ��ӵ�λ��
//			curpos = child;
//			child = curpos * 2 + 1;
//		}
//		else
//			break;
//	}
//}
//
//void test()
//{
//	int arr[] = { 10,5,3,8,7,6 };
//	//���±�Ϊ0��λ�ÿ�ʼ����ȡ��
//	shiftDown(arr, sizeof(arr) / sizeof(arr[0]), 0);
//}



////С�ѵ����ϵ���:logn
////�ѵ����ϵ���:�͸��ڵ���бȽϣ���Ҫ�����򽻻������µ����ڵ��λ�ü������Ͽ�
////���򣺽���
//void shiftUp(int* arr, int n, int cur)
//{
//	//���ڵ��λ��
//	int parent = (cur - 1) / 2;
//	while (cur > 0)
//	{
//		if (arr[cur] < arr[parent])
//		{
//			//����
//			int tmp = arr[cur];
//			arr[cur] = arr[parent];
//			arr[parent] = tmp;
//
//			//���µ����ڵ��λ�ã��������Ͽ�
//			cur = parent;
//			parent = (cur - 1) / 2;
//		}
//		else
//			break;
//	}
//}
//
//
//
////С�ѵ����µ�����logn
//void shiftDown(int* arr, int n, int curpos)
//{
//	//����
//	int child = curpos * 2 + 1;
//	//����С��n�ż������бȽ�
//	while (child < n)
//	{
//		//�����Һ������ҵ�һ����Сֵ��λ��,Ҫ��֤�Һ��Ӵ��ڲ��ܱȽ�
//		if (child + 1 < n && arr[child + 1] < arr[child])
//			child++;
//		//��Ҫ���������ݺ���Сֵ���бȽ�
//		if (arr[child] < arr[curpos])
//		{
//			int tmp = arr[child];
//			arr[child] = arr[curpos];
//			arr[curpos] = tmp;
//			//���µ�ǰ��Ҫ������λ�úͺ��ӵ�λ��
//			curpos = child;
//			child = curpos * 2 + 1;
//		}
//		else
//			break;
//	}
//}





#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef int HDataType;
typedef struct Heap
{
	HDataType* data;
	int size;
	int capacity;
}heap;


//��ʼ����
void heapInit(heap* hp)
{
	if (hp == NULL)
		return;
	hp->data = NULL;
	hp->size = hp->capacity = 0;
}


//��������
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


//�������
void checkCapacity(heap* hp)
{
	if (hp->size == hp->capacity)
	{
		hp->capacity = hp->capacity == 0 ? 1 : 2 * hp->capacity;
		hp->data = (HDataType*)realloc(hp->data, sizeof(HDataType));
	}
}


//��ѵ����ϵ���:logn
//�ѵ����ϵ���:�͸��ڵ���бȽϣ���Ҫ�����򽻻������µ����ڵ��λ�ü������Ͽ�
//���򣺽���
void shiftUp(int* arr, int n, int cur)
{
	//���ڵ��λ��
	int parent = (cur - 1) / 2;
	while (cur > 0)
	{
		if (arr[cur] > arr[parent])
		{
			//����
			int tmp = arr[cur];
			arr[cur] = arr[parent];
			arr[parent] = tmp;

			//���µ����ڵ��λ�ã��������Ͽ�
			cur = parent;
			parent = (cur - 1) / 2;
		}
		else
			break;
	}
}



//��ѵ����µ�����logn
void shiftDown(int* arr, int n, int curpos)
{
	//����
	int child = curpos * 2 + 1;
	//����С��n�ż������бȽ�
	while (child < n)
	{
		//�����Һ������ҵ�һ�����ֵ��λ��,Ҫ��֤�Һ��Ӵ��ڲ��ܱȽ�
		if (child + 1 < n && arr[child + 1] > arr[child])
			child++;
		//��Ҫ���������ݺ����ֵ���бȽ�
		if (arr[child] > arr[curpos])
		{
			int tmp = arr[child];
			arr[child] = arr[curpos];
			arr[curpos] = tmp;
			//���µ�ǰ��Ҫ������λ�úͺ��ӵ�λ��
			curpos = child;
			child = curpos * 2 + 1;
		}
		else
			break;
	}
}



//�ѵĲ���
void heapPush(heap* hp, HDataType val)
{
	//�������
	checkCapacity(hp);
	//β��
	hp->data[hp->size++] = val;
	//���ϵ���
	shiftUp(hp->data, hp->size, hp->size - 1);
}



//�ѵ�ɾ����ɾ���Ѷ�Ԫ��
void heapPop(heap* hp)
{
	if (hp == NULL || hp->size == 0)
		return;
	//����
	Swap(&hp->data[0], &hp->data[hp->size - 1]);
	//βɾ
	hp->size--;
	//���µ���
	shiftDown(hp->data, hp->size, 0);
}



//�п�
int heapEmpty(heap* hp)
{
	if (hp == NULL || hp->size == 0)
		return 1;
	else
		return 0;
}


//ȡ�Ѷ�Ԫ��
HDataType heapTop(heap* hp)
{
	return hp->data[0];
}



//�ѵĴ�����nlogn
//�ѵĴ����������һ����Ҷ�ӽڵ㿪ʼ����������ȡ���Ĺ��̡�
//����ȡ���Ĵ����ͷ�Ҷ�ӽڵ�ĸ�����ͬ��
//���һ����Ҷ�ӽڵ��λ�ã�����������n-2��/2��n���±��λ�á�
void creatHeap(int* arr, int n)
{
	//�����һ����Ҷ�ӽڵ㿪ʼ���µ���
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		//shiftDown������ָ�룬����Ԫ�ظ�������������ʼλ�ã�
		//i����Ӱ��Ƚϸ������������n
		shiftDown(arr, n, i);
	}
}

//void test()
//{
//	int arr[] = { 100, 20, 3, 6, 89, 12, 15, 36, 25 };
//	creatHeap(arr, sizeof(arr) / sizeof(arr[0]));
//}

//void test()
//{
//	heap hp;
//	heapInit(&hp);
//	heapPush(&hp, 28);
//	heapPush(&hp, 29);
//	heapPush(&hp, 45);
//	heapPush(&hp, 46);
//	heapPush(&hp, 25);
//	heapPush(&hp, 38);
//	heapPush(&hp, 19);
//	heapPush(&hp, 8);
//
//	//heapPop(&hp);
//	//heapPop(&hp);
//	//heapPop(&hp);
//	//heapPop(&hp);
//	//heapPop(&hp);
//	//heapPop(&hp);
//	//heapPop(&hp);
//	//heapPop(&hp);
//	while (!heapEmpty(&hp))
//	{
//		printf("%d ", heapTop(&hp));
//			heapPop(&hp);
//	}
//	printf("\n");
//}


void PrintTopk(int* a, int n, int k)
{
	heap hp;
	heapInit(&hp);
	for (int i = 0; i < n; i++)
	{
		heapPush(&hp, a[i]);
	}
	while (k--)
	{
		printf("%d ", heapTop(&hp));
		heapPop(&hp);
	}
}
void test()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (size_t i = 0; i < n; i++)
	{
		a[i] = rand() % 1000000;
	}
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 13;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	PrintTop(a, n, 10);
}
int main()
{
	test();
	return 0;
}


