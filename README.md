### En español [aquí](https://github.com/akercheval/si/blob/master/README_espa%C3%B1ol.md)

####Update:
Sí 2.0 is up and running! Translation to and from python is now available. 
Some things that are different about it:

1. Now, you must specify which language you'd like to translate to and from. This means the usage for a hypothetial file now looks like this: `si cpp testfile.si testfile.cpp`, whereas before it looked like `si testfile.si testfile.cpp` It's the same with python, by the way, you just need to replace `cpp` with `py`: `si py testfile.si testfile.py`
2. Sí will attempt to run the python script automatically, for a more (although not nearly perfect) python shell-like experience. *This only works with python3, not with anything younger.*
3. As always, translations are still in development. The current list for python can be found [here](https://docs.google.com/document/d/1-K0fD7VggYoBeeeJRqcQnw3W_9d-RqdDuT5c9MRoZ8E/edit?usp=sharing)

### Sí
##### A coding utility for native Spanish speakers

Sí is a pseudo-programming language that serves as a Spanish-based alternative to C++ and Python, so that Spanish speakers can write code using Spanish keywords that make more sense to them than English ones do. This is especially useful for Spanish-speaking students who are learning to code for the first time, allowing them to learn to write programs without having to first understand English.

In other words, code written using the Spanish keywords in Sí translates directly to C++ or Python code that can be compiled and run without ever having to look at English.

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

#####To Use:

1. Clone the repository and compile with `make all`
2. Add the Sí executable to your path if you want.
  1. [Instructions to do so](http://unix.stackexchange.com/questions/162134/how-to-execute-a-bash-script-without-typing) if you don't know how!
3. From the command line, type `si <cpp or py> <sífile>.si <destination>.<cpp or py>` (or `./si` if
the executable isn't in your path).
  1. If no destination is specified, `<sífile>.<cpp or py>` will be created and w.
4. The file will be translated to English C++ or Python and can then be compiled and run.
5. `make all` will also make an executable called `is`, which is `si`, but backwards. In other words, it translates C++ into Sí.

#####Notes:

* A full list of words and their translations can be found [here for C++](https://docs.google.com/document/d/1c7vxJ4XN6ZArNbPVxBXsT-MwcSWAqconURG9hyf_63w/edit?usp=sharing) and [here for Python](https://docs.google.com/document/d/1-K0fD7VggYoBeeeJRqcQnw3W_9d-RqdDuT5c9MRoZ8E/edit?usp=sharing)
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
