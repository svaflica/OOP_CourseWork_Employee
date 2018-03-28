#include "stdafx.h"
#include "Dictionary.h"


Dictionary::Dictionary(const Dictionary &obj)
{
	Node* temp = obj.head_->next_;

	insertHead(obj.head_);
	for (int i = 1; i < obj.count_; i++)
	{
		this->insertTail(temp);
		temp = temp->next_;
	}
}


int
Dictionary::count() const
{
	return count_;
}


String
Dictionary::headItem() const
{
	return head_->nameOfProfession_;
}


String&
Dictionary::headItem()
{
	return head_->nameOfProfession_;
}


String
Dictionary::tailItem() const
{
	return tail_->nameOfProfession_;
}

int& 
Dictionary::tailNumber()
{
	return tail_->numberOfProfession_;
}

int 
Dictionary::tailNumber() const
{
	return tail_->numberOfProfession_;
}


String&
Dictionary::tailItem()
{
	return tail_->nameOfProfession_;
}


void
Dictionary::insertTail(String item)
{
	insertTail(new Node(item));

}


void
Dictionary::insertHead(String item)
{
	insertHead(new Node(item));
}


bool
Dictionary::deleteHead()
{
	if (head_ == NULL)
		return false;

	if (head_->next_ != NULL) {
		(head_->next_)->prev_ = NULL;
		delete head_;
		head_ = head_->next_;
	}
	else {
		if (head_ != NULL)
			delete head_;

		if (tail_ != NULL)
			delete tail_;
	}

	count_--;

	return true;
}


bool
Dictionary::deleteTail()
{
	if (tail_ == NULL)
		return false;

	if (tail_->prev_ != NULL) {
		(tail_->prev_)->next_ = NULL;
		delete tail_;
		tail_ = tail_->prev_;
	}
	else {
		if (head_ != NULL)
			delete head_;

		if (tail_ != NULL)
			delete tail_;
	}

	count_--;

	return true;
}


bool
Dictionary::deleteElement(String item)
{
	Node* i = searchNode(item);

	if (i == NULL)
		return false;

	(i->prev_)->next_ = i->next_;
	(i->next_)->prev_ = i->prev_;

	count_--;

	delete i;

	return true;
}


bool
Dictionary::searchItem(String item)
{
	Node* i = head_;

	while (i != NULL)
	{
		if (i->nameOfProfession_ == item)
			return true;

		i = i->next_;
	}

	return false;
}


void
Dictionary::outAll()
{
	Node* i = head_;

	while (i != tail_)
	{
		cout << i->nameOfProfession_ << ' ';
		cout << "id: " << i->numberOfProfession_ << '\n';
		i = i->next_;
	}

	cout << tail_->nameOfProfession_ << '\n';
}


Dictionary::~Dictionary()
{
	while (deleteHead() == true);
}


void
Dictionary::insertTail(Node *x)
{
	x->prev_ = tail_;

	if (tail_ != NULL)
		tail_->next_ = x;
	else
		head_ = x;

	tail_ = x;

	tail_->numberOfProfession_ = ++count_;
}


void
Dictionary::insertHead(Node *x)
{
	x->next_ = head_;
	if (head_ != NULL)
		head_->prev_ = x;
	else
		tail_ = x;

	head_ = x;

	head_->numberOfProfession_ = ++count_;
}

void
Dictionary::insertItem(String item)
{
	Node* temp = searchPrevNode(item);

	if (temp == NULL)
		insertHead(item);
	else if (temp == tail_)
		insertTail(item);
	else
		insertItem(temp, new Node(item), temp->next_);
}

void
Dictionary::insertItem(Node* prevNode, Node* x, Node* nextNode)
{
	x->next_ = nextNode;
	x->prev_ = prevNode;
	x->numberOfProfession_ = ++count_;

	prevNode->next_ = x;
	nextNode->prev_ = x;
}

//void 
//Dictionary::increaseByOneValueOfNumberOfProfession(Node* item)
//{
//	while (item != NULL)
//	{
//		item->numberOfProfession_++;
//		item = item->next_;
//	}
//}

Dictionary::Node*
Dictionary::searchNode(String item) const
{
	Node* i = head_;

	while (i != NULL)
	{
		if (i->nameOfProfession_ == item)
			return i;

		i = i->next_;
	}

	return i;

}

Dictionary::Node*
Dictionary::searchNode(int numberOfProfession) const
{
	Node* i = head_;

	while (i != NULL)
	{
		if (i->numberOfProfession_ == numberOfProfession)
			return i;

		i = i->next_;
	}

	return i;

}

Dictionary::Node*
Dictionary::searchPrevNode(String item)
{
	Node* i = head_;

	if (head_ == NULL || i->nameOfProfession_ <= item)
		return NULL;

	while (i->next_ != NULL)
	{
		if (i->nameOfProfession_ <= item && item <= (i->next_)->nameOfProfession_)
			return i;

		i = i->next_;
	}

	return i;

}

int 
Dictionary::getNumberOfProfession(String item)
{
	return searchNode(item)->numberOfProfession_;
}

String 
Dictionary::getNameOfProfession(int numberOfProfession) const
{
	return searchNode(numberOfProfession)->nameOfProfession_;
}