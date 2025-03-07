# Get Next Line 🚀

El proyecto **Get Next Line** tiene como objetivo programar una función en C que lee una línea de un file descriptor. ¡Nunca más tendrás que lidiar con la tediosa tarea de leer líneas de un archivo manualmente! 🎉

---

## 📜 Resumen

**Get Next Line** es un proyecto diseñado para que aprendas a manejar **file descriptors** y a usar **variables estáticas** en C. El desafío consiste en implementar una función que lea línea por línea de un file descriptor, devolviendo la línea leída, y gestionando adecuadamente la memoria.

---

## 🚀 Objetivos

- Implementar la función `get_next_line` que lee y devuelve una línea de un file descriptor.
- Aprender y utilizar variables estáticas en C.
- Gestionar la memoria de manera eficiente sin fugas.
- Resolver problemas con buffer size configurable y múltiples file descriptors.

---
## Conceptos importantes

### ¿Qué es un File Descriptor?

Un **file descriptor** (descriptor de archivo) es un número entero que el kernel del sistema operativo asigna a un archivo abierto, un socket, una tubería (pipe) o cualquier otro recurso que pueda ser leído o escrito. Los file descriptors permiten a los programas manejar archivos y otros recursos de manera uniforme y abstracta.

#### Funciones Básicas de un File Descriptor

1. **Lectura y Escritura**:
   - **read(fd, buffer, tam)**: Lee bytes del file descriptor `fd` y los coloca en un buffer de tamaño `tam`.
   - **write(fd, buffer, tam)**: Toma los primeros `tam` bytes del buffer y los envía al file descriptor `fd`.

2. **Descriptores Estándar**:
   - **0**: Entrada estándar (stdin)
   - **1**: Salida estándar (stdout)
   - **2**: Error estándar (stderr).

3. **Gestión de Recursos**:
   - Los file descriptors permiten a los programas manejar archivos, sockets y otros recursos de manera uniforme y abstracta, sin preocuparse por los detalles del hardware subyacente.
---
## 🛠️ Instrucciones Generales

### Requisitos
- **Lenguaje**: C
- **Norma**: Asegúrate de seguir la [Norma](https://github.com/42School/norma) estrictamente.
- **Funciones permitidas**: `read`, `malloc`, `free`.

### Compilación
- Tu proyecto debe compilarse utilizando las siguientes flags:
  ```bash
  cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 <archivos>.c
