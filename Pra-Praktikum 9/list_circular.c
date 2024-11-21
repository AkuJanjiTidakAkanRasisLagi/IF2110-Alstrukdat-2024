#include "list_circular.h"
#include <stdio.h>
#include <stdlib.h>

boolean isEmpty(List l) {
  return FIRST(l) == NULL;
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
  FIRST(*l) = NULL;
}
/* I.S. l sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
Address allocate(ElType val) {
  Address p = (Address) malloc(sizeof(ElmtList));
  if (p != NULL) {
    INFO(p) = val;
    NEXT(p) = NULL;
  } 

  return p;
}
/* Mengirimkan Address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
/* menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */

void deallocate(Address P) {
  free(P);
  P = NULL;
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val) {
  Address p = FIRST(l);
  if (p != NULL) {
    do {
      if (INFO(p) == val) {
        return p;
      }
      p = NEXT(p);
    } while (p != FIRST(l));
  }
  return NULL;
}
/* Mencari apakah ada elemen list dengan INFO(P)= val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */

boolean addrSearch(List l, Address p) {
  Address pl = FIRST(l);
  if (pl != NULL) {
    do {
      if (pl == p) {
        return true;
      }
      pl = NEXT(pl);
    } while (pl != FIRST(l));
  }
  return false;
}
/* Mencari apakah ada elemen list l yang beralamat p */
/* Mengirimkan true jika ada, false jika tidak ada */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val) {
  Address p = allocate(val);
  if (p != NULL) {
    if (isEmpty(*l)) {
      FIRST(*l) = p;
      NEXT(p) = p;
    } else {
      Address last = FIRST(*l);
      while (NEXT(last) != FIRST(*l)) {
        last = NEXT(last);
      }
      NEXT(p) = FIRST(*l);
      NEXT(last) = p;
      FIRST(*l) = p;
    }
  }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
void insertLast(List *l, ElType val) {
  Address p = allocate(val);
  if (p != NULL) {
    if (isEmpty(*l)) {
      FIRST(*l) = p;
      NEXT(p) = p;
    }
    else {
      Address last = FIRST(*l);
      while (NEXT(last) != FIRST(*l)) {
        last = NEXT(last);
      }

      NEXT(last) = p;
      NEXT(p) = FIRST(*l);
    }
  }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType * val) {
  Address first = FIRST(*l);
  Address last = FIRST(*l);
  Address second = NEXT(first);

  if (NEXT(first) == first) {
    *val = INFO(FIRST(*l));
    deallocate(FIRST(*l));
    FIRST(*l) = NULL;

    return;
  }

  while (NEXT(last) != FIRST(*l)) {
    last = NEXT(last);
  }

  NEXT(last) = second;
  FIRST(*l) = second;
  *val = INFO(first);

  deallocate(first);
}
/* I.S. List l tidak kosong  */
/* F.S. val adalah elemen pertama list l sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      First element yg baru adalah suksesor elemen pertama yang lama */
/*      Alamat elemen terakhir di-dealokasi */
void deleteLast(List *l, ElType * val) {
  Address first = FIRST(*l);
  Address last = FIRST(*l);
  Address beforeLast = NULL;

  if (NEXT(first) == first) {
    *val = INFO(FIRST(*l));
    deallocate(FIRST(*l));
    FIRST(*l) = NULL;
    
    return;
  }

  while (NEXT(last) != FIRST(*l)) {
    beforeLast = last;
    last = NEXT(last);
  }

  NEXT(beforeLast) = first;
  *val = INFO(last);

  deallocate(last);
}
/* I.S. list tidak kosong */
/* F.S. x adalah elemen terakhir list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      Last element baru adalah predesesor elemen pertama yg lama, jika ada */
/*      Alamat elemen terakhir di-dealokasi */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l) {
  Address p = FIRST(l);
  if (p != NULL) {
    printf("[");
    do {
      printf("%d", INFO(p));
      p = NEXT(p);
      if (p != FIRST(l)) {
        printf(",");
      }
    } while (p != FIRST(l));
    printf("]");
  } else {
    printf("[]");
  }
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

// int main() {
//   List l;
//   CreateList(&l);
//   displayList(l);
//   printf("\n");

//   insertFirst(&l, 1);
//   displayList(l);
//   printf("\n");

//   insertFirst(&l, 2);
//   displayList(l);
//   printf("\n");

//   insertLast(&l, 3);
//   displayList(l);
//   printf("\n");

//   insertLast(&l, 4);
//   displayList(l);
//   printf("\n");

//   ElType val;
//   deleteFirst(&l, &val);
//   displayList(l);
//   printf("\n");

//   deleteLast(&l, &val);
//   displayList(l);
//   printf("\n");

//   deleteFirst(&l, &val);
//   displayList(l);
//   printf("\n");

//   deleteLast(&l, &val);
//   displayList(l);
//   printf("\n");

//   return 0;
// }