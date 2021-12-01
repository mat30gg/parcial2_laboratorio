/*
 * archivos.c
 *
 *  Created on: 30 nov. 2021
 *      Author: mateo
 */

#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "archivos.h"
#include "input.h"
#include "libro.h"
#include "editorial.h"

int LibrosDesdeTexto(FILE* pArchivo, LinkedList* listaLibros)
{
	int exito;
	eLibro* aux;
	char id[8];
	char titulo[128];
	char autor[128];
	char precio[8];
	char idEditorial[8];
	exito = 0;
	if(pArchivo != NULL)
	{
		exito = 1;
		fscanf(pArchivo, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n", id, titulo, autor, precio, idEditorial);
		while(!feof(pArchivo))
		{
			fscanf(pArchivo, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n", id, titulo, autor, precio, idEditorial);
			aux = NuevoLibroParametros(id, titulo, autor, precio, idEditorial);
			if(aux != NULL)
			{
				if(ll_add(listaLibros, aux) == -1)
				{
					exito = 0;
					break;
				}
			}
		}
	}
	return exito;
}

int EditorialesDesdeTexto(FILE* pArchivo, LinkedList* listaEditoriales)
{
	int exito;
	eEditorial* aux;
	char id[8];
	char nombre[64];
	exito = 0;
	if(pArchivo != NULL)
	{
		exito = 1;
		fscanf(pArchivo, "%[^;];%[^\n]\n", id, nombre);
		while(!feof(pArchivo))
		{
			fscanf(pArchivo, "%[^;];%[^\n]\n", id, nombre);
			aux = NuevoEditorialParametros(id, nombre);
			if(aux != NULL)
			{
				if(ll_add(listaEditoriales, aux) == -1)
				{
					exito = 0;
					break;
				}
			}
		}
	}
	return exito;
}

int LibrosATexto(FILE* pArchivo, LinkedList* listaLibros)
{
	eLibro* aux;
	int exito;
	int len;
	int x;

	int id;
	char titulo[128];
	char autor[128];
	float precio;
	int editorial;
	exito = 0;
	//aux = (eLibro*) malloc(sizeof(eLibro));
	if(pArchivo != NULL && listaLibros != NULL)
	{
		len = ll_len(listaLibros);
		for(x = 0; x < len; x++)
		{
			aux = ll_get(listaLibros, x);
			getId(aux, &id);
			getTitulo(aux, titulo);
			getAutor(aux, autor);
			getPrecio(aux, &precio);
			getEditorial(aux, &editorial);
			fprintf(pArchivo, "%d;%s;%s;%.2f;%d\n", id, titulo, autor, precio, editorial);
		}
		exito = 1;
	}
	return exito;
}
