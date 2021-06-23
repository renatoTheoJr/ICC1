#include<stdio.h>

int main(){
    long long int a1, r, n, an, soman;
    scanf("%lld %lld %lld", &a1, &r, &n);
    an = a1 + (n-1)*r;
    soman = ((a1+an)*n)/2;
    printf("%lld\n%lld\n", an, soman);
    return 0;
}