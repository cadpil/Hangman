#include <iostream>
#include <ctime>
#include <limits>
#include <algorithm>
#include <vector>

std::string words[] = {"banana", "keyboard"};

int main() {

    bool playing = true;
    int maxIncorrectGuesses;
    int gueses;
    int won;

    char guessedLetter;
    std::string selectedWord;
    std::string guessedWord;
    std::vector<char> guessedLetters;

    int wordsSize = sizeof(words)/sizeof(std::string);

    while (playing){
        srand(time(0));
        system("cls");

        selectedWord = words[rand() % 2];
        guessedWord = "";

        for (int i = 0; i < selectedWord.length(); i++) {
            guessedWord.append("_");
        }

        std::cout << "**** Hangman ****\n\n";

        std::cout << "How many lives do you want? ";
        while (!(std::cin >> maxIncorrectGuesses)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "How many lives do you want? ";
        };
        system("cls");

        for (int i = 0; i < maxIncorrectGuesses; i++) {

            won = guessedWord == selectedWord;
            if (won == 1) {
                break;
            }

            std::cout << "Incorrect guesses: ";
            for (char letter : guessedLetters) {
                std::cout << letter << ", ";
            }
            std::cout << '\n';

            std::cout << "\nYou have " << maxIncorrectGuesses - i << " lives left\n";
            std::cout << "Current word: " << guessedWord << "\n\n";
            
            std::cout << "Guess a letter: ";
            std::cin >> guessedLetter;

            system("cls");
            if (selectedWord.find(guessedLetter) < selectedWord.length()) {

                for (int j = 0; j < selectedWord.length(); j++) {
                    if (selectedWord[j] == guessedLetter) {
                        guessedWord[j] = guessedLetter;
                    }
                }

                i--;
            } else {
                // Check if guessed letter is already in the guessedLetters vector
                if (!(std::find(guessedLetters.begin(), guessedLetters.end(), guessedLetter) != guessedLetters.end())){
                    guessedLetters.push_back(guessedLetter);
                }
            }

        }

        system("cls");
        
        if (won == 1) {
            std::cout << "You won!\n\n";
        } else {
            std::cout << "You lost :(\n\n";
        }
        std::cout << "The correct word was: " << selectedWord << "\n\n";

        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> guessedLetter;

        if (guessedLetter == 'n') {
            playing = false;
        } else {
            guessedLetters.clear();
            guessedLetter = '0';
            won = 0;
        }
    }

    return 0;
}