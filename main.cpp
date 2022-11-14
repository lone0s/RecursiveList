#include <iostream>
#include "List.h"

using namespace std;
int main() {
//    List a;
//    List b(5,a);
//    List c(4,b);
//    List d(3,c);
//    List x;
//    cout << "/// Tests d ///\n";
//    cout << d ;
//    x = d.tail();
//    cout << x ;
//    x.top->setValue(10);
//    cout << x;
//    x.top->setValue(18);
//    cout << x ;
//    cout << d;

//    cout << "// Test fill list //";
    List f,g;
    int valuesF[10] {5, 7, -5, 3, 56, 12, 96, 45, 12, 90};
    int valuesG [3] {-3,-2,-1};
    f.fillList(valuesF, 10);
    g.fillList(valuesG,3);
//    cout << f ;
//
//    cout << length(f);
//
//    append(5,f);
//    cout << f;
//    cout << length(f.top) << endl;
//    append(-1,f.top);
//    cout << f;
//    string res = has_length(f.top,10) ? "True\n" : "False\n";
//    cout << res;
//    concat(f.top,g.top);
//    cout << f;
//    cout << get(f.top,9);
    cout << "Append bis\n";
    List res (appendBis(-10,g.top));
    cout << g ;
    cout << res;
    cout << "Fin append bis\n";
    List x;
    x.top = getUnevenIndex(f.top);
    cout << "Reverse func\n";
    List rev (reverse(x.top));
    cout << rev;
    cout << x;
    List duplique(dupliquer(x.top));
    cout << x ;
    cout << duplique;
    cout << x ;
//    cout << "Uneven indexes\n";
//    List uneven (getUnevenIndexes(f.top));
//    cout << uneven;

    cout << "Even indexes\n";
    cout << f;
    List even(getEvenIndexes(f.top));
    cout << even;
    List uneven(getEvenIndexes(f.top -> getNext()));
    cout << uneven;

    cout << "Reverse Linear Complexity\n";
    List reversedLinear(reverseLinear(f.top));
    cout << f ;
    cout << reversedLinear;

    List a;
    List b;
    int val[3] {1,2,3};
    int val2[3] {1,4,5};
    a.fillList(val,3);
    b.fillList(val2,3);

    List concatOrdered (concatOrderedLists(a.top,b.top));
    cout << "Ordered : \n";
    cout << a ;
    cout << b;
    cout << concatOrdered;

    List c;
    int valDup[6] {1,1,1,2,2,3};
    c.fillList(valDup,6);
    cout << c;
    List d (removeDuplicates(c.top));
    cout << d ;
}
