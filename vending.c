#include "vending.h"
#include "cashregister.h"
#include "dispenser.h"

void showSelection(Product products[4])
{
    printf("\n*** Welcome to Snack Shop ***\n");
    printf("To select an item, enter\n\n");
    printf("Products\tCost\t\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d for %s\t[Php %d]\n", i + 1, products[i].name, products[i].cost);
    }
    printf("5 to Exit\n");
}

void sellProduct(Product products[4])
{
    int selectedProduct, quantity, checkStock;
    showSelection(products);
    do
    {
        printf("\nPlease select an option: ");
        scanf("%d", &selectedProduct);
        if(selectedProduct == 5)
        {
            printf("Thank you for checking out!");
            getch();
            exit(0);
        }
        if(selectedProduct > 5)
        {
            printf("Invalid choice, please try again\n\n");
            getch();
            return;
        }
    }while(selectedProduct > 5);
    selectedProduct = selectedProduct - 1;
    checkStock = getCount(selectedProduct, &products[selectedProduct]);
    if(checkStock == 0)
    {
        printf("Sorry, there is not enough stock of this product\n\n");
        getch();
        system("cls");
    }
    printf("\nHow many?: ");
    scanf("%d", &quantity);
    int count = getCount(selectedProduct, &products[selectedProduct]);
    if(quantity <= count)
    {
        makeSale(selectedProduct, quantity, products);
    }
    else if(quantity > count)

    {
        printf("Sorry, there is not enough stock of this product\n\n");
        getch();
        system("cls");
    }
    getch();
    system("cls");
}

void showQuantity(Product products[4])
{
    FILE *fp = fopen("Quantity.txt", "r+");

    for(int i = 0; i < 5; i++)
    {
        fscanf(fp, "%s %d %d\n", products[i].name, &products[i].cost, &products[i].pcs);
    }
    fclose(fp);
}

void updateQuantity(Product products[4])
{
    FILE *fp = fopen("Quantity.txt", "w+");

    for(int i = 0; i < 4; i++)
    {
        fprintf(fp, "%s %d %d\n", products[i].name, products[i].cost, products[i].pcs);
    }
    fclose(fp);
}


