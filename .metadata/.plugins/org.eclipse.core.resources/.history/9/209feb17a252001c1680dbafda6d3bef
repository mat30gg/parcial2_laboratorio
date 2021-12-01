/*
 * libro.c
 *
 *  Created on: 30 nov. 2021
 *      Author: mateo
 */

#include "libro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


eLibro* NuevoLibro()
{
	eLibro* plibro;
	plibro = (eLibro*) malloc(sizeof(eLibro));
	setId(plibro, 0);
	setTitulo(plibro, "");
	setAutor(plibro, "");
	setPrecio(plibro, 0);
	setEditorial(plibro, 0);

	return plibro;
}

int setId(eLibro* plibro, int id)
{
	int raux = 0;
	if(plibro != NULL)
	{
		raux = 1;
		plibro->idLibro = id;
	}
	return raux;
}
int getId(eLibro* plibro, int* id)
{
	int raux = 0;
	if(plibro != NULL)
	{
		raux = 1;
		*id = plibro->idLibro;
	}
	return raux;
}
int setTitulo(eLibro* plibro, char* titulo)
{
	int raux = 0;
	if(plibro != NULL)
	{
		raux = 1;
		strcpy(plibro->titulo, titulo);
	}
	return raux;
}
int getTitulo(eLibro* plibro, char* titulo)
{
	int raux = 0;
	if(plibro != NULL)
	{
		raux = 1;
		strcpy(titulo, plibro->titulo);
	}
	return raux;
}
int setAutor(eLibro* plibro, char* autor)
{
	int raux = 0;
	if(plibro != NULL)
	{
		raux = 1;
		strcpy(plibro->autor, autor);
	}
	return raux;
}
int getAutor(eLibro* plibro, char* autor)
{
	int raux = 0;
	if(plibro != NULL)
	{
		raux = 1;
		strcpy(autor, plibro->autor);
	}
	return raux;
}
int setPrecio(eLibro* plibro, float precio)
{
	int raux = 0;
	if(plibro != NULL)
	{
		raux = 1;
		plibro->precio = precio;
	}
	return raux;
}
int getPrecio(eLibro* plibro, float* precio)
{
	int raux = 0;
	if(plibro != NULL)
	{
		raux = 1;
		*precio = plibro->precio;
	}
	return raux;
}
int setEditorial(eLibro* plibro, int editorial)
{
	int raux = 0;
	if(plibro != NULL)
	{
		raux = 1;
		plibro->idEditorial = editorial;
	}
	return raux;
}
int getEditorial(eLibro* plibro, int* editorial)
{
	int raux = 0;
	if(plibro != NULL)
	{
		raux = 1;
		*editorial = plibro->idEditorial;
	}
	return raux;
}

eLibro* NuevoLibroParametros(char* id, char* titulo, char* autor, char* precio, char* editorial)
{
	eLibro* pLibro;

	int exito;
	int idLibro;
	float precioLibro;
	int idEditorial;

	exito = 0;
	idLibro = atoi(id);
	precioLibro = atof(precio);
	idEditorial = atoi(editorial);

	pLibro = NuevoLibro();
	if(pLibro != NULL)
	{
		if(setId(pLibro, idLibro))
		{
			if(setTitulo(pLibro, titulo))
			{
				if(setAutor(pLibro, autor))
				{
					if(setPrecio(pLibro, precioLibro))
					{
						if(setEditorial(pLibro, idEditorial))
						{
							exito = 1;
						}
					}
				}
			}
		}
	}
	if(exito == 0)
	{
		BorrarLibro(pLibro);
	}
	return pLibro;
}

void BorrarLibro(eLibro* libro)
{
	free(libro);
}

int OrdenAutores(void* lib1, void* lib2)
{
	char autor1[64];
	char autor2[64];
	int raux;
	getAutor(lib1, autor1);
	getAutor(lib2, autor2);
	raux = strcmp(autor1, autor2);
	return raux;
}

int ImprimirUnLibro(eLibro* libro)
{
	int exito;
	int id;
	char titulo[128];
	char autor[128];
	float precio;
	exito = 0;
	if(libro != NULL)
	{
		exito = 1;
		getId(libro, &id);
		getTitulo(libro, titulo);
		getAutor(libro, autor);
		getPrecio(libro, &precio);
		printf("[%-3d] [%-50s] %-20s, $%.2f // Editorial ", id, titulo, autor, precio);
	}
	return exito;
}

int FiltroMinotauro(void* libro)
{
	int idLibro;
	int raux;
	getEditorial(libro, &idLibro);
	if(idLibro == 4)
	{
		raux = 1;
	}
	else
	{
		raux = 0;
	}
	return raux;
}

void FuncionMapeo(void* libro)
{
	int idEditorial;
	float precio;
	getEditorial(libro, &idEditorial);
	getPrecio(libro, &precio);
	switch(idEditorial)
	{
	case 1:
		if(precio >= 300)
		{
			precio = precio - (precio * 0.20);
		}
		break;
	case 2:
		if(precio <= 200)
		{
			precio = precio - (precio * 0.10);
		}
		break;
	}
	setPrecio(libro, precio);
}
