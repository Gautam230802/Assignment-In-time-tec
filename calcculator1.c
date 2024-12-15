#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/*To check character is operator or not*/
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int isSpace(char c)
{
    return ( c==' ');
}

int isDigit(char c)
{
    if(c>='0' && c<='9')
    {
        return 1;
    }
    else{
        return 0;
    }
}
int findLen(char expression[])
{   int length =0;
    int i=0;
    while(expression[i]!='\0')
    {
        i++;
        length++;
    }
    return length;
}

/* To give different precedence  to different operator*/
int precedence(char c) {
    if (c == '/')
        return 4;
    else if (c == '*')
        return 3;
    else if (c == '+')
        return 2;
    else
        return 1;
}

/* If expression contain whitespace then remove it*/
void spaceRemover(char expression[], char* exp)
{
    int len =findLen(expression);
    int j =0;
    for(int i =0;i<len;i++)
    {
        if(expression[i]!=' ')
        {
            exp[j]=expression[i];
            j++;
        }
    }
    exp[j]='\0';
}

/* To check expression is valid or not*/
int isValid(char exp[]) {
    int length = findLen(exp);
    if (length == 0) /* expression should not be empty*/
       { return 0;}
    if ((isOperator(exp[0]) && exp[0]!='-') || isOperator(exp[length - 1]))  /* first and last character should not operator , except first can be '-'*/
       { return 0;}

    for (int i = 0; i < length; i++) {
        char c = exp[i];
        if (!isDigit(c) && !isOperator(c) && !isSpace(c) ) {  /* check expression contain only digit, operator, space*/
            return 0;
        }

        
        if (i > 0 && isOperator(c) && isOperator(exp[i - 1])) 
           {if(!(c == '-' && !isOperator(exp[i - 2])))   /*Multiple operator should not be there
                                                            like*+ , but*- will be accepted  */
           {return 0;}
           }
        
        if (c == '/' && i + 1 < length && exp[i + 1] == '0') {    /* No zero in divisior*/
            printf("Error: Division by zero \n");
            return 0;
        }
    }
    return 1;
}

/* Infix to postfix conversion*/
char* infixToPostfix(char* exp) {
    int len = findLen(exp);
    char* postfix = (char*)malloc((len * 2) * sizeof(char)); 
    char stack[100];
    int top = -1;
    int j = 0;

    for (int i = 0; i < len; i++) {
        char c = exp[i];

        
        if ((c == '-' && (i == 0 || isOperator(exp[i - 1]))) || isDigit(c)) { /* if positive or negative digit*/
            postfix[j++] = c;
            while (i + 1 < len && isDigit(exp[i + 1])) {
                postfix[j++] = exp[++i];
            }
            postfix[j++] = ' '; /* for space between operator and digit*/
        } else if (isOperator(c)) {
            while (top != -1 && precedence(c) <= precedence(stack[top])) {
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            stack[++top] = c;
        }
    }

    while (top != -1) {
        postfix[j++] = stack[top--]; /* if operator left in stack*/
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';
    return postfix;
}

/* postfix evalution*/
int postfixEvaluation(char* postfix) {
    int digitStore[100];
    int top = -1;
    int len = findLen(postfix);
    
    for (int i = 0; i < len; i++) {
        char c = postfix[i];
        if (isDigit(c) || (c == '-' && isDigit(postfix[i + 1]))) {
            int digit = 0;
            int sign = 1;
            if (c == '-') {
                sign = -1;        /* To handle negative digits*/
                i++;
            }
            while (i < len && isDigit(postfix[i])) {
                digit = digit * 10 + (postfix[i++] - '0'); /* to handle multiple digits*/
            }
            i--; 
            digitStore[++top] = digit * sign;
        } else if (isOperator(c)) {
            int num1 = digitStore[top--];
            int num2 = digitStore[top--];

            switch (c) {
                case '+':
                             digitStore[++top] = num2 + num1; 
                            break;
                case '-': 
                            digitStore[++top] = num2 - num1; 
                            break;
                case '*': 
                            digitStore[++top] = num2 * num1; 
                            break;
                case '/': 
                        if (num1 == 0) {
                            printf("Division by zero error\n");
                            return 0;
                        }
                        digitStore[++top] = num2 / num1; 
                        break;
            }
        }
    }
    return digitStore[top];
}

int main() {
    char exp[100];
    char expression[100];
    printf("Please Enter the Expression: ");
    gets(expression);
    printf("%s\n",expression);
    spaceRemover(expression,exp);
    if (!isValid(exp)) {
        printf("Error: Invalid expression\n");
        return 0;
    }

    char* postfix = infixToPostfix(exp);
    //printf("Postfix is: %s\n", postfix);//

    int result = postfixEvaluation(postfix);
    printf("Result is: %d\n", result);

    
    return 0;
}
