/*
Autor: Jorge Giménez (1493035)
Ficher: Fitxer main per backtracking Sudoku (cpp)
Comentari: Per a PREproblema de CRI 1
*/
#include <iostream>
#include <list>
#include "SudokuDeck.h"
#include "iostream"
#include <chrono>
using namespace std;
using namespace std::chrono;

// vars -> Caselles per emplenar (variables)
// domain -> Valors possibles (domini)
bool backtrackToSolve(SudokuDeck* sudoku, list<pair<int, int>>* vars, pair<int, int> lastCoordinates) {
	if (vars->empty()) return true;

	pair<int, int> coordinates = vars->front();
	for (int domain = 1; domain < 10; domain++) {
		if (sudoku->setCellValue(coordinates.first, coordinates.second, domain)) {
			vars->pop_front();
			if (backtrackToSolve(sudoku, vars, coordinates)) return true;
		}
		sudoku->deleteCellValue(coordinates.first, coordinates.second);
	}
	vars->push_front(lastCoordinates);

	return false;
}

int main()
{
	SudokuDeck* sudokuDeck = new SudokuDeck();

	list<pair<int, int>> dom;
	for (int x = 0; x < 9; x++) {
		for (int y = 0; y < 9; y++) {
			dom.push_back(pair<int, int>(x, y));
		}
	}

	auto start = high_resolution_clock::now();
	backtrackToSolve(sudokuDeck, &dom, pair<int, int>(0,0));
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	sudokuDeck->printDeck();
	cout << "Time elapsed to complete Sudoku: " << duration.count()/1000.0 << "ms";
}