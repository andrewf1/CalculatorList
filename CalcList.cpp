#include "CalcList.hpp"

CalcList::CalcList() {
    header = new CalcListNode;
    trailer = new CalcListNode;
    header->next = trailer;
    trailer->prev = header;
    total_val = 0.0;
}

// void CalcList::newOperation(const FUNCTIONS func, const double operand) {
//     CalcListNode* new_operation = new CalcListNode;
//     new_operation->operation = func;
//     header->next = new_operation;
//     trailer->prev = new_operation;
//     if(empty()) {
//         new_operation->next = trailer;
//         new_operation->prev = header;
//     }
//     else {
//         //connect to the end of the list
//         trailer->next = new_operation;
//     }
//         switch(func) {
//             case ADDITION:
//                 total_val += operand;
//                 break;
//             case SUBTRACTION:
//                 total_val -= operand;
//                 break;
//             case MULTIPLICATION:
//                 total_val *= operand;
//                 break;
//             case DIVISION:
//                 total_val /= operand;
//                 break;
//             default:

//         }
//         new_operation->node_total = total_val;
// }