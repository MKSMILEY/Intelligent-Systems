/*
 *Author: Marko Smiljanic
 *Class: CSc 180
 *Assignment 2: Congress Chess
 *Program Name: Regulator
 */

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void makeMove();
int min(int depth, int alpha, int beta);
char performMove(int i, int j, int i2, int j2);
int max(int depth, int alpha, int beta);
int evaluate();
int checkWinner();
void checkGameOver();
void getMove();
void setup();
int * hDisplayMoves();
int * cDisplayMoves();
void printBoard();
int charToInt(char c);
char intToChar(int j);

int intToRev(int n);

bool hCheckEnemy(int i, int j);
bool cCheckEnemy(int i, int j);
int * hPawnCheck(int i, int j);
int * cPawnCheck(int i, int j);
int * hKnightCheck(int i, int j);
int * cKnightCheck(int i, int j);
int * hBishopCheck(int i, int j);
int * cBishopCheck(int i, int j);
int * hKingCheck(int i, int j);
int * cKingCheck(int i, int j);


const int MAX_DEPTH = 5;
const int MAX_MOVES = 60;
int nodes = 0;
bool humanTurn = false;
float plies = 0;
//int turns = 0;
//float totalPlies = 0;

char board[6][8] = {
	'h', 'h', '-', 'k', 'k', '-', 'b', 'b',
	'-', 'p', 'p', 'p', 'p', 'p', 'p', '-',
	'-', '-', '-', '-', '-', '-', '-', '-',
	'-', '-', '-', '-', '-', '-', '-', '-',
	'-', 'P', 'P', 'P', 'P', 'P', 'P', '-',
	'H', 'H', '-', 'K', 'K', '-', 'B', 'B'
};

int allMoves[MAX_DEPTH][MAX_MOVES][4];

int main() {
	setup();
	printBoard();
	for (;;) {
		if (humanTurn) {
			getMove();
			//makeMove();
			printBoard();
			checkGameOver();
		}
		else {
			makeMove();
			printBoard();
			checkGameOver();
		}
	}
}

void printBoard() {
	cout << "  -------------------------  Computer" << endl;
	for (int i = 6; i > 0; i--) {
		cout << i << "  ";
		for (int j = 0; j < 8; j++) {
			cout << " " << board[i - 1][j] << " ";
		}
		cout << endl;
	}
	cout << "  -------------------------  Player" << endl;
	cout << "    A  B  C  D  E  F  G  H" << endl;
}

void setup() {
	char ans;

	for (int i = 0; i < MAX_DEPTH; i++) {
		for (int j = 0; j < MAX_MOVES; j++) {
			for (int k = 0; k < 4; k++) {
				allMoves[i][j][k] = -1;
			}
		}
	}
	
	cout << "Hello, my name is Regulator! I am here to help keep the peace between the two branches of Government." << endl << endl;
	cout << "Would you like to go first? (Y/N)";
	cin >> ans;
	if (ans == 'y' || ans == 'Y') {
		humanTurn = true;
	}
	else {
		humanTurn = false;
	}
}

int * hDisplayMoves() {
	if (humanTurn) {
		cout << "Available Moves" << endl;
	}
	int movNum = 0;
	static int ret[200];
	for (int i = 0; i < 200; i++) {
		ret[i] = -1;
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			char col = intToChar(j);
			char piece = board[i][j];
			if (piece == 'h') {
				int *moves;
				moves = hKnightCheck(i, j);
				int k = 0;
				while (moves[k] != -1) {
					//add current coord
					ret[movNum++] = j;
					ret[movNum++] = i;

					//add new coord
					if (humanTurn) {
						cout << "    -" << col << (i + 1) << " to ";
					}
					int temp = moves[k];
					moves[k++] = -1;
					ret[movNum++] = temp;
					char tempCol = intToChar(temp);


					temp = moves[k];
					moves[k++] = -1;
					ret[movNum++] = temp;
					if (humanTurn) {
						cout << tempCol;
						cout << (temp + 1);
					}
				}
			}
			if (piece == 'k') {
				int *moves;
				moves = hKingCheck(i, j);
				int k = 0;
				while (moves[k] != -1) {
					//add current coord
					ret[movNum++] = j;
					ret[movNum++] = i;

					//add new coord
					if (humanTurn) {
						cout << "    -" << col << (i + 1) << " to ";
					}
					int temp = moves[k];
					moves[k++] = -1;
					ret[movNum++] = temp;
					char tempCol = intToChar(temp);


					temp = moves[k];
					moves[k++] = -1;
					ret[movNum++] = temp;
					if (humanTurn) {
						cout << tempCol;
						cout << (temp + 1);
					}
				}
			}
			if (piece == 'b') {
				int *moves;
				moves = hBishopCheck(i, j);
				int k = 0;
				while (moves[k] != -1) {
					//add current coord
					ret[movNum++] = j;
					ret[movNum++] = i;

					//add new coord
					if (humanTurn) {
						cout << "    -" << col << (i + 1) << " to ";
					}
					int temp = moves[k];
					moves[k++] = -1;
					ret[movNum++] = temp;
					char tempCol = intToChar(temp);


					temp = moves[k];
					moves[k++] = -1;
					ret[movNum++] = temp;
					if (humanTurn) {
						cout << tempCol;
						cout << (temp + 1);
					}
				}
			}
			if (piece == 'p') {
				int *moves;
				moves = hPawnCheck(i, j);
				int k = 0;
				while (moves[k] != -1) {
					//add current coord
					ret[movNum++] = j;
					ret[movNum++] = i;

					//add new coord
					if (humanTurn) {
						cout << "    -" << col << (i + 1) << " to ";
					}
					int temp = moves[k];
					moves[k++] = -1;
					ret[movNum++] = temp;
					char tempCol = intToChar(temp);

					
					temp = moves[k];
					moves[k++] = -1;
					ret[movNum++] = temp;
					if (humanTurn) {
						cout << tempCol;
						cout << (temp + 1);
					}
				}
			}
		}
	}
	if (humanTurn) {
		cout << endl;
	}
	return ret;
}

int * cDisplayMoves() {
	int movNum = 0;
	static int ret[200] = { -1 };
	for (int i = 0; i < 200; i++) {
		ret[i] = -1;
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			char col = intToChar(j);
			char piece = board[i][j];
			if (piece == 'H') {
				int *moves;
				moves = cKnightCheck(i, j);
				int k = 0;
				while (moves[k] != -1 && k < 16){
					//add current coord
					ret[movNum++] = j;
					ret[movNum++] = i;

					int temp = moves[k];
					moves[k++] = -1;
					ret[movNum++] = temp;
					char tempCol = intToChar(temp);

					temp = moves[k];
					moves[k++] = -1;
					ret[movNum++] = temp;
				}
			}
			if (piece == 'K') {
				int *moves;
				moves = cKingCheck(i, j);
				int k = 0;
				while (moves[k] != -1 && k < 2) {
					//add current coord
					ret[movNum++] = j;
					ret[movNum++] = i;

					int temp = moves[k];
					moves[k++] = -1;
					ret[movNum++] = temp;
					char tempCol = intToChar(temp);


					temp = moves[k];
					moves[k++] = -1;
					ret[movNum++] = temp;
				}
			}
			if (piece == 'B') {
				int *moves;
				moves = cBishopCheck(i, j);
				int k = 0;
				while (moves[k] != -1 && k < 20) {
					//add current coord
					ret[movNum++] = j;
					ret[movNum++] = i;

					int temp = moves[k];
					moves[k++] = -1;
					ret[movNum++] = temp;
					char tempCol = intToChar(temp);


					temp = moves[k];
					moves[k++] = -1;
					ret[movNum++] = temp;
				}
			}
			if (piece == 'P') {
				int *moves;
				moves = cPawnCheck(i, j);
				int k = 0;
				while (moves[k] != -1 && k < 6) {
					//add current coord
					ret[movNum++] = j;
					ret[movNum++] = i;

					int temp = moves[k];
					moves[k++] = -1;
					ret[movNum++] = temp;
					char tempCol = intToChar(temp);


					temp = moves[k];
					moves[k++] = -1;
					ret[movNum++] = temp;
				}
			}
		}
	}
	return ret;
}

void getMove() {
	char col1, col2;
	int	i, i2;

	int *moves;
	moves = hDisplayMoves();
	if(moves[0] == -1) {
		cout << "I am the winner of Congress Chess! I will hold my seat for longer more!" << endl;
		cout << "Press Enter to close the game.";
		cin.ignore();
		exit(0);
	}
	cout << "Enter your move: ";
	cin >> col1 >> i >> col2 >> i2;
	cin.clear();
	//cout << "your move: " << col1 << i << " to " << col2 << i2 << endl;

	i -= 1;
	i2 -= 1;
	int j = charToInt(col1);
	int j2 = charToInt(col2);

	int n = 0;
	bool legalMove = false;
	while (moves[n] != -1) {
		int t1 = moves[n];
		moves[n++] = -1;
		int t2 = moves[n];
		moves[n++] = -1;
		int t3 = moves[n];
		moves[n++] = -1;
		int t4 = moves[n];
		moves[n++] = -1;
		if (j == t1 && i == t2 && j2 == t3 && i2 == t4) {
			cout << "This is a legal move!" << endl;
			legalMove = true;
		}
	}
	if (legalMove) {
		performMove(i, j, i2, j2);
		humanTurn = false;
	}
	else {
		cout << "This is not a legal move. Please enter a legal move." << endl;
	}
}

int evaluate() {
	int ret = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			char temp = board[i][j];
			switch (temp) {
				case 'h': ret -= 1000;
					break;
				case 'k': ret -= 5000;
					break;
				case 'b': ret -= 2000;
					break;
				case 'p': ret -= 250;
					break;
				case 'H': ret += 1000;
					break;
				case 'K': ret += 5000;
					break;
				case 'B': ret += 2000;
					break;
				case 'P': ret += 250;
					break;
				default: 
					break;
			}
		}
	}
	return ret;
}

void makeMove() {
	//cout << "makeMove called" << endl;
	int best = -20000, depth = 0;
	int bestMove = 0;
	int score, mi, mj, mi2, mj2;
	int *moves;
	moves = cDisplayMoves();
	if (moves[0] == -1) {
		cout << "You are the winner of Congress Chess! The Regulator secedes the floor..." << endl;
		cout << "Press Enter to close the game.";
		cin.ignore();
		exit(0);
	}
	int n = 0;
	int m = 0;

	while (moves[n] != -1) {
		allMoves[depth][m][0] = moves[n++];
		allMoves[depth][m][1] = moves[n++];
		allMoves[depth][m][2] = moves[n++];
		allMoves[depth][m][3] = moves[n++];
		m++;
	}
	
	int moveNum = 0;
	while (moveNum < m) {
		int t1, t2, t3, t4;
		t1 = allMoves[depth][moveNum][0];
		t2 = allMoves[depth][moveNum][1];
		t3 = allMoves[depth][moveNum][2];
		t4 = allMoves[depth][moveNum][3];
		
 		char temp = performMove(t2, t1, t4, t3);
		score = min(depth + 1, -100000, 100000);
		if (score > best) {
			bestMove = moveNum;
			best = score;
		}
		//TODO add piece replacement
		performMove(t4, t3, t2, t1);
		board[t4][t3] = temp;
		moveNum++;
		plies += depth;
		nodes++;
	}

	mi = allMoves[depth][bestMove][1];
	mj = allMoves[depth][bestMove][0];
	mi2 = allMoves[depth][bestMove][3];
	mj2 = allMoves[depth][bestMove][2];

	char j = intToChar(mj);
	char j2 = intToChar(mj2);
	cout << "Nodes visited: " << nodes << endl;
	cout << "Average plies: " << plies / nodes << endl;
	int rev1 = intToRev(mi + 1);
	int rev2 = intToRev(mi2 + 1);
	cout << "My move is " << j << mi + 1 << j2 << mi2 + 1 << " (" << j << rev1 << j2 << rev2 << ")" << endl;
	performMove(mi, mj, mi2, mj2);
	humanTurn = true;
	nodes = 0;
	plies = 0;
}

int min(int depth, int alpha, int beta) {
	//cout << "min called " << depth << endl;
	int worst = 20000;
	int worstMove = 0;
	int score, mi, mj, mi2, mj2;
	if (checkWinner() != -1) {
		return checkWinner();
	}
	if (depth >= MAX_DEPTH) {
		return evaluate();
	}
	int *moves;
	moves = hDisplayMoves();
	int n = 0;
	int m = 0;

	while (moves[n] != -1) {
		allMoves[depth][m][0] = moves[n++];
		allMoves[depth][m][1] = moves[n++];
		allMoves[depth][m][2] = moves[n++];
		allMoves[depth][m][3] = moves[n++];
		m++;
	}

	int moveNum = 0;
	while (moveNum < m) {
		int t1, t2, t3, t4;
		t1 = allMoves[depth][moveNum][0];
		t2 = allMoves[depth][moveNum][1];
		t3 = allMoves[depth][moveNum][2];
		t4 = allMoves[depth][moveNum][3];

		char temp = performMove(t2, t1, t4, t3);
		score = max(depth + 1, alpha, beta);
		if (score < worst) {
			worstMove = moveNum;
			worst = score;
		}
		if (worstMove < beta) {
			beta = worstMove;
		}
		
		//TODO add piece replacement
		performMove(t4, t3, t2, t1);
		board[t4][t3] = temp;
		moveNum++;
		nodes++;
		plies += depth;
		if (beta <= alpha) {
			break;
		}
	}
	return worst;
}

int max(int depth, int alpha, int beta) {
	//cout << "max called " << depth << endl;
	int best = -20000;
	int bestMove = 0;
	int score, mi, mj, mi2, mj2;
	if (checkWinner() != -1) {
		return checkWinner();
	}
	if (depth >= MAX_DEPTH) {
		return evaluate();
	}
	int *moves;
	moves = cDisplayMoves();
	int n = 0;
	int m = 0;

	while (moves[n] != -1) {
		allMoves[depth][m][0] = moves[n++];
		allMoves[depth][m][1] = moves[n++];
		allMoves[depth][m][2] = moves[n++];
		allMoves[depth][m][3] = moves[n++];
		m++;
	}

	int moveNum = 0;
	while (moveNum < m) {
		int t1, t2, t3, t4;
		t1 = allMoves[depth][moveNum][0];
		t2 = allMoves[depth][moveNum][1];
		t3 = allMoves[depth][moveNum][2];
		t4 = allMoves[depth][moveNum][3];

		char temp = performMove(t2, t1, t4, t3);
		score = min(depth + 1, alpha, beta);
		if (score > best) {
			bestMove = moveNum;
			best = score;
		}
		if (bestMove > alpha) {
			alpha = bestMove;
		}
		//TODO add piece replacement
		performMove(t4, t3, t2, t1);
		board[t4][t3] = temp;
		moveNum++;
		nodes++;
		plies += depth;
		if (beta <= alpha) {
			break;
		}
	}
	return best;
}

int checkWinner() {
	bool hKing = false;
	bool cKing = false;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			char temp = board[i][j];
			if (temp == 'k') {
				hKing = true;
			}
			if (temp == 'K') {
				cKing = true;
			}
		}
	}
	if (hKing && cKing) {
		return -1;
	}
	else if (!hKing && cKing) {
		return 20000;
	}
	else if (hKing && !cKing) {
		return -20000;
	}
	else {
		//This is not possible
		return 0;
	}
}

void checkGameOver() {
	int result = checkWinner();
	if (result == -20000) {
		cout << "You are the winner of Congress Chess! The Regulator secedes the floor..." << endl;
		cout << "Press Enter to close the game.";
		cin.ignore();
		exit(0);
	}
	else if (result == 20000) {
		cout << "I am the winner of Congress Chess! I will hold my seat for longer more!" << endl;
		cout << "Press Enter to close the game.";
		cin.ignore();
		exit(0);
	}
	else if(result == 0){
		cout << "We have somehow mutually assured our destruction... This should not be possible!" << endl;
		cout << "Press Enter to close the game.";
		cin.ignore();
		exit(0);
	}
}

int * hPawnCheck(int i, int j) {
	static int ret[6];
	for (int n = 0; n < 6; n++) {
		ret[n] = -1;
	}
	int count = 0;
	if (i + 1 < 6 && board[i + 1][j] == '-') {
		ret[count++] = j;
		ret[count++] = i + 1;
	}
	if (i + 1 < 6 && j - 1 >= 0 && hCheckEnemy(i + 1, j - 1)) {
		ret[count++] = j - 1;
		ret[count++] = i + 1;
	}
	if (i + 1 < 6 && j + 1 < 8 && hCheckEnemy(i + 1, j + 1)) {
		ret[count++] = j + 1;
		ret[count++] = i + 1;
	}
	return ret;
}

int * cPawnCheck(int i, int j) {
	static int ret[6];
	for (int n = 0; n < 6; n++) {
		ret[n] = -1;
	}
	int count = 0;
	if (i - 1 >= 0 && board[i - 1][j] == '-') {
		ret[count++] = j;
		ret[count++] = i - 1;
	}
	if (i - 1 >= 0 && j - 1 >= 0 && cCheckEnemy(i - 1, j - 1)) {
		ret[count++] = j - 1;
		ret[count++] = i - 1;
	}
	if (i - 1 >= 0 && j + 1 < 8 && cCheckEnemy(i - 1, j + 1)) {
		ret[count++] = j + 1;
		ret[count++] = i - 1;
	}
	return ret;
}

int * hKnightCheck(int i, int j) {
	static int ret[16];
	for (int n = 0; n < 16; n++) {
		ret[n] = -1;
	}
	int count = 0;

	if (i + 1 < 6 && j + 2 < 8 && (board[i + 1][j + 2] == '-' || hCheckEnemy(i + 1, j + 2))) {
		ret[count++] = j + 2;
		ret[count++] = i + 1;
	}
	if (i + 1 < 6 && j - 2 >= 0 && (board[i + 1][j - 2] == '-' || hCheckEnemy(i + 1, j - 2))) {
		ret[count++] = j - 2;
		ret[count++] = i + 1;
	}
	if (i + 2 < 6 && j + 1 < 8 && (board[i + 2][j + 1] == '-' || hCheckEnemy(i + 2, j + 1))) {
		ret[count++] = j + 1;
		ret[count++] = i + 2;
	}
	if (i + 2 < 6 && j - 1 >= 0 && (board[i + 2][j - 1] == '-' || hCheckEnemy(i + 2, j - 1))) {
		ret[count++] = j - 1;
		ret[count++] = i + 2;
	}

	if (i > 2) {
		if (i - 1 >= 0 && j + 2 < 8 && hCheckEnemy(i - 1, j + 2)) {
			ret[count++] = j + 2;
			ret[count++] = i - 1;
		}
		if (i - 1 >= 0 && j - 2 >= 0 && hCheckEnemy(i - 1, j - 2)) {
			ret[count++] = j - 2;
			ret[count++] = i - 1;
		}
		if (i - 2 >= 0 && j + 1 < 8 && hCheckEnemy(i - 2, j + 1)) {
			ret[count++] = j + 1;
			ret[count++] = i - 2;
		}
		if (i - 2 >= 0 && j - 1 >= 0 && hCheckEnemy(i - 2, j - 1)) {
			ret[count++] = j - 1;
			ret[count++] = i - 2;
		}
	}
	return ret;
}

int * cKnightCheck(int i, int j) {
	static int ret[16];
	for (int n = 0; n < 16; n++) {
		ret[n] = -1;
	}
	int count = 0;

	if (i - 1 >= 0 && j + 2 < 8 && (board[i - 1][j + 2] == '-' || cCheckEnemy(i - 1, j + 2))) {
		ret[count++] = j + 2;
		ret[count++] = i - 1;
	}
	if (i - 1 >= 0 && j - 2 >= 0 && (board[i - 1][j - 2] == '-' || cCheckEnemy(i - 1, j - 2))) {
		ret[count++] = j - 2;
		ret[count++] = i - 1;
	}
	if (i - 2 >= 0 && j + 1 < 8 && (board[i - 2][j + 1] == '-' || cCheckEnemy(i - 2, j + 1))) {
		ret[count++] = j + 1;
		ret[count++] = i - 2;
	}
	if (i - 2 >= 0 && j - 1 >= 0 && (board[i - 2][j - 1] == '-' || cCheckEnemy(i - 2, j - 1))) {
		ret[count++] = j - 1;
		ret[count++] = i - 2;
	}

	if (i < 3) {
		if (i + 1 < 6 && j + 2 < 8 && cCheckEnemy(i + 1, j + 2)) {
			ret[count++] = j + 2;
			ret[count++] = i + 1;
		}
		if (i + 1 < 6 && j - 2 >= 0 && cCheckEnemy(i + 1, j - 2)) {
			ret[count++] = j - 2;
			ret[count++] = i + 1;
		}
		if (i + 2 < 6 && j + 1 < 8 && cCheckEnemy(i + 2, j + 1)) {
			ret[count++] = j + 1;
			ret[count++] = i + 2;
		}
		if (i + 2 < 6 && j - 1 >= 0 && cCheckEnemy(i + 2, j - 1)) {
			ret[count++] = j - 1;
			ret[count++] = i + 2;
		}
	}
	return ret;
}

int * hBishopCheck(int i, int j) {
	static int ret[20];
	for (int n = 0; n < 20; n++) {
		ret[n] = -1;
	}
	bool enemyFound = false;
	int count = 0;
	int k = 1;
	while (i + k < 6 && j + k < 8 && (board[i + k][j + k] == '-' || hCheckEnemy(i + k, j + k)) && !enemyFound) {
		ret[count++] = j + k;
		ret[count++] = i + k;
		if (hCheckEnemy(i + k, j + k)) {
			enemyFound = true;
		}
		k++;
	}

	enemyFound = false;
	k = 1;
	while (i + k < 6 && j - k >= 0 && (board[i + k][j - k] == '-' || hCheckEnemy(i + k, j - k)) && !enemyFound) {
		ret[count++] = j - k;
		ret[count++] = i + k;
		if (hCheckEnemy(i + k, j - k)) {
			enemyFound = true;
		}
		k++;
	}
	if (i > 2) {
		enemyFound = false;
		k = 1;
		while (i - k >= 0 && j + k < 8 && (board[i - k][j + k] == '-' || hCheckEnemy(i - k, j + k)) && !enemyFound) {
			if (hCheckEnemy(i - k, j + k)) {
				ret[count++] = j + k;
				ret[count++] = i - k;
				enemyFound = true;
			}
			k++;
		}

		enemyFound = false;
		k = 1;
		while (i - k >= 0 && j - k >= 0 && (board[i - k][j - k] == '-' || hCheckEnemy(i - k, j - k)) && !enemyFound) {
			if (hCheckEnemy(i - k, j - k)) {
				ret[count++] = j - k;
				ret[count++] = i - k;
				enemyFound = true;
			}
			k++;
		}
	}
	return ret;
}

int * cBishopCheck(int i, int j) {
	static int ret[20];
	for (int n = 0; n < 20; n++) {
		ret[n] = -1;
	}
	bool enemyFound = false;
	int count = 0;
	int k = 1;
	while (i - k >= 0 && j + k < 8 && (board[i - k][j + k] == '-' || cCheckEnemy(i - k, j + k)) && !enemyFound) {
		ret[count++] = j + k;
		ret[count++] = i - k;
		if (cCheckEnemy(i - k, j + k)) {
			enemyFound = true;
		}
		k++;
	}

	enemyFound = false;
	k = 1;
	while (i - k >= 6 && j - k >= 0 && (board[i - k][j - k] == '-' || cCheckEnemy(i - k, j - k)) && !enemyFound) {
		ret[count++] = j - k;
		ret[count++] = i - k;
		if (cCheckEnemy(i - k, j - k)) {
			enemyFound = true;
		}
		k++;
	}

	if (i < 3) {
		enemyFound = false;
		k = 1;
		while (i + k < 6 && j + k < 8 && (board[i + k][j + k] == '-' || cCheckEnemy(i + k, j + k)) && !enemyFound) {
			if (cCheckEnemy(i + k, j + k)) {
				ret[count++] = j + k;
				ret[count++] = i + k;
				enemyFound = true;
			}
			k++;
		}

		enemyFound = false;
		k = 1;
		while (i + k >= 0 && j - k >= 0 && (board[i + k][j - k] == '-' || cCheckEnemy(i + k, j - k)) && !enemyFound) {
			if (cCheckEnemy(i + k, j - k)) {
				ret[count++] = j - k;
				ret[count++] = i + k;
				enemyFound = true;
			}
			k++;
		}
	}
	return ret;
}

int * hKingCheck(int i, int j) {
	static int ret[2] = { -1, -1 };
	int count = 0;
	if (j > 3) {
		if (j + 1 < 8 && (board[i][j + 1] == '-' || hCheckEnemy(i, j + 1))) {
			ret[count++] = j + 1;
				ret[count++] = i;
		}
	}
	else {
		if (j - 1 >= 0 && (board[i][j - 1] == '-' || hCheckEnemy(i, j - 1))) {
			ret[count++] = j - 1;
				ret[count++] = i;
		}
	}
	return ret;
}

int * cKingCheck(int i, int j) {
	static int ret[2] = { -1, -1 };
	int count = 0;
	if (j > 3) {
		if (j + 1 < 8 && (board[i][j + 1] == '-' || cCheckEnemy(i, j + 1))) {
			ret[count++] = j + 1;
			ret[count++] = i;
		}
	}
	else {
		if (j - 1 >= 0 && (board[i][j - 1] == '-' || cCheckEnemy(i, j - 1))) {
			ret[count++] = j - 1;
			ret[count++] = i;
		}
	}
	return ret;
}

char performMove(int i, int j, int i2, int j2) {
	char temp = board[i][j];
	char ret = board[i2][j2];
	board[i][j] = '-';
	if (temp == 'h' && j2 > 3) {
		board[i2][j2] = 'b';
	}
	else if (temp == 'b' && j2 < 4) {
		board[i2][j2] = 'h';
	}
	else if (temp == 'H' && j2 > 3) {
		board[i2][j2] = 'B';
	}
	else if (temp == 'B' && j2 < 4) {
		board[i2][j2] = 'H';
	}
	else {
		board[i2][j2] = temp;
	}
	return ret;
}

bool hCheckEnemy(int i, int j) {
	char target = board[i][j];
	if (target == 'K' || target == 'B' || target == 'H' || target == 'P') {
		return true;
	}
	return false;
}

bool cCheckEnemy(int i, int j) {
	char target = board[i][j];
	if (target == 'k' || target == 'b' || target == 'h' || target == 'p') {
		return true;
	}
	return false;
}

int charToInt(char c) {
	if (c == 'a' || c == 'A') {
		return 0;
	}
	else if (c == 'b' || c == 'B') {
		return 1;
	}
	else if (c == 'c' || c == 'C') {
		return 2;
	}
	else if (c == 'd' || c == 'D') {
		return 3;
	}
	else if (c == 'e' || c == 'E') {
		return 4;
	}
	else if (c == 'f' || c == 'F') {
		return 5;
	}
	else if (c == 'g' || c == 'G') {
		return 6;
	}
	else if (c == 'h' || c == 'h') {
		return 7;
	}
	return -1;
}

char intToChar(int j) {
	if (j == 0) {
		return 'A';
	}
	else if (j == 1) {
		return 'B';
	}
	else if (j == 2) {
		return 'C';
	}
	else if (j == 3) {
		return 'D';
	}
	else if (j == 4) {
		return 'E';
	}
	else if (j == 5) {
		return 'F';
	}
	else if (j == 6) {
		return 'G';
	}
	else if (j == 7) {
		return 'H';
	}
	return 'Z';
}

int intToRev(int n) {
	if (n == 1) {
		return 6;
	}
	else if (n == 2) {
		return 5;
	}
	else if (n == 3) {
		return 4;
	}
	else if (n == 4) {
		return 3;
	}
	else if (n == 5) {
		return 2;
	}
	else {
		return 1;
	}
}