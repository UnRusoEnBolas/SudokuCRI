/*
Autor: Jorge Giménez (1493035)
Ficher: Clase tauler de Sudoku (cpp)
Comentari: Per a PREproblema de CRI 1
*/
#include "SudokuDeck.h"
#include "iostream"
using namespace std;

SudokuDeck::SudokuDeck() {
	for (int x = 0; x < 9; x++) {
		for (int y = 0; y < 9; y++) {
			SudokuCell* sudokuCell = new SudokuCell(x, y);
			this->deck[x][y] = sudokuCell;
		}
	}
}

int SudokuDeck::getSubDeckFromPosition(int x, int y) {
	int subDeck = -1;
	if (x >= 0 && x <= 2) {
		if (y >= 0 && y <= 2) {
			subDeck = 0;
		}
		else if (y >= 3 && y <= 5){
			subDeck = 1;
		}
		else if (y >= 6 && y <= 8) {
			subDeck = 2;
		}
	}
	else if (x >= 3 && x <= 5) {
		if (y >= 0 && y <= 2) {
			subDeck = 3;
		}
		else if (y >= 3 && y <= 5) {
			subDeck = 4;
		}
		else if (y >= 6 && y <= 8) {
			subDeck = 5;
		}
	}
	else if (x >= 6 && x <= 8) {
		if (y >= 0 && y <= 2) {
			subDeck = 6;
		}
		else if (y >= 3 && y <= 5) {
			subDeck = 7;
		}
		else if (y >= 6 && y <= 8) {
			subDeck = 8;
		}
	}
	return subDeck;
}

bool SudokuDeck::isValidInSubDeck(int subDeck, int value) {
	int startingIndexX = -1;
	int startingIndexY = -1;

	if (subDeck == 0 || subDeck == 1 || subDeck == 2) startingIndexX = 0;
	else if (subDeck == 3 || subDeck == 4 || subDeck == 5) startingIndexX = 3;
	else if (subDeck == 6 || subDeck == 7 || subDeck == 8) startingIndexX = 6;

	if (subDeck == 0 || subDeck == 3 || subDeck == 6) startingIndexY = 0;
	else if (subDeck == 1 || subDeck == 4 || subDeck == 7) startingIndexY = 3;
	else if (subDeck == 2 || subDeck == 5 || subDeck == 8) startingIndexY = 6;

	for (int x = startingIndexX; x < startingIndexX + 3; x++) {
		for (int y = startingIndexY; y < startingIndexY + 3; y++) {
			if (!this->deck[x][y]->isCellEmpty()) {
				if (this->deck[x][y]->getValue() == value) return false;
			}
		}
	}

	return true;
}

bool SudokuDeck::isValidInRow(int row, int value) {
	for (int y = 0; y < 9; y++) {
		if (!this->deck[row][y]->isCellEmpty()) {
			if (this->deck[row][y]->getValue() == value) return false;
		}
	}
	return true;
}

bool SudokuDeck::isValidInColumn(int column, int value) {
	for (int x = 0; x < 9; x++) {
		if (!this->deck[x][column]->isCellEmpty()) {
			if (this->deck[x][column]->getValue() == value) return false;
		}
	}
	return true;
}

bool SudokuDeck::checkIfValueIsValid(int x, int y, int value) {
	int belongingSubDeck = this->getSubDeckFromPosition(x, y);
	if (!this->isValidInSubDeck(belongingSubDeck, value)) return false;
	if (!this->isValidInRow(x, value)) return false;
	if (!this->isValidInColumn(y, value)) return false;
	return true;
}

bool SudokuDeck::setCellValue(int x, int y, int value) {
	if (this->checkIfValueIsValid(x, y, value)) {
		this->deck[x][y]->setValue(value);
		this->nFilledCells++;
		if (nFilledCells == 9 * 9) this->isFinished = true;
	}
	else return false;

	return true;
}

int SudokuDeck::getCellValue(int x, int y) {
	return this->deck[x][y]->getValue();
}

bool SudokuDeck::isCellEmpty(int x, int y) {
	return this->deck[x][y]->isCellEmpty();
}

void SudokuDeck::deleteCellValue(int x, int y) {
	this->deck[x][y]->deleteValue();
	this->nFilledCells--;
	this->isFinished = false;
}

bool SudokuDeck::isDeckFinished() {
	return this->isFinished;
}

int SudokuDeck::getNFilledCells() {
	return this->nFilledCells;
}

void SudokuDeck::printDeck() {
	for (int x = 0; x < 9; x++) {
		for (int y = 0; y < 9; y++) {
			if (this->deck[x][y]->isCellEmpty()) {
				cout << "-" << " ";
			}
			else {
				cout << this->deck[x][y]->getValue() << " ";
			}
			if (y == 2 || y== 5) cout << "* ";
		}
		if (x == 2 || x == 5) {
			cout << "\n";
			cout << "* * * * * * * * * * *";
		}
		cout << "\n";
	}
}