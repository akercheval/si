####Sí 2.0 ya está!
En este versión de Sí, puedes usarlo con Python con función completa. Es bastante fácil,
pero hay unos cámbios que debería notar:

1. Ahora tienes que especificar con qué idioma estás usando Sí. Por ejemplo, en el pasado, usar Sí parecía así: `si archivo.si archivo.cpp`, pero ahora parece así: `si cpp archivo.si archivo.cpp` (o, por supuesto: `si py archivo.si archivo.py`)
2. El programa también tratará ejecutar Python con el archivo nuevo, para simiular el Python shell. *Esto sólo funciona con Python3*

### Sí
##### Una herramienta de programación de computadoras para programadores hispanohablantes

Sí es una pseudo-lenguaje de programación que funciona como opción española de
programar en C++ y Python, para que programadores hispanohablantes puedan escribir código
usando palabras en español en lugar de palabras en inglés. Es especialmente útil
para estudientas hispanohablantes de informática porque pueden aprender cómo programar
sin tener que saber inglés también.

En otras palabras, programas escritos usando las palabras españolas en Sí traducen
directamente a C++ o Python, que puede ser compilado y ejecutado sin mirar una vez a inglés.

Por ejemplo, una programa Hello World en C++ parecería así:
```
#include <iostream>
using namespace std;

int main(void)
{
        cout << "¡Hola, mundo!" << endl;
        return 0;
}
```
Pero en Sí, parece así:
```
#incluir <iostream>
usando nombres std;

int main(vacío)
{
        ca << "¡Hola, mundo!" << terml;
        volver 0;
}
```

#####Para usar:

1. Haz `git clone` en el depósito, compila con `make all` y pon el ejecutable de Sí en tu path, si quieres.
  1. [Instrucciones](http://unix.stackexchange.com/questions/162134/how-to-execute-a-bash-script-without-typing), si no sabes cómo hacerlo
3. En el shell, escribe `si <py o cpp> <archivosí>.si <destino>.<py o cpp>` (o `./sí` si el ejecutable
no está en tu path). Nota que el comando y la extensión del archivo son escritos ´si´, sin
acento.
  1. Si no incluyas destino, `<archivosí>.cpp` será creado y escrito.
4. El archivo será traducido a C++ o Python en inglés que puede ser compilado y ejecutado.
5. `make all` también compilará `is`, que es el opuesto de `si` - transla C++ a Sí.

#####Notas:

* Una lista completa de palabras y sus traducciónes está [aquí para C++](https://docs.google.com/document/d/1c7vxJ4XN6ZArNbPVxBXsT-MwcSWAqconURG9hyf_63w/edit?usp=sharing) y [aquí para Python](https://docs.google.com/document/d/1-K0fD7VggYoBeeeJRqcQnw3W_9d-RqdDuT5c9MRoZ8E/edit?usp=sharing)
* Este programa funciona con C, también. Solo tienes que especificar escribir a un archivo .c en lugar de un .cpp.
* Este programa, como resulto de la codificación ANSI de carácteres acentuados en Windows, posiblemente no funciona en Windows. También no sé exactamente si esto es el caso, pero en realidad no deberías programar en Windows de todas formas.
* No pasa nada si escribes unas palabras en inglés y otras en español - Sí solo traduce lo que es en español

#####Actualizaciónes planificadas:

* Más traducciónes, siempre
* Compatabilidad con otras lenguajes de programación
* Traducciónes para mensajes del compilador
* Traducciones para el comandos del shell
* Un sitio web para Sí

¡Si me quieres ayudar, te doy la bienvenida! Enrédate con lo que quieres y arregla lo que puedes.
O, si eres perezoso y quieres darme tarea, dímelo [aquí.](http://goo.gl/forms/KPEAhqB33H3q5IcF2)
