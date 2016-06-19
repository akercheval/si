#ifndef WORD_H
#define WORD_H

#include <vector>
#include <fstream>

using namespace std;

class Word {
        public:
                void set_word(string new_word);
                void set_in(string new_in);
                void set_out(string new_out);
                void write();
                void close_files();

        private:
                string word;
                bool ignore;
                bool long_ignore;
                bool q_ignore;
                vector<string> wvec;
                vector<string> symvec;
                ifstream in;
                ofstream out;

                void check_front();
                void split_word();
                void print_word();
                void translate_word();
        };

#endif
