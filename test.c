#define _CRT_SECURE_NO_WARNINGS
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。

//方法一
#include<stdio.h>
#include<stdlib.h>
typedef int SDataType;
//顺序表实现栈
typedef struct stack
{
    SDataType* data;
    size_t size;
    size_t capacity;
}stack;

//初始化栈
void stackInit(stack* st);

//入栈
void stackPush(stack* st, SDataType val);

//出栈
void stackPop(stack* st);

//栈的大小
int stackSize(stack* st);

//判空
int stackEmpty(stack* st);

//检查容量：增容
void checkCapacity(stack* st);

//初始化栈
void stackInit(stack* st)
{
    //空栈
    if (st == NULL)
        return;
    st->data = NULL;
    st->size = st->capacity = 0;
}

//检查容量：增容
void checkCapacity(stack* st)
{
    if (st->size == st->capacity)
    {
        int newCap = st->capacity == 0 ? 1 : 2 * st->capacity;
        st->data = (SDataType*)realloc(st->data, sizeof(SDataType) * newCap);
        st->capacity = newCap;
    }
}

//入栈：尾插
void stackPush(stack* st, SDataType val)
{
    if (st == NULL)
        return;
    checkCapacity(st);
    st->data[st->size++] = val;
}

//出栈：尾删
void stackPop(stack* st)
{
    if (st == NULL || st->size == 0)
        return;
    st->size--;
}

//获取栈顶元素
int stackTop(stack* st)
{
    return st->data[st->size - 1];
}

//判空:为空返回1，不为空返回0
int stackEmpty(stack* st)
{
    if (st == NULL || st->size == 0)
        return 1;
    return 0;
}

//栈的大小
int stackSize(stack* st)
{
    if (st == NULL || st->size == 0)
        return 0;
    return st->size;
}
bool isValid(char* s) {
    //括号映射
    char map[3][2] = { {'(',')'},{'{','}'},{'[',']'} };
    struct stack st;
    stackInit(&st);
    while (*s)
    {
        //标记flag看看是否是左括号
        int flag = 0;
        //左括号：入栈
        for (int i = 0; i < 3; i++)
        {
            if (*s == map[i][0])
            {
                stackPush(&st, *s);
                //判断下一个字符
                ++s;
                flag = 1;
                break;
            }
        }
        //右括号
        if (flag == 0)
        {
            //如果栈为空的话，没有适合的左括号匹配右括号，返回false
            if (stackEmpty(&st))
                return false;
            //取出栈顶元素：左括号
            char topChar = stackTop(&st);
            stackPop(&st);
            //找到当前字符*s对应的左括号
            for (int i = 0; i < 3; i++)
            {
                if (map[i][1] == *s)
                {
                    if (topChar == map[i][0])
                    {
                        ++s;
                        break;
                    }
                    else
                        return false;
                }
            }
        }
    }
    return stackEmpty(&st);
}



//方法二

#include<stdio.h>
#include<stdlib.h>
typedef int SDataType;
//顺序表实现栈
typedef struct stack
{
    SDataType* data;
    size_t size;
    size_t capacity;
}stack;

//初始化栈
void stackInit(stack* st);

//入栈
void stackPush(stack* st, SDataType val);

//出栈
void stackPop(stack* st);

//栈的大小
int stackSize(stack* st);

//判空
int stackEmpty(stack* st);

//检查容量：增容
void checkCapacity(stack* st);

//初始化栈
void stackInit(stack* st)
{
    //空栈
    if (st == NULL)
        return;
    st->data = NULL;
    st->size = st->capacity = 0;
}

//检查容量：增容
void checkCapacity(stack* st)
{
    if (st->size == st->capacity)
    {
        int newCap = st->capacity == 0 ? 1 : 2 * st->capacity;
        st->data = (SDataType*)realloc(st->data, sizeof(SDataType) * newCap);
        st->capacity = newCap;
    }
}

//入栈：尾插
void stackPush(stack* st, SDataType val)
{
    if (st == NULL)
        return;
    checkCapacity(st);
    st->data[st->size++] = val;
}

//出栈：尾删
void stackPop(stack* st)
{
    if (st == NULL || st->size == 0)
        return;
    st->size--;
}

//获取栈顶元素
int stackTop(stack* st)
{
    return st->data[st->size - 1];
}

//判空:为空返回1，不为空返回0
int stackEmpty(stack* st)
{
    if (st == NULL || st->size == 0)
        return 1;
    return 0;
}

//栈的大小
int stackSize(stack* st)
{
    if (st == NULL || st->size == 0)
        return 0;
    return st->size;
}

bool isValid(char* s) {
    //括号映射
    char arr[128] = { 0 };
    arr[')'] = '(';
    arr['}'] = '{';
    arr[']'] = '[';
    struct stack st;
    stackInit(&st);
    while (*s)
    {
        //标记flag看看是否是左括号
        int flag = 0;
        //左括号：入栈
        if (*s == '(' || *s == '[' || *s == '{')
        {
            stackPush(&st, *s);
            ++s;
            flag = 1;
        }
        //右括号
        if (flag == 0)
        {
            //如果栈为空的话，没有适合的左括号匹配右括号，返回false
            if (stackEmpty(&st))
                return false;
            //取出栈顶元素：左括号
            char topChar = stackTop(&st);
            stackPop(&st);
            //找到当前字符*s对应的左括号
            if (arr[*s] == topChar)
                ++s;
            else
                return false;
        }
    }
    return stackEmpty(&st);
}



//2.用队列实现栈
//使用队列实现栈的下列操作：
//push(x) --元素 x 入栈
//pop() --移除栈顶元素
//top() --获取栈顶元素
//empty() --返回栈是否为空
//你只能使用队列的基本操作-- 也就是 push to back, peek / pop from front, size, 和 is empty 这些操作是合法的。
//你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列, 只要是标准的队列操作即可。
//你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。
//带尾结点的单链表实现队列


//方法一
//前n-1个元素先出队，再入队，最后一个元素直接出队
typedef int QDataType;

//结点
typedef struct QNode
{
    struct QNode* next;
    QDataType data;
}QNode;

//队列
typedef struct Queue
{
    QNode* front;
    QNode* rear;
    int size;
}Queue;

//初始化队列
void queueInit(Queue* q);

//入队:尾插
void queuePush(Queue* q, QDataType data);

//出队：头删
void queuePop(Queue* q);

//长度
int queueSize(Queue* q);

//判空
int queueEmpty(Queue* q);

//销毁
void queueDestory(Queue* q);

//获取对头元素
QDataType queueFront(Queue* q);

//获取队尾元素
QDataType queueBack(Queue* q);

//初始化队列
void queueInit(Queue* q)
{
    q->front = q->rear = NULL;
    q->size = 0;
}

//创建结点
QNode* creatNode(QDataType data)
{
    QNode* node = (QNode*)malloc(sizeof(QNode));
    node->data = data;
    node->next = NULL;
    return node;
}

//入队:尾插
void queuePush(Queue* q, QDataType data)
{
    QNode* node = creatNode(data);
    //空队列：入队一个结点，首尾都指向这个结点
    if (q->front == NULL)
        q->front = q->rear = node;
    else
    {
        q->rear->next = node;
        q->rear = node;
    }
    q->size++;
}

//出队：头删
void queuePop(Queue* q)
{
    //为空侧不能删
    if (q->front)
    {
        QNode* next = q->front->next;
        free(q->front);
        q->front = next;
        //删除之后如果为空表，要改变尾指针
        if (q->front == NULL)
            q->rear = NULL;
        q->size--;
    }
}

//长度
int queueSize(Queue* q)
{
    int num = 0;
    QNode* cur = q->front;
    while (cur)
    {
        ++num;
        cur = cur->next;
    }
    return num;
    //return q->size;
}

//判空
int queueEmpty(Queue* q)
{
    if (q->front == NULL)
        return 1;
    return 0;
}

//销毁
void queueDestory(Queue* q)
{
    QNode* cur = q->front;
    while (cur)
    {
        QNode* next = cur->next;
        free(cur);
        //摧毁直接释放，无需连接
        cur = next;
    }
    q->front = q->rear = NULL;
    q->size = 0;
}

//获取对头元素
QDataType queueFront(Queue* q)
{
    return q->front->data;
}

//获取队尾元素
QDataType queueBack(Queue* q)
{
    return q->rear->data;
}


typedef struct {
    //队列成员
    struct Queue q;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    //动态创建
    MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
    queueInit(&pst->q);
    return pst;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    queuePush(&obj->q, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int n = queueSize(&obj->q);
    while (n > 1)
    {
        //出队，入队
        //把出队元素记录下来出队，再入队
        int front = queueFront(&obj->q);
        queuePop(&obj->q);
        queuePush(&obj->q, front);
        --n;
    }
    //记录要出队的元素
    int top = queueFront(&obj->q);
    queuePop(&obj->q);
    return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return queueBack(&obj->q);

}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return queueEmpty(&obj->q);

}

void myStackFree(MyStack* obj) {
    queueDestory(&obj->q);
    free(obj);

}




//方法二
//给两个队列，出栈：非空队列前n-1个元素出队到空队列，第n个元素处队
//入栈：给非空队列入队
//带尾结点的单链表实现队列
typedef int QDataType;

//结点
typedef struct QNode
{
    struct QNode* next;
    QDataType data;
}QNode;

//队列
typedef struct Queue
{
    QNode* front;
    QNode* rear;
    int size;
}Queue;

//初始化队列
void queueInit(Queue* q);

//入队:尾插
void queuePush(Queue* q, QDataType data);

//出队：头删
void queuePop(Queue* q);

//长度
int queueSize(Queue* q);

//判空
int queueEmpty(Queue* q);

//销毁
void queueDestory(Queue* q);

//获取对头元素
QDataType queueFront(Queue* q);

//获取队尾元素
QDataType queueBack(Queue* q);

//初始化队列
void queueInit(Queue* q)
{
    q->front = q->rear = NULL;
    q->size = 0;
}

//创建结点
QNode* creatNode(QDataType data)
{
    QNode* node = (QNode*)malloc(sizeof(QNode));
    node->data = data;
    node->next = NULL;
    return node;
}

//入队:尾插
void queuePush(Queue* q, QDataType data)
{
    QNode* node = creatNode(data);
    //空队列：入队一个结点，首尾都指向这个结点
    if (q->front == NULL)
        q->front = q->rear = node;
    else
    {
        q->rear->next = node;
        q->rear = node;
    }
    q->size++;
}

//出队：头删
void queuePop(Queue* q)
{
    //为空侧不能删
    if (q->front)
    {
        QNode* next = q->front->next;
        free(q->front);
        q->front = next;
        //删除之后如果为空表，要改变尾指针
        if (q->front == NULL)
            q->rear = NULL;
        q->size--;
    }
}

//长度
int queueSize(Queue* q)
{
    int num = 0;
    QNode* cur = q->front;
    while (cur)
    {
        ++num;
        cur = cur->next;
    }
    return num;
    //return q->size;
}

//判空
int queueEmpty(Queue* q)
{
    if (q->front == NULL)
        return 1;
    return 0;
}

//销毁
void queueDestory(Queue* q)
{
    QNode* cur = q->front;
    while (cur)
    {
        QNode* next = cur->next;
        free(cur);
        //摧毁直接释放，无需连接
        cur = next;
    }
    q->front = q->rear = NULL;
    q->size = 0;
}

//获取对头元素
QDataType queueFront(Queue* q)
{
    return q->front->data;
}

//获取队尾元素
QDataType queueBack(Queue* q)
{
    return q->rear->data;
}



typedef struct {
    //队列成员
    struct Queue q1;
    struct Queue q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    //动态创建
    MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
    queueInit(&pst->q1);
    queueInit(&pst->q2);
    return pst;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    //非空队列入栈
    if (!queueEmpty(&obj->q1))
        queuePush(&obj->q1, x);
    else
        queuePush(&obj->q2, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int top;
    if (!queueEmpty(&obj->q1))
    {
        int n = queueSize(&obj->q1);
        while (n > 1)
        {
            //出队，入队
            //把出队元素记录下来出队，再入队
            int front = queueFront(&obj->q1);
            queuePop(&obj->q1);
            queuePush(&obj->q2, front);
            --n;
        }
        //记录要出队的元素
        top = queueFront(&obj->q1);
        queuePop(&obj->q1);
    }
    else
    {
        int n = queueSize(&obj->q2);
        while (n > 1)
        {
            //出队，入队
            //把出队元素记录下来出队，再入队
            int front = queueFront(&obj->q2);
            queuePop(&obj->q2);
            queuePush(&obj->q1, front);
            --n;
        }
        //记录要出队的元素
        top = queueFront(&obj->q2);
        queuePop(&obj->q2);
    }
    return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if (!queueEmpty(&obj->q1))
        return queueBack(&obj->q1);
    else
        return queueBack(&obj->q2);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return queueEmpty(&obj->q1) && queueEmpty(&obj->q2);

}

void myStackFree(MyStack* obj) {
    queueDestory(&obj->q1);
    queueDestory(&obj->q2);
    free(obj);
}





//3. 用栈实现队列
//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列的支持的所有操作（push、pop、peek、empty）：
//void push(int x) 将元素 x 推到队列的末尾
//int pop() 从队列的开头移除并返回元素
//int peek() 返回队列开头的元素
//boolean empty() 如果队列为空，返回 true ；否则，返回 false


//两个栈，一个出队栈，一个入队栈  ， 出队：出栈队有元素直接出，如果无元素：从入队栈出栈到出队栈
//入队：元素依次进入入队栈
typedef int SDataType;
//顺序表实现栈
typedef struct stack
{
    SDataType* data;
    size_t size;
    size_t capacity;
}stack;

//初始化栈
void stackInit(stack* st);

//入栈
void stackPush(stack* st, SDataType val);

//出栈
void stackPop(stack* st);

//判空
int stackEmpty(stack* st);

//检查容量：增容
void checkCapacity(stack* st);

//初始化栈
void stackInit(stack* st)
{
    //空栈
    if (st == NULL)
        return;
    st->data = NULL;
    st->size = st->capacity = 0;
}

//检查容量：增容
void checkCapacity(stack* st)
{
    if (st->size == st->capacity)
    {
        int newCap = st->capacity == 0 ? 1 : 2 * st->capacity;
        st->data = (SDataType*)realloc(st->data, sizeof(SDataType) * newCap);
        st->capacity = newCap;
    }
}

//入栈：尾插
void stackPush(stack* st, SDataType val)
{
    if (st == NULL)
        return;
    checkCapacity(st);
    st->data[st->size++] = val;
}

//出栈：尾删
void stackPop(stack* st)
{
    if (st == NULL || st->size == 0)
        return;
    st->size--;
}

//获取栈顶元素
int stackTop(stack* st)
{
    if (st == NULL || st->size == 0)
        return 0;
    return st->data[(st->size) - 1];
}

//判空:为空返回1，不为空返回0
int stackEmpty(stack* st)
{
    if (st == NULL || st->size == 0)
        return 1;
    return 0;
}

//栈的大小
int stackSize(stack* st)
{
    if (st == NULL || st->size == 0)
        return 0;
    return st->size;
}

//栈的摧毁
void stackDestory(stack* st)
{
    if (st)
    {
        if (st->data)
        {
            free(st->data);
            st->data = NULL;
            st->size = st->capacity = 0;
        }
    }
}

typedef struct {
    //队列成员
    stack pushST;
    stack popST;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* pq = (MyQueue*)malloc(sizeof(MyQueue));
    stackInit(&pq->pushST);
    stackInit(&pq->popST);
    return pq;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    //入队栈push
    stackPush(&obj->pushST, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    int front;
    //判断出队栈是否为空
    if (!stackEmpty(&obj->popST))
    {
        front = stackTop(&obj->popST);
        stackPop(&obj->popST);
    }
    else
    {
        //把入队栈的元素存入出队栈
        while (!stackEmpty(&obj->pushST))
        {
            stackPush(&obj->popST, stackTop(&obj->pushST));
            stackPop(&obj->pushST);
        }
        front = stackTop(&obj->popST);
        stackPop(&obj->popST);
    }
    return front;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    //判断出队栈是否为空
    if (stackEmpty(&obj->popST))
    {
        //把入队栈的元素存入出队栈
        while (!stackEmpty(&obj->pushST))
        {
            stackPush(&obj->popST, stackTop(&obj->pushST));
            stackPop(&obj->pushST);
        }
    }
    return stackTop(&obj->popST);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return stackEmpty(&obj->pushST) && stackEmpty(&obj->popST);
}

void myQueueFree(MyQueue* obj) {
    stackDestory(&obj->pushST);
    stackDestory(&obj->popST);
    free(obj);
}
