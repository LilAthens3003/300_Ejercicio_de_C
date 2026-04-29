/*. Que lea 10 números por teclado, los almacene en un array y muestre la media.*/

#include <stdio.h>

int main(){
	float vector [10], suma = 0;
	int i,vali;
	char basura;
	
	
	printf ("--- Arraysde 10 numero, encontramos la media ---\n");
	for (i=0 ; i < 10 ; i++){
		do{
			printf ("introduce el numero %d de 10 numeros: ",i + 1);
			vali = scanf("%f",&vector[i]);
			 
			if (vali != 1){
				printf("[ERROR] Caracteres no permitidos, solo se aceptan numeros. \n\n");
				while(getchar() != '\n');
			}
			else{
                basura = getchar();
                if (basura != '\n'){
                    while(getchar() != '\n');
                    printf("[ERROR] Detectado basura o formato incorrecto.\n\n");
                    vali = 0;
                }
			}
		}while(vali != 1);	
	}
	
	for (i = 0 ; i < 10 ; i++){
		suma += vector[i];	
	}
	suma /= 10;
	
	printf("La media del array es: %.2f",suma);
	
	return 0;
}