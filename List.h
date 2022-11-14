//
// Created by jeune on 12/11/2022.
//

#pragma once

#include <iostream>
#include <stdexcept>
#include "Cell.h"

class List {



public:
    Cell *top;
    List() : top(nullptr) {}; //Aka Nil
    List(int x, const List &list) : top(nullptr) {
        this->top = new Cell(x);
        this->top->setNext(list.top);
    }
    explicit List(Cell* cell) : top(cell) {};

    List(const List& list) : top(list.top){};

    List& operator = (const List& list)  {
        if (this != &list) {
            if (!list.empty()) {
                this -> top = new Cell(list.top->getValue());
                Cell* current = this -> top;
                Cell* copyNext = list.top -> getNext();
                while (copyNext != nullptr) {
                    current ->setNext(new Cell(copyNext->getValue()));
                    copyNext = copyNext -> getNext();
                    current = current -> getNext();
                }
            }
        }
        return *this;
    }

    inline int head() const {
        if (this->top == nullptr)
            throw std::invalid_argument("Empty list, cannot get head of empty");
        return this->top->getValue();
    };

    inline bool empty() const { return (this->top == nullptr); };

    inline List tail() {
        if (this->top == nullptr)
            throw std::invalid_argument("Empty list, cannot get tail of empty");
        Cell *current = this->top;
        this->top = this -> top -> getNext();
        delete current;
        return *new List(*this);
    }

    inline friend std::ostream &operator<<(std::ostream &os, List& list) {
        os << "List : [" ;
        int cpt = 0;
        Cell* current = list.top;
        while (current != nullptr) {
            os << current->getValue();
            if (current -> getNext() != nullptr)
                os << ";" ;
            current = current -> getNext();
        }
        os << "]\n";
        return os;
    };

    void fillList(const int elements[] ,int nbElements);

    Cell* getLast() const {
      if (top != nullptr) {
          Cell* current = this -> top;
          while(current != nullptr)
              current = current -> getNext();
          return current;
      }
      return top;
    };

    //TD1 AA//

    friend int length(List list);
//    friend List append(int newVal,List list);
};

