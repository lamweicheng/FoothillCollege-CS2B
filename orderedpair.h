#ifndef ORDERED_PAIR
#define ORDERED_PAIR
#include <iostream>

/* precondition for setFirst and setSecond: the values of first and second cannot be equal,
except when they are both equal to DEFAULT_VALUE.
*/


namespace cs_pairs {
    template<class T>
    class OrderedPair {
    public:
        // Use the first of the following two lines to make the non-templated version work.
        // Use the second one when you begin converting to a templated version.
        class DuplicateMemberError {};
        static const T DEFAULT_VALUE;
        
        OrderedPair(T newFirst = DEFAULT_VALUE, T newSecond = DEFAULT_VALUE) 
            throw(DuplicateMemberError);
        void setFirst(T newFirst) throw(DuplicateMemberError);
        void setSecond(T newSecond) throw(DuplicateMemberError);
        T getFirst();
        T getSecond();
        OrderedPair operator+(const OrderedPair& right) ;
        bool operator<(const OrderedPair& right) ;
        void print();
    private:
        T first;
        T second;
    };

    // Leave the following const declaration commented out when you are testing the non-templated version.
    // Uncomment it when you begin converting to a templated version.

    // To convert to a templated version you will need a template prefix here above this declaration
  

}


#endif
