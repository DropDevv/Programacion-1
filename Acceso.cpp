#include "Acceso.h"
#include <iostream>

using namespace std;

void leerArchivo()
{
	ifstream archivo("datos.dat", ios::binary); // Abre el archivo "datos.dat" en modo binario
	if (!archivo.is_open()) 	// Verifica si el archivo se abrió correctamente
	{
		cerr << "Error abriendo archivo!"; //msg de error
		return; // sale de la funcion
	}

	Registro reg; // variable de tipo registro
	while (archivo.read((char*)&reg, sizeof(Registro)))// Lee el archivo mientras haya datos disponibles
	{
		// muestra los datos del archivo
		cout << "\nID: " << reg.id
			<< "\nNombre: " << reg.nombre
			<< "\nSalario: " << reg.salario << endl;
	}
	// cierra el archivo
	archivo.close();
};

void buscarPorID(int idBuscado)
{
	ifstream archivo("datos.dat", ios::binary); // Abre el archivo "datos.dat" en modo binario
	if (!archivo.is_open())// Verifica si el archivo se abrió correctamente
	{
		cerr << "Error abriendo archivo!"; // muestra msg de error
		return;//sale de la funcion
	}
	Registro reg; // variable de tipo registro
	bool encontrado = false;

	// Lee el archivo registro por registro mientras no se haya encontrado el ID buscado
	while (archivo.read((char*)&reg, sizeof(Registro)&& !encontrado)) 
	{
		if (reg.id == idBuscado) // compara si el id es igual al id que se busca
		{
			// Si el ID coincide, muestra la información del registro
			cout << "\nRegistro encontrado:" 
				<< "\nNombre: " << reg.nombre
				<< "\nSalario: " << reg.salario << endl;
			encontrado = true; // marca que el registro fue encontrado
		}
	}

	// Si no se encontró el registro, muestra un mensaje de aviso
	if (!encontrado) cout << "Registro no encontrado!" << endl;
	archivo.close(); //cierra el archivo
}
