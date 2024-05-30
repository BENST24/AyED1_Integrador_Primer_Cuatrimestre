# AyED_Integrador_Primer_Cuatrimestre

# Sistema de Gestión de Invitados

Este proyecto es un programa en C++ para la gestión de invitados de un evento. El objetivo del programa es permitir la carga, modificación, búsqueda, eliminación y confirmación de asistencia de los invitados a una fiesta.

## Descripción

El programa utiliza estructuras y arreglos para manejar los invitados, cada uno de los cuales contiene información del invitado y un ticket único. La información se guarda y carga desde un archivo CSV.

### Funcionalidades

1. **Cargar Datos**: Lee los invitados de un archivo CSV y los carga en memoria.
2. **Guardar Datos**: Guarda los invitados en memoria en un archivo CSV.
3. **Agregar Invitado**: Permite agregar un nuevo invitado.
4. **Eliminar Invitado**: Permite eliminar un invitado existente.
5. **Modificar Invitado**: Permite modificar los datos de un invitado existente.
6. **Buscar Invitado**: Permite buscar un invitado por su ticket.
7. **Confirmar Asistencia**: Permite confirmar la asistencia de un invitado.
8. **Mostrar Invitados Confirmados**: Muestra todos los invitados que han confirmado su asistencia en la consola.

### Estructura del Proyecto

- `main.cpp`: Contiene la función principal del programa y el menú de opciones.
- `listainvitados.csv`: Archivo CSV utilizado para almacenar los invitados.