#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    cout << "Welcome to the casino game!" << endl << "The rules are: " << endl <<
    "If your number matches the number produced by the casino board, you will win 2x your bet. " <<
    "If your number does not match the casino board number, you will lose your bet amount." << endl;
    cout << "What is your name?" << endl;
    string name = "Karan";
    cin >> name;
    cout << "Hello, " << name << "! Welcome to the casino game." << endl;
    cout << "How much money would you like to start with?" << endl;
    int deposit = 0;
    cout << "$";
    cin >> deposit;
    int chosen_num = 0;
    //int casino_num = 2;
    char cont_game = 'Y';
    int casino_num = rand() % 5 + 1;
    while(1)
    {
        if(deposit == 0)
        {
            cout << "Sorry, your balance is 0. This means you've lost the game. Bye!" << endl;
            exit(0);
        }
        cout << "How much would you like to bet?" << endl;
        int bet = 0;
        cout << "$";
        cin >> bet;
        if(((deposit - bet) >= 0) && (bet <= deposit) && (bet > 0))
        {
            cout << "Your bet of $" << bet << " has been placed." << endl;
            deposit = deposit - bet;
            cout << "Your remaining balance is $" << deposit << endl;
            casino_num = rand() % 5 + 1;
            while(1)
            {
                cout << "Please choose a number between 1 and 5." << endl;
                cin >> chosen_num;
                if((chosen_num >= 1) && (chosen_num <= 5))
                {
                    cout << "Your chosen number is " << chosen_num << endl;
                    cout << "The casino board number is " << casino_num << endl;
                    if(chosen_num == casino_num)
                    {
                        deposit = deposit + bet + bet;
                        cout << "You won! your new deposit is $" << deposit << ".";
                    }
                    else
                    {
                        cout << "You lost this round :(. Your remaining deposit is $" << deposit << "." << endl;
                    }
                    while(1)
                        {
                            cout << "Would you like to continue playing the game? (Y/N)" << endl;
                            cin >> cont_game;
                            if((cont_game == 'y') || (cont_game == 'Y'))
                            {
                                break;
                            }
                            else if((cont_game == 'n') || (cont_game == 'N'))
                            {
                                exit(0);
                            }
                            else
                            {
                                cout << "Invalid Choice. Please try again." << endl;
                            }
                            break;
                        }
                    break;
                }
                else
                {
                    cout << "Please try again." << endl;
                }
            }
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
