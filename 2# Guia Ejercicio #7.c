/*Tenemos guardada en una matriz los alumnos de una escuela. Sabiendo que hay 3 cursos distintos, 5 
alumnos por curso y que cada alumno tiene 2 asignaturas, se pide:
1. Pedir por teclado las notas que ha sacado cada alumno en cada asignatura y de cada curso.
2. Decir cual es la nota media de un determinado curso.
3. Decir cuántos aprobados y suspensos hay en una determinada asignatura en un determinado curso.*/

//titulo:
//conocer el promedio de 15 alumnos en 3 cursos distintos en dos asignaturas

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

// ==========================================
//  ESCUDO ANTI CTRL+C
// ==========================================
void escudo_ctrl_c(int sig) {
	
    printf("\n----- [SISTEMA] Por favor, usa la opcion 'N' al final del programa, si deseas salir correctamente. -----");
    printf("\nPorfavor escribir 'x': ");
    // Re-armamos el escudo para el siguiente impacto
    signal(SIGINT, escudo_ctrl_c);
    // Despertamos a la consola para que no se buguee
    clearerr(stdin);
    freopen("CON", "r", stdin); 
    
}

// ==========================================
//  VALIDACIÓN DE PREGUNTA [S/N]
// ==========================================
char desicion (char palabra){
    int c;
    
    // PRIMERO: El Escudo Anti EOF 
    if (palabra == 26 || feof(stdin)) {
        printf("\n----- [ALERTA] Intento de cierre por EOF bloqueado. Reiniciando... -----\n");
        clearerr(stdin); 
        freopen("CON", "r", stdin); 
        return 'X'; // Retorna un valor inválido para que repita el bucle
    }
    
    while ((c = getchar()) != '\n' && c != EOF);
    palabra = toupper(palabra);                 
    if (palabra != 'S' && palabra !='N'){
        printf("\n----- [ERROR] La respuesta debe ser 'S' o 'N', ya sea en mayuscula o minuscula -----\n\n");
    }
    return palabra;
}

// ==========================================
//  VALIDACIÓN DE LAS NOTAS
// ==========================================
float validar_numero (int validacion, float numero){
    char basura;
    int c;
	validacion = 1;
    //PRIMERO: El Escudo Anti EOF
    if (validacion == EOF || feof(stdin)) {
        printf("\n----- [ALERTA] Intento de cierre por EOF bloqueado. Reiniciando... -----\n");
        clearerr(stdin); 
        freopen("CON", "r", stdin); 
        return 0; 
    }
    
    // SEGUNDO: Validaciones matemáticas y limpieza de buffer
    if (validacion != 1){ //si el numero es diferente a un numero
        printf("\n----- [ERROR] Caracteres no permitidos, solo se aceptan numeros. -----\n");
        while((c = getchar()) != '\n' && c != EOF); // Aspiradora
        return 0;
    }
    else if (numero < -1){ // si numero es menor o igual a 0
        printf("\n----- [ERROR] el numero no puede ser menor que 0 o igual a 0. -----\n");
        while((c = getchar()) != '\n' && c != EOF);
        return 0;
    }
    else if (numero < 0 || numero >20){ // si el numero es mayor de 85
        printf("\n----- [ERROR] La nota se comprende entre los limites de 00 hasta 20 siendo la mejor nota. -----\n");
        while((c = getchar()) != '\n' && c != EOF); 
        return 0;
    }
    else { //si el numero tiene alguna letra 
        basura = getchar();
        if (basura != '\n'){
            while((c = getchar()) != '\n' && c != EOF); 
            printf("\n----- [ERROR] detectado basura. solo se aceptan numeros -----\n");
            return 0;
        }
    }
    return 1; // Retorna 1 (verdadero) si todo está perfecto
}

// ==========================================
//  VALIDACIÓN DE QUE SEA DE 1 A 3 EL NUMERO
// ==========================================
float validar_curso (int validacion,int numero){
    char basura;
    int c;
	validacion = 1;
    //PRIMERO: El Escudo Anti EOF
    if (validacion == EOF || feof(stdin)) {
        printf("\n----- [ALERTA] Intento de cierre por EOF bloqueado. Reiniciando... -----\n");
        clearerr(stdin); 
        freopen("CON", "r", stdin); 
        return 0; 
    }
    
    // SEGUNDO: Validaciones matemáticas y limpieza de buffer
    if (validacion != 1){ //si el numero es diferente a un numero
        printf("\n----- [ERROR] Caracteres no permitidos, solo se aceptan numeros. -----\n");
        while((c = getchar()) != '\n' && c != EOF); // Aspiradora
        return 0;
    }
    else if (numero <= 0){ // si numero es menor o igual a 0
        printf("\n----- [ERROR] el numero no puede ser menor que 0 o igual a 0. -----\n");
        while((c = getchar()) != '\n' && c != EOF);
        return 0;
    }
    else if (numero < 1 || numero > 3){ // si el numero es mayor de 85
        printf("\n----- [ERROR] el numero no puede ser mayor a 3 ni menor a 1. -----\n");
        while((c = getchar()) != '\n' && c != EOF); 
        return 0;
    }
    else { //si el numero tiene alguna letra 
        basura = getchar();
        if (basura != '\n'){
            while((c = getchar()) != '\n' && c != EOF); 
            printf("\n----- [ERROR] detectado basura. solo se aceptan numeros -----\n");
            return 0;
        }
    }
    return 1; // Retorna 1 (verdadero) si todo está perfecto
}

// ==========================================
//  VALIDACIÓN DE NOMBRE, QUE NO CONTENGA NUMEROS
// ==========================================
int validar_nombre (int validacion, char nombre[]){
	int c, k=0;
	
	validacion = 1;
	while((c = getchar()) != '\n' && c != EOF);
	for(k = 0; nombre[k] != '\0'; k++){
        if(!isalpha(nombre[k]) && nombre[k] != ' '){
            printf("[ERROR] El nombre solo puede contener letras y espacios.\n\n");
         	return 0;
    	}
    }
    return 1;
}

// ==========================================
//  VALIDACIÓN DE OPCION NO SEA MAYOR DE 3 O MENOR DE 1
// ==========================================
float validar_opcion_three (int validacion,int numero){
    validacion = 1;
	char basura;
    int c;
    //PRIMERO: El Escudo Anti EOF
    if (validacion == EOF || feof(stdin)) {
        printf("\n----- [ALERTA] Intento de cierre por EOF bloqueado. Reiniciando... -----\n");
        clearerr(stdin); 
        freopen("CON", "r", stdin); 
        return 0; 
    }
    
    // SEGUNDO: Validaciones matemáticas y limpieza de buffer
    if (validacion != 1){ //si el numero es diferente a un numero
        printf("\n----- [ERROR] Caracteres no permitidos, solo se aceptan numeros. -----\n");
        while((c = getchar()) != '\n' && c != EOF); // Aspiradora
        return 0;
    }
    else if (numero <= 0){ // si numero es menor o igual a 0
        printf("\n----- [ERROR] el numero no puede ser menor que 0 o igual a 0. -----\n");
        while((c = getchar()) != '\n' && c != EOF);
        return 0;
    }
    else if (numero < 1 ||numero > 3){ 
        printf("\n----- [ERROR] el numero no puede ser mayor a 3 ni menor a 1. -----\n");
        while((c = getchar()) != '\n' && c != EOF); 
        return 0;
    }
    else { //si el numero tiene alguna letra 
        basura = getchar();
        if (basura != '\n'){
            while((c = getchar()) != '\n' && c != EOF); 
            printf("\n----- [ERROR] detectado basura. solo se aceptan numeros -----\n");
            return 0;
        }
    }
    return 1; // Retorna 1 (verdadero) si todo está perfecto
}

// ==========================================
//  VALIDACIÓN DE OPCION NO SEA MAYOR DE 4 O MENOR A 1
// ==========================================
float validar_opcion_four (int validacion,int numero){
    validacion = 1;
	char basura;
    int c;
    //PRIMERO: El Escudo Anti EOF
    if (validacion == EOF || feof(stdin)) {
        printf("\n----- [ALERTA] Intento de cierre por EOF bloqueado. Reiniciando... -----\n");
        clearerr(stdin); 
        freopen("CON", "r", stdin); 
        return 0; 
    }
    
    // SEGUNDO: Validaciones matemáticas y limpieza de buffer
    if (validacion != 1){ //si el numero es diferente a un numero
        printf("\n----- [ERROR] Caracteres no permitidos, solo se aceptan numeros. -----\n");
        while((c = getchar()) != '\n' && c != EOF); // Aspiradora
        return 0;
    }
    else if (numero <= 0){ // si numero es menor o igual a 0
        printf("\n----- [ERROR] el numero no puede ser menor que 0 o igual a 0. -----\n");
        while((c = getchar()) != '\n' && c != EOF);
        return 0;
    }
    else if (numero < 1 ||numero > 4){ 
        printf("\n----- [ERROR] el numero no puede ser mayor a 4 ni menor a 1. -----\n");
        while((c = getchar()) != '\n' && c != EOF); 
        return 0;
    }
    else { //si el numero tiene alguna letra 
        basura = getchar();
        if (basura != '\n'){
            while((c = getchar()) != '\n' && c != EOF); 
            printf("\n----- [ERROR] detectado basura. solo se aceptan numeros -----\n");
            return 0;
        }
    }
    return 1; // Retorna 1 (verdadero) si todo está perfecto
}

// ==========================================
//  MENU #1
// ==========================================
void menu(){
	printf("---     MENU     ---\n");
	printf("\nSeleccione con el numero la opcion que quiere elegir: ");
	printf("\n1. nota media de todos los estudiantes de un curso.");
	printf("\n2. Determinar cuantos aprobados y suspensos hay en una asignatura en un curso.");
	printf("\n3. Salir del menu.\n");
}

// ==========================================
//  MENU #2
// ==========================================
void menutwo(){
	system("cls");
	printf("---     MENU     ---\n");
	printf("\nNota media de todos los estudiantes de un curso.");
	printf("\n1. La Nota media del curso uno.");
	printf("\n2. La Nota media del curso dos.");
	printf("\n3. La Nota media del curso tres.");
	printf("\n4. Regresar en el menu.\n");
}

// ==========================================
//  MENU #3
// ==========================================
void menuthree(){
	system("cls");
	printf("---     MENU     ---\n");
	printf("\nDeterminar cuántos aprobados y suspensos hay en una asignatura en un curso.");
	printf("\n1. Determinar las Notas de la asignatura uno.");
	printf("\n2. Determinar las Notas de la asignatura dos.");
	printf("\n3. Regresar en el menu.\n");
}

// ==========================================
//  MENU #4
// ==========================================
void menufour(){
	system("cls");
	printf("---     MENU     ---\n");
	printf("\nDeterminar cuántos aprobados y suspensos hay en La asignatura uno");
	printf("\n1. Aprobados y suspendidos del curso uno.");
	printf("\n2. Aprobados y suspendidos del curso dos.");
	printf("\n3. Aprobados y suspendidos del curso tres.");
	printf("\n4. Regresar en el menu.\n");
}
// ==========================================
//  MENU #5
// ==========================================
void menufive(){
	system("cls");
	printf("---     MENU     ---\n");
	printf("\nDeterminar cuántos aprobados y suspensos hay en La asignatura dos");
	printf("\n1. Aprobados y suspendidos del curso uno.");
	printf("\n2. Aprobados y suspendidos del curso dos.");
	printf("\n3. Aprobados y suspendidos del curso tres.");
	printf("\n4. Regresar en el menu.\n");
}

// ==========================================
//  PROGRAMA PRINCIPAL
// ==========================================
int main(){
	signal(SIGINT, escudo_ctrl_c); // protegemos el sistema de un crontrol + C (asegun)
	
	//declaracion de variables
	char nombre[14][50], pregunta;
	float asignatura_uno[14], asignatura_dos[14], suma;
	int validacion = 1, curso[14], cantidad = 0, opcion, opciontwo, opcionthree, opcionfour, opcionfive;
	int reprobados = 0, aprobados = 0;
	
	printf("\n--- Bienvenid@ al programa ---");
	for (int i=0;i<14;i++){  // Un ciclo que registre a los 15 estudiantes
		printf("\n---      Alumno %d#      ---",i+1);
		do{
			printf("\n A- Porfavor ingrese su nombre: "); //Pedimos nombre 
			validacion = scanf(" %40[^\n]", &nombre[i]);
			validacion = validar_nombre (validacion, nombre[i]);
		}while(validacion != 1);
		do{
			printf("\n B- Porfavor ingrese de la opcion del curso que pertenece %s: ",nombre[i]); //pedimos su curso
			printf ("\n1- Pertenesco al curso uno.");
			printf ("\n2- Pertenesco al curso dos.");
			printf ("\n3- Pertenesco al curso tres.\n");
			validacion = scanf("%d", &curso[i]);
			validacion = validar_curso (validacion, curso[i]);
		}while(validacion != 1);
		do{
			printf("\n C- Cual fue la nota de %s en su primera asignatura: ",nombre[i]); //Pedimos su nota en la primera asignatura 
			validacion = scanf("%f", &asignatura_uno[i]);
			validacion = validar_numero (validacion, asignatura_uno[i]);
		}while(validacion != 1);
		do{
			printf("\n C- Cual fue la nota de %s en su segunda asignatura: ",nombre[i]); //Pedimos su nota en la segunda asignatura
			validacion = scanf("%f", &asignatura_dos[i]);
			validacion = validar_numero (validacion, asignatura_dos[i]);
		}while(validacion != 1);
		system("cls");
	}
	
	
	
	do{
		do{
			menu();  // menu #1 de opciones
			validacion = scanf("%d", &opcion);
			validacion = validar_opcion_three(validacion, opcion); //validamos si la opcion es 1, 2 o 3
		}while(validacion != 1);
		switch(opcion){ //segun la opcion se muestra en pantalla el menu #2 o #3, o salir del programa
			case 1:
				do{
					menutwo(); // menu #2
					validacion = scanf("%d", &opciontwo);
					validacion = validar_opcion_four(validacion, opciontwo); //validadmos si la opcion es 1, 2, 3 o 4
				}while(validacion != 1);
				switch(opciontwo){ //switch anidado
					case 1:
						cantidad = 0;
						suma = 0;
						for(int i=0; i<14; i++){
							if(curso[i] == 1){ //pasamos por los 15 estudiantes y validamos cuales pertenescan al curso 1
								suma += asignatura_uno[i] + asignatura_dos[i];  // sumamos sus notas ya que es un promedio general
								cantidad ++;
							}
						}
						if (cantidad == 0){
							printf ("\nPor alguna razon no hay estudiantes en este curso."); //por si el usuario no coloco alumnos en un curso
							break;
						}
						suma /= cantidad * 2; // dividimos la suma total entre la cantidad de alumnos por dos, por ser dos materias
						printf("\nLa media del curso uno es: %.2f \n",suma); 
						break;
					case 2:
						cantidad = 0;
						suma = 0;
						for(int i=0; i<14; i++){
							if(curso[i] == 2){
								suma += asignatura_uno[i] + asignatura_dos[i];
								cantidad ++;
							}
						}
						if (cantidad == 0){
							printf ("\nPor alguna razon no hay estudiantes en este curso.");
							break;
						}
						suma /= cantidad * 2;
						printf("la media del curso dos es: %.2f \n",suma);
						break;
					case 3:
						cantidad = 0;
						suma = 0;
						for(int i=0; i<14; i++){
							if(curso[i] == 3){
								suma += asignatura_uno[i] + asignatura_dos[i];
								cantidad ++;
							}
						}
						if (cantidad == 0){
							printf ("\nPor alguna razon no hay estudiantes en este curso.");
							break;
						}
						suma /= cantidad * 2;
						printf("la media del curso tres es: %.2f \n",suma);
						break;
					case 4:
					break;
				}	
				break;
			case 2:
				do{
					menuthree(); // menu #3 que da al menu #4 o al #5
					validacion = scanf("%d", &opcionthree);
					validacion = validar_opcion_three(validacion, opcionthree);
				}while(validacion != 1);
				switch(opcionthree){
					case 1:
						do{
							menufour();  //menu #4
							validacion = scanf("%d", &opcionfour);
							validacion = validar_opcion_three(validacion, opcionfour);
						}while(validacion != 1);
						switch(opcionfour){
							case 1:
								cantidad = 0;
								aprobados = 0;
								reprobados = 0;
								for(int i=0;i<14;i++){
									if (curso[i] == 1){ //buscamos quienes son del curso 1
										cantidad++;
										if(asignatura_uno[i] > 10){ // comprobamos si paso en la asignatura 1 
											printf("%d. El alumno %s esta aprovado en la asignatura uno con la nota: %.2f \n",cantidad, nombre[i],asignatura_uno[i]); // lo mostramos en pantalla
											aprobados++; // aumentamos un contados para decir el total 
										}
										else{ // si no los reprovados
											printf("%d. El alumno %s esta reprovado en la asignatura uno con la nota: %.2f \n",cantidad, nombre[i],asignatura_uno[i]); 
											reprobados++;
										}
									}
								}
								printf ("\nLos alumnos aprobados fueron: %d \n Los alumnos reprobados fueron: %d",aprobados,reprobados); // mostramos el total de los dos resultados
								break;
							case 2:
								cantidad = 0;
								aprobados = 0;
								reprobados = 0;
								for(int i=0;i<14;i++){
									if (curso[i] == 2){
										cantidad++;
										if(asignatura_uno[i] > 10){
											printf("%d. El alumno %s esta aprovado en la asignatura uno con la nota: %.2f \n",cantidad, nombre[i],asignatura_uno[i]);
											aprobados++;
										}
										else{
											printf("%d. El alumno %s esta reprovado en la asignatura uno con la nota: %.2f \n",cantidad, nombre[i],asignatura_uno[i]);
											reprobados++;
										}
									}
								}
								printf ("\nLos alumnos aprobados fueron: %d \n Los alumnos reprobados fueron: %d",aprobados,reprobados);
								break;
							case 3:
								cantidad = 0;
								aprobados = 0;
								reprobados = 0;
								for(int i=0;i<14;i++){
									if (curso[i] == 3){
										cantidad++;
										if(asignatura_uno[i] > 10){
											printf("%d. El alumno %s esta aprovado en la asignatura uno con la nota: %.2f \n",cantidad, nombre[i],asignatura_uno[i]);
											aprobados++;
										}
										else{
											printf("%d. El alumno %s esta reprovado en la asignatura uno con la nota: %.2f \n",cantidad, nombre[i],asignatura_uno[i]);
											reprobados++;
										}
									}
								}
								printf ("\nLos alumnos aprobados fueron: %d \n Los alumnos reprobados fueron: %d",aprobados,reprobados);
								break;
							case 4:
								break;
						}
						break;
					case 2:
						do{
							menufive(); //menu #5
							validacion = scanf("%d", &opcionfive);
							validacion = validar_opcion_three(validacion, opcionfive);
						}while(validacion != 1);
						switch (opcionfive){
							case 1:  
								cantidad = 0;
								aprobados = 0;
								reprobados = 0;
								for(int i=0;i<14;i++){
									if (curso[i] == 1){
										cantidad++;
										if(asignatura_dos[i] > 10){ // en este caso es lo mismo pero con la asignatura 2
											printf("%d. El alumno %s esta aprovado en la asignatura uno con la nota: %.2f \n",cantidad, nombre[i],asignatura_dos[i]);
											aprobados++;
										}
										else{
											printf("%d. El alumno %s esta reprovado en la asignatura uno con la nota: %.2f \n",cantidad, nombre[i],asignatura_dos[i]);
											reprobados++;
										}
									}
								}
								printf ("\nLos alumnos aprobados fueron: %d \n Los alumnos reprobados fueron: %d",aprobados,reprobados);
								break;
							case 2:
								cantidad = 0;
								aprobados = 0;
								reprobados = 0;
								for(int i=0;i<14;i++){
									if (curso[i] == 2){
										cantidad++;
										if(asignatura_dos[i] > 10){
											printf("%d. El alumno %s esta aprovado en la asignatura uno con la nota: %.2f \n",cantidad, nombre[i],asignatura_dos[i]);
											aprobados++;
										}
										else{
											printf("%d. El alumno %s esta reprovado en la asignatura uno con la nota: %.2f \n",cantidad, nombre[i],asignatura_dos[i]);
											reprobados++;
										}
									}
								}
								printf ("\nLos alumnos aprobados fueron: %d \n Los alumnos reprobados fueron: %d",aprobados,reprobados);
								break;
							case 3:
								cantidad = 0;
								aprobados = 0;
								reprobados = 0;
								for(int i=0;i<14;i++){
									if (curso[i] == 3){
										cantidad++;
										if(asignatura_dos[i] > 10){
											printf("%d. El alumno %s esta aprovado en la asignatura uno con la nota: %.2f \n",cantidad, nombre[i],asignatura_dos[i]);
											aprobados++;
										}
										else{
											printf("%d. El alumno %s esta reprovado en la asignatura uno con la nota: %.2f \n",cantidad, nombre[i],asignatura_dos[i]);
											reprobados++;
										}
									}
								}
								printf ("\nLos alumnos aprobados fueron: %d \n Los alumnos reprobados fueron: %d",aprobados,reprobados);
								break;
							case 4:
								break;
						}
						break;
					case 3:
						break;
				}
				break;
				
			case 3:
				do{
        			printf("\n Seguro que desea salir del menu ? [S] [N] \n"); //pregunramos al usuario si quiere salir
            		scanf("%c", &pregunta); 
            		validacion = desicion(pregunta);                       
        		}while(pregunta != 'S' && pregunta !='N');
				break;	
		}	
	}while(pregunta != 'S');
	
	return 0;
}