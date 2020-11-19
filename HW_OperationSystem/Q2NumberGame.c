#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "Q2NumberGame.h"
#include "Q2HelpFunc.h"
#include "helpFunctions.h"
#define ROWS 4
#define COLS 4
void Q2(){
  int mat[4][4];
  initMatQ2((int*)mat,4,4);
  printMat((int*)mat,3,3);
}