#include <stdio.h>
#include <stdlib.h>

enum week {Do, Se, Te, Qua, Qui, Sex, Sa};
int main(){
    int dia;
    scanf("%d",&dia);
    printf("         Abril 2021         \n");
    printf(" Do  Se  Te  Qu  Qu  Se  Sa \n");
    printf("                ");
    int semana = Qui;
    for(int i=1; i<31; i++){
        if(dia==i){
            printf("(%2d)", dia);
        }
        else{
            printf(" %2d ",i);
        }

        if(semana==Sa){
            printf("\n");
            semana=Do;
        }else{
            semana++;
        }

    }

}