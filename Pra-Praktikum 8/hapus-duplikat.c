#include "listlinier.h"
#include <stdio.h>

List hapusDuplikat(List L) {
  int len = length(L);
  List p1 = L;

  List l;
  CreateList(&l);
  for (int i = 0; i < len; i++) {
    insertFirst(&l, INFO(p1));
    p1 = NEXT(p1);
  }

  List ret;
  CreateList(&ret);
  
  p1 = l;
  int idx = 0;
  while (p1 != NULL) {
    boolean shift = false;
    while (NEXT(p1) != NULL && INFO(p1) == INFO(NEXT(p1))) {
      p1 = NEXT(p1);
      shift = true;
    }
    if (shift) p1 = NEXT(p1);
    else if (p1 != NULL) {
      insertLast(&ret, INFO(p1));
      p1 = NEXT(p1);
    }
  }

  return ret;
}

/*
int main() {
  List X;
  CreateList(&X);

  insertLast(&X, 0);
  insertLast(&X, 0);
  insertLast(&X, 0);
  insertLast(&X, 1);
  insertLast(&X, 3);
  insertLast(&X, 3);
  insertLast(&X, 4);
  insertLast(&X, 4);
  insertLast(&X, 5);
  insertLast(&X, 6);
  insertLast(&X, 9);
  displayList(X);

  List Y = hapusDuplikat(X);
  displayList(Y);
}
*/