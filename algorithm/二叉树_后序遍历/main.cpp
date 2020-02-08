#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
#include<iterator>
#include<algorithm>

template<typename T>
class BinNode
{
public:
	BinNode(const T& mdata);
	void SetData(const T& mdata);
	T& GetData();
	void SetLeftChild(BinNode<T>* left);
	BinNode<T>* GetLeftChild() const;
	void SetRightChild(BinNode<T>* Right);
	BinNode<T>* GetRightChild()const;
private:
	T data;
	BinNode<T>* leftChild;
	BinNode<T>* rightChild;
};

template<typename T>
void BinaryTree<T>::PostOrder(BinNode<T>* root_node)const//后序遍历
{
	if (nullptr == root_node)
		return;
	else
	{
		BinNode<T>* left = root_node->GetLeftChild();
		PostOrder(left);
		BinNode<T>* right = root_node->GetRightChild();
		PostOrder(right);
		std::cout << root_node->GetData() << " ";
	}
}

//非递归后序遍历  关键在怎么知道右子树是否被访问
//tag
template < typename T >
void BinaryTree<T>::NorecPostOrder(BinNode<T>* root_node)
{
	if (root_node == nullptr)
		return;
	std::stack<BinNode<T>*> sta;
	BinNode<T>* tag = nullptr;
	BinNode<T>* ptr = root_node;
	while (!sta.empty() || ptr != nullptr)
	{
		while (ptr != nullptr)
		{
			sta.push(ptr);
			ptr = ptr->GetLeftChild();
		}
		ptr = sta.top();
		sta.pop();
		if (ptr->GetRightChild() == nullptr || ptr->GetRightChild() == tag)
		{
			std::cout << ptr->GetData() << " ";
			tag = ptr;
			ptr = nullptr;
		}
		else
		{
			sta.push(ptr->GetRightChild());
			ptr = ptr->GetRightChild();
		}
	}
}

template<typename T>
void BinaryTree<T>::NorecPostOrder(BinNode<T>* root_node)//非递归后序遍历  关键在怎么知道右子树是否被访问
{
	if (root_node == nullptr)
		return;
	std::stack<BinNode<T>*> sta;
	std::unorder_set<BinNode<T>*> _set;

	sta.push(root_node);
	while (!sta.empty())
	{
		BinNode<T>* node = sta.top();
		bool visitedRight = true;
		bool visitedLeft = true;

		if (node->GetRightChild() != nullptr && _set.find(node->GetRightChild() == _set.end()))
		{
			sta.push(node->GetRightChild());
			visitedRight = false;
		}
		if (node->GetLeftChild() != nullptr && _set.find(node->GetLeftChild() == _set.end()))
		{
			sta.push(node->GetLeftChild());
			visitedLeft = false;
		}
		if (visitedRight && visitedLeft)
		{
			std::cout << node->GetData() << " ";
			_set.insert(node);
			sta.pop();
		}
	}
}

template<typename T>
void BinaryTree<T>::NorecPostOrder(BinNode<T>* root_node)const//非递归后序遍历,广度遍历+逆序输出
{
	if (root_node == nullptr)
		return;
	std::stack<BinNode<T>*> sta;
	std::list<T> output;

	sta.push(root_node);
	while (!sta.empty())
	{
		BinNode<T>* node = sta.top();
		sta.pop();
		output.push_front(node->GetData());
		if (node->GetLeftChild() != nullptr)
			sta.push(node->GetLeftChild());
		if (node->GetRightChild() != nullptr)
			sta.push(node->GetRightChild());
	}
	for (std::list<T>::iterator it = output.begin(); it != output.end(); it++)
		std::cout << *it << " ";
}