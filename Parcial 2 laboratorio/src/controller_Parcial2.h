/*
 * controller_Parcial2.h
 *
 *  Created on: 30 nov. 2021
 *      Author: mateo
 */
#include "../inc/LinkedList.h"

#ifndef CONTROLLER_PARCIAL2_H_
#define CONTROLLER_PARCIAL2_H_

int controller_MainMenu();
int controller_1LeerArchivoDeLibros(LinkedList*);
int controller_2LeerArchivoDeEditoriales(LinkedList*);
int controller_3OrdenarLibrosPorAutor(LinkedList*);
int controller_4ImprimirLibros(LinkedList*, LinkedList*);
int controller_5ListadoMinotauro(LinkedList*);
int controller_6Mappeo(LinkedList*);
int controller_7CuantosCuestan500mas(LinkedList*);
int controller_8SumatoriaPrecioPearson(LinkedList*);

#endif /* CONTROLLER_PARCIAL2_H_ */
