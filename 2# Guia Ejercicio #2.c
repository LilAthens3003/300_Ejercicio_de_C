/*Problema 2: Programe un algoritmo en lenguaje C que, dados dos números enteros que entran 
como datos, indique si uno es divisor del otro.*/

#include <stdio.h>

int divisor (int num1 , int num2){
	int calculo = num1 % num2;
	int calculo2 = num2 % num1;
	if (calculo == 1 && calculo2 == 0){ //cuando uno no y el otro si 
		return 1;
	}
	else if (calculo == 0 && calculo2 == 1){  //cuando otro no y uno si   
		return 2;
	}
	else if (calculo == 0 && calculo2 == 0){ // cuando los dos si 
		return 3;
	}
	else { //cuando ninguno
		return 0;
	}
}

int main (){
	
	int num1,num2, vali, op;
	char basura;
	
	do{
		
		printf("Porfavor ingrese el primer numero dividendo: ");
		vali = scanf("%d",&num1);
		if (vali != 1){
			printf("[ERROR] Caracteres no permitidos, solo se aceptan numeros. \n\n");
			while(getchar() != '\n');
		}
		else if (vali <= 0){
			printf("[ERROR] el numero no puede ser 0 o menor que 0. \n\n");
			while(getchar() != '\n');
			vali = 0;
		}
		else {
			basura = getchar();
			if (basura != '\n'){
				while(getchar() != '\n');
				printf("[ERROR] detectado decimales o basura. solo es aceptan numeros enteros\n\n");
				vali = 0;
			}
		}
	}while(vali != 1);
	
		do{
		
		printf("Porfavor ingrese el primer numero dividendo: ");
		vali = scanf("%d",&num2);
		if (vali != 1){
			printf("[ERROR] Caracteres no permitidos, solo se aceptan numeros. \n\n");
			while(getchar() != '\n');
		}
		else if (vali <= 0){
			printf("[ERROR] el numero no puede ser 0 o menor que 0. \n\n");
			while(getchar() != '\n');
			vali = 0;
		}
		else {
			basura = getchar();
			if (basura != '\n'){
				while(getchar() != '\n');
				printf("[ERROR] detectado decimales o basura. solo es aceptan numeros enteros\n\n");
				vali = 0;
			}
		}
	}while(vali != 1);
	
	op = divisor (num1,num2);
	
switch(op){
        case 1:
            printf("\nEl numero %d NO es divisible por %d, pero %d SI es divisible por %d\n", num1, num2, num2, num1);
            break;
        case 2:
            printf("\nEl numero %d SI es divisible por %d, pero %d NO es divisible por %d\n", num1, num2, num2, num1);
            break;
        case 3:
            printf("\nAmbos numeros %d y %d son divisibles entre si \n", num1, num2);
            break;
        case 0:
            printf("\nNinguno de los numeros es divisible por el otro.\n");
            break;  
    }
	
	return 0;
}