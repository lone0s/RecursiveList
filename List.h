//
// Created by jeune on 12/11/2022.
//

#pragma once

#include <iostream>
#include <stdexcept>
#include "Cell.h"

class List {
    Cell *top;
    int size;

    inline void pop() {

    }
public:
    List() : top(nullptr), size(0) {}; //Aka Nil
    List(int x, const List &list) : top(nullptr), size(0) {
        this->top = new Cell(x);
        this->top->setNext(list.top);
        size += (list.size + 1);
    }
    List(const List& list) : top(list.top), size(list.size) {};
    List& operator = (const List& list)  {
        if (this != &list) {
            this -> size = 0;
            this -> top = nullptr;
            Cell* copyCell = list.top;
            Cell* existingCell = this -> top;
            while (copyCell != nullptr) {
                existingCell = new Cell (copyCell -> getValue());
                ++size;
                copyCell = copyCell -> getNext();
                existingCell = existingCell -> getNext();
            }
        }
        return *this;
    }

    inline int head() const {
        if (this->size == 0)
            throw std::invalid_argument("Empty list, cannot get head of empty");
        return this->top->getValue();
    };

    inline bool empty() const { return (this->size == 0); };

    inline void tail() {
        if (this->size == 0)
            throw std::invalid_argument("Empty list, cannot get tail of empty");
        Cell *current = this->top;
        this->top = this -> top -> getNext();
        delete current;
        --size;
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
};

