#include "vigenere.c"

int main( int argc, char *argv[] )
{

	system("clear");

	char * mensaje = (char *) malloc(sizeof(char*)*100);
	char * senha = (char *) malloc(sizeof(char*)*100);

	int opc = 0;

	printf("Enter para iniciar!");

	while (opc != 3) {
		
		clean_stdin();
		printf("\nSelecciona la operación a realizar: ");
		printf("\n(1) Cifrar mensaje");
		printf("\n(2) Descifrar mensaje");
		printf("\n(3) Salir\n");

		scanf("%d", &opc);

		switch(opc) {
			case 1:
				clean_stdin();

				printf("Introduce el mensaje (máximo 100 caracteres)\n");
				fgets(mensaje, 100, stdin);

				printf("\nIntroduce la contraseña (menor que el mensaje)\n");
				fgets(senha, 100, stdin);

				if ((strlen(mensaje)>0) && (mensaje[strlen (mensaje) - 1] == '\n'))
			        mensaje[strlen (mensaje) - 1] = '\0';
			    if ((strlen(senha)>0) && (senha[strlen (senha) - 1] == '\n'))
			        senha[strlen (senha) - 1] = '\0';

				senha = validarSenha(senha, mensaje);
				if(senha == NULL)
					printf("ERROR: Tu contraseña es más grande que el texto\n");

				char * cifrado = (char *) malloc(sizeof(char*)*strlen(mensaje));

				printf("\n\n******************Cifrando*******************\n\n");

				strcpy(cifrado, cifrar(senha, mensaje));
				printf("Tu mensaje cifrado es:\n%s\n\nPresiona cualquier tecla para continuar", cifrado);
				clean_stdin();
			break;

			case 2:
				clean_stdin();

				printf("Introduce el mensaje (máximo 100 caracteres)\n");
				fgets(mensaje, 100, stdin);

				printf("\nIntroduce la contraseña (menor que el mensaje)\n");
				fgets(senha, 100, stdin);

				if ((strlen(mensaje)>0) && (mensaje[strlen (mensaje) - 1] == '\n'))
			        mensaje[strlen (mensaje) - 1] = '\0';
			    if ((strlen(senha)>0) && (senha[strlen (senha) - 1] == '\n'))
			        senha[strlen (senha) - 1] = '\0';

				senha = validarSenha(senha, mensaje);
				if(senha == NULL)
					printf("ERROR: Tu contraseña es más grande que el texto\n");

				char * descifrado = (char *) malloc(sizeof(char*)*strlen(mensaje));

				printf("\n\n******************Descifrando*******************\n\n");

				strcpy(descifrado, descifrar(senha, cifrado));

				printf("Tu mensaje descifrado es:\n%s\n\nPresiona cualquier tecla para continuar", descifrado);
				clean_stdin();
			break;

			case 3:
			break;

			default:
				printf("\nOpción incorrecta\n");
				pause();
			break;
		}
	}
	
	
	

return 0;
}