//TRABAJO INFORMATICA 2018-2019
<<<<<<< HEAD
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










=======
>>>>>>> parent of 3472f3d... funcion




//funciones
int buscaautor(){
	int i=0,j=0,k=0,tmp1,tmp2;// para el bucle y para comparar
	int N=devuelveN( );//para saber el numero de peliculas
	char autor[50];
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
    	printf("\nIntroduzca el autor del libro: \n");
		scanf("%[^\n]",autor);
		
		while (feof(pbiblioteca) == 0) //Primero leemos los datos
		{
			fscanf(pbiblioteca, "%[^;]; %[^;]; %[^;]; %i; %d;", lib[i].titulo, lib[i].autor, lib[i].genero, &lib[i].year, &lib[i].estado);
			i++;
		}
		
		printf("\nTitulo\t\t\t\t\tAutor\t\t\tGenero\t\tA%co\t\tEstado\n\n",164);
	
		for(i=0; i<=N-1; i++) //Lo ordenamos
		{
			for(j=i+1; j<=N-1 ; j++) // Comparamos cada elemento con el siguiente
			{
				if (strcmp(lib[i].autor,lib[j].autor)>0)//Si es mayor(alfabeticamente) intercambiamos el contenido de los dos elementos
				{
				aux = lib[i]; 
				lib[i] = lib[j];
				lib[j] = aux;
				}
			}
			
			for(k=0; k<=strlen(lib[i].autor); k++)//bucle para recorrer cada pelicula
			{
				if (autor[0]==lib[i].autor[k])//comprobamos que coincidan el titulo introducido y el titulo de la pelicula registrada
				{
					tmp1=0;
					tmp2=k;
					
					while ((autor[tmp1]==lib[i].autor[tmp2]) && (tmp2<strlen(lib[i].autor)) && (tmp1!=strlen(autor)))
					{
                		tmp1++;
						tmp2++;
						if (tmp1==strlen(autor))
                    	{
						printf("%-40s %-23s %-15s %i\t\t%d\n",lib[i].titulo, lib[i].autor, lib[i].genero, lib[i].year, lib[i].estado);
                  		}
	              	}
    	        } 
        	}
			
		}	
		printf("\n");
	}
	return 0;
}
int buscalibro( )
{
	int i=0,j=0,k=0,tmp1,tmp2;// para el bucle y para comparar
	int N=devuelveN( );//para saber el numero de peliculas
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
    	printf("\nIntroduzca el titulo del libro: \n");
		scanf("%[^\n]",titulo);
		
		while (feof(pbiblioteca) == 0) //Primero leemos los datos
		{
			fscanf(pbiblioteca, "%[^;]; %[^;]; %[^;]; %i; %d;", lib[i].titulo, lib[i].autor, lib[i].genero, &lib[i].year, &lib[i].estado);
			i++;
		}
		
		printf("\nTitulo\t\t\t\t\tAutor\t\t\tGenero\t\tA%co\t\tEstado\n\n",164);
	
		for(i=0; i<=N-1; i++) //Lo ordenamos
		{
			for(j=i+1; j<=N-1 ; j++) // Comparamos cada elemento con el siguiente
			{
				if (strcmp(lib[i].titulo,lib[j].titulo)>0)//Si es mayor(alfabeticamente) intercambiamos el contenido de los dos elementos
				{
				aux = lib[i]; 
				lib[i] = lib[j];
				lib[j] = aux;
				}
			}
			
			for(k=0; k<=strlen(lib[i].titulo); k++)//bucle para recorrer cada libro
			{
				if (titulo[0]==lib[i].titulo[k]){//comprobamos que coincidan el titulo introducido y el titulo del libro registrado
					tmp1=0;
					tmp2=k;
					
					while ((titulo[tmp1]==lib[i].titulo[tmp2]) && (tmp2<strlen(lib[i].titulo)) && (tmp1!=strlen(titulo)))
					{
                		tmp1++;
						tmp2++;
						if (tmp1==strlen(titulo))
                    		printf("%-40s %-23s %-15s %i\t\t%d\n",lib[i].titulo, lib[i].autor, lib[i].genero, lib[i].year, lib[i].estado);
	              	}
    	        }
        	}	
		
		}	
		printf("\n");
	}
	return 0;
}

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
//funcion para buscar por genero
int buscagenero(){
	int i=0,j=0,k=0,tmp1,tmp2;// para el bucle y para comparar
	int N=devuelveN( );//para saber el numero de peliculas
	char genero[50];
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
    	printf("\nIntroduzca el genero del libro: \n");
		scanf("%[^\n]",genero);
		
		while (feof(pbiblioteca) == 0) //Primero leemos los datos
		{
			fscanf(pbiblioteca, "%[^;]; %[^;]; %[^;]; %i; %d;", lib[i].titulo, lib[i].autor, lib[i].genero, &lib[i].year, &lib[i].estado);
			i++;
		}
		
		printf("\nTitulo\t\t\t\t\tAutor\t\t\tGenero\t\tA%co\t\tEstado\n\n",164);
	
		for(i=0; i<=N-1; i++) //Lo ordenamos
		{
			for(j=i+1; j<=N-1 ; j++) // Comparamos cada elemento con el siguiente
			{
				if (strcmp(lib[i].genero,lib[j].genero)>0)//Si es mayor(alfabeticamente) intercambiamos el contenido de los dos elementos
				{
				aux = lib[i]; 
				lib[i] = lib[j];
				lib[j] = aux;
				}
			}
			
			for(k=0; k<=strlen(lib[i].genero); k++)//bucle para recorrer cada pelicula
			{
				if (genero[0]==lib[i].genero[k])//comprobamos que coincidan el titulo introducido y el titulo de la pelicula registrada
				{
					tmp1=0;
					tmp2=k;
					
					while ((genero[tmp1]==lib[i].genero[tmp2]) && (tmp2<strlen(lib[i].genero)) && (tmp1!=strlen(genero)))
					{
                		tmp1++;
						tmp2++;
						if (tmp1==strlen(genero))
                    	{
						printf("%-40s %-23s %-15s %i\t\t%d\n",lib[i].titulo, lib[i].autor, lib[i].genero, lib[i].year, lib[i].estado);
                  		}
	              	}
    	        } 
        	}
			
		}	
		printf("\n");
	}
	return 0;
}
