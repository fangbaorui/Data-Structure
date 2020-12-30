#define _CRT_SECURE_NO_WARNINGS

//����һ
//���ѭ������
typedef struct {
	//��ͷԪ��λ��
	int front;
	//��βԪ�ص���һ��λ��
	int rear;
	//���е�����
	int _k;
	//���Ԫ�ؿռ���׵�ַ
	int* data;
} MyCircularQueue;


bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
	//rear+1%���鳤��==front
	return (obj->rear + 1) % (obj->_k + 1) == obj->front;
}

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->data = (int*)malloc(sizeof(int) * (k + 1));
	cq->_k = k;
	//0��k�����ԣ�������ȶ���Ϊ��
	cq->front = cq->rear = 0;
	return cq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	//���������������
	if (myCircularQueueIsFull(obj))
		return false;
	//��β���
	obj->data[obj->rear++] = value;
	//�ж϶�β�Ƿ�Խ��[0,k]
	if (obj->rear > obj->_k)
		obj->rear = 0;
	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	//����Ϊ�գ�����ʧ��
	if (myCircularQueueIsEmpty(obj))
		return false;
	//��ͷ����
	obj->front++;
	//�ж϶�ͷ�Ƿ�Խ��
	if (obj->front > obj->_k)
		obj->front = 0;
	return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->data[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;
	if (obj->rear != 0)
		return obj->data[obj->rear-1];
	//rearΪ0���������һ������
	return obj->data[obj->_k];
}


void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->data);
	free(obj);
}


//������
//���ѭ������
typedef struct {
	//��ͷԪ��λ��
	int front;
	//��βԪ�ص���һ��λ��
	int rear;
	//���е�����
	int _k;
	//���Ԫ�ؿռ���׵�ַ
	int* data;
	//������ЧԪ�صĸ���
	int size;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->data = (int*)malloc(sizeof(int) * (k));
	cq->_k = k;
	//0��k�����ԣ�������ȶ���Ϊ��
	cq->front = cq->rear = 0;
	cq->size = 0;
	return cq;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return obj->size == obj->_k;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	//���������������
	if (myCircularQueueIsFull(obj))
		return false;
	//��β���
	obj->data[obj->rear++] = value;
	//�ж϶�β�Ƿ�Խ��[0,k]
	if (obj->rear >= obj->_k)
		obj->rear = 0;
	obj->size++;
	return true;
}


bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	//����Ϊ�գ�����ʧ��
	if (myCircularQueueIsEmpty(obj))
		return false;
	//��ͷ����
	obj->front++;
	//�ж϶�ͷ�Ƿ�Խ��
	if (obj->front >= obj->_k)
		obj->front = 0;
	obj->size--;
	return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->data[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;
	if (obj->rear != 0)
		return obj->data[obj->rear - 1];
	else
	{
		//rearΪ0���������һ������
		return obj->data[obj->_k - 1];
	}
}


void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->data);
	free(obj);
}
