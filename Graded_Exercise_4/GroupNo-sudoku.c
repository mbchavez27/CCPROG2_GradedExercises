#include "sudoku.h" //do not remove or replace
#include <stdio.h>

/* Tasks : Implement each and every function indicated
           in sudoku.h.  You are not allowed to modify
                   the parameter list or the return type.  Other
                   constraints and requirements are indicated in
                   the instructions in the pdf file.

                   Complete the main program based on the
                   comments indicated.
*/

int isInRange(int num) {
  if (num >= 1 && num <= 9)
    return 1;
  else
    return 0;
}

void getInput(int aMatrix[][SIZE]) {
  int input = 0;
  int row = 0;
  int col = 0;
  while (row < SIZE) {
    scanf("%d", &input);
    if (isInRange(input)) {
      aMatrix[row][col] = input;
      col++;
      if (col == (SIZE)) {
        col = 0;
        row++;
      }
    }
  }
}

void displayRow(int aRow[]) {
  int item = 0;
  int space = 0;
  while (item < SIZE) {
    printf("%d ", aRow[item]);
    item++;
    space++;
    if (space == 3) {
      printf("  ");
      space = 0;
    }
  }
}

void displayAll(int aMatrix[][SIZE]) {
  int col = 0;
  int space = 0;
  for (col = 0; col < SIZE; col++) {
    space++;
    displayRow(aMatrix[col]);
    printf("\n");
    if (space == 3) {
      space = 0;
      printf("\n");
    }
  }
}

int checkrow(int aData[]) {
  int item = 0;
  int checkedRow = 0;
  int isFound = 1;
  for (item = 0; item < SIZE && isFound; item++) {
    if (isInRange(aData[item])) {
      checkedRow = 1;
    } else {
      checkedRow = 0;
      isFound = 0;
    }
  }

  return checkedRow;
}

int checkcol(int aMatrix[][SIZE], int nColInd) {
  int item = 0;
  int checkedCol = 0;
  int isFound = 1;

  for (item = 0; item < SIZE && isFound; item++) {
    if (isInRange(aMatrix[item][nColInd])) {
      checkedCol = 1;
    } else {
      checkedCol = 0;
      isFound = 0;
    }
  }
  return checkedCol;
}

int checkbox(int aMatrix[][SIZE], int nRow, int nCol) {
  int row = 0;
  int col = 0;
  int checkedBox = 0;
  int isFound = 1;
  for (row = nRow; row < (nRow + 2) && isFound; row++) {
    for (col = nCol; col < (nCol + 2) && isFound; col++) {
      if (isInRange(aMatrix[row][col])) {
        checkedBox = 1;
      } else {
        checkedBox = 0;
        isFound = 0;
      }
    }
  }
  return checkedBox;
}

int main() {
  int aMatrix[SIZE][SIZE];
  /* you can add your own variables */

  /* call getInput().  It is encouraged that you use
     input redirection, so you do not need to keep
     typing a set of values.  Modify file containing
     the input values to consider other test cases OR
     create other files of input values per test case.
  */
  getInput(aMatrix);
  /* call displayAll() to verify that you got the inputs
     correctly.  Note the expected format of the displayed
     result.
  */
  displayAll(aMatrix);

  /* call function checkrow() multiple times in loop.
     Note that checkrow() will check one row at a time.
  */
  int allRows = 0;
  int rowsStatus = 0;
  for (allRows = 0; allRows < SIZE; allRows++) {
    rowsStatus = checkrow(aMatrix[allRows]);
  }

  /* write your condition to execute the following only
     if all rows are still correct.  Call function
     checkcol() mutiple times in a loop. checkcol() will
     check one column at a time.
  */
  int allCols = 0;
  int colsStatus = 0;

  if (rowsStatus) {
    for (allCols = 0; allCols < SIZE; allCols++) {
      colsStatus = checkcol(aMatrix, allCols);
    }
  }

  /* write your condition to execute the following only
     if all rows and columns are still correct.  Call
     function checkbox() mutiple times as the function will
     check one 3x3 box at a time.
  */
  int boxRow = 0;
  int boxCol = 0;
  int boxStatus = 0;
  if (rowsStatus && colsStatus) {
    for (boxRow = 0; boxRow < SIZE; boxRow += 3) {
      boxCol = boxRow;
      boxStatus = checkbox(aMatrix, boxRow, boxCol);
    }
  }
  /* if the matrix is a correctly solved Sudoku puzzle,
     display "Sudoku!".  Otherwise display "Wrong Solution".
     While debugging, it is suggested that you include
     in the display which row or column or box the
     wrong solution was [first] detected.
  */
  if (rowsStatus && colsStatus && boxStatus)
    printf("Sodoku!\n");
  else
    printf("Wrong Solution\n");

  return 0;
}
