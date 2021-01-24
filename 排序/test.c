#define _CRT_SECURE_NO_WARNINGS
//��ֵ������
//���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ��������
bool _isUnivalTree(struct TreeNode* root, int val)
{
	if (root)
	{
		//������ǰֵ������������������
		return root->val == val && _isUnivalTree(root->left, val)
		&& _isUnivalTree(root->right, val);
	}

	//���Ϊ����������
	return true;
}
bool isUnivalTree(struct TreeNode* root) {
	if (root == NULL) 
		return true;
	return _isUnivalTree(root, root->val);  //roo->val�����Ǹ���ֵ���Ƕ�ֵ
}




//����һ�����������ҳ��������ȡ�
//�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
int maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	//���������߶ȵ����ֵ��1
	int left = maxDepth(root->left);
	int right = maxDepth(root->right);
	return left > right ? left + 1 : right + 1;
}

int maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	//���������߶ȵ����ֵ��1
	int left = maxDepth(root->left) + 1;
	int right = maxDepth(root->right) + 1;
	return left > right ? left : right;
}



// ��ת������
struct TreeNode* invertTree(struct TreeNode* root) {
	//�������ؿ�
	if (root == NULL)
		return NULL;
	//������������
	struct TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	invertTree(root->left);
	invertTree(root->right);
	return root;
}



//������������������дһ�����������������Ƿ���ͬ��
//����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�

//������ͬ�ı���˳�򣺱�֤��������ÿ���ڵ��λ�ö�����ͬ��
//���ͬʱ����սڵ㣺��ͬ�����û��ͬʱ����սڵ���ͬ��
//û�е���սڵ㣺�Ƚ�ֵ������������������������
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	//ͬʱΪ�գ�������
	if (p == NULL && q == NULL)
		return true;
	//��ͬʱΪ�գ����ؼ�
	if (p == NULL || q == NULL)
		return false;
	//�Ƚϲ�Ϊ�յ�ֵ���ڱ�����������������
	return p->val == q->val &&
		isSameTree(p->left, q->left) &&
		isSameTree(p->right, q->right);
}



//��һ����������
//���������ǿն����� s �� t������ s ���Ƿ������ t ������ͬ�ṹ�ͽڵ�ֵ��������
//s ��һ���������� s ��һ���ڵ������ڵ���������s Ҳ���Կ����������һ��������
//�ж��������Ƿ���ͬ
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	//ͬʱΪ�գ�������
	if (p == NULL && q == NULL)
		return true;
	//��ͬʱΪ�գ����ؼ�
	if (p == NULL || q == NULL)
		return false;
	//�Ƚϲ�Ϊ�յ�ֵ���ڱ�����������������
	return p->val == q->val &&
		isSameTree(p->left, q->left) &&
		isSameTree(p->right, q->right);
}

//��ǰ�ڵ�ȥ�Ƚϣ�������ȥ�Ƚϣ�������ȥ�Ƚ�
bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
	//tΪ������������������
	if (t == NULL)
		return true;
	if (s == NULL)
		return false;
	return isSameTree(s, t) ||
		isSubtree(s->left, t) || isSubtree(s->right, t);
}



//����һ����������������Ƿ��Ǿ���ԳƵġ�
//left->left==right->right,left->right==right->left
bool _isSym(struct TreeNode* left, struct TreeNode* right)
{
	//ͬʱΪ�գ�������
	if (left == NULL && right == NULL)
		return true;
	//��ͬʱ�ﵽ�շ��ؼ�
	if (left == NULL || right == NULL)
		return false;
	//�Ƚ�ֵ����ߵ�������ұߵ��ұߡ���ߵ��ұߺ��ұߵ����
	return left->val == right->val &&
		_isSym(left->left, right->right) && _isSym(left->right, right->left);
}
bool isSymmetric(struct TreeNode* root) {
	if (root == NULL)
		return true;
	return _isSym(root->left, root->right);
}




//����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������
//�����У�һ�ø߶�ƽ�����������Ϊ��
//һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ��
//������ĸ߶�
int getHeight(struct TreeNode* root)
{
	//���������
	if (root)
	{
		int left = getHeight(root->left);
		int right = getHeight(root->right);
		return left > right ? left + 1 : right + 1;
	}
	else
		return 0;
}
bool isBalanced(struct TreeNode* root) {
	if (root == NULL)
		return true;
	//����ڵ��������ĸ߶�
	int left = getHeight(root->left);
	//����ڵ��������ĸ߶�
	int right = getHeight(root->right);
	return abs(left - right) < 2 &&
		isBalanced(root->left) &&
		isBalanced(root->right);
}



//��������ǰ�����
//����������ĸ��ڵ� root ���������ڵ�ֵ�� ǰ�� ������
//��������ڵ����
int getSize(struct TreeNode* root)
{
	if (root)
		return getSize(root->left) + getSize(root->right) + 1;
	return 0;
}

//ǰ��������ݹ�
void preorder(struct TreeNode* root, int* arr, int* idx)
{
	if (root)
	{
		arr[(*idx)++] = root->val;
		preorder(root->left, arr, idx);
		preorder(root->right, arr, idx);
	}
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	int sz = getSize(root);
	int* arr = (int*)malloc(sizeof(int) * sz);
	int idx = 0;
	preorder(root, arr, &idx);
	*returnSize = idx;
	return arr;
}

//�ǵݹ�
//ǰ�����������ÿһ���ڵ㣬���ȷ��ʵ����Դ˽ڵ㿪ʼ������·��
//          ����ÿһ���������ȷ��ʵ������������ڷ�����·�����������������
//��ߵĽڵ���ʣ����϶��£��ұߵĽڵ���ʣ����¶���

//1.����ÿһ���ڵ㿪ʼ������·�������ʵ���ÿһ���ڵ���ջ
//2.����·���������֮�󣬻�ȡջ��Ԫ�أ�����������ջ��Ԫ�ص�������Ϊ�����ӽṹ������ִ�е�1��
//3.������ջΪ��&&������Ϊ��

//�ǵݹ�
typedef struct TreeNode* SDataType;
//˳���ʵ��ջ
typedef struct stack
{
	SDataType* data;
	size_t size;
	size_t capacity;
}stack;
//��ʼ��ջ
void stackInit(stack* st);
//��ջ
void stackPush(stack* st, SDataType val);
//��ջ
void stackPop(stack* st);
//�п�
int stackEmpty(stack* st);
//�������������
void checkCapacity(stack* st);
//��ʼ��ջ
void stackInit(stack* st)
{
	//��ջ
	if (st == NULL)
		return;
	st->data = NULL;
	st->size = st->capacity = 0;
}
//�������������
void checkCapacity(stack* st)
{
	if (st->size == st->capacity)
	{
		int newCap = st->capacity == 0 ? 1 : 2 * st->capacity;
		st->data = (SDataType*)realloc(st->data, sizeof(SDataType) * newCap);
		st->capacity = newCap;
	}
}
//��ջ��β��
void stackPush(stack* st, SDataType val)
{
	if (st == NULL)
		return;
	checkCapacity(st);
	st->data[st->size++] = val;
}
//��ջ��βɾ
void stackPop(stack* st)
{
	if (st == NULL || st->size == 0)
		return;
	st->size--;
}
//��ȡջ��Ԫ��
SDataType stackTop(stack* st)
{
	return st->data[st->size - 1];
}
//�п�:Ϊ�շ���1����Ϊ�շ���0
int stackEmpty(stack* st)
{
	if (st == NULL || st->size == 0)
		return 1;
	return 0;
}

//��������ڵ����
int getSize(struct TreeNode* root)
{
	if (root)
		return getSize(root->left) + getSize(root->right) + 1;
	return 0;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	int sz = getSize(root);
	int* arr = malloc(sizeof(int) * sz);
	stack st;
	stackInit(&st);
	int idx = 0;
	//��ǰ�����Ľڵ㲻Ϊ�գ���ջ��Ϊ��
	while (root || !stackEmpty(&st))
	{
		//1.��������·��
		while (root)
		{
			arr[idx++] = root->val;
			//��ǰ�ڵ���ջ
			stackPush(&st, root);
			root = root->left;
		}
		//2.��ȡջ��Ԫ��
		root = stackTop(&st);
		stackPop(&st);
		root = root->right;
	}
	*returnSize = idx;
	return arr;
}




//94. ���������������
//����һ���������ĸ��ڵ� root ���������� ���� ������
//��������ڵ����
int getSize(struct TreeNode* root)
{
	if (root)
		return getSize(root->left) + getSize(root->right) + 1;
	return 0;
}
//�������
void inorder(struct TreeNode* root, int* arr, int* idx)
{
	if (root)
	{
		inorder(root->left, arr, idx);
		arr[(*idx)++] = root->val;
		inorder(root->right, arr, idx);
	}
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	int sz = getSize(root);
	int* arr = (int*)malloc(sizeof(int) * sz);
	int idx = 0;
	inorder(root, arr, &idx);
	*returnSize = idx;
	return arr;
}



//�ǵݹ顪���������
//1.�Խڵ㿪ʼ��������·������·����������ÿһ���ڵ�������ջ�����ǲ��ܷ���
//2.��ȡջ��Ԫ�أ�����ջ��Ԫ��
//3.��ȡջ��Ԫ�ص�������������ִ�е�1��
//4.������ջΪ��&&������Ϊ��

//�ǵݹ�
typedef struct TreeNode* SDataType;
//˳���ʵ��ջ
typedef struct stack
{
	SDataType* data;
	size_t size;
	size_t capacity;
}stack;

//��ʼ��ջ
void stackInit(stack* st);

//��ջ
void stackPush(stack* st, SDataType val);

//��ջ
void stackPop(stack* st);


//�п�
int stackEmpty(stack* st);

//�������������
void checkCapacity(stack* st);


//��ʼ��ջ
void stackInit(stack* st)
{
	//��ջ
	if (st == NULL)
		return;
	st->data = NULL;
	st->size = st->capacity = 0;
}

//�������������
void checkCapacity(stack* st)
{
	if (st->size == st->capacity)
	{
		int newCap = st->capacity == 0 ? 1 : 2 * st->capacity;
		st->data = (SDataType*)realloc(st->data, sizeof(SDataType) * newCap);
		st->capacity = newCap;
	}
}

//��ջ��β��
void stackPush(stack* st, SDataType val)
{
	if (st == NULL)
		return;
	checkCapacity(st);
	st->data[st->size++] = val;
}

//��ջ��βɾ
void stackPop(stack* st)
{
	if (st == NULL || st->size == 0)
		return;
	st->size--;
}

//��ȡջ��Ԫ��
SDataType stackTop(stack* st)
{
	return st->data[st->size - 1];
}

//�п�:Ϊ�շ���1����Ϊ�շ���0
int stackEmpty(stack* st)
{
	if (st == NULL || st->size == 0)
		return 1;
	return 0;
}

//��������ڵ����
int getSize(struct TreeNode* root)
{
	if (root)
		return getSize(root->left) + getSize(root->right) + 1;
	return 0;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
	int sz = getSize(root);
	int* arr = malloc(sizeof(int) * sz);
	stack st;
	stackInit(&st);
	int idx = 0;
	//��ǰ�����Ľڵ㲻Ϊ�գ���ջ��Ϊ��
	while (root || !stackEmpty(&st))
	{
		//1.��������·��
		while (root)
		{
			//��ǰ�ڵ���ջ
			stackPush(&st, root);
			root = root->left;
		}
		//2.��ȡջ��Ԫ��,������
		root = stackTop(&st);
		arr[idx++] = root->val;
		stackPop(&st);

		//3.����ջ����������
		root = root->right;
	}
	*returnSize = idx;
	return arr;
}




//145. �������ĺ������
//����һ������������������ ���� ������
//�ݹ�
//��������ڵ����
int getSize(struct TreeNode* root)
{
	if (root)
		return getSize(root->left) + getSize(root->right) + 1;
	return 0;
}
//�������
void postorder(struct TreeNode* root, int* arr, int* idx)
{
	if (root)
	{
		postorder(root->left, arr, idx);
		postorder(root->right, arr, idx);
		arr[(*idx)++] = root->val;
	}
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
	int sz = getSize(root);
	int* arr = (int*)malloc(sizeof(int) * sz);
	int idx = 0;
	postorder(root, arr, &idx);
	*returnSize = idx;
	return arr;
}


//�ǵݹ�
//���������1.�Խڵ㿪ʼ����������·����������ÿһ���ڵ㣬��ջ
//          2.��ȡջ��Ԫ��:
//              ��ǰջ��Ԫ���Ƿ���Է��ʣ�
//                  a.û�������������Է���---��ִ�е�1��
//                  b.������������ɣ����Է���---��ִ�е�1��
//                  c.�������������ǻ�û�з��ʣ����ܷ��ʵ�ǰԪ��---�����ȷ���������---��ִ�е�1��
//          3.�������ڵ�Ϊ��&&ջΪ��
typedef struct TreeNode* SDataType;
//˳���ʵ��ջ
typedef struct stack
{
	SDataType* data;
	size_t size;
	size_t capacity;
}stack;

//��ʼ��ջ
void stackInit(stack* st);

//��ջ
void stackPush(stack* st, SDataType val);

//��ջ
void stackPop(stack* st);


//�п�
int stackEmpty(stack* st);

//�������������
void checkCapacity(stack* st);


//��ʼ��ջ
void stackInit(stack* st)
{
	//��ջ
	if (st == NULL)
		return;
	st->data = NULL;
	st->size = st->capacity = 0;
}

//�������������
void checkCapacity(stack* st)
{
	if (st->size == st->capacity)
	{
		int newCap = st->capacity == 0 ? 1 : 2 * st->capacity;
		st->data = (SDataType*)realloc(st->data, sizeof(SDataType) * newCap);
		st->capacity = newCap;
	}
}

//��ջ��β��
void stackPush(stack* st, SDataType val)
{
	if (st == NULL)
		return;
	checkCapacity(st);
	st->data[st->size++] = val;
}

//��ջ��βɾ
void stackPop(stack* st)
{
	if (st == NULL || st->size == 0)
		return;
	st->size--;
}

//��ȡջ��Ԫ��
SDataType stackTop(stack* st)
{
	return st->data[st->size - 1];
}

//�п�:Ϊ�շ���1����Ϊ�շ���0
int stackEmpty(stack* st)
{
	if (st == NULL || st->size == 0)
		return 1;
	return 0;
}

//��������ڵ����
int getSize(struct TreeNode* root)
{
	if (root)
		return getSize(root->left) + getSize(root->right) + 1;
	return 0;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
	int sz = getSize(root);
	int* arr = malloc(sizeof(int) * sz);
	stack st;
	stackInit(&st);
	int idx = 0;

	//prev:��һ�η��ʵĽڵ�
	struct TreeNode* prev = NULL;

	//��ǰ�����Ľڵ㲻Ϊ�գ���ջ��Ϊ��
	while (root || !stackEmpty(&st))
	{
		//1.��������·��
		while (root)
		{
			stackPush(&st, root);
			root = root->left;
		}
		//top: ջ���Ľڵ�
		struct TreeNode* top = stackTop(&st);
		//�ж�ջ��Ԫ���Ƿ���Է���
		//���Է��ʣ�û�������� ���� �������������
		//������������ɣ���һ�η��ʵĽڵ�prev��Ϊ�������ĸ��ڵ�
		if (top->right == NULL || top->right == prev)
		{
			//���Է��ʵ�ǰջ��Ԫ��
			arr[idx++] = top->val;
			stackPop(&st);
			//����prev
			prev = top;
		}
		else
			//������û�з��ʣ����ȷ���������
			root = top->right;
	}
	*returnSize = idx;
	return arr;
}




//�������Ĺ���������
//��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ������������ָ�뷽ʽ�洢���� 
//�������µ���������ַ����� ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������������˶������Ժ�
//�ٶԶ������������������������������
#include<stdio.h>
#include<stdlib.h>
typedef char DataType;
//�������Ľڵ㣺������
typedef struct BNode
{
	struct BNode* left;
	struct BNode* right;
	DataType data;
}Node;

typedef struct BTree
{
	//�������ĸ��ڵ�
	Node* root;
}BTree;

Node* creatBinaryTree(DataType arr[], int* idx)
{
	if (arr[*idx] == '#')
	{
		(*idx)++;
		return NULL;  //����
	}
	//��ǰ���ĸ��ڵ�
	Node* root = (Node*)malloc(sizeof(Node));
	root->data = arr[(*idx)++];

	root->left = creatBinaryTree(arr, idx);
	root->right = creatBinaryTree(arr, idx);
	return root;
}

//�������
void InOrder(Node* root)
{

	if (root)
	{
		//������  ��  ������
		InOrder(root->left);
		printf("%c ", root->data);
		InOrder(root->right);
	}
}

void test()
{
	char arr[100] = { 0 };
	int i = 0;
	for (i = 0; i < 100; i++)
	{
		scanf("%c", &arr[i]);
	}
	int idx = 0;
	Node* root = creatBinaryTree(arr, &idx);
	InOrder(root);

}
int main()
{
	test();
	return 0;
}
