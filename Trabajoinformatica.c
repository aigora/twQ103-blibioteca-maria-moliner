//TRABAJO INFORMATICA 2018-2019

#include<stdio.h>
#include<string.h>

typedef struct{
	char titulo[50];
	char autor[50];
	char genero[50];
	int year;
	int estado; //1=nuevo, 2=usado, 3=deteriorado
}libro; // estructura de cada libro

//Todas las funciones que vamos a necesitar
int registralibro( );//
int mostrarlibro( );//
int devuelveN( );//Funcion que devuelve un valor N que es el número de libros
int ordenayear( );
int ordenatitulo( );
int ordenagenero();
int ordenaautor();
int buscalibro( );
int buscayear( );
int buscagenero();
int buscaautor();

int main()
{	
	int a,b,c; //para los switch-case
	printf("\n*****BIBLIOTECA MARIA MOLINER*****\n");
	do
	{	
		devuelveN( );//para saber el numero de libros
		printf("\nQue desea hacer: \n1:Registrar \n2:Mostrar libros \n3:Buscar \n4:Ordenar \n5:Salir\n");
		scanf("%i",&a);
		
		switch (a)
		{
			case 1:
				registralibro( );
			break;
				
			case 2:
				mostrarlibro( );
			break;
		
			case 3:// para las funciones de buscar
				do
				{
					printf("\n1:Por fecha \n2:Por titulo \n3:Por genero \n4: Por autor \n5:Volver\n");
					scanf("%i",&b);
					switch(b)
					{
						case 1:
							buscayear( );	
						break;
						
						case 2:
							buscalibro( );
						break;
						
						case 3:
							buscagenero();
						break;
						
						case 4:
							buscaautor();
						break;
						
						case 5:
							printf("\nHas vuelto al inicio.\n");
						break;
					}	
				} while(b!=5);
			break;
			
			case 4:// para las funciones de ordenar
				do
				{
					printf("\n1:Por fecha \n2:Por genero \n3:Por titulo \n4:Por autor \n5:Volver\n");
					scanf("%i",&c);
					switch(c)
					{
						case 1:
							ordenayear( );
						break;
						
						case 2:
							ordenagenero( );
						break;
						
						case 3:
							ordenatitulo( );
						break;
							
						case 4:
							ordenaautor();
						break;
						case 5:
							printf("\nHas vuelto al inicio.\n");
					}	
				} while(c!=5);
			break;
			
			case 5:
				printf("\nHas salido del programa.\n");
			break;		
			
			default:
				printf("\nOpcion no disponible.\n");
			break;
		}
	} while(a!=5);
	return 0;
}



int registralibro( ) 
{
	libro lib;
	FILE *pbiblioteca;
	pbiblioteca=fopen("Biblioteca.txt","a");
	
	if (pbiblioteca == NULL)
	{
		printf("Error al abrir el fichero.\n");
		return -1;
	}
	
	else
	{	
		fflush(stdin);
		
		printf("\nTitulo del libro: \n");
		scanf("%[^\n]", lib.titulo);
		fprintf(pbiblioteca, "\n%s;\t\t\t", lib.titulo);
		
		fflush(stdin);
		
		printf("\nAutor del libro:  \n");
		scanf("%[^\n]", lib.autor);
		fprintf(pbiblioteca, "\n%s;\t\t\t", lib.autor);
		
		fflush(stdin);
		
		printf("\nGenero del libro:  \n");
		scanf("%[^\n]", lib.genero);
		fprintf(pbiblioteca, "\n%s; \t\t\t", lib.genero);
		
		printf("\nA%co del libro:\n", 164);
		scanf("%d",&lib.year);
		if(lib.year<0) //control errores
		{
			printf("\nA%co no valido\n",164);
			return -1;
		}
		else
			fprintf(pbiblioteca, "%d;\t", lib.year);
			
		printf("\nEstado del libro: (n = nuevo, u = usado, d = deteriorado)\n");
		do{
		scanf("%i",&lib.estado);
		fflush(stdin);
			switch (lib.estado){
				case 1:
					printf("\nEl libro es nuevo.\n");
					break;
				
				case 2:
					printf("\nEl libro esta usado.\n");
					break;
				
				case 3:
					printf("\nEl libro esta deteriorado.\n");
					break;
				
				default:
					printf("\nEstado del libro no valido. Vuelva a introducir el valor del estado.\n\n");
					break;	
			}
		}while (lib.estado > 3 || lib.estado <1);
		
		fprintf(pbiblioteca, "%d;\t", lib.estado);

			
		printf("\nLibro registrado correctamente.\n");
	}
	fclose(pbiblioteca);
	return 0;
}



int mostrarlibro( )
{
	FILE *pbiblioteca;
	libro lib;
	pbiblioteca=fopen("biblioteca.txt", "r");
	
	if (pbiblioteca == NULL)
	{
		printf("Error al abrir el fichero.\n");
		return -1;
	}
	else
	{
		printf("\nTitulo\t\t\t\t\tAutor\t\t\t\tGenero\t\tA%co\t\tEstado\n\n",164);
		while (feof(pbiblioteca) == 0) // Leemos el fichero y mostramos los libros
		{  
			fscanf(pbiblioteca, "%[^;]; %[^;]; %[^;]; %i; %d; ", lib.titulo, lib.autor, lib.genero, &lib.year, &lib.estado);
			printf("%-40s %-30s %-15s %i\t\t%d\n",lib.titulo, lib.autor, lib.genero, lib.year, lib.estado);
		}
	}
	fclose(pbiblioteca); 
	return 0;
}


//funciones
int buscaautor(){
	int i=0,j=0,k=0,tmp1,tmp2;// para el bucle y para comparar
	int N=devuelveN( );// numero de libros en total
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
			
			for(k=0; k<=strlen(lib[i].autor); k++)//bucle para leer cada libro
			{
				if (autor[0]==lib[i].autor[k])//comprobamos que coincidan el titulo introducido y el titulo de los libros 
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
//funcion para buscar libros
int buscalibro( )
{
	int i=0,j=0,k=0,tmp1,tmp2;// para el bucle y para comparar
	int N=devuelveN( );//para saber el numero de libros
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
// funcion para buscar por año
int buscaryear()
{
	int i=0,existe=0;// para el bucle y para usar en el if y saber si hay pelis con el año dado
	int N=devuelveN( );//para saber el numero de libros
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
		for(i=0;i<N;i++)//Recorremos el vector de las libros 
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
	int N=devuelveN( );//para saber el numero de libros
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
			
			for(k=0; k<=strlen(lib[i].genero); k++)//bucle para recorrer cada libro
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
