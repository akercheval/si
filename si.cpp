#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
        ofstream outfile;
        outfile.open("holamundo.cpp");
        
        string temp;
        string word;

        while (getline(cin, temp, '\n')) {
                /* include, using, namespace */
                while(temp.find("incluir") != string::npos) {
                        temp.replace(temp.find("incluir"), 7, "include");
                }
                while(temp.find("usando") != string::npos) {
                        temp.replace(temp.find("usando"), 6, "using");
                }
                while(temp.find("nombres") != string::npos) {
                        temp.replace(temp.find("nombres"), 7, "namespace");
                }
                
                /* general data types */
                while(temp.find("carác") != string::npos) {
                        temp.replace(temp.find("carác"), 7, "char");
                }
                while(temp.find("palab") != string::npos) {
                        temp.replace(temp.find("palab"), 5, "string");
                }
                while(temp.find("archivo") != string::npos) {
                        temp.replace(temp.find("archivo"), 7, "FILE");
                }
                while(temp.find("larg") != string::npos) {
                        temp.replace(temp.find("larg"), 4, "larg");
                }
                while(temp.find("flot") != string::npos) {
                        temp.replace(temp.find("flot"), 4, "float");
                }
                while(temp.find("doble") != string::npos) {
                        temp.replace(temp.find("doble"), 5, "double");
                }
                
                /*flow control */
                while(temp.find("si") != string::npos) {
                        temp.replace(temp.find("si"), 2, "if");
                }
                while(temp.find("si_no") != string::npos) {
                        temp.replace(temp.find("si_no"), 5, "else");
                }
                while(temp.find("para") != string::npos) {
                        temp.replace(temp.find("para"), 4, "for");
                }
                while(temp.find("mientras") != string::npos) {
                        temp.replace(temp.find("mientras"), 8, "while");
                }
                while(temp.find("haz") != string::npos) {
                        temp.replace(temp.find("haz"), 3, "do");
                }
                while(temp.find("romper") != string::npos) {
                        temp.replace(temp.find("romper"), 5, "break");
                }
                while(temp.find("continuar") != string::npos) {
                        temp.replace(temp.find("continuar"), 9, "continue");
                }
                while(temp.find("interr") != string::npos) {
                        temp.replace(temp.find("interr"), 6, "switch");
                }
                while(temp.find("caso") != string::npos) {
                        temp.replace(temp.find("caso"), 4, "case");
                }
                while(temp.find("larg") != string::npos) {
                        temp.replace(temp.find("larg"), 4, "larg");
                }

                /* assert.h */
                while(temp.find("afirma") != string::npos) {
                        temp.replace(temp.find("afirma"), 6, "assert");
                }

                /* ctype.h */
                while(temp.find("esalnum") != string::npos) {
                        temp.replace(temp.find("esalnum"), 7, "isalnum");
                }
                while(temp.find("esalfa") != string::npos) {
                        temp.replace(temp.find("esalfa"), 6, "isapha");
                }
                while(temp.find("esvacio") != string::npos) {
                        temp.replace(temp.find("esvacio"), 7, "isblank");
                }
                while(temp.find("escntrl") != string::npos) {
                        temp.replace(temp.find("escntrl"), 7, "iscntrl");
                }
                while(temp.find("esdec") != string::npos) {
                        temp.replace(temp.find("esdec"), 5, "isdec");
                }
                while(temp.find("esgraf") != string::npos) {
                        temp.replace(temp.find("esgraf"), 6, "isgraph");
                }
                while(temp.find("esminúsc") != string::npos) {
                        temp.replace(temp.find("esminúsc"), 9, "islower");
                }
                while(temp.find("esimprim") != string::npos) {
                        temp.replace(temp.find("isprint"), 7, "esimprim");
                }
                while(temp.find("espunt") != string::npos) {
                        temp.replace(temp.find("espunt"), 6, "ispunct");
                }
                while(temp.find("esespac") != string::npos) {
                        temp.replace(temp.find("esespac"), 7, "isspace");
                }
                while(temp.find("esmayúsc") != string::npos) {
                        temp.replace(temp.find("esmayúsc"), 9, "isupper");
                }
                while(temp.find("eshexa") != string::npos) {
                        temp.replace(temp.find("eshexa"), 6, "ishexdigit");
                }
                while(temp.find("aminúsc") != string::npos) {
                        temp.replace(temp.find("aminúsc"), 8, "tolower");
                }
                while(temp.find("amayúsc") != string::npos) {
                        temp.replace(temp.find("amayúsc"), 8, "toupper");
                }

                /* errno.h */
                while(temp.find("errnum") != string::npos) {
                        temp.replace(temp.find("errnum"), 6, "errno");
                }

                outfile << temp;
                outfile << endl;
        }

        outfile.close();

        return 0;
}

