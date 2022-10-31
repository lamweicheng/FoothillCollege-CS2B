#include <iostream>
#include "orderedpair.h"
using namespace std;

namespace cs_pairs {
    template<class T>
    OrderedPair<T>::OrderedPair(T newFirst, T newSecond) throw(DuplicateMemberError) {
        setFirst(newFirst);
        setSecond(newSecond);
    }

    template<class T>
    void OrderedPair<T>::setFirst(T newFirst) throw(DuplicateMemberError) {
        // if statement to throw an exception if precondition not met goes here. 
        if (newFirst == second && newFirst != DEFAULT_VALUE) {
            throw DuplicateMemberError();
        }
        first = newFirst;
    }

    template<class T>
    void OrderedPair<T>::setSecond(T newSecond) throw(DuplicateMemberError) {
        // if statement to throw an exception if precondition not met goes here.
        if (newSecond == first && newSecond != DEFAULT_VALUE) {
            throw DuplicateMemberError();
        }
        second = newSecond;
    }

    template<class T>
    T OrderedPair<T>::getFirst() {
        return first;
    }

    template<class T>
    T OrderedPair<T>::getSecond() {
        return second;
    }

    template <class T>
    OrderedPair<T> OrderedPair<T>::operator+(const OrderedPair& right) {
        return OrderedPair(first + right.first, second + right.second);
    }

    template<class T>
    bool OrderedPair<T>::operator<(const OrderedPair& right) {
        return first + second < right.first + right.second;
    }

    template<class T>
    void OrderedPair<T>::print() {
        cout << "(" << first << ", " << second << ")";
    }

    
    template <class T>
    const T OrderedPair<T>::DEFAULT_VALUE = T();
    template class OrderedPair<string>;

}