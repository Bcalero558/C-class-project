#include "Blackjack.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

Blackjack::Blackjack() {
	value = 0;
	playing = true;
}
void Blackjack:: menu() {
	cout << "---------------------------------------" << endl
		<< "|               Welcome               |" << endl
		<< "|                  To                 |" << endl
		<< "|              BlackJack              |" << endl
		<< "---------------------------------------" << endl
		<< "     Make sure not to go over 21 \n";

}

void Blackjack::Thehouse() {
	srand(time(NULL));
	int card = (rand() % 14);
	if (HitorFold == '1') {
		if (card == 0) {
			value++;
		}
		else if (card == 1) {
			value += 2;
		}
		else if (card == 2) {
			value += 3;
		}
		else if (card == 3) {
			value += 4;
		}
		else if (card == 4) {
			value += 5;
		}

		else if (card == 5) {
			value += 6;
		}
		else if (card == 6) {
			value += 7;
		}
		else if (card == 7) {
			value += 8;
		}
		else if (card == 8) {
			value += 9;
		}
		else if (card == 10) {
			value += 10;
		}
		else if (card == 11) {
			value += 10;
		}
		else if (card == 12) {
			value += 10;
		}
		else if (card == 13) {
			value += 10;
		}
	}

	else if (HitorFold == '2') {
	cout << "Thats the end lets look at the score\n";
	playing = false;
	}

}

void Blackjack::start(){
	srand(time(NULL));
	int card = (rand() % 14);

	int ace=0;
	system("ClS");
	cout << value<<"is your current value"
		         <<"\n     choose"
		         <<"\n1.hit      2.fold" ;
	cin >> HitorFold;
	if (value > 21) {
		cout << "oh thats a bust\n";
		HitorFold = '2';
	}
	if (value == 21) {
		cout << "Perfect BlackJack\n";
		HitorFold = '2';
	}
	if (HitorFold == '1') {
		if (card == 0) {
			cout << "You got an ace choose 1 or 11 for your value\n";
			while (ace != 1 && ace != 11) {
				cin >> ace;
				if (ace == 1) {
					value++;
				}
				else if (ace == 11) {
					value += 11;
				}
				else {
					cout << "\nsorry that is not a viable option\n";
					ace = 0;
				}
			}
			ace = 0;
		}
		else if (card == 1) {
			cout << "you got a 2\n";
			value += 2;
		}
		else if (card == 2) {
			cout << "you got a 3\n";
			value += 3;
		}
		else if (card == 3) {
			cout << "you got a 4\n";
			value += 4;
		}
		else if (card == 4) {
			cout << "you got a 5\n";
			value += 5;
		}

		else if (card == 5) {
			cout << "you got a 6\n";
			value += 6;
		}
		else if (card == 6) {
			cout << "you got a 7\n";
			value += 7;
		}
		else if (card == 7) {
			cout << "you got a 8\n";
			value += 8;
		}
		else if (card == 8) {
			cout << "you got a 9\n";
			value += 9;
		}
		else if (card == 10) {
			cout << "you got a 10\n";
			value += 10;
		}
		else if (card == 11) {
			cout << "you got a J value goes up by 10\n";
			value += 10;
		}
		else if (card == 12) {
			cout << "you got a K value goes up by 10\n";
			value += 10;
		}
		else if (card == 13) {
			cout << "you got a Q value goes up by 10\n";
			value += 10;
		}
	}
	else if (HitorFold == '2') {
		cout << "Thats the end lets look at the score\n";
		playing = false;
	}
}