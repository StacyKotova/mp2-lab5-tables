#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "hashnode.h"
#include <sstream>

// ��������� ������� ���-�������
const size_t SIZE = 100;

// ���-�������
struct KeyHash
{
	unsigned long operator()(const std::string& key) const
	{
		int sum = 0;
		for (char c : key)
			sum += (int)c;
		return sum % SIZE;
	}
};

// ����� ���-�������
template <typename K, typename V, typename F>
class HashTable
{
	HashNode<K, V> **table; // �������
	F function; // ���-�������

public:
	// ����������� ���-�������
	HashTable()
	{
		table = new HashNode<K, V>*[SIZE]();
	}

	bool existsKey(const K &key)
	{
		if (table[function(key)])
			return true;
		else
			return false;
	}

	// ����� �� ����� key � ������ � value
	bool get(const K &key, V &value)
	{
		// ���������� ���-��������
		unsigned long hashValue = function(key);
		HashNode<K, V> *entry = table[hashValue];

		int count = 0;
		while (entry)
		{
			count++;
			if (entry->key() == key) // ���� ������� ������
			{
				value = entry->value();
				std::cout << "���-������� - �������� ������: " << count << std::endl;
				return true;
			}
			entry = entry->next();
		}

		std::cout << "������� � ����� ������ �� ������\n";
		return false;
	}

	void add(const K &key, const V &value)
	{
		// ���������� ���-��������
		unsigned long hashValue = function(key);
		HashNode<K, V> *prev = NULL;
		HashNode<K, V> *entry = table[hashValue];

		// ���������� ���������� ��������
		int count = 1;
		while (entry && entry->key() != key)
		{
			prev = entry;
			entry = entry->next();
			count++;
		}

		// ��������� ������� (���������� ��� �������� ����)
		if (!entry)
		{
			entry = new HashNode<K, V>(key, value);
			if (prev == NULL)
				table[hashValue] = entry;
			else
				prev->setNext(entry);
		}
		else
			entry->setValue(value);

		std::cout << "���-������� - �������� ����������: "
			<< count << std::endl;
	}
};

#endif /* HASHTABLE_H */