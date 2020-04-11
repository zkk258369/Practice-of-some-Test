#include<bits/stdc++.h>

using std::string;

typedef struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        :val(x)
    {}
}TreeNode;

//重载string类的+运算符
string operator+(string &content, int number)
{
	string temp = "";
	char t = 0;
	while (true)
    {
		t = number % 10 + '0';
		temp = t + temp;
		number /= 10;
		if (number == 0)
        {
			return content + temp;
		}
	}
}

//重载string类的+=运算符
string& operator+=(string& content, int number)
{
    return content = content + number;
}

/*
 * 二叉树的序列化
 * 将 已经序列化的二叉树字符串 重构成 二叉树
 * 本题用先序遍历
 * 二叉树的val是int类型的，要处理多为数字比如 123转化成字符串，用','分隔；从字符串转换成数字。
 * 
*/
class Solution
{
public:
    char* Serialize(TreeNode *root)
    {       
        if(root == nullptr)
        {
            return nullptr;
        }
        string str;
        SerializeDFS(root, str);
        char* res = new char[str.size()+1];
        strcpy(res, str.c_str());
        return res;
    }
    void SerializeDFS(TreeNode* root, string& arr)
    {
        if(nullptr == root)
        {
            arr += '#';
        }
        else
        {
            arr += std::to_string(root->val);
            arr += ",";
            SerializeDFS(root->left, arr);
            SerializeDFS(root->right, arr);
        }      
    }
    //12,5,2,##9,##18,15,#17,16,###19,##
    TreeNode* Deserialize(char* str)
    {
        TreeNode* root = nullptr;
        if(str == nullptr)
        {
            return root;
        }
        root = DeserializeDFS(str);
        return root;
    }
    TreeNode* DeserializeDFS(char*& str)
    {
        if(str == nullptr || *str == '#')
        {
            ++str;
            return nullptr;
        }
        else
        {
            int value = 0;
            while(*str != ',')
            {
                value = 10 * value + *str-'0';
                ++str;
            }
            ++str;
            TreeNode* p = new TreeNode(value);
            p->left = DeserializeDFS(str);
            p->right = DeserializeDFS(str);
            return p;
        }
    }
};