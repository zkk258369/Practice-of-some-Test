#include<iostream>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

//交换非叶子节点的左右子树
class Solution
{
public:
    void Mirror(TreeNode *pRoot)
    {
        if(pRoot == nullptr)
            return;
        std::swap(pRoot->left, pRoot->right);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};