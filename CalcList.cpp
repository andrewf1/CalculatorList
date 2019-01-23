#include "CalcList.hpp"
#include <iostream>

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
    new_operation->operand = operand;
    new_operation->next = trailer;
    new_operation->prev = trailer->prev;
    trailer->prev = new_operation;
    trailer->prev->next = trailer->prev;
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
    CalcListNode* node_to_remove = trailer->prev;
    //Do the opposite operation to restore previous total_val
    switch(node_to_remove->operation) {
        case ADDITION:
            total_val -= node_to_remove->operand;
            break;
        case SUBTRACTION:
            total_val += node_to_remove->operand;
            break;
        case MULTIPLICATION:
            total_val /= node_to_remove->operand;
            break;
        case DIVISION:
            total_val *= node_to_remove->operand;
            break;
    }
    CalcListNode* prev_node = node_to_remove->prev;
    CalcListNode* next_node = trailer;
    prev_node->next = next_node;
    trailer->prev = prev_node;
    delete node_to_remove;
}

int main() {
    
    CalcList newList;
    newList.newOperation(ADDITION, 10);
    std::cout << "TOTAL = " << newList.total() << std::endl;
    newList.newOperation(MULTIPLICATION, 100);
    std::cout << "TOTAL = " << newList.total() << std::endl;
    newList.removeLastOperation();
    std::cout << "TOTAL = " << newList.total() << std::endl;

    return 0;    
}