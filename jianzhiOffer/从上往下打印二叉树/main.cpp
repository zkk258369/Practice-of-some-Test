#include<iostream>
#include<vector>
#include<queue>

using std::vector;
using std::queue;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution
{
public:
    vector<int> PrintFromTopToBottom(TreeNode* root)
    {
        std::vector<int> vec;
        if(root == nullptr)
            return vec;
        
        std::queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty())
        {
            struct TreeNode* ptmp = que.front();
            que.pop();
            if(ptmp->left != nullptr)
                que.push(ptmp->left);
            if(ptmp->right != nullptr)
                que.push(ptmp->right);
            vec.push_back(ptmp->val);
        }
        return vec;
    }
};