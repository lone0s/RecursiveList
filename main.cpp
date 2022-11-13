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

    List x;
    x.top = getUnevenIndex(f.top);
    cout << f;
    cout << x ;
}
