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
#include <string.h>

void menu(){
	printf("1. Buscar un alumno.\n");
	printf("2. Modificar su nota.\n");
	printf("3. Realizar la media de todas las notas.\n");
	printf("4. Realizar la media de las notas menores de 5.\n");
	printf("5. Mostrar el alumno que mejores notas ha sacado.\n");
	printf("6. Mostrar el alumno que peores notas ha sacado.\n");
	printf("7. Agregar estudiante mas su nota\n");
	printf("8. salir del programa\n");
	printf("\nRespuesta: ");
}

int main(){
	int opcion, nota = 3,alumno = 3, cantidad = 3, buscar, five ;
	float notas [200], promedio, mejornota;
	char alumnos[200][50], basura,pregunta, mejoralumno[50];
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
		while(getchar() != '\n');
	
		switch (opcion){
			case 1:
				do{
					system("cls");
					printf("La lista de estudiantes en sistema: ");
					for (i=0;i<cantidad;i++){
						printf("\n%d. %s  su nota es: %.2f",i+1,alumnos[i],notas[i]);
					}
					do{
						es_valido = 1;
						printf("\n Desea regresar al menu ? [S][N]: ");
						scanf(" %c", &pregunta);
						pregunta = toupper(pregunta);
						
						if (pregunta != 'S'||pregunta !='N'){
							printf("[ERROR] La respuesta debe ser 'S' o 'N', ya sea en mayuscula o minuscula");
							es_valido = 0;
						}
					}while(es_valido == 0);
				}while ( pregunta != 'S');
				system("cls");
				break;
			case 2:
				do{
					system("cls");
					
					
					do{
						printf("Indique el numero de lista del estudiante que desea cambiarle la nota:  ");
		    			vali = scanf("%d", &buscar);
						if (vali != 1){
							printf("[ERROR] Caracteres no permitidos, solo se aceptan numeros. \n\n");
							while(getchar() != '\n');
						}
						else if (notas[i] < 0){
							printf("[ERROR] el numero no puede ser menor que 0. \n\n");
							while(getchar() != '\n');
							vali = 0;
						}
						else if (buscar < cantidad || buscar > cantidad){
							printf("[ERROR] Hay %d estudiantes en lista, no puede ser un numero mayor o menor. \n\n", cantidad);
							while(getchar() != '\n');
							vali = 0;
						}	
						else {
							basura = getchar();
							if (basura != '\n'){
								while(getchar() != '\n');
								printf("[ERROR] detectado basura. solo es aceptan numeros enteros, sin desimales. \n\n");
								vali = 0;
							}
						}
					}while(vali != 1);
					
					i = buscar;
					printf("\nEl estudiante: %s Y su nota es: %.2f ",alumnos[i-1],notas[i-1]);
					
					
					
					do{
						printf("\nIndique la numeva nota del estudiante: ");
						vali = scanf("%f",&notas[i-1]);
						if (vali != 1){
							printf("[ERROR] Caracteres no permitidos, solo se aceptan numeros. \n\n");
							while(getchar() != '\n');
						}
						else if (notas[i-1] < 0){
							printf("[ERROR] el numero no puede ser menor que 0. \n\n");
							while(getchar() != '\n');
							vali = 0;
						}
						else if (notas[i-1] < 0 || notas[i-1] > 20){
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
		
					
					printf("\n--- Cambio Completado ---\n\n");
					printf("\n Desea realizar otro cambio [S][N]: ");
					scanf(" %c", &pregunta);
					pregunta = toupper(pregunta);
					while(getchar() != '\n');
					if (pregunta == 'S'){
						system("cls");
					}
				}while ( pregunta != 'N');
				system("cls");
				break;
			case 3:
				do{
					promedio = 0;
					system("cls");
					for (i=0;i<cantidad;i++){
						promedio += notas[i];
					}
					promedio /= cantidad;
					printf("La media de las notas de %d estudiantes es: %.2f ", cantidad, promedio);
					printf("\n Desea regresar al menu ? [S][N]: ");
					scanf(" %c", &pregunta);
					pregunta = toupper(pregunta);
					while(getchar() != '\n');
					if (pregunta == 'S'){
						system("cls");
					}
				}while ( pregunta != 'S');
				system("cls");
				break;
			case 4:
				do{
					promedio = 0;
					five = 0;
					system("cls");
					five = 0;
					for (i=0;i<cantidad;i++){
						if(notas[i] <= 5){
							promedio += notas[i];
							five++;
						}
					}
					if (five == 0){
						printf("\nNingun alumno saco menor nota que 05");
					}
					else{
						promedio /= five;
						printf("La media de las notas menores a 05 estudiantes es: %.2f ", promedio);
					}
					printf("\n Desea regresar al menu ? [S][N]: ");
					scanf(" %c", &pregunta);
					pregunta = toupper(pregunta);
					while(getchar() != '\n');
					if (pregunta == 'S'){
						system("cls");
					}
				}while ( pregunta != 'S');
				system("cls");
				break;
			case 5:
				do{
					system("cls");
					mejornota = notas[0];
        			strcpy(mejoralumno, alumnos[0]);
					for (i=1;i<cantidad;i++){
						if(notas[i] > mejornota){
							mejornota = notas[i]; 
                			strcpy(mejoralumno, alumnos[i]);
						}
					}
					printf("El estudiante con mejor nota es %s y su nota fue: %.2f ",mejoralumno, mejornota);
					printf("\n Desea regresar al menu ? [S][N]: ");
					scanf(" %c", &pregunta);
					pregunta = toupper(pregunta);
					while(getchar() != '\n');
					if (pregunta == 'S'){
						system("cls");
					}
				}while ( pregunta != 'S');
				system("cls");
				break;
			case 6:
				do{
					system("cls");
					mejornota = notas[0];
        			strcpy(mejoralumno, alumnos[0]);
					for (i=1;i<cantidad;i++){
						if(notas[i] < mejornota){
							mejornota = notas[i]; 
                			strcpy(mejoralumno, alumnos[i]);
						}
					}
					printf("El estudiante con la peor nota es %s y su nota fue: %.2f ",mejoralumno, mejornota);
					printf("\n Desea regresar al menu ? [S][N]: ");
					scanf(" %c", &pregunta);
					pregunta = toupper(pregunta);
					while(getchar() != '\n');
					if (pregunta == 'S'){
						system("cls");
					}
				}while ( pregunta != 'S');
				system("cls");
				break;
			case 7:
				do{
					cantidad ++;
					for(i = cantidad - 1; i < cantidad; i++){
					
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
					}
					printf("\n Desea agregar otro alumno ? [S][N]: ");
					scanf(" %c", &pregunta);
					pregunta = toupper(pregunta);
					while(getchar() != '\n');
					if (pregunta == 'S'){
						system("cls");
					}
				}while ( pregunta != 'N');
				system("cls");
				break;
			case 8:
				printf("\n Seguro que Desea cerrar el programa ? [S][N]: ");
					scanf(" %c", &pregunta);
					pregunta = toupper(pregunta);
					while(getchar() != '\n');
					if (pregunta == 'S'){
						system("cls");
					}
				break;
		}		
	}while(opcion != 8);
	
	return 0;
}