### Sí
##### A coding utility for native Spanish speakers

Sí is a pseudo-programming language that serves as a Spanish-based alternative to C++, so that Spanish speakers can write code using Spanish keywords that make more sense to them than English ones do. This is especially useful for Spanish-speaking students who are learning to code for the first time, allowing them to learn to write programs without having to first understand English.

In other words, code written using the Spanish keywords in Sí translates directly to C++ code that can be compiled and run without ever having to look at English.

For example, a Hello World program in C++ would look like this:
```
#include <iostream>
using namespace std;

int main(void)
{
        cout << "¡Hola, mundo!" << endl;
        return 0;
}
```
would be written in Sí like this:
```
#incluir <iostream>
usando nombres std;

int main(vacío)
{
        ca << "¡Hola, mundo!" << terml;
        volver 0;
}
```

#####Update:
Python (and general multi-language) support for Sí is currently in development and should be released (tentatively) by the end of October! I'm planning for it to compile and run the script at runtime, so that you could run Sí on your code and have Python start executing your code automatically.
Theoretically I could do the same with C and C++ code, but considering that compilation is manual in those languages and it isn't quite the same in Python, I'm thinking of leaving C and C++ as they are. 

#####To Use:

1. Clone the repository and compile with `make all`
2. Add the Sí executable to your path if you want.
  1. [Instructions to do so](http://unix.stackexchange.com/questions/162134/how-to-execute-a-bash-script-without-typing) if you don't know how!
3. From the command line, type `si <sífile>.si <destination>.cpp` (or `./si` if
the executable isn't in your path).
  1. If no destination is specified, `<sífile>.cpp` will be created and written.
4. The file will be translated to English C++ and can then be compiled and run.
5. `make all` will also make an executable called `is`, which is `si`, but backwards. In other words, it translates C++ into Sí.

#####Notes:

* A full list of words and their translations can be found [here](https://docs.google.com/document/d/1c7vxJ4XN6ZArNbPVxBXsT-MwcSWAqconURG9hyf_63w/edit?usp=sharing)
* This also theoretically works with other languages, notably C, as long as you specify that you're writing to a .c file instead of a .cpp one. I've played around with it and Python a little bit and it shoul work in a limited capacity - that is, once I add the keywords and make a few edits it should be fine and theoretically could work with any language. Stick to C++ and C for now.
* This program is, because of Windows's weird ANSI encoding of accented characters (and my limited experience with dealing with it), only questionably compatible with Windows at the moment. But let's be real, why were you coding on Windows anyway? God knows how this would work on the Windows command prompt. I'd rather not think about it. Updates to come.
* If you choose to only write some words in Spanish as opposed to all of them, that's chill too. The `si` command won't translate anything in English to Spanish.

#####Planned updates:

* More translations, of course.
* Compatibility with other languages
* Compiler support - admittedly, this whole thing isn't worth very much if you can't understand compiler messages
* Shell translations (i.e. having `qt` for quitar do the same thing as `rm`)
* A web app for Sí demonstration without the download
* Debugging, of which I'm sure plenty is needed

Any help at all with anything is more than welcome, so go ahead and fork and shoot a pull request - whatever you want!
Alternately, if you're lazy and just want to tell me something to do, hit me up [here.](http://goo.gl/forms/KPEAhqB33H3q5IcF2)
