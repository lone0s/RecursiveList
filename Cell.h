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
    Cell* Construct(int val, Cell* next) {
        Cell* temp = new Cell(val);
        temp -> value = val;
        temp->next = next;
    }
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

    friend Cell* appendBis (int val, Cell* cell) {
        if (cell == nullptr) {
            return new Cell(val);
        }
        else
            return new Cell(cell->getValue(),appendBis(val,cell->getNext()));
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

    friend Cell* reverse(Cell* l) {
        if (l == nullptr) {
            return l;
        }
        else {
            append(l->getValue(),reverse(l->getNext()));
        }
    };

    friend Cell* getEvenIndexes(Cell* list) {
        if (list == nullptr || list -> getNext() == nullptr) {
            return list;
        }
        return new Cell(list->value, getEvenIndexes(list -> getNext() -> getNext()));
    }

    friend Cell* getUnevenIndexes(Cell* l, int cpt = 0) {
        if (l == nullptr)
            return l;
        else if (cpt % 2 == 0) {
            new Cell(l->value,getUnevenIndexes(l->getNext(),++cpt));
        }
    }

    friend Cell* dupliquer(Cell* list) {
        if (list == nullptr) {
            return list;
        }
        else
            return new Cell(list -> getValue(), new Cell(list -> getValue(),dupliquer(list->getNext())));
    }

    friend Cell* reverseLinear(Cell* list) {
        if (list == nullptr || list -> getNext() == nullptr) {
            return list;
        }
        return reverseAux(list,nullptr);
    }

    friend Cell* reverseAux(Cell* l1, Cell* l2) {
        if (l1 == nullptr)
            return l2;
        return reverseAux(l1 -> next,new Cell(l1->value,l2));
    }
//    friend void dupliquerProcedure (Cell* list ) {
//        if (list == nullptr)
//            return;
//        else {
//            list ->setNext(new Cell(list -> getValue(),new Cell(list -> getValue(),dupliquerProcedure(list->getNext()))));
//        }
//    }



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

    friend Cell* concatOrderedLists(Cell* l1, Cell* l2) {
        if (l2 == nullptr) {
            return l1;
        }
        else if (l1 == nullptr) {
            return l2;
        }
        else if (l1->value <= l2 -> value) {
            return new Cell(l1 -> value, concatOrderedLists(l1 -> next, l2));
        }
        else
            return new Cell(l2 -> value, concatOrderedLists(l2->next,l1));
    }

    friend Cell* removeDuplicates(Cell* list)
    {
        return new Cell(list -> value, remDupAux(list->value,list -> next));
    }

    friend Cell* remDupAux(int i, Cell* list ) {
        if (list == nullptr) {
            return list;
        }
        else if(list -> value == i)
            remDupAux(i,list -> next);
        else
        return new Cell (list -> value,remDupAux(list -> value,list->next));
    }

};

