// @author Renato Tadeu Theodoro Junior
// @usp 11796750
// @title [4 - Funções + Ponteiros] Horários Interplanetares
#include <stdio.h>
#include <string.h>

void earth(long long int *days,  long long int *seconds){
    *days = *seconds / 86400; // 86400 secs in a day
    *seconds = *seconds % 86400;
}

void mercury(long long int *days, long long int *seconds){
    *days = *seconds / 5068800; // 5068800 secs in a day
    *seconds = *seconds % 5068800;
}

void venus(long long int *days, long long int *seconds){
    *days = *seconds / 20995200; // 20995200 secs in a day
    *seconds = *seconds % 20995200;
}

void jupiter(long long int *days, long long int *seconds){
    *days = *seconds / 35760; // 35760 secs in a day
    *seconds = *seconds % 35760;
}

void calculationDefault(long long int *hours, long long int *minutes, long long int *seconds){
    *hours = *seconds / 3600; // 3600 secs in an hour
    *seconds = *seconds % 3600;
    *minutes = *seconds / 60; // 60 secs in a minute
    *seconds = *seconds % 60;
}

int main(){
    long long int secondsOriginal;
    char planet[9];
    scanf("%llu %s", &secondsOriginal, planet);

    long long int days = 0, hours = 0, minutes = 0, seconds = secondsOriginal;

    if(strcmp(planet, "Terra") == 0){
        earth(&days, &seconds);
    }else if(strcmp(planet, "Mercurio") == 0){
        mercury(&days, &seconds);
    }else if(strcmp(planet, "Venus") == 0){
        venus(&days, &seconds);
    }else if(strcmp(planet, "Jupiter") == 0){
        jupiter(&days, &seconds);
    }

    calculationDefault(&hours, &minutes, &seconds);

    printf("%llu segundos no planeta %s equivalem a:\n%llu dias, %llu horas, %llu minutos e %llu segundos\n",
        secondsOriginal, planet, days, hours, minutes, seconds);


    return 0;
}