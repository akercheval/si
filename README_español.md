### Sí
##### Una herramienta de programación de computadoras para programadores hispanohablantes

Sí es una pseudo-lenguaje de programación que funciona como opción española de
programar en C++, para que programadores hispanohablantes pueden escribir código
usando palabras en español en lugar de palabras en inglés. Es especialmente útil
para estudientes hispanohablantes de informática porque pueden aprender cómo programar
sin tener que saber inglés también.

En otras palabras, programas escritos usando las palabras españolas en Sí traducen
directamente a C++, que puede ser compilado y ejecutado sin mirar una vez a inglés.

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

1. Haz `git clone` en el depósito, pon el ejecutable de Sí en tu bin, si quieres.
  1. [Instrucciones](http://unix.stackexchange.com/questions/162134/how-to-execute-a-bash-script-without-typing), si no sabes cómo hacerlo
2. Compila con `make all`
3. En el shell, escribe `si <archivosí>.si <destino>.cpp` (o `./sí` si el ejecutable
no está en tu bin). Nota que el comando y la extensión del archivo son escritos ´si´, sin
acento.
  1. Si no incluyas destino, `<archivosí>.cpp` será creado y escrito.
4. El archivo será traducido a C++ en inglés que puede ser compilado y ejecutado.
5. `make all` también compilará `is`, que es el opuesto de `si` - transla C++ a Sí.

#####Notas:

* Una lista completa de palabras y sus traducciónes está [aquí](https://docs.google.com/document/d/1c7vxJ4XN6ZArNbPVxBXsT-MwcSWAqconURG9hyf_63w/edit?usp=sharing)
* Es posible que este programa ya funciona con C también. En realidad solo es que ya no lo he probado.
  * Si de verdad funciona en C, tendrías que especificar escribir a un archivo de .c en lugar de un de .cpp.
* Este programa, como resulto de la codificación ANSI de carácteres acentuados en Windows, posiblemente no funciona en Windows. También no sé exactamente si esto es el caso, pero en realidad no deberías programar en Windows de todas formas.
* No pasa nada si escribes unas palabras en inglés u otras en español - Sí solo traduce lo que es en español

#####Actualizaciónes planificadas:

* Más traducciónes, siempre
* Compatabilidad con otras lenguajes de programación
* Traducciónes para mensajes del compilador
* Traducciones para el comandos del shell
* Un sitio web para Sí

¡Si me quieres ayudar, te doy la bienvenida! Enrédate con lo que quieres y arregla lo que puedes.
O, si eres perezoso y quieres darme tarea, dímelo [aquí.](http://goo.gl/forms/KPEAhqB33H3q5IcF2)
