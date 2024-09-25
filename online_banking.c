#include "online_banking.h"

int main(void)
{
    
    printf("What are you here today for ?\n");
    printf("1.Register an account\n");
    printf("2.Login to account\n");
    
    printf("Enter your choice\n");
    scanf("%d",&opt);

    if(opt ==1)
    {
        system("clear");
        printf("Enter your phone number :\t");
        scanf("%s",usr.phone);
        printf("\nEnter your account number:\t");
        scanf("%s",usr.ac);
        printf("\nEnter your password 8 characters minimum:\t");
        scanf("%s",usr.password);
        usr.balance = 0;
        strcpy(filename,usr.phone);
        fp = fopen(strcat(filename,".csv"),"w");
        fwrite(&usr,sizeof(struct user),1,fp);
        if(fwrite!=0)
        {
            printf("\n\nAccount successfully registered");
        }
        else{
            printf("\n\nsomething went wrong please try again");
        }
        fclose(fp);
    }
    if(opt == 2)
{
    system("clear");
    printf("\nPhone number:\t");
    scanf("%s",phone);
    printf("\nPassword:\t");
    scanf("%s",password);
    strcpy(filename, phone);
    
    // Open the file in read mode instead of write mode
    fp = fopen(strcat(filename,".csv"),"r"); 
    if(fp == NULL)
    {
        printf("\nAccount number not registered");
    }
    else
    {
        fread(&usr, sizeof(struct user), 1, fp);
        fclose(fp);
        
        // Compare the passwords after reading the file
        if(!strcmp(password, usr.password))
        {
            printf("Password matched\n");
            
            while(flag == 'y')
            {
                system("clear");
                printf("\n Press 1 to check balance");
                printf("\n Press 2 to add money");
                printf("\n Press 3 to withdraw");
                printf("\n Press 4 to transfer money");
                printf("\n Press 5 to change password");

                printf("\n\nEnter yout choice:\t");
                scanf("%d",&choice);

                switch(choice)
                {
                    case 1:
                            printf("\nYour current balance is \t %.2f",usr.balance);
                            break;
                    case 2:
                            printf("\nENter the amount\t");
                            scanf("%f",&amount);
                            usr.balance+=amount;
                            fp = fopen(filename,"r");
                            fwrite(&usr,sizeof(struct user),1,fp);
                            if(fwrite != NULL)
                            printf("\nSuccessfully deposited money");
                            fclose(fp);
                            break;
                    case 3:
                            printf("\nENter the amount\t");
                            scanf("%f",&amount);
                            usr.balance-=amount;
                            fp = fopen(filename,"r");
                            fwrite(&usr,sizeof(struct user),1,fp);
                            if(fwrite != NULL)
                            printf("\nSuccessfully withdrawn money rs.%.2f",amount);
                            fclose(fp);
                            break;
                    case 4:
                            printf("\nEnter the phone  number to transfer the money to:\t ");
                            scanf("%s",phone);
                            strcpy(filename,phone);
                            printf("\nEnter the amount to transfer:\t");
                            scanf("%f",&amount);
                            if(amount > usr.balance)
                            {
                                printf("\nInsufficient Balance");
                            }
                            else{
                                fp = fopen(strcat(filename,".csv"),"w");
                                if(fp == NULL)
                                {
                                    printf("\n Phone number not registered");
                                    return 0;
                                }
                                fread(&usr1,sizeof(struct user),1,fp);
                                fclose(fp);
                                fp = fopen(filename,"w");
                                usr1.balance += amount;
                                fwrite(&usr1,sizeof(struct user),1,fp);
                                fclose(fp);
                                if(fwrite != NULL)
                                printf("\nYou have successfully transferred %.2f to %s",amount,phone);
                                strcpy(filename,usr.phone);
                                fp = fopen(strcat(filename,".csv"),"w");
                                fwrite(&usr1,sizeof(struct user),1,fp);
                                fclose(fp);

                            }
                            break;
                    case 5:
                            printf("\nEnter new password:\t");
                            scanf("%s",password);
                            fp = fopen(filename,"w");
                            strcpy(usr.password,password);
                            fwrite(&usr,sizeof(struct user),1,fp);
                            if(fwrite!=NULL)
                            {
                            printf("Successfully changed the password\n");
                            }
                            break;

                    default:
                            printf("Invalid choice try again\n");
                            break;
                }

                printf("\nDo you want to continue the transaction [y/n] ?");
                scanf("%s",&flag);
            }
        }
        else
        {
            printf("Invalid password\n");
        }
    }
}


    return 0;
}