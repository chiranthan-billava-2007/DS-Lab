#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;

    if (c == '*' || c == '/')
        return 2;

    return 0;
}

void displayIteration(int iteration, char c, char postfix[], int j)
{
    int i;

    printf("%-10d %-10c ", iteration, c);

    printf("%-15s ", top == -1 ? "EMPTY" : "");

    if (top != -1)
    {
        for (i = 0; i <= top; i++)
            printf("%c", stack[i]);
    }

    printf("%*s", 15, "");

    printf("%s\n", postfix);
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char c;
    int iteration = 1;

    printf("\n%-10s %-10s %-15s %-15s\n",
           "Iteration", "Symbol", "Stack", "Postfix");

    printf("------------------------------------------------------------\n");

    for (i = 0; infix[i] != '\0'; i++)
    {
        c = infix[i];

        if ((c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9'))
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }

            if (top != -1)
                pop();   // Remove '('
        }
        else
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(c))
            {
                postfix[j++] = pop();
            }

            push(c);
        }

        postfix[j] = '\0';

        displayIteration(iteration, c, postfix, j);
        iteration++;
    }

    /* Pop remaining operators */
    while (top != -1)
    {
        postfix[j++] = pop();
        postfix[j] = '\0';

        printf("%-10d %-10s ", iteration, "POP");

        if (top == -1)
            printf("%-15s", "EMPTY");
        else
        {
            int k;
            for (k = 0; k <= top; k++)
                printf("%c", stack[k]);
        }

        printf("%15s%s\n", "", postfix);

        iteration++;
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("\nPostfix expression: %s\n", postfix);

    return 0;
}
