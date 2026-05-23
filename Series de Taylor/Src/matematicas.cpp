#include "../include/matematicas.h"

// -- a ver... valor absoluto base para varios calculos --
double valor_absoluto(double numero) {
    if (numero < 0) {
        return -numero;
    }
    return numero;
}

// -- oye mira... potencia con exponente entero por multiplicacion repetida --
double potencia(double base, int exponente) {
    double resultado = 1.0;
    int indice;
    int exponente_positivo;

    if (exponente == 0) {
        return 1.0;
    }

    exponente_positivo = exponente;
    if (exponente < 0) {
        exponente_positivo = -exponente;
    }

    for (indice = 0; indice < exponente_positivo; indice++) {
        resultado = resultado * base;
    }

    if (exponente < 0) {
        return 1.0 / resultado;
    }
    return resultado;
}

// -- bueno entonces... factorial necesario para las series de Taylor --
double factorial(int numero) {
    double resultado = 1.0;
    int indice;

    if (numero <= 1) {
        return 1.0;
    }
    for (indice = 2; indice <= numero; indice++) {
        resultado = resultado * indice;
    }
    return resultado;
}

// -- dale pues... normalizo el angulo entre -PI y PI para mayor precision --
double normalizar_angulo(double angulo_radianes) {
    double dos_pi = 2.0 * PI;
    while (angulo_radianes > PI) {
        angulo_radianes = angulo_radianes - dos_pi;
    }
    while (angulo_radianes < -PI) {
        angulo_radianes = angulo_radianes + dos_pi;
    }
    return angulo_radianes;
}

// -- listo ya... seno por serie de Taylor: sin(x) = x - x^3/3! + x^5/5! ... --
double seno(double angulo_radianes) {
    double angulo_normalizado = normalizar_angulo(angulo_radianes);
    double resultado = 0.0;
    double termino;
    int indice;
    int exponente;

    for (indice = 0; indice < ITERACIONES; indice++) {
        exponente = 2 * indice + 1;
        termino   = potencia(angulo_normalizado, exponente) / factorial(exponente);
        if (indice % 2 == 0) {
            resultado = resultado + termino;
        } else {
            resultado = resultado - termino;
        }
        if (valor_absoluto(termino) < PRECISION) {
            break;
        }
    }
    return resultado;
}

// -- bueno pues... coseno por serie de Taylor: cos(x) = 1 - x^2/2! + x^4/4! ... --
double coseno(double angulo_radianes) {
    double angulo_normalizado = normalizar_angulo(angulo_radianes);
    double resultado = 0.0;
    double termino;
    int indice;
    int exponente;

    for (indice = 0; indice < ITERACIONES; indice++) {
        exponente = 2 * indice;
        termino   = potencia(angulo_normalizado, exponente) / factorial(exponente);
        if (indice % 2 == 0) {
            resultado = resultado + termino;
        } else {
            resultado = resultado - termino;
        }
        if (valor_absoluto(termino) < PRECISION) {
            break;
        }
    }
    return resultado;
}

// -- a ver... tangente como cociente de seno y coseno --
double tangente(double angulo_radianes) {
    double valor_coseno = coseno(angulo_radianes);
    if (valor_absoluto(valor_coseno) < PRECISION) {
        // tangente indefinida en este punto
        return 0.0;
    }
    return seno(angulo_radianes) / valor_coseno;
}

// -- oye mira... exponencial por serie de Taylor: e^x = 1 + x + x^2/2! ... --
double exponencial(double exponente) {
    double resultado = 1.0;
    double termino   = 1.0;
    int indice;

    for (indice = 1; indice < ITERACIONES; indice++) {
        termino   = termino * exponente / indice;
        resultado = resultado + termino;
        if (valor_absoluto(termino) < PRECISION) {
            break;
        }
    }
    return resultado;
}

// -- dale pues... logaritmo natural por serie: ln(x) = 2*(u + u^3/3 + u^5/5...) --
// donde u = (x-1)/(x+1), converge para todo x > 0
double logaritmo_natural(double numero) {
    double variable_u;
    double potencia_u;
    double resultado;
    double termino;
    int indice;

    if (numero <= 0.0) {
        return 0.0;
    }
    if (numero == 1.0) {
        return 0.0;
    }

    variable_u  = (numero - 1.0) / (numero + 1.0);
    potencia_u  = variable_u;
    resultado   = variable_u;

    for (indice = 1; indice < ITERACIONES; indice++) {
        potencia_u = potencia_u * variable_u * variable_u;
        termino    = potencia_u / (2 * indice + 1);
        resultado  = resultado + termino;
        if (valor_absoluto(termino) < PRECISION) {
            break;
        }
    }
    return 2.0 * resultado;
}

// -- bueno entonces... log base 10 usando cambio de base --
double logaritmo_base_diez(double numero) {
    if (numero <= 0.0) {
        return 0.0;
    }
    return logaritmo_natural(numero) / logaritmo_natural(10.0);
}

// -- listo ya... raiz cuadrada por metodo de Newton-Raphson --
double raiz_cuadrada(double numero) {
    double estimacion;
    double estimacion_nueva;
    int iteracion;

    if (numero < 0.0) {
        return 0.0;
    }
    if (numero == 0.0) {
        return 0.0;
    }

    estimacion = numero / 2.0;
    for (iteracion = 0; iteracion < ITERACIONES; iteracion++) {
        estimacion_nueva = (estimacion + numero / estimacion) / 2.0;
        if (valor_absoluto(estimacion_nueva - estimacion) < PRECISION) {
            break;
        }
        estimacion = estimacion_nueva;
    }
    return estimacion_nueva;
}

// -- a ver... raiz cubica por Newton-Raphson: x_nuevo = (2x + n/x^2) / 3 --
double raiz_cubica(double numero) {
    double estimacion;
    double estimacion_nueva;
    int iteracion;

    if (numero == 0.0) {
        return 0.0;
    }

    estimacion = numero / 3.0;
    if (estimacion == 0.0) {
        estimacion = 1.0;
    }

    for (iteracion = 0; iteracion < ITERACIONES; iteracion++) {
        estimacion_nueva = (2.0 * estimacion + numero / (estimacion * estimacion)) / 3.0;
        if (valor_absoluto(estimacion_nueva - estimacion) < PRECISION) {
            break;
        }
        estimacion = estimacion_nueva;
    }
    return estimacion_nueva;
}

// -- oye mira... potencia real usando e^(exponente * ln(base)) --
double potencia_real(double base, double exponente) {
    if (base <= 0.0) {
        return 0.0;
    }
    return exponencial(exponente * logaritmo_natural(base));
}

// -- bueno pues... conversion de grados a radianes --
double grados_a_radianes(double grados) {
    return grados * PI / 180.0;
}

// -- dale pues... conversion de radianes a grados --
double radianes_a_grados(double radianes) {
    return radianes * 180.0 / PI;
}
