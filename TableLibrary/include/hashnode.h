#ifndef HASHNODE_H
#define HASHNODE_H

// ����� ���� ���-�������
template <typename K, typename V>
class HashNode
{
	K _key; // ����
	V _value; // ������
	HashNode *_next; // ��������� ����

public:
	// �����������
	HashNode(const K &key, const V &value)
	{
		_key = key;
		_value = value;
		_next = NULL;
	}

	// ��������� �����
	K key() const 
	{
		return _key;
	}

	// ��������� ������
	V value() const
	{
		return _value;
	}

	// ��������� ���������� ����
	HashNode* next() const
	{
		return _next;
	}

	// ��������� �����
	void setKey(const K &key)
	{
		_key = key;
	}

	// ��������� ������
	void setValue(const V &value)
	{
		_value = value;
	}

	// ��������� ���������� ����
	void setNext(HashNode *next)
	{
		_next = next;
	}

};

#endif /* HASHNODE_H */