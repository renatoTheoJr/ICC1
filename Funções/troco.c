// @author Renato Tadeu Theodoro Junior
// @usp 11796750
// @title [4 - Funções + Ponteiros] Troco em Moedas
#include <stdio.h>

int divisionWithRest (int dividend, int divider, int *rest){
    *rest = dividend % divider;
    return dividend / divider;
}

void calculationChange (int cents, int *oneReal, int *fiftyCents, int *twentyFiveCents, int *tenCents, int *fiveCents, int *oneCent){
    *oneReal = divisionWithRest(cents, 100, &cents);
    *fiftyCents = divisionWithRest(cents, 50, &cents);
    *twentyFiveCents = divisionWithRest(cents, 25, &cents);
    *tenCents = divisionWithRest(cents, 10, &cents);
    *fiveCents = divisionWithRest(cents, 5, oneCent);
}

int main(){
    int cents;
    scanf("%d", &cents);

    int oneReal = 0, fiftyCents = 0, twentyFiveCents = 0, tenCents = 0, fiveCents = 0, oneCent = 0;
    calculationChange(cents, &oneReal, &fiftyCents, &twentyFiveCents, &tenCents, &fiveCents, &oneCent);

    printf("O valor consiste em %d moedas de 1 real\n"
            "O valor consiste em %d moedas de 50 centavos\n"
            "O valor consiste em %d moedas de 25 centavos\n"
            "O valor consiste em %d moedas de 10 centavos\n"
            "O valor consiste em %d moedas de 5 centavos\n"
            "O valor consiste em %d moedas de 1 centavo\n", 
            oneReal, fiftyCents, twentyFiveCents, tenCents, fiveCents, oneCent
        );
    
    return 0;
}