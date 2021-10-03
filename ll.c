#include "stdio.h"
#include "stdlib.h"

struct node {
    int data;
    struct node* next;
};
struct node* top= NULL;
int odd=0, even=0;
void create(int t) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = t;
    newnode->next = NULL;

    if (top==NULL)
        top = newnode;
    else {
        newnode->next = top;
        top = newnode;
    }
}

void display() {
    if(top==NULL) {
        printf("Empty list.\n");
        return;
    }

    else {
        struct node* temp = top;
        do{
            printf("%d ", temp->data);
            temp = temp->next;
        }while(temp != NULL);
    }
}

int count() {
    int c=0;
    if(top == NULL) return c;
    else {
        struct node *temp = top;
        do{
            c++;
            temp=temp->next;
        }while(temp != NULL);
    }
    return c;
}

void countOddEven() {
    if(top == NULL) return ;
    else {
        struct node *temp = top;
        do{

            if((temp->data)%2 == 0)
                even++;
            else odd++;
            temp=temp->next;
        }while(temp != NULL);
    }
}

int main() {
    int ch; int inp,c;
    do{
        printf("\n1. Insert at end\n2. Display\n3. Count\n4. Exit\nChoice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &inp);
                create(inp);
                break;

            case 2:
                display();
                break;

            case 3:
                c = count();
                //countOddEven();
                //printf("\nCount: %d\nOdd: %d\nEven: %d", c, odd, even);
                printf("\nCount: %d", c);
                break;

            case 4:
                break;
        }
    }while(ch != 4);

    return 0;
}
