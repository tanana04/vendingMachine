#ifndef CASHREGISTER_H
#define CASHREGISTER_H

#include "vending.h"

int currentBalance(int balance, int payment);
void acceptMoney(int selectedProduct, int quantity, Product *products, int balance, int payment);

#endif
