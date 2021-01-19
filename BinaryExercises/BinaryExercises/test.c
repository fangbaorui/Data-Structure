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

//ǰ�����
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

