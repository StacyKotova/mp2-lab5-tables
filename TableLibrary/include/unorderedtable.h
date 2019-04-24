#ifndef UNORDERED_TABLE_H
#define UNORDERED_TABLE_H

#include <iostream>
#include <vector>
#include "../include/tableelement.h"

// ����� "��������������� �������"
class UnorderedTable
{
	std::vector<TableElement*> *table; // ������
public:
	// ����������� �������
	UnorderedTable()
	{
		table = new std::vector<TableElement*>();
	}

	bool existsKey(const std::string& key)
	{
		for (auto te : *table)
			if (te->key() == key)
				return true;
		return false;
	}

	// ���������� ������
	void add(const std::string& key, const Polynomial& p)
	{
		table->push_back(new TableElement(key, p));
		std::cout << "��������������� ������� - �������� ����������: 1." << std::endl;
	}

	// ���������� ������
	void add(const TableElement& te)
	{
		add(te.key(), te.value());
	}

	// ��������� ������
	Polynomial get(const std::string& key)
	{
		for (size_t i = 0; i < table->size(); i++)
		{
			if (table->at(i)->key() == key)
			{
				std::cout << "��������������� ������� - �������� ������: "
					<< i + 1 << "." << std::endl;
				return table->at(i)->value();
			}
		}
		return NULL;
	}
};

#endif /* UNORDERED_TABLE_H */