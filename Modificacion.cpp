#include "Modificacion.h"
#include "Busqueda.h"
#include <fstream>

using namespace std;

void modificarRegistro(Registro modificado)
{
	// Abre el archivo "datos.dat" en modo binario para lectura y escritura
	fstream archivo("datos.dat", ios::binary | ios::in | ios::out);
		if (!archivo.is_open()) // Verifica si el archivo se abrió correctamente
		{
			cerr << "Error abriendo el archivo!"; // msg de error
			return; // sale de la funcion
		}
		// Busca la posición del registro con el ID especificado
		int pos = buscarPosicion(modificado.id);
		// Si no se encuentra el registro, muestra un mensaje y sale de la función
		if (pos == -1)
		{
			cout << "Registro no encontrado!"<<endl;
			return; // sale de la funcion
		}

		archivo.seekp(pos * sizeof(Registro)); // se mueve el puntero de escritura (skeep) a una posicion espesifica
		//dentro del archivo binario para sobreescribir un registro existente
		archivo.write((char *)&modificado, sizeof(Registro));
		archivo.close();
		cout << "Registro modificado!"<<endl;
}