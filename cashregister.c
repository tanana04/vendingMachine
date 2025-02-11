#include "cashregister.h"
#include "vending.h"
#include "dispenser.h"

int currentBalance(int balance, int payment)
{
    return balance - payment;
}

void acceptMoney(int selectedProduct, int quantity, Product *products, int balance, int payment)
{
    if (payment > balance)
    {
        for (int i = 0; i < quantity; i++)
        {
            products->pcs--;
        }
        printf("Success!\nYour change is: %d pesos", payment - balance);
        printf("\nPlease claim your item from the dispenser\n\n");
        getch();
        return;
    }
    for (int i = 0; i < quantity; i++)
    {
        products->pcs--;
    }
    printf("Success!");
    printf("\nPlease claim your item from the dispenser\n\n");
    getch();
    return;
}
