/* A console implementation of a 3 x 3 tic-tac-toe board game.
*  This is a structured-programming approach, an object
*  based approach might be better.
*/

#include <iostream>

//universal variables are generally a bad thing!
//should be refactored into classes or passed by reference
//functions, but this is a concept-demonstration program
char board[3][3];
int playerNumber;
bool isGameOver = false;
int row;
int column;
char playerObject;
int moveCount = 0;

//generate the board and set the blank spaces
//to the character '-'
void makeBoard() {

	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
		board[x][y] = '-';
		}
	}
}

//loop through the 2d array to print the board
//nested loop prints the row's columns
//before moving to the next row
void printBoard() {

	std::cout << "Board:\n";
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
		std::cout << board[x][y] << " ";
		}
		std::cout << std::endl;	
	}
}

//change the player object to print the correct
//character (the first player always uses X and
//the second 2)
char setObject() {

	if (playerNumber == 1) {
	playerObject = 'X';
	}
	else if (playerNumber == 2) {
	playerObject = 'O';
	}
	
	return playerObject;
}

//more elegant way to handle exit condition
//using boolean in the while loop to run
//the program
void exitGame() {
	isGameOver == true;
	
	//note this exit 0 is a bad way
	//to do it!
	exit(0);
}

//the function to put the object in the right place
// - should check if there is an object there
// and prompt re-entry of input if so
void placeObject() {

	int userInput;

	std::cout << "Player " << playerNumber << ", place your "<< playerObject <<".\n";

	std::cout << "Choose the row. 1 is Top, 2 is Centre and 3 is Bottom. 0 to exit. \nRow (1,2,3): ";
	
	std::cin >> userInput;
	
	//attempt to handle invalid input (characters, etc.)
	while(!std::cin) {
		std::cout << "That wasn't a number. Try again: ";
		std::cin.clear();
		std::cin.ignore();
		std::cin >> userInput;
	}

	if (userInput == 0) {
		exitGame();
	}

	/*userInput is int for math operation. 
	created the new userInput variable for cleanness instead of typecast to row.
	take 1 from user input  because array count starts from 0*/
	row = (userInput - 1);

	std::cout << "Choose the column. 1 is Left, 2 is Middle and 3 is Right. 0 to exit. \nColumn (1,2,3): ";
	
	std::cin >> userInput;

	//attempt to handle invalid input (characters, etc.)
	while(!std::cin) {
		std::cout << "That wasn't a number. Try again: ";
		std::cin.clear();
		std::cin.ignore();
		std::cin >> userInput;
	}


	if (userInput == 0) {
		exitGame();
	}


	column = (userInput - 1);

	//handle if square is already taken or not a valid array location.
	if (board[row][column] == '-') {
	board[row][column] = playerObject;
	moveCount++;
	}
	else {
	std::cout << "That square is not available. Try again.\n";
	placeObject();
	}
}

//switch player which is also needed to change the character
void changePlayer() {
	
	if (isGameOver != true) {
		if (playerNumber == 1) {
		playerNumber =2;
		}
		else if (playerNumber == 2) {
		playerNumber = 1;
		}
	}
}

void checkForWin() {

//not possible to win until 5th move so skip check until then
if (moveCount > 4 ) {	

	//check row where object was just placed for win condition
	if (isGameOver != true && board[row][0] != '-') {
	       if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
		isGameOver = true;
		std::cout << "Game over. The winner is Player " << playerNumber << ".\n";
		}
	 }

	//check current column for win condition
	 if (isGameOver != true && board[0][column] != '-') {
		if (board[0][column] == board[1][column] && board[1][column] == board[2][column]) {

		isGameOver = true;
		std::cout << "Game over. The winner is Player " << playerNumber << ".\n";
		}			      
	 }
	

	//check board diagonal from top left to bottom right
	if (isGameOver != true && board[0][0] != '-') {
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		isGameOver = true;
		std::cout << "Game over. The winner is Player " << playerNumber << ".\n";
		
		}
	}
	//check diagonal from bottom left to top right
	if (isGameOver != true && board[0][2] != '-') {
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		isGameOver = true;
		std::cout << "Game over. The winner is Player " << playerNumber << ".\n";
		}
	}
}
}


int main () {

	makeBoard();

	if (moveCount == 0) {
		printBoard();
	}


	playerNumber = 1;
	
	do {
	setObject();

	placeObject();
	
	printBoard();	

	checkForWin();

	changePlayer();
	} while (isGameOver == false && moveCount < 9);

	if (isGameOver == false && moveCount >= 9) {
		std::cout << "There is no winner. Thanks for playing.\n";
	}

}
