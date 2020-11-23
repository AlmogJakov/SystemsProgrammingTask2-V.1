#include <stdio.h>
#include "myBank.h"

int main()
{
    char option;
    double amount;
    double interest;
    int accNum;
    int bool = 1;
    while(bool==1){
            printf("Transaction type?\n");
            scanf(" %c", &option);
        if (option=='O'){
            printf("Initial deposit?:\n");
            scanf(" %lf", &amount);
            openAcc(amount);
        } else if (option=='B') {
            printf("Account number?:\n");
            scanf(" %d", &accNum);
            balance(accNum);
        } else if (option=='D') {
            printf("Account number?:\n");
            scanf(" %d", &accNum);
            printf("Amount?:\n");
            scanf(" %lf", &amount);
            deposit(accNum, amount);
        } else if (option=='W') {
            printf("Account number?:\n");
            scanf(" %d", &accNum);
            printf("Amount?:\n");
            scanf(" %lf", &amount);
            withdrawal(accNum, amount);
        } else if (option=='C') {
            printf("Account number?:\n");
            scanf(" %d", &accNum);
            closeAcc(accNum);
        } else if (option=='I') {
            printf("Interest rate?:\n");
            scanf(" %lf", &interest);
            addInterest(interest);
        } else if (option=='P') {
            printAllAccs();
        } else if (option=='E') {
            closeAllAccs();
            bool = 0;
        } else {
            printf("Please enter a proper input!\n");
            // clean buffer loop (for incorrect input of several characters at once)
            while ((option=getchar())!='\n'&&option!=EOF) { }
        }
        printf("\n");
    }
    return 0;
}
