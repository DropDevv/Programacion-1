#include "Insercion.h"
#include <fstream>

using namespace std;

void insertarRegistro(Registro nuevo) {
    // Abre el archivo "datos.dat" en modo binario y en modo adjuntar (append)
    ofstream archivo("datos.dat", ios::binary | ios::app);
    if (!archivo.is_open()) // Verifica si el archivo se abrió correctamente
    {
        cerr << "Error abriendo archivo!";//msg de error
        return;// sale de la funcion
    }

    // Escribe en el archivo el contenido de la estructura "Registro"
    // obtiene la dirección de memoria de la variable y convierte esa dirección a un puntero de tipo char*.
    archivo.write((char*)&nuevo, sizeof(Registro)); 
    archivo.close();// cierra el archivo
    cout << "Registro insertado correctamente!" << endl;
}