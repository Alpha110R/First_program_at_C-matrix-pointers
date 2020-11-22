#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "helpFunctions.h"

int createRandomNumber(int max, int min){
  int num =min + (rand()%(max-min+1));
  return num;
}
void initMat(int* mat, int rows, int cols){
  for(int i =0 ; i<rows*cols ; i++){
    *mat=createRandomNumber(50,0);
    mat++;
  }
}
void printMat(const int* mat, int rows, int cols){
  for(int i =0 ; i<rows ; i++){
    printf("[");
      for(int j=0 ; j<cols ; j++){
        if(j==cols-1){
          printf("%d", *mat);
        mat++;
        }
        else{
        printf("%d, ", *mat);
        mat++;
        }
      }
      printf("]\n");
  }
}
int menu(){
  int menu;
  printf("Please choose one of the following options\n");
  printf("1 - 90 degree clockwise\n");
  printf("2 - 90 degree counter clockwise\n");
  printf("3 - Flip Horizontal\n");
  printf("4 - Flip Vertical\n");
  printf("-1 - Quit\n");
  scanf("%d", &menu);
  return menu;
}
void rotateMatrixRight(int* mat, int indexRow, int indexCol,int sizeOfRow)
{
  int temp1;
  int temp2;
  for(int i=0 ; i<4 ; i++){
    switch(i){
      case 0:
      temp1 = *(mat+indexCol*sizeOfRow+(sizeOfRow-1-indexRow));
      *(mat+indexCol*sizeOfRow+(sizeOfRow-1-indexRow)) = *(mat+indexRow*sizeOfRow+indexCol);
      break;
      case 1: 
      temp2 = *(mat+(sizeOfRow-1-indexRow)*sizeOfRow+(sizeOfRow-1-indexCol));
      *(mat+(sizeOfRow-1-indexRow)*sizeOfRow+(sizeOfRow-1-indexCol)) = temp1;
      break;
      case 2:
      temp1 = *(mat+(sizeOfRow-1-indexCol)*sizeOfRow+(indexRow));
      *(mat+(sizeOfRow-1-indexCol)*sizeOfRow+(indexRow)) = temp2;
      break;
      case 3:
      *(mat+(indexRow)*sizeOfRow+indexCol) = temp1;
      break;
    }
  }


}
void rotateMatrixLeft(int* mat, int indexRow, int indexCol,int sizeOfRow)
{
  int temp1;
  int temp2;
  for(int i=0 ; i<4 ; i++){
    switch(i){
      case 0:
      temp1 = *(mat+(sizeOfRow-1-indexCol)*sizeOfRow+(indexRow));
      *(mat+(sizeOfRow-1-indexCol)*sizeOfRow+(indexRow)) = *(mat+indexRow*sizeOfRow+indexCol);
      break;
      case 1: 
      temp2 = *(mat+(sizeOfRow-1-indexRow)*sizeOfRow+(sizeOfRow-1-indexCol));
      *(mat+(sizeOfRow-1-indexRow)*sizeOfRow+(sizeOfRow-1-indexCol)) = temp1;
      break;
      case 2:
      temp1 = *(mat+indexCol*sizeOfRow+(sizeOfRow-1-indexRow));
      *(mat+indexCol*sizeOfRow+(sizeOfRow-1-indexRow)) = temp2;
      break;
      case 3:
      *(mat+(indexRow)*sizeOfRow+indexCol) = temp1;
      break;
    }
  }
}
void flipHorizontal(int* mat, int indexRow, int indexCol,int sizeOfRow)
{
  int temp1;
  temp1 = *(mat +(sizeOfRow -1 - indexRow)*sizeOfRow +indexCol);
  *(mat +(sizeOfRow -1 - indexRow)*sizeOfRow +indexCol) = *(mat +(indexRow)*sizeOfRow +indexCol);
  *(mat +(indexRow)*sizeOfRow +indexCol) = temp1;
}
void flipVertical(int* mat, int indexRow, int indexCol,int sizeOfRow)
{
  int temp1;
  temp1 = *(mat +(indexRow)*sizeOfRow +(sizeOfRow -1 -indexCol));
  *(mat +(indexRow)*sizeOfRow +(sizeOfRow -1 -indexCol)) = *(mat +(indexRow)*sizeOfRow + indexCol);
  *(mat +(indexRow)*sizeOfRow + indexCol) = temp1;
}