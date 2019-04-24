#ifndef TABLE_ELEMENT_H
#define TABLE_ELEMENT_H

#include <string>
#include "polynomial.h"

// ����� "������� �������"
class TableElement
{
	std::string _key; // ����
	Polynomial _value; // ��������

public:
	// ����������� �� ���������
	TableElement(){}

	// ����������� � �����������
	TableElement(const std::string& key, const Polynomial& value)
	{
		_key = key;
		_value = value;
	}

	// ��������� �����
	std::string key() const
	{
		return _key;
	}

	// ��������� ������
	Polynomial value() const
	{
		return _value;
	}

	// ���������� ���������<
	friend bool operator<(const TableElement& te1, const TableElement& te2)
	{
		return te1.key() < te2.key();
	}

	// ���������� ���������==
	friend bool operator==(const TableElement& te1, const TableElement& te2)
	{
		return te1.key() == te2.key();
	}

	// ���������� ���������>
	friend bool operator>(const TableElement& te1, const TableElement& te2)
	{
		return te1.key() > te2.key();
	}
};

#endif /* TABLE_ELEMENT_H */
