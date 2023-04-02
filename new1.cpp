#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int MAX_WRONG = 8;

vector<string> words {"COMPUTER", "PROGRAMMING", "ALGORITHM", "NETWORK", "DATABASE"};

int main() {
    srand(time(NULL));
    
    string word = words[rand() % words.size()];
    int wrong = 0;
    string guessed(word.size(), '-');
    vector<char> guessed_letters;
    
    cout << "Welcome to Hangman!" << endl;
    cout << "I'm thinking of a word with " << word.length() << " letters." << endl;
    
    while (wrong < MAX_WRONG && guessed != word) {
        cout << endl << "You have " << MAX_WRONG - wrong << " incorrect guesses left." << endl;
        cout << "Guessed letters: ";
        for (char letter : guessed_letters) {
            cout << letter << " ";
        }
        cout << endl << "Guess the word: " << guessed << endl;
        char letter;
        cout << "Enter a letter: ";
        cin >> letter;
        
        if (find(guessed_letters.begin(), guessed_letters.end(), letter) != guessed_letters.end()) {
            cout << "You already guessed that letter. Try again." << endl;
        } else {
            guessed_letters.push_back(letter);
            bool correct_guess = false;
            for (int i = 0; i < word.length(); i++) {
                if (word[i] == letter) {
                    guessed[i] = letter;
                    correct_guess = true;
                }
            }
            if (correct_guess) {
                cout << "You guessed a letter correctly!" << endl;
            } else {
                cout << "Sorry, that letter is not in the word." << endl;
                wrong++;
            }
        }
    }
    
    if (wrong == MAX_WRONG) {
        cout << "You've been hanged!" << endl;
    } else {
        cout << "Congratulations! You guessed the word " << word << "!" << endl;
    }
    
    return 0;
}
