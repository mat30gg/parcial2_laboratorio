/*
 * controller_Parcial2.c
 *
 *  Created on: 30 nov. 2021
 *      Author: mateo
 */

#include <stdio.h>
#include <stdlib.h>
#include "archivos.h"
#include "libro.h"
#include "editorial.h"
#include "../inc/LinkedList.h"
#include "controller_Parcial2.h"
#include "input.h"

int controller_MainMenu()
{
	int eleccion;
	printf("| (1) - Leer archivo con datos de libros.\n");
	printf("| (2) - Leer archivo con datos de editoriales.\n");
	printf("| (3) - Ordenar lista de libros por autor.\n");
	printf("| (4) - Imprimir datos de libros.\n");
	printf("| (5) - Listado de libros de editorial \"MINOTAURO\".\n");
	printf("| (0) - Salir.\n");
	eleccion = getInt("| Ingrese una opcion: ");
	return eleccion;
}

int controller_1LeerArchivoDeLibros(LinkedList* listaLibros)
{
	int exito;
	char nArchivo[64];
	FILE* pArchivo;

	exito = 0;
	SolicitarArchivo("Ingrese el nombre del archivo con los datos de libros: ", nArchivo, ".csv");
	pArchivo = fopen(nArchivo, "r");
	if(pArchivo != NULL && listaLibros != NULL)
	{
		LibrosDesdeTexto(pArchivo, listaLibros);
		exito = 1;
	}
	fclose(pArchivo);
	return exito;
}

int controller_2LeerArchivoDeEditoriales(LinkedList* listaEditoriales)
{
	int exito;
	char nArchivo[64];
	FILE* pArchivo;

	exito = 0;
	SolicitarArchivo("Ingrese el nombre del archivo con los datos de editoriales: ", nArchivo, ".csv");
	pArchivo = fopen(nArchivo, "r");
	if(pArchivo != NULL && listaEditoriales != NULL)
	{
		EditorialesDesdeTexto(pArchivo, listaEditoriales);
		exito = 1;
	}
	fclose(pArchivo);
	return exito;
}

int controller_3OrdenarLibrosPorAutor(LinkedList* listaLibros)
{
	int exito;
	exito = 0;
	if(listaLibros != NULL)
	{
		ll_sort(listaLibros, OrdenAutores, 1);
		exito = 1;
	}
	return exito;
}

int controller_4ImprimirLibros(LinkedList* listaLibros, LinkedList* listaEditoriales)
{
	eLibro* aux;
	int idEditorial;
	int exito;
	int len;
	int i;
	exito = 0;
	if(listaLibros != NULL && listaEditoriales != NULL)
	{
		len = ll_len(listaLibros);
		for(i = 0; i < len; i++)
		{
			aux = ll_get(listaLibros, i);
			getEditorial(aux, &idEditorial);
			ImprimirUnLibro(aux);
			ImprimirEditorial(listaEditoriales, idEditorial);
			printf("\n");
		}
		exito = 1;
	}
	return exito;
}

int controller_5ListadoMinotauro(LinkedList* listadoLibros)
{
	LinkedList* ListadoMinotauro;
	FILE* pArchivo;
	int exito;
	exito = 0;
	pArchivo = fopen("MINOTAURO.csv", "w");
	if(listadoLibros != NULL && pArchivo != NULL)
	{
		ListadoMinotauro = ll_filter(listadoLibros, FiltroMinotauro);
		LibrosATexto(pArchivo, ListadoMinotauro);
		exito = 1;
	}
	fclose(pArchivo);
	return exito;
}

int controller_6Mappeo(LinkedList* listadoLibros)
{
	LinkedList* ListaMapeada;
	FILE* pArchivo;
	int exito;
	exito = 0;
	pArchivo = fopen("mapeado.csv", "w");
	if(listadoLibros != NULL)
	{
		ListaMapeada = ll_map(listadoLibros, FuncionMapeo);
		LibrosATexto(pArchivo, ListaMapeada);
		exito = 1;
	}
	fclose(pArchivo);
	return exito;
}