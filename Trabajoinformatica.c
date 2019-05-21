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
