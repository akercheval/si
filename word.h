#ifndef WORD_H
#define WORD_H

#include <vector>
#include <fstream>

using namespace std;

class Word {
        public:
                void set_word(string new_word);
                void set_out(ostream *new_out);
                void write();

        private:
                string word;
                bool ignore;
                bool long_ignore;
                bool q_ignore;
                vector<string> wvec;
                vector<string> symvec;
                ostream out;

                //void translate();
                void check_front();
                void split_word();
                void print_word();
                void translate_word();
        };

#endif
