#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

typedef struct
{
    char name[50];
    int cost;
    int pcs;
} Product;

void showSelection(Product products[4]);
void sellProduct(Product products[4]);
void showQuantity(Product products[4]);
void updateQuantity(Product products[4]);

#endif
