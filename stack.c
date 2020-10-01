#include<stdio.h>
#include<stdlib.h>
#define MAX 10
float stack[MAX];
int top = -1;

void PUSH()
{
	float push;
	if(top==(MAX-1))
	{
		printf("Stack Overflow\n");
	}
	else
	{
		printf("Please enter the value to be pushed in the stack\n");
		scanf("%f",&push);
		stack[++top] = push;
	}
}

void POP()
{
	if(top==-1)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		printf("The value poped is %f",stack[top--]);
	}
}

void PEEK()
{
	if(top==-1)
	{
		printf("Stack is Empty\n");
	}
	else
	{
		printf("The value at the top of the stack is %f",stack[top]);
	}
}

void DISPLAY()
{
	int i;
	if(top==-1)
	{
		printf("Stack is EMpty");
	}
	else
	{
		for(i=0;i<MAX;i++)
		{
			printf("The value at the %d position : %f\n",i,stack[i]);
		}
	}
}

int main()
{
	int choice;
	while(1)
	{
		printf("\nPlease enter the operation to be performed\n1: PUSH an element onto the Stack\n2: POP an element from Stack\n3: PEEK (Know the element at the top of the Stack)\n4: Display the elements onto the Stack\n5: Exit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: PUSH();
				break;
			case 2: POP();
				break;
			case 3: PEEK();
				break;
			case 4: DISPLAY();
				break;
			case 5: exit(1);
				break;
			default: printf("You have entered the wrong choice\n");

		}
	}
	return 0;
}
