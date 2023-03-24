
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "TTT.h"
#include "Connect_4.h"
#include "Blackjack.h"
using namespace std;
const char X = 'X';
const char O = 'O';
void MainMenu();
int main()
{
    bool fin = false;
    int c4choice;
    char choice;
    char color = 'n';
    char color2 = 'n';
    char score[9]{ '1','2','3','4','5','6','7','8','9' };
    char Continue = 'y';


    do{
    MainMenu();
    do {

        cin >> choice;
        if (choice != '1' && choice != '2' && choice != '3'&& choice != '4') {
            cout << "Invalid game";

        }

    } while (choice != '1' && choice != '2' && choice != '3');

    do {
        if (choice == '1') {
            system("CLS");
            TTT first;
            first.TTTmenu();
            first.TicTacToe(score);
            cout << "press y to play again";
            cin >> Continue;
            system("CLS");
            if (Continue != 'y' && Continue != 'Y')
                choice = 0;
        }
        else if (choice == '2') {
            system("CLS");
            Connect_4 play;
            play.makeMenu();
            cin >> c4choice;
            if (c4choice == 1) {
                cout << "\nPick R for red or Y for yellow\n";
                do {
                    cin >> color;
                    if (color == 'r' || color == 'R')
                        color = 'R';
                    else if (color == 'y' || color == 'Y')
                        color = 'Y';
                    else {
                        cout << "color invalid\n";
                    }
                } while (color != 'R' && color != 'Y');
                system("CLS");
                Connect_4_Player players2(color);
                while (fin == false) {

                    players2.print();
                    players2.turn();
                    system("CLS");
                    fin = players2.horizontalwin();
                    if (fin == false)
                        fin = players2.verticalwin();
                    if (fin == false)
                        fin = players2.diagnolwin();
                }

                cout << "press y to play again";
                cin >> Continue;
                system("CLS");
                fin = false;
                if (Continue != 'y' && Continue != 'Y')
                    choice = '0';
            }
            else if (c4choice == 2) {
                cout << "\nPick R for red or Y for yellow\n";
                do {
                    cin >> color;
                    if (color == 'r' || color == 'R')
                        color = 'R';
                    else if (color == 'y' || color == 'Y')
                        color = 'Y';
                    else {
                        cout << "color invalid\n";
                    }
                } while (color != 'R' && color != 'Y');
                system("CLS");
                Connect_4_Player Play(color);
                while (fin == false) {

                    Play.print();
                    Play.turn();
                    system("CLS");
                    fin = Play.horizontalwin();
                    if (fin == false)
                        fin = Play.verticalwin();
                    if (fin == false)
                        fin = Play.diagnolwin();
                    Play.aiturnE();
                    fin = Play.horizontalwin();
                    if (fin == false)
                        fin = Play.verticalwin();
                    if (fin == false)
                        fin = Play.diagnolwin();
                   
                }
                cout << "press y to play again";
                cin >> Continue;
                system("CLS");
                fin = false;
                if (Continue != 'y' && Continue != 'Y')
                    choice = '0';
            }
        }   
        else if (choice == '3') {
            Blackjack player;
            Blackjack house;

            player.menu();
            system("pause");
            while (player.playing == true) {
                player.start();
                house.Thehouse();
                house.HitorFold = player.HitorFold;
            }
            cout << "Lets Compare scores \nThe house got:" << house.value << "\nYou got: " << player.value;
            if (player.value > 21) {
                cout << "\nyou Lose\n";
            }
            else if (player.value == 21) {
                cout << "\nyou win\n";
            }
            if (house.value > 21 && player.value <= 21) {
                cout << "\nyou win\n";
            }

            else if (house.value <= 21 && house.value > player.value) {
                cout << "\nyou Lose\n";
            }
            else if (house.value <= 21 && player.value <= 21 && house.value < player.value) {
                cout << "\nyou win\n";
            }
            cout << "press y to play again";
            cin >> Continue;
            system("CLS");
            if (Continue != 'y' && Continue != 'Y')
                choice = 0;
        }
        
        else if (choice == '4') {
            Continue = 'z';
        }
    } while (Continue == 'y' || Continue == 'Y');
    
}while (choice != '4');
}
    
void MainMenu() {
    cout <<"-------------------------------\n"
         <<"|          Pick a Game        |\n"
         <<"-------------------------------\n"
         <<"1.Tic tac toe       2.Connect 4\n"
         <<"3. blackjack        4.quit\n";
            
}