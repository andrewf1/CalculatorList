#ifndef CALCLIST_HPP
#define CALCLIST_HPP

#include "CalcListInterface.hpp"

struct CalcListNode {
    CalcListNode() = default;
    ~CalcListNode() = default;
    CalcListNode* prev;
    CalcListNode* next;
    FUNCTIONS operation;
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
private:
    CalcListNode* header;
    CalcListNode* trailer;
    double total_val;
};


#endif /* CALCLIST_HPP*/