# Gen-Fork-Tree

Este proyecto permite generar un gráfico (usando Graphviz) de forma automática del árbol de procesos
que genera un código escrito en el lenguaje C. El propósito de esta herramienta es ayudar a visualizar
de forma clara y gráfica el árbol de procesos generados por un código escrito en C.

## Funcionamiento 
Para utilizar esta herramienta, se deben seguir las siguientes serie de pasos: 
- [x] Asegurarse de tener instalado Graphviz
- [x] Ejecutar make
- [x] Ejecutar genForkTree.out pasando como argumento la ruta y el nombre del archivo .c que se desea analizar. Ej: ./genForkTree.out /home/usuario/mi/ruta/archivo.c
        
- [x] Visualizar la imagen graph.png

### Consideraciones y Limitaciones

Actualmente es la primera versión funcional de esta pequeña herramienta, la cual posee algunas limitaciones
que se tratarán de solventar en versiones posteriores, a continuación se resumen en la siguiente lista:
  1. Todos los archivos PNG generados con esta herramienta se llamarán graph.png
	2. Los archivos .c de los cuales se desea generar el árbol de procesos, no deben tener operaciones de
    entrada-salida por otro medio que no sea ficheros. No soporta la interacción con el usuario (pantalla - teclado).
	3. Los arcos del árbol en algunas ocasiones serán múltiples, esto indica la cantidad de veces que se considera
    la relación (padre e hijo). En versiones posteriores estará disponible la opción de visualizar el árbol con 
    arcos únicos entre dos nodos, así como también otras opciones referentes al análisis.
	4. La herramienta fuerza a que no existan procesos huérfanos; por lo cual, no deberían existir procesos hijos del
    proceso con PID = 1.
   
### Reporte de Errores

Este proyecto se encuentra en fase de prueba, por lo cual se recomienda comparar el resultado del árbol con un análisis
manual del código, cualquier notificación de error, dudas o sugerencias por favor hacerlas llegar a las cuentas de correo:
  - alvarolac2@gmail.com
  - alvaroaraujo@yandex.com
  
### Ejemplos

Junto con el código fuente de la herramienta, se proporcionan 3 códigos de prueba: 
  * ejemploFork1.c
  * ejemploFork2.c
  * ejemploFork3.c
Estos códigos permiten probar el correcto funcionamiento de la herramienta. 
Ej:
  ./genForkTree.out ejemploFork1.c


   
