#include <iostream>

using namespace std;

const int TABLE_SIZE = 10000;

unsigned long hash(string str)
{
        unsigned long hash = 5381;
        int c;
        int i = 0;

        while ((c = str[i++]))
                hash = hash * 33 + c;

        return hash;
}

int main(int argc, char* argv[])
{
        string str;
        unsigned long table[TABLE_SIZE] = {0};
        unsigned long hashval;
        int counter = 0, cols = 0;

        /*if (argc != 2) {
                cout << "Please enter a word to be hashed" << endl;
                cin >> str;
        }
        else 
                str = argv[1];
                */
        while(cin >> str) {
                counter++;
                hashval = hash(str) % TABLE_SIZE;
                
                if(table[hashval] == 0)
                        table[hashval] = 1;
                else 
                        cols++;
        }

        cout << "Words hashed: " << counter << endl;
        cout << "Collisions: " << cols << endl;
        return 0;
}
