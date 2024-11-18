#include <stdio.h>
#include "listlinier.h"
#include <stdlib.h>

Address newNode(ElType val) {
  Address New = (Address) malloc(sizeof(Node));

  if (New != NULL) {
    INFO(New) = val;
    NEXT(New) = NULL;
  }

  return New;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
  FIRST(*l) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l) {
  return FIRST(l) == NULL;
}
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx) {
  for (int i = 0; i < idx; i++) {
    l = NEXT(l);
  }
  return INFO(l);
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, ElType val) {
  List p = *l;
  for (int i = 0; i < idx; i++) {
    p = NEXT(p);
  }
  INFO(p) = val;
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(List l, ElType val) {
  int idx = 0;
  while (l != NULL) {
    if (INFO(l) == val) return idx;
    idx++;
    l = NEXT(l); 
  }
  return IDX_UNDEF;
}
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val) {
  if (isEmpty(*l)) {
    Address newnode = newNode(val);
    FIRST(*l) = newnode;
  }
  else {
    Address newnode = newNode(val);
    NEXT(newnode) = *l;
    FIRST(*l) = newnode;
  }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(List *l, ElType val) {
  if (isEmpty(*l)) {
    Address newnode = newNode(val);
    FIRST(*l) = newnode;
  }
  else {
    Address p = *l;
    Address newnode = newNode(val);
    while (NEXT(p) != NULL) {
      p = NEXT(p);
    }
    NEXT(p) = newnode;
  }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(List *l, ElType val, int idx) {
  if (idx == 0) {
    insertFirst(l, val);
    return;
  }

  Address newnode = newNode(val);

  List p = *l;
  for (int i = 0; i < idx - 1; i++) {
    p = NEXT(p);
  }

  Address nextnode = NEXT(p);
  NEXT(newnode) = nextnode;
  NEXT(p) = newnode;
}
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val) {
  List temp = *l;
  *val = INFO(*l);
  *l = NEXT(*l);
  free(temp);
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, ElType *val) {
  int len = length(*l);
  if (len == 1) {
    *val = INFO(*l);
    CreateList(l);
  }
  else {
    Address newLast;
    List p = *l;
    for (int i = 0; i < len - 2; i++) {
      p = NEXT(p);
    }
    *val = INFO(NEXT(p));
    free(NEXT(p));
    NEXT(p) = NULL;
  }
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List *l, int idx, ElType *val) {
  int len = length(*l);
  if (len == 1) {
    *val = INFO(*l);
    CreateList(l);
  }
  else {
    if (idx == 0) {
      deleteFirst(l, val);
      return;
    }

    List p = *l;
    for (int i = 0; i < idx - 1; i++) {
      p = NEXT(p);
    }

    *val = INFO(NEXT(p));
    NEXT(p) = NEXT(NEXT(p));
  }
}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l) {
  printf("[");
  boolean first = true;

  while (l != NULL) {
    if (first) printf("%d", INFO(l));
    else printf(",%d", INFO(l));
    
    l = NEXT(l);
    first = false;
  }

  printf("]\n");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(List l) {
  if (isEmpty(l)) return 0;
  
  int len = 0;
  while (l != NULL) {
    len++;
    l = NEXT(l);
  }

  return len;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
  List l3;
  CreateList(&l3);

  for (int i = 0; i < length(l1); i++) {
    insertLast(&l3, getElmt(l1, i));
  }
  for (int i = 0; i < length(l2); i++) {
    insertLast(&l3, getElmt(l2, i));
  }
  return l3;
}
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */

/*

int main() {
  List(l);
  CreateList(&l);

  displayList(l);

  insertFirst(&l, 10);
  displayList(l);
  insertLast(&l, 5);
  insertLast(&l, 6);
  insertFirst(&l, 3);
  insertLast(&l, 8);
  insertFirst(&l, 1);
  insertFirst(&l, 0);
  displayList(l);
  insertLast(&l, 9);
  displayList(l);

  printf("%d\n", indexOf(l, 0));
  printf("%d\n", indexOf(l, 1));
  printf("%d\n", indexOf(l, 2));
  printf("%d\n", indexOf(l, 9));
  printf("%d\n", indexOf(l, 199));

  int dump;
  deleteLast(&l, &dump);
  displayList(l);
  printf("%d\n", dump);
  deleteAt(&l, 2, &dump);
  displayList(l);
  printf("%d\n", dump);

  insertAt(&l, 69, 0);
  displayList(l);
  deleteAt(&l, 0, &dump);
  displayList(l);
  printf("%d\n", dump);
  deleteAt(&l, 5, &dump);
  displayList(l);
  printf("%d\n", dump);
  printf("%d\n", indexOf(l, 6));
}


*/