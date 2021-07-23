/* @author Renato Tadeu Theodoro Junior
   @USP  11796750
   @Title [5 - Alocação Dinâmica] Notação Polonesa Reversa
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double *popStack(double *stack, int *sizeStack){
   for(int i = 0; i < *sizeStack - 1; i++){
      stack[i] = stack[i + 1];
   }
   stack = realloc(stack, --(*sizeStack)  * sizeof(double));
   return stack;
}

int main(){
   double *stack;
   stack = NULL;
   int sizeStack = 0;
   char caracter;
   caracter = getchar();

   while (caracter != EOF){
      if(caracter != ' '){
         if(caracter == '+'){
            stack[1] = stack[1] + stack[0];
            stack = popStack(stack, &sizeStack);            
         }else if (caracter == '-'){
            stack[1] = stack[1] - stack[0];
            stack = popStack(stack, &sizeStack);            

         }else if (caracter == '*'){
            stack[1] = stack[1] * stack[0];
            stack = popStack(stack, &sizeStack);            

         }else if (caracter == '/'){
            stack[1] = stack[1] / stack[0];
            stack = popStack(stack, &sizeStack);            
         }else if(isalnum(caracter)){
            ungetc(caracter, stdin);
            double aux;
            scanf("%lf", &aux);
            sizeStack++;
            stack = realloc(stack, sizeStack * sizeof(double));
      
            for(int i = sizeStack - 1; i > 0; i--){
               stack[i] = stack[i - 1];
            }
            stack[0] = aux;
         }
      }
      caracter = getchar();
   }
   printf("Resultado: %.6lf\n", stack[0]);
   free(stack);

   return 0;
}