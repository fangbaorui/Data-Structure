#define _CRT_SECURE_NO_WARNINGS

//小堆向下取整，前提：左右子树必须是一个堆，才能调整。
//1.从左右孩子中选择一个最小值。
//2.当前需要调整的数据和最小值进行比较：大于最小值，和最小值进行交换，从取整的位置继续执行第一步，
//小于等于最小值，结束调整。
void shiftDown(int* arr, int n, int curpos)
{
	//左孩子
	int child = curpos * 2 + 1;
	//孩子小于n才继续进行比较
	while (child < n)
	{
		//从左右孩子中找到一个最小值的位置,要保证右孩子存在才能比较
		if (child + 1 < n && arr[child+1] < arr[child])
			child++;
		//需要调整的数据和最小值进行比较
		if (arr[child] < arr[curpos])
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

void test()
{
	int arr[] = { 10,5,3,8,7,6 };
	//从下标为0的位置开始向下取整
	shiftDown(arr, sizeof(arr) / sizeof(arr[0]), 0);
}





//建堆
//建堆：从最后一个非叶子节点开始，进行向下取整的过程。
//向下取整的次数和非叶子节点的个数相同。
//最后一个非叶子节点的位置（索引）：（n-2）/2，n是下标的位置。

//堆的向下取整
void shiftDown(int* arr, int n, int curpos)
{
	//左孩子
	int child = curpos * 2 + 1;
	//孩子小于n才继续进行比较
	while (child < n)
	{
		//从左右孩子中找到一个最小值的位置,要保证右孩子存在才能比较
		if (child + 1 < n && arr[child + 1] < arr[child])
			child++;
		//需要调整的数据和最小值进行比较
		if (arr[child] < arr[curpos])
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


//堆的创建
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

void test()
{
	int arr[] = { 100, 20, 3, 6, 89, 12, 15, 36, 25 };
	creatHeap(arr, sizeof(arr) / sizeof(arr[0]));
}
int main()
{
	test();
	return 0;
}


