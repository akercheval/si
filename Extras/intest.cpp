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
