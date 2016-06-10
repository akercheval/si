#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
        ofstream outfile;
        outfile.open("holamundo.cpp");

        int i;
        string word, tempword;
        struct end_word {
                bool valid;
                vector<char> cvec;
        } end_word;
        struct multi_word {
                vector<string> wvec;
                vector<string> symvec;
        } multi_word;

        while (cin >> word) {
                end_word.valid = 0;
                if (!isalnum(word.front()) && (word.size() > 1)) {
                        outfile << word.front();
                        word.erase(0,1);
                }
                /* this needs work. see algorithm on lenovo. */

                for(i = 0; i < word.length(); i++) {
                        if(!isalnum(word[i]) && (!isspace(word[i]))
                           && word[i] != '_') {
                                tempword = word.substr(0,i);
                                word.erase(0,i);
                                multi_word.wvec.push_back(tempword);
                        }
                }

                if (!isalnum(word.back()) && (word.size() > 1)) {
                        end_word.valid = 1;
                        end_word.cvec.push_back(word.back());
                        word.pop_back();
                }

                /* etc */
                if (word == "incluir")
                        outfile << "include";
                else if (word == "usando")
                        outfile << "using";
                else if (word == "nombres")
                        outfile << "namespace";
                else if (word == "defina")
                        outfile << "define";
                else if (word == "sinodef")
                        outfile << "ifndef";
                else if (word == "termsi")
                        outfile << "endif";
                else if (word == "salir")
                        outfile << "exit";
                else if (word == "volver")
                        outfile << "return";
                
                /* general data types */
                else if (word == "carác")
                        outfile << "char";
                else if (word == "palab")
                        outfile << "string";
                else if (word == "archivo")
                        outfile << "file";
                else if (word == "ARCHIVO")
                        outfile << "FILE";
                else if (word == "larg")
                        outfile << "long";
                else if (word == "flot")
                        outfile << "float";
                else if (word == "doble")
                        outfile << "double";
                else if (word == "Class")
                        outfile << "Clase";
                else if (word == "struct")
                        outfile << "estruct";
               
                /* flow control */
                else if (word == "si")
                        outfile << "if";
                else if (word == "si_no")
                        outfile << "else";
                else if (word == "para")
                        outfile << "for";
                else if (word == "mientras")
                        outfile << "while";
                else if (word == "haz")
                        outfile << "do";
                else if (word == "romper")
                        outfile << "break";
                else if (word == "continuar")
                        outfile << "continue";
                else if (word == "interr")
                        outfile << "switch";
                else if (word == "caso")
                        outfile << "case";

                
                /* assert.h */
                else if (word == "afirma")
                        outfile << "assert";
                
                /* ctype.h */
                else if (word == "esalnum")
                        outfile << "isalpha";
                else if (word == "esalfa")
                        outfile << "isalpha";
                else if (word == "esvacio")
                        outfile << "isblank";
                else if (word == "escntrl")
                        outfile << "iscntrl";
                else if (word == "esdec")
                        outfile << "isdigit";
                else if (word == "esgraf")
                        outfile << "isgraph";
                else if (word == "esminúsc")
                        outfile << "islower";
                else if (word == "esimprim")
                        outfile << "isprint";
                else if (word == "espunt")
                        outfile << "ispunct";
                else if (word == "esespac")
                        outfile << "isspace";
                else if (word == "esmayúsc")
                        outfile << "isupper";
                else if (word == "eshexa")
                        outfile << "isxdigit";
                else if (word == "aminúsc")
                        outfile << "tolower";
                else if (word == "amayúsc")
                        outfile << "toupper";

                /* errno.h */
                else if (word == "errnum")
                        outfile << "errno";

                /* iso646.h */
                else if (word == "y")
                        outfile << "and";
                else if (word == "y_ig")
                        outfile << "and_eq";
                else if (word == "bit_y")
                        outfile << "bitand";
                else if (word == "bit_o")
                        outfile << "bitor";
                else if (word == "no")
                        outfile << "not";
                else if (word == "no_ig")
                        outfile << "not_eq";
                else if (word == "o")
                        outfile << "or";
                else if (word == "o_ig")
                        outfile << "or_eq";
                else if (word == "oex")
                        outfile << "xor";
                else if (word == "oex_ig")
                        outfile << "xor_eq";
                
                /* math.h */
                else if (word == "seno")
                        outfile << "sin";
                else if (word == "asen")
                        outfile << "asin";
                else if (word == "senh")
                        outfile << "sinh";
                else if (word == "asenh")
                        outfile << "asinh";
                else if (word == "log1m")
                        outfile << "log1p";
                else if (word == "pot")
                        outfile << "pow";
                else if (word == "rzcd")
                        outfile << "sqrt";
                else if (word == "rzcb")
                        outfile << "cbrt";
                else if (word == "hipot")
                        outfile << "hypot";
                else if (word == "tope")
                        outfile << "ceil";
                else if (word == "suelo")
                        outfile << "floor";
                else if (word == "redond")
                        outfile << "round";
                else if (word == "lredond")
                        outfile << "lround";
                else if (word == "llredond")
                        outfile << "llround";
                else if (word == "cercaint")
                        outfile << "nearbyint";
                else if (word == "resto")
                        outfile << "remainder";
                else if (word == "rescoc")
                        outfile << "remquo";
                else if (word == "copsigno")
                        outfile << "copysign";
                else if (word == "non")
                        outfile << "nan";
                else if (word == "siguiente")
                        outfile << "nextafter";
                else if (word == "sig_a")
                        outfile << "nexttoward";
                else if (word == "fdif")
                        outfile << "fdim";
                else if (word == "fms")
                        outfile << "fma";
                else if (word == "fpclas")
                        outfile << "fpclassify";
                else if (word == "esfinito")
                        outfile << "isfinite";
                else if (word == "esinfinito")
                        outfile << "isinf";
                else if (word == "esnon")
                        outfile << "isnan";
                else if (word == "esnormal")
                        outfile << "isnormal";
                else if (word == "signobit")
                        outfile << "signbit";
                else if (word == "esmÃ¡s")
                        outfile << "isgreater";
                else if (word == "ismásigual")
                        outfile << "isgreaterequal";
                else if (word == "esmenos")
                        outfile << "isless";
                else if (word == "esmenosigual")
                        outfile << "islessequal";
                else if (word == "esmásmenos")
                        outfile << "islessgreater";
                else if (word == "esnoordenado")
                        outfile << "isunordered";
                else if (word == "INFINITO")
                        outfile << "INFINITY";
                else if (word == "NON")
                        outfile << "NAN";
                else if (word == "GRANDE")
                        outfile << "HUGE_VAL";
                else if (word == "GRANDEF")
                        outfile << "HUGE_VALF";
                else if (word == "GRANDEL")
                        outfile << "HUGE_VALL";
                
                /* setjmp.h */
                else if (word == "brinclg")
                        outfile << "longjmp";
                else if (word == "ponbrinc")
                        outfile << "setjmp";

                /* signal.h */
                else if (word == "señal")
                        outfile << "signal";
                else if (word == "elevar")
                        outfile << "raise";

                /* stddef.h */
                else if (word == "ptodif_t")
                        outfile << "ptrdiff_t";
                else if (word == "tamaño_t")
                        outfile << "size_t";
                else if (word == "máx_nivel_t")
                        outfile << "max_align_t";
                else if (word == "nulopto_t")
                        outfile << "nullptr_t";
                else if (word == "compensadode")
                        outfile << "offsetof";
                else if (word == "NULO")
                        outfile << "NULL";

                /* stdio.h */
                else if (word == "quitar")
                        outfile << "remove";
                else if (word == "renombrar")
                        outfile << "rename";
                else if (word == "archivotmp")
                        outfile << "tmpfile";
                else if (word == "nombretmp")
                        outfile << "tmpnam";
                else if (word == "fcerrar")
                        outfile << "fclose";
                else if (word == "fdescarg")
                        outfile << "fflush";
                else if (word == "fabrir")
                        outfile << "fopen";
                else if (word == "freopen")
                        outfile << "freabrir";
                else if (word == "ponguarda")
                        outfile << "setbuf";
                else if (word == "ponvguarda")
                        outfile << "setvbuf";
                else if (word == "fimprimaf")
                        outfile << "fprintf";
                else if (word == "fescanf")
                        outfile << "fscanf";
                else if (word == "imprimaf")
                        outfile << "printf";
                else if (word == "escanf")
                        outfile << "scanf";
                else if (word == "snimprimaf")
                        outfile << "snprintf";
                else if (word == "simprimaf")
                        outfile << "sprintf";
                else if (word == "sescanf")
                        outfile << "sscanf";
                else if (word == "vfimprimaf")
                        outfile << "vfprintf";
                else if (word == "vfescanf")
                        outfile << "vfscanf";
                else if (word == "vimprimaf")
                        outfile << "vprintf";
                else if (word == "vescanf")
                        outfile << "vscanf";
                else if (word == "vsnimprimaf")
                        outfile << "vsnprintf";
                else if (word == "vsimprimaf")
                        outfile << "vsprintf";
                else if (word == "vsescanf")
                        outfile << "vsscanf";
                else if (word == "fsacac")
                        outfile << "fgetc";
                else if (word == "fsacas")
                        outfile << "fgets";
                else if (word == "fponc")
                        outfile << "fputc";
                else if (word == "fpons")
                        outfile << "fputs";
                else if (word == "sacac")
                        outfile << "getc";
                else if (word == "sacacarác")
                        outfile << "getchar";
                else if (word == "sacas")
                        outfile << "gets";
                else if (word == "ponc")
                        outfile << "putc";
                else if (word == "poncarác")
                        outfile << "putchar";
                else if (word == "pons")
                        outfile << "puts";
                else if (word == "dessacac")
                        outfile << "ungetc";
                else if (word == "fleer")
                        outfile << "fread";
                else if (word == "fescribir")
                        outfile << "fwrite";
                else if (word == "fsacapos")
                        outfile << "fgetpos";
                else if (word == "fbusc")
                        outfile << "fseek";
                else if (word == "fponpos")
                        outfile << "fsetpos";
                else if (word == "fdecir")
                        outfile << "ftell";
                else if (word == "rebob")
                        outfile << "rewind";
                else if (word == "quitaerr")
                        outfile << "clearerr";
                else if (word == "ffda")
                        outfile << "feof";
                else if (word == "ierror")
                        outfile << "perror";
                
                /* stdlib.h */
                else if (word == "paadob")
                        outfile << "atof";
                else if (word == "paaint")
                        outfile << "atoi";
                else if (word == "paall")
                        outfile << "atoll";
                else if (word == "paladob")
                        outfile << "strtod";
                else if (word == "palaflo")
                        outfile << "strtof";
                else if (word == "palal")
                        outfile << "strtol";
                else if (word == "palald")
                        outfile << "strtold";
                else if (word == "palall")
                        outfile << "strtoll";
                else if (word == "palansl")
                        outfile << "strtoul";
                else if (word == "palansll")
                        outfile << "strtoull";
                else if (word == "aleat")
                        outfile << "rand";
                else if (word == "saleat")
                        outfile << "srand";
                else if (word == "casign")
                        outfile << "calloc";
                else if (word == "lib")
                        outfile << "free";
                else if (word == "masign")
                        outfile << "malloc";
                else if (word == "reasign")
                        outfile << "realloc";
                else if (word == "ensalir")
                        outfile << "atexit";
                else if (word == "en_salir_rápido")
                        outfile << "at_quick_exit";
                else if (word == "sistema")
                        outfile << "system";
                else if (word == "_Salir")
                        outfile << "_Exit";
                else if (word == "bbusca")
                        outfile << "bsearch";
                else if (word == "rordena")
                        outfile << "qsort";
                else if (word == "mbtam")
                        outfile << "mblen";
                else if (word == "mbacl")
                        outfile << "mbtowc";
                else if (word == "clamb")
                        outfile << "wctomb";
                else if (word == "mbaclpal")
                        outfile << "mbtowcs";
                else if (word == "clpalampbal")
                        outfile << "wvstombs";
                else if (word == "SALIR_FRACASO")
                        outfile << "EXIT_FAILURE";
                else if (word == "SALIR_ÉXITO")
                        outfile << "EXIT_SUCCESS";
                else if (word == "MB_TAM_MÁX")
                        outfile << "MB_CUR_MAX";
                else if (word == "NULO")
                        outfile << "NULL";
                else if (word == "ALEATORIO_MÁX")
                        outfile << "RAND_MAX";

                /* string.h */
                else if (word == "copmem")
                        outfile << "memcpy";
                else if (word == "muevamem")
                        outfile << "memmove";
                else if (word == "coppal")
                        outfile << "strcpy";
                else if (word == "copnpal")
                        outfile << "strncpy";
                else if (word == "catpal")
                        outfile << "strcat";
                else if (word == "catnpal")
                        outfile << "strncat";
                else if (word == "compmem")
                        outfile << "memcmp";
                else if (word == "comppal")
                        outfile << "strcmp";
                else if (word == "collpal")
                        outfile << "strcoll";
                else if (word == "compnpal")
                        outfile << "strncmp";
                else if (word == "xfrmpal")
                        outfile << "strxfrm";
                else if (word == "memcarác")
                        outfile << "memchr";
                else if (word == "palcarác")
                        outfile << "strchr";
                else if (word == "alcancpal")
                        outfile << "strcspn";
                else if (word == "palcbusc")
                        outfile << "strpbrk";
                else if (word == "pallcarác")
                        outfile << "strrchr";
                else if (word == "alcanpal")
                        outfile << "strspn";
                else if (word == "palpal")
                        outfile << "strstr";
                else if (word == "palsím")
                        outfile << "strtok";
                else if (word == "mempon")
                        outfile << "memset";
                else if (word == "palerr")
                        outfile << "strerr";
                else if (word == "paltamaño")
                        outfile << "strlen";
                else if (word == "tamaño_t")
                        outfile << "size_t";

                /* time.h */
                else if (word == "reloj")
                        outfile << "clock";
                else if (word == "diftiempo")
                        outfile << "difftime";
                else if (word == "haztiempo")
                        outfile << "mktime";
                else if (word == "tiempo")
                        outfile << "time";
                else if (word == "asctiempo")
                        outfile << "asctime";
                else if (word == "ctiempo")
                        outfile << "ctime";
                else if (word == "utctiempo")
                        outfile << "gmtime";
                else if (word == "tiempolocal")
                        outfile << "localtime";
                else if (word == "TIC_POR_SEGUNDO")
                        outfile << "CLOCKS_PER_SEC";
                else if (word == "reloj_t")
                        outfile << "clock_t";
                else if (word == "tiempo_t")
                        outfile << "time_t";

                /* <iostream> */
                else if (word == "terml")
                        outfile << "endl";
                else if (word == "cen")
                        outfile << "cin";
                else if (word == "ca")
                        outfile << "cout";
                else if (word == "creg")
                        outfile << "clog";
                else if (word == "lcen")
                        outfile << "wcin";
                else if (word == "lca")
                        outfile << "wcout";
                else if (word == "lcerr")
                        outfile << "wcerr";
                else if (word == "lcreg")
                        outfile << "wclog";

                /* <string> */
                else if (word == "palabra_simple")
                        outfile << "basic_string";
                else if (word == "carác_carác")
                        outfile << "char_traits";
                else if (word == "palabra")
                        outfile << "string";
                else if (word == "ns16string")
                        outfile << "u16string";
                else if (word == "ns32string")
                        outfile << "u32string";
                else if (word == "palabral")
                        outfile << "wstring";
                else if (word == "pai")
                        outfile << "stoi";
                else if (word == "pal")
                        outfile << "stol";
                else if (word == "pansl")
                        outfile << "stoul";
                else if (word == "pall")
                        outfile << "stoll";
                else if (word == "pansll")
                        outfile << "stoull";
                else if (word == "paf")
                        outfile << "stof";
                else if (word == "pad")
                        outfile << "stod";
                else if (word == "pald")
                        outfile << "stold";
                else if (word == "a_palabra")
                        outfile << "to_string";
                else if (word == "a_palabral")
                        outfile << "to_wstring";
                else if (word == "empieza")
                        outfile << "begin";
                else if (word == "fin")
                        outfile << "end";

                /* containers */
                else if (word == "matríz")
                        outfile << "array";
                else if (word == "dfila")
                        outfile << "deque";
                else if (word == "lista_adelante")
                        outfile << "forward_list";
                else if (word == "lista")
                        outfile << "list";
                else if (word == "pila")
                        outfile << "stack";
                else if (word == "fila")
                        outfile << "queue";
                else if (word == "fila_priorizada")
                        outfile << "priority_queue";
                else if (word == "colección")
                        outfile << "set";
                else if (word == "multicolección")
                        outfile << "set";
                else if (word == "mapa")
                        outfile << "map";
                else if (word == "multimapa")
                        outfile << "multimap";
                else if (word == "colección_desordenada")
                        outfile << "unordered_set";
                else if (word == "multicolección_desordenada")
                        outfile << "unordered_multiset";
                else if (word == "mapa_desordenada")
                        outfile << "unordered_map";
                else if (word == "multimapa_desordenada")
                        outfile << "unordered_multimap";
                else if (word == "empieza")
                        outfile << "begin";
                else if (word == "antes_empieza")
                        outfile << "before_begin";
                else if (word == "oempieza")
                        outfile << "rbegin";
                else if (word == "ofin")
                        outfile << "rend";
                else if (word == "cempieza")
                        outfile << "cbegin";
                else if (word == "antes_cempieza")
                        outfile << "cbefore_begin";
                else if (word == "cfin")
                        outfile << "cend";
                else if (word == "crempieza")
                        outfile << "crbegin";
                else if (word == "crfin")
                        outfile << "crbegin";
                else if (word == "crempieza")
                        outfile << "crbegin";
                else if (word == "crfin")
                        outfile << "crend";
                else if (word == "tamaño")
                        outfile << "size";
                else if (word == "tamaño_máx")
                        outfile << "max_size";
                else if (word == "vaciar")
                        outfile << "empty";
                else if (word == "remedir")
                        outfile << "resize";
                else if (word == "reducir_a_tamaño")
                        outfile << "shring_to_fit";
                else if (word == "capacidad")
                        outfile << "capacity";
                else if (word == "reservar")
                        outfile << "reserve";
                else if (word == "frente")
                        outfile << "front";
                else if (word == "atrás")
                        outfile << "back";
                else if (word == "operador")     // in my notes as operator[]
                        outfile << "operador";   // but idk if i want []
                else if (word == "en")
                        outfile << "at";
                else if (word == "asignar")
                        outfile << "assign";
                else if (word == "emponer")
                        outfile << "emplace";
                else if (word == "emponer_después")
                        outfile << "emplace_after";
                else if (word == "emponer_pista")
                        outfile << "emplace_hint";
                else if (word == "insertar")
                        outfile << "insert";
                else if (word == "insertar_después")
                        outfile << "insert_after";
                else if (word == "borrar")
                        outfile << "erase";
                else if (word == "emponer_frente")
                        outfile << "emplace_front";
                else if (word == "borrar_después")
                        outfile << "erase_after";
                else if (word == "pulsar_atrás")
                        outfile << "push_back";
                else if (word == "pop_atrás")
                        outfile << "pop_back";
                else if (word == "emponer_frente")
                        outfile << "emplace_front";
                else if (word == "pulsar_frente")
                        outfile << "push_front";
                else if (word == "pop_frente")
                        outfile << "pop_front";
                else if (word == "despejar")
                        outfile << "clear";
                else if (word == "swap")
                        outfile << "trocar";
                else if (word == "unir")
                        outfile << "splice";
                else if (word == "quitar")
                        outfile << "remove";
                else if (word == "quitar_si")
                        outfile << "remove_if";
                else if (word == "único")
                        outfile << "unique";
                else if (word == "fundir")
                        outfile << "merge";
                else if (word == "ordenar")
                        outfile << "sort";
                else if (word == "invertir")
                        outfile << "reverse";
                else if (word == "saca_asignador")
                        outfile << "get_allocator";
                else if (word == "contar")
                        outfile << "count";
                else if (word == "encontrar")
                        outfile << "find";
                else if (word == "gama_igual")
                        outfile << "equal_range";
                else if (word == "límite_inferior")
                        outfile << "lower_bound";
                else if (word == "límite_superior")
                        outfile << "upper_bound";
                else if (word == "comp_clave")
                        outfile << "key_comp";
                else if (word == "comp_valor")
                        outfile << "value_comp";
                else if (word == "ig_clave")
                        outfile << "key_eq";
                else if (word == "función_hash")
                        outfile << "hash_function";
                else if (word == "balde")
                        outfile << "bucket";
                else if (word == "num_balde")
                        outfile << "bucket_count";
                else if (word == "balde_tamaño")
                        outfile << "bucket_size";
                else if (word == "máx_num_balde")
                        outfile << "max_bucket_count";
                else if (word == "carga_factor")
                        outfile << "load_factor";
                else if (word == "máx_carga_factor")
                        outfile << "max_load_factor";

                
                else
                        outfile << word;
                
                if (end_word.valid) {
                        end_word.valid = 0;
                        outfile << end_word.cvec.back();
                        end_word.cvec.pop_back();
                }
                
                while(isspace(cin.peek())){
                        while(cin.peek() == ' '){
                                outfile << ' ';
                                cin.get();
                        }
                        while(cin.peek() == '\t'){
                                outfile << "\t";
                                cin.get();
                        }
                        while(cin.peek() == '\n'){
                                outfile << endl;
                                cin.get();
                        }
                }
        }
        outfile.close();
        return 0;
}
