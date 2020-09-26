/*
Autor: Jorge Giménez (1493035)
Ficher: Clase casella de Sudoku (cpp)
Comentari: Per a PREproblema de CRI 1
*/

#include "SudokuCell.h"
#include <assert.h>

SudokuCell::SudokuCell(int x, int y) {
	assert((x > -1 && x < 9)&&(y>-1 && y<9));
	this->xPosition = x;
	this->yPosition = y;
	this->isEmpty = true;
}

void SudokuCell::setValue(int value) {
	assert(value > 0 && value < 10);
	this->value = value;
	this->isEmpty = false;
}

int SudokuCell::getValue() {
	assert(!this->isEmpty);
	return this->value;
}

int SudokuCell::getXPosition() {
	return this->xPosition;
}

int SudokuCell::getYPosition() {
	return this->yPosition;
}

bool SudokuCell::isCellEmpty() {
	return this->isEmpty;
}

void SudokuCell::deleteValue() {
	this->value = -1;
	this->isEmpty = true;
}