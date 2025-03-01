#include "Eliminacion.h"
#include "registro.h"
#include <fstream>
#include <cstdio>

using namespace std;

void eliminarRegistro(int idEliminar)
{
	// Abre el archivo "datos.dat" en modo binario
	ifstream entrada("datos.dat", ios::binary);
	if (!entrada.is_open()) // Verifica si el archivo se abrió correctamente
	{
		cerr << "Error abriendo archivo!";// msg de error
		return;// sale de la funcion
	}

	// Abre un archivo temporal "temp.dat" en modo binario para escritura
	ofstream salida("temp.dat", ios::binary);
	Registro reg;  // variable de tipo registro
	bool eliminado = false; // Variable para indicar si el registro fue eliminado

	// Lee los registros del archivo de entrada uno por uno
	while (entrada.read((char*)&reg, sizeof(Registro))) 
	{
		// Si el ID del registro no coincide con el ID a eliminar, lo escribe en el archivo temporal
		if (reg.id != idEliminar)
		{
			salida.write((char*)&reg, sizeof(Registro));
		}
		else
		{
			eliminado = true;// Marca como eliminado si el ID coincide
		}
	}
	entrada.close();
	salida.close();

	// Cierra los archivos de entrada y salida
	remove("datos.dat");
	rename("temp.dat", "datos.dat");

	//musetra un msg si el registro fue eliminado o no
	if (eliminado) cout << "Registro elimindao!" << endl;
	else cout << "Registro no encontrado!" << endl;


}