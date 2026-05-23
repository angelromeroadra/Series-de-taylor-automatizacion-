# Calculadora Matemática sin Librerías

**Autor:** Angel David Romero Alarcon

---

##  Descripción

Implementación desde cero en C++ de las funciones matemáticas fundamentales **sin usar `math.h` ni ninguna librería externa**. Cada función está construida manualmente usando métodos numéricos clásicos:

- **Series de Taylor** para seno, coseno y exponencial
- **Método de Newton-Raphson** para raíz cuadrada y raíz cúbica
- **Serie logarítmica de Mercator** para logaritmo natural
- **Cambio de base** para logaritmo en base 10
- **Multiplicación repetida** para potencias enteras
- **Identidad `e^(b·ln(a))`** para potencias con exponente real

El programa presenta un menú interactivo en consola donde el usuario elige la función y escribe el valor a calcular.

---

##  Funciones disponibles

| # | Función | Método usado |
|---|---------|--------------|
| 1 | Seno | Serie de Taylor |
| 2 | Coseno | Serie de Taylor |
| 3 | Tangente | sin(x) / cos(x) |
| 4 | Raíz cuadrada | Newton-Raphson |
| 5 | Raíz cúbica | Newton-Raphson |
| 6 | Potencia entera | Multiplicación repetida |
| 7 | Potencia real | e^(b·ln(a)) |
| 8 | Exponencial e^x | Serie de Taylor |
| 9 | Logaritmo natural | Serie de Mercator |
| 10 | Logaritmo base 10 | Cambio de base |

---

##  Cómo compilar y ejecutar

### 🐧 Linux

**Con Make:**
```bash
make
./matematicas
```

**Con CMake:**
```bash
mkdir build && cd build
cmake ..
make
./matematicas
```

**Directo con g++:**
```bash
g++ -std=c++11 -Iinclude main.cpp src/matematicas.cpp -o matematicas
./matematicas
```

---

### Mac

**Con Make:**
```bash
make
./matematicas
```

**Con CMake:**
```bash
mkdir build && cd build
cmake ..
make
./matematicas
```

**Directo con g++:**
```bash
g++ -std=c++11 -Iinclude main.cpp src/matematicas.cpp -o matematicas
./matematicas
```

> Si no tienes g++, instala las herramientas de desarrollo con: `xcode-select --install`

---

### Windows

**Con CMake + MinGW:**
```bash
mkdir build && cd build
cmake .. -G "MinGW Makefiles"
mingw32-make
matematicas.exe
```

**Directo con g++ (MinGW):**
```bash
g++ -std=c++11 -Iinclude main.cpp src/matematicas.cpp -o matematicas.exe
matematicas.exe
```

> Si no tienes MinGW, descárgalo desde: https://www.mingw-w64.org

---

## Estructura del proyecto

```
matematicas/
├── README.md
├── CMakeLists.txt
├── Makefile
├── main.cpp
├── include/
│   └── matematicas.h
└── src/
    └── matematicas.cpp
```
