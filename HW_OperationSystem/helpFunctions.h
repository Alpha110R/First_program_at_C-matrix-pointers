#ifndef __HELPFUNCTIONS_
#define __HELPFUNCTIONS_

void initMat(int* mat, int rows, int col);
void printMat(const int* mat, int rows, int cols);
int createRandomNumber(int max);
int menu();
void rotateMatrixRight(int* mat, int indexRow, int indexCol,int sizeOfRow);
void rotateMatrixLeft(int* mat, int indexRow, int indexCol,int sizeOfRow);
void flipHorizontal(int* mat, int indexRow, int indexCol,int sizeOfRow);
void flipVertical(int* mat, int indexRow, int indexCol,int sizeOfRow);

#endif