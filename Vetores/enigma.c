// Renato Tadeu Theodoro Junior - 11796750
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    scanf("%*[^\r\n]s"); // Ignora tudo até o final da linha

    int rotor1[26], rotor2[26], rotor3[26];
    for(int i = 0; i < 26; i++){
        scanf("%d", &rotor1[i]);
    }
    for(int i = 0; i < 26; i++){
        scanf("%d", &rotor2[i]);
    }
    for(int i = 0; i < 26; i++){
        scanf("%d", &rotor3[i]);
    }

    scanf("%*[\r\n]s"); // Ignora o pula linha
    scanf("%*[^\r\n]s"); // Ignora tudo até o final da linha
    scanf("%*[\r\n]s"); // Ignora o pula linha

    char mensagem;
    int contadorRotor1 = 0, contadorRotor2 = 0;
    while (scanf("%c", &mensagem) != EOF){
        int asciiValor = (int) mensagem;
        int retorno;

        if(isalpha(mensagem)){
            if(isupper(mensagem)){
                retorno = rotor3[rotor2[rotor1[asciiValor - 65]]];
                printf("%c", retorno + 65);
            }else{
                retorno = rotor3[rotor2[rotor1[asciiValor - 97]]];
                printf("%c", retorno + 97);
            }
            
            int variavelAux;
            variavelAux = rotor1[0];
            for(int i = 1; i < 26; i++){
                rotor1[i - 1] = rotor1[i];
            }
            rotor1[25] = variavelAux;
            contadorRotor1++;

            if(contadorRotor1 == 26){
                variavelAux = rotor2[0];
    
                for(int i= 1; i < 26; i++){
                    rotor2[i - 1] = rotor2[i];
                }
                rotor2[25] = variavelAux;
                contadorRotor1 = 0;
                contadorRotor2++;
            }
        
            if(contadorRotor2 == 26){
                variavelAux = rotor3[0];
                for(int i = 1; i < 26; i++){
                    rotor3[i - 1] = rotor3[i];
                }
                rotor3[25] = variavelAux;
                contadorRotor2 = 0;
            }
        }else{
            printf("%c", mensagem);
        }
    }
    return 0;
}