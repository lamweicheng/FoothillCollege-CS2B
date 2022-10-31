#include <iostream>
#include "sequence.h"
#include <cassert>
using namespace std;


namespace cs_sequence
{
	Sequence::Sequence(){

		headPtr = NULL;
		cursor = NULL;
		tailPtr = NULL;
		precursor = NULL;
		numItems = 0;
	}






	void Sequence::start(){

		if (headPtr == NULL) {

			cursor = NULL;
			precursor = NULL;
		}
		else {

			cursor = headPtr;
			precursor = NULL;
		}
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







	void Sequence::insert(const value_type& entry){

		node* new_node = new node;
		new_node -> data = entry;
		numItems++;

		if (cursor == headPtr || cursor == nullptr) { 

			new_node -> next = headPtr;        
			headPtr = new_node;

			if (numItems == 1) {

				tailPtr = new_node;
			}
		}

		else {    

			new_node -> next = cursor;         
			precursor -> next = new_node;
		}

		cursor = new_node;
	}







	size_type Sequence::size()const{

		return numItems;
	}







	bool Sequence::is_item()const{

		return (cursor != NULL);
	}






	value_type Sequence::current()const{

		assert(is_item());
		return cursor->data;
	}
}







