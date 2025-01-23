#include<stdio.h>
#include<string.h>
#include "bank.h"
#include "createacc.h"
#include "ctype.h"



int validateName(char name[])
{
    int i=0;

    if(name[i]=='\0')
        return 0;

    while(name[i])
    {
        if(isalpha(name[i])==0 && name[i]!=' ')
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int validatePhone(char phone[])
{
    int i=0;
    while(phone[i])
    {
        if(isdigit(phone[i])==0)
        {
            return 0;
        }
        i++;
    }
    if(i!=10)
        return 0;
    return 1;
}
int validateEmail(char email[])
{
    int i=0;
    int at_count = 0, dot_count = 0;
    
    if (email[i] == '\0')
        return 0;

    
    while(email[i])
    {
        if(email[i]=='@')
        {
            at_count++;
            if (at_count > 1 || i == 0)
                return 0;        
        }

        else if(email[i]=='.')
        {
            if (i == 0 || email[i - 1] == '.') 
                return 0;
            if (at_count == 1 && email[i+1] == 'c' && email[i+2]=='o' && email[i+3]=='m' )
            {
                dot_count++;

            }
        }
        else if (!isalnum(email[i]) && email[i] != '_' && email[i] != '-' && email[i] != '+')
        {
            if (at_count == 0) // Invalid character before '@'
                return 0;
            else if (at_count == 1 && !isalnum(email[i]) && email[i] != '-') // Invalid character in domain
                return 0;
        }
        i++;
    }
    if(at_count!=1 || dot_count==0 )
    {
        return 0;
    }
    return 1;

}
int validatePin(char pin[])
{
    int i=0;
    while(pin[i])
    {
        if(isdigit(pin[i])==0)
        {
            return 0;
        }
        i++;
    }
    if(i!=8)
        return 0;
    return 1; 
}
int ifExistPhone(BankCustomer *bank_cus,char phone[],char acc_type)
{
    int count = bank_cus->customer_count;
    for(int i=0;i<count;i++)
    {
        if(strcmp(phone,bank_cus->customers[i].phone)==0)
        {
            return 1;
        }
    }
    return 0;

}
int ifExistEmail(BankCustomer *bank_cus,char email[],char acc_type)
{
    int count = bank_cus->customer_count;
    for(int i=0;i<count;i++)
    {
        if(strcmp(email,bank_cus->customers[i].email)==0)
        {
            return 1;
        }
    }
    return 0;

}

