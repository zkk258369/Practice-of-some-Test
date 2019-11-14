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
	BinNode<T>* CreateBinTree(char* &str);//����������
	void PreOrder(BinNode<T>* root_node)const;//ǰ�����
	void InOrder(BinNode<T>* root_node)const;//�������
	void PostOrder(BinNode<T>* root_node)const;//�������
	void LevelOrder(BinNode<T>* root_node)const;//��α���
	void NorecPreOrder(BinNode<T>* root_node)const;//�ǵݹ�ǰ�����
	void NorecInOrder(BinNode<T>* root_node)const;//�ǵݹ�ǰ�����
	void NorecPostOrder(BinNode<T>* root_node)const;//�ǵݹ�ǰ�����
	int Count(BinNode<T>* root_node)const;//��ȡ�ڵ����
	int GetHeight(BinNode<T>* root_node)const;//��ȡ�߶�
	bool Is_Full_BinTree(BinNode<T>* root_node)const;//�ж��Ƿ�Ϊ��������
	bool Is_Comp_BinTree(BinNode<T>* root_node)const;//�ж��Ƿ�Ϊ��ȫ������
	bool Is_BST_BinTree(BinNode<T>* root_node)const;//�ж��Ƿ�ΪBST��(����������)
	bool Is_Balance_BinTree(BinNode<T>* root_node)const;//�ж��Ƿ�Ϊƽ�������
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
BinNode<T>* BinaryTree<T>::CreateBinTree(char* &str)//����������
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
void BinaryTree<T>::PreOrder(BinNode<T>* root_node)const//ǰ�����
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
void BinaryTree<T>::InOrder(BinNode<T>* root_node)const//�������
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
void BinaryTree<T>::PostOrder(BinNode<T>* root_node)const//�������
{
	assert(root_node != nullptr);

	BinNode<T>* left = root_node->GetLeftChild();
	InOrder(left);
	BinNode<T>* right = root_node->GetRightChild();
	InOrder(right);
	std::cout << root_node->GetData() << " ";
}

template<typename T>
void BinaryTree<T>::NorecPreOrder(BinNode<T>* root_node)const//�ǵݹ�ǰ�����
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
void BinaryTree<T>::NorecInOrder(BinNode<T>* root_node)const//�ǵݹ��������
{

}

template<typename T>
void BinaryTree<T>::NorecPostOrder(BinNode<T>* root_node)const//�ǵݹ�������
{

}

template<typename T>
void BinaryTree<T>::LevelOrder(BinNode<T>* root_node)const//��α���
{

}

template<typename T>
int BinaryTree<T>::Count(BinNode<T>* root_node)const//��ȡ�ڵ����
{
	if (root_node == nullptr)
		return 0;
	else
		return Count(root_node->GetLeftChild()) + Count(root_node->GetRightChild()) + 1;
}

template<typename T>
int BinaryTree<T>::GetHeight(BinNode<T>* root_node)const//��ȡ�߶�
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
bool BinaryTree<T>::Is_Full_BinTree(BinNode<T>* root_node)const//�ж��Ƿ�Ϊ��������
{
	if (root_node == nullptr)
		return false;
	int height = GetHeight(root_node);
	int count = Count(root_node);
	return count == pow(2, height) - 1 ? true : false;
}


int main()
{
	char* str1 = "ABC##DE##F##G#H##";//����
	char* str2 = "ABD##E##CF##G##";//����

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