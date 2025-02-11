

#ifndef VENDING_H
#define VENDING_H

#include "dispenser.h"
#include "cashregister.h"

int getCount(int selectedProduct, Product *products);
int getProductCost(int selectedProduct, int quantity, Product *products);
void makeSale(int selectedProduct, int quantity, Product *products);


#endif

