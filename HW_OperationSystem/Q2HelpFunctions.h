#ifndef __Q2HELPFUNCTIONS_
#define __Q2HELPFUNCTIONS_
void initMatQ2(int* mat, int sizeRow, int sizeCol);
void moveZeroUp(int* mat , int rows, int cols, int* indexRow, int* indexCol);
void moveZeroLeft(int* mat , int rows, int cols, int* indexRow, int* indexCol);
void moveZeroRight(int* mat , int rows, int cols, int* indexRow, int* indexCol);
void moveZeroDown(int* mat , int rows, int cols, int* indexRow, int* indexCol);
void mixTheMatrix(int* mat , int rows, int cols, int numberOfTimesToMix, int* indexZeroRow, int* indexZeroCol);
int checkingBoard(int* mat , int rows, int cols);//1-win 0-not complete
int userMove(int* mat , int rows, int cols,int number, int* indexZeroRow, int* indexZeroCol);//1-zero moved 0-not succed to move
#endif