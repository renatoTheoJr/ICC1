#include <stdio.h>

int main(){
    int base, expoente, result=1;
    scanf("%d %d", &base, &expoente);
    for(int i=0; i<expoente; i++){
        result*=base;
    }
    printf("%d\n", result);
    return 0;
}