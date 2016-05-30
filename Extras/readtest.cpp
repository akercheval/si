#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
        ofstream outfile;
        outfile.open("holamundo.cpp");
        
        string temp;
        string word;

        while (getline(cin, temp, '\n')) {
                while(temp.find("ca") != string::npos) {
                        temp.replace(temp.find("ca"), 2, "cout");
                }
                while(temp.find("incluir") != string::npos) {
                        temp.replace(temp.find("incluir"), 7, "include");
                }
                while(temp.find("usando") != string::npos) {
                        temp.replace(temp.find("usando"), 6, "using");
                }
                while(temp.find("nombres") != string::npos) {
                        temp.replace(temp.find("nombres"), 7, "namespace");
                }
                while(temp.find("terml") != string::npos) {
                        temp.replace(temp.find("terml"), 5, "endl");
                }
                outfile << temp;
                outfile << endl;
        }

        outfile.close();

        return 0;
}
