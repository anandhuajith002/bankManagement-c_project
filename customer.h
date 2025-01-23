#include"bank.h"

void view_info(BankCustomer *bank_cus,int i);
int searchPhone(BankCustomer *bank_cus,char phone[]);
void print_details_customer(BankCustomer *bank_cus, int i);
void cus_banking_page(BankCustomer *bank_cus,int i);
void transfer(BankCustomer *bank_cus,int i);
void pinchange(BankCustomer *bank_cus,int i);
void withdraw(BankCustomer *bank_cus,int i);
void deposit(BankCustomer *bank_cus,int i);