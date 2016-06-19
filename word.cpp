#include "word.h"
#include <fstream>
using namespace std;

void Word::set_out(string new_out)
{
        out.open(new_out);
}

void Word::set_in(string new_in)
{
        in.open(new_in);
}

void Word::close_files()
{
        in.close();
        out.close();
}

void Word::check_front()
{
        string com_check;

        com_check.clear();
        
        /* analyze front of word and set ignores if necessary */

        while (!isalnum(word.front()) && (word.size() >= 1)) {
                com_check += word.front();
                out << word.front();
                word.erase(0,1);
                if (com_check == "//") {
                        ignore = true;
                }
                else if (com_check == "/*") {
                        long_ignore = true;
                }
                else if (com_check == "*/" && long_ignore) {
                        long_ignore = false;
                } 
                else if (com_check == "\x22" && !q_ignore) {
                        q_ignore = true;
                }
                else if(com_check == "\x22" && q_ignore) {
                        q_ignore = false;
                }
        }
}

void Word::split_word()
{
        /* loops through the whole word taken in. if symbols are found,
         * splits word up for piece-by-piece analysis and stores
         * symbols elsewhere, that way a theoretically valid "word"
         * like ca<<rzcb((mi_matríz->mi_palabra.tamaño))<<terml;
         * gets everything necessary to change to English changed.
         */
        unsigned long i = 0;
        while (i != word.length()) {
                /* loop through word until non-aplhanumeric is found */
                if(!isalnum(word[i]) && (!isspace(word[i])) 
                   && word[i] != '_') { 
                        /* put word up to that point in vector */
                        wvec.push_back(word.substr(0,i));
                        word.erase(0,i);
                        i = 0;
                        /* parse through non-alphanums and set ignores */
                        while (!isalnum(word[i]) && !isspace(word[i]) &&
                                i != word.length()) {
                                if (word[i] == '/' && word[i + 1] == '/') {
                                        ignore = true;
                                }
                                else if (word[i] == '"' && !q_ignore) {
                                        q_ignore = true;
                                }
                                else if (word[i] == '/' && word[i + 1] == '*') {
                                        long_ignore = true;
                                }
                                i++;
                        }
                        /* put non-alphanums in vector */
                        symvec.push_back(word.substr(0,i));
                        word.erase(0,i);
                        i = 0;
                        continue;
                }
                i++;
        }
        if (word.length() != 0)
                wvec.push_back(word);
}

void Word::print_word()
{
        string sym;
                /* empty word and sym vectors and translate/print them
                 * as necessary */

        while (!wvec.empty()) {
                word = wvec.front();
                wvec.erase(wvec.begin());

                if (long_ignore || q_ignore || ignore)
                        out << word;
                else 
                        translate_word();

                if (!symvec.empty()) {
                        sym = symvec.front();
                        out << sym;
                        /* turn off ignores */
                        if ((sym.find("*/") != string::npos)
                             && long_ignore)
                                long_ignore = false;
                        else if ((sym.find("\x22") != string::npos)
                                  && q_ignore)
                                q_ignore = false;
                        symvec.erase(symvec.begin());
                }
        }

        /* print whitespace where necessary */
        while(isspace(in.peek())){
                while(in.peek() == ' '){
                        out << ' ';
                        in.get();
                }
                while(in.peek() == '\t'){
                        out << "\t";
                        in.get();
                }
                while(in.peek() == '\n'){
                        out << endl;
                        in.get();
                        if (ignore) {
                                ignore = false;
                        }
                }
        }
}


void Word::translate_word()
{
        /* etc */
        if (word == "incluir")
                out << "include";
        else if (word == "usando")
                out << "using";
        else if (word == "nombres")
                out << "namespace";
        else if (word == "defina")
                out << "define";
        else if (word == "sinodef")
                out << "ifndef";
        else if (word == "termsi")
                out << "endif";
        else if (word == "salir")
                out << "exit";
        else if (word == "volver")
                out << "return";
        
        /* general data types */
        else if (word == "carác")
                out << "char";
        else if (word == "palab")
                out << "string";
        else if (word == "archivo")
                out << "file";
        else if (word == "ARCHIVO")
                out << "FILE";
        else if (word == "larg")
                out << "long";
        else if (word == "flot")
                out << "float";
        else if (word == "doble")
                out << "double";
        else if (word == "Class")
                out << "Clase";
        else if (word == "struct")
                out << "estruct";
        else if (word == "no_signo")
                out << "unsigned";
        else if (word == "void")
                out << "vacío";
       
        /* flow control */
        else if (word == "si")
                out << "if";
        else if (word == "si_no")
                out << "else";
        else if (word == "para")
                out << "for";
        else if (word == "mientras")
                out << "while";
        else if (word == "haz")
                out << "do";
        else if (word == "romper")
                out << "break";
        else if (word == "continuar")
                out << "continue";
        else if (word == "interr")
                out << "switch";
        else if (word == "caso")
                out << "case";

        
        /* assert.h */
        else if (word == "afirma")
                out << "assert";
        
        /* ctype.h */
        else if (word == "esalnum")
                out << "isalpha";
        else if (word == "esalfa")
                out << "isalpha";
        else if (word == "esvacio")
                out << "isblank";
        else if (word == "escntrl")
                out << "iscntrl";
        else if (word == "esdec")
                out << "isdigit";
        else if (word == "esgraf")
                out << "isgraph";
        else if (word == "esminúsc")
                out << "islower";
        else if (word == "esimprim")
                out << "isprint";
        else if (word == "espunt")
                out << "ispunct";
        else if (word == "esespac")
                out << "isspace";
        else if (word == "esmayúsc")
                out << "isupper";
        else if (word == "eshexa")
                out << "isxdigit";
        else if (word == "aminúsc")
                out << "tolower";
        else if (word == "amayúsc")
                out << "toupper";

        /* errno.h */
        else if (word == "errnum")
                out << "errno";

        /* iso646.h */
        else if (word == "y")
                out << "and";
        else if (word == "y_ig")
                out << "and_eq";
        else if (word == "bit_y")
                out << "bitand";
        else if (word == "bit_o")
                out << "bitor";
        else if (word == "no")
                out << "not";
        else if (word == "no_ig")
                out << "not_eq";
        else if (word == "o")
                out << "or";
        else if (word == "o_ig")
                out << "or_eq";
        else if (word == "oex")
                out << "xor";
        else if (word == "oex_ig")
                out << "xor_eq";
        
        /* math.h */
        else if (word == "seno")
                out << "sin";
        else if (word == "asen")
                out << "asin";
        else if (word == "senh")
                out << "sinh";
        else if (word == "asenh")
                out << "asinh";
        else if (word == "log1m")
                out << "log1p";
        else if (word == "pot")
                out << "pow";
        else if (word == "rzcd")
                out << "sqrt";
        else if (word == "rzcb")
                out << "cbrt";
        else if (word == "hipot")
                out << "hypot";
        else if (word == "tope")
                out << "ceil";
        else if (word == "suelo")
                out << "floor";
        else if (word == "redond")
                out << "round";
        else if (word == "lredond")
                out << "lround";
        else if (word == "llredond")
                out << "llround";
        else if (word == "cercaint")
                out << "nearbyint";
        else if (word == "resto")
                out << "remainder";
        else if (word == "rescoc")
                out << "remquo";
        else if (word == "copsigno")
                out << "copysign";
        else if (word == "non")
                out << "nan";
        else if (word == "siguiente")
                out << "nextafter";
        else if (word == "sig_a")
                out << "nexttoward";
        else if (word == "fdif")
                out << "fdim";
        else if (word == "fms")
                out << "fma";
        else if (word == "fpclas")
                out << "fpclassify";
        else if (word == "esfinito")
                out << "isfinite";
        else if (word == "esinfinito")
                out << "isinf";
        else if (word == "esnon")
                out << "isnan";
        else if (word == "esnormal")
                out << "isnormal";
        else if (word == "signobit")
                out << "signbit";
        else if (word == "esmás")
                out << "isgreater";
        else if (word == "ismásigual")
                out << "isgreaterequal";
        else if (word == "esmenos")
                out << "isless";
        else if (word == "esmenosigual")
                out << "islessequal";
        else if (word == "esmásmenos")
                out << "islessgreater";
        else if (word == "esnoordenado")
                out << "isunordered";
        else if (word == "INFINITO")
                out << "INFINITY";
        else if (word == "NON")
                out << "NAN";
        else if (word == "GRANDE")
                out << "HUGE_VAL";
        else if (word == "GRANDEF")
                out << "HUGE_VALF";
        else if (word == "GRANDEL")
                out << "HUGE_VALL";
        
        /* setjmp.h */
        else if (word == "brinclg")
                out << "longjmp";
        else if (word == "ponbrinc")
                out << "setjmp";

        /* signal.h */
        else if (word == "señal")
                out << "signal";
        else if (word == "elevar")
                out << "raise";

        /* stddef.h */
        else if (word == "ptodif_t")
                out << "ptrdiff_t";
        else if (word == "tamaño_t")
                out << "size_t";
        else if (word == "máx_nivel_t")
                out << "max_align_t";
        else if (word == "nulopto_t")
                out << "nullptr_t";
        else if (word == "compensadode")
                out << "offsetof";
        else if (word == "NULO")
                out << "NULL";

        /* stdio.h */
        else if (word == "quitar")
                out << "remove";
        else if (word == "renombrar")
                out << "rename";
        else if (word == "archivotmp")
                out << "tmpfile";
        else if (word == "nombretmp")
                out << "tmpnam";
        else if (word == "fcerrar")
                out << "fclose";
        else if (word == "fdescarg")
                out << "fflush";
        else if (word == "fabrir")
                out << "fopen";
        else if (word == "freopen")
                out << "freabrir";
        else if (word == "ponguarda")
                out << "setbuf";
        else if (word == "ponvguarda")
                out << "setvbuf";
        else if (word == "fimprimaf")
                out << "fprintf";
        else if (word == "fescanf")
                out << "fscanf";
        else if (word == "imprimaf")
                out << "printf";
        else if (word == "escanf")
                out << "scanf";
        else if (word == "snimprimaf")
                out << "snprintf";
        else if (word == "simprimaf")
                out << "sprintf";
        else if (word == "sescanf")
                out << "sscanf";
        else if (word == "vfimprimaf")
                out << "vfprintf";
        else if (word == "vfescanf")
                out << "vfscanf";
        else if (word == "vimprimaf")
                out << "vprintf";
        else if (word == "vescanf")
                out << "vscanf";
        else if (word == "vsnimprimaf")
                out << "vsnprintf";
        else if (word == "vsimprimaf")
                out << "vsprintf";
        else if (word == "vsescanf")
                out << "vsscanf";
        else if (word == "fsacac")
                out << "fgetc";
        else if (word == "fsacas")
                out << "fgets";
        else if (word == "fponc")
                out << "fputc";
        else if (word == "fpons")
                out << "fputs";
        else if (word == "sacac")
                out << "getc";
        else if (word == "sacacarác")
                out << "getchar";
        else if (word == "sacas")
                out << "gets";
        else if (word == "ponc")
                out << "putc";
        else if (word == "poncarác")
                out << "putchar";
        else if (word == "pons")
                out << "puts";
        else if (word == "dessacac")
                out << "ungetc";
        else if (word == "fleer")
                out << "fread";
        else if (word == "fescribir")
                out << "fwrite";
        else if (word == "fsacapos")
                out << "fgetpos";
        else if (word == "fbusc")
                out << "fseek";
        else if (word == "fponpos")
                out << "fsetpos";
        else if (word == "fdecir")
                out << "ftell";
        else if (word == "rebob")
                out << "rewind";
        else if (word == "quitaerr")
                out << "clearerr";
        else if (word == "ffda")
                out << "feof";
        else if (word == "ierror")
                out << "perror";
        
        /* stdlib.h */
        else if (word == "paadob")
                out << "atof";
        else if (word == "paaint")
                out << "atoi";
        else if (word == "paall")
                out << "atoll";
        else if (word == "paladob")
                out << "strtod";
        else if (word == "palaflo")
                out << "strtof";
        else if (word == "palal")
                out << "strtol";
        else if (word == "palald")
                out << "strtold";
        else if (word == "palall")
                out << "strtoll";
        else if (word == "palansl")
                out << "strtoul";
        else if (word == "palansll")
                out << "strtoull";
        else if (word == "aleat")
                out << "rand";
        else if (word == "saleat")
                out << "srand";
        else if (word == "casign")
                out << "calloc";
        else if (word == "lib")
                out << "free";
        else if (word == "masign")
                out << "malloc";
        else if (word == "reasign")
                out << "realloc";
        else if (word == "ensalir")
                out << "atexit";
        else if (word == "en_salir_rápido")
                out << "at_quick_exit";
        else if (word == "sistema")
                out << "system";
        else if (word == "_Salir")
                out << "_Exit";
        else if (word == "bbusca")
                out << "bsearch";
        else if (word == "rordena")
                out << "qsort";
        else if (word == "mbtam")
                out << "mblen";
        else if (word == "mbacl")
                out << "mbtowc";
        else if (word == "clamb")
                out << "wctomb";
        else if (word == "mbaclpal")
                out << "mbtowcs";
        else if (word == "clpalampbal")
                out << "wvstombs";
        else if (word == "SALIR_FRACASO")
                out << "EXIT_FAILURE";
        else if (word == "SALIR_ÉXITO")
                out << "EXIT_SUCCESS";
        else if (word == "MB_TAM_MÁX")
                out << "MB_CUR_MAX";
        else if (word == "NULO")
                out << "NULL";
        else if (word == "ALEATORIO_MÁX")
                out << "RAND_MAX";

        /* string.h */
        else if (word == "copmem")
                out << "memcpy";
        else if (word == "muevamem")
                out << "memmove";
        else if (word == "coppal")
                out << "strcpy";
        else if (word == "copnpal")
                out << "strncpy";
        else if (word == "catpal")
                out << "strcat";
        else if (word == "catnpal")
                out << "strncat";
        else if (word == "compmem")
                out << "memcmp";
        else if (word == "comppal")
                out << "strcmp";
        else if (word == "collpal")
                out << "strcoll";
        else if (word == "compnpal")
                out << "strncmp";
        else if (word == "xfrmpal")
                out << "strxfrm";
        else if (word == "memcarác")
                out << "memchr";
        else if (word == "palcarác")
                out << "strchr";
        else if (word == "alcancpal")
                out << "strcspn";
        else if (word == "palcbusc")
                out << "strpbrk";
        else if (word == "pallcarác")
                out << "strrchr";
        else if (word == "alcanpal")
                out << "strspn";
        else if (word == "palpal")
                out << "strstr";
        else if (word == "palsím")
                out << "strtok";
        else if (word == "mempon")
                out << "memset";
        else if (word == "palerr")
                out << "strerr";
        else if (word == "paltamaño")
                out << "strlen";
        else if (word == "tamaño_t")
                out << "size_t";

        /* time.h */
        else if (word == "reloj")
                out << "clock";
        else if (word == "diftiempo")
                out << "difftime";
        else if (word == "haztiempo")
                out << "mktime";
        else if (word == "tiempo")
                out << "time";
        else if (word == "asctiempo")
                out << "asctime";
        else if (word == "ctiempo")
                out << "ctime";
        else if (word == "utctiempo")
                out << "gmtime";
        else if (word == "tiempolocal")
                out << "localtime";
        else if (word == "TIC_POR_SEGUNDO")
                out << "CLOCKS_PER_SEC";
        else if (word == "reloj_t")
                out << "clock_t";
        else if (word == "tiempo_t")
                out << "time_t";

        /* fstream */
        else if (word == "abrir")
                out << "open";
        else if (word == "abierto")
                out << "is_open";
        else if (word == "cerrar")
                out << "close";
        else if (word == "leecarga")
                out << "rdbuf";
        else if (word == "trocar")
                out << "swap";
        else if (word == "numcarác")
                out << "gcount";
        else if (word == "saca")
                out << "get";
        else if (word == "sacalínea")
                out << "getline";
        else if (word == "ignorar")
                out << "ignore";
        else if (word == "mira")
                out << "peek";
        else if (word == "leer")
                out << "read";
        else if (word == "leeralguna")
                out << "readsome";
        else if (word == "pon")
                out << "putback";
        else if (word == "dessaca")
                out << "unget";
        else if (word == "decirg")
                out << "tellg";
        else if (word == "buscarg")
                out << "seekg";
        else if (word == "sinc")
                out << "sync";
        else if (word == "escribir")
                out << "write";
        else if (word == "decirp")
                out << "tellp";
        else if (word == "buscarp")
                out << "seekp";
        else if (word == "descargar")
                out << "flush";
        else if (word == "bueno")
                out << "good";
        else if (word == "fda")
                out << "eof";
        else if (word == "fracaso")
                out << "fail";
        else if (word == "malo")
                out << "bad";
        else if (word == "leerestado")
                out << "rdstate";
        else if (word == "ponestado")
                out << "setstate";
        else if (word == "despejar")
                out << "clear";
        else if (word == "copfmt")
                out << "copyfmt";
        else if (word == "llenar")
                out << "fill";
        else if (word == "excepciónes")
                out << "exceptions";
        else if (word == "imbuir")
                out << "imbue";
        else if (word == "atar")
                out << "tie";
        else if (word == "reducir")
                out << "narrow";
        else if (word == "ampliar")
                out << "widen";
        else if (word == "señales")
                out << "flags";
        else if (word == "ponseñal")
                out << "setf";
        else if (word == "desponseñal")
                out << "unsetf";
        else if (word == "precisión")
                out << "precision";
        else if (word == "ancho")
                out << "width";
        else if (word == "sacaloc")
                out << "getloc";
        else if (word == "xasign")
                out << "xalloc";
        else if (word == "ipalab")
                out << "iword";
        else if (word == "ppalab")
                out << "pword";
        else if (word == "retrollamada")
                out << "register_callback";
        else if (word == "sinc_con_stdio")
                out << "sync_with_stdio";

        /* <iostream> */
        else if (word == "terml")
                out << "endl";
        else if (word == "cen")
                out << "cin";
        else if (word == "ca")
                out << "cout";
        else if (word == "creg")
                out << "clog";
        else if (word == "lcen")
                out << "wcin";
        else if (word == "lca")
                out << "wcout";
        else if (word == "lcerr")
                out << "wcerr";
        else if (word == "lcreg")
                out << "wclog";

        /* <string> */
        else if (word == "palabra_simple")
                out << "basic_string";
        else if (word == "carác_carác")
                out << "char_traits";
        else if (word == "palabra")
                out << "string";
        else if (word == "ns16string")
                out << "u16string";
        else if (word == "ns32string")
                out << "u32string";
        else if (word == "palabral")
                out << "wstring";
        else if (word == "pai")
                out << "stoi";
        else if (word == "pal")
                out << "stol";
        else if (word == "pansl")
                out << "stoul";
        else if (word == "pall")
                out << "stoll";
        else if (word == "pansll")
                out << "stoull";
        else if (word == "paf")
                out << "stof";
        else if (word == "pad")
                out << "stod";
        else if (word == "pald")
                out << "stold";
        else if (word == "a_palabra")
                out << "to_string";
        else if (word == "a_palabral")
                out << "to_wstring";
        else if (word == "empieza")
                out << "begin";
        else if (word == "fin")
                out << "end";

        /* containers */
        else if (word == "matríz")
                out << "array";
        else if (word == "dfila")
                out << "deque";
        else if (word == "lista_adelante")
                out << "forward_list";
        else if (word == "lista")
                out << "list";
        else if (word == "pila")
                out << "stack";
        else if (word == "fila")
                out << "queue";
        else if (word == "fila_priorizada")
                out << "priority_queue";
        else if (word == "colección")
                out << "set";
        else if (word == "multicolección")
                out << "set";
        else if (word == "mapa")
                out << "map";
        else if (word == "multimapa")
                out << "multimap";
        else if (word == "colección_desordenada")
                out << "unordered_set";
        else if (word == "multicolección_desordenada")
                out << "unordered_multiset";
        else if (word == "mapa_desordenada")
                out << "unordered_map";
        else if (word == "multimapa_desordenada")
                out << "unordered_multimap";
        else if (word == "empieza")
                out << "begin";
        else if (word == "antes_empieza")
                out << "before_begin";
        else if (word == "oempieza")
                out << "rbegin";
        else if (word == "ofin")
                out << "rend";
        else if (word == "cempieza")
                out << "cbegin";
        else if (word == "antes_cempieza")
                out << "cbefore_begin";
        else if (word == "cfin")
                out << "cend";
        else if (word == "crempieza")
                out << "crbegin";
        else if (word == "crfin")
                out << "crbegin";
        else if (word == "crempieza")
                out << "crbegin";
        else if (word == "crfin")
                out << "crend";
        else if (word == "tamaño")
                out << "size";
        else if (word == "tamaño_máx")
                out << "max_size";
        else if (word == "vaciar")
                out << "empty";
        else if (word == "remedir")
                out << "resize";
        else if (word == "reducir_a_tamaño")
                out << "shring_to_fit";
        else if (word == "capacidad")
                out << "capacity";
        else if (word == "reservar")
                out << "reserve";
        else if (word == "frente")
                out << "front";
        else if (word == "atrás")
                out << "back";
        else if (word == "operador")
                out << "operador";
        else if (word == "en")
                out << "at";
        else if (word == "asignar")
                out << "assign";
        else if (word == "emponer")
                out << "emplace";
        else if (word == "emponer_después")
                out << "emplace_after";
        else if (word == "emponer_pista")
                out << "emplace_hint";
        else if (word == "insertar")
                out << "insert";
        else if (word == "insertar_después")
                out << "insert_after";
        else if (word == "borrar")
                out << "erase";
        else if (word == "emponer_frente")
                out << "emplace_front";
        else if (word == "borrar_después")
                out << "erase_after";
        else if (word == "pulsar_atrás")
                out << "push_back";
        else if (word == "pop_atrás")
                out << "pop_back";
        else if (word == "emponer_frente")
                out << "emplace_front";
        else if (word == "pulsar_frente")
                out << "push_front";
        else if (word == "pop_frente")
                out << "pop_front";
        else if (word == "despejar")
                out << "clear";
        else if (word == "swap")
                out << "trocar";
        else if (word == "unir")
                out << "splice";
        else if (word == "quitar")
                out << "remove";
        else if (word == "quitar_si")
                out << "remove_if";
        else if (word == "único")
                out << "unique";
        else if (word == "fundir")
                out << "merge";
        else if (word == "ordenar")
                out << "sort";
        else if (word == "invertir")
                out << "reverse";
        else if (word == "saca_asignador")
                out << "get_allocator";
        else if (word == "contar")
                out << "count";
        else if (word == "encontrar")
                out << "find";
        else if (word == "gama_igual")
                out << "equal_range";
        else if (word == "límite_inferior")
                out << "lower_bound";
        else if (word == "límite_superior")
                out << "upper_bound";
        else if (word == "comp_clave")
                out << "key_comp";
        else if (word == "comp_valor")
                out << "value_comp";
        else if (word == "ig_clave")
                out << "key_eq";
        else if (word == "función_hash")
                out << "hash_function";
        else if (word == "balde")
                out << "bucket";
        else if (word == "num_balde")
                out << "bucket_count";
        else if (word == "balde_tamaño")
                out << "bucket_size";
        else if (word == "máx_num_balde")
                out << "max_bucket_count";
        else if (word == "carga_factor")
                out << "load_factor";
        else if (word == "máx_carga_factor")
                out << "max_load_factor";
        
        else
                out << word;
}

void Word::write()
{       
        while (in >> word) {
                check_front();
                split_word();
                print_word();
        }
}
