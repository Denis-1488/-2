#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Šibenica {

    vector<string> words = { "Apple", "House", "Water", "Table", "Cat", "RUST",
                             "Car", "Ukraine", "PC", "Playstation", "RTX", "ChatGBT",  "PV521" };
    string word, hidden;

    int lives = 10;
    int incorrect = 0;

public:
    Šibenica() {
        word = words[rand() % words.size()];
        hidden = string(word.size(), '_');
    }

    // есть ли буква в слове
    bool check(char letter) {
        for (char c : word)
            if (c == letter)
                return true;
        return false;
    }

     //Обновление скрытого слова
    void updateWord(char letter) {
        for (size_t i = 0; i < word.size(); i++)
            if (word[i] == letter)
                hidden[i] = letter;
    }

    void play() {
        while (lives > 0 && hidden != word) {

            cout << "Слово: " << hidden << "   Жизни: " << lives << "\n";
            cout << "Буква: ";
            char letter;
            cin >> letter;

            bool letterFound = check(letter);

            if (letterFound) {
                cout << "Да эта буква '" << letter << "' есть в слове." << endl;
                updateWord(letter);
            }
            else {
                cout << " Жаль но буквы '" << letter << "' нету в этом слове." << endl;
                lives--;
                incorrect++;
            }
        }

        if (hidden == word)
            cout << "Красавчик выиграл Слово: " << word << "\n";
        else
            cout << "Ти проиграл Слово було: " << word << "\n";
    }
};
