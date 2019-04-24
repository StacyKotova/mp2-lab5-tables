#ifndef TREE_H
#define TREE_H

#include <utility>
#include "treenode.h"
#include "tableelement.h"

// ����� "������"
class Tree
{
	TreeNode<TableElement> *root; // ������

	// ���������� � ������
	int _add(TreeNode<TableElement> *current, const TableElement& data, int count)
	{
		// ���� ����, �� �������� ������ ����
		if (current == NULL)
		{
			current = new TreeNode<TableElement>(data);
			return count + 1;
		}
		else if (current->data < data)
		{
			if (current->right == NULL)
			{
				current->right = new TreeNode<TableElement>(data);
				return count + 1;
			}
			else
				return _add(current->right, data, count + 1);
		}
		else
		{
			if (current->left == NULL)
			{
				current->left = new TreeNode<TableElement>(data);
				return count + 1;
			}
			else
				return _add(current->left, data, count + 1);
		}
	}

	// ����� �� ������
	std::pair<TreeNode<TableElement>*, int> _find(TreeNode<TableElement> *current,
		const TableElement& key, int count)
	{
		// ���� ������� ���� ��� ����� ����, �� ���������� �������
		if (current == NULL || current->data == key)
			return std::pair<TreeNode<TableElement>*, int>(current, count + 1);
		// ����� ������� � ����� ��� ������ ���������
		else if (current->data < key)
			return _find(current->right, key, count + 1);
		else
			return _find(current->left, key, count + 1);
	}

	bool _existsKey(TreeNode<TableElement> *current, const TableElement& te)
	{
		if (current == NULL)
			return false;
		else if (current->data.key() == te.key())
			return true;
		else if (current->data < te)
			return _existsKey(current->right, te);
		else
			return _existsKey(current->left, te);
	}

public:
	// ����������� �� ���������
	Tree()
	{
		root = NULL;
	}

	// ����������� � ����������
	Tree(const TableElement& data)
	{
		root = new TreeNode<TableElement>(data);
	}

	// ���������� ������
	int add(const TableElement& data)
	{
		// ���� ������ ����, ������� ���
		if (root == NULL)
		{
			root = new TreeNode<TableElement>(data);
			return 1;
		}
		else
			return _add(root, data, 0);
	}

	// ����� �� �����
	std::pair<TreeNode<TableElement>*, int> find(const TableElement& key)
	{
		return _find(root, key, 0);
	}

	bool existsKey(const TableElement& te)
	{
		return _existsKey(root, te);
	}
};

#endif // !TREE_H
