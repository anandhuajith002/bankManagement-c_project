#include<stdio.h>
#include<string.h>
#include "bank.h"
#include"admin.h"


void adm_banking_page(BankAdmin *bank_adm,BankCustomer *bank_cus,int i)
{
adm:
    int len=bank_cus->customer_count;
    printf("\n\n---Welcome Admin %s---\n",bank_adm->admins[i].name);
    printf("1 -> View all accounts\n");
    printf("2 -> Search an account\n");
    printf("3 -> Edit an account\n");
    printf("4 -> Close an account\n");
    printf("5 -> Goto Home\n");
    printf("\nTotal accounts : %d",len);
    printf("\nEnter the choice : ");
    int choice;
    scanf("%d",&choice);
    int j;

    switch(choice)
    {
        case 1:
            viewall(bank_cus);
            adm_banking_page(bank_adm,bank_cus,i);
            break;

        case 2:
            printf("\n---Search Account---\n");
            j= searchacc(bank_cus);
            if(j==-1)
            {
                printf("\n!!!No Accounts found!!!");
                adm_banking_page(bank_adm,bank_cus,i);
            }
            print_details_cus(bank_cus,j);
            adm_banking_page(bank_adm,bank_cus,i);
            break;

        case 3:
            char ch,pswrd[20];
            j=searchacc(bank_cus);
            if(j==-1)
            {
                printf("\n!!!No Accounts found!!!");
                adm_banking_page(bank_adm,bank_cus,i);
            }
            print_details_cus(bank_cus,j);
            printf("Is it the details to be edited(y/n) : ");
            getchar();
            scanf("%c",&ch);
            if(ch!='y')
            {
                adm_banking_page(bank_adm,bank_cus,i);
            }
            printf("Confirm your password to edit : ");
            scanf(" %s",pswrd);
            if(strcmp(pswrd,bank_adm->admins[i].pswrd)!=0)
            {
                printf("!!!Invalid password!!!\n\n");
                adm_banking_page(bank_adm,bank_cus,i);
            }
            edit_acc(bank_cus,j);
            adm_banking_page(bank_adm,bank_cus,i);
            break;

        case 4:
            j=searchacc(bank_cus);
            if(j==-1)
            {
                printf("No Accounts found");
                adm_banking_page(bank_adm,bank_cus,i);
            }
            print_details_cus(bank_cus,j);
            printf("Is it the details to be deleted(y/n) : ");
            getchar();
            scanf("%c",&ch);
            if(ch!='y')
            {
                adm_banking_page(bank_adm,bank_cus,i);
            }
            printf("Confirm your password to close account : ");
            scanf(" %s",pswrd);
            if(strcmp(pswrd,bank_adm->admins[i].pswrd)!=0)
            {
                printf("!!!Invalid password!!!\n\n");
                adm_banking_page(bank_adm,bank_cus,i);
            }
            close_acc(bank_cus,j);
            adm_banking_page(bank_adm,bank_cus,i);
            break;

        case 5:
            return;

        default:
            getchar();
            printf("!!!Invalid Choice!!!\n");
            goto adm;

    }
}
int searchAdmId(BankAdmin *bank_adm,char adm_id[])
{
    int count= bank_adm->admin_count;
    for(int i=0;i<count;i++)
    {
        if(strcmp(adm_id,bank_adm->admins[i].admin_id)==0)
        {
            return i;
        }
    }

    return -1;
}
void viewall(BankCustomer *bank_cus)
{
    int len = bank_cus->customer_count;
    if (len == 0)
    {
        printf("\n---No Accounts Found---\n");
        return;
    }

    printf("\n---All Accounts Listed---\n");
    printf("==============================================================================================\n");
    printf("| Sl. No |   Account No   |       Name       |           Email           |    Phone   | Type |\n");
    printf("==============================================================================================\n");

    for (int j = 0; j < len; j++)
    {
        printf("| %6d | %14s | %-16s | %-25s | %-10s |   %c  |\n",
               j + 1,
               bank_cus->customers[j].acc_no,
               bank_cus->customers[j].name,
               bank_cus->customers[j].email,
               bank_cus->customers[j].phone,
               bank_cus->customers[j].acc_type);
    }

    printf("==============================================================================================\n");
}

int searchacc(BankCustomer *bank_cus)
{
    char acc_no[15];
    printf("Enter the account number :");
    scanf(" %s",acc_no);

    for(int i=0;i<bank_cus->customer_count;i++)
    {
        if(strcmp(acc_no,bank_cus->customers[i].acc_no)==0)
        {
            return i;
        }
    }
    return -1;

}
void edit_acc(BankCustomer *bank_cus,int j)
{
    printf("\n---Edit Acoount---\n");
    printf("1 -> Name\n");
    printf("2 -> e-mail\n");
    printf("3 -> Phone\n");
    printf("Enter what to edit : ");
    int choice;
    scanf("%d",&choice);


    if(choice==1)
    {
        char name[50];
        printf("Enter new name : ");
        scanf(" %[^\n]",name);
        strcpy(bank_cus->customers[j].name,name);
    }
    else if(choice==2)
    {
        char email[50];
        printf("Enter new email : ");
        scanf(" %[^\n]",email);
        strcpy(bank_cus->customers[j].email,email);
    }
    else if(choice == 3)
    {
        char phone[15];
        printf("Enter new phone number : ");
        scanf(" %s",phone);
        strcpy(bank_cus->customers[j].phone,phone);
    }
    else
        return;

    printf("\n---The Edited Details---");
    print_details_cus(bank_cus,j);

}
void close_acc(BankCustomer *bank_cus,int j)
{
    int len=bank_cus->customer_count;
    for(int k=j+1;k<len;k++)
    {
        bank_cus->customers[k-1]=bank_cus->customers[k];
    }
    bank_cus->customer_count--;
    printf("\nAccount Deleted");
}
void print_details_cus(BankCustomer *bank_cus, int i)
{
    printf("\n+------------------------------------------------------+\n");
    printf("|                   Account Details                    |\n");
    printf("+------------------------------------------------------+\n");
    printf("| Account Number : %-35s |\n", bank_cus->customers[i].acc_no);
    printf("| Name           : %-35s |\n", bank_cus->customers[i].name);
    printf("| Email          : %-35s |\n", bank_cus->customers[i].email);
    printf("| Phone          : %-35s |\n", bank_cus->customers[i].phone);
    printf("| Account Type   : %-35c |\n", bank_cus->customers[i].acc_type);
    printf("+------------------------------------------------------+\n");
}

