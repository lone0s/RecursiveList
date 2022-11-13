//
// Created by jeune on 12/11/2022.
//

#include "List.h"

void List::fillList(const int elements[] ,int nbElements ) {
//    int cpt = 0;
//    Cell* last = this -> top;
//    Cell* before = nullptr;
//    while (last != nullptr) {
//        before = last;
//        last = last -> getNext();
//    }
//    last = new Cell(elements[cpt]);
//    last = last -> getNext();
//    cpt++;
//    while(cpt < nbElements) {
//        last = new Cell(elements[cpt]);
//        before = last;
//        last = last -> getNext();
//        cpt++;
//    }
    int cpt = 0;
    if (this -> top == nullptr) {
        this -> top = new Cell(elements[cpt]);
        ++cpt;
    }
    Cell* current = this -> top;
    Cell* next = this -> top -> getNext();
    //Si liste pas vide
    while (next != nullptr) {
        current = current -> getNext();
        next = next -> getNext();
    }
    //Mtn on add
    while(cpt < nbElements){
        next = new Cell(elements[cpt]);
        current ->setNext(next);
        current = current -> getNext();
        next = next->getNext();
        ++cpt;
    }
}

int length(List list) {
    if (list . top == nullptr)
        return 0;
    else
        return 1 + length(list . tail());
}

//List append(int newVal, List list) {
//}



