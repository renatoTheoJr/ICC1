#include<stdio.h>

int main(){
    float a1, q, an, soman;
    int n;
    scanf("%f %f %d", &a1, &q, &n);
    float result=1;
    for(int i=0; i<n-1; i++){
        result*=q;
    }
    an = a1 * result;
    result = 1;
     for(int i=0; i<n; i++){
        result*=q;
    }
    soman = a1*(result-1)/(q-1);
    printf("%.2f\n%.2f\n", an, soman);
    return 0;
}