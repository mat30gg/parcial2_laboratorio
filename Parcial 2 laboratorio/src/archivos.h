/*
 * archivos.h
 *
 *  Created on: 30 nov. 2021
 *      Author: mateo
 */
#include "../inc/LinkedList.h"

#ifndef ARCHIVOS_H_
#define ARCHIVOS_H_

int LibrosDesdeTexto(FILE* pArchivo, LinkedList* listaLibros);
int EditorialesDesdeTexto(FILE* pArchivo, LinkedList* listaEditoriales);
int LibrosATexto(FILE* pArchivo, LinkedList* listaLibros);

#endif /* ARCHIVOS_H_ */
