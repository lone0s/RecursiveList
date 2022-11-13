//
// Created by jeune on 12/11/2022.
//

#pragma once


class Cell {
    int value;
    Cell* next;

public:
    explicit Cell(int val) : value(val), next(nullptr){} ;
//    ~Cell() = default;

    inline int getValue() const {return this->value;};
    inline Cell* getNext() const {return this -> next;};
    inline void setNext(Cell* newNext) {this -> next = newNext;};
};

