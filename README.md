# tarea-hash-csv
Tabla hash en C++ y Java con carga de estudiantes desde CSV, operaciones básicas y comparación de estructuras.

 Nombre: Carlos Daniel Castro Caceres  
 Carné: 9941-24-10004  



. Estructura del proyecto

tarea-hash-csv/

 cpp-hash/
 main.cpp
 estudiantes.csv

 java-hashmap/
 Main.java
 Estudiante.java
 estudiantes.csv

 evidencias/
 evidencia.pdf

 README.md
 

. Implementación en C++

. Descripción

Se implementó una tabla hash manual utilizando **Separate Chaining** con listas enlazadas.  
No se utilizaron estructuras STL como `map` o `unordered_map`.
La clave principal es:
- `student_id`


. Funcionalidades

- Carga de estudiantes desde archivo CSV  
- Inserción en tabla hash  
- Búsqueda por student_id  
- Eliminación por student_id  
- Detección de duplicados  
- Visualización por buckets  
- Conteo de estudiantes  
- Conteo de colisiones  
- Factor de carga  

Descripción

Se utilizó la estructura nativa HashMap<Integer, Estudiante> para almacenar estudiantes cargados desde CSV.


Ejecución
javac Main.java Estudiante.java
java Main
Comparación C++ vs Java

C++
Implementación manual de tabla hash
Manejo de colisiones con listas enlazadas
Mayor control y complejidad
Más código y lógica interna

Java
Uso de HashMap ya implementado
Manejo automático de colisiones
Menos código y más simple
Mayor abstracción
