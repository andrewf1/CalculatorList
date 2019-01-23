#include "CalcList.hpp"

CalcList::CalcList() {
    total_val = 0.0;
    header = new CalcListNode;
    trailer = new CalcListNode;
    header->next = trailer;
    trailer->prev = header;
    size = 0;
}

CalcList::~CalcList() {
    while(!empty()) {
        removeLastOperation();
    }
    delete trailer;
    delete header;
}

void CalcList::newOperation(const FUNCTIONS func, const double operand) {
    CalcListNode* new_operation = new CalcListNode;
    new_operation->operation = func;
    new_operation->operand = operand;
    if(empty()) {
        header->next = new_operation;
        new_operation->prev = header;
        new_operation->next = trailer;
        trailer->prev = new_operation;
    }
    else {
        new_operation->next = trailer;
        new_operation->prev = trailer->prev;
        trailer->prev->next = new_operation;
        trailer->prev = new_operation;
    }
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
            if(operand == 0) throw("DivideByZero");
            total_val /= operand;
            break;
    }
    new_operation->node_total = total_val;
    size++;
}

void CalcList::removeLastOperation() {\
    if(empty())
        throw("CannotRemoveFromEmptyList");
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
    oSS << getOperationString(size, trailer->prev, precision);
    return oSS.str();
}   

std::string CalcList::getOperationString(unsigned int length, const CalcListNode* node, unsigned short prec) const{
    char op;
    switch(node->operation) {
        case ADDITION:
            op = '+';
            break;
        case SUBTRACTION:
            op = '-';
            break;
        case MULTIPLICATION:
            op = '*';
            break;
        case DIVISION:
            op = '/';
            break;
    }
    std::string op_strings = "";
    std::ostringstream oSS;
    if(node->prev == header) {
        double zero = 0.0000000000000000000000000000000000000000000000;
        oSS << "1: " << std::setprecision(prec) << std::fixed << zero << ' ' << op << ' ' << node->operand << " = " << node->node_total;
        oSS << std::endl;
        op_strings += oSS.str();
        return op_strings;
    }
    else {
        oSS << length << ": " << std::setprecision(prec) << std::fixed;
        oSS << node->prev->node_total << ' ' << op << ' ' << std::setprecision(prec) << std::fixed;
        oSS << node->operand << " = " << std::setprecision(prec) << std::fixed;
        oSS << node->node_total << std::endl;
        op_strings += oSS.str();
        return op_strings += getOperationString(length - 1, node->prev, prec);
    }
}

// int main() {
    
//     CalcList newList;
//     newList.newOperation(ADDITION, 10);
//     newList.newOperation(MULTIPLICATION, 10);
//     newList.newOperation(DIVISION, 5);
//     newList.newOperation(SUBTRACTION, 5);
//     std::cout << "total = " << newList.total() << std::endl;
//     std::cout << newList.toString(2);
//     newList.removeLastOperation();
//     std::cout << std::endl;
//     std::cout << newList.toString(2);
//     return 0;    
// }