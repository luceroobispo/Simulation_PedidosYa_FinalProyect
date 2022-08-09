# Simulación de Pedidos Ya

Aplicación minimalista sobre el tema de Gestión de envíos, en base a la ya existente aplicación de “PedidosYa".

## Características
- Implementación de 7 tipos de estructuras con templates: Pila, lista enlazada doble, vector, hashtable, cola, grafo y mapa.
- Creación de funciones con lambdas y recursividad.
- Uso del algoritmo fisher yates y de diferentes tipos de ordenamientos.
- Uso de programación orientada a objetos, se implementaron 28 clases.
- Uso de archivos para generar, leer y escribir 1 millon de datos.

## Funcionamiento del programa
1. Menú principal: 
   - iniciar sesión
   - registrar cuenta
   - salir
2. Si no tiene cuenta, se registra indicando su nombre de usuario y contraseña. Si es su primera vez iniciando sesión, se le pide su nombre, dirección y teléfono.
3. El programa tiene un usuario llamado admin. Si inicia sesión con este usuario, se desplegará otro menú: 
   - ver usuarios
   - ordenar usuarios por nombre de usuarios (bubbleSort con recursividad en lista enlazada doble)
   - invertir el orden de los usuarios
   - eliminar el primer usuario
   - eliminar el último usuario
   - mostrar los usuarios de los programadores 
   - encontrar usuario por posición
   - listar personal de delivery por areas
   - listar personal de delivery por condicion
   - mostrar el k-esimo personal de delivery con el salario mas bajo (quickSelect)
   - ordenar el personal de delivery por su salario (quickSort)
   - eliminar el primer rating (dequeue cola)
   - mostrar ratings
   - mostrar primer rating recibido (peek cola)
   - mostrar ratings con puntuacion baja y alta
   - insertar top cadena
   - mostrar los top cadena
   - guardar dataset .csv de 1 millon de ratings
   - leer dataset .txt de 1 millon de ratings
   - cargar dataset .txt de 1 millon de ratings
4. Si inicia sesión con otra cuenta que no sea admin, entonces se desplegará el siguiente menú para hacer pedidos o envios: 
   - ver productos disponibles
   - ver productos a bajo costo
   - ver productos por categoría
   - hacer un pedido
   - ver pedidos
   - desordenar los pedidos
   - ordenar pedidos (mergeSort)
   - calcular el precio total de pedidos
   - buscar el menor precio de los pedidos
   - hacer un envio (push pila)
   - ver envios
   - cancelar el último envio (pop pila)
   - mostrar envios realizados a los programadores
   - buscar envio por posición
   - modificar último envio
   - guardar ubicacion
   - guardar kilometraje entre ubicaciones
   - listar ubicaciones guardadas y sus relaciones (grafo)
   - cerrar sesión
5. Cuando el usuario cierra sesión, vuelve al menú principal.

## Authors
- Jair Andreé Coraje Bayona
- Eric Fernando Cuevas Rios
- Lucero Abigail Obispo Rios 🙋🏻
