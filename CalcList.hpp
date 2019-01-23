#ifndef CALCLIST_HPP
#define CALCLIST_HPP

#include <string>
#include <sstream>
#include <iomanip>
#include "CalcListInterface.hpp"

class CalcListNode {
public:
    CalcListNode() = default;
    ~CalcListNode() = default;
private:
    CalcListNode* prev;
    CalcListNode* next;
    FUNCTIONS operation;
    double node_total;
    double operand;
friend class CalcList;
};

class CalcList : public CalcListInterface {
public:
    CalcList();
    ~CalcList();
    virtual double total() const override { return total_val; }
    virtual void newOperation(const FUNCTIONS func, const double operand) override;
    virtual void removeLastOperation() override;
    virtual std::string toString(unsigned short precision) const override;
    bool empty() { return header->next == trailer; }
    std::string getOperationString(unsigned int length, const CalcListNode* node, unsigned short prec) const;
private:
    unsigned int size;
    CalcListNode* header;
    CalcListNode* trailer;
    double total_val;
};


#endif /* CALCLIST_HPP */