/* 2. Que lea 5 números por teclado, los copie a otro array multiplicados por 2 y los muestre todos ordenados 
usando un tercer array.*/

int main(){
	float vector [5], vectormul [5],vector_ordenado[10], temporal;
	int i,j,vali;
	char basura;
	
	
	printf ("--- Arrays multiplicados por 2 ---\n");
	for (i=0 ; i < 5 ; i++){
		do{
			printf ("introduce el numero %d de 5 numeros: ",i + 1);
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
				else if (vector[i] == 0){
					printf("[ERROR] el numero no puede ser 0  \n\n");
					vali = 0;
				}
			}
		}while(vali != 1);
		vectormul [i]= vector [i] * 2;
	}
	// --- 2. FUSIÓN EN EL TERCER ARRAY ---
    for (i = 0 ; i < 5 ; i++){
        vector_ordenado[i] = vector[i];       // Metemos los 5 originales en los primeros puestos (0 al 4)
        vector_ordenado[i + 5] = vectormul[i]; // Metemos los 5 multiplicados en los siguientes puestos (5 al 9)
    }
    
	printf ("\n --- resultados de Arrays --- ");
	for (i=0 ; i < 10 ; i++){	
		printf ("\npuesto %d del Array: %.2f",i + 1, vector_ordenado[i]);
	}
	return 0;
}