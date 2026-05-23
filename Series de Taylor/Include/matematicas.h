#ifndef MATEMATICAS_H
#define MATEMATICAS_H

// -- bueno pues... declaro todas las funciones matematicas propias --

// constantes
#define PI        3.14159265358979323846
#define EULER     2.71828182845904523536
#define PRECISION 0.000001
#define ITERACIONES 100

// potencia y raiz
double potencia(double base, int exponente);
double potencia_real(double base, double exponente);
double raiz_cuadrada(double numero);
double raiz_cubica(double numero);
double valor_absoluto(double numero);

// trigonometria
double seno(double angulo_radianes);
double coseno(double angulo_radianes);
double tangente(double angulo_radianes);

// logaritmos y exponencial
double exponencial(double exponente);
double logaritmo_natural(double numero);
double logaritmo_base_diez(double numero);

// utilidades
double factorial(int numero);
double normalizar_angulo(double angulo_radianes);
double grados_a_radianes(double grados);
double radianes_a_grados(double radianes);

#endif
