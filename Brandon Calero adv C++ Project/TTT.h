#pragma once
class TTT
{
public:
	char choice = 'a';
	char selection;
	void playerTurn(char board[9]);
	void TTTmenu();
	void TicTacToe(char board[9]);
	bool win(char board[9]);
	void playerletter();
	void PVP(char board[9]);
	void ImpossibleAI(char board[9]);
	void Cpu(char board[9]);
	bool islegal(char board[9], int choice);
	void MBoard(char board[9]);
private:
	char base_board[9]{ '1','2','3','4','5','6','7','8','9' };
};

