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
	printf("| (6) - Mapeado.\n");
	printf("| (7) - Imprimir cuantos libros cuestan mas de 500\n");
	printf("| (8) - Total de precio de los libros de la editorial \"PEARSON\"\n");
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

int controller_7CuantosCuestan500mas(LinkedList* listaLibros)
{
	int cont;
	if(listaLibros != NULL)
	{
		cont = ll_count(listaLibros, LibrosSobre500);
		if(cont > 0)
		{
			printf("La cantidad de libros que cuestan mas de 500 son %d", cont);
		}
	}
	return cont;
}

int controller_8SumatoriaPrecioPearson(LinkedList* listaLibros)
{
	int suma;
	if(listaLibros != NULL)
	{
		suma = ll_count(listaLibros, SumatoriaLibrosPearson);
		if(suma > 0)
		{
			printf("La suma de los precios de los libros de la editorial pearson es de  $%d", suma);
		}
	}
	return suma;
}
