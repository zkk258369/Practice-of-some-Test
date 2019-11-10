#include<iostream>

#define END '#'

template<typename T>
class BinNode
{
public:
	BinNode(T mdata);
	~BinNode();
	void SetData(T mdata);
	T GetData();
	void SetLeftChild(BinNode<T>* left);
	BinNode<T>* GetLeftChild();
	void SetRightChild(BinNode<T>* Right);
	BinNode<T>* GetRightChild();
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
	BinNode<T>* GetRoot();
	void SetRoot(BinNode<T>* node);
	BinNode<T>* CreateBinTree(char* &str);//创建二叉树
	void PreOrder(BinNode<T>* node);//前序遍历
	void INOrder(BinNode<T>* root);//中序遍历
	void PostOrder(BinNode<T>* root);//后序遍历
	bool Is_Full_BinTree(BinNode<T>* root);//判断是否为满二叉树
private:
	BinNode<T>* root;
};

template<typename T>
BinNode<T>::BinNode(T mdata)
{
	data = mdata;
	leftChild = nullptr;
	rightChild = nullptr;
}

template<typename T>
void BinNode<T>::SetData(T mdata)
{
	data = mdata;
}

template<typename T>
T BinNode<T>::GetData()
{
	return data;
}

template<typename T>
void BinNode<T>::SetLeftChild(BinNode<T>* left)
{
	leftChild = left;
}

template<typename T>
BinNode<T>* BinNode<T>::GetLeftChild()
{
	return leftChild;
}

template<typename T>
void BinNode<T>::SetRightChild(BinNode<T>* right)
{
	rightChild = right;
}

template<typename T>
BinNode<T>* BinNode<T>::GetRightChild()
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

}

template<typename T>
BinNode<T>* BinaryTree<T>::GetRoot()
{
	return root;
}

template<typename T>
void BinaryTree<T>::SetRoot(BinNode<T>* node)
{
	root = node;
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
void BinaryTree<T>::PreOrder(BinNode<T>* node)//前序遍历
{
	if (nullptr == node)
		return;
	else
	{
		std::cout << node->GetData() << " ";
		BinNode<T>* left = node->GetLeftChild();
		PreOrder(left);
		BinNode<T>* right = node->GetRightChild();
		PreOrder(right);
	}
}

int main()
{
	char* str = "ABC##DE##F##G#H##";
	BinaryTree<char> bt1;
	BinNode<char>* root = bt1.CreateBinTree(str);
	bt1.SetRoot(root);
		
	std::cout << "The result of PreOrder:";
	bt1.PreOrder(bt1.GetRoot());
	std::cout << std::endl;
	

	return 0;
}