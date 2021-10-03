#include<stdio.h>
#include<stdlib.h>
void printArr(int a[], int n) {
    for(int i=0;i<n; i++)
    printf("%d ", a[i]);
    printf("\n");
}

void linSearch(int a[], int n, int num) {
    int flag = 0,i;
    for(i=0; i<n; i++) 
        if(a[i] == num) {
            flag = 1;
            break;
        }
    if(!flag) printf("Number %d not found. \n", num);
    else printf("Number %d found at position %d\n", num, i+1);
}

void binSearch(int a[], int n, int num) {
    int low = 0, high = n-1, mid, flag=0;
    while(low<=high) {
        mid = low + (high-low)/2;
        if(a[mid] == num) {flag=1; break; }

        else if(a[mid] > num) 
            high = mid-1;
        else
            low = mid+1;
    }

    if(!flag) printf("Number %d not found. \n", num);
    else printf("Number %d found at position %d\n", num, mid+1);
}

void bubSort(int a[], int n) {
    int temp;
    for(int i=0;i<n-1; i++) 
        for(int j=0; j<n-i-1; j++) 
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }

    printArr(a,n);
}

void insSort(int a[], int n) {
    for(int i = 1; i < n; i++){
        int key = a[i], j = i-1;
        while(j >=0 && a[j]> key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }

    printArr(a,n);
}

void selSort(int a[], int n) {
    int min;
    for(int i=0; i<n-1; i++) {
        min = i;
        for(int j=i+1; j<n; j++) 
            if(a[j] < a[min]) 
                min = j;

        int t = a[i];
        a[i] = a[min];
        a[min] = t;
    }

    printArr(a,n);
}
void genRandom(int a[], int n) {
    int t;
    for(int i=0; i<n; i++) {
        t = rand() % 100;
        a[i] = t;
    }
}
int main() {
    int n;
    printf("Enter n: "); scanf("%d", &n);
    int a[n];
    printf("Bubble sort: \n");
    genRandom(a, n);
    printArr(a, n);
    bubSort(a, n);

    printf("Insertion sort: \n");
    genRandom(a, n);
    printArr(a, n);
    insSort(a, n);

    printf("Selection sort: \n");
    genRandom(a, n);
    printArr(a, n);
    selSort(a, n);

    printf("Enter num to search: ");
    int num; scanf("%d", &num);
    printf("Using linear Search: \n");
    linSearch(a, n, num);
    printf("Using binary Search: \n");
    binSearch(a, n, rand()%100);
}