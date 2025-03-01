#include "busqueda.h"
#include <fstream>
#include "registro.h"

using namespace std; 

int buscarPosicion(int idBuscado)
{
	ifstream archivo("datos.dat" ,ios::binary);
	//Si el archivo no se pudo abrir, retorna -1 indicando un error 
	if (!archivo.is_open()) return -1;
	Registro reg; //variable donde se almacenara temporalmente cada registro leido 
	int pos = 0; //Contador de posicion para identificar en que indice esta el registro buscando
	// lee el archivo registro por registro hasta llegar al final 
	while (archivo.read((char*)&reg, sizeof(Registro)))
	{
		if (reg.id == idBuscado)
		{
			archivo.close(); // cierra el archivo antes de salir 
			return pos; // retorna la posicion donde se encontro el registro
		}
		pos++; // si no es el registro buscado, aumenta la posicion y sigue leyendo
	}
	archivo.close(); // cierra el archivo al finalizar la busqueda 
	return -1; // se no se encontro el ID retorno -1
	

}