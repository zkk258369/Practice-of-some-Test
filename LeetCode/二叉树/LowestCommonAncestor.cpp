/*
 *寻找最近公共祖先节点
*/
#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_set>

using std::unordered_map;
using std::vector;
using std::unordered_set;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        : val(x), left(NULL), right(NULL)
    {}
};
 
class Solution  //recursive
{
public:
    Solution(TreeNode* answer=nullptr)
        :ans(answer)
        {}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        recursiveTree(root, p, q);
        return ans;
    }
private:
    bool recursiveTree(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == nullptr)
            return false;
        
        int left = recursiveTree(root->left, p, q) ? 1 : 0;
        int right = recursiveTree(root->right, p, q);
        int mid = (root == p || root == q) ? 1 : 0;

        if(mid + left + right >= 2)
            ans = root;
        
        return(mid + left + right > 0);
    }
private:
    TreeNode* ans;
};

class Solution  //recursive2
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root == nullptr || root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left == nullptr) return right;
        if(right == nullptr) return left;

        return root;
    }
};

//tarjan算法--------------------------------------------------------------------start
class unionFind
{
public:
    unordered_map<TreeNode*, TreeNode*> arr;

    unionFind()
    {}

    void Union(TreeNode* first,TreeNode* second)
    {
        TreeNode* i=find(first); 
        TreeNode* j=find(second);
        if(i!=j)//如果祖先不同 真的合并
        {
            arr[j]=i;
        }
    }

    TreeNode* find(TreeNode* cur)//路径压缩的find
    { 
        if(arr.count(cur)==0)
            arr[cur]=cur;
        if(arr[cur]!=cur)
        {
            TreeNode* ans=find(arr[cur]);
            arr[cur]=ans;
            return ans;
            // return arr[cur]=find(arr[cur]); //直接和最终的答案接起来
        }
        else 
            return cur;
    }
};

class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {    
        // <2> 离线的Tarjan算法, 也就是说有q个查询, 在一次dfs遍历中全部完成  
            https://www.cnblogs.com/JVxie/p/4854719.html
            // 1.任选一个点为根节点，从根节点u开始, 标记根节点被访问过
            // 2.递归调用dfs遍历根节点的所有子节点v, 每调用一次dfs, 把v合并到u上, 注意一定是把v合并到u上, u是更高级
            // 3.寻找与当前点u有询问关系的点q。
            // 4.若是q已经被访问过了，则可以确认u和q的最近公共祖先就是q的父亲f


        // 这个写法尽可能地想要实现一次dfs遍历, 把所有的q个查询都完成, 所以大量地使用了unordered_map
        // 这么实现的一个小问题是, p的查询中有q,q的查询中有p, 但是最终返回的结果是, 要么是p记录着正确结果, 要么是q记录着正确结果, 另外一个显示得是NULL
            // 对于怎么好地表示这个查询, 怎么好地记录结果, 怎么好地表示并查集,还是没有好的办法
        
        unordered_map<TreeNode*, vector<TreeNode*>> query; // 记录结果, 如果有q个查询, 在query中实际上有2q个项
        unordered_map<TreeNode*, vector<TreeNode*>> res;   // 记录结果, 如果有q中查询, 在res中有2q个项, 其中q个记录着正确答案, 剩下q个记录着NULL
        unordered_set<TreeNode*> visited; // 记录某个结点是否被访问过
        query[p]={q}; // 建立query 注意查询是双向的, 对称的
        query[q]={p};
        unionFind uF; //并查集
        dfs(root, query, res, uF, visited); // 进行dfs
        if(res[p][0]) // 由于res[p][0]和res[q][0]一个记录着正确答案, 一个记录着NULL, 必须把正确答案挑选出来
            return res[p][0];
        else 
            return res[q][0];

    }


    // <2> 离线的Tarjan算法, 也就是说有q个查询, 在一次dfs遍历中全部完成  
    // https://www.cnblogs.com/JVxie/p/4854719.html
    void dfs(TreeNode* root,
            unordered_map<TreeNode*, vector<TreeNode*>>& query, 
            unordered_map<TreeNode*, vector<TreeNode*>>& res, 
            unionFind& uF,
            unordered_set<TreeNode*>& visited)
    {
        if(root)
        {
            visited.insert(root); // 现在设置root访问过, 还是把这个放在所有的子节点访问过后, 我觉得没区别, 因为在并查集中查询的时候, 没访问过的结点会被创建, 同时把父亲设置为自己
            if(root->left)// 如果左子树存在
            { 
                dfs(root->left, query, res, uF,visited); // dfs左子树
                uF.Union(root,root->left); // 注意一定是把左子树合并到根节点上, 根节点还是父亲
            }
            if(root->right)
            {
                dfs(root->right, query, res, uF,visited); // dfs右子树
                uF.Union(root,root->right);  // 注意一定是把右子树合并到根节点上, 根节点还是父亲
            }

            if(query.count(root)!=0)// 如果有关于root的查询
            {
                if(res.count(root)==0)// 建立容纳结果的数组
                {
                    res[root]=vector<TreeNode*>(query[root].size(), NULL);
                }
                for(int i=0;i<query[root].size();++i)// 对于和root有关的每一个查询
                {
                    if(visited.count(query[root][i]))// 这个这个结点已经被访问过了
                    {
                        res[root][i]=uF.find(query[root][i]); // 那么这个结点的父亲就是两个结点的最近公共祖先                
                    }
                        
                }
            }
        }
    }
};
//tarjan算法--------------------------------------------------------------------end
