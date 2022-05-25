//
// Created by Max on 2022-05-22.
//

#ifndef SUDOKU_SPELLINGBEE_H
#define SUDOKU_SPELLINGBEE_H


#include "Dictionary.h"
#include "vector"
#include "algorithm"

class SpellingBee {
    Dictionary Dictionary;
    vector<char> activeChars;
    set<char> charset;
    char mandatoryChar;
    bool playing = false;
public:
    void setup() {
        playing = true;
        srand ( time(NULL) );
        string vowels = "aeiou";
        string consonants = "bdfghjklmnpqrstvwxyz";

        for (int i = 0; i < 7; i++) {
            if (i < 2) {
                int randInd = rand() % vowels.length();
                while (charset.find(vowels[randInd]) != charset.end()) {
                    randInd++;
                    if (randInd == vowels.length()) {
                        randInd = 0;
                    }
                }
                charset.insert(vowels[randInd]);
            } else {
                int randInd = rand() % consonants.length();
                while (charset.find(consonants[randInd]) != charset.end()) {
                    randInd++;
                    if (randInd == consonants.length()) {
                        randInd = 0;
                    }
                }
                charset.insert(consonants[randInd]);
            }
        }
        activeChars = vector<char>(charset.begin(), charset.end());
        std::random_shuffle(activeChars.begin(), activeChars.end());
    }

    void StartGame() {
        setup();
        string guess = "";
        bool validGuess = false;
        while (playing) {
            validGuess = false;
            cout << "SPELLING BEE: " << activeChars[0] << " | ";
            for (int i = 1; i < activeChars.size(); i++) {
                cout << activeChars.at(i);
                if (i < activeChars.size() - 1) {
                    cout << ",";
                }
            }
            cin >> guess;
            if (guess == "EXIT") {
                return;
            }
            for (auto c : guess) {
                if (c == activeChars[0]) {
                    validGuess = true;
                }
                if (charset.find(c) == charset.end()) {
                    validGuess = false;
                    cout << "Invalid guess: Guess contains letter outside of letter set." << endl;
                    break;
                }
            }
            if (validGuess) {
                cout << "Great guess!" << endl;
            } else {
                cout << "Invalid guess: Guess does not contain the letter " << activeChars[0] << endl;
            }
        }

    }

};


#endif //SUDOKU_SPELLINGBEE_H
