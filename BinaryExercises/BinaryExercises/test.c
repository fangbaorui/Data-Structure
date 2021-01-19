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

//前序遍历
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

