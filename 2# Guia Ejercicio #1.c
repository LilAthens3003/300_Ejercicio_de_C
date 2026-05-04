/* diseña un programa en c que, dado un numero real que entra como dato, nos indique si esta contenido dentro de
 los limites predeterminados, el limite inferior y el superior 200 */
/* Diseñe un programa en C que, dado un numero real que entra como dato, nos indique si esta contenido dentro de los limites predeterminados, el limite inferior 100 y el superior 200 */

#include<stdio.h>

// --- funciones --- 

int evaluar_limites(float numero_a_evaluar) {
    
   
    if (numero_a_evaluar >= 100 && numero_a_evaluar <= 200) {
        return 1; 
    } else {
        return 2; 
    }
}

int main(){
    float num;
    int op, vali;

    // --- Zona de Validación  ---
    do {
        printf("Por favor introduzca un numero: ");
        vali = scanf("%f", &num);
          
        if (vali != 1) {
            printf("[ERROR] Caracteres no permitidos. Solo se aceptan numeros.\n");
            while(getchar() != '\n'); 
        } 
           
    } while (vali != 1); 
    
    
    // --- LA FUNCIÓN ---

    op = evaluar_limites(num);


    // --- Zona de Resultados ---
   
    switch (op) {
        case 1:
            printf("\nEl valor %.2f se comprende en el limite entre 100 y 200\n", num);
            break;
        case 2:
            printf("\nEl valor %.2f no se comprende entre los limites 100 y 200\n", num);
            break;
        default: 
            break;

            //TEXTO DE EJEMPLO
    }
    
    return 0;
} 