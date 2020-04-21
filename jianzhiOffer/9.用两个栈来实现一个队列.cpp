/*
用两个栈来实现一个队列，完成队列的Push和Pop操作。
队列中的元素为int类型。
push()函数中，直接将元素入栈。
pop()函数中，首先要判断stack2是否为空，
	为空则需要将stack1中的数据出栈并压入stack2，
	然后删除栈顶即可。如果不为空，直接删除栈顶。
*/

#if 1
#include<iostream>
#include<stack>
using std::stack;

class Solution
{
public:
	void push(int node)
	{
		stack1.push(node);
	}

	int pop()
	{
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		int res = stack2.top();
		stack2.pop();
		return res;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main()
{


	return 0;
}
#endif