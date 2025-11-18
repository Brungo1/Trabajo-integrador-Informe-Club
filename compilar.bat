@echo off
echo Compilando Sistema de Gestion de Club...
clang++ main.cpp menu.cpp socios.cpp actividades.cpp canchas.cpp pagos.cpp inscripciones.cpp reservas.cpp asistencia.cpp -o club.exe
if %errorlevel% == 0 (
    echo Compilacion exitosa! Ejecutable: club.exe
) else (
    echo Error en la compilacion.
)
pause