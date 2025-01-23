#include<stdio.h>
#include "bank.h"
#include "login.h"

int main()
{

    BankCustomer bank_cus;
    BankAdmin bank_adm;
    init_admin(&bank_adm);
    init_cus(&bank_cus);
    int choice;
    

    do
    {

        printf("\n\n-----Bank Account-----\n");
        printf("1 -> Login\n");
        printf("2 -> Create account\n");
        printf("3 -> Save \n");
        printf("4 -> Exit\n\n");
        printf("Enter choice : ");
        scanf("%d",&choice);

        switch(choice)
        {

            case 1:
            login:
                printf("\n---Login---\n");
                printf("1 -> Admin\n");
                printf("2 -> Customer\n");
                printf("3 -> Goto Home\n");
                printf("\nEnter User type : ");
                int usr;
                scanf("%d",&usr);

                switch (usr)
                {
                    case 1:

                        
                        login_admin(&bank_adm,&bank_cus);
                        break;

                    case 2:
                        
                        login_cus(&bank_cus);
                        break;
                    case 3:
                        break;

                    default:
                        getchar();
                        printf("!!!invalid choice!!!\n");
                        goto login;
                }
                break;

            case 2:
                createacc(&bank_cus);  
                break;
            
            case 3:

                save_cus(&bank_cus);    
                printf("\nSaved to Database ....\n");
                break;
            case 4:
                printf("\n\nExiting......\n");
                break;

            default :
                getchar();
                printf("!!!invalid choice!!!");
                break;

        }

    }while(choice !=4);
}
