#include <stdio.h>
#include "lectura.h"
#include "operaciones.h"

#define MAX_PRODUCTOS 100
#define MAX_NOMBRE 50

char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
int cantidades[MAX_PRODUCTOS];
float precios[MAX_PRODUCTOS];
int numProductos = 0;

void copiarCadena(char* destino, const char* origen) {
    while (*origen) {
        *destino = *origen;
        destino++;
        origen++;
    }
    *destino = '\0';
}

int revisaCadena(const char* cadena1, const char* cadena2) {
    while (*cadena1 && *cadena2) {
        char c1 = (*cadena1 >= 'A' && *cadena1 <= 'Z') ? *cadena1 + 32 : *cadena1;
        char c2 = (*cadena2 >= 'A' && *cadena2 <= 'Z') ? *cadena2 + 32 : *cadena2;
        if (c1 != c2) {
            return 0;
        }
        cadena1++;
        cadena2++;
    }
    return (*cadena1 == '\0' && *cadena2 == '\0');
}

void ingresarProducto() {
    if (numProductos < MAX_PRODUCTOS) {
        printf("Ingresar nombre del producto: ");
        scanf(" %[^\n]", nombres[numProductos]);
        
        cantidades[numProductos] = leerEnteroPositivo("Ingresar cantidad: ");
        precios[numProductos] = leerFlotantePositivo("Ingresar precio: ");
        
        numProductos++;
    } else {
        printf("Inventario lleno.\n");
    }
}

void editarProducto() {
    char nombreEditar[MAX_NOMBRE];
    printf("Ingresar nombre del producto a editar: ");
    scanf(" %[^\n]", nombreEditar);

    int encontrado = 0;
    for (int i = 0; i < numProductos; i++) {
        if (revisaCadena(nombres[i], nombreEditar)) {
            encontrado = 1;
            printf("Editar nombre del producto (anterior: %s): ", nombres[i]);
            scanf(" %[^\n]", nombres[i]);
            
            cantidades[i] = leerEnteroPositivo("Ingresar nueva cantidad: ");
            precios[i] = leerFlotantePositivo("Ingresar nuevo precio: ");
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}

void eliminarProducto() {
    char nombreEliminar[MAX_NOMBRE];
    printf("Ingresar nombre del producto a eliminar: ");
    scanf(" %[^\n]", nombreEliminar);

    int encontrado = 0;
    for (int i = 0; i < numProductos; i++) {
        if (revisaCadena(nombres[i], nombreEliminar)) {
            encontrado = 1;
            for (int j = i; j < numProductos - 1; j++) {
                copiarCadena(nombres[j], nombres[j + 1]);
                cantidades[j] = cantidades[j + 1];
                precios[j] = precios[j + 1];
            }
            numProductos--;
            printf("Producto eliminado.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}

void listarProductos() {
    if (numProductos > 0) {
        printf("Lista de productos:\n");
        for (int i = 0; i < numProductos; i++) {
            printf("Nombre: %s\n", nombres[i]);
            printf("Cantidad: %d\n", cantidades[i]);
            printf("Precio: %.2f\n", precios[i]);
            printf("\n");
        }
    } else {
        printf("No hay productos en el inventario.\n");
    }
}

void mostrarMenu() {
    printf("\nSistema de Inventarios\n");
    printf("1. Ingresar producto\n");
    printf("2. Editar producto\n");
    printf("3. Eliminar producto\n");
    printf("4. Listar productos\n");
    printf("5. Salir\n");
}
