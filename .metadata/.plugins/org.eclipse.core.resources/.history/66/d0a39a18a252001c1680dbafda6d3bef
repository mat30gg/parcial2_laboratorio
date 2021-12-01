/*
 ============================================================================
 Name        : Parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "controller_Parcial2.h"
#include "../inc/LinkedList.h"

int main(void) {
	setbuf(stdout, NULL);
	int banderaLibros = 0;
	int banderaEditoriales = 0;

	LinkedList* listaLibros = ll_newLinkedList();
	LinkedList* listaEditoriales = ll_newLinkedList();
	int eleccion;
	do{
		eleccion = controller_MainMenu();
		switch(eleccion)
		{
			case 1:
				controller_1LeerArchivoDeLibros(listaLibros);
				banderaLibros++;
				break;
			case 2:
				controller_2LeerArchivoDeEditoriales(listaEditoriales);
				banderaEditoriales++;
				break;
			case 3:
				controller_3OrdenarLibrosPorAutor(listaLibros);
				break;
			case 4:
				if(banderaLibros != 0 && banderaEditoriales != 0)
				{
					controller_4ImprimirLibros(listaLibros, listaEditoriales);
				}
				break;
			case 5:
				if(banderaLibros != 0)
				{
					controller_5ListadoMinotauro(listaLibros);
				}
				break;
			case 6:
				if(banderaLibros != 0)
				{
					controller_6Mappeo(listaLibros);
				}
				break;
		}
		printf("\n");
	}while(eleccion != 0);

	return 0;
}
