/*
 * editorial.c
 *
 *  Created on: 30 nov. 2021
 *      Author: mateo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "editorial.h"

eEditorial* NuevoEditorial()
{
	eEditorial* pEdito;
	pEdito = (eEditorial*) malloc(sizeof(eEditorial));
	setIdEdito(pEdito, 0);
	setNombreEdito(pEdito, "");
	return pEdito;
}

int setIdEdito(eEditorial* pEdito, int id)
{
	int exito = 0;
	if(pEdito != NULL)
	{
		pEdito->idEditorial = id;
		exito = 1;
	}
	return exito;
}
int getIdEdito(eEditorial* pEdito, int* id)
{
	int exito = 0;
	if(pEdito != NULL)
	{
		*id = pEdito->idEditorial;
		exito = 1;
	}
	return exito;
}
int setNombreEdito(eEditorial* pEdito, char* nombre)
{
	int exito = 0;
	if(pEdito != NULL)
	{
		strcpy(pEdito->nombre, nombre);
		exito = 1;
	}
	return exito;
}
int getNombreEdito(eEditorial* pEdito, char* nombre)
{
	int exito = 0;
	if(pEdito != NULL)
	{
		strcpy(nombre, pEdito->nombre);
		exito = 1;
	}
	return exito;
}

eEditorial* NuevoEditorialParametros(char* id, char* nombre)
{
	eEditorial* pEdito;

	int exito = 0;
	int idEditorial;
	idEditorial = atoi(id);

	pEdito = NuevoEditorial();
	if(pEdito != NULL)
	{
		if(setIdEdito(pEdito, idEditorial))
		{
			if(setNombreEdito(pEdito, nombre))
			{
				exito = 1;
			}
		}
	}
	if(exito == 0)
	{
		BorrarEditorial(pEdito);
	}
	return pEdito;
}

void BorrarEditorial(eEditorial* pEdito)
{
	free(pEdito);
}

int ImprimirEditorial(LinkedList* listaEditorial, int id)
{
	int exito;
	eEditorial* aux;
	exito = 0;
	if(listaEditorial != NULL)
	{
		aux = EditorialPorId(listaEditorial, id);
		if(aux != NULL)
		{
			printf("%s", aux->nombre);
			exito = 1;
		}
	}
	return exito;
}

eEditorial* EditorialPorId(LinkedList* listaEditorial, int id)
{
	eEditorial* aux;
	int len;
	int x;
	len = ll_len(listaEditorial);
	for(x = 0; x < len; x++)
	{
		aux = ll_get(listaEditorial, x);
		if(aux->idEditorial == id)
		{
			break;
		}
	}
	return aux;
}

eEditorial* EditorialPorNombre(LinkedList* listaEditorial, char* nombre)
{
	eEditorial* aux;
	int len;
	int x;
	if(listaEditorial != NULL)
	{
		len = ll_len(listaEditorial);
		for(x = 0; x < len; x++)
		{
			aux = ll_get(listaEditorial, x);
			if(stricmp(aux->nombre, nombre) == 0)
			{
				break;
			}
		}
	}
	return aux;
}
