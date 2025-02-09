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

/*
 S11B - Grp22

 Max Chavez
 Charles Cordez
 Carl Crespo
 */

int isInRange(int num) { return (num >= 1 && num <= 9); }

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
  int duplicateItem = 0;
  int checkedRow = 1;
  for (item = 0; item < SIZE; item++) {
    for (duplicateItem = item + 1; duplicateItem < SIZE; duplicateItem++) {
      if (aData[item] == aData[duplicateItem]) {
        checkedRow = 0;
      }
    }
  }

  return checkedRow;
}

int checkcol(int aMatrix[][SIZE], int nColInd) {
  int item = 0;
  int duplicateItem = 0;
  int checkedCol = 1;
  for (item = 0; item < SIZE; item++) {
    for (duplicateItem = item + 1; duplicateItem < SIZE; duplicateItem++) {
      if (aMatrix[item][nColInd] == aMatrix[duplicateItem][nColInd]) {
        checkedCol = 0;
      }
    }
  }
  return checkedCol;
}

int checkbox(int aMatrix[][SIZE], int nRow, int nCol) {
  int row = 0;
  int col = 0;
  int dRow = 0;
  int dCol = 0;
  int checkedBox = 1;
  for (row = nRow; row < (nRow + 3); row++) {
    for (col = nCol; col < (nCol + 3); col++) {
      for (dRow = nRow; dRow < (nRow + 3); dRow++) {
        for (dCol = nCol; dCol < (nCol + 3); dCol++) {
          if ((row != dRow || col != dCol) &&
              aMatrix[row][col] == aMatrix[dRow][dCol]) {
            checkedBox = 0;
          }
        }
      }
    }
  }
  return checkedBox;
}

int main() {
  int aMatrix[SIZE][SIZE];
  /* you can add your own variables */
  int allRows = 0;
  int rowsStatus = 0;
  int allCols = 0;
  int colsStatus = 0;
  int boxRow = 0;
  int boxCol = 0;
  int boxStatus = 0;
  int isFailed = 1;

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
  for (allRows = 0; allRows < SIZE && isFailed; allRows++) {
    rowsStatus = checkrow(aMatrix[allRows]);
    if (!rowsStatus)
      isFailed = 0;
  }

  /* write your condition to execute the following only
     if all rows are still correct.  Call function
     checkcol() mutiple times in a loop. checkcol() will
     check one column at a time.
  */

  if (rowsStatus) {
    for (allCols = 0; allCols < SIZE && isFailed; allCols++) {
      colsStatus = checkcol(aMatrix, allCols);

      if (!colsStatus)
        isFailed = 0;
    }
  }

  /* write your condition to execute the following only
     if all rows and columns are still correct.  Call
     function checkbox() mutiple times as the function will
     check one 3x3 box at a time.
  */
  if (rowsStatus && colsStatus) {
    for (boxRow = 0; boxRow < SIZE && isFailed; boxRow += 3) {
      for (boxCol = 0; boxCol < SIZE && isFailed; boxCol += 3) {
        boxStatus = checkbox(aMatrix, boxRow, boxCol);
        if (!boxStatus)
          isFailed = 0;
      }
    }
  }
  /* if the matrix is a correctly solved Sudoku puzzle,
     display "Sudoku!".  Otherwise display "Wrong Solution".
     While debugging, it is suggested that you include
     in the display which row or column or box the
     wrong solution was [first] detected.
  */
  if (isFailed)
    printf("Sudoku!\n");
  else
    printf("Wrong Solution\n");

  return 0;
}
