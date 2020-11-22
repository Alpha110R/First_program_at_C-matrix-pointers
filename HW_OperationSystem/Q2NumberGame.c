#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "helpFunctions.h"
#include "Q2HelpFunctions.h"
#include "Q2NumberGame.h"
#define ROWS 5
#define COLS 4
#define SHUFFEL_COUNT 10
void Q2(){
  int mat [ROWS][COLS];
  int rows = ROWS-1;
  int cols = COLS-1;
  int* indexZeroRow;
  int* indexZeroCol;
  indexZeroRow = &rows;
  indexZeroCol= &cols;
  initMatQ2((int*)mat, ROWS, COLS);
  printMat((int*)mat, ROWS, COLS);
  printf("\n");
  mixTheMatrix((int*)mat, ROWS, COLS, SHUFFEL_COUNT, indexZeroRow, indexZeroCol);
  printf("After a 15 rounds to move the Zero: \n");
  printMat((int*)mat, ROWS, COLS);
  while(checkingBoard((int*)mat, ROWS, COLS) !=1)
  {
    int number;
    printf("Enter the number you want to move: ");
    scanf("%d", &number);
    while(userMove((int*)mat, ROWS, COLS, number, indexZeroRow, indexZeroCol) ==0)
    {
      printf("You enterd invalid number to replace with zero\n");
      printf("Enter the number you want to move: ");
      scanf("%d", &number);
    }
    printMat((int*)mat, ROWS, COLS);
  }
  printf("YOU WON!");
}