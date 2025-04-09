#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Game
{
    int randomNumber;
public:
    void guessEasy()
    {
        randomNumber = rand() % 5 + 1;
    }
    void guessMedium()
    {
        randomNumber = rand() % 10 + 6;
    }
    void guessHard()
    {
        randomNumber = rand() % 15 + 16;
    }
    bool checkGuess(int guess)
    {
        return guess == randomNumber;
    }
    void display()
    {
        cout << "The correct number was: " << randomNumber << endl;
    }
};

int main()
{
    srand(time(0));
    Game g1;
    int ch, x;

    cout << "Press 1 for easy level (1-5)\n"
         << "Press 2 for medium level (6-15)\n"
         << "Press 3 for hard level (16-30)" << endl;
    cin >> ch;

    if (ch == 1)
    {
        g1.guessEasy();
    }
    else if (ch == 2)
    {
        g1.guessMedium();
    }
    else if (ch == 3)
    {
        g1.guessHard();
    }
    else
    {
        cout << "Invalid Input! Enter a number (1-3) to select the difficulty level." << endl;
        return 0;
    }

    bool guessedCorrectly = false;
    for (int attempts = 1; attempts <= 3; attempts++)
    {
        cout << "Attempt " << attempts << "/3 - Enter your guess: ";
        cin >> x;

        if (g1.checkGuess(x))
        {
            cout << "Congratulations! You guessed the correct number!" << endl;
            guessedCorrectly = true;
            break;
        }
        else
        {
            cout << "Wrong guess! Try again." << endl;
        }
    }

    if (!guessedCorrectly)
    {
        cout << "You've used all 3 attempts! " << endl;
        g1.display();
    }

    return 0;
}
