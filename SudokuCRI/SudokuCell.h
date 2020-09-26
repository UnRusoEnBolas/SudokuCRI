/*
Autor: Jorge Giménez (1493035)
Ficher: Clase casella de Sudoku (h)
Comentari: Per a PREproblema de CRI 1
*/

class SudokuCell
{
	private:
		int xPosition;
		int yPosition;
		bool isEmpty = true;
		int value = -1;
	public:
		SudokuCell(int x, int y);
		int getXPosition();
		int getYPosition();
		bool isCellEmpty();
		void setValue(int value);
		int getValue();
		void deleteValue();
};

