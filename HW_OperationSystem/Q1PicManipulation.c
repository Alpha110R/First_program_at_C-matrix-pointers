#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "helpFunctions.h"
#include "Q1PicManipulation.h"
#define ROWS 4
#define COLS 4
void Q1(){
  int mat[ROWS][COLS];
  initMat((int*)mat,ROWS,COLS);
  printMat((int*)mat,ROWS,COLS);
  int numberOfMenu = menu();
  switch(numberOfMenu){
   case 1:
   for(int i=0; i<ROWS/2; i++){
     for(int j=0 ; j<(COLS/2+COLS%2) ; j++){
       rotateMatrixRight((int*)mat,i,j,ROWS);
     }
   }
   printMat((int*)mat,ROWS,COLS);
    break;
    case 2:
    for(int i=0; i<ROWS/2; i++){
     for(int j=0 ; j<(COLS/2+COLS%2) ; j++){
       rotateMatrixLeft((int*)mat,i,j,ROWS);
     }
   }
   printMat((int*)mat,ROWS,COLS);
    break;
     case 3:
     for(int i=0; i<ROWS/2; i++){
      for(int j=0 ; j<COLS; j++){
         flipHorizontal((int*)mat,i,j,ROWS);
      }
    }
     printMat((int*)mat,ROWS,COLS);
    break;
    case 4:
      for(int i=0; i<ROWS; i++){
      for(int j=0 ; j<COLS/2; j++){
         flipVertical((int*)mat,i,j,ROWS);
      }
    }
     printMat((int*)mat,ROWS,COLS);
    break;
  }
}

