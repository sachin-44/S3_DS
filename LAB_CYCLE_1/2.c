#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

//OPERATOR STACK//
char operatorStack[100];
int top = -1;

//OPERATOR STACK FUNCTION//
void OperatorStack_push(char ch)
{
    operatorStack[++top] = ch;
}

char OperatorStack_pop()
{
    return operatorStack[top--];
}

char OperatorStack_peek()
{
    return operatorStack[top];
}

bool OperatorStack_isEmpty()
{
    return top == -1;
}

//OTHER FUNCTIONS=//
bool isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

// To perform the given operation on operands and return result
int performOperation(char operator, int op1, int op2)
{
    switch (operator)
    {
    case '+':
        return op2 + op1;
    case '-':
        return op2 - op1;
    case '*':
        return op2 * op1;
    case '/':
        return op2 / op1;
    case '^':
        return pow(op2, op1);
    default:
        return -1;
    }
}
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
bool hasHigherPrecedence(char c1, char c2)
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
            while (!OperatorStack_isEmpty() && !isOpeningBracket(OperatorStack_peek()) && hasHigherPrecedence(OperatorStack_peek(), exp[i])) // Checking precedence
            {
                postfix[k++] = OperatorStack_pop(); // If greater precedence, then pop and push top to postfix
            }
            OperatorStack_push(exp[i]); // If lower precedence, push to operator stack
        }
        else if (isOpeningBracket(exp[i])) // If opening bracket
        {
            OperatorStack_push(exp[i]); // Then push to operator stack
        }
        else if (isClosingBracket(exp[i])) // If closing bracket
        {
            while (!OperatorStack_isEmpty() && !isOpeningBracket(OperatorStack_peek())) // Till stack is empty and not opening bracket
            {
                postfix[k++] = OperatorStack_pop(); // pop operator stack and push to postfix
            }
            OperatorStack_pop(); // This is to pop the closing bracket
        }
    }
    while (!OperatorStack_isEmpty()) // For the remaining element in operator stack (if any)
    {
        postfix[k++] = OperatorStack_pop(); // Simply pop and push it to the postfix
    }
    printf("\nPostfix expression is \t"); // Printing postfix expression
    for (int i = 0; i < k; i++)
    {
        printf("%c", postfix[i]);
    }
}
// ===== POSTFIX EVALUATION FUNCTION ===== //
int postfixEval(char exp[])
{
    int n = strlen(exp);        // length of given expression
    for (int i = 0; i < n; i++) // for each character in expression
    {
        if (exp[i] == ' ')   // if character is space
            continue;        // then continue to next character
        if (isDigit(exp[i])) // if character is digit
        {
            int num = 0;
            while (isDigit(exp[i])) // To continue in case of multiple digits
            {
                num = num * 10 + (int)(exp[i] - '0'); // '0' is subtracted since exp[i] is a character
                i++;
            }
            i--;
            OperatorStack_push(num); // the resulting number is pushed to the stack
        }
        else // If operator
        {
            int op1 = OperatorStack_pop(); // Then pop two elements from stack
            int op2 = OperatorStack_pop();
            int result = performOperation(exp[i], op1, op2); // and perform the operation on them
            OperatorStack_push(result);                              // Push this result to the stack
        }
    }
    return OperatorStack_peek(); // The answer will be the top and only element remaining in stack
}
//=======MAIN FUNCTION=======//
int main()
{
    int ch;
    char exp[100],exp1[100]; // infix expression
    printf("Choose 1 to Convert infix to postfix expression \nchoose 2 to evaluvate a postfix expression\n");
    scanf("%d",&ch);
    switch(ch)
        {
           case(1): 
    printf("\nEnter infix expression without any spaces\n");
    //printf("\nFor unary - or +, use $. eg: a*-b must be entered as a*$b\n\n");
    scanf("%s", &exp);
    infix2postfix(exp);
break;
case(2):printf("\nEnter postfix expression, each item must be space separated\n");
    printf("For example: 12 32 + 44 /\n");
    scanf("%s",exp1);
    int EvaluatedValue = postfixEval(exp1);
    printf("\nResult Of evaluated postfix:  %d", EvaluatedValue);
    break;
    default :printf("error\n");
    }
}
