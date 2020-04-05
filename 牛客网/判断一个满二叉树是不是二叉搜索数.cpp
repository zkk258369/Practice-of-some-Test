/*
 * 给定一棵满二叉树，判定该树是否为二叉搜索树，是的话打印True，不是的话打印False
 *
 * 输入 10, 5, 15, 3, 7, 13, 18
 * 输出 true
 * 说明：
 * a. 二叉搜索树（Binary Search Tree），它或者是一棵空树，或者是具有下列性质的二叉树： 
    若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
    若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值； 
    它的左、右子树也分别为二叉搜索树。
 * b. 满二叉树，除最后一层无任何子节点外，每一层上的所有结点都有两个子结点二叉树。
 * c. 树内节点数不超过 10000，非空节点值为大于0小于65536的整数，空树或空节点输入为None
 */


#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void ShowVector(vector<int>& vec)
{
    for(auto iter : vec)
    {
        cout << iter << " ";
    }
    cout << endl;
}

class Solution
{
public:
    /*
        10
      5    15
    3  7 13  19
    */
    bool IsBalanceBT(vector<int>& vec)
    {
        vector<int> res;
        InOrder(vec, res, 0);
        for(unsigned int i=0; i<res.size()-1; ++i)
        {
            if(res[i] > res[i+1])
                return false;
        }
        ShowVector(res);
        return true;
    }

private:
    void InOrder(vector<int>& vec ,vector<int>& res, unsigned int cur)
    {
        if((cur*2+1) < vec.size())
            InOrder(vec, res, cur*2+1);

        res.push_back(vec[cur]);

        if((cur*2+2) < vec.size())
            InOrder(vec, res, cur*2+2);
    }
};


int main()
{
    vector<int> vec;
    int x = -1;
    char c = ','; // 存储 ,
    while(cin >> x)
    {
        vec.push_back(x);
        cin >> c;
    }

    ShowVector(vec);

    Solution test;
    bool y = test.IsBalanceBT(vec);
    if(y)
        printf("True\n");
    else
        printf("False\n");
    
    

    system("pause");
    return 0;
}
