#include<stdio.h>

int menu();
int NewAccount();
int CashWithdraw(int OrgAmount);
void DisplayAll(int amount);
void LoanCalculator();
int CashDeposit(int orgamount);
void Return();
int i=0;

char AccNo[10];
char FName[10];	
char LName[10];
char CNIC[10];
int Pin=3515;;
int Amount;
char Email[10];

int main()
{
	int option;
	system("COLOR F");
	printf("\n\t\t\t\t\t    *****HSA Bank Limited****\n\n\t\t\t");
	printf("\n\t\t----------------------------------------------------------------------------------");
	printf("\n\t\t|\t\t\t\t     MAIN MENU   \t\t\t\t |");
	printf("\n\t\t----------------------------------------------------------------------------------");
	printf("\n\t\t|Select the following options to Proceed:\t\t\t\t\t |");
	printf("\n\t\t|\t\t\t\t\t\t\t\t\t\t |");
	printf("\n\t\t|Press 1 to Create an Account\t\t\tPress 4 to Take Loan\t\t |");
	printf("\n\t\t|Press 2 for Money Withdrawal\t\t\tPress 5 to Display all accounts  |");
	printf("\n\t\t|Press 3 for Money Deposit\t\t\tPress 6 to Exit\t\t\t |");
	printf("\n\t\t----------------------------------------------------------------------------------");
	printf("\n\t\t  Option:");
	scanf("%d",&option);
	switch(option)
	{
		case 1 :NewAccount();
				Return();
				break;
		case 2: CashWithdraw(Amount);
				Return();
				break;
		case 3 :CashDeposit(Amount);
				Return();
				break;
		case 4: LoanCalculator();
				Return();
				break;
		case 5: DisplayAll(Amount);
				Return();
				break;
		case 6: system("CLS");
				printf("Closing the Application");
				for(i=0;i<=4;i++)
				{
					sleep(320);
					printf(".");
				}
				system("CLS");
				system("COLOR B");
				printf("\n\n\t\t\t---------------------------------------------------------");
				printf("\n\t\t\t|\t\t\t\t\t\t\t|");
				printf("\n\t\t\t|\t\tApplication Has Been Closed\t\t|");
				printf("\n\t\t\t|\t\t\t\t\t\t\t|");
				printf("\n\t\t\t---------------------------------------------------------\n\n\n\n");
				for(i=0;i<=3;i++)
				{
					sleep(320);
				}
				return 0;
}
