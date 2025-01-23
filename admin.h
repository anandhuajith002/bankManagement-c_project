#include "bank.h"



int searchAdmId(BankAdmin *bank_adm,char adm_id[]);
void adm_banking_page(BankAdmin *bank_adm,BankCustomer *bank_cus,int i);
void viewall(BankCustomer *bank_cus);
int searchacc(BankCustomer *bank_cus);
void edit_acc(BankCustomer *bank_cus,int j);
void close_acc(BankCustomer *bank_cus,int j);
void print_details_cus(BankCustomer *bank_cus, int i);
