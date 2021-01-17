#define _CRT_SECURE_NO_WARNINGS
#include"BinaryTree.h"

//����һ�������������ض������ĸ��ڵ�ָ��
//�����˳��Ϊǰ�����
Node* creatBinaryTree(DataType arr[],int* idx)
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

//ǰ�����
void preOrder(Node* root)
{
	if (root)
	{
		//��  ������  ������
		printf("%c ", root->data);

		preOrder(root->left);
		preOrder(root->right);
	}
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

//�������
void postOrder(Node* root)
{
	if (root)
	{
		//������ ������ ��
		postOrder(root->left);
		postOrder(root->right);
		printf("%c ", root->data);
	}
}

//�������ڵ����
int bTreeSize(Node* root)
{
	if (root == NULL)
		return 0;
	//����������+����������+��ǰ�ڵ�
	return bTreeSize(root->left) + bTreeSize(root->right) + 1;
}

//�������ĸ߶�
int bTreeHeight(Node* root)
{
	if (root == NULL)
		return 0;
	//max(���������ĸ߶�
	int left = bTreeHeight(root->left);
	int right = bTreeHeight(root->right);
	return left > right ? left + 1 : right + 1;
}

//������Ҷ�ӽڵ�ĸ���
int bTreeLeafSize(Node* root)
{
	//����
	if (root == NULL)
		return 0;
	//Ҷ�ӽڵ�
	if (root->left == NULL && root->right == NULL)
		return 1;
	//��Ҷ��
	return bTreeLeafSize(root->left) + bTreeLeafSize(root->right);
}

//��k��ڵ����������������k-1���,�����Ϊ��һ��
int bTreeKSize(Node* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return bTreeKSize(root->left, k - 1) + bTreeKSize(root->right, k - 1);
}

//����ֵΪch�Ľڵ�
Node* bTreeFind(Node* root, char ch)
{
	if (root)
	{
		Node* node;
		//�����ǰֵ�ҵ��˾ͷ��ؽڵ�
		if (root->data == ch)
			return root;
		//��������
		node = bTreeFind(root->left, ch);
		if (node)
			return node;
		else
			return bTreeFind(root->right, ch); //��������
	}
	else
		return NULL;
}

//����
void bTreeDestory(Node** root)
{
	if (*root)
	{
		bTreeDestory(&((*root)->left));
		bTreeDestory(&((*root)->left));
		free(*root);
		*root = NULL;
	}
}//�����һ��ָ�룬ָ��û���ÿգ��ÿյ�ָ��Ϊָ��Ŀ���������Ұָ��


//�������
void bTreeLevelOrder(Node* root)
{
	//�������б���ڵ�
	Queue q;
	queueInit(&q);
	//���ڵ�������
	if (root)
		queuePush(&q, root);
	//���������е�ÿһ���ڵ�
	while (!queueEmpty(&q))
	{
		//��ȡ��ͷԪ��
		Node* front = queueFront(&q);
		//����
		queuePop(&q);
		printf("%c ", front->data);
		//�����ͷԪ�ص����Һ��ӽڵ�
		if (front->left)
			queuePush(&q, front->left);
		if (front->right)
			queuePush(&q, front->right);
	}
	printf("\n");
}


//��ȫ������������������ڵ��������м�û�пսڵ�
int isCompleteBtree(Node* root)
{
	Queue q;
	queueInit(&q);
	if (root)
		queuePush(&q, root);
	while (!queueEmpty(&q))
	{
		//��ȡ��ͷԪ��
		Node* front = queueFront(&q);
		queuePop(&q);
		//���Һ������
		if (front)
		{
			queuePush(&q, front->left);
			queuePush(&q, front->right);
		}
		else
			break;
	}
	//�鿴ʣ��Ԫ���У��Ƿ��зǿսڵ�
	while (!queueEmpty)
	{
		Node* front = queueFront(&q);
		if (front)
			//���ʣ��Ԫ���д��ڷǿսڵ㣬˵���ڵ㲻����
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
















////�ж��Ƿ�Ϊ��ȫ������
//int BinaryTreeComplete(Node* root)
//{
//	list q;
//	Initlist(&q);  //��ʼ��
//	//���ڵ����
//	if(root)
//		pushBack(&q, root);
//	while (!listEmpty(&q))
//	{
//		//��ȡ��ͷԪ����ɾ��
//		Node* front = head(&q);
//		popfront(&q);
//		//�����ͷԪ�ز�Ϊ�գ������ͷԪ�ص���������
//		if (front)
//		{
//			pushBack(&q, front->left);
//			pushBack(&q, front->right);
//		}
//		else
//			break;
//	}
//	//ѭ������ʣ��Ԫ��
//	while (!listEmpty(&q))
//	{
//		//��¼��ͷԪ�أ���ɾ�������Ϊ��ֱ�ӷ���
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