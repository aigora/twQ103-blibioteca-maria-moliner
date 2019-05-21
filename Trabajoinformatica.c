//TRABAJO INFORMATICA 2018-2019
#include<stdio.h>
#include<string.h>

<<<<<<< HEAD

=======
typedef struct{
	char titulo[50];
	char autor[50];
	char genero[50];
	int year;
	int estado; //1=nuevo, 2=usado, 3=deteriorado
}libro; // estructura de cada libro
>>>>>>> 8ffa83f67c2a21722accb5e894e8646d2c864b55


















//funciones
int buscaryear()
{
	int i=0,existe=0;// para el bucle y para usar en el if y saber si hay pelis con el año dado
	int N=devuelveN( );//para saber el numero de peliculas
	int yeardado;
	char titulo[50];
	libro lib[N];
	libro aux;
	FILE *pbiblioteca;
	 pbiblioteca=fopen("Biblioteca.txt","r");	
	if (pbiblioteca == NULL)
	{
	printf("Error al abrir el fichero.\n");
		return -1;
	}
	else
	{
		fflush(stdin); 	
    	printf("\nIntroduzca el a%co del que quiere mostrar libros: \n",164);
		scanf("%d",&yeardado);
		printf("\nTitulo\t\t\t\t\tAutor\t\t\tGenero\t\tA%co\t\tEstado\n\n",164);
		while (feof(pbiblioteca) == 0) //Primero leemos los datos
		{
			fscanf(pbiblioteca, "%[^;]; %[^;]; %[^;]; %i; %d;", lib[i].titulo, lib[i].autor, lib[i].genero, &lib[i].year, &lib[i].estado);
			i++;
		}
		for(i=0;i<N;i++)//Recorremos el vector de las peliculas 
		{
			
			if (yeardado==lib[i].year)
			{
				printf("%-40s %-23s %-15s %i\t\t%d\n",lib[i].titulo, lib[i].autor, lib[i].genero, lib[i].year, lib[i].estado);
				existe=1;     	
		    }
		}
		if(existe<1)
		    	printf("\nNo hay libros registrados en ese a%co\n",164);
		printf("\n");
	}
	return 0;
}			
    }   
    
