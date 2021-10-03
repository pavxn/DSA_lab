#include "stdlib.h"
#include "stdio.h"
#include <string.h>
struct node {
    int id;
    int price;
    char name[20];
    struct node* next;
};

struct node *head=NULL, *tail=NULL;

void insert(int id_in, int price_in, char name_in[]) {
    printf("Inserting item.\n");
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->id = id_in;
    newnode->price = price_in;
    strcpy(newnode->name,name_in);
    newnode->next = NULL;

    if(head == NULL) {
        head = newnode;
        tail = head;
    }

    else if( price_in > head->price) {
        newnode->next = head;
        head = newnode;
    }

    else if( price_in < tail->price) {
        tail->next = newnode;
        tail = newnode;
    }

    else {
        struct node *temp = head;

        while(temp->next->price > price_in)
            temp = temp->next;

        newnode->next = temp->next;
        temp->next = newnode;
    }

    printf("Inserted item.\n");
}

void sell(int id_in) {
    if(head==NULL) {
        printf("No items in inventory.\n");
        return;
    }
    if(id_in == head->id) {
        struct node* temp = head->next;
        head->next = NULL;
        printf("Sold item %d(%s).\n", head->id, head->name);//print sold item
        free(head);
        head = temp;
    }

    else if( id_in == tail->id) {
        struct node* temp = head;

        while (temp->next != tail)
            temp = temp->next;

        temp->next = NULL;
        printf("Sold item %d(%s).\n", tail->id, tail->name);//print sold item
        free(tail);
        tail = temp;
    }

    else {
        struct node *temp = head, *temp2;

        while(temp->next->id != id_in)
            temp = temp->next;

        temp->next = temp2->next;
        printf("Sold item %d(%s).\n", temp2->id, temp2->name);//print sold item
        free(temp2);
    }
}

int main() {
    char menu[] = "\n1. Insert item\n2. Sell item\n3. Quit\nEnter choice: ", name[20];
    int ch,id,price;
    do {
        printf("%s", menu);
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter ID, Name, Price: ");
                scanf("%d%s%d", &id, name, &price);
                //fgets(name,20,stdin);
                //scanf("%d", &price);

                insert(id,price,name);
                break;

            case 2:
                printf("\nEnter ID to sell: ");
                scanf("%d", &id);

                sell(id);
                break;

            case 3:
                break;
            default:
                printf("Try again.\n");
                break;
        }
    } while(ch != 3);
    return 0;
}
