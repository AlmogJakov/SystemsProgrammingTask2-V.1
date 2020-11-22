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
        if (option=='O'){ // openAcc
            printf("Initial deposit?:\n");
            scanf(" %lf", &amount);
            openAcc(amount);
        } else if (option=='B') { // balance
            printf("Account number?:\n");
            scanf(" %d", &accNum);
            balance(accNum);
        } else if (option=='D') { // deposit
            printf("Account number?:\n");
            scanf(" %d", &accNum);
            printf("Amount?:\n");
            scanf(" %lf", &amount);
            deposit(accNum, amount);
        } else if (option=='W') { // withdrawal
            printf("Account number?:\n");
            scanf(" %d", &accNum);
            printf("Amount?:\n");
            scanf(" %lf", &amount);
            withdrawal(accNum, amount);
        } else if (option=='C') { // closeAcc
            printf("Account number?:\n");
            scanf(" %d", &accNum);
            closeAcc(accNum);
        } else if (option=='I') { // addInterest
            printf("Interest rate?:\n");
            scanf(" %lf", &interest);
            addInterest(interest);
        } else if (option=='P') { // printAllAccs
            printAllAccs();
        } else if (option=='E') { // closeAllAccs
            closeAllAccs();
            bool = 0;
        } else {
            printf("Please enter a proper input!\n");
            //int flushall( void );
            //while (scanf(" %c", &option) != EOF){
            //    scanf(" %c", &option);
            //}
        }
        printf("\n");
    }
    return 0;
}
