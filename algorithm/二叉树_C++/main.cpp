#include<iostream>
#include<cassert>
#include<cmath>
#define END '#'

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
class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	void del(BinNode<T>* root_node);
	BinNode<T>* GetRoot();
	void SetRoot(BinNode<T>* root_node);
	BinNode<T>* CreateBinTree(char* &str);//创建二叉树
	void PreOrder(BinNode<T>* root_node)const;//前序遍历
	void InOrder(BinNode<T>* root_node)const;//中序遍历
	void PostOrder(BinNode<T>* root_node)const;//后序遍历
	void LevelOrder(BinNode<T>* root_node)const;//层次遍历
	void NorecPreOrder(BinNode<T>* root_node)const;//非递归前序遍历
	void NorecInOrder(BinNode<T>* root_node)const;//非递归前序遍历
	void NorecPostOrder(BinNode<T>* root_node)const;//非递归前序遍历
	int Count(BinNode<T>* root_node)const;//获取节点个数
	int GetHeight(BinNode<T>* root_node)const;//获取高度
	bool Is_Full_BinTree(BinNode<T>* root_node)const;//判断是否为满二叉树
	bool Is_Comp_BinTree(BinNode<T>* root_node)const;//判断是否为完全二叉树
	bool Is_BST_BinTree(BinNode<T>* root_node)const;//判断是否为BST树(二叉搜索树)
	bool Is_Balance_BinTree(BinNode<T>* root_node)const;//判断是否为平衡二叉树
private:
	BinNode<T>* root;
};

template<typename T>
BinNode<T>::BinNode(const T& mdata)
{
	data = mdata;
	leftChild = nullptr;
	rightChild = nullptr;
}

template<typename T>
void BinNode<T>::SetData(const T& mdata)
{
	data = mdata;
}

template<typename T>
T& BinNode<T>::GetData()
{
	return data;
}

template<typename T>
void BinNode<T>::SetLeftChild(BinNode<T>* left)
{
	leftChild = left;
}

template<typename T>
BinNode<T>* BinNode<T>::GetLeftChild()const
{
	return leftChild;
}

template<typename T>
void BinNode<T>::SetRightChild(BinNode<T>* right)
{
	rightChild = right;
}

template<typename T>
BinNode<T>* BinNode<T>::GetRightChild()const
{
	return rightChild;
}

template<typename T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;
}

template < typename T >
BinaryTree<T>::~BinaryTree()
{
	del(GetRoot());
	root = nullptr;
}

template<typename T>
void BinaryTree<T>::del(BinNode<T>* root_node)
{
	if (root_node != nullptr)
	{
		del(root_node->GetLeftChild());
		del(root_node->GetRightChild());
		delete root_node;
	}
}

template<typename T>
BinNode<T>* BinaryTree<T>::GetRoot()
{
	return root;
}

template<typename T>
void BinaryTree<T>::SetRoot(BinNode<T>* root_node)
{
	root = root_node;
}

template<typename T>
BinNode<T>* BinaryTree<T>::CreateBinTree(char* &str)//创建二叉树
{
	if (str == NULL || *str == END)
		return NULL;
	else
	{
		BinNode<T>* node = new BinNode<T>(*str);
		BinNode<T>* left = CreateBinTree(++str);
		node->SetLeftChild(left);
		BinNode<T>* right = CreateBinTree(++str);
		node->SetRightChild(right);
		return node;
	}
}

template<typename T>
void BinaryTree<T>::PreOrder(BinNode<T>* root_node)const//前序遍历
{
	if (nullptr == root_node)
		return;
	else
	{
		std::cout << root_node->GetData() << " ";
		BinNode<T>* left = root_node->GetLeftChild();
		PreOrder(left);
		BinNode<T>* right = root_node->GetRightChild();
		PreOrder(right);
	}
}

template<typename T>
void BinaryTree<T>::InOrder(BinNode<T>* root_node)const//中序遍历
{
	if (nullptr == root_node)
		return;
	else
	{
		BinNode<T>* left = root_node->GetLeftChild();
		InOrder(left);
		std::cout << root_node->GetData() << " ";
		BinNode<T>* right = root_node->GetRightChild();
		InOrder(right);
	}
}

template<typename T>
void BinaryTree<T>::PostOrder(BinNode<T>* root_node)const//后序遍历
{
	assert(root_node != nullptr);

	BinNode<T>* left = root_node->GetLeftChild();
	InOrder(left);
	BinNode<T>* right = root_node->GetRightChild();
	InOrder(right);
	std::cout << root_node->GetData() << " ";
}

template<typename T>
void BinaryTree<T>::NorecPreOrder(BinNode<T>* root_node)const//非递归前序遍历
{
	BinNode<T>* ptr = root_node;
	while ()
	{
		if (p->GetLeftChild())
		{

		}
		else
		{

		}
	}
}

template<typename T>
void BinaryTree<T>::NorecInOrder(BinNode<T>* root_node)const//非递归中序遍历
{

}

template<typename T>
void BinaryTree<T>::NorecPostOrder(BinNode<T>* root_node)const//非递归后序遍历
{

}

template<typename T>
void BinaryTree<T>::LevelOrder(BinNode<T>* root_node)const//层次遍历
{

}

template<typename T>
int BinaryTree<T>::Count(BinNode<T>* root_node)const//获取节点个数
{
	if (root_node == nullptr)
		return 0;
	else
		return Count(root_node->GetLeftChild()) + Count(root_node->GetRightChild()) + 1;
}

template<typename T>
int BinaryTree<T>::GetHeight(BinNode<T>* root_node)const//获取高度
{
	if (root_node == nullptr)
		return 0;
	else
	{
		int a = GetHeight(root_node->GetLeftChild());
		int b = GetHeight(root_node->GetRightChild());
		return (a > b ? a : b) + 1;
	}
}

template<typename T>
bool BinaryTree<T>::Is_Full_BinTree(BinNode<T>* root_node)const//判断是否为满二叉树
{
	if (root_node == nullptr)
		return false;
	int height = GetHeight(root_node);
	int count = Count(root_node);
	return count == pow(2, height) - 1 ? true : false;
}


int main()
{
	char* str1 = "ABC##DE##F##G#H##";//先序
	char* str2 = "ABD##E##CF##G##";//先序

	BinaryTree<char> bt1;
	BinNode<char>* root = bt1.CreateBinTree(str1);
	bt1.SetRoot(root);

	std::cout << "The result of PreOrder:";
	bt1.PreOrder(bt1.GetRoot());
	std::cout << std::endl;

	std::cout << "The result of InOrder:";
	bt1.InOrder(bt1.GetRoot());
	std::cout << std::endl;

	std::cout << "The result of PostOrder:";
	bt1.PostOrder(bt1.GetRoot());
	std::cout << std::endl;

	int count = bt1.Count(root);
	std::cout << "Count = " << count << std::endl;

	int height = bt1.GetHeight(root);
	std::cout << "height = " << height << std::endl;

	bool flag = bt1.Is_Full_BinTree(root);
	if (flag)
		std::cout << "str1 Is_Full_BinTree" << std::endl;
	else
		std::cout << "str1 Is_Not_Full_BinTree" << std::endl;


	return 0;
}