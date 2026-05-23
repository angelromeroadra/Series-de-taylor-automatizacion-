CXX      = g++
ESTANDAR = -std=c++11
INCLUDES = -Iinclude
OBJETIVO = matematicas

FUENTES = main.cpp \
          src/matematicas.cpp

OBJETOS = $(FUENTES:.cpp=.o)

all: $(OBJETIVO)

$(OBJETIVO): $(OBJETOS)
	$(CXX) $(ESTANDAR) $(OBJETOS) -o $(OBJETIVO)

%.o: %.cpp
	$(CXX) $(ESTANDAR) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJETOS) $(OBJETIVO)
