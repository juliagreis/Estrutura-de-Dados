#include "MyList.hpp"
#include <iostream>

int main(){
MyList<int> lista;
lista.pushback(1);
lista.pushback(2);
lista.pushfront(0);
lista.insert(3,0);
lista.insert(3,4);
lista.print();

return 0;
}