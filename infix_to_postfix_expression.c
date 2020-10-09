#include <ctype.h>
#include <stdio.h>
#include<math.h>
#define SIZE 50 /* Size of Stack we have fixed upto max no.of elements*/

/* Enter your code here. Read input from STDIN. Print output to STDOUT */
char s[SIZE];//char string of the expression is taken
int top = -1; /* Global declarations for the stack as it is empty beforehand */

/* Function to remove spaces from given string as they can be given in it*/
void RemoveSpaces(char* source)//source string in it
{
    char* i = source;
    char* j = source;
    while(*j != 0)
    {
        *i = *j++;
        if(*i != ' ')//if space occurs move ahead and don't count that space
            i++;
    }
    *i = 0;
}

/* Function for PUSH operation */
void push(char elem)
{
    s[++top] = elem;//if any element occurs push it into the stack
}

/* Function for POP operation */
char pop()
{
    return (s[top--]);//pop the elements from the stack
}

/* Function for precedence */
int pr(char elem)
{
    switch (elem)//precedence of the various operators as described in the question
    {
    case '+':
        return 0;
    case '(':
        return 1;
    case '#':
    case '@':
       return 2;
    case '&':
    case '/':
        return 3;
    case '^':
       return 4;
    }
}
/*
* Function to convert from infix to postfix expression
*/
void infix_to_postfix(char *infix, char *postfix)
{
    char ch, elem;
    int i = 0, k = 0;

    RemoveSpaces(infix);//removing the spaces in it
    push('+');

    while ((ch = infix[i++]) != '\n')//till the next line is not obtained continue the loop
    {
        if (ch == '(')//push the characters after (
            push(ch);
        else if (isalnum(ch))
            postfix[k++] = ch;//add the element or the character except the bracket inside the postfix expression
        else if (ch == ')')
        {
            while (s[top] != '(')
                postfix[k++] = pop();//pop the elements till the previous ( is not obtained
            elem = pop(); /* Remove ( *///element got popped out
        }
        else     /* Operator */
        {
            while (pr(s[top]) >= pr(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    while (s[top] != '+') /* Pop from stack till empty and no element is left in it */
        postfix[k++] = pop();

    postfix[k] = 0; /* Make postfix as valid string */
}

/*
* Function to evaluate a postfix expression
*/
int eval_postfix(char *postfix)
{
    char ch;
    int i = 0, op1, op2;
    while((ch = postfix[i++]) != 0)
    {
        if(isdigit(ch))
            push(ch-'0'); /* Push the operand by conversion of the ascii value into the string*/
        else   /* Operator,pop two operands */
        {
            op2 = pop();//operand 2
            op1 = pop();//operand 1
            switch(ch)
            {
            case '#' :
                push(op1+op2);//adding operands
                break;
            case '@' :
                push(op1-op2);//subtracting the operands
                break;
            case '&' :
                push(op1*op2);//multiplying the operands
                break;
            case '/' :
                push(op1/op2);//division of the operands
                break;
            case '^' :
                push(pow(op1,op2));//finding power of the operand or exponentiation
                break;
            }
        }
    }
    return s[top];//returning the topmost element in the stack
}

int main()   /* Main Program */
{

    char infx[50], pofx[50];
    fgets(infx, 50, stdin);//taking in the infix expression input by user

    infix_to_postfix(infx, pofx);//conversion

    top = -1;
    printf("%d",eval_postfix(pofx));
    return 0;
}
