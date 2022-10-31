#ifndef sequence_h
#define sequence_h
#include <iostream>

namespace cs_sequence
{
	typedef int value_type;
	typedef unsigned int size_type;

	typedef struct node_type{

		value_type data;
		struct node_type* next;
	}node;

	class Sequence
	{
	private:
		node* headPtr;
		node* cursor;
		node* tailPtr;
		node* precursor;
		size_type numItems;
	
	public:
		Sequence();
		void start();
		void advance();
		void insert(const value_type& entry);
		//void attach(const value_type& entry);
		//void remove_current();
		size_type size() const;
		bool is_item() const;
		value_type current() const;
	};
}
#endif