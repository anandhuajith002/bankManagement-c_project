#ifndef LOGIN_H
#define LOGIN_H

#include "bank.h"


void login_admin(BankAdmin *bank_adm,BankCustomer *bank_cus);
void login_cus(BankCustomer *bank_cus);
void createacc(BankCustomer *bank_cus);


#endif