#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    int balance;
    char accNo[10];
    struct node *next, *prev;
}*head, *tail;

void insert() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter accNo and balance: ");
    int bal; char acc[10];
    scanf("%s %d", acc, &bal);
    newnode->balance = bal; strcpy(newnode->accNo, acc);
    newnode->next = newnode->prev = NULL;
    
    if(head == NULL) 
        head = tail = newnode;
    else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    printf("Inserted Account %s\n", acc);
}

void disp() {
    if(head == NULL) {
         printf("Rep Empty\n");
        return;
    }

    struct node *temp = head;
     printf("\nAccNo\tBalance\n");
    while(temp != NULL) {
        if(temp->balance >= 1500)
            printf("%s\t%d\n", temp->accNo, temp->balance);
        temp = temp->next;
    }
}

void delete(char *accNo) {
    if(head == NULL) {
        printf("Rep Empty\n");
        return;
    }

    int flag=0;
    struct node *temp = head;

    while(temp != NULL) {
        if(strcmp(accNo, temp->accNo)==0) {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if(!flag) printf("Account Not found");
    
    else {
        if(head == tail) head=tail=NULL;
        
        else if(temp == head) {
            head = temp->next;
            head->prev = NULL;
        }

        else if(temp == tail) {
            tail = temp->prev;
            tail->next = NULL;
        }

        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        printf("\nAccount %s deleted.", temp->accNo);
        free(temp);
    }
}

int main() {
    char msg[] = "\n1. Insert account.\n2. Display Rep.\n3. Delete Account.\n4. Quit.\n: ";
    int ch;
    do {
        printf(msg);
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                insert();
                break;
            
            case 2:
                disp();
                break;
            
            case 3:
                {
                    char acc[5];
                    printf("Enter account No: "); scanf("%s", acc);
                    delete(acc);
                    break;
                }
            
            case 4:
                break;
        }
    }while(ch!=4);
}