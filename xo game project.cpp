#include <iostream>
using namespace std;

	
	char board[3][3] = { 
		{'1', '2', '3'},
		{'4', '5', '6'},
		{'7', '8', '9'}
	};
	void drawfullboard(string playerX, string playerO);
	void startgame(string playerX, string playerO);
	int checkwin();

	int main() {
	cout << "=== XO Game ===" << endl;
	string playerX, playerO;
	cout << "Enter name for Player X: "<<endl;
	cin >> playerX;
	cout << "Enter name for Player O: "<<endl;
	cin >> playerO;

	drawfullboard(playerX, playerO);
	startgame(playerX, playerO);

}
	void drawfullboard(string playerX, string playerO) {
		cout << "Player X: " << playerX << endl;
		cout << "Player O: " << playerO << endl;
		cout << endl;
		cout << "     |     |     " << endl;
		cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
		cout << "_____|_____|_____" << endl;
		cout << "     |     |     " << endl;
		cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
		cout << "_____|_____|_____" << endl;
		cout << "     |     |     " << endl;
		cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
		cout << "     |     |     " << endl;
	}
	void startgame(string playerX, string playerO) {
		int choice;
		int player = 1;
		int i;
		char mark;
		do {
			drawfullboard(playerX, playerO);
			player = (player % 2) ? 1 : 2;
			cout << "Player " << player << ", enter a number: ";
			cin >> choice;
			mark = (player == 1) ? 'X' : 'O';
			if (choice == 1 && board[0][0] == '1')
				board[0][0] = mark;
			else if (choice == 2 && board[0][1] == '2')
				board[0][1] = mark;
			else if (choice == 3 && board[0][2] == '3')
				board[0][2] = mark;
			else if (choice == 4 && board[1][0] == '4')
				board[1][0] = mark;
			else if (choice == 5 && board[1][1] == '5')
				board[1][1] = mark;
			else if (choice == 6 && board[1][2] == '6')
				board[1][2] = mark;
			else if (choice == 7 && board[2][0] == '7')
				board[2][0] = mark;
			else if (choice == 8 && board[2][1] == '8')
				board[2][1] = mark;
			else if (choice == 9 && board[2][2] == '9')
				board[2][2] = mark;
			else {
				cout << "Invalid move ";
				player--;
				cin.ignore();
				cin.get();
			}
			i = checkwin();
			player++;
		} while (i == -1);
		drawfullboard(playerX, playerO);
		if (i == 1)
			cout << "==>\aPlayer " << --player << " win ";
		else
			cout << "==>\aGame draw";
		cin.ignore();
		cin.get();
	}

	int checkwin() {
		if (board[1] == board[2] && board[2] == board[3]) {
			return 1;
		}
		else if (board[4] == board[5] && board[5] == board[6]) {
			return 1;
		}
		else if (board[7] == board[8] && board[8] == board[9]) {
			return 1;
		}
		else if (board[1] == board[4] && board[4] == board[7]) {
			return 1;
		}
		else if (board[2] == board[5] && board[5] == board[8]) {
			return 1;
		}
		else if (board[3] == board[6] && board[6] == board[9]) {
			return 1;
		}
		else if (board[1] == board[5] && board[5] == board[9]) {
			return 1;
		}
		else if (board[3] == board[5] && board[5] == board[7]) {
			return 1;
		}
		else if (board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3' &&
			board[1][0] != '4' && board[1][1] != '5' && board[1][2] != '6' &&
			board[2][0] != '7' && board[2][1] != '8' && board[2][2] != '9') {
			return 0;
		}
		else
			return -1;
	}
