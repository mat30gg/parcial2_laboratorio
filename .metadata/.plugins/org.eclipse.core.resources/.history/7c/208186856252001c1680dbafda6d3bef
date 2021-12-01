/*
 * editorial.h
 *
 *  Created on: 30 nov. 2021
 *      Author: mateo
 */

#ifndef EDITORIAL_H_
#define EDITORIAL_H_

typedef struct{
	int idEditorial;
	char nombre[64];
}eEditorial;

eEditorial* NuevoEditorial();
eEditorial* NuevoEditorialParametros(char* id, char* nombre);

int setIdEdito(eEditorial* pEdito, int id);
int getIdEdito(eEditorial* pEdito, int* id);
int setNombreEdito(eEditorial* pEdito, char* nombre);
int getNombreEdito(eEditorial* pEdito, char* nombre);

void BorrarEditorial(eEditorial* pEdito);
int ImprimirEditorial(LinkedList* listaEditorial, int id);
eEditorial* EditorialPorId(LinkedList* listaEditorial, int id);

#endif /* EDITORIAL_H_ */
