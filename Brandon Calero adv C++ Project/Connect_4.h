#pragma once
class Connect_4
{
public:
	Connect_4();
	char board[6][7];
	char player_color;
	int choice;
	bool horizontalwin();
	bool verticalwin();
	bool diagnolwin();
	void print();
	void makeMenu();
private:
};

class Connect_4_Player :
	public Connect_4
{
	public:
	Connect_4_Player(char play);
	void turn();
	void aiturnE();
	void aiturnH();
	private:
};


