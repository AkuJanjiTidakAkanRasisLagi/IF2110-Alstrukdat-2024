#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>

#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

void CreateListDin(ListDin *l, int capacity) {
  BUFFER(*l) = (int*) malloc(capacity*sizeof(int));
  CAPACITY(*l) = capacity;
  NEFF(*l) = 0;
}

void dealocateList(ListDin *l) {
  NEFF(*l) = 0;
  CAPACITY(*l) = 0;
  free(BUFFER(*l));
}

int listLength(ListDin l) {
  return NEFF(l);
}

IdxType getFirstIdx(ListDin l) {
  return 0;
}

IdxType getLastIdx(ListDin l) {
  return NEFF(l) - 1;
}

boolean isIdxValid(ListDin l, IdxType i) {
  return 0 <= i && i < CAPACITY(l);
}

boolean isIdxEff(ListDin l, IdxType i) {
  return 0 <= i && i <= getLastIdx(l);
}

boolean isEmpty(ListDin l) {
  return NEFF(l) == 0;
}

boolean isFull(ListDin l) {
  return NEFF(l) == CAPACITY(l);
}

void readList(ListDin *l) {
  int n;
  do {
    scanf("%d", &n);
  } while (n < 0 || n > CAPACITY(*l));

  NEFF(*l) = n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &ELMT(*l, i));
  }
}

void printList(ListDin l) {
  printf("[");
  for (int i = 0; i < NEFF(l); i++) {
    printf("%d", ELMT(l, i));
    if (i < NEFF(l) - 1) {
      printf(",");
    }
  }
  printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus) {
  ListDin l;
  CreateListDin(&l, CAPACITY(l1));
  NEFF(l) = NEFF(l1);

  for (int i = 0; i < NEFF(l); i++) {
    if (plus) ELMT(l, i) = ELMT(l1, i) + ELMT(l2, i);
    else ELMT(l, i) = ELMT(l1, i) - ELMT(l2, i);
  }

  return l;
}

boolean isListEqual(ListDin l1, ListDin l2) {
  if (NEFF(l1) != NEFF(l2)) return false;

  for (int i = 0; i < NEFF(l1); i++) {
    if (ELMT(l1, i) != ELMT(l2, i)) return false;
  }

  return true;
}

IdxType indexOf(ListDin l, ElType val) {
  for (int i = 0; i < NEFF(l); i++) {
    if (ELMT(l, i) == val) return i;
  }
  return IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min) {
  *max = ELMT(l, 0);
  *min = ELMT(l, 0);

  for (int i = 1; i < NEFF(l); i++) {
    if (ELMT(l, i) > *max) *max = ELMT(l, i);
    if (ELMT(l, i) < *min) *min = ELMT(l, i);
  }
}

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut) {
  CreateListDin(lOut, CAPACITY(lIn));
  NEFF(*lOut) = NEFF(lIn);

  for (int i = 0; i < NEFF(lIn); i++) {
    ELMT(*lOut, i) = ELMT(lIn, i);
  }
}

ElType sumList(ListDin l) {
  int sum = 0;
  for (int i = 0; i < NEFF(l); i++) {
    sum += ELMT(l, i);
  }

  return sum;
}

int countVal(ListDin l, ElType val) {
  int count = 0;
  for (int i = 0; i < NEFF(l); i++) count += (ELMT(l, i) == val);

  return count;
}

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc) {
  for (int i = 0; i < NEFF(*l); i++) {
    for (int j = i + 1; j < NEFF(*l); j++) {
      if (asc) {
        if (ELMT(*l, i) > ELMT(*l, j)) {
          int temp = ELMT(*l, i);
          ELMT(*l, i) = ELMT(*l, j);
          ELMT(*l, j) = temp;
        }
      } else {
        if (ELMT(*l, i) < ELMT(*l, j)) {
          int temp = ELMT(*l, i);
          ELMT(*l, i) = ELMT(*l, j);
          ELMT(*l, j) = temp;
        }
      }
    }
  }
}

void insertLast(ListDin *l, ElType val) {
  ELMT(*l, NEFF(*l)) = val;
  NEFF(*l)++;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val) {
  *val = ELMT(*l, NEFF(*l) - 1);
  NEFF(*l)--;
}

void expandList(ListDin *l, int num) {
  CAPACITY(*l) += num;
  BUFFER(*l) = (int*) realloc(BUFFER(*l), CAPACITY(*l)*sizeof(int));
}

void shrinkList(ListDin *l, int num) {
  CAPACITY(*l) -= num;
  BUFFER(*l) = (int*) realloc(BUFFER(*l), CAPACITY(*l)*sizeof(int));
}

void compressList(ListDin *l) {
  CAPACITY(*l) = NEFF(*l);
  BUFFER(*l) = (int*) realloc(BUFFER(*l), CAPACITY(*l)*sizeof(int));
}