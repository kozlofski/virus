#define BOARD_SIZE 20
#define ROUNDS 150
#define FRAME_SPEED 100

#include <iostream>
#include <cstdlib>
#include "Field.h"

void generateBoard();
void printBoard();
void patientZero();
void turn(int howManyTurns);
void infection();
void infectNeighbors(int x, int y);
void infectField(int x, int y);
void beingSick();
void dieOrNotToDie();
void checkImmunities();
void increaseIllnessDays();

Field board[BOARD_SIZE][BOARD_SIZE];

int main (){
	srand(time(NULL));
	Field board[BOARD_SIZE][BOARD_SIZE];
	Animation::clear();
	generateBoard();
	patientZero();
	turn(ROUNDS);
	return 0;
}

void generateBoard() {
	for(int y = 0; y < BOARD_SIZE; y++) {
		for(int x = 0; x < BOARD_SIZE; x++) {
			board[y][x] = Field();
		}
	}	
}

void printBoard() {
	int color;
	Animation::clear();
	for (int y = 0; y < BOARD_SIZE; y++) {
		for(int x = 0; x < BOARD_SIZE; x++) {				
			board[y][x].infected ? color = 4 : color = board[y][x].state;
			Animation::drawPixel(color, 'X');
			// Animation::drawPixel(color, board[y][x].illness + 48);
		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
	Animation::wait(FRAME_SPEED);
}

void patientZero() {
	int x = rand() % BOARD_SIZE;
	int y = rand() % BOARD_SIZE;
	board[y][x].patientZeroGetIll();
}

void turn(int howManyTurns) {
	for(int i = 0; i < howManyTurns; i++) {		
		// std::cout<<"\nTurn "<<i+1<<" now some will be infected\n";
		infection(); // samo zarażanie
		increaseIllnessDays();
		// printBoard();
		// std::cout<<"\nTurn "<<i+1<<" now some will become sick\n";
		beingSick(); // zachorowywanie
		// printBoard();
		// std::cout<<"\nTurn "<<i+1<<" now some will become immune\n";
		checkImmunities();
		// printBoard();	
		// std::cout<<"\nTurn "<<i+1<<" now some will die\n";
		dieOrNotToDie();		
		printBoard();		
	}
}

void dieOrNotToDie() {
	for(int y = 0; y < BOARD_SIZE; y++) {
		for(int x = 0; x < BOARD_SIZE; x++) {
			if(board[y][x].state != IMMUNE && 
				board[y][x].state == ILL &&
				rand() % 1000 < DEATH_RATE * 1000) {
					board[y][x].die();	
			}
		}
	}
}

void increaseIllnessDays() {
	for(int y = 0; y < BOARD_SIZE; y++) {
		for(int x = 0; x < BOARD_SIZE; x++) {
			if(board[y][x].state == ILL) {
				board[y][x].illness--;
			}
		}
	}
}

void infection() {
	for(int y = 0; y < BOARD_SIZE; y++) {
		for(int x = 0; x < BOARD_SIZE; x++) {
			if(board[y][x].state == ILL) {
				infectNeighbors(x, y);		
			}
		}
	}
}

void infectNeighbors(int x, int y) {
	infectField(x+1, y-1); // right upper
	infectField(x+1, y); // right
	infectField(x+1, y+1); //right lower
	infectField(x, y+1); //lower
	infectField(x-1, y+1); //left lower
	infectField(x-1, y); //left
	infectField(x-1, y-1); //left upper
	infectField(x, y-1); //upper	
}	

void infectField(int x, int y) {
	if(x>=0 && x<BOARD_SIZE && y>=0 && y<BOARD_SIZE
		&& board[y][x].state == HEALTHY) {
		board[y][x].getInfected();
	}
}

void beingSick() {
	for(int y = 0; y < BOARD_SIZE; y++) {
		for(int x = 0; x < BOARD_SIZE; x++) {
			if(board[y][x].infected) {
				board[y][x].getIll();
			}
		}
	}
}

void checkImmunities() {
	for(int y = 0; y < BOARD_SIZE; y++) {
		for(int x = 0; x < BOARD_SIZE; x++) {
			if(board[y][x].state == ILL) {
				board[y][x].checkImmunity();
			}
		}
	}
}