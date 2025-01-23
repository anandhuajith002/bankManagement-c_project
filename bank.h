#ifndef BANK_H
#define BANK_H

#define MAX_ADM 10
#define MAX_CUS 100

typedef struct 
{
    char acc_no[15];
    char name[50];
    char email[50];
    char phone[15];
    char pin[10]; //8digit
    char acc_type; // s-savings c-curent
    long int balance;
}Customer;

typedef struct
{
    char admin_id[15];
    char name[50];
    char phone[15];
    char pswrd[20];

}Admin;

typedef struct
{
    Admin admins[MAX_ADM];
    int admin_count;

}BankAdmin;

typedef struct
{
    Customer customers[MAX_CUS];
    int customer_count;
}BankCustomer;

void init_admin(BankAdmin *bank_adm);
void init_cus(BankCustomer *bank_cus);
void save_cus(BankCustomer *bank_cus);




#endif 