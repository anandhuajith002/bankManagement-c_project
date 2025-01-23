#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "bank.h"
#include "login.h"
#include "customer.h"
#include "admin.h"
#include "createacc.h"

void login_cus(BankCustomer *bank_cus)
{
    char phone[50],pin[10],acc_typ;
    printf("\n----Customer Login----\n");
login_c:
    
    printf("Enter mobile no : ");
    scanf(" %[^\n]",phone);
    int i=searchPhone(bank_cus,phone);
    if( i==-1)
    {
        printf("!!!Phone number not found!!!\n\n");
        goto login_c;
    }
    printf("Enter 8 digit pin : ");
    scanf(" %s",pin);
    if(strcmp(pin,bank_cus->customers[i].pin)!=0)
    {
        printf("!!!Invalid pin!!!\n\n");
        goto login_c;
    }
    cus_banking_page(bank_cus,i);

}
void login_admin(BankAdmin *bank_adm,BankCustomer *bank_cus)
{
    char adm_id[15],pswrd[20];
    printf("\n----Admin Login----\n");
admlog:
    printf("Enter Admin ID : ");
    scanf(" %[^\n]",adm_id);

    int i=searchAdmId(bank_adm,adm_id);
    if(i==-1)
    {
        printf("!!!Admin ID not found!!!\n\n");
        goto admlog;
    }

    printf("Enter password : ");
    scanf(" %s",pswrd);
    if(strcmp(pswrd,bank_adm->admins[i].pswrd)!=0)
    {
        printf("!!!Invalid password!!!\n\n");
        goto admlog;
    }
    adm_banking_page(bank_adm,bank_cus,i);

}
void createacc(BankCustomer *bank_cus)
{
    /*
    1.what type of acc
    2.name(validate)
    3.phone (validate,check if exist)
    4.email(validate,checkif exists)
    5.pin (validate,confirm)
    6.display details
    7.confirm details
    8.if yes append to file

    */    
    char acc_no[15],name[50],email[50],phone[15],pin[10],cnfpin[10],acc_type;
    // int index = bank_cus->customer_count+1;
    Customer cus;

    printf("\n----Create Account----\n");


    int ifsc=2200;
    extern int bank_no;
    bank_no++;
    sprintf(acc_no,"%d%d%d",ifsc,bank_no,00);
    strcpy(cus.acc_no,acc_no);


    printf("\nCurrent Account-'c' / Savings Account-'s'");
accty:
    printf("\nEnter the type of account : ");
    getchar();
    scanf("%c",&acc_type);
    if(acc_type != 'c' && acc_type !='s')
    {
        printf("\n!!!Invalid Account type\n");
        goto accty;
    }
    cus.acc_type=acc_type;


nameee:
    printf("Enter the Name : ");
    scanf(" %[^\n]",name);
    if(!validateName(name))
    {
        printf("\n!!!Name is not valid!!!\n");
        goto nameee;
    }
    strcpy(cus.name,name);



phonee:
    printf("Enter the phone number : ");
    scanf("%s",phone);
    if(!validatePhone(phone))
    {
        printf("\n!!!Phone NUmber not valid!!!\n");
        goto phonee;
    }
    if(ifExistPhone(bank_cus,phone,acc_type))
    {
        printf("\n!!!Phone NUmber already exists!!!\n");
        goto phonee;
    }
    strcpy(cus.phone,phone);



emaail:
    printf("Enter the e-mail : ");
    scanf("%s",email);
    if(!validateEmail(email))
    {
        printf("\n!!!Email not valid!!!\n");
        goto emaail;
    }
    if(ifExistEmail(bank_cus,email,acc_type))
    {
        printf("\n!!!e-mail already exists!!!\n");
        goto emaail;
    }
    strcpy(cus.email,email);


pin:
    printf("Enter the new 8-digit pin : ");
    scanf("%s",pin);
    if(!validatePin(pin))
    {
        printf("\n!!!Pin not valid!!!\n");
        goto pin;
    }
    printf("Confirm the pin : ");
    scanf("%s",cnfpin);
    if(strcmp(pin,cnfpin)!=0)
    {
        printf("\n!!!Pin doesn't match!!!\n");
        goto pin;

    }
    strcpy(cus.pin,pin);

    cus.balance=0;

    printf("\n\n---Please confirm the details---\n");
    printf("Name           : %s\nPhone          : %s \nE-mail         : %s\nAccount Type   : %c\n",name,phone,email,acc_type);
    printf("\nIs the details correct (y/n) : ");
    char val;
    getchar();
    scanf("%c",&val);
    if(val != 'y')
    {
        getchar();
        return;
    }

    bank_cus->customers[bank_cus->customer_count]=cus;
    bank_cus->customer_count++;

    printf("\n-----New Account Created-----");
    print_details_cus(bank_cus,bank_cus->customer_count-1);
    
    return;

}
