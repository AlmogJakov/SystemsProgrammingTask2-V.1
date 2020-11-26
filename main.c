#include <stdio.h>
#include "myBank.h"

int main()
{
    char option; // temporary option input
    double amount; // temporary amount input
    double interest; // temporary interest input
    int accNum; // temporary account input
    int bool = 1; // boolean to run the whole task
    int oneCharInput = 1; // for checking invalid input of main menu
    char ch; // for checking invalid input of internal cases

    while(bool==1){
            printf("Transaction type?\n");
            scanf(" %c", &option);
            oneCharInput = 1;
            while ((ch=getchar())!='\n'&&ch!=EOF) {
                oneCharInput = 0;
             }

        if (option=='O'&&oneCharInput==1){ // openAcc
            printf("Initial deposit?:\n");
            if (scanf(" %lf", &amount)==1&&((ch=getchar())=='\n'||ch==EOF)) {
                openAcc(amount);
            }
            else { // invalid input
                printf("Please enter a valid input!\n");
                while ((ch=getchar())!='\n'&&ch!=EOF) { }
            }

        } else if (option=='B'&&oneCharInput==1) { // balance
            printf("Account number?:\n");
            if (scanf(" %d", &accNum)==1&&((ch=getchar())=='\n'||ch==EOF)) {
                balance(accNum);
            }
            else { // invalid input
                printf("Please enter a valid input!\n");
                while ((ch=getchar())!='\n'&&ch!=EOF) { }
            }

        } else if (option=='D'&&oneCharInput==1) { // deposit
            printf("Account number?:\n");
            if (scanf(" %d", &accNum)==1&&((ch=getchar())=='\n'||ch==EOF)) {}
            else { // invalid input
                printf("Please enter a valid input!\n\n");
                while ((ch=getchar())!='\n'&&ch!=EOF) { }
            }
            printf("Amount?:\n");
            if (scanf(" %lf", &amount)==1&&((ch=getchar())=='\n'||ch==EOF)) {
                deposit(accNum, amount);
                continue;
            }
            else { // invalid input
                printf("Please enter a valid input!\n");
                while ((ch=getchar())!='\n'&&ch!=EOF) { }
            }

        } else if (option=='W'&&oneCharInput==1) { // withdrawal
            printf("Account number?:\n");
            if (scanf(" %d", &accNum)==1&&((ch=getchar())=='\n'||ch==EOF)) {}
            else { // invalid input
                printf("Please enter a valid input!\n\n");
                while ((ch=getchar())!='\n'&&ch!=EOF) { }
                continue;
            }
            printf("Amount?:\n");
            if (scanf(" %lf", &amount)==1&&((ch=getchar())=='\n'||ch==EOF)) {
                withdrawal(accNum, amount);
            }
            else { // invalid input
                printf("Please enter a valid input!\n");
                while ((ch=getchar())!='\n'&&ch!=EOF) { }
            }

        } else if (option=='C'&&oneCharInput==1) { // closeAcc
            printf("Account number?:\n");
            if (scanf(" %d", &accNum)==1&&((ch=getchar())=='\n'||ch==EOF)) {
                closeAcc(accNum);
            }
            else { // invalid input
                printf("Please enter a valid input!\n");
                while ((ch=getchar())!='\n'&&ch!=EOF) { }
            }

        } else if (option=='I'&&oneCharInput==1) { // addInterest
            printf("Interest rate?:\n");
            if (scanf(" %lf", &interest)==1&&((ch=getchar())=='\n'||ch==EOF)) {
                addInterest(interest);
            }
            else { // invalid input
                printf("Please enter a valid input!\n");
                while ((ch=getchar())!='\n'&&ch!=EOF) { }
            }

        } else if (option=='P'&&oneCharInput==1) { // printAllAccs
            printAllAccs();

        } else if (option=='E'&&oneCharInput==1) { // closeAllAccs
            closeAllAccs();
            bool = 0;

        } else {
            printf("Please enter a valid input!\n");
        }
        printf("\n");
    }
    return 0;
}
