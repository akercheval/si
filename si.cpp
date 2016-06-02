#include <iostream>
#include <fstream>

using namespace std;

int main()
{
        ofstream outfile;
        outfile.open("holamundo.cpp");

        string word;
        struct end_word {
                bool valid;
                char c;
        } end_word;

        while (cin >> word) {
                end_word.valid = 0;
                if (!isalnum(word.front()) && (word.size() > 1)) {
                        outfile << word.front();
                        word.erase(0,1);
                }
                if (!isalnum(word.back()) && (word.size() > 1)) {
                        end_word.valid = 1;
                        end_word.c = word.back();
                        word.pop_back();
                }

                /* general data types */
                if (word == "carác")
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
                else if (word == "esmás")
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
                

                /* etc */
                if (word == "incluir")
                        outfile << "include";
                else if (word == "usando")
                        outfile << "using";
                else if (word == "nombres")
                        outfile << "namespace";
                else if (word == "ca")
                        outfile << "cout";
                else if (word == "terml")
                        outfile << "endl";
                
                else
                        outfile << word;
                
                if (end_word.valid) {
                        end_word.valid = 0;
                        outfile << end_word.c;
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
