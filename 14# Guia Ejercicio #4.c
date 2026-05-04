/*Problema 4: Escriba un programa que calcule el valor de ex
Recuerde que dicha constante matemática se calcula de la siguiente forma: 
Y el factorial de todo número se obtiene así:*/

//Titulo:
// --- sacar numero factorial y la serie de taylor e^x ---

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

// ==========================================
// 1. ESCUDO ANTI CTRL+C
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
// 2. FUNCIÓN FACTORIAL
// ==========================================
float factorial (int numero){
    float resultado;
    resultado = numero; 
    for (int i=1 ;i < numero ;i++){
        resultado *= numero - i;
    }
    return(resultado);
}

// ==========================================
// 3. VALIDACIÓN DE PREGUNTA [S/N]
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
// 4. VALIDACIÓN DEL NÚMERO MATEMÁTICO
// ==========================================
float validar_numero (float numero, int validacion){
    char basura;
    int c;
	char reiniciar [10];
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
    else if (numero > 85){ // si el numero es mayor de 85
        printf("\n----- [ERROR] el numero no puede ser mayor a 85. -----\n");
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
//  FUNCIÓN PRINCIPAL
// ==========================================
int main(){
    signal(SIGINT, escudo_ctrl_c);
    
    float numero;
    int i, validacion, c;
    float resultado = 1;
    char pregunta;

    do{
        // Pedimos el valor de x
        do{
            printf("Define el valor de x para sacar e^x: ");
            validacion = scanf("%f", &numero);
            
            // Validamos respuesta
            validacion = validar_numero(numero, validacion);      
        }while(validacion != 1);
        
        // Aplicamos la serie de Taylor
        for(i=1; i < 15; i++){
            resultado += pow(numero, i)/factorial(i);
        }
        
        // Imprimimos resultado
        printf("El resultado de e^x es: %.5f\n", resultado);
        
        
        // Preguntamos si desea repetir
        do{
            printf("\n Deseas sacar otro valor? [S][N]: ");
            scanf("%c", &pregunta); 
            pregunta = desicion(pregunta);                       
        }while(pregunta != 'S' && pregunta !='N');
            
        system("cls");
        resultado = 1; 
    }while (pregunta == 'S');
                    
    return 0;
}