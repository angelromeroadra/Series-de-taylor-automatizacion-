#include <stdio.h>
#include "include/matematicas.h"

// -- bueno entonces... muestro el menu principal --
void mostrar_menu() {
    printf("\n========================================\n");
    printf("   Calculadora Matematica sin librerias\n");
    printf("========================================\n");
    printf(" 1. Seno\n");
    printf(" 2. Coseno\n");
    printf(" 3. Tangente\n");
    printf(" 4. Raiz cuadrada\n");
    printf(" 5. Raiz cubica\n");
    printf(" 6. Potencia (base entera)\n");
    printf(" 7. Potencia (exponente real)\n");
    printf(" 8. Exponencial (e^x)\n");
    printf(" 9. Logaritmo natural\n");
    printf("10. Logaritmo base 10\n");
    printf(" 0. Salir\n");
    printf("========================================\n");
    printf("Opcion: ");
}

// -- a ver... ejecuto la opcion elegida por el usuario --
void ejecutar_opcion(int opcion) {
    double numero;
    double base;
    double exponente_real;
    double grados;
    int exponente_entero;

    if (opcion == 1 || opcion == 2 || opcion == 3) {
        printf("Angulo en grados: ");
        scanf("%lf", &grados);
        double radianes = grados_a_radianes(grados);

        if (opcion == 1) {
            printf("seno(%.4f°) = %.8f\n", grados, seno(radianes));
        } else if (opcion == 2) {
            printf("coseno(%.4f°) = %.8f\n", grados, coseno(radianes));
        } else {
            printf("tangente(%.4f°) = %.8f\n", grados, tangente(radianes));
        }

    } else if (opcion == 4) {
        printf("Numero: ");
        scanf("%lf", &numero);
        printf("raiz_cuadrada(%.4f) = %.8f\n", numero, raiz_cuadrada(numero));

    } else if (opcion == 5) {
        printf("Numero: ");
        scanf("%lf", &numero);
        printf("raiz_cubica(%.4f) = %.8f\n", numero, raiz_cubica(numero));

    } else if (opcion == 6) {
        printf("Base: ");
        scanf("%lf", &base);
        printf("Exponente entero: ");
        scanf("%d", &exponente_entero);
        printf("potencia(%.4f, %d) = %.8f\n", base, exponente_entero, potencia(base, exponente_entero));

    } else if (opcion == 7) {
        printf("Base: ");
        scanf("%lf", &base);
        printf("Exponente real: ");
        scanf("%lf", &exponente_real);
        printf("potencia_real(%.4f, %.4f) = %.8f\n", base, exponente_real, potencia_real(base, exponente_real));

    } else if (opcion == 8) {
        printf("Exponente x: ");
        scanf("%lf", &numero);
        printf("exponencial(%.4f) = %.8f\n", numero, exponencial(numero));

    } else if (opcion == 9) {
        printf("Numero (mayor que 0): ");
        scanf("%lf", &numero);
        printf("logaritmo_natural(%.4f) = %.8f\n", numero, logaritmo_natural(numero));

    } else if (opcion == 10) {
        printf("Numero (mayor que 0): ");
        scanf("%lf", &numero);
        printf("logaritmo_base_diez(%.4f) = %.8f\n", numero, logaritmo_base_diez(numero));
    }
}

// -- listo ya... punto de entrada con game loop del menu --
int main() {
    int opcion;

    printf("\nBienvenido. Todas las funciones se calculan\n");
    printf("desde cero, sin usar math.h ni ninguna libreria.\n");

    opcion = -1;
    while (opcion != 0) {
        mostrar_menu();
        scanf("%d", &opcion);

        if (opcion == 0) {
            printf("\nHasta luego.\n");
        } else if (opcion >= 1 && opcion <= 10) {
            ejecutar_opcion(opcion);
        } else {
            printf("Opcion no valida.\n");
        }
    }

    return 0;
}
