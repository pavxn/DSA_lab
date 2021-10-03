#define max 10
#include <stdio.h>
#include <string.h>
struct p_file{
    int ts;
    char desc[20];
};

struct p_file queue[max];
int front=-1,rear=-1;
void insert(struct p_file item) {
    if((rear+1)%max == front)
        {
            printf("Maximum buffer capacity reached\n");
            return;
        }

    else if(front==-1 && rear==-1) {
        front = 0;
        rear = 0;
        queue[front] = item;
    }

    else {
        rear = (rear+1)%max;
        queue[rear] = item;
    }
    printf("Inserted file with ts: %d\n", item.ts);
}

void delete() {
    if(front == -1) {
        printf("Buffer empty\n\n");
        return;
    }

    else {
        printf("Printing file with ts: %d\n%s\n\n", queue[front].ts, queue[front].desc);
        if(front==rear)
        {front=-1;rear=-1;}
        else {
            front = (front+1)%max;
        }
    }
}

int main() {
    struct p_file item;
    int ch;
    while(1) {
        printf("1. Insert for printing\n2. Print item\n3. Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter ts and data: \n");
                scanf("%d", &(item.ts));
                fgets(item.desc,20,stdin);
                insert(item);
                break;

            case 2:
                delete();
                break;
            case 3:
                break;
        }
        if(ch==3) break;
    }

    return 0;
}
