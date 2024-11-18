#include <stdio.h>
#include "liststatik.h"

void CreateListStatik(ListStatik *l) {
   for (int i = 0; i < CAPACITY; i++) {
      ELMT(*l, i) = MARK;
   }
}

int listLength(ListStatik l) {
   int i = 0;
   while (ELMT(l, i) != MARK && i < CAPACITY) {
      i++;
   }
   return i;
}


IdxType getFirstIdx(ListStatik l) {
   return 0;
}

IdxType getLastIdx(ListStatik l) {
   return listLength(l) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i) {
   return 0 <= i && i < CAPACITY;
}

boolean isIdxEff(ListStatik l, IdxType i){
   return 0 <= i && i < listLength(l);
}

/* ********** TEST KOSONG/PENUH ********** */
boolean isEmpty(ListStatik l) {
   return listLength(l) == 0;
}

boolean isFull(ListStatik l) {
   return listLength(l) == CAPACITY;
}

void readList(ListStatik *l) {
   int n;
   scanf("%d", &n);

   while (n < 0 || n > CAPACITY) {
      scanf("%d", &n);
   }

   for (int i = 0; i < n; i++) {
      scanf("%d", &ELMT(*l, i));
   }
   for (int i = n; i < CAPACITY; i++) {
      ELMT(*l, i) = MARK;
   }
}

void printList(ListStatik l) {
   printf("[");
   for (int i = 0; i < listLength(l); i++) {
      printf("%d", ELMT(l, i));
      if (i != listLength(l) - 1) {
         printf(",");
      }
   }
   printf("]");
}

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus) {
   ListStatik l;
   CreateListStatik(&l);

   for (int i = 0; i < listLength(l1); i++) {
      if (plus) {
         ELMT(l, i) = ELMT(l1, i) + ELMT(l2, i);
      } else {
         ELMT(l, i) = ELMT(l1, i) - ELMT(l2, i);
      }
   }

   return l;
}

boolean isListEqual(ListStatik l1, ListStatik l2) {
   if (listLength(l1) != listLength(l2)) {
      return false;
   }

   for (int i = 0; i < CAPACITY; i++) {
      if (ELMT(l1, i) != ELMT(l2, i)) {
         return false;
      }
   }

   return true;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val) {
   for (int i = 0; i < CAPACITY; i++) {
      if (ELMT(l, i) == val) {
         return i;
      }
   }
   return IDX_UNDEF;
}

void extremeValues(ListStatik l, ElType *max, ElType *min) {
   *max = ELMT(l, 0);
   *min = ELMT(l, 0);

   for (int i = 1; i < listLength(l); i++) {
      if (ELMT(l, i) > *max) {
         *max = ELMT(l, i);
      }

      if (ELMT(l, i) < *min) {
         *min = ELMT(l, i);
      }
   }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val) {
   for (int i = listLength(*l); i > 0; i--) {
      ELMT(*l, i) = ELMT(*l, i - 1);
   }
   ELMT(*l, 0) = val;
}


void insertAt(ListStatik *l, ElType val, IdxType idx) {
   for (int i = listLength(*l); i > idx; i--) {
      ELMT(*l, i) = ELMT(*l, i - 1);
   }
   ELMT(*l, idx) = val;
}

void insertLast(ListStatik *l, ElType val) {
   ELMT(*l, listLength(*l)) = val;
}


void deleteFirst(ListStatik *l, ElType *val) {
   *val = ELMT(*l, 0);
   for (int i = 0; i < listLength(*l) - 1; i++) {
      ELMT(*l, i) = ELMT(*l, i + 1);
   }
   ELMT(*l, listLength(*l) - 1) = MARK;
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx) {
   *val = ELMT(*l, idx);
   for (int i = idx; i < listLength(*l) - 1; i++) {
      ELMT(*l, i) = ELMT(*l, i + 1);
   }
   ELMT(*l, listLength(*l) - 1) = MARK;
}

void deleteLast(ListStatik *l, ElType *val) {
   *val = ELMT(*l, listLength(*l) - 1);
   ELMT(*l, listLength(*l) - 1) = MARK;
}

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc) {
   if (asc) {
      for (int i = 0; i < listLength(*l) - 1; i++) {
         for (int j = i + 1; j < listLength(*l); j++) {
            if (ELMT(*l, i) > ELMT(*l, j)) {
               ElType temp = ELMT(*l, i);
               ELMT(*l, i) = ELMT(*l, j);
               ELMT(*l, j) = temp;
            }
         }
      }
   } else {
      for (int i = 0; i < listLength(*l) - 1; i++) {
         for (int j = i + 1; j < listLength(*l); j++) {
            if (ELMT(*l, i) < ELMT(*l, j)) {
               ElType temp = ELMT(*l, i);
               ELMT(*l, i) = ELMT(*l, j);
               ELMT(*l, j) = temp;
            }
         }
      }
   }
}