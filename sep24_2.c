#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head = NULL, *tail = NULL;

void insert(int num) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;
    
    if(head == NULL) {head = newnode; tail = head;}
    else {
        if(num < head->data) {
            newnode->next = head;
            head = newnode;
        }
        else if(num> tail->data) {
            tail->next = newnode;
            tail = newnode;
        }

        else{
        struct node *temp = head;
        while(temp->next->data < num) {
            if(temp->next->data == num) {
                printf("\n%d already present.", num);
                free(newnode);
                break;
            }
            else {
                newnode->next = temp->next;
                temp->next = newnode;
            }
        }
        }
    }
}

void countPair(int x) {
    struct node *t1, *t2; int flag = 0;
    if(head==NULL) { printf("\nEmpty list."); return; }
    else{
        t1 = head;
        while(t1 != NULL) {
            t2 = head;
            while(t2!=NULL) {
                int n = t1->data, m = t2->data;
                if(n*m == x) {
                    printf("(%d, %d)\n", n, m); flag=1;
                    break;
                }
                t2 = t2->next;
            }
            t1 = t1->next;
        }
    }
    if(!flag) printf("No pair found.");
}

void del_list() {
    struct node *temp = head, *temp2;
    if(head==NULL) return;
    else {
        while(temp != NULL) {
            temp2 =  temp->next;
            free(temp);
            temp = temp2;
        }
    }
}
int main() {
    int ch; char text[] = "1. Add element to list\n2. Check & count pairs\n3. Quit\nChoice: ";
    do{
       printf(text);
       int temp;
       scanf("%d", &ch);
       switch(ch){

        case 1:
        scanf("%d", &temp);
        insert(temp);
        break;

        case 2:
        printf("Enter element to find pairs: ");
        scanf("%d", &temp);
        countPair(temp);
        break;

        case 3:
        del_list();
        break;
       }
    }while(ch != 3);
    return 0;
}