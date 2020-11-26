#include <stdio.h>
#include "myBank.h"

double Accs[2][50];

void openAcc(double x) {
    int found = 0;
    int iterator = 0;
    while (found==0&&iterator<50){
        if (Accs[1][iterator]==0){
            Accs[1][iterator] = 1;
            Accs[0][iterator] = ((int)(x*100))/100.0; // save the amount with 2 digits only after the dot
            found = 1;
        } else {
            iterator++;
        }
    }
    if (found == 1) printf("%.2d\n", 901+iterator);
    else printf("no space to open a new account.\n");
}

void balance(int x) {
    if (x>950||x<901) { // check if x in range of accounts numbers
        printf("Out of account numbers range.\n");
        return;
    }
    if (Accs[1][x-901]==0) printf("this account isn't open.\n");
    else printf("%.2lf\n", Accs[0][x-901]);
}

void deposit(int acc, double amount){
    if (acc>950||acc<901||amount<0) { // check if acc in range of accounts numbers and amount is positive
        printf("Out of account numbers range or invalid amount input.\n");
        return;
    }
    if (Accs[1][acc-901]==0) printf("this account isn't open.\n");
    else {
        Accs[0][acc-901] = ((int)((Accs[0][acc-901]+amount)*100))/100.0; // save the amount with 2 digits only after the dot
        printf("%.2lf\n", Accs[0][acc-901]);
    }
}

void withdrawal(int acc, double amount){
    if (acc>950||acc<901||amount<0) { // check if acc in range of accounts numbers and amount is positive
        printf("Out of account numbers range or invalid amount input.\n");
        return;
    }
    if (Accs[1][acc-901]==0) printf("this account isn't open.\n");
    else {
        if (Accs[0][acc-901]-amount>=0){
            Accs[0][acc-901] = ((int)((Accs[0][acc-901]-amount)*100))/100.0; // save the amount with 2 digits only after the dot
            printf("%.2lf\n", Accs[0][acc-901]);
        } else {
            printf("There is not enough cash to withdraw.\n");
        }
    }
}

void closeAcc(int acc){
    if (acc>950||acc<901) { // check if acc in range of accounts numbers
        printf("Out of account numbers range.\n");
        return;
    }
    if (Accs[1][acc-901]==0) printf("this account is already closed.\n");
    else {
        Accs[1][acc-901] = 0;
    }
}

void addInterest(double interest){
    if (interest<0) {
        printf("invalid input.\n");
        return;
    }
    for (int i = 0; i<50; i++) {
        if (Accs[1][i]==1) {
            // save the amount with 2 digits only after the dot
            Accs[0][i] = ((int)((Accs[0][i]*(1+(interest/100)))*100))/100.0;
        }
    }
}
void printAllAccs() {
    printf("-----------------\n");
    for (int i = 0; i<50; i++) {
        if (Accs[1][i]==1) {
            printf("Account Number: %d\n", i+901);
            printf("Account Amount: %.2lf\n", Accs[0][i]);
            printf("\n");
        }
    }
    printf("-----------------");
}

void closeAllAccs() {
    for (int i = 0; i<50; i++) {
        if (Accs[1][i]==1) {
            Accs[1][i] = 0;
        }
    }
}