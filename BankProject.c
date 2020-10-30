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
	int mainmenu;
	mainmenu=menu();
	return 0;
}

int menu()
{	
	int option;
	system("COLOR F");
	printf("\n\t\t\t\t\t    *****ABC Bank Limited****\n\n\t\t\t");
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
				break;
	}
}


int NewAccount()
{
	system("CLS") ;
	system("COLOR E");
	printf("Loading");
	for(i=0;i<4;i++)
	{
	sleep(420);
	printf(".");
	}	
	system("CLS");
	printf("\n\t\t\t-------------------------------------------------\n");
	printf("\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t|\t\tNew Account Creation\t\t|\n");
	printf("\t\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t\t-------------------------------------------------\n");
	printf("\nEnter First Name: ");
	scanf("%s",&FName);
	printf("\nEnter Last Name: ");
	scanf("%s",&LName);
	printf("\nEnter CNIC Number: ");
	scanf("%s",&CNIC);
	printf("\nEnter Email: ");
	scanf("%s",&Email);
	printf("\nEnter Account Number: ");
	scanf("%s",&AccNo);
	printf("\nEnter Funds In Account: Rs");
	scanf("%d",&Amount);
	printf("\nWait");
	
	for(i=0;i<=5;i++)
	{
		sleep(320);
		printf(".");
	}
	
	system("COLOR 2");
	printf("\n\t\tAccount Created Successfully. . .\n");
	printf("\n\nYour 4 Digit Pin is: %d",Pin);
	system("COLOR F");
	for(i=0;i<4;i++)
	{
		sleep(320);
	}  
}


int CashWithdraw(int OrgAmount)
{
	int withdraw,total,Pincode;
	system("CLS");
	system("COLOR C");
	printf("\n\nLoading");
	for(i=0;i<=5;i++)
	{
		sleep(320);
		printf(".");
	}
	printf("\n\t\t ||||***Cash Withdrawal***||||");		
	printf("\n\nEnter Account Number:");
	scanf("%s",AccNo);	
	printf("\nEnter your 4 Digit Pin: ");
	scanf("%d",&Pincode);
	printf("\nVerifying");
	for(i=0;i<=5;i++)
		{
			sleep(320);
			printf(".");
		}
		
	if(Pin==Pincode)
	{
		printf("\nVerified");
		printf("\nEnter Amount to Withdraw: Rs");
		scanf("%d",&withdraw);
		
		while(withdraw > OrgAmount)
		{
			system("COLOR 4");
			printf("\n\nYou have insufficient Funds in your Account");
			printf("\n\nPlease re-enter Amount for Withdrawal: Rs");
			scanf("%d",&withdraw);
		}
			system("COLOR F");
			OrgAmount = OrgAmount - withdraw ;
			system("COLOR 2");
			printf("\n\nWithdrawal Successful");
		

		for(i=0;i<=5;i++)
		{
			sleep(320);
		}
		system("COLOR F");
		printf("\n\nThe Amount after Withdrawal is: Rs%d",OrgAmount);
		for(i=0;i<=5;i++)
		{
			sleep(320);
		}
		return 0;
	}
	else
	{
		system("COLOR 4");
		printf("\nInvalid Pincode");
			
		for(i=0;i<4;i++)
		{
			sleep(320);
			printf(".");
		}
	}
}

int CashDeposit(int orgamount)
{
	int deposit,total,Pincode;
	system("CLS");
	system("COLOR C");
	printf("\n\nLoading");
	for(i=0;i<=5;i++)
	{
		sleep(320);
		printf(".");
	}
	printf("\n\t\t ||||***Cash Withdrawal***||||");		
	printf("\n\nEnter Account Number:");
	scanf("%s",AccNo);	
	printf("\nEnter your 4 Digit Pin: ");
	scanf("%d",&Pincode);
	printf("\nVerifying");
	for(i=0;i<=5;i++)
		{
			sleep(320);
			printf(".");
		}
		
	if(Pin==Pincode)
	{
		printf("\nVerified");
		printf("\nEnter Amount to Deposit: Rs");
		scanf("%d",&deposit);
		
		system("COLOR F");
		orgamount = orgamount + deposit ;
		system("COLOR 2");
		printf("\n\nDeposit Successful");

		for(i=0;i<=5;i++)
		{
			sleep(320);
		}
		system("COLOR F");
		printf("\n\nThe Amount After Deposit is: Rs%d",orgamount);
		for(i=0;i<=5;i++)
		{
			sleep(320);
		}
		return 0;
	}
	else
	{
		system("COLOR 4");
			printf("\nInvalid Pincode");
		for(i=0;i<4;i++)
		{
			sleep(320);
			printf(".");
		}
		return menu();
	}
}

void LoanCalculator()
{
	system("CLS");
	system("COLOR E");
	printf("Loading");
	for(i=0;i<=5;i++)
	{
		Sleep(320);
		printf(".");
	}
	printf("\n\t\t ***LOAN CALCULATOR***");
	int val,option,dwnpymt,monthly;
	
	printf("\n\nEnter Loan Amount: ");
	scanf("%d",&val);

	printf("\n1) 1 Year\n2) 3 Years\n3) 5 Years\nPlease choose installment plan no. from above:");
	scanf("%d",&option);
	
	switch(option)
	{
		case 1: dwnpymt = val * 0.1;
				monthly = (((val - dwnpymt) / 12)*0.05)+((val - dwnpymt) / 12);
				printf("Your  Downpayment will be: Rs%d\nYour Monthly installments for a year: Rs%d",dwnpymt,monthly);
				break;
		case 2: dwnpymt = val * 0.1;
				monthly = (((val - dwnpymt) / 36)*0.05)+((val - dwnpymt) / 36);
				printf("Your  Downpayment will be: Rs%d\nYour Monthly installments for 3 years tenure: Rs%d",dwnpymt,monthly);
				break;
		case 3: dwnpymt = val * 0.1;
				monthly = (((val - dwnpymt) / 60)*0.05)+((val - dwnpymt) / 60);
				printf("Your  Downpayment will be: Rs%d\nYour Monthly installments for 5 years tenure: Rs%d",dwnpymt,monthly);
				break;
	}
}

void DisplayAll(int amount)
{
	int option;
	system("CLS");
	system("COLOR C");
	printf("Loading");
	for(i=0;i<=5;i++)
	{
		sleep(320);
		printf(".");
	}
	system("CLS");
	printf("\nFirst Name: ");
	puts(FName);
	printf("\nLast Name: ");
	puts(LName);
	printf("\nCNIC: ");
	puts(CNIC);
	printf("\nEmail: ");
	puts(Email);
	printf("\nAccount Number: ");
	puts(AccNo);
	printf("\nFunds In Account: Rs%d",amount);

}

void Return()
{	
	system("COLOR F");
	int option;
	printf("\n\nEnter 1 to Return to Main Menu\nEnter 0 to Exit\nOption: ");
	scanf("%d",&option);
	switch(option==1)
	{
		case 1: return menu();
		break;
		case 0:	system("CLS");
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
}
