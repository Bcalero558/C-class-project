#include <iostream>
#include <stdlib.h>
#include "Connect_4.h"
using namespace std;
Connect_4::Connect_4() {
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 7; j++)
		{
			board[i][j] = '_';
		}
}

bool Connect_4::diagnolwin() {

	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++) {

			if ((board[i][j] == 'Y' && board[i + 1][j + 1] == 'Y' && board[i + 2][j + 2] == 'Y' && board[i + 3][j + 3] == 'Y'))
			{
				print();
				cout << "Y wins\n";
				return true;
			}
			else if (board[i][j] == 'R' && board[i + 1][j + 1] == 'R' && board[i + 2][j + 2] == 'R' && board[i + 3][j + 3] == 'R') {
				print();
				cout << "R wins\n";
				return true;
			}
			else if (board[i + 3][j] == 'Y' && board[i + 2][j + 1] == 'Y' && board[i + 1][j + 2] == 'Y' && board[i][j + 3] == 'Y')
			{
				print();
				cout << "Y wins\n";
				return true;
			}
			else if (board[i + 3][j] == 'R' && board[i + 2][j + 1] == 'R' && board[i + 1][j + 2] == 'R' && board[i][j + 3] == 'R') {
				print();
				cout << "R wins\n";
				return true;
			}
		}
			return false;
}

bool Connect_4::verticalwin() {
	int checkY = 0;
	int checkR = 0;
	int current_row = 0;
	for (current_row; current_row < 7; current_row++) {
		for (int i = 0; i < 6; i++) {
			if (board[i][current_row] == 'Y') {
				checkY++;
				checkR = 0;
			}
			else if (board[i][current_row] == 'R') {
				checkR++;
				checkY = 0;
			}
			else {
				checkY = 0;
				checkR = 0;
			}
			if (checkY >= 4) {
				print();
				cout << "\nCongrats Y\n";
				return true;
			}
			if (checkR >= 4) {
				print();
				cout << "\nCongrats R\n";
				return true;
			}
		}
	}
	if (checkY < 4 && checkY < 4)
		return false;

}

bool Connect_4::horizontalwin() {
	int checkY=0;
	int checkR=0;
	int current_row = 0;
	for (current_row; current_row < 6; current_row++) {
		for (int i = 0; i < 7; i++) {
			if (board[current_row][i] == 'Y') {
				checkY++;
				checkR = 0;
			}
			else if (board[current_row][i] == 'R') {
				checkR++;
				checkY = 0;
			}
			else {
				checkY = 0;
				checkR = 0;
			}
			if (checkY >= 4) {
				print();
				cout << "\nCongrats Y\n";
				return true;
			}
			if (checkR >= 4) {
				print();
				cout << "\nCongrats R\n";
				return true;
			}
		}
	}
	if (checkY < 4 && checkY<4)
		return false;
	}

void Connect_4::print() {
	cout << "  1    2    3    4    5    6    7 \n";
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++)
		{
			cout << "{ " << board[i][j] << " }";
		}
		cout << endl;
	}
}

void Connect_4::makeMenu() {
	cout << "---------------------------------------" << endl
		<< "|               Welcome               |" << endl
		<< "|                  To                 |" << endl
		<< "|              Connect 4              |" << endl
		<< "---------------------------------------" << endl
		<< "1. 2 Player               2. Vs AI \n3.Quit"<< endl;
			
				
}

Connect_4_Player::Connect_4_Player(char play) {
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 7; j++)
		{
			board[i][j] = '_';
		}
	player_color = play;
	}

void Connect_4_Player::turn() {
	int i = 5;
	bool legal = false;
	int j;
	do{
	do {
		
		cout << "Pick a spot between 1 and 7: ";
		cin >> choice;
		choice-=1;
	} while(choice >6);

		if (board[i][choice] != 'R' && board[i][choice] != 'Y') {
			board[i][choice] = player_color;
			legal = true;
		}
		else
		{
			while(board[i][choice]=='R'||board[i][choice] == 'Y')
			i--;
		}
		if (i < 0) {
			cout << "Pick a different number";
			i = 5;
			cin >> choice;
			legal = false;
		}
		
			
	} while (legal == false);
	if (player_color == 'R')
		player_color = 'Y';
	else if (player_color == 'Y')
		player_color = 'R';
}


void Connect_4_Player::aiturnE() {
	srand(time(NULL));
	int turn = (rand() % 7);
	bool workin=false;
	do {
		turn = (rand() % 7);
		if (board[5][turn] == '_') {
			board[5][turn] = player_color;
			workin = true;
		}
		else if (board[5][turn] == 'R' || board[5][turn] == 'Y') {
			if (board[4][turn] == '_') {
				board[4][turn] = player_color;
				workin = true;
			}
			else if (board[4][turn] == 'R' || board[4][turn] == 'Y') {
				if (board[3][turn] == '_') {
					board[3][turn] = player_color;
					workin = true;
				}
				else if (board[3][turn] == 'R' || board[3][turn] == 'Y') {
					if (board[2][turn] == '_') {
						board[2][turn] = player_color;
						workin = true;
					}
					else if (board[2][turn] == 'R' || board[2][turn] == 'Y') {
						if (board[1][turn] == '_') {
							board[1][turn] = player_color;
							workin = true;
						}
						else if (board[1][turn] == 'R' || board[1][turn] == 'Y') {
							if (board[0][turn] == '_') {
								board[0][turn] = player_color;
								workin = true;
							}
						}
					}
				}
			}
		}
	} while (workin == false);
	if (player_color == 'R')
		player_color = 'Y';
	else if (player_color == 'Y')
		player_color = 'R';
}

