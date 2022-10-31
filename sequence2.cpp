#include <iostream>
#include "sequence2.h"
#include <cassert>
using namespace std;


namespace cs_sequence{

	Sequence::Sequence(){

		headPtr = NULL;
		cursor = NULL;
		tailPtr = NULL;
		precursor = NULL;
		numItems = 0;
	}







	void Sequence::start(){

		cursor = headPtr;
		precursor = NULL;
	}






	void Sequence::advance(){

		assert(is_item());
		if (cursor->next != NULL){

			precursor = cursor;
			cursor = cursor->next;
		}
		else
			cursor = NULL;
	}






	size_type Sequence::size()const{

		return numItems;
	}






	value_type Sequence::current()const{

		assert(is_item());
		return cursor->data;
	}







	bool Sequence::is_item()const{

		return (cursor != NULL);
	}






	void Sequence::insert(const value_type& entry) {

		node* new_node = new node;
		new_node->data = entry;
		numItems++;

		if (cursor == headPtr || cursor == nullptr) { // insert at front (or into empty list).
			new_node->next = headPtr;                 // precursor remains nullptr.
			headPtr = new_node;
			if (numItems == 1) {
				tailPtr = new_node;
			}
		}
		else {                                       // inserting anywhere else
			new_node->next = cursor;                   // tailPtr, headPtr and precursor don't change.
			precursor->next = new_node;
		}

		cursor = new_node;
	}









	void Sequence::copy(const Sequence& cloneMe){

		if (cloneMe.headPtr == NULL) 
			headPtr = NULL;

		else {

			numItems = 1;

			headPtr = new node;
			headPtr->data = cloneMe.headPtr->data;

			node* newNode = headPtr;
			node* sourcePtr = cloneMe.headPtr->next;

			cursor = headPtr;

			while (sourcePtr != NULL) {

				newNode->next = new node;
				newNode = newNode->next;
				newNode->data = sourcePtr->data;

				if (cloneMe.cursor != NULL) {

					if (sourcePtr == cloneMe.cursor)
						cursor = newNode;
				}
				else
					cursor = NULL;

				sourcePtr = sourcePtr->next;
				numItems++;
			}
			newNode->next = NULL;
		}

	}






	void Sequence::clear(){

		node* newNode = headPtr;

		while (newNode != NULL){

			newNode = newNode->next;
			delete headPtr;
			headPtr = newNode;
		}
		numItems = 0;
	}






	Sequence::~Sequence(){

		clear();
	}






	Sequence::Sequence(const Sequence& cloneMe){

		copy(cloneMe);
	}






	Sequence Sequence::operator=(const Sequence& right){

		if (this != &right) {

			clear();
			copy(right);
		}
		return *this;
	}







	void Sequence::attach(const value_type& entry){

		node* newNode = new node;
		newNode->data = entry;
		newNode->next = NULL;
		numItems++;

		if (headPtr == NULL)
			headPtr = newNode;
		

		else if (cursor == NULL){

			tailPtr->next = newNode;
			precursor = tailPtr;
		}

		else{

			newNode->next = cursor->next;
			precursor = cursor;
			precursor->next = newNode;
			if (newNode->next == NULL)
				tailPtr = newNode;
		}
		cursor = newNode;

	}






	void Sequence::remove_current()
	{
		if (precursor == NULL){

			headPtr = cursor->next;
			numItems--;
			cursor = headPtr;
		}

		else{

			precursor->next = cursor->next;
			numItems--;

			if (precursor == NULL)
				start();
			else
				cursor = precursor->next;
		}
		
	}
}

