#ifndef TREENODE_H
#define TREENODE_H

// ��������� "���� ������"
template<typename T>
struct TreeNode
{
	T data; // ������
	TreeNode *left, *right; // ����-�������
	
	// ����������� �� ���������
	TreeNode<T>()
	{
		this->data = NULL;
		this->left = NULL;
		this->right = NULL;
	}

	// ����������� � �����������
	TreeNode<T>(const T& data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}

	// ����������� � �����������
	TreeNode<T>(const T& data, TreeNode<T> *left, TreeNode<T> *right)
	{
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

#endif /* TREENODE_H */