#include "matrix.h"
#include <stdio.h>

void createMatrix(int nRows, int nCols, Matrix *m) {
  ROW_EFF(*m) = nRows;
  COL_EFF(*m) = nCols;
}


boolean isMatrixIdxValid(int i, int j) {
  return 0 <= i && i < ROW_CAP && 0 <= j && j < COL_CAP;
}

IdxType getLastIdxRow(Matrix m) {
  return ROW_EFF(m) - 1;
}

IdxType getLastIdxCol(Matrix m) {
  return COL_EFF(m) - 1;
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j) {
  return 0 <= i && i <= getLastIdxRow(m) && 0 <= j && j <= getLastIdxCol(m);
}

ElType getElmtDiagonal(Matrix m, IdxType i) {
  return ELMT(m, i, i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut) {
  ROW_EFF(*mOut) = ROW_EFF(mIn);
  COL_EFF(*mOut) = COL_EFF(mIn); 

  int i, j;
  for (i = 0; i < ROW_EFF(mIn); i++) {
    for (j = 0; j < COL_EFF(mIn); j++) {
      ELMT(*mOut, i, j) = ELMT(mIn, i, j);
    }
  }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol) {
    createMatrix(nRow, nCol, m);
    
    int i, j;
    for (i = 0; i < nRow; i++) {
      for (j = 0; j < nCol; j++) {
        scanf("%d", &ELMT(*m, i, j));
      }
    }
}

void displayMatrix(Matrix m) {
  int i, j;

  for (i = 0; i < ROW_EFF(m); i++) {
    for (j = 0; j < COL_EFF(m); j++) {
      
      if (j == getLastIdxCol(m)) printf("%d", ELMT(m, i, j));
      else printf("%d ", ELMT(m, i, j));
    }

    if (i != getLastIdxRow(m)) printf("\n");
  }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2) {
  Matrix M;
  createMatrix(ROW_EFF(m1), COL_EFF(m2), &M);

  int i, j;
  for (i = 0; i < ROW_EFF(m1); i++) {
    for (j = 0; j < COL_EFF(m2); j++) {
      ELMT(M, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
    }
  }

  return M;
}

Matrix subtractMatrix(Matrix m1, Matrix m2) {
  Matrix M;
  createMatrix(ROW_EFF(m1), COL_EFF(m2), &M);

  int i, j;
  for (i = 0; i < ROW_EFF(m1); i++) {
    for (j = 0; j < COL_EFF(m2); j++) {
      ELMT(M, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
    }
  }

  return M;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2) {
  Matrix M;
  createMatrix(ROW_EFF(m1), COL_EFF(m2), &M);

  int i, j, k;
  for (i = 0; i < ROW_EFF(m1); i++) {
    for (j = 0; j < COL_EFF(m2); j++) {
      ELMT(M, i, j) = 0;

      for (k = 0; k < COL_EFF(m1); k++) {
        ELMT(M, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
      }
    }
  }

  return M;
}

Matrix multiplyByConst(Matrix m, ElType x) {
  Matrix M;
  createMatrix(ROW_EFF(m), COL_EFF(m), &M);

  int i, j;
  for (i = 0; i < ROW_EFF(m); i++) {
    for (j = 0; j < COL_EFF(m); j++) {
      ELMT(M, i, j) = ELMT(m, i, j) * x;
    }
  }

  return M;
}

void pMultiplyByConst(Matrix *m, ElType k) {
  int i, j;
  for (i = 0; i < ROW_EFF(*m); i++) {
    for (j = 0; j < COL_EFF(*m); j++) {
      ELMT(*m, i, j) *= k;
    }
  }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2) {
  if (ROW_EFF(m1) != ROW_EFF(m2) || COL_EFF(m1) != COL_EFF(m2)) return false;
  else {
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++) {
      for (j = 0; j < COL_EFF(m1); j++) {
        if (ELMT(m1, i, j) != ELMT(m2, i, j)) return false;
      }
    }

    return true;
  }
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2) {
  return !isMatrixEqual(m1, m2);
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2) {
  if (ROW_EFF(m1) != ROW_EFF(m2) || COL_EFF(m1) != COL_EFF(m2)) return false;
  else return true;
}

/* ********** Operasi lain ********** */
int countElmt(Matrix m) {
  return ROW_EFF(m) * COL_EFF(m);
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m) {
  return ROW_EFF(m) == COL_EFF(m);
}

boolean isSymmetric(Matrix m) {
  if (isSquare(m)) {
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
      for (j = 0; j < COL_EFF(m); j++) {
        if (ELMT(m, i, j) != ELMT(m, j, i)) return false;
      }
    }
    return true;
  }
  return false;
}

boolean isIdentity(Matrix m) {
  if (isSquare(m)) {
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
      for (j = 0; j < COL_EFF(m); j++) {
        if (i == j && ELMT(m, i, j) != 1) return false;
        else if (i != j && ELMT(m, i, j) != 0) return false;
      }
    }
    return true;
  }
  return false;
}

boolean isSparse(Matrix m) {
  return countElmt(m) <= 500;
}

Matrix negation(Matrix m) {
  Matrix M;
  createMatrix(ROW_EFF(m), COL_EFF(m), &M);

  int i, j;
  for (i = 0; i < ROW_EFF(m); i++) {
    for (j = 0; j < COL_EFF(m); j++) {
      ELMT(M, i, j) = -1*(ELMT(m, i, j));
    }
  }

  return M;
}

void pNegation(Matrix *m) {
  int i, j;
  for (i = 0; i < ROW_EFF(*m); i++) {
    for (j = 0; j < COL_EFF(*m); j++) {
      ELMT(*m, i, j) *= -1;
    }
  }
}

float determinant(Matrix m) {
  if (ROW_EFF(m) == 1) return ELMT(m, 0, 0);
  else {
    float det = 0;

    for (int j = 0; j < COL_EFF(m); j++) {
      Matrix Temp;
      createMatrix(ROW_EFF(m) - 1, COL_EFF(m) - 1, &Temp);

      int x = 0, y = 0;
      for (int i = 1; i < ROW_EFF(m); i++) {
        y = 0;
        for (int k = 0; k < COL_EFF(m); k++) {
          if (k != j) {
            ELMT(Temp, x, y) = ELMT(m, i, k);
            y++;
          }
        }
        x++;
      }
      float sign = (j % 2 == 0) ? 1 : -1;
      det += sign * ELMT(m, 0, j) * determinant(Temp);
    }
    return det;
  }
}

Matrix transpose(Matrix m) {
  Matrix M;
  createMatrix(ROW_EFF(m), COL_EFF(m), &M);

  int i, j;
  for (i = 0; i < ROW_EFF(m); i++) {
    for (j = 0; j < COL_EFF(m); j++) {
      ELMT(M, i, j) = ELMT(m, j, i);
    }
  }

  return M;
}

void pTranspose(Matrix *m) {
  Matrix Temp;
  copyMatrix(*m, &Temp);

  int i, j;
  for (i = 0; i < ROW_EFF(*m); i++) {
    for (j = 0; j < COL_EFF(*m); j++) {
      ELMT(*m, i, j) = ELMT(Temp, j, i);
    }
  }
}