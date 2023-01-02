#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>

typedef struct Stack
{
    int top, size;
    int *arr;
} Stack;

void push(Stack *s, int val)
{
    if (s->top == s->size - 1)
    {
        printf("Stack overflow!\n");
        return;
    }
    s->arr[++(s->top)] = val;
}

int pop(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack underflow!\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

int top(Stack *s)
{
    return s->arr[s->top];
}

int postfix_eval(char *ch)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    s->size = 100;
    s->arr = (int *)malloc(sizeof(int) * s->size);
    int n1, n2, n3, num;

    for(int i=strlen(ch)-1;i>=0;i--){
        if (isdigit(ch[i]))
        {
            num = ch[i] - 48;
            push(s, num);
        }
        else
        {
            n1 = pop(s);
            n2 = pop(s);
            switch (ch[i])
            {
            case '+':
                n3 = n1 + n2;
                break;
            case '-':
                n3 = n1 - n2;
                break;
            case '*':
                n3 = n1 * n2;
                break;
            case '/':
                n3 = n1/n2;
                break;
            }
            push(s, n3);
        }
    }
    printf("The value of this expression is %d", top(s));
}

int main()
{
    char ch[100];
    printf("Enter the prefix expression : ");
    scanf("%[^\n]s", ch);
    postfix_eval(ch);
    return 0;
}