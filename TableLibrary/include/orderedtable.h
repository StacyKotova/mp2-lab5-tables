#ifndef ORDERED_TABLE_H
#define ORDERED_TABLE_H

#include "../include/tableelement.h"
#include "../include/tree.h"
#include <iostream>

// ����� "������������� �������"
class OrderedTable
{
	Tree *table; // �������� ������ ������

public:
	// ����������� �������
	OrderedTable() 
	{
		table = new Tree();
	}

	bool existsKey(const TableElement& te)
	{
		return table->existsKey(te);
	}

	// ���������� ������
	void add(const std::string& key, const Polynomial& p)
	{
		int count = table->add(TableElement(key, p));
		std::cout << "������������� ������� - �������� ����������: "
			<< count << std::endl;
	}

	// ���������� ������
	void add(const TableElement& te)
	{
		add(te.key(), te.value());
	}

	// ����� ��������
	Polynomial get(const std::string& key)
	{
		auto result = table->find(TableElement(key, Polynomial()));
		std::cout << "������������� ������� - �������� ������: "
			<< result.second << "." << std::endl;
		return result.first->data.value();
	}
};

#endif /* ORDERED_TABLE_H */