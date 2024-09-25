#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct user{
    char phone[13];
    char ac[20];
    char password[30];
    float balance;
};
char flag = 'y';
    char phone[15];
    char password[30];
    struct user usr,usr1;
    float amount;
    FILE *fp;
    char filename[50];
    int opt,choice;