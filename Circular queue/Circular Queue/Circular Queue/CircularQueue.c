#define _CRT_SECURE_NO_WARNINGS

//方法一
//设计循环队列
typedef struct {
	//队头元素位置
	int front;
	//队尾元素的下一个位置
	int rear;
	//队列的容量
	int _k;
	//存放元素空间的首地址
	int* data;
} MyCircularQueue;


bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
	//rear+1%数组长度==front
	return (obj->rear + 1) % (obj->_k + 1) == obj->front;
}

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->data = (int*)malloc(sizeof(int) * (k + 1));
	cq->_k = k;
	//0到k都可以，两个相等队列为空
	cq->front = cq->rear = 0;
	return cq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	//队列已满不能入队
	if (myCircularQueueIsFull(obj))
		return false;
	//队尾入队
	obj->data[obj->rear++] = value;
	//判断队尾是否越界[0,k]
	if (obj->rear > obj->_k)
		obj->rear = 0;
	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	//队列为空，出队失败
	if (myCircularQueueIsEmpty(obj))
		return false;
	//队头出队
	obj->front++;
	//判断队头是否越界
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
	//rear为0，返回最后一个数据
	return obj->data[obj->_k];
}


void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->data);
	free(obj);
}


//方法二
//设计循环队列
typedef struct {
	//队头元素位置
	int front;
	//队尾元素的下一个位置
	int rear;
	//队列的容量
	int _k;
	//存放元素空间的首地址
	int* data;
	//队列有效元素的个数
	int size;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->data = (int*)malloc(sizeof(int) * (k));
	cq->_k = k;
	//0到k都可以，两个相等队列为空
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
	//队列已满不能入队
	if (myCircularQueueIsFull(obj))
		return false;
	//队尾入队
	obj->data[obj->rear++] = value;
	//判断队尾是否越界[0,k]
	if (obj->rear >= obj->_k)
		obj->rear = 0;
	obj->size++;
	return true;
}


bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	//队列为空，出队失败
	if (myCircularQueueIsEmpty(obj))
		return false;
	//队头出队
	obj->front++;
	//判断队头是否越界
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
		//rear为0，返回最后一个数据
		return obj->data[obj->_k - 1];
	}
}


void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->data);
	free(obj);
}
