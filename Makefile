# Makefile para el Sistema de Gestión de Club

# Compilador
CXX = clang++

# Flags de compilación
CXXFLAGS = -std=c++11 -Wall

# Nombre del ejecutable
TARGET = club.exe

# Archivos fuente
SOURCES = main.cpp menu.cpp socios.cpp actividades.cpp canchas.cpp pagos.cpp inscripciones.cpp reservas.cpp asistencia.cpp

# Archivos objeto
OBJECTS = $(SOURCES:.cpp=.o)

# Regla principal
all: $(TARGET)

# Compilar el ejecutable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Compilar archivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	del *.o $(TARGET)

# Ejecutar el programa
run: $(TARGET)
	./$(TARGET)

# Declarar targets que no son archivos
.PHONY: all clean run