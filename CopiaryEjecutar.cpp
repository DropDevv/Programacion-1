#include <iostream>
#include "registro.h"
#include "acceso.h"
#include "Insercion.h"
#include "Busqueda.h"
#include "Eliminacion.h"
#include "Modificacion.h"

using namespace std;

void mostrarMenu() {
    //menu
    cout << "\n===== GESTION DE ARCHIVOS ====="
        << "\n1. Mostrar todos"
        << "\n2. Buscar por ID"
        << "\n3. Agregar registro"
        << "\n4. Modificar registro"
        << "\n5. Eliminar registro"
        << "\n6. Salir"
        << "\nOpcion: ";
}

int main() {
    int opcion, id;
    Registro reg ; //variable de tipo registro

    do {
        mostrarMenu(); // dibuja el menu
        cin >> opcion; // guarde la opcion ingresada
        cin.ignore(); // Limpiar buffer

        switch (opcion) {
        case 1:
            leerArchivo(); // ejecuta la funcion leerArchivo de Acceso
            break;

        case 2:
            cout << "ID a buscar: ";
            cin >> id;
            buscarPorID(id); // ejecuta la funcion de buscarPorID de Acceso
            break;

        case 3:
            cout << "Nuevo registro:\nID: ";
            cin >> reg.id; // obtiene el id ingresado
            cout << "Nombre: ";
            cin.ignore();
            cin.getline(reg.nombre, 30);// obtiene el nombre ingresado, hasta 30 caracteres
            cout << "Salario: ";
            cin >> reg.salario; // obtiene el salario ingresado
            insertarRegistro(reg); // ejecuta la funcion de insertarRegistro de Insercion
            break;

        case 4:
            cout << "ID a modificar: ";
            cin >> reg.id;// obtiene el id ingresado
            cout << "Nuevo nombre: ";
            cin.ignore();
            cin.getline(reg.nombre, 30);// obtiene el nombre ingresado, hasta 30 caracteres
            cout << "Nuevo salario: ";
            cin >> reg.salario;// obtiene el salario ingresado
            modificarRegistro(reg); // ejecuta la funcion de modificarRegistro de Modificacion
            break;

        case 5:
            cout << "ID a eliminar: ";
            cin >> id;// obtiene el id ingresado
            eliminarRegistro(id);// ejecuta la funcion de eliminarRegistro de Modificacion
            break;
        }
    } while (opcion != 6);

    return 0;
}