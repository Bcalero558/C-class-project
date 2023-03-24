#include "TTT.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
 

bool TTT::win(char board[9]) {

    if ((board[0] == board[4] && board[0] == board[8]) || (board[2] == board[4] && board[2] == board[6])) {
        MBoard(board);
        cout << "Diagnal win";
        if (((board[0] == 'X') && (board[4] == 'X') && (board[8] == 'X')) || ((board[2] == 'X') && (board[4] == 'X') && (board[6] == 'X')))
            cout << "\nCongrats X\n";
        if (((board[0] == 'O') && (board[4] == 'O') && (board[8] == 'O')) || ((board[6] == 'O') && (board[4] == 'O') && (board[2] == 'O')))
            cout << "\n Congrats 0\n";
        return true;
    }
    else if (((board[0] == board[1] && board[0] == board[2])) || ((board[8] == board[7] && board[8] == board[6])) || ((board[3] == board[4] && board[3] == board[5]))) {
        MBoard(board);
        cout << "Horizontal win";
        if (((board[0] == 'X') && (board[1] == 'X') && (board[2] == 'X')) || ((board[8] == 'X') && (board[7] == 'X') && (board[6] == 'X')) || ((board[3] == 'X') && (board[4] == 'X') && (board[5] == 'X')))
            cout << "\nCongrats X\n";
        if (((board[0] == 'O') && (board[1] == 'O') && (board[2] == 'O')) || ((board[8] == 'O') && (board[7] == 'O') && (board[6] == 'O')) || ((board[3] == 'O') && (board[4] == 'O') && (board[5] == 'O')))
            cout << "\nCongrats 0\n";
        return true;
    }
    else if (((board[0] == board[3] && board[0] == board[6])) || ((board[8] == board[5] && board[8] == board[2])) || ((board[1] == board[4] && board[1] == board[7]))) {
        MBoard(board);
        cout << "Vertical win";
        if ((board[0] == 'X') && (board[3] == 'X') && (board[6] == 'X') || (board[8] == 'X') && (board[5] == 'X') && (board[2] == 'X') || (board[1] == 'X') && (board[4] == 'X') && (board[7] == 'X'))
            cout << "\nCongrats X\n";
        if (((board[0] == 'O') && (board[3] == 'O') && (board[6] == 'O')) || ((board[8] == 'O') && (board[5] == 'O') && (board[2] == 'O')) || ((board[1] == 'O') && (board[4] == 'O') && (board[7] == 'O')))
            cout << "\nCongrats 0\n";
        return true;
    }
    else if (board[0]!='1'&& board[1] != '2'&& board[2] != '3' && board[3] != '4' && board[4] != '5' && board[5] != '6' && board[6] != '7' && board[7] != '8' && board[8] != '9') {
        cout << "Draw\n";
        return true;
    }
    else return false;
}

void TTT::TicTacToe(char board[9]) {
    for (int i = 0; i < 9; i++) {

        board[i] = base_board[i];
    }
    
    char vscomp;
    char EasyorImpossible;
    cout << "do you want to play against a computer or with a friend\n\npress C to face the program or press any button to face a person with you";
    cin >> vscomp;
    if (vscomp == 'C'|| vscomp == 'c') {
        cout << "If you want a challenge press c";
        cin >> EasyorImpossible;
        if (EasyorImpossible == 'c' || EasyorImpossible == 'C')
            ImpossibleAI(board);
        else
        Cpu(board);

    }
    else {
        PVP(board);
}
}

void TTT::playerletter() {
    cout << "X or O : ";
    do {

        cin >> choice;
        if (choice == 'x' || choice == 'X') {
            cout << "X goes first";
            choice = 'X';
        }
        else if (choice == 'o' || choice == 'O') {
            cout << "O goes first";
            choice = 'O';
        }
        else
        {
            cout << "error please chose again";
        }
    } while (choice != 'X' && choice != 'O');
    system("CLS");
}

void TTT::PVP(char board[9]) {
    cout << "player 1 first\n";
    playerletter();
    
    do {
        MBoard(board);
        cout << choice << " Turn please pick a number";
        cin >> selection;
        switch (selection) {
        case '1':
            if (board[0] != 'X' && board[0] != 'O') {
                switch (choice) {
                case 'X':
                    board[0] = 'X';
                    choice = 'O';
                    break;
                case 'O':
                    board[0] = 'O';
                    choice = 'X';
                    break;
                }
            }
            else
                cout << "\nInvalid This spot is taken\n";
            break;

        case '2':
            if (board[1] != 'X' && board[1] != 'O') {
                switch (choice) {
                case 'X':
                    board[1] = 'X';
                    choice = 'O';
                    break;
                case 'O':
                    board[1] = 'O';
                    choice = 'X';
                    break;
                }
            }
            else
                cout << "\nInvalid This spot is taken\n";
            break;

        case '3':
            if (board[2] != 'X' && board[2] != 'O') {
                switch (choice) {
                case 'X':
                    board[2] = 'X';
                    choice = 'O';
                    break;
                case 'O':
                    board[2] = 'O';
                    choice = 'X';
                    break;
                }
            }
            else
                cout << "\nInvalid This spot is taken\n";
            break;
        case '4':
            if (board[3] != 'X' && board[3] != 'O') {
                switch (choice) {
                case 'X':
                    board[3] = 'X';
                    choice = 'O';
                    break;
                case 'O':
                    board[3] = 'O';
                    choice = 'X';
                    break;
                }
            }
            else
                cout << "\nInvalid This spot is taken\n";
            break;

        case '5':
            if (board[4] != 'X' && board[4] != 'O') {
                switch (choice) {
                case 'X':
                    board[4] = 'X';
                    choice = 'O';
                    break;
                case 'O':
                    board[4] = 'O';
                    choice = 'X';
                    break;
                }
            }
            else
                cout << "\nInvalid This spot is taken\n";
            break;

        case '6':
            if (board[5] != 'X' && board[5] != 'O') {
                switch (choice) {
                case 'X':
                    board[5] = 'X';
                    choice = 'O';
                    break;
                case 'O':
                    board[5] = 'O';
                    choice = 'X';
                    break;
                }
            }
            else
                cout << "\nInvalid This spot is taken\n";
            break;

        case '7':
            if (board[6] != 'X' && board[6] != 'O') {
                switch (choice) {
                case 'X':
                    board[6] = 'X';
                    choice = 'O';
                    break;
                case 'O':
                    board[6] = 'O';
                    choice = 'X';
                    break;
                }
            }
            else
                cout << "\nInvalid This spot is taken\n";
            break;
        case '8':
            if (board[7] != 'X' && board[7] != 'O') {
                switch (choice) {
                case 'X':
                    board[7] = 'X';
                    choice = 'O';
                    break;
                case 'O':
                    board[7] = 'O';
                    choice = 'X';
                    break;
                }
            }
            else
                cout << "\nInvalid This spot is taken\n";
            break;
        case '9':
            if (board[8] != 'X' && board[8] != 'O') {
                switch (choice) {
                case 'X':
                    board[8] = 'X';
                    choice = 'O';
                    break;
                case 'O':
                    board[8] = 'O';
                    choice = 'X';
                    break;
                }
            }
            else
                cout << "\nInvalid This spot is taken\n";
            break;
        default:
            cout << "invalid\n";

        }
        system("CLS");
    } while (win(board) == false);

}

void TTT::MBoard(char board[9]) {
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 3; j++) {
            cout << board[i + j] << " | ";
        }
        cout << endl;
    }
}

void TTT::TTTmenu() {
   cout << "---------------------------------------" << endl
        << "|               Welcome               |" << endl
        << "|                  To                 |" << endl
        << "|             Tic Tac Toe             |" << endl
        << "---------------------------------------" << endl;
}

bool TTT::islegal(char board[9],int turn){
    if (board[turn] != 'O' && board[turn] != 'X')
        return true;
    else
        return false;
}

void TTT::Cpu(char board[9]){
    bool fin=false;
   

    int turn = (rand() % 9);
    srand(time(NULL));
    playerletter();
    do {
        if (fin == false) {
            playerTurn(board);
            fin = win(board);
        }
            do {
                turn = (rand() % 9);

            } while (islegal(board, turn) == false);
        
        if (fin == false) {
            if (choice == 'O')
                board[turn] = 'X';
            else if (choice == 'X')
                board[turn] = 'O';
            fin = win(board);
        }
    } while (fin == false);
}

void TTT::playerTurn(char board[9]) {
    bool legal = false;
    int Pturn;
    
    do {
        MBoard(board);
        cout << choice << " Turn please pick a number";
        cin >> Pturn;
        Pturn--;
        if (board[Pturn] != 'X' && board[Pturn] != 'O') {
            board[Pturn] = choice;
            legal = true;
        }
        else {
            cout << "Invalid Turn\n";
            legal = false;
        }
    } while (legal == false);
}

void TTT::ImpossibleAI(char board[9]) {
 
    char aiChoice='?';
    bool fin;
    cout << "CPU goes first try your best\n";
    playerletter();
    cout << "Welcome to The Crucible\n";
    if (choice == 'X')
        aiChoice = 'O';
    else if (choice == 'O')
        aiChoice = 'X';
    //ai starts hard to lose
    
    board[8] = aiChoice;
  //players turn
    playerTurn(board);
    // ai turn 2 all possible choices
    if (board[0] == choice)
        board[6] = aiChoice;

    else if (board[1] == choice)
        board[2] = aiChoice;

    else if (board[2] == choice)
        board[6] = aiChoice;

    else if (board[3] == choice)
        board[6] = aiChoice;

    else if (board[4] == choice)
    board[0] = aiChoice;
    
    else if (board[5] == choice) 
        board[6] = aiChoice;

    else if (board[6] == choice)
         board[2] = aiChoice;

    else if (board[7] == choice)
        board[2] = aiChoice;
    //players turn
    playerTurn(board);
    //Ai turn 3 potential to win
    if (board[0] == choice && board[1] == choice && board[6]==aiChoice)
        board[7] = aiChoice;
    else if (board[0] == choice && board[2] == choice && board[6] == aiChoice)
        board[7] = aiChoice;
    else if (board[0] == choice && board[3] == choice && board[6] == aiChoice)
        board[7] = aiChoice;
    else if (board[0] == choice && board[4] == choice && board[6] == aiChoice)
        board[7] = aiChoice;
    else if (board[0] == choice && board[5] == choice && board[6] == aiChoice)
        board[7] = aiChoice;
    else if (board[0] == choice && board[7] == choice && board[6] == aiChoice)
        board[2] = aiChoice;

    else if (board[1] == choice && board[0] == choice && board[2] == aiChoice)
        board[5] = aiChoice;
    else if (board[1] == choice && board[3] == choice && board[2] == aiChoice)
        board[5] = aiChoice;
    else if (board[1] == choice && board[4] == choice && board[2] == aiChoice)
        board[5] = aiChoice;
    else if (board[1] == choice && board[5] == choice && board[2] == aiChoice)
        board[6] = aiChoice;
    else if (board[1] == choice && board[6] == choice && board[2] == aiChoice)
        board[5] = aiChoice;
    else if (board[1] == choice && board[7] == choice && board[2] == aiChoice)
        board[5] = aiChoice;

    else if (board[2] == choice && board[0] == choice && board[6] == aiChoice)
        board[7] = aiChoice;
    else if (board[2] == choice && board[1] == choice && board[6] == aiChoice)
        board[7] = aiChoice;
    else if (board[2] == choice && board[3] == choice && board[6] == aiChoice)
        board[7] = aiChoice;
    else if (board[2] == choice && board[4] == choice && board[6] == aiChoice)
        board[7] = aiChoice;
    else if (board[2] == choice && board[5] == choice && board[6] == aiChoice)
        board[7] = aiChoice;
    else if (board[2] == choice && board[7] == choice && board[6] == aiChoice)
        board[0] = aiChoice;

    else if (board[3] == choice && board[0] == choice && board[6] == aiChoice)
        board[7] = aiChoice;
    else if (board[3] == choice && board[1] == choice && board[6] == aiChoice)
        board[7] = aiChoice;
    else if (board[3] == choice && board[2] == choice && board[6] == aiChoice)
        board[7] = aiChoice;
    else if (board[3] == choice && board[4] == choice && board[6] == aiChoice)
        board[7] = aiChoice;
    else if (board[3] == choice && board[5] == choice && board[6] == aiChoice)
        board[7] = aiChoice;
    else if (board[3] == choice && board[7] == choice && board[6] == aiChoice)
        board[2] = aiChoice;

    else if (board[4] == choice && board[1] == choice && board[0] == aiChoice)
        board[7] = aiChoice;
    else if (board[4] == choice && board[2] == choice && board[0] == aiChoice)
        board[6] = aiChoice;
    else if (board[4] == choice && board[3] == choice && board[0] == aiChoice)
        board[5] = aiChoice;
    else if (board[4] == choice && board[5] == choice && board[0] == aiChoice)
        board[3] = aiChoice;
    else if (board[4] == choice && board[6] == choice && board[0] == aiChoice)
        board[2] = aiChoice;
    else if (board[4] == choice && board[7] == choice && board[0] == aiChoice)
        board[1] = aiChoice;

    else if (board[5] == choice && board[0] == choice && board[6] == aiChoice)
        board[7] = aiChoice;
    else if (board[5] == choice && board[1] == choice && board[6] == aiChoice)
        board[7] = aiChoice;
    else if (board[5] == choice && board[2] == choice && board[6] == aiChoice)
        board[7] = aiChoice;
    else if (board[5] == choice && board[3] == choice && board[6] == aiChoice)
        board[7] = aiChoice;
    else if (board[5] == choice && board[4] == choice && board[6] == aiChoice)
        board[7] = aiChoice;
    else if (board[5] == choice && board[7] == choice && board[6] == aiChoice)
        board[0] = aiChoice;

    else if (board[6] == choice && board[0] == choice && board[2] == aiChoice)
        board[5] = aiChoice;
    else if (board[6] == choice && board[1] == choice && board[2] == aiChoice)
        board[5] = aiChoice;
    else if (board[6] == choice && board[3] == choice && board[2] == aiChoice)
        board[5] = aiChoice;
    else if (board[6] == choice && board[4] == choice && board[2] == aiChoice)
        board[5] = aiChoice;
    else if (board[6] == choice && board[5] == choice && board[2] == aiChoice)
        board[0] = aiChoice;
    else if (board[6] == choice && board[7] == choice && board[2] == aiChoice)
        board[5] = aiChoice;

    else if (board[7] == choice && board[0] == choice && board[2] == aiChoice)
        board[5] = aiChoice;
    else if (board[7] == choice && board[1] == choice && board[2] == aiChoice)
        board[5] = aiChoice;
    else if (board[7] == choice && board[3] == choice && board[2] == aiChoice)
        board[5] = aiChoice;
    else if (board[7] == choice && board[4] == choice && board[2] == aiChoice)
        board[5] = aiChoice;
    else if (board[7] == choice && board[5] == choice && board[2] == aiChoice)
        board[6] = aiChoice;
    else if (board[7] == choice && board[6] == choice && board[2] == aiChoice)
        board[5] = aiChoice;
        fin = win(board);
    if (fin==false) {
        playerTurn(board);
        
        if (board[6] == aiChoice && board[2] == aiChoice && board[5]==choice && board[7] == choice)
            board[4] = aiChoice;
        else if (board[6] == aiChoice && board[2] == aiChoice && board[4] == choice && board[7] == choice)
            board[5] = aiChoice;
        else if (board[6] == aiChoice && board[2] == aiChoice && board[5] == choice && board[4] == choice)
            board[7] = aiChoice;

        else if (board[6] == aiChoice && board[0] == aiChoice && board[3] == choice && board[7] == choice)
            board[4] = aiChoice;
        else if (board[6] == aiChoice && board[0] == aiChoice && board[4] == choice && board[7] == choice)
            board[3] = aiChoice;
        else if (board[6] == aiChoice && board[0] == aiChoice && board[3] == choice && board[4] == choice)
            board[7] = aiChoice;

        else if (board[2] == aiChoice && board[0] == aiChoice && board[4] == choice && board[1] == choice)
            board[5] = aiChoice;
        else if (board[2] == aiChoice && board[0] == aiChoice && board[5] == choice && board[1] == choice)
            board[4] = aiChoice;
        else if (board[2] == aiChoice && board[0] == aiChoice && board[5] == choice && board[4] == choice)
            board[1] = aiChoice;
        
        else if (board[1] == aiChoice && board[0] == aiChoice && board[4] == choice && board[7] == choice && board[2] == choice)
            board[6] = aiChoice;
        else if (board[1] == aiChoice && board[0] == aiChoice && board[4] == choice && board[7] == choice && (board[5] == choice || board[3] == choice || board[6] == choice))
            board[2] = aiChoice;

        else if (board[1] == aiChoice && board[0] == aiChoice && board[4] == choice && board[7] == choice && board[2] == choice)
            board[6] = aiChoice;
        else if (board[1] == aiChoice && board[0] == aiChoice && board[4] == choice && board[7] == choice && (board[5] == choice || board[3] == choice || board[6] == choice))
            board[2] = aiChoice;

        
        else if (board[7] == aiChoice && board[0] == aiChoice && board[4] == choice && board[1] == choice && board[6] == choice)
            board[2] = aiChoice;
        else if (board[7] == aiChoice && board[0] == aiChoice && board[4] == choice && board[1] == choice && (board[5] == choice || board[3] == choice || board[2] == choice))
            board[6] = aiChoice;


        else if (board[5] == aiChoice && board[0] == aiChoice && board[4] == choice && board[3] == choice && board[2] == choice)
            board[6] = aiChoice;
        else if (board[5] == aiChoice && board[0] == aiChoice && board[4] == choice && board[3] == choice && (board[1] == choice || board[6] == choice || board[7] == choice))
            board[2] = aiChoice;


        else if (board[3] == aiChoice && board[0] == aiChoice && board[4] == choice && board[5] == choice && board[6] == choice)
            board[2] = aiChoice;
        else if (board[3] == aiChoice && board[0] == aiChoice && board[4] == choice && board[7] == choice && (board[7] == choice || board[1] == choice || board[2] == choice))
            board[6] = aiChoice;
        
        fin = win(board);
        if (fin == false) {
            playerTurn(board);

            if ((board[1] == aiChoice || board[7] == aiChoice) && (board[6] == aiChoice || board[2] == aiChoice) && board[5] == choice)
                board[3] = aiChoice;

            else if ((board[1] == aiChoice || board[7] == aiChoice) && (board[6] == aiChoice || board[2] == aiChoice) && board[3] == choice)
                board[5] = aiChoice;

            if ((board[3] == aiChoice || board[5] == aiChoice) && (board[6] == aiChoice || board[2] == aiChoice) && board[1] == choice)
                board[7] = aiChoice;

            else if ((board[3] == aiChoice || board[5] == aiChoice) && (board[6] == aiChoice || board[2] == aiChoice) && board[7] == choice)
                board[1] = aiChoice;

            fin = win(board);
            }
    }
}