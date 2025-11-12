# 🏆 Sistema de Gestión de Club

**Trabajo Práctico Integrador - Programación II**

## 👥 Integrantes
- Nicolas Bernal
- Bruno Scapolla

## 📋 Descripción
Sistema completo de gestión para un club deportivo que permite administrar socios, actividades, canchas, reservas, pagos, inscripciones y asistencias.

## 🎯 Características Principales

### Gestión de Socios
- Alta, baja y modificación de socios
- Búsqueda por DNI o número de socio
- Control de estado (activo/eliminado)

### Gestión de Actividades
- Registro de actividades deportivas/recreativas
- Control de responsables y aranceles
- Estado activo/inactivo

### Gestión de Canchas
- Administración de canchas deportivas
- Tarifas por hora
- Control de disponibilidad

### Sistema de Reservas
- Reserva de canchas por horario
- Asociación con socios
- Confirmación de reservas

### Sistema de Pagos
- Registro de pagos de socios
- Conceptos y montos
- Estado de procesamiento

### Control de Inscripciones
- Inscripción de socios a actividades
- Fecha de inscripción
- Relación N:M entre socios y actividades

### Control de Asistencia
- Registro de asistencia a actividades
- Fecha y estado de presencia
- Estadísticas por socio/actividad

## 🏗️ Arquitectura

### Clases de Entidad (8)
1. **Socio** - Datos de socios del club
2. **Actividad** - Actividades ofrecidas
3. **Cancha** - Instalaciones deportivas
4. **Reserva** - Reservas de canchas
5. **Pago** - Pagos realizados
6. **Inscripcion** - Relación socio-actividad
7. **Asistencia** - Control de asistencia
8. **Fecha** - Clase auxiliar para fechas

### Clases de Persistencia (7)
1. **ArchivoSocio** - Gestiona socios.dat
2. **ArchivoActividad** - Gestiona actividades.dat
3. **ArchivoCancha** - Gestiona canchas.dat
4. **ArchivoReserva** - Gestiona reservas.dat
5. **ArchivoPago** - Gestiona pagos.dat
6. **ArchivoInscripcion** - Gestiona inscripciones.dat
7. **ArchivoAsistencia** - Gestiona asistencias.dat

**Total: 15 clases**

## 💾 Persistencia de Datos

### Archivos Binarios (.dat)
- `socios.dat` - Registros de socios
- `actividades.dat` - Registros de actividades
- `canchas.dat` - Registros de canchas
- `reservas.dat` - Registros de reservas
- `pagos.dat` - Registros de pagos
- `inscripciones.dat` - Registros de inscripciones
- `asistencias.dat` - Registros de asistencias

### Operaciones CRUD
Cada clase Archivo implementa:
- `guardar()` - Agregar nuevo registro
- `leer()` - Leer registro por posición
- `modificar()` - Actualizar registro existente
- `contarRegistros()` - Contar total de registros
- `buscar...()` - Métodos de búsqueda específicos

## 🛠️ Tecnologías

- **Lenguaje:** C++
- **Compilador:** Clang++
- **Paradigma:** Programación Orientada a Objetos
- **Persistencia:** Archivos binarios
- **Interfaz:** rlutil.h (colores en consola)
- **Control de versiones:** Git + GitHub

## 📁 Estructura del Proyecto

```
TpprograII/
├── main.cpp                    # Programa principal con menús
├── rlutil.h                    # Librería para interfaz colorida
│
├── Fecha.h                     # Clase auxiliar Fecha
├── Socio.h                     # Clase Socio
├── Actividad.h                 # Clase Actividad
├── Cancha.h                    # Clase Cancha
├── Reserva.h                   # Clase Reserva
├── Pago.h                      # Clase Pago
├── Inscripcion.h               # Clase Inscripcion
├── Asistencia.h                # Clase Asistencia
│
├── ArchivoSocio.h              # Persistencia de Socio
├── ArchivoActividad.h          # Persistencia de Actividad
├── ArchivoCancha.h             # Persistencia de Cancha
├── ArchivoReserva.h            # Persistencia de Reserva
├── ArchivoPago.h               # Persistencia de Pago
├── ArchivoInscripcion.h        # Persistencia de Inscripcion
├── ArchivoAsistencia.h         # Persistencia de Asistencia
│
├── DIAGRAMA_CLASES_COMPLETO.txt
├── INFORME_CLASES_PARA_PROFESOR.txt
├── RELACIONES_ENTRE_CLASES.txt
│
└── club.exe                    # Ejecutable compilado
```

## 🚀 Compilación y Ejecución

### Compilar
```bash
clang++ main.cpp -o club.exe
```

### Ejecutar
```bash
./club.exe
```

## 🎨 Interfaz

El sistema cuenta con menús interactivos con colores:
- **Menú Principal** - 7 módulos de gestión
- **Submenús** - Para cada entidad (Socios, Actividades, etc.)
- **Colores** - Usando rlutil.h para mejor experiencia

## 📊 Conceptos de POO Aplicados

✅ **Encapsulamiento** - Atributos privados con getters/setters  
✅ **Abstracción** - Clases representan entidades del mundo real  
✅ **Modularización** - Separación en archivos .h  
✅ **Reutilización** - Clase Fecha usada en múltiples clases  
✅ **Responsabilidad única** - Persistencia centralizada en clases Archivo

## 🔗 Relaciones entre Clases

### Composición
- Todas las entidades principales contienen objetos `Fecha`

### Asociación (por ID)
- `Reserva` → `Socio` + `Cancha`
- `Pago` → `Socio`
- `Inscripcion` → `Socio` + `Actividad` (N:M)
- `Asistencia` → `Socio` + `Actividad` (N:M)

### Gestión
- Cada clase `Archivo` gestiona una clase de entidad

## 📝 Decisiones de Diseño

### Persistencia Centralizada
Optamos por **NO** usar métodos `leerDisco()` y `escribirDisco()` en las clases de entidad. En su lugar, **centralizamos** toda la persistencia en las clases Archivo.

**Ventajas:**
- Una sola forma de persistir datos
- Responsabilidad única por clase
- Más fácil de mantener y extender
- Evita duplicación de código

### Entrada/Salida de Datos
Usamos **getters y setters** en lugar de métodos `cargar()` y `mostrar()` para mayor flexibilidad en el formato de entrada/salida según las necesidades de cada módulo.

## 📚 Documentación

- `DIAGRAMA_CLASES_COMPLETO.txt` - Diagrama detallado de todas las clases
- `INFORME_CLASES_PARA_PROFESOR.txt` - Respuestas a correcciones del profesor
- `RELACIONES_ENTRE_CLASES.txt` - Documentación de relaciones entre clases

## 🔗 Repositorio

[GitHub - Trabajo Integrador Club](https://github.com/Brungo1/Trabajo-integrador-Informe-Club.git)

## 📄 Licencia

Proyecto académico - Programación II

---

**Universidad Tecnológica Nacional (UTN)**  
**Facultad Regional General Pacheco**
