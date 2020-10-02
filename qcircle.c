#include<stdio.h>
#define max 10
int queue[max];
int front, rear;
void createQueue()
{
	front = rear = -1;
}
void insert()
{
	int num;
	printf("Please enter the number to be inserted :\n");
	scanf("%d", &num);
	if((front==0 && rear==max-1) || (front == rear+1))
		printf("Queue is FULL\n");
	else
	{
		if((front == -1) && (rear == -1))
			front = rear = 0;
		else if((rear == max-1) && (front != -1))
			rear = 0;
		else
			rear++;
		queue[rear] = num;
	}
}
void DELETE()
{
	if((front == -1) && (rear == -1))
		printf("Queue is EMPTY\n");
	else
	{
		printf("The deleted element is %d\n", queue[front]);
		if(front == rear)
			front = rear = -1;
		else if(front == max-1)
		{
			front = 0;
		}
		else
			front++;
	}
}
void peek()
{
	if((front == -1) && (rear == -1))
		printf("Queue is EMPTY\n");
	else
		printf("The element at the top is %d\n", queue[front]);
}
void display()
{
	int i;
   if((front == -1) && (rear == -1))
		printf("Queue is EMPTY\n");
	else if(front < rear)
	{
		for(i=front; i<=rear; i++)
			printf("%d\t", queue[i]);
		printf("\n");
	}
	else
	{
		for(i=front; i<=(max-1); i++)
			printf("%d\t", queue[i]);
		for(i=0; i<=rear; i++)
			printf("%d\t", queue[i]);
		printf("\n");
	}
}
void main()
{
	createQueue();
   int ch;
	do
	{
		printf("\nPlease enter the choice\n");
		printf("1: INSERT\n2: DELETE\n3: PEEK\n4: DISPALY\n5: QUIT\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
					insert();
					break;
			case 2:
					DELETE();
					break;
			case 3:
					peek();
					break;
			case 4:
					display();
					break;
		}
	}while(ch != 5);
}
