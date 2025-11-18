# 📁 Estructura Modular del Proyecto

## 🎯 División del Código

El proyecto ha sido reorganizado en múltiples archivos .cpp para mejor mantenimiento y organización:

### 📄 Archivos Principales

#### `main.cpp`
- **Función:** Punto de entrada del programa
- **Contenido:** Solo la función `main()` que llama al menú principal
- **Tamaño:** Mínimo, solo 7 líneas

#### `menu.h`
- **Función:** Declaraciones de todas las funciones
- **Contenido:** Headers de funciones de menús y operaciones
- **Propósito:** Permitir que los archivos .cpp se comuniquen entre sí

#### `menu.cpp`
- **Función:** Sistema de menús y navegación
- **Contenido:** 
  - `mostrarEncabezado()` - Función de utilidad para títulos
  - `mostrarMenuPrincipal()` - Menú principal del sistema
  - `menuSocios()` - Menú de gestión de socios
  - `menuActividades()` - Menú de gestión de actividades
  - `menuPagos()` - Menú de gestión de pagos
  - `menuCanchas()` - Menú de gestión de canchas
  - `menuInscripciones()` - Menú de inscripciones (en desarrollo)
  - `menuReservas()` - Menú de reservas (en desarrollo)
  - `menuAsistencia()` - Menú de asistencia (en desarrollo)

#### `socios.cpp`
- **Función:** Operaciones CRUD para socios
- **Contenido:**
  - `agregarSocio()` - Alta de nuevos socios
  - `listarSocios()` - Listado de socios activos
  - `buscarSocio()` - Búsqueda por DNI o número
  - `modificarSocio()` - Modificación de datos
  - `eliminarSocio()` - Baja lógica de socios

#### `actividades.cpp`
- **Función:** Operaciones para actividades
- **Contenido:**
  - `agregarActividad()` - Alta de nuevas actividades
  - `listarActividades()` - Listado de actividades activas

#### `canchas.cpp`
- **Función:** Operaciones para canchas
- **Contenido:**
  - `agregarCancha()` - Alta de nuevas canchas
  - `listarCanchas()` - Listado de todas las canchas

#### `pagos.cpp`
- **Función:** Operaciones para pagos
- **Contenido:**
  - `registrarPago()` - Registro de nuevos pagos
  - `listarPagos()` - Listado de todos los pagos

## 🔧 Compilación

### Opción 1: Script Automático (Windows)
```bash
compilar.bat
```

### Opción 2: Makefile
```bash
make
```

### Opción 3: Comando Manual
```bash
clang++ main.cpp menu.cpp socios.cpp actividades.cpp canchas.cpp pagos.cpp inscripciones.cpp reservas.cpp asistencia.cpp -o club.exe
```

## 📊 Ventajas de la Modularización

### ✅ Mantenimiento
- **Fácil localización:** Cada funcionalidad en su archivo específico
- **Modificaciones aisladas:** Cambios en socios no afectan pagos
- **Debugging simplificado:** Errores más fáciles de localizar

### ✅ Colaboración
- **Trabajo en paralelo:** Diferentes desarrolladores pueden trabajar en diferentes módulos
- **Menos conflictos:** Menor probabilidad de conflictos en Git
- **Responsabilidades claras:** Cada archivo tiene un propósito específico

### ✅ Escalabilidad
- **Nuevas funciones:** Fácil agregar nuevos módulos
- **Reutilización:** Funciones pueden ser reutilizadas
- **Testing:** Cada módulo puede ser probado independientemente

### ✅ Organización
- **Código limpio:** Archivos más pequeños y enfocados
- **Navegación rápida:** Encontrar funciones específicas es más fácil
- **Documentación:** Cada archivo puede tener su propia documentación

## 🏗️ Estructura de Dependencias

```
main.cpp
    ↓
menu.cpp ← menu.h
    ↓
socios.cpp → ArchivoSocio.h → Socio.h
actividades.cpp → ArchivoActividad.h → Actividad.h
canchas.cpp → ArchivoCancha.h → Cancha.h
pagos.cpp → ArchivoPago.h → Pago.h
```

## 🚀 Próximos Pasos

### Módulos Completados
1. **inscripciones.cpp** - Gestión completa de inscripciones ✅
2. **reservas.cpp** - Gestión completa de reservas ✅
3. **asistencia.cpp** - Control completo de asistencia ✅

### Funciones Implementadas por Módulo
- **Socios:** Todas implementadas ✅
- **Actividades:** Todas implementadas ✅
- **Canchas:** Todas implementadas ✅
- **Pagos:** Todas implementadas ✅
- **Inscripciones:** Todas implementadas ✅
- **Reservas:** Todas implementadas ✅
- **Asistencia:** Todas implementadas ✅

## 📝 Convenciones de Código

### Nombres de Archivos
- **Entidades:** `socios.cpp`, `actividades.cpp`, etc.
- **Funciones:** Verbos descriptivos (`agregar`, `listar`, `buscar`)
- **Headers:** Mismo nombre que el .cpp pero con extensión .h

### Estructura de Funciones
```cpp
void nombreFuncion() {
    // 1. Declaración de variables
    // 2. Interfaz de usuario
    // 3. Validaciones
    // 4. Operaciones de archivo
    // 5. Mensajes de resultado
}
```

Esta estructura modular hace el proyecto más profesional, mantenible y escalable. 🎯