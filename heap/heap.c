#define _CRT_SECURE_NO_WARNINGS

//С������ȡ����ǰ�᣺��������������һ���ѣ����ܵ�����
//1.�����Һ�����ѡ��һ����Сֵ��
//2.��ǰ��Ҫ���������ݺ���Сֵ���бȽϣ�������Сֵ������Сֵ���н�������ȡ����λ�ü���ִ�е�һ����
//С�ڵ�����Сֵ������������
void shiftDown(int* arr, int n, int curpos)
{
	//����
	int child = curpos * 2 + 1;
	//����С��n�ż������бȽ�
	while (child < n)
	{
		//�����Һ������ҵ�һ����Сֵ��λ��,Ҫ��֤�Һ��Ӵ��ڲ��ܱȽ�
		if (child + 1 < n && arr[child+1] < arr[child])
			child++;
		//��Ҫ���������ݺ���Сֵ���бȽ�
		if (arr[child] < arr[curpos])
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

void test()
{
	int arr[] = { 10,5,3,8,7,6 };
	//���±�Ϊ0��λ�ÿ�ʼ����ȡ��
	shiftDown(arr, sizeof(arr) / sizeof(arr[0]), 0);
}





//����
//���ѣ������һ����Ҷ�ӽڵ㿪ʼ����������ȡ���Ĺ��̡�
//����ȡ���Ĵ����ͷ�Ҷ�ӽڵ�ĸ�����ͬ��
//���һ����Ҷ�ӽڵ��λ�ã�����������n-2��/2��n���±��λ�á�

//�ѵ�����ȡ��
void shiftDown(int* arr, int n, int curpos)
{
	//����
	int child = curpos * 2 + 1;
	//����С��n�ż������бȽ�
	while (child < n)
	{
		//�����Һ������ҵ�һ����Сֵ��λ��,Ҫ��֤�Һ��Ӵ��ڲ��ܱȽ�
		if (child + 1 < n && arr[child + 1] < arr[child])
			child++;
		//��Ҫ���������ݺ���Сֵ���бȽ�
		if (arr[child] < arr[curpos])
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


//�ѵĴ���
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


