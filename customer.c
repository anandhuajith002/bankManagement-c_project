#include<stdio.h>
#include<string.h>
#include "bank.h"
#include"customer.h"


void cus_banking_page(BankCustomer *bank_cus,int i)
{

cus:
    printf("\n\n---Welcome %s---\n",bank_cus->customers[i].name);
    printf("1 -> View account details\n");
    printf("2 -> Deposit\n");
    printf("3 -> Withdraw\n");
    printf("4 -> Pin change\n");
    printf("5 -> Transfer money\n");
    printf("6 -> Goto Home\n");
    printf("\nEnter the choice : ");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            view_info(bank_cus,i);
            break;

        case 2:
            deposit(bank_cus,i);
            break;
        case 3:
            withdraw(bank_cus,i);
            break;
        case 4:
            pinchange(bank_cus,i);
            break;
        case 5:
            transfer(bank_cus,i);
            break;
        case 6:
            return;
            break;
        default :
            getchar();
            printf("!!!Invalid choice!!!\n");
            goto cus;

    }

}
int searchPhone(BankCustomer *bank_cus,char phone[])
{
    int count= bank_cus->customer_count;
    for(int i=0;i<count;i++)
    {
        if(strcmp(phone,bank_cus->customers[i].phone)==0)
        {
            return i;
        }
    }

    return -1;
}
void view_info(BankCustomer *bank_cus,int i)
{
    printf("\n---Bank Details---\n");
    printf("Account Number  : %s\n",bank_cus->customers[i].acc_no);
    printf("Name            : %s\n",bank_cus->customers[i].name);
    printf("e-mail          : %s\n",bank_cus->customers[i].email);
    printf("Phone           : %s\n",bank_cus->customers[i].phone);
    if(bank_cus->customers[i].acc_type=='c')
    printf("Account type    : Current\n");
    else
    printf("Account type    : Savings\n");
    printf("Account Balance : %d\n",bank_cus->customers[i].balance);

    cus_banking_page(bank_cus,i);
}
void deposit(BankCustomer *bank_cus,int i)
{
    char pin[10];
    long int amt;
    printf("\n---Deposit---");
    printf("\nEnter the 8 digit pin : ");
    scanf(" %s",&pin);
    if(strcmp(pin,bank_cus->customers[i].pin)!=0)
    {
        printf("!!!Invalid pin!!!");
        cus_banking_page(bank_cus,i);
    }
    printf("Enter the amount : ");
    scanf("%ld",&amt);
    bank_cus->customers[i].balance=bank_cus->customers[i].balance+amt;
    printf("The new balance is : %ld",bank_cus->customers[i].balance);
    printf("\nTransaction complete...");
    cus_banking_page(bank_cus,i);
}
void withdraw(BankCustomer *bank_cus,int i)
{
    char pin[10];
    long int amt;
    printf("\n---Withdraw---");
    printf("\nEnter the 8 digit pin : ");
    scanf(" %s",&pin);
    if(strcmp(pin,bank_cus->customers[i].pin)!=0)
    {
        printf("!!!Invalid pin!!!");
        cus_banking_page(bank_cus,i);
    }
    printf("Enter the amount : ");
    scanf("%ld",&amt);
    if(amt>bank_cus->customers[i].balance)
    {
        printf("!!!Insufficient balance!!!");
        printf("\nTransaction complete...");  
        cus_banking_page(bank_cus,i);

    }
    bank_cus->customers[i].balance=bank_cus->customers[i].balance-amt;
    printf("The new balance is : %ld",bank_cus->customers[i].balance);
    printf("\nTransaction complete...");
    cus_banking_page(bank_cus,i);
}
void pinchange(BankCustomer *bank_cus,int i)
{
    char pin[10],newpin[10],cnfrmpin[10];
    printf("\n---Pin Change---");
    printf("\nEnter the 8 digit pin : ");
    scanf(" %s",&pin);
    if(strcmp(pin,bank_cus->customers[i].pin)!=0)
    {
        printf("!!!Invalid pin!!!");
        cus_banking_page(bank_cus,i);
    }
    printf("Enter the new pin : ");
    scanf(" %s",newpin);
cpin:
    printf("Re-enter the new pin : ");
    scanf(" %s",cnfrmpin);
    if(strcmp(newpin,cnfrmpin)!=0)
    {
        printf("!!!pin doesn't match,try again!!!");
        goto cpin;
    }
    strcpy(bank_cus->customers[i].pin,newpin);
    printf("\nPin changed successfully");
    cus_banking_page(bank_cus,i);

}
void transfer(BankCustomer *bank_cus,int i)
{
    char tr_phone[15],tr_acc_no[15],pin[10];
    long int tr_amt;
    printf("\n---Transfer---\n");
trans:
    printf("Enter the phone number to transfer : ");
    scanf(" %s",tr_phone);
    int j=searchPhone(bank_cus,tr_phone);
    if( j==-1)
    {
        printf("!!!Phone number not found!!!\n\n");
        goto trans;
    }
    printf("Enter the account number to transfer : ");
    scanf(" %s",tr_acc_no);
    if(strcmp(tr_acc_no,bank_cus->customers[j].acc_no)!=0)
    {
        printf("!!!Account number doesnt match!!!\n\n");
        goto trans;
    }
    printf("Please validate name  %s (y/n) : ",bank_cus->customers[j].name);
    
    char val;
    getchar();
    scanf("%c",&val);
    if(val != 'y')
    {
        getchar();
        cus_banking_page(bank_cus,i);
    }
    
    printf("Enter your pin again : ");
    scanf(" %s",&pin);
    if(strcmp(pin,bank_cus->customers[i].pin)!=0)
    {
        printf("!!!Invalid pin!!!");
        goto trans;
    }

    printf("Enter the amount to be transfered :");
    scanf("%ld",&tr_amt);
    if(tr_amt>bank_cus->customers[i].balance)
    {
        printf("!!!Insufficient balance!!!");
        printf("\nTransaction complete...");  
        cus_banking_page(bank_cus,i);
    }
    bank_cus->customers[i].balance -= tr_amt;
    bank_cus->customers[j].balance += tr_amt;
    printf("The new balance is : %ld",bank_cus->customers[i].balance); 
    printf("\nTransaction complete...");  
    cus_banking_page(bank_cus,i);
}

void print_details_customer(BankCustomer *bank_cus, int i)
{
    printf("Account Number : %s\n", bank_cus->customers[i].acc_no);
    printf("Name           : %s\n", bank_cus->customers[i].name);
    printf("Phone          : %s\n", bank_cus->customers[i].phone);
    printf("PIN            : %s\n", bank_cus->customers[i].pin);
    printf("Account Type   : %c\n\n", bank_cus->customers[i].acc_type);
}