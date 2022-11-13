//
// Created by jeune on 12/11/2022.
//

#pragma once


#include <stdexcept>
#include <iostream>

class Cell {
    int value;
    Cell* next;

public:
    explicit Cell(int val) : value(val), next(nullptr){} ;
    Cell(int val, Cell* next) : value(val), next(next) {};
//    ~Cell() = default;
    ~Cell() {};
    inline int getValue() const {return this->value;};
    inline void setValue(int val) {this -> value = val;};
    inline Cell* getNext() const {return this -> next;};
    inline void setNext(Cell* newNext) {this -> next = newNext;};

    friend int length (Cell* cell) {
        if (cell == nullptr)
            return 0;
        else
            return 1 + length(cell->getNext());
    };

    friend void append (int val, Cell* cell) {
        if (cell == nullptr) {
            cell = new Cell(val);
        }
        else if (cell->next == nullptr) {
            cell ->setNext(new Cell(val));
        }
        else
            append(val,cell -> getNext());
    }

    friend bool has_length(Cell* cell,int k) {
//        if (cell == nullptr && k != 0) {
//            return false;
//        }
//        else if (cell == nullptr && k == 0) {
//            return true;
//        }
//        has_length(cell -> next,k-1);

        if ((cell == nullptr && k == 0)) {
            return true;
        }
        else if (cell == nullptr && k != 0) {
            return false;
        }
        else if (cell -> next != nullptr && k == 0) {
            return true;
        }
        else if (cell -> next == nullptr && k != 0) {
            return false;
        }
        has_length(cell -> getNext(), k-1);
    }

    friend void concat(Cell* l1, Cell* l2) {
        if (l1 == nullptr) {
            l1 = l2;
        }
        else if (l1->next == nullptr) {
            l1 ->setNext(l2);
        }
        else
            concat(l1 -> getNext(), l2);
    }

    friend void reverse(Cell* l) {};

//    friend void reverseAux (Cell* auxList, Cell* list) {
//        if (list == nullptr) {
//            return;
//        }
//        if (list -> next == nullptr) {
//            if (auxList == nullptr) {
//                auxList = new Cell(list->value);
//            }
//            else {
//                auxList ->setNext()
//            }
//        }
//    }

    friend int get(Cell* l, int k) {
        if (l == nullptr || k < 0) {
            throw std::invalid_argument("Incorrect 2nd argument");
        }
        else if (k == 0) {
            return  l->value;
        } else
            return get(l -> getNext(),--k);
    }

    friend Cell* getUnevenIndex(Cell* l) {
        if (l == nullptr) {
            return l;}
        else
            return getUnevenIndexAux(l,nullptr,0);
    }

    friend Cell* getUnevenIndexAux(Cell* l, Cell* aux, int cpt) {
        if (l == nullptr) {
            return aux;
        }
        else if (cpt % 2 == 0) {
            if(aux == nullptr) {
                aux = new Cell(l->value);
            } else {
                aux->setNext(new Cell(l -> value));
                getUnevenIndexAux(l-> getNext(),aux -> getNext(),++cpt);
            }
        }
        getUnevenIndexAux(l->getNext(),aux,++cpt);
    }
};

