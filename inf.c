#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
struct node {
    char op;
    struct node* next;
};
struct node* top=NULL;

void push(char c) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->op = c;
    newnode->next = NULL;

    if(top==NULL)
        top = newnode;
    else {
        newnode->next = top;
        top = newnode;
    }
}

char pop() {
    if(top==NULL)
        return -1;

    else {
        struct node* temp = top;
        top = top->next;
        temp->next = NULL;
        char c = temp->op;
        free(temp);
        return c;
    }
}
char peek() {
    if(top==NULL)
        return -1;
    return top->op;
}

void display() {
    struct node* temp = top;
    if(top != NULL) {
    while(temp != NULL) {
        printf("%c", temp->op);
        temp = temp->next;
    }
    }
}

int isOperand(char c) {
    if(c>= 48 && c<= 57)
        return 1;
    return 0;
}

int preced(char c) {
        if(c=='^') return 3;
        else if(c=='*' || c=='\\') return 2;
        else if(c=='+' || c=='-') return 1;
        return -1;
}

int operate(int a, int b, char op) {
    int ans;
    switch (op) {
        case '+':
            ans = a+b;
            break;
        case '-':
            ans = a-b;
            break;
        case '*':
            ans = a*b;
            break;
        case '^':
            ans = pow(a,b);
            break;
        case '\\':
            ans = a/b;
            break;
    }

    return ans;
}
void evalExp(char* exp) {
    //printf("\n%s",exp);
    int i,j; int a=0,b=0,c=0;
    for(i=0;exp[i] != '#'; i++) {
        char ch = exp[i];
        if(isOperand(ch))
            push(ch-'0');
        else{
            a = pop();
            b = pop();
            c = operate(b,a,ch);
            push(c);
        }
        //printf("\n:%d:%d:%d:",a,b,c);
        //display();
    }
    int ans = pop();
    printf("\nEvaluated postfix expression: %d", ans);
    return;
}


void infToPost(char* exp) {
    int i,j=0;
    char* fin = (char*)malloc(sizeof(char));
    for(i=0;exp[i] != '#'; i++) {
        char ch = exp[i];
        if(isOperand(ch)) {
            fin[j] = ch;
            j++;
        }
        else if(ch == '(')
            push('(');

        else if(ch == ')') {
            do{
                fin[j] = pop();
                j++;
            }while(peek() != '(');
            pop();
        }

        else if(preced(ch) < preced(peek())) {
            do{
                fin[j] = pop();
                j++;
            }while(preced(peek()) >= preced(ch));
            push(ch);
        }

        else push(ch);
    //printf("\n%c:%s: ",ch , fin);
    //display();
    }
    fin[j] = '#';
    printf("\nPostfix Expression: %s\n", fin);
    evalExp(fin);

}

int main() {
    char str[30];
    printf("Enter expression: ");
    scanf("%s", str);
    infToPost(str);
    return 0;
}
