//
// Created by Max on 2022-05-24.
//

#ifndef SUDOKU_DICTIONARY_H
#define SUDOKU_DICTIONARY_H
#include "iostream"
#include "fstream"
#include "set"
#include "Windows.h"
using namespace std;

class Dictionary {
public:
    set<string> words;
    Dictionary() {
        string word;
        ifstream wordBank ("words.txt");
        if (wordBank.is_open())
        {
            while ( getline (wordBank,word) )
            {
                words.insert(word);
            }
            wordBank.close();
        }

        else cout << "Unable to open file";
    }
    Dictionary(int wordLength) {

    }
    void printTest() {
        for (auto s: words) {
            cout << s << endl;
        }
    }
    string randomWord() {
        if (words.size() == 0) {
            cerr << "Dictionary::randomWord -> attempted to get random word with size 0" << endl;
            return "404";
        }
        int randInd = rand() % words.size();
        int curr = 0;
        for (auto s : words) {
            if (curr == randInd) {
                return s;
            }
            curr++;
        }
    }
};


#endif //SUDOKU_DICTIONARY_H
