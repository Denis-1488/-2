#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;





class Шибениця {



    vector<string> words = { "Apple", "House", "Water", "Table", "Cat", "RUST"
                             "Car", "Ukraine", "PC", "Playstation", "RTX", "ChatGBT",  "PV521"};
    string word, hidden;
    int lives = 10;

public:
    Шибениця() {
        srand(time(0));
        word = words[rand() % words.size()];
        hidden = string(word.size(), '_');
    }

    void play() {
        while (lives > 0 && hidden != word) {
            
            cout << "Слово: " << hidden << "   Жизни: " << lives << "\n";
            cout << "Буква: ";
            char c; cin >> c;

            bool ok = false;
            for (size_t i = 0; i < word.size(); i++)
                if (word[i] == c) hidden[i] = c, ok = true;

            if (!ok) lives--;
        }

        if (hidden == word) cout << "Красавчик выиграл. Слово: " << word << "\n";
        else cout << "Ты проиграл. Слово было: " << word << "\n";
    }
};

