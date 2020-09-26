/*
Autor: Jorge Giménez (1493035)
Ficher: Clase tauler de Sudoku (h)
Comentari: Per a PREproblema de CRI 1
*/
#include "SudokuCell.h"

class SudokuDeck
{
	private:
		SudokuCell* deck[9][9];
		int nFilledCells = 0;
		bool isFinished = false;
		bool checkIfValueIsValid(int x, int y, int value);
		int getSubDeckFromPosition(int x, int y);
		bool isValidInSubDeck(int subDeck, int value);
		bool isValidInRow(int row, int value);
		bool isValidInColumn(int column, int value);
	public:
		SudokuDeck();
		bool setCellValue(int x, int y, int value);
		void deleteCellValue(int x, int y);
		bool isDeckFinished();
		int getNFilledCells();
		void printDeck();
		int getCellValue(int x, int y);
		bool isCellEmpty(int x, int y);
};

