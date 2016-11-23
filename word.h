#ifndef WORD_H
#define WORD_H

#include <vector>
#include <fstream>
#include <unordered_map>

using namespace std;

class Word {
        public:
                void set_type(string filetype);
                string get_type();
                void set_dict(string direction);
                void set_in(string new_in);
                void set_out(string new_out);
                void write();
                void close_files();
                Word();

        private:
                string word;
                string filetype;
                bool py_ignore = false;
                bool ignore = false;
                bool long_ignore = false;
                bool q_ignore = false;
                vector<string> wvec;
                vector<string> symvec;
                unordered_map<string, string> dictionary;
                ifstream in;
                ofstream out;

                void check_front();
                void split_word();
                void print_word();
                string translate_word(string word);
        };

#endif
