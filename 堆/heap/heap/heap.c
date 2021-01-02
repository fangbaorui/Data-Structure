#define _CRT_SECURE_NO_WARNINGS

////小堆向下取整，前提：左右子树必须是一个堆，才能调整。
////1.从左右孩子中选择一个最小值。
////2.当前需要调整的数据和最小值进行比较：大于最小值，和最小值进行交换，从取整的位置继续执行第一步，
////小于等于最小值，结束调整。
//void shiftDown(int* arr, int n, int curpos)
//{
//	//左孩子
//	int child = curpos * 2 + 1;
//	//孩子小于n才继续进行比较
//	while (child < n)
//	{
//		//从左右孩子中找到一个最小值的位置,要保证右孩子存在才能比较
//		if (child + 1 < n && arr[child+1] < arr[child])
//			child++;
//		//需要调整的数据和最小值进行比较
//		if (arr[child] < arr[curpos])
//		{
//			int tmp = arr[child];
//			arr[child] = arr[curpos];
//			arr[curpos] = tmp;
//			//更新当前需要调整的位置和孩子的位置
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
//	//从下标为0的位置开始向下取整
//	shiftDown(arr, sizeof(arr) / sizeof(arr[0]), 0);
//}



////小堆的向上调整:logn
////堆的向上调整:和父节点进行比较，需要交换则交换，更新到父节点的位置继续向上看
////否则：结束
//void shiftUp(int* arr, int n, int cur)
//{
//	//父节点的位置
//	int parent = (cur - 1) / 2;
//	while (cur > 0)
//	{
//		if (arr[cur] < arr[parent])
//		{
//			//交换
//			int tmp = arr[cur];
//			arr[cur] = arr[parent];
//			arr[parent] = tmp;
//
//			//更新到父节点的位置，继续向上看
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
////小堆的向下调整：logn
//void shiftDown(int* arr, int n, int curpos)
//{
//	//左孩子
//	int child = curpos * 2 + 1;
//	//孩子小于n才继续进行比较
//	while (child < n)
//	{
//		//从左右孩子中找到一个最小值的位置,要保证右孩子存在才能比较
//		if (child + 1 < n && arr[child + 1] < arr[child])
//			child++;
//		//需要调整的数据和最小值进行比较
//		if (arr[child] < arr[curpos])
//		{
//			int tmp = arr[child];
//			arr[child] = arr[curpos];
//			arr[curpos] = tmp;
//			//更新当前需要调整的位置和孩子的位置
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


//初始化堆
void heapInit(heap* hp)
{
	if (hp == NULL)
		return;
	hp->data = NULL;
	hp->size = hp->capacity = 0;
}


//交换函数
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


//检查容量
void checkCapacity(heap* hp)
{
	if (hp->size == hp->capacity)
	{
		hp->capacity = hp->capacity == 0 ? 1 : 2 * hp->capacity;
		hp->data = (HDataType*)realloc(hp->data, sizeof(HDataType));
	}
}


//大堆的向上调整:logn
//堆的向上调整:和父节点进行比较，需要交换则交换，更新到父节点的位置继续向上看
//否则：结束
void shiftUp(int* arr, int n, int cur)
{
	//父节点的位置
	int parent = (cur - 1) / 2;
	while (cur > 0)
	{
		if (arr[cur] > arr[parent])
		{
			//交换
			int tmp = arr[cur];
			arr[cur] = arr[parent];
			arr[parent] = tmp;

			//更新到父节点的位置，继续向上看
			cur = parent;
			parent = (cur - 1) / 2;
		}
		else
			break;
	}
}



//大堆的向下调整：logn
void shiftDown(int* arr, int n, int curpos)
{
	//左孩子
	int child = curpos * 2 + 1;
	//孩子小于n才继续进行比较
	while (child < n)
	{
		//从左右孩子中找到一个最大值的位置,要保证右孩子存在才能比较
		if (child + 1 < n && arr[child + 1] > arr[child])
			child++;
		//需要调整的数据和最大值进行比较
		if (arr[child] > arr[curpos])
		{
			int tmp = arr[child];
			arr[child] = arr[curpos];
			arr[curpos] = tmp;
			//更新当前需要调整的位置和孩子的位置
			curpos = child;
			child = curpos * 2 + 1;
		}
		else
			break;
	}
}



//堆的插入
void heapPush(heap* hp, HDataType val)
{
	//检查容量
	checkCapacity(hp);
	//尾插
	hp->data[hp->size++] = val;
	//向上调整
	shiftUp(hp->data, hp->size, hp->size - 1);
}



//堆的删除：删除堆顶元素
void heapPop(heap* hp)
{
	if (hp == NULL || hp->size == 0)
		return;
	//交换
	Swap(&hp->data[0], &hp->data[hp->size - 1]);
	//尾删
	hp->size--;
	//向下调整
	shiftDown(hp->data, hp->size, 0);
}



//判空
int heapEmpty(heap* hp)
{
	if (hp == NULL || hp->size == 0)
		return 1;
	else
		return 0;
}


//取堆顶元素
HDataType heapTop(heap* hp)
{
	return hp->data[0];
}



//堆的创建：nlogn
//堆的创建：从最后一个非叶子节点开始，进行向下取整的过程。
//向下取整的次数和非叶子节点的个数相同。
//最后一个非叶子节点的位置（索引）：（n-2）/2，n是下标的位置。
void creatHeap(int* arr, int n)
{
	//从最后一个非叶子节点开始向下调整
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		//shiftDown（数组指针，数组元素个数，调整的起始位置）
		//i会间接影响比较个数，无需调整n
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


