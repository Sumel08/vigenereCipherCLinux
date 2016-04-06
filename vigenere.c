#include "vigenere.h"

char *validarSenha(char* sen, char* men){
	char *senha=malloc(sizeof(strlen(sen)));
	char *mensaje=malloc(sizeof(strlen(men)));
	int i;
	strcpy(senha,sen);	
	strcpy(mensaje,men);	

	//Completamos la senha a el tamaño del mensaje si es necesario
	if( strlen( senha ) < strlen( mensaje ) ){
		i= strlen( mensaje )/strlen( senha );
		char *aux = malloc(sizeof(strlen(senha)));
		strcpy( aux,senha );
		for (i; i>1; i--){
			strcat( aux,senha );
		} 
		i = strlen( mensaje )%strlen( aux );
		strcpy( &senha[i],"\0");
		strcat( aux,senha );
		strcpy( senha,aux );
	}
	else
		return NULL;

return senha;
}

char *cifrar(char* sen, char* men){
	char *senha=malloc(sizeof(strlen(sen)));
	char *mensaje=malloc(sizeof(strlen(men)));
	char *cifrado=malloc(sizeof(strlen(men)));
	int i, L = 95, aux;
	strcpy(senha,sen);	
	strcpy(mensaje,men);
	for (i = 0; i < strlen(mensaje); ++i)
	{
		//aux = ( (((int) mensaje[i] - '0')+48) + (((int) senha[i] - '0')+48) ) % L;
		aux = ((( (((int) mensaje[i] - 32)) + (((int) senha[i] - 32)) )) % L) +32;
		//printf("\nMENSAJE %d : %c\n", (int) mensaje[i], mensaje[i]);
		//printf("\nKEY %d : %c\n", (int) senha[i], senha[i]);
		cifrado[i] = aux;
	}

	return cifrado;
}

char *descifrar(char* sen, char* men){
	char *senha=malloc(sizeof(strlen(sen)));
	char *mensaje=malloc(sizeof(strlen(men)));
	char *descifrado=malloc(sizeof(strlen(men)));
	int i, L = 95, aux;
	strcpy(senha,sen);	
	strcpy(mensaje,men);
	for (i = 0; i < strlen(mensaje); ++i)
	{
		//aux = ( (((int) mensaje[i] - '0')+48) - (((int) senha[i] - '0')+48) ) % L;
		//aux = ((( (((int) mensaje[i] - 32)) - (((int) senha[i] - 32)) )) % L) +32;
		aux = (( (((int) mensaje[i] - 32)) - (((int) senha[i] - 32)) ));
		if(aux<0)
			aux = L + aux + 32;
		else
			aux = (aux%L) + 32;
		descifrado[i] = aux;
		
	}
	return descifrado;
}

void pause(){
	printf("Presione ENTER para continuar.");
	while(getchar() != '\n');
}

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}