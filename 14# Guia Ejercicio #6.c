/*Que gestiona las notas de una clase de 20 alumnos de los cuales sabemos el nombre y la nota. El 
programa debe ser capaz de:
1. Buscar un alumno.
2. Modificar su nota.
3. Realizar la media de todas las notas.
4. Realizar la media de las notas menores de 5.
5. Mostrar el alumno que mejores notas ha sacado.
6. Mostrar el alumno que peores notas ha sacado.*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void menu(){
	printf("1. Buscar un alumno.\n");
	printf("2. Modificar su nota.\n");
	printf("3. Realizar la media de todas las notas.\n");
	printf("4. Realizar la media de las notas menores de 5.\n");
	printf("5. Mostrar el alumno que mejores notas ha sacado.\n");
	printf("6. Mostrar el alumno que peores notas ha sacado.\n");
	printf("7. Agregar estudiante mas su nota\n");
	printf("8. salir del programa\n");
}

int main(){
	int opcion, nota = 3,alumno = 3, cantidad = 3 ;
	float notas [nota];
	char alumnos[alumno][50], basura,pregunta;
	int i, j,k, es_valido = 1, vali;
		
	for(i = 0; i < cantidad; i++){
		printf("Por favor agregue como minimo 3 alumnos\n");
      	do {
      		es_valido = 1;
        	printf("\nPor favor ingrese el nombre del alumno %d: ", i + 1);
        	scanf(" %[^\n]", alumnos[i]);
        	while(getchar() != '\n');
        	for(k = 0; alumnos[i][k] != '\0'; k++){
           		if(!isalpha(alumnos[i][k]) && alumnos[i][k] != ' '){
                es_valido = 0;
                printf("[ERROR] El nombre solo puede contener letras y espacios.\n\n");
                break; 
               	}
           	}
       	} while(es_valido == 0);
       	
		
		do{
			printf("Ahora por favor ingrese la nota de %s: ",alumnos[i]);
			vali = scanf("%f", &notas[i]);	
			if (vali != 1){
				printf("[ERROR] Caracteres no permitidos, solo se aceptan numeros. \n\n");
				while(getchar() != '\n');
			}
			else if (notas[i] < 0){
				printf("[ERROR] el numero no puede ser menor que 0. \n\n");
				while(getchar() != '\n');
				vali = 0;
			}
			else if (notas[i] < 0 || notas[i] > 20){
				printf("[ERROR] el numero no puede ser menor a 0 o mayor a 20. la notas se comprenden de 00 a 20. \n\n");
				while(getchar() != '\n');
				vali = 0;
			}	
			else {
				basura = getchar();
				if (basura != '\n'){
					while(getchar() != '\n');
					printf("[ERROR] detectado basura. solo es aceptan numeros \n\n");
					vali = 0;
				}
			}
		}while(vali != 1);
		system("cls");	
	}
	
	do{
		printf("--- Menu de opciones ---");
		printf("\nPor favor selecciones una opcion: \n");
		menu();
		scanf("%d",&opcion);
	
	
		switch (opcion){
			case 1:
				do{
					printf("Aqui le presento la lista de estudiantes en sistema: ");
					for (i=0;i<cantidad;i++){
						printf("\n%d. %s  su nota es: %2.f",i+1,alumnos[i],notas[i]);
					}
					printf("\n Desea regresar al menu ? [S][N] \n");
					scanf(" %[^\n]", pregunta);
					toupper (pregunta);
					if (pregunta == 'S'){
						system("cls");
					}
				}while ( pregunta != 'S');
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
		}		
	}while(opcion != 8);
	
	return 0;
}