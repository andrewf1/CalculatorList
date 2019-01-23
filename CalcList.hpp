#ifndef CALCLIST_HPP
#define CALCLIST_HPP

#include "CalcListInterface.hpp"
#include <string>
#include <sstream>
#include <iomanip>

class CalcListNode {
public:
    CalcListNode() = default;
    ~CalcListNode() = default;
private:
    CalcListNode* prev;
    CalcListNode* next;
    FUNCTIONS operation;
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
    virtual std::string toString(unsigned short precision) const override { return "hi"; }
    bool empty() { return header->next == trailer; }
private:
    CalcListNode* header;
    CalcListNode* trailer;
    double total_val;
};


#endif /* CALCLIST_HPP */