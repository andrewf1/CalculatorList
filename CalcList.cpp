#include "CalcList.hpp"

CalcList::CalcList() {
    total_val = 0.0;
    header = new CalcListNode;
    trailer = new CalcListNode;
    header->next = trailer;
    trailer->prev = header;
    total_val = 0.0;
}

CalcList::~CalcList() {

}

void CalcList::newOperation(const FUNCTIONS func, const double operand) {
    CalcListNode* new_operation = new CalcListNode;
    new_operation->operation = func;
    new_operation->next = trailer;
    new_operation->prev = trailer->prev;
    trailer->prev->next = trailer->prev = new_operation;
    switch(func) {
        case ADDITION:
            total_val += operand;
            break;
        case SUBTRACTION:
            total_val -= operand;
            break;
        case MULTIPLICATION:
            total_val *= operand;
            break;
        case DIVISION:
            total_val /= operand;
            break;
    }
}

void CalcList::removeLastOperation() {

}