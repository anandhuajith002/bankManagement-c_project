#include "bank.h"

int validateName(char name[]);
int validatePhone(char phone[]);
int validateEmail(char email[]);
int validatePin(char pin[]);
int ifExistPhone(BankCustomer *bank_cus,char phone[],char acc_type);
int ifExistEmail(BankCustomer *bank_cus,char email[],char acc_type);

