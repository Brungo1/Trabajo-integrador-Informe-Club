#ifndef MENU_H
#define MENU_H

// Funciones de utilidad
void mostrarEncabezado(const char* titulo, int color);

// Menús principales
void mostrarMenuPrincipal();
void menuSocios();
void menuActividades();
void menuInscripciones();
void menuPagos();
void menuCanchas();
void menuReservas();
void menuAsistencia();

// Funciones de socios
void agregarSocio();
void listarSocios();
void buscarSocio();
void modificarSocio();
void eliminarSocio();

// Funciones de actividades
void agregarActividad();
void listarActividades();
void buscarActividad();
void buscarActividadPorNombre();
void modificarActividad();
void desactivarActividad();

// Funciones de canchas
void agregarCancha();
void listarCanchas();
void buscarCancha();
void buscarCanchaPorTipo();
void modificarCancha();
void cambiarDisponibilidad();

// Funciones de pagos
void registrarPago();
void listarPagos();
void buscarPagosPorSocio();
void modificarEstadoPago();
void reportePagos();

// Funciones de inscripciones
void nuevaInscripcion();
void listarInscripciones();
void buscarInscripcionesPorSocio();
void buscarInscripcionesPorActividad();
void cancelarInscripcion();

// Funciones de reservas
void nuevaReserva();
void listarReservas();
void buscarReservasPorSocio();
void buscarReservasPorCancha();
void cancelarReserva();

// Funciones de asistencia
void registrarAsistencia();
void listarAsistencias();
void buscarAsistenciaPorSocio();
void buscarAsistenciaPorActividad();
void reporteAsistencia();

#endif