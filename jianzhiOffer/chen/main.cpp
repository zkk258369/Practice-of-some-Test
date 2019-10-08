/*
������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������
�����е�Ԫ��Ϊint���͡�
push()�����У�ֱ�ӽ�Ԫ����ջ��
pop()�����У�����Ҫ�ж�stack2�Ƿ�Ϊ�գ�
	Ϊ������Ҫ��stack1�е����ݳ�ջ��ѹ��stack2��
	Ȼ��ɾ��ջ�����ɡ������Ϊ�գ�ֱ��ɾ��ջ����
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