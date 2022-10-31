#ifndef sequence2_h
#define sequence2_h
#include <iostream>


namespace cs_sequence
{
	typedef int value_type;
	typedef unsigned int size_type;


	typedef struct node_type
	{
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
		void copy(const Sequence& cloneMe);
		void clear();
	public:
		Sequence();
		void start();
		void advance();
		void insert(const value_type& entry);
		size_type size() const;
		bool is_item() const;
		value_type current() const;


		~Sequence();
		Sequence(const Sequence& cloneMe);
		Sequence operator=(const Sequence& right);
		void attach(const value_type& entry);
		void remove_current();

	};
}
#endif