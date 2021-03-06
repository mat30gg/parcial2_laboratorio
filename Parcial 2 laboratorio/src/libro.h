/*
 * libro.h
 *
 *  Created on: 30 nov. 2021
 *      Author: mateo
 */

#ifndef LIBRO_H_
#define LIBRO_H_

typedef struct{
	int idLibro;
	char titulo[128];
	char autor[128];
	float precio;
	int idEditorial;
}eLibro;

eLibro* NuevoLibro();
eLibro* NuevoLibroParametros(char* id, char* titulo, char* autor, char* precio, char* editorial);
void BorrarLibro(eLibro*);

int setId(eLibro* plibro, int id);
int getId(eLibro* plibro, int* id);
int setTitulo(eLibro* plibro, char* titulo);
int getTitulo(eLibro* plibro, char* titulo);
int setAutor(eLibro* plibro, char* autor);
int getAutor(eLibro* plibro, char* autor);
int setPrecio(eLibro* plibro, float precio);
int getPrecio(eLibro* plibro, float* precio);
int setEditorial(eLibro* plibro, int editorial);
int getEditorial(eLibro* plibro, int* editorial);

int OrdenAutores(void*, void*);
int ImprimirUnLibro(eLibro*);
int FiltroMinotauro(void*);
void FuncionMapeo(void*);

int LibrosSobre500(void*);
int SumatoriaLibrosPearson(void*);

#endif /* LIBRO_H_ */
