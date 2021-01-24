#define _CRT_SECURE_NO_WARNINGS
//单值二叉树
//如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
bool _isUnivalTree(struct TreeNode* root, int val)
{
	if (root)
	{
		//遍历当前值及其左子树、右子树
		return root->val == val && _isUnivalTree(root->left, val)
		&& _isUnivalTree(root->right, val);
	}

	//如果为空树返回真
	return true;
}
bool isUnivalTree(struct TreeNode* root) {
	if (root == NULL) 
		return true;
	return _isUnivalTree(root, root->val);  //roo->val传的是根的值，是定值
}




//给定一个二叉树，找出其最大深度。
//二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
int maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	//左右子树高度的最大值加1
	int left = maxDepth(root->left);
	int right = maxDepth(root->right);
	return left > right ? left + 1 : right + 1;
}

int maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	//左右子树高度的最大值加1
	int left = maxDepth(root->left) + 1;
	int right = maxDepth(root->right) + 1;
	return left > right ? left : right;
}



// 翻转二叉树
struct TreeNode* invertTree(struct TreeNode* root) {
	//空树返回空
	if (root == NULL)
		return NULL;
	//交换左右子树
	struct TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	invertTree(root->left);
	invertTree(root->right);
	return root;
}



//给定两个二叉树，编写一个函数来检验它们是否相同。
//如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

//按照相同的遍历顺序：保证遍历到的每个节点的位置都是相同的
//如果同时到达空节点：相同，如果没有同时到达空节点则不同，
//没有到达空节点：比较值，遍历左子树，遍历右子树
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	//同时为空，返回真
	if (p == NULL && q == NULL)
		return true;
	//不同时为空，返回假
	if (p == NULL || q == NULL)
		return false;
	//比较不为空的值，在遍历左子树，右子树
	return p->val == q->val &&
		isSameTree(p->left, q->left) &&
		isSameTree(p->right, q->right);
}



//另一个树的子树
//给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。
//s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。
//判断两棵树是否相同
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	//同时为空，返回真
	if (p == NULL && q == NULL)
		return true;
	//不同时为空，返回假
	if (p == NULL || q == NULL)
		return false;
	//比较不为空的值，在遍历左子树，右子树
	return p->val == q->val &&
		isSameTree(p->left, q->left) &&
		isSameTree(p->right, q->right);
}

//当前节点去比较，左子树去比较，右子树去比较
bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
	//t为空树是所有树的子树
	if (t == NULL)
		return true;
	if (s == NULL)
		return false;
	return isSameTree(s, t) ||
		isSubtree(s->left, t) || isSubtree(s->right, t);
}



//给定一个二叉树，检查它是否是镜像对称的。
//left->left==right->right,left->right==right->left
bool _isSym(struct TreeNode* left, struct TreeNode* right)
{
	//同时为空，返回真
	if (left == NULL && right == NULL)
		return true;
	//不同时达到空返回假
	if (left == NULL || right == NULL)
		return false;
	//比较值、左边的左边与右边的右边、左边的右边和右边的左边
	return left->val == right->val &&
		_isSym(left->left, right->right) && _isSym(left->right, right->left);
}
bool isSymmetric(struct TreeNode* root) {
	if (root == NULL)
		return true;
	return _isSym(root->left, root->right);
}




//给定一个二叉树，判断它是否是高度平衡的二叉树。
//本题中，一棵高度平衡二叉树定义为：
//一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
//求出树的高度
int getHeight(struct TreeNode* root)
{
	//如果树存在
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
	//求根节点左子树的高度
	int left = getHeight(root->left);
	//求根节点右子树的高度
	int right = getHeight(root->right);
	return abs(left - right) < 2 &&
		isBalanced(root->left) &&
		isBalanced(root->right);
}



//二叉树的前序遍历
//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
//求二叉树节点个数
int getSize(struct TreeNode* root)
{
	if (root)
		return getSize(root->left) + getSize(root->right) + 1;
	return 0;
}

//前序遍历：递归
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

//非递归
//前序遍历：对于每一个节点，最先访问的是以此节点开始的最左路径
//          对于每一棵树，最先访问的右子树，是在访问左路径最后遇到的右子树
//左边的节点访问：自上而下，右边的节点访问：自下而上

//1.访问每一个节点开始的最左路径，访问到的每一个节点入栈
//2.最左路径访问完成之后，获取栈顶元素，继续访问以栈顶元素的右子树为根的子结构，继续执行第1步
//3.结束：栈为空&&右子树为空

//非递归
typedef struct TreeNode* SDataType;
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
SDataType stackTop(stack* st)
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

//求二叉树节点个数
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
	//当前遍历的节点不为空，或栈不为空
	while (root || !stackEmpty(&st))
	{
		//1.访问最左路径
		while (root)
		{
			arr[idx++] = root->val;
			//当前节点入栈
			stackPush(&st, root);
			root = root->left;
		}
		//2.获取栈顶元素
		root = stackTop(&st);
		stackPop(&st);
		root = root->right;
	}
	*returnSize = idx;
	return arr;
}




//94. 二叉树的中序遍历
//给定一个二叉树的根节点 root ，返回它的 中序 遍历。
//求二叉树节点个数
int getSize(struct TreeNode* root)
{
	if (root)
		return getSize(root->left) + getSize(root->right) + 1;
	return 0;
}
//中序遍历
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



//非递归——中序遍历
//1.以节点开始，走最左路径，此路径上遇到的每一个节点首先入栈，但是不能访问
//2.获取栈顶元素，访问栈顶元素
//3.获取栈顶元素的右子树，继续执行第1步
//4.结束：栈为空&&右子树为空

//非递归
typedef struct TreeNode* SDataType;
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
SDataType stackTop(stack* st)
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

//求二叉树节点个数
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
	//当前遍历的节点不为空，或栈不为空
	while (root || !stackEmpty(&st))
	{
		//1.遍历最左路径
		while (root)
		{
			//当前节点入栈
			stackPush(&st, root);
			root = root->left;
		}
		//2.获取栈顶元素,访问它
		root = stackTop(&st);
		arr[idx++] = root->val;
		stackPop(&st);

		//3.访问栈顶的右子树
		root = root->right;
	}
	*returnSize = idx;
	return arr;
}




//145. 二叉树的后序遍历
//给定一个二叉树，返回它的 后序 遍历。
//递归
//求二叉树节点个数
int getSize(struct TreeNode* root)
{
	if (root)
		return getSize(root->left) + getSize(root->right) + 1;
	return 0;
}
//后序遍历
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


//非递归
//后序遍历：1.以节点开始，遍历最左路径，遇到的每一个节点，入栈
//          2.获取栈顶元素:
//              当前栈顶元素是否可以访问：
//                  a.没有右子树：可以访问---》执行第1步
//                  b.右子树访问完成：可以访问---》执行第1步
//                  c.有右子树，但是还没有访问：不能访问当前元素---》首先访问右子树---》执行第1步
//          3.结束：节点为空&&栈为空
typedef struct TreeNode* SDataType;
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
SDataType stackTop(stack* st)
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

//求二叉树节点个数
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

	//prev:上一次访问的节点
	struct TreeNode* prev = NULL;

	//当前遍历的节点不为空，或栈不为空
	while (root || !stackEmpty(&st))
	{
		//1.遍历最左路径
		while (root)
		{
			stackPush(&st, root);
			root = root->left;
		}
		//top: 栈顶的节点
		struct TreeNode* top = stackTop(&st);
		//判断栈顶元素是否可以访问
		//可以访问：没有右子树 或者 右子树访问完成
		//右子树访问完成：上一次访问的节点prev，为右子树的根节点
		if (top->right == NULL || top->right == prev)
		{
			//可以访问当前栈顶元素
			arr[idx++] = top->val;
			stackPop(&st);
			//更新prev
			prev = top;
		}
		else
			//右子树没有访问，首先访问右子树
			root = top->right;
	}
	*returnSize = idx;
	return arr;
}




//二叉树的构建及遍历
//编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。 
//例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。建立起此二叉树以后，
//再对二叉树进行中序遍历，输出遍历结果。
#include<stdio.h>
#include<stdlib.h>
typedef char DataType;
//二叉树的节点：二叉链
typedef struct BNode
{
	struct BNode* left;
	struct BNode* right;
	DataType data;
}Node;

typedef struct BTree
{
	//二叉树的根节点
	Node* root;
}BTree;

Node* creatBinaryTree(DataType arr[], int* idx)
{
	if (arr[*idx] == '#')
	{
		(*idx)++;
		return NULL;  //空树
	}
	//当前树的根节点
	Node* root = (Node*)malloc(sizeof(Node));
	root->data = arr[(*idx)++];

	root->left = creatBinaryTree(arr, idx);
	root->right = creatBinaryTree(arr, idx);
	return root;
}

//中序遍历
void InOrder(Node* root)
{

	if (root)
	{
		//左子树  根  右子树
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
