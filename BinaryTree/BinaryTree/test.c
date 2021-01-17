#define _CRT_SECURE_NO_WARNINGS
#include"BinaryTree.h"

//创建一个二叉树，返回二叉树的根节点指针
//数组的顺序为前序遍历
Node* creatBinaryTree(DataType arr[],int* idx)
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

//前序遍历
void preOrder(Node* root)
{
	if (root)
	{
		//根  左子树  右子树
		printf("%c ", root->data);

		preOrder(root->left);
		preOrder(root->right);
	}
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

//后序遍历
void postOrder(Node* root)
{
	if (root)
	{
		//左子树 右子树 根
		postOrder(root->left);
		postOrder(root->right);
		printf("%c ", root->data);
	}
}

//二叉树节点个数
int bTreeSize(Node* root)
{
	if (root == NULL)
		return 0;
	//左子树个数+右子树子树+当前节点
	return bTreeSize(root->left) + bTreeSize(root->right) + 1;
}

//二叉树的高度
int bTreeHeight(Node* root)
{
	if (root == NULL)
		return 0;
	//max(左右子树的高度
	int left = bTreeHeight(root->left);
	int right = bTreeHeight(root->right);
	return left > right ? left + 1 : right + 1;
}

//二叉树叶子节点的个数
int bTreeLeafSize(Node* root)
{
	//空树
	if (root == NULL)
		return 0;
	//叶子节点
	if (root->left == NULL && root->right == NULL)
		return 1;
	//非叶子
	return bTreeLeafSize(root->left) + bTreeLeafSize(root->right);
}

//第k层节点个数：左右子树的k-1层和,假设根为第一层
int bTreeKSize(Node* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return bTreeKSize(root->left, k - 1) + bTreeKSize(root->right, k - 1);
}

//查找值为ch的节点
Node* bTreeFind(Node* root, char ch)
{
	if (root)
	{
		Node* node;
		//如果当前值找到了就返回节点
		if (root->data == ch)
			return root;
		//找左子树
		node = bTreeFind(root->left, ch);
		if (node)
			return node;
		else
			return bTreeFind(root->right, ch); //找右子树
	}
	else
		return NULL;
}

//销毁
void bTreeDestory(Node** root)
{
	if (*root)
	{
		bTreeDestory(&((*root)->left));
		bTreeDestory(&((*root)->left));
		free(*root);
		*root = NULL;
	}
}//如果是一级指针，指针没有置空，置空的指针为指针的拷贝，存在野指针


//层序遍历
void bTreeLevelOrder(Node* root)
{
	//借助队列保存节点
	Queue q;
	queueInit(&q);
	//根节点存入队列
	if (root)
		queuePush(&q, root);
	//遍历队列中的每一个节点
	while (!queueEmpty(&q))
	{
		//获取队头元素
		Node* front = queueFront(&q);
		//出队
		queuePop(&q);
		printf("%c ", front->data);
		//保存队头元素的左右孩子节点
		if (front->left)
			queuePush(&q, front->left);
		if (front->right)
			queuePush(&q, front->right);
	}
	printf("\n");
}


//完全二叉树：层序遍历，节点连续，中间没有空节点
int isCompleteBtree(Node* root)
{
	Queue q;
	queueInit(&q);
	if (root)
		queuePush(&q, root);
	while (!queueEmpty(&q))
	{
		//获取队头元素
		Node* front = queueFront(&q);
		queuePop(&q);
		//左右孩子入队
		if (front)
		{
			queuePush(&q, front->left);
			queuePush(&q, front->right);
		}
		else
			break;
	}
	//查看剩余元素中，是否有非空节点
	while (!queueEmpty)
	{
		Node* front = queueFront(&q);
		if (front)
			//如果剩余元素中存在非空节点，说明节点不连续
			return 0;
	}
	return 1;
}


//void test()
//{
//	char arr[] = "ABD##E#H##CF##G##";
//	int idx = 0;
//	Node* root = creatBinaryTree(arr, &idx);
//	preOrder(root);
//	printf("\n");
//	InOrder(root);
//	printf("\n");
//	postOrder(root);
//	printf("\n");
//	printf("%d\n", bTreeSize(root));
//	printf("Height: %d\n", bTreeHeight(root));
//
//	printf("kSzie:k-->%d:  %d\n", 4, bTreeKSize(root, 4));
//	printf("kSzie:k-->%d:  %d\n", 3, bTreeKSize(root, 3));
//	printf("kSzie:k-->%d:  %d\n", 2, bTreeKSize(root, 2));
//	printf("kSzie:k-->%d:  %d\n", 1, bTreeKSize(root, 1));
//	printf("kSzie:k-->%d:  %d\n", 5, bTreeKSize(root, 5));
//
//	Node* node = bTreeFind(root, 'G');
//
//	bTreeDestory(&root);
//}

int main()
{
	test();
	return 0;
}
















////判断是否为完全二叉树
//int BinaryTreeComplete(Node* root)
//{
//	list q;
//	Initlist(&q);  //初始化
//	//根节点入队
//	if(root)
//		pushBack(&q, root);
//	while (!listEmpty(&q))
//	{
//		//获取队头元素再删除
//		Node* front = head(&q);
//		popfront(&q);
//		//如果队头元素不为空，存入队头元素的左右子树
//		if (front)
//		{
//			pushBack(&q, front->left);
//			pushBack(&q, front->right);
//		}
//		else
//			break;
//	}
//	//循环队列剩余元素
//	while (!listEmpty(&q))
//	{
//		//记录队头元素，再删除，如果为空直接返回
//		Node* front = head(&q);
//		popFront(&q);
//		if (front)
//			return 0;
//		return 1;
//	}
//}
//
//struct TreeNode* invertTree(struct TreeNode* root)
//{
//	if (root)
//	{
//		struct TreeNode* tmp = root->left;
//		root->left = root->right;
//		root->right = tmp;
//		invertTree(root->left);
//		invertTree(root->right);
//	}
//	return root;
//}
//
//
//
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//	if (p == NULL && q == NULL)
//		return true;
//	if (p == NULL || q == NULL)
//		return false;
//	return p->val == q->val &&
//		isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}
//
//
//
//bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
//
//}