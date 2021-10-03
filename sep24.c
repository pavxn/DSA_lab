#include<stdio.h>

void k_large(int* a, int n, int k) {
    int a_copy[n];
    for(int i=0; i<n; i++) {
        a_copy[i] = a[i];
    }

    for(int i=0; i<n-1; i++){
        for(int j= 0; j<n-i-1; j++)
            if(a[j] < a[j+1]) {
                int  t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
    }

    int kth = a[k-1];
    printf("Kth largest: %d\n", kth);
    int temp = kth, sum=0;
    while(temp > 0) {
        sum += temp%10;
        temp /= 10;
    }

    if(a_copy[sum] == kth) printf("Matching\n");
    else printf("Not Matching\n");
}

int main() {
    int n,k;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }
    printf("\nEnter k: ");
    scanf("%d", &k);

    k_large(a, n, k);
}