#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "word.h"

using namespace std;

string make_outfile(string type, string namefile);

int main(int argc, char* argv[])
{
        string outfile;
        Word word;
        string type = "";
        
        if (strncmp(argv[1], "cpp", 3) == 0) {
                word.set_dict("dict_cpp.txt");
                type = "cpp";
        }
        else if (strncmp(argv[1], "py", 3) == 0) {
                word.set_dict("dict_py.txt");
                type = "py";
        }
        else {
                cerr << "Usage: si [py,cpp] origin.si [destination]" << endl;
                exit(EXIT_FAILURE);
        }

        if (argc < 3) {
                cerr << "Usage: si [py,cpp] origin.si [destination]" << endl;
                exit(EXIT_FAILURE);
        }
        else if (argc == 3) {
                ifstream inputFile(argv[2]);
                if (!inputFile) {
                        cerr << "ERROR: Input file could not be read." << endl;
                        exit(EXIT_FAILURE);
                } else {
                        outfile = make_outfile(argv[1], argv[2]);
                        word.set_out(outfile);
                }
        }
        else if (argc > 2) {
                ifstream inputFile(argv[2]);
                if (!inputFile) {
                        cerr << "ERROR: Input file could not be read." << endl;
                        exit(EXIT_FAILURE);
                } else {
                        outfile = argv[3];
                        word.set_out(argv[3]);
                }

        }

        word.set_in(argv[2]);
        word.write();

        word.close_files();

        if (type == "py") {
                string out = "python3 " + outfile;
                system(out.c_str());
        }
}

/* if no destination file is provided, this will take the
 * first argument and turn its contents in to the name
 * of the destination file in .cpp format
 */
string make_outfile(string type, string namefile)
{
        string name = "";
        for (int i = 0; i < (int)namefile.length(); i++) {
                if (namefile[i] == '.') {
                        name = namefile.substr(0,i);
                        if (type == "py") {
                                name += ".py";
                        }
                        else if (type == "cpp") {
                                name += ".cpp";
                        }
                        break;
                }
        }
        if (name == "") {
                cerr << "No .si file found\n";
                exit(EXIT_FAILURE);
        }
        return name;
}
