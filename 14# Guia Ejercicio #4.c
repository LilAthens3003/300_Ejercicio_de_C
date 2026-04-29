/*Que mediante un array almacene números tanto positivos como negativos y los muestre ordenados.*/

#include<stdio.h>
int main(){
	int  cantidad = 0;
	int i,j,vali;
	char basura;
	

	
	do{
		printf ("porfavor indique cuantos numeros quiere agregar en el array: ");
		vali = scanf("%d",&cantidad);
			 
		if (vali != 1){
			printf("[ERROR] Caracteres no permitidos, solo se aceptan numeros. \n\n");
			while(getchar() != '\n');
		}
		else if (cantidad <= 0){
					printf("[ERROR] el numero no puede ser 0 o menor  \n\n");
					vali = 0;
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
	float vector [cantidad],temporal;
	
	printf ("--- Arrays de %d para prdenar de manera ascendente ---\n",cantidad);
	for (i=0 ; i < cantidad ; i++){
		do{
			printf ("introduce el numero %d de %d numeros: ",i + 1,cantidad);
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
// --- 3. ORDENAMIENTO (Corregido el límite de j) ---
    for (i = 0 ; i < cantidad ; i++){
        for (j = 0 ; j < cantidad - i - 1 ; j++){ 
            if (vector[j] > vector[j + 1]){
                temporal = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temporal;
            }
        }
    }
    
    printf ("\n--- Resultado del array ordenado ---\n");
    for (i = 0 ; i < cantidad ; i++){  // Nota que aquí el ciclo va hasta 10
        printf ("Puesto %d del Array: %.2f\n", i + 1, vector[i]);
    }
	return 0;
}