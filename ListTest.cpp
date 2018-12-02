/*
 * ListTest.cpp
 *
 *  Created on: 2016年10月2日
 *      Author: LeoBrilliant
 */

#include <list>
#include <iostream>

using namespace std;

struct Node{
	struct Node * parent;
	struct Node * sibling;
	struct Node * son;
	int Volume;
	int VolumeLeft;
	bool visited;
};

typedef struct Node Node;


void ListTest()
{
	list<int> li;
	li.push_back(1);
	li.push_back(2);
	li.push_back(3);

	cout << li.front() << endl;

	int i = li.front();

	cout << i << endl;

	Node * n = new Node;
	n->Volume = i;
	n->son = NULL;

	list<Node*> ln;
	ln.push_back(n);

	Node * n2 = ln.front();

	delete n2;

}

