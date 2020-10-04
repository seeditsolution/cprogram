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
	if(rear == max-1)
		printf("Queue is FULL\n");
	else if((front == -1) && (rear == -1))
		front = rear = 0;
	else
		rear++;
	queue[rear] = num;
}
void DELETE()
{
	if((front == -1) || (front > rear))
		printf("Queue is EMPTY\n");
	else
	{
		printf("The deleted element is %d\n", queue[front]);
		front++;
	}
}
void peek()
{
	if((front == -1) || (front > rear))
		printf("Queue is EMPTY\n");
	else
		printf("The element at the top is %d\n", queue[front]);
}
void display()
{
	if((front == -1)||(front > rear))
		printf("Queue is EMPTY\n");
	else
	{
		int i;
		for(i=front; i<=rear; i++)
			printf("%d\t", queue[i]);
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
