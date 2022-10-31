#include <iostream>
#include <string>
#include "orderedpair.h"

using namespace std;
using namespace cs_pairs;

int main() {

    string str1, str2;
    OrderedPair<string> myList2[10];
  

    cout << "default value: ";
    myList2[0].print();
    cout << endl;

    string strCandidate = "";
    for (int i = 0; i < 10; i++) {
        myList2[i].setFirst(strCandidate + char('a' + rand() % 26));
        myList2[i].setSecond(strCandidate + char('A' + rand() % 26));
    }

    myList2[2] = myList2[0] + myList2[1];

    if (myList2[0] < myList2[1]) {
        myList2[0].print();
        cout << " is less than ";
        myList2[1].print();
        cout << endl;
    }

    for (int i = 0; i < 10; i++) {
        myList2[i].print();
        cout << endl;
    }

    cout << "Enter two strings to use in an orderedPair.  Make sure they are different strings: ";
    cin >> str1 >> str2;
    OrderedPair<string> y;
    try {
        y.setFirst(str1);
        y.setSecond(str2);
    }
    catch (OrderedPair<string>::DuplicateMemberError e) {
        y.setFirst(strCandidate);
        y.setSecond(strCandidate);
    }
    cout << "The resulting orderedPair: ";
    y.print();
    cout << endl;
}

/*
default value: (, )
(p, H) is less than (q, G)
(p, H)
(q, G)
(pq, HG)
(m, E)
(a, Y)
(l, N)
(l, F)
(d, X)
(f, I)
(r, C)
Enter two strings to use in an orderedPair.  Make sure they are different strings: siii aiii
The resulting orderedPair: (siii, aiii)

(process 7912) exited with code 0.
Press any key to close this window . . .
*/