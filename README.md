# Schedule
Este es una aplicación escrita en C++, con fácil traducción a C. Se trata de una agenda electrónica.

## Documentación
Esta es una breve documentación sobre la agenda electrónica, mencionando que el código está totalmente comentado para su fácil lectura.

- - -

### Introducción
En la actualidad, desarrollar aplicaciones en C, C++ o bien, en un lenguaje de programación de bajo nivel, se le dice que sólo sirven para generar un mejor entendimiento para el incremento de lógica. Sin embargo, los que suelen transmitir ese tipo de ideas, probablemente no han construido aplicaciones que estén a la altura del lenguaje. Hay que desmantelar ese pensamiento.

Ahora bien, aprovechar este proyecto para sacar el máximo provecho en cuando aprendizaje, es fundamental, así que se desarrollará una aplicación de agenda, donde esta almacene contactos; estos contactos tienen atributos, tal y como si estuvieses gestionando con la aplicación que tienes instalada en el móvil u ordenador. Dejar de alguna manera todo aquello que fuere estático y convertirlo en algo dinámico, donde el usuario final tenga la capacidad de juguetear con la aplicación hasta dominar su uso y que realmente valga la pena utilizarla.

Este proyecto requiere de escribirla en C++, aunque con altas referencias del lenguaje C, hasta el punto que no cueste convertir el código fuente en este otro.

Existen algunos requerimientos dentro de la estructura de la aplicación, al menos en el punto importante y es sobre qué va a almacenar, en este caso, estarán definidor los atributos: Nombre, Teléfono, Celular, Email y Fecha de nacimiento.

El funcionamiento estará en la gestión de los contactos, como temas principales, el mostrar o listar los contactos que existan en la agenda, además de buscar, actualizar o modificar y eliminar.

Los eventos que existirán será que se puedan aplicar filtros, objetivamente en la sección de aplicar una búsqueda; que dicha búsqueda se pueda realizar por medio de los atributos del contacto, ya sea por Nombre, Teléfono, Celular o Email. Asimismo para agregar se tomará en cuenta parte de estos procedimientos, ya que al agregar un nuevo contacto se tendrá que comprobar si el nombre nuevo que se está ingresando se encuentra en la “base de datos” (la estructura), de tal manera que si se encuentra, se tendrá que escribir nuevos datos que no choquen con los ya registrados.

Los menús de la aplicación son interactivos, prácticamente haciendo una mueca completa a una aplicación normal para móvil, web o desktop en cuanto a la filosofía de su manipulación. Por lo que no es una aplicación predecible.

- - -

### Objetivos del proyecto
* Objetivo general: 

    * Desarrollar una aplicación en C++ con funcionalidades totales de una agenda electrónica (digital) utilizando estructuras de datos.

* Objtivos específicos: 

    *  Desarrollar una aplicación desktop en C++ con filosofía de Agenda Electrónica (digital).
    * Llevar a cabo el uso de estructuras para almacenar los datos (contactos).
    * Realizar una aplicación que interactúe (dinámicamente) con el usuario.
    * Aplicar eventos de contactos (crear, buscar, actualizar y eliminar).
    * Aplicar el toque de originalidad y diferenciación al algoritmo.
    * Testear la aplicación con datos por omisión para el mayor aprovechamiento del tiempo en la realización del mismo.

- - -

### Desarrollo
Por medio de la programación estructurada se pueden desarrollar excelentes aplicaciones, se asimila mejor al momento de escribir, entender y seguir implementando librerías que hacen que el programa se conviera en aquel que en ciertos momentos imaginamos que sería.

Probablemente, ya se han creado millones de agendas electrónicas, nunca se termina de tomar esa filosofía (idea) para desarrollar un mejor concepto sobre el lenguaje y así pasar al siguiente nivel. Lo importante de elaborar programas tan repetitivos como estos, es que se le puede ir sumando cierto grado de complejidad, ya que si seguimos a detalle qué instrucciones son mejores que otras en cuanto a rendimiento, sabremos que estamos yendo por el buen camino, aún así si se está escribiendo una aplicación de no tan alta gama de importancia.

Se debe estructurar correctamente la aplicación, fragmentarla de forma tal, que otro programado la pueda entender, aplicando formalidades o técnicas para buenas prácticas. Así que siguiendo el guion del documento que se nos ha impartido para llevar a cabo la realización de este proyecto, estaremos describiendo punto por punto los trozos de código de total relevancia.

El paso más importante es el de la estructura donde se almacenarán los datos, todas aquellas referencias que haremos al aplicar las funcionalidades planteadas (mostrar, buscar, actualizar, eliminar). Lo primero que se debe tener en cuenta es que una aplicación de verdad (que está en el mercado) sobre este tipo de filosofía, no se accede y directamente hay controles de eliminar contactos, ya que si es la primera vez que se instala y se ejcuta, no existen contactos, así qu es ilógico pensar de que en la primera pantalla le aparecerá buscar, actualizar, eliminar contactos, porque claro, precisamente no hay contactos.

La existencia de información en la estructura me dice que hay contactos en la agenda y que ahora sí, se puede mostrar menús de opciones para poder navegar sobre algunas como: Realizar una búsqueda, Listar, Salir de la aplicación.

Los eventos de actualizar y eliminar, serán tratados como debe ser, de forma tal, que sólo cuando se haga una búsqueda del contacto y se haya encontrado (se entenderá que ha sido seleccionado), es ahí donde se mostrarán las opciones de Actualizar y Eliminar respectivamente.
Todos estos eventos tienen centinelas que consultará con una pregunta si desea salir de aplicación o advertencias por si desea modificar o eliminar un contacto.

- - -

### Experiencia Obtenida
Todo lo que tiene que ver con estructuras, puede parecer difícil en un principio, sin embargo, cuando se pone en práctica toda aquella teoría supuestamente aburrida, todo cambia, hasta la forma de pensar, de cómo se crean objetos, de cómo se almacena la información con respecto a los espacios de memoria establecidos; existen muchas curiosidades que aún se están investigando, sabemos que esta aplicación se puede mejorar.

Se ha aprendido mucho con la guía y por parte de una extensa investigación sobre el manejo de estructuras y sus referencias.

Se aprendió como manipular estructuras de diferentes formas, así para darle un toque más de originalidad en cuanto a su escritura.

- - -

### Recomendaciones para mejorar
* Poner colores (Foreground, Background) por medio de notación húngara.
* Agregar sonidos (para Windows, código Visual Basic Script) o bien, alguna librería que favorezca en este tema.
* Agregar efectos visuales (aplicando ciclos, para cuestiones de carga).
* Almacenar un respaldo de la información en ficheros para que sea más persistente o sobre un sistema gestor de base de datos.
* Utilizar ventanas modales.
* Adaptarle interfaz gráfica. 

### Conclusion
En el desarrollo de esta agenda electrónica, se ha destacado el uso de estructuras, por encima de los arreglos unidimensionales y multidimensionales normales de enteros, flotantes y cadenas, orientándose así directamente a estructuras. Se ha logrado con creces, la inventiva de la aplicación para la interacción con el usuario final, tomando en cuenta que se ha creado todos los eventos necesarios para tener una agenda electrónica completa en cuanto a funcionalidad.

Los eventos de contactos se han creado y se han puesto en marcha exitosamente, correspondiendo a cada punto orientado en la guía para la elaboración de este proyecto, dejando sin lugar a duda, todos los puntos en discusión, resueltos.

La aplicación está accesible, todas las instrucciones de relevancia totalmente comentadas.