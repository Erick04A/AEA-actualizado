#include <stdio.h>
#include "lectura.h"
#include "operaciones.h"

int main() {
    int opcion;
    do {
        mostrarMenu();
        opcion = leerEntero("Seleccione una opcion: ");
        
        while(getchar() != '\n');

        switch (opcion) {
            case 1:
                ingresarProducto();
                break;
            case 2:
                editarProducto();
                break;
            case 3:
                eliminarProducto();
                break;
            case 4:
                listarProductos();
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 5);
    
    return 0;
}
