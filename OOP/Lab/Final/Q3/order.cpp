#include "order.h"

    Order::Order(bool stat){
        this->status = stat;
    }
    Order::~Order(){

    }
    bool Order::getstat(){
        return this->status;
    }
    void setstat(bool x){
        this->stat = x;
    }