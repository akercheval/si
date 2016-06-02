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
        size_t pos;

        while (getline(cin, temp, '\n')) {
                while((pos = temp.find("ca")) && (pos != string::npos)){ 
                        if(!isalnum(temp[pos - 1]) && !isalnum(temp[pos + 2]))
                        temp.replace(pos, 2, "cout");
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
