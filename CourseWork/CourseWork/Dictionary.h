#pragma once

#ifndef DICTIONARY
#define DICTIONARY

#include <stdlib.h>
#include "String.h"

class Dictionary
{
public:
	Dictionary() :count_(0), head_(NULL), tail_(NULL) { };

	Dictionary(const Dictionary &obj);

	int count() const;

	String headItem() const;

	String &headItem();

	int& tailNumber();

	int tailNumber() const;

	String tailItem() const;

	String &tailItem();

	bool deleteHead();

	bool deleteTail();

	void insertItem(String item);

	bool searchItem(String item);

	String getNameOfProfession(int numberOfProfession) const;

	int getNumberOfProfession(String item);

	int& getNumberOfProfession(String item) const;

	void outAll();

	bool deleteElement(String item);

	virtual ~Dictionary(void);

private:
	struct Node
	{
		String nameOfProfession_;
		int numberOfProfession_;
		Node *next_;
		Node *prev_;

		Node(String nameOfProfession, Node *next = NULL, Node *prev = NULL) :
			nameOfProfession_(nameOfProfession), next_(next), prev_(prev) {}
	};

	int count_;
	Node *head_;
	Node *tail_;

	void increaseByOneValueOfNumberOfProfession(Node* item);

	void insertTail(String item);
	void insertHead(String item);

	void insertHead(Node *x);
	void insertTail(Node *x);
	void insertItem(Node* prevNode, Node* x, Node* nextNode);

	Node* searchNode(String item) const;
	Node* searchNode(int numberOfProfession) const;
	Node* searchPrevNode(String item);
};

#endif