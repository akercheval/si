#include <iostream>
#include <cstring>
#include "word.h"

using namespace std;

string make_outfile(string namefile);

int main(int argc, char* argv[])
{
        Word word;
        
        if (strncmp(argv[1], "cpp", 3) == 0) {
                word.set_type("cpp");
                word.set_dict("is");
        }
        else if (strncmp(argv[1], "py", 3) == 0) {
                word.set_type("py");
                word.set_dict("is");
        }
        else if (strncmp(argv[1], "c", 3) == 0) {
                word.set_type("c");
                word.set_dict("is");
        }
        else {
                cerr << "Usage: is [py,cpp] origin.cpp [destination.si]" << endl;
                exit(EXIT_FAILURE);
        }

        if (argc < 3) {
                cerr << "Usage: is [py,cpp] origin.cpp [destination.si]" << endl;
                exit(EXIT_FAILURE);
        }
        else if (argc == 3) {
                ifstream inputFile(argv[2]);
                if (!inputFile) {
                        cerr << "ERROR: Input file could not be read." << endl;
                        exit(EXIT_FAILURE);
                } else {
                        string outfile = make_outfile(argv[2]);
                        word.set_out(outfile);
                }
        }
        else if (argc > 3) {
                ifstream inputFile(argv[2]);
                if (!inputFile) {
                        cerr << "ERROR: Input file could not be read." << endl;
                        exit(EXIT_FAILURE);
                } else {
                        word.set_out(argv[3]);
                }

        }

        word.set_in(argv[2]);
        word.write();

        word.close_files();
}

/* if no destination file is provided, this will take the
 * first argument and turn its contents in to the name
 * of the destination file in .cpp format
 */
string make_outfile(string namefile)
{
        string name = "";
        for (int i = 0; i < (int)namefile.length(); i++) {
                if (namefile[i] == '.') {
                        name = namefile.substr(0,i);
                        name += ".si";
                        break;
                }
        }
        if (name == "") {
                cerr << "No file found to read from\n";
                exit(EXIT_FAILURE);
        }
        return name;
}
