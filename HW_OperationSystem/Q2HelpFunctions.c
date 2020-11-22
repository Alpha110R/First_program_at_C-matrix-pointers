#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "helpFunctions.h"
#include "Q2HelpFunctions.h"

//positions: 1-up 2-left 3-right 4-down
void initMatQ2(int* mat, int sizeRow, int sizeCol)
{
  for(int i=0 ; i<sizeRow*sizeCol ; i++)
  {
    if(i==(sizeRow*sizeCol-1)) *(mat+i)=0;
     else{
          *(mat+i) = i+1;
     } 
  }
}

void moveZeroUp(int* mat , int rows, int cols, int* indexRow, int* indexCol)
{
  int temp= *(mat + (*indexRow)*cols-cols+*indexCol);
  *(mat + (*indexRow)*cols-cols+*indexCol) =0;
  *(mat +(*indexRow)*cols +*indexCol) = temp;
  (*indexRow)--;
}
void moveZeroDown(int* mat , int rows, int cols, int* indexRow, int* indexCol)
{
  int temp = *(mat +((*indexRow)*cols+cols)+*indexCol);
  *(mat +((*indexRow)*cols+cols)+*indexCol)=0;
  *(mat +(*indexRow)*cols +*indexCol)=temp;
  (*indexRow)++;
}
void moveZeroLeft(int* mat , int rows, int cols, int* indexRow, int* indexCol)
{
  int temp = *(mat+(*indexRow)*cols+*indexCol-1);
  *(mat+(*indexRow)*cols+*indexCol-1) = 0;
  *(mat +(*indexRow)*cols +*indexCol)=temp;
  (*indexCol)--;
}
void moveZeroRight(int* mat , int rows, int cols, int* indexRow, int* indexCol)
{
  int temp = *(mat+(*indexRow)*cols+*indexCol+1);
  *(mat+(*indexRow)*cols+*indexCol+1)=0;
  *(mat +(*indexRow)*cols +*indexCol)=temp;
  (*indexCol)++;
}

void mixTheMatrix(int* mat , int rows, int cols, int numberOfTimesToMix, int* indexZeroRow, int* indexZeroCol)
//1-up 2-left 3-right 4-down
{
  for(int i=0 ; i< numberOfTimesToMix; i++){
    int randomMove=createRandomNumber(4,1);
    switch(randomMove){
      case 1:
        if(*indexZeroRow==0) break;
        moveZeroUp((int*)mat, rows, cols, indexZeroRow, indexZeroCol);
      break;
      case 2:
      if(*indexZeroCol==0) break;
      moveZeroLeft((int*)mat, rows, cols, indexZeroRow, indexZeroCol);
      break;
      case 3:
      if(*indexZeroCol==cols-1) break;
      moveZeroRight((int*)mat, rows, cols, indexZeroRow, indexZeroCol);
      break;
      case 4:
      if(*indexZeroRow == rows-1) break;
      moveZeroDown((int*)mat, rows, cols, indexZeroRow, indexZeroCol);
      break;
    }
  }
}
int checkingBoard(int* mat , int rows, int cols)
{
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++)
    {
      if(i==rows-1 && j==cols-2){
        break;
      }
      if(*(mat+i*cols+j) != (*(mat+i*cols+j+1)-1)){
        return 0;
      } 
    }
  }
  return 1;
}
int userMove(int* mat , int rows, int cols,int number, int* indexZeroRow, int* indexZeroCol)
{//1-up 2-left 3-right 4-down
  for(int i=1 ; i<=4 ; i++)
  {
    switch(i){
      case 1:
        if(*indexZeroRow==0) break;
        if(*(mat + (*indexZeroRow)*cols-cols+*indexZeroCol) == number){
          moveZeroUp((int*)mat, rows, cols, indexZeroRow, indexZeroCol);
          return 1;
        }
      break;
      case 2:
        if(*indexZeroCol==0) break;
        if(*(mat+(*indexZeroRow)*cols+*indexZeroCol-1) == number){
          moveZeroLeft((int*)mat, rows, cols, indexZeroRow, indexZeroCol);
          return 1;
        }
      break;
      case 3:
        if(*indexZeroCol==cols-1) break;
        if(*(mat+(*indexZeroRow)*cols+*indexZeroCol+1) == number){
         moveZeroRight((int*)mat, rows, cols, indexZeroRow, indexZeroCol);
         return 1;
        }
      break;
      case 4:
        if(*indexZeroRow == rows-1) break;
        if(*(mat +((*indexZeroRow)*cols+cols)+*indexZeroCol)==number){
          moveZeroDown((int*)mat, rows, cols, indexZeroRow, indexZeroCol);
          return 1;
        }
      break;
    }
  }
  return 0;
}