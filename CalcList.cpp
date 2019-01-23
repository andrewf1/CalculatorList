#include "CalcList.hpp"

CalcList::CalcList() {
    total_val = 0.0;
    header = new CalcListNode;
    trailer = new CalcListNode;
    header->next = trailer;
    trailer->prev = header;
    total_val = 0.0;
    size = 0;
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
    new_operation->node_total = total_val;
    size++;
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
    size--;
    delete node_to_remove;
}

//Have to implement set precision to the string still!!
std::string CalcList::toString(unsigned short precision) const {
    std::ostringstream oSS;
    auto length = size;
    oSS << getOperationString(length, trailer->prev);
    return oSS.str();
}   

std::string CalcList::getOperationString(unsigned int length, const CalcListNode* node) const{
    std::string op_strings;
    std::ostringstream oSS;
    if(node == header->next) {
        oSS << "1: 0 " << node->operation << ' ' << node->operand << " = " << node->node_total;
        oSS << std::endl;
        op_strings += oSS.str();
        return op_strings;
    }
    else {
        oSS << length << ": " << node->prev->node_total << ' ' << node->operation << ' ';
        oSS << node->operand << " = " << node->node_total << std::endl;
        op_strings += oSS.str();
        return op_strings + getOperationString(length - 1, node->prev);
    }
}

int main() {
    
    CalcList newList;
    newList.newOperation(ADDITION, 10);
    newList.newOperation(MULTIPLICATION, 10);
    newList.newOperation(DIVISION, 5);
    newList.newOperation(SUBTRACTION, 5);
    std::cout << newList.toString(2);
    newList.removeLastOperation();
    std::cout << newList.toString(2);
    return 0;    
}