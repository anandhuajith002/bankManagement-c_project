#include<stdio.h>
#include "bank.h"
#include<string.h>
int bank_no;


void init_admin(BankAdmin *bank_adm)
{
    FILE *fptr=fopen("admin.csv","r");
    char admin_id[15],name[50],phone[15],pswrd[20];
    if(fptr == NULL)
    {
        printf("File not opened\n");
        return;
    }
    fscanf(fptr,"#%d\n",&bank_adm->admin_count);

    for(int i=0;i<bank_adm->admin_count;i++)
    {
        fscanf(fptr,"%[^,],%[^,],%[^,],%[^\n]\n",admin_id,name,phone,pswrd);
        strcpy(bank_adm->admins[i].admin_id,admin_id);
        strcpy(bank_adm->admins[i].name,name);
        strcpy(bank_adm->admins[i].phone,phone);
        strcpy(bank_adm->admins[i].pswrd,pswrd);

    }
    
    fclose(fptr);


}

void init_cus(BankCustomer *bank_cus)
{
    FILE *fptr = fopen("custo.csv","r");
    char acc_no[15],name[50],email[50],phone[15],pin[10],acc_type;
    long int balance;
    if(fptr == NULL)
    {
        printf("File not opened\n");
        return;
    }
    fscanf(fptr,"#%d#%d\n",&bank_cus->customer_count,&bank_no);
    for(int i=0;i<bank_cus->customer_count;i++)
    {
        fscanf(fptr,"%[^,],%[^,],%[^,],%[^,],%[^,],%c,%ld\n",acc_no,name,email,phone,pin,&acc_type,&balance); // pin 8 digit  and acc type c or s
        strcpy(bank_cus->customers[i].acc_no,acc_no);
        strcpy(bank_cus->customers[i].name,name);
        strcpy(bank_cus->customers[i].email,email);
        strcpy(bank_cus->customers[i].phone,phone);
        strcpy(bank_cus->customers[i].pin,pin);
        bank_cus->customers[i].acc_type=acc_type;
        bank_cus->customers[i].balance=balance;

    }
    
    fclose(fptr);

}

void save_cus(BankCustomer *bank_cus)
{
    FILE *fptr = fopen("custo.csv","w");
    int len=bank_cus->customer_count;
    long int balance;
    char acc_no[15],name[50],email[50],phone[15],pin[10],acc_type;
    fprintf(fptr,"#%d#%d\n",len,bank_no);

    for(int i=0;i<len;i++)
    {
        strcpy(acc_no,bank_cus->customers[i].acc_no);
        strcpy(name,bank_cus->customers[i].name);
        strcpy(email,bank_cus->customers[i].email);
        strcpy(phone,bank_cus->customers[i].phone);
        strcpy(pin,bank_cus->customers[i].pin);
        acc_type=bank_cus->customers[i].acc_type;
        balance=bank_cus->customers[i].balance;
        fprintf(fptr,"%s,%s,%s,%s,%s,%c,%ld\n",acc_no,name,email,phone,pin,acc_type,balance); // pin 8 digit  and acc type c or s
    }
    fclose(fptr);


}



