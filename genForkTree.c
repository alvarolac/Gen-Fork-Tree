#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int analizarCodigo(char *);

void * manejador_hilo() 
{
	while(1)
	{
		printf(".");
  		fflush(stdout);
  		sleep(1);
	}
}

int main(int argc, char const *argv[])
{
	if(argc != 2)
	{
		printf(" Debe especificar la ruta del archivo fuente a analizar \n");
		return -1;
	}
	
	system("touch .graph.dot");
	system("rm .graph.dot");
	system("touch .graph.dot");

	system("touch .out.c");
	system("rm .out.c");
	system("touch .out.c");

	pthread_t info_hilos;

	pthread_create(&info_hilos,NULL,(void *)&manejador_hilo, NULL);


  	pid_t pid;
 	int estado;
  	pid = fork();

  	char nombre_archivo[200];
 
  	strcpy(nombre_archivo, argv[1]);

	if(pid == -1)
	{
		perror("Error en la ejecucion del fork");
	    return 0;  
	}
	  
	switch(pid)
	{
		case 0:
	        analizarCodigo(nombre_archivo);
	        break;

	    default:
	        wait(&estado);
	        if(!estado){
	          	printf("..... Analisis Completo ... Falta poco .....");
				FILE *___fp___; 
				___fp___ = fopen(".graph.dot", "a");
			  	fprintf(___fp___," graph hola { \n"); 
				fclose (___fp___);
				sleep(2);
			  	system("gcc .out.c -o .codigo_analizado.out");
			  	system("./.codigo_analizado.out");
				sleep(2);
				___fp___ = fopen(".graph.dot", "a");
				fprintf(___fp___,"\n }");
				fclose (___fp___);

				system("dot -Tpng .graph.dot -o graph.png");
	          	printf("\n\n\tgraph.png creado de manera correcta!\n\n");
	      
	        }
	        else
	          	printf("\n\tOcurrio un error durante el analisis del Codigo proporcionado. \n");  
	        
	        break;
	} 
	
	return 0;
}



int analizarCodigo(char rutaArchivo[])
{
	char * argumentos[] = {"./analizador.out", rutaArchivo, NULL};
	execvp(argumentos[0], argumentos);

	/* Codigo no alcanzable en correcta ejecucion */	
	perror("Error: Execvp");
	return -1;
}