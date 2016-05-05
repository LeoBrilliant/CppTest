/*
 * chtbl.h
 *
 *  Created on: 2016Äê2ÔÂ17ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef C_CHTBL_H_
#define C_CHTBL_H_

#include "List.h"

const int ELEMENT_FOUND = 0;
const int ELEMENT_NOT_FOUND = 1;

template<typename Key>
class ChainHashTable
{
public:
	ChainHashTable(){
		this->buckets = 0;
		this->h = NULL;
		this->match = NULL;
		this->destroy = NULL;
		this->size = 0;
		this->table = NULL;

		cout << "ChainHashTable Default Constructor" << endl;
	}

private:
	int buckets;

	int (*h)(const Key *key);
	int (*match)(const Key *key1, const Key *key2);
	void (*destroy)(Key *data);

	int size;

	List<Key> * table;

	int chtbl_init(int buckets, int (*h)(const Key *key),
			int (*match)(const Key *key1, const Key *key2),
			void (*destroy)(Key *data));

	void chtbl_destroy();

	int chtbl_insert(const Key *data);

	int chtbl_remove(Key **data);

	int chtbl_lookup(Key **data);

public:
	inline int Size() {return this->size;}

	void GetSummary()
	{
		cout << "Summary[" << endl;
		//cout << "empty: \t" << (this->Empty()? "True":"False") << "\t" << endl;
		cout << "size: \t" << this->Size() << endl;
		//cout << "max_size: \t" << this->MaxSize() << endl;
		cout << "]" << endl;
	}
public:
	void GetDetail(const string& s);

	static const enum ConstValue
	{
		ELEMENT_FOUND = 0,
		ELEMENT_NOT_FOUND = 1,
		SUCCESS = 0,
		FAILED = -1,
		EXCEPTION = -1
	} x ;
};

#endif /* C_CHTBL_H_ */
