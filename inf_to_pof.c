#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

struct stack{
	char a[MAXSIZE];
	int top;
};
struct int_stack{
	int a[MAXSIZE];
	int top;
};
void create(struct stack * s)
{
	s->top = -1;
}
void is_create(struct int_stack * s)
{
	s->top = -1;
}
int isFull(struct stack * s)
{
	if(s->top == MAXSIZE-1)
		return 1;
	else
		return 0;
}
int is_isFull(struct int_stack * s)
{
	if(s->top == MAXSIZE-1)
		return 1;
	else
		return 0;
}
int isEmpty(struct stack * s)
{
	if(s->top == -1)
		return 1;
	else
		return 0;
}
int is_isEmpty(struct int_stack * s)
{
	if(s->top == -1)
		return 1;
	else
		return 0;
}
void push(struct stack * s, char n)
{
	if(isFull(s) == 1)
	{
		printf("Stack is full. Cannot Push\n");
	}
	else
	{
		(s->top)++;
		s->a[s->top] = n;
	}
}
void is_push(struct int_stack * s, int n)
{
	if(is_isFull(s) == 1)
	{
		printf("Stack is full. Cannot Push\n");
	}
	else
	{
		(s->top)++;
		s->a[s->top] = n;
	}
}
void pop(struct stack * s)
{
	if(isEmpty(s) == 1)
		printf("Cannot pop the element!!\n");
	else
		(s->top)--;
}
int is_pop(struct int_stack * s)
{
	if(is_isEmpty(s) == 1)
	{
		printf("Cannot pop the element!!\n");
		return -1;
	}
	else
	{
		int data = s->a[s->top];
		(s->top)--;
		return data;
	}
}
char peek(struct stack s)
{
	printf("  %c  \n",s.a[s.top]);
	return s.a[s.top];
}
int is_peek(struct int_stack s)
{
	printf(" %.2f  \n",(float)s.a[s.top]);
	return s.a[s.top];
}
int Operator(char a)
{
    if (a == '+' || a == '-' || a == '*' || a == '/' || a == '^' || a == '%')
        return 1;
    else
        return 0;
}
int Paranthesis(char a)
{
    if (a == '(' || a == ')')
        return 1;
    else
        return 0;
}
int operator_precedence(char a)
{
    if (a == '^')
        return 3;
    else if (a == '*' || a == '/' || a == '%')
        return 2;
    else if (a == '+' || a == '-')
        return 1;
    else
        return 0;
}
int length_of_string(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
void inf_to_postf(struct stack *s, char infix[], char postfix[])
{
    int n = length_of_string(infix);
    int i, j = 0;
    for (i = 0; i < n; i++)
    {
        if (Paranthesis(infix[i]) == 0)
        {
            if (Operator(infix[i]) == 1)
            {
                while (isEmpty(s) == 0 && operator_precedence(s->a[s->top]) >= operator_precedence(infix[i]))
                {
                    postfix[j] = s->a[s->top];
                    pop(s);
                    j++;
                }
                push(s, infix[i]);
            }
            else
            {
                postfix[j] = infix[i];
                j++;
            }
        }
        else
        {
            if (infix[i] == '(')
                push(s, '(');
            else
            {
                while (s->a[s->top] != '(')
                {
                    postfix[j] = s->a[s->top];
                    pop(s);
                    j++;
                }
                pop(s);
            }
        }
    }

    while (isEmpty(s) == 0)
    {
        postfix[j] = s->a[s->top];
        pop(s);
        j++;
    }

    postfix[j] = '\0';
}

int pw(int a, int b)
{
    int p = 1;
    while (b--)
        p = a * p;
    return p;
}
int evaluate(int n1, int n2, char o)
{
    int x;
    switch (o)
    {
    case '+':
        x = n1 + n2;
        break;

    case '-':
        x = n1 - n2;
        break;

    case '*':
        x = n1 * n2;
        break;

    case '/':
        x = n1 / n2;
        break;

    case '%':
        x = n1 % n2;
        break;

    case '^':
        x = pw(n1, n2);
        break;

    default:
        printf("Error! Unidentified operator\n");
    }
    return x;
}
int evaluate_postfix(char postfix[])
{
    struct int_stack st;
    is_create(&st);
    float ans;
    int i, num1;
    for (i = 0; i < length_of_string(postfix); i++)
    {
        if (Operator(postfix[i]) == 1)
        {
            int n1, n2;
            n2 = is_pop(&st);
            n1 = is_pop(&st);
            ans = evaluate(n1, n2, postfix[i]);
            is_push(&st, ans);
        }
        else
        {
            num1 = postfix[i] - 48;
            is_push(&st, num1);
        }
    }
    int t = is_pop(&st);
    return t;
}


int main(){
	struct stack s;
    create(&s);

    char infix[MAXSIZE], postfix[MAXSIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    printf("----------------------\n");
    inf_to_postf(&s, infix, postfix);
    printf("Infix expression is %s\n", infix);
    printf("Postfix expression is %s\n", postfix);
    printf("----------------------\n");
    int a = evaluate_postfix(postfix);
    printf("Evaluation of postfix : %d\n", a);

	return 0;
}




