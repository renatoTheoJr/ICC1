
#include <stdio.h>
#include <math.h>

int main(){
    float base, expoente;
    scanf("%f %f", &base,&expoente);
    printf("%.4f\n", pow(base, expoente));
    return 0;
}