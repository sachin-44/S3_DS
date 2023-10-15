#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100

char stack[100];
int top = -1;

//OPERATOR STACK FUNCTION//
void push(char ch)
{
   stack[++top] = ch;
}
void push1(char item) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = item;
}

int pop1() {
    if (top < 0) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}
char pop()
{
    return stack[top--];
}

char peek()
{
    return stack[top];
}

bool empty()
{
    return top == -1;
}

//OTHER FUNCTIONS=//

// To get precedence of current character
int getPrecedence(char c)
{
    switch (c)
    {
    case '$':
        return 4;
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return -1;
    }
}

// To check higher precedence of two characters
bool highprecedence(char c1, char c2)
{
    return getPrecedence(c1) >= getPrecedence(c2);
}

// To check if current character is an Operand
bool isOperand(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
}

// To check if opening bracket
bool isOpeningBracket(char c)
{
    return c == '(' || c == '{' || c == '[';
}

// To check if closing bracket
bool isClosingBracket(char c)
{
    return c == ')' || c == '}' || c == ']';
}

//=======INFIX TO POSTFIX CONVERTER========//
void infix2postfix(char exp[])
{
    int n = strlen(exp);
    char postfix[100]; // POSTFIX ARRAY
    int k = 0;         // Index for postfix array
    for (int i = 0; i < n; i++)
    {
        if (isOperand(exp[i])) // If current character is operand
        {
            postfix[k++] = exp[i]; // Then push to postfix
        }
        else if (!isOpeningBracket(exp[i]) && !isClosingBracket(exp[i])) // If current character is operator (not brackets)
        {
            while (!empty() && !isOpeningBracket(peek()) && highprecedence(peek(), exp[i])) // Checking precedence
            {
                postfix[k++] = pop(); // If greater precedence, then pop and push top to postfix
            }
            push(exp[i]); // If lower precedence, push to operator stack
        }
        else if (isOpeningBracket(exp[i])) // If opening bracket
        {
           push(exp[i]); // Then push to operator stack
        }
        else if (isClosingBracket(exp[i])) // If closing bracket
        {
            while (!empty() && !isOpeningBracket(peek())) // Till stack is empty and not opening bracket
            {
                postfix[k++] = pop(); // pop operator stack and push to postfix
            }
            pop(); // This is to pop the closing bracket
        }
    }
    while (!empty()) // For the remaining element in operator stack (if any)
    {
        postfix[k++] = pop(); // Simply pop and push it to the postfix
    }
    printf("\nPostfix expression\n"); // Printing postfix expression
    for (int i = 0; i < k; i++)
    {
        printf("%c", postfix[i]);
    }
}
int evaluate_postfix(char* exp) {
    int i, op1, op2, result;
    char *token;

    token = strtok(exp, " ");
    while (token != NULL) {
        if (isdigit(*token)) {
            push(atoi(token));
        } else {
            op2 = pop();
            op1 = pop();
            switch (*token) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
            push(result);
        }
        token = strtok(NULL, " ");
    }
    return pop();
}



//=======MAIN FUNCTION=======//
int main()
{
    {
    int ch;
    char exp[100]; // infix expression
    printf("Choose 1 to Convert infix to postfix expression \nchoose 2 to evaluvate a postfix expression\n");
    scanf("%d",&ch);
    switch(ch)
        {
           case(1): 
    printf("\nEnter infix expression without any spaces\n");
    
    scanf("%s", &exp);
    infix2postfix(exp);
break;
case(2):
     char exp1[MAX_SIZE];
    printf("Enter postfix expression: ");
    getchar();
    fgets(exp1, sizeof(exp1), stdin);
    int len = strlen(exp1);
    if (exp1[len - 1] == '\n') {
        exp1[len - 1] = '\0';
    }
    int result = evaluate_postfix(exp1);
    printf("Result: %d\n", result);
    break;
    default :printf("error\n");
    }
   
//CSL201 DATA STRUCTURES LAB ----- DEION TOMSON

}
}

