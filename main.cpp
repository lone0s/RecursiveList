#include <iostream>
#include "List.h"

using namespace std;
int main() {
    List a;
    List b(5,a);
    List c(4,b);
    List d(3,c);
    cout << d ;


}
