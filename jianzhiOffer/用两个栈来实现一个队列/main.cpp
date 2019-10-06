//������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ 
//�����е�Ԫ��Ϊint���͡�
#if 1
#include<iostream>
#include<stack>
using std::stack;

class Solution
{
public:
	void push(int node)
	{
		while (!stack2.empty())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
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