# Simulación de Pedidos Ya

Aplicación minimalista sobre el tema de Gestión de envíos, en base a la ya existente aplicación de “PedidosYa".

## Características
- Implementación de 3 tipos de estructuras con templates: Pila, lista enlazada doble y vector.
- Creación de funciones con lambdas y recursividad.
- Uso del algoritmo fisher yates y de diferentes tipos de ordenamientos.
- Uso de programación orientada a objetos, se implementaron 9 clases.
- Uso de archivos para leer y escribir.

## Funcionamiento del programa
1. Menú principal: 
   - iniciar sesión
   - registrar cuenta
   - salir
3. Si no tiene cuenta, se registra indicando su nombre de usuario, contraseña. Y si es su primera vez iniciando sesión, se le pide su nombre, dirección y teléfono.
4. El programa tiene un usuario llamado admin. Si inicia sesión con este usuario, se desplegará otro menú: 
   - ver usuarios
   - ordenar usuarios por nombre de usuarios
   - invertir el orden de los usuarios
   - eliminar el primer usuario
   - eliminar el último usuario
   - mostrar los usuarios de los programadores 
   - encontrar usuario por posición
5. Si inicia sesión con otra cuenta que no sea admin, entonces se desplegará el siguiente menú para hacer pedidos o envios: 
   - ver productos disponibles
   - ver productos a bajo costo
   - ver productos por categoría
   - hacer un pedido
   - ver pedidos
   - desordenar los pedidos
   - calcular el precio total de pedidos
   - buscar el menor precio de los pedidos
   - hacer un envio
   - ver envios
   - cancelar el último envio
   - mostrar envios realizados a los programadores
   - buscar envio por posición
   - modificar último envio
   - cerrar sesión
6. Cuando el usuario cierra sesión, vuelve al menú principal.

## Authors
- Jair Andreé Coraje Bayona
- Eric Fernando Cuevas Rios
- Lucero Abigail Obispo Rios 🙋🏻
