#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/*To check character is operator or not*/
int isoperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
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
void space_remover(char expression[], char* exp)
{
    int len =strlen(expression);
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
int isvalid(char exp[]) {
    int length = strlen(exp);
    if (length == 0) /* expression should not be empty*/
       { return 0;}
    if ((isoperator(exp[0]) && exp[0]!='-') || isoperator(exp[length - 1]))  /* first and last character should not operator , except first can be '-'*/
       { return 0;}

    for (int i = 0; i < length; i++) {
        char c = exp[i];
        if (!isdigit(c) && !isoperator(c) && !isspace(c) ) {  /* check expression contain only digit, operator, space*/
            return 0;
        }

        
        if (i > 0 && isoperator(c) && isoperator(exp[i - 1])) 
           {if(!(c == '-' && !isoperator(exp[i - 2])))   /*Multiple operator should not be there
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
    int len = strlen(exp);
    char* postfix = (char*)malloc((len * 2) * sizeof(char)); 
    char stack[100];
    int top = -1;
    int j = 0;

    for (int i = 0; i < len; i++) {
        char c = exp[i];

        
        if ((c == '-' && (i == 0 || isoperator(exp[i - 1]))) || isdigit(c)) { /* if positive or negative digit*/
            postfix[j++] = c;
            while (i + 1 < len && isdigit(exp[i + 1])) {
                postfix[j++] = exp[++i];
            }
            postfix[j++] = ' '; /* for space between operator and digit*/
        } else if (isoperator(c)) {
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
    int digit_store[100];
    int top = -1;
    int len = strlen(postfix);
    
    for (int i = 0; i < len; i++) {
        char c = postfix[i];
        if (isdigit(c) || (c == '-' && isdigit(postfix[i + 1]))) {
            int digit = 0;
            int sign = 1;
            if (c == '-') {
                sign = -1;        /* To handle negative digits*/
                i++;
            }
            while (i < len && isdigit(postfix[i])) {
                digit = digit * 10 + (postfix[i++] - '0'); /* to handle multiple digits*/
            }
            i--; 
            digit_store[++top] = digit * sign;
        } else if (isoperator(c)) {
            int num1 = digit_store[top--];
            int num2 = digit_store[top--];

            switch (c) {
                case '+':
                             digit_store[++top] = num2 + num1; 
                            break;
                case '-': 
                            digit_store[++top] = num2 - num1; 
                            break;
                case '*': 
                            digit_store[++top] = num2 * num1; 
                            break;
                case '/': 
                        if (num1 == 0) {
                            printf("Division by zero error\n");
                            return 0;
                        }
                        digit_store[++top] = num2 / num1; 
                        break;
            }
        }
    }
    return digit_store[top];
}

int main() {
    char exp[100];
    char expression[100];
    printf("Please Enter the Expression: ");
    gets(expression);
    printf("%s\n",expression);
    space_remover(expression,exp);
    if (!isvalid(exp)) {
        printf("Error: Invalid expression\n");
        return 0;
    }

    char* postfix = infixToPostfix(exp);
    //printf("Postfix is: %s\n", postfix);//

    int result = postfixEvaluation(postfix);
    printf("Result is: %d\n", result);

    
    return 0;
}
