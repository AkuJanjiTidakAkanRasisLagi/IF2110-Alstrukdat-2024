#include <stdio.h>
#include "mesinkarakter.h"
#include "mesinkata.h"

void cetak_current_word() {
  for (int i = 0; i < currentWord.Length; i++) {
    printf("%c", currentWord.TabWord[i]);
  }
}

int check_seb() {
    if (currentWord.Length == 7 && currentWord.TabWord[0] == 's' && currentWord.TabWord[1] == 'e' && 
        currentWord.TabWord[2] == 'p' && currentWord.TabWord[3] == 'u' && currentWord.TabWord[4] == 'l' && 
        currentWord.TabWord[5] == 'u' && currentWord.TabWord[6] == 'h') 
        return 10; // "sepuluh"
    
    else if (currentWord.Length == 7 && currentWord.TabWord[0] == 's' && currentWord.TabWord[1] == 'e' && 
             currentWord.TabWord[2] == 'b' && currentWord.TabWord[3] == 'e' && currentWord.TabWord[4] == 'l' && 
             currentWord.TabWord[5] == 'a' && currentWord.TabWord[6] == 's') 
        return 11; // "sebelas"
    return -1; // If it doesn't match any number between 10 and 20
}

int check_satuan() {
    if (currentWord.Length == 3 && currentWord.TabWord[0] == 'n' && currentWord.TabWord[1] == 'o' && 
        currentWord.TabWord[2] == 'l') 
        return 0; // "nol"
    
    else if (currentWord.Length == 4 && currentWord.TabWord[0] == 's' && currentWord.TabWord[1] == 'a' && 
             currentWord.TabWord[2] == 't' && currentWord.TabWord[3] == 'u') 
        return 1; // "satu"
    
    else if (currentWord.Length == 3 && currentWord.TabWord[0] == 'd' && currentWord.TabWord[1] == 'u' && 
             currentWord.TabWord[2] == 'a') 
        return 2; // "dua"
    
    else if (currentWord.Length == 4 && currentWord.TabWord[0] == 't' && currentWord.TabWord[1] == 'i' && 
             currentWord.TabWord[2] == 'g' && currentWord.TabWord[3] == 'a') 
        return 3; // "tiga"
    
    else if (currentWord.Length == 5 && currentWord.TabWord[0] == 'e' && currentWord.TabWord[1] == 'm' && 
             currentWord.TabWord[2] == 'p' && currentWord.TabWord[3] == 'a' && currentWord.TabWord[4] == 't') 
        return 4; // "empat"
    
    else if (currentWord.Length == 4 && currentWord.TabWord[0] == 'l' && currentWord.TabWord[1] == 'i' && 
             currentWord.TabWord[2] == 'm' && currentWord.TabWord[3] == 'a') 
        return 5; // "lima"
    
    else if (currentWord.Length == 4 && currentWord.TabWord[0] == 'e' && currentWord.TabWord[1] == 'n' && 
             currentWord.TabWord[2] == 'a' && currentWord.TabWord[3] == 'm') 
        return 6; // "enam"
    
    else if (currentWord.Length == 5 && currentWord.TabWord[0] == 't' && currentWord.TabWord[1] == 'u' && 
             currentWord.TabWord[2] == 'j' && currentWord.TabWord[3] == 'u' && currentWord.TabWord[4] == 'h') 
        return 7; // "tujuh"
    
    else if (currentWord.Length == 7 && currentWord.TabWord[0] == 'd' && currentWord.TabWord[1] == 'e' && 
             currentWord.TabWord[2] == 'l' && currentWord.TabWord[3] == 'a' && currentWord.TabWord[4] == 'p' && 
             currentWord.TabWord[5] == 'a' && currentWord.TabWord[6] == 'n') 
        return 8; // "delapan"
    
    else if (currentWord.Length == 8 && currentWord.TabWord[0] == 's' && currentWord.TabWord[1] == 'e' && 
             currentWord.TabWord[2] == 'm' && currentWord.TabWord[3] == 'b' && currentWord.TabWord[4] == 'i' && 
             currentWord.TabWord[5] == 'l' && currentWord.TabWord[6] == 'a' && currentWord.TabWord[7] == 'n') 
        return 9; // "sembilan"

    return -1; // If it doesn't match any number between 0 and 9
}

int check_puluh() {
  if (currentWord.Length == 5 && currentWord.TabWord[0] == 'p' && currentWord.TabWord[1] == 'u' && 
      currentWord.TabWord[2] == 'l' && currentWord.TabWord[3] == 'u' && currentWord.TabWord[4] == 'h') 
      return 1;
  else return 0;
}

int check_ratus() {
  if (currentWord.Length == 5 && currentWord.TabWord[0] == 'r' && currentWord.TabWord[1] == 'a' && 
      currentWord.TabWord[2] == 't' && currentWord.TabWord[3] == 'u' && currentWord.TabWord[4] == 's') 
      return 1;
  else return 0;
}

int check_seratus() {
  if (currentWord.Length == 7 && currentWord.TabWord[0] == 's' && currentWord.TabWord[1] == 'e' && 
      currentWord.TabWord[2] == 'r' && currentWord.TabWord[3] == 'a' && currentWord.TabWord[4] == 't' && 
      currentWord.TabWord[5] == 'u' && currentWord.TabWord[6] == 's') 
      return 1;
  else return -1;
}

int check_belas() {
  if (currentWord.Length == 5 && currentWord.TabWord[0] == 'b' && currentWord.TabWord[1] == 'e' && 
      currentWord.TabWord[2] == 'l' && currentWord.TabWord[3] == 'a' && currentWord.TabWord[4] == 's') 
      return 1;
  else return 0;
}


int main() {
  STARTWORD();

  boolean first = 1;
  int angka = -1;
  while (!EndWord) {
    int now = 0;

    if (first) first = 0;
    else printf(" ");

    int c;
    if (check_satuan() == -1 && check_seb() == -1 && check_seratus() == -1) {
      cetak_current_word();
    }
    else {
      int x = check_seb();
      if (x != -1) {
        printf("%d", x);
      }
      else if (check_seratus() == 1) {
        now = 100;

        ADVWORD();
        
        c = check_satuan();
        if (c == 0) {
          printf("%d", now);
          continue;
        }
        else if (c >= 1){
          ADVWORD();
          if (check_puluh()) {
            now += c*10;

            ADVWORD();
            c = check_satuan();
            if (c == 0) {
              printf("%d", now);
              continue;
            }
            else if (c >= 1){
              printf("%d", now + c);
            }
            else {
              printf("%d", now);
              continue;
            }
          }
          else if (check_belas()) {
            now += 10;
            now += c;

            printf("%d", now);
          }
          else {
            printf("%d", now + c);
          }
        }
        else if (check_seb() != -1) {
          now += check_seb();

          printf("%d", now);
        }
        else {
          printf("%d", now);
          continue;
        }
      }
      else {
        int c = check_satuan();

        if (c == 0) {
          printf("0");
        }
        else {
          ADVWORD();

          if (check_ratus()) {
            now = c*100;

            ADVWORD();
            c = check_satuan();

            if (c == 0) {
              printf("%d", now);
              continue;
            }
            else if (c >= 1){
              ADVWORD();
              if (check_puluh()) {
                now += c*10;

                ADVWORD();
                c = check_satuan();
                if (c == 0) {
                  printf("%d", now);
                  continue;
                }
                else if (c >= 1){
                  printf("%d", now + c);
                }
                else {
                  printf("%d", now);
                  continue;
                }
              }
              else if (check_belas()) {
                now += 10;
                now += c;

                printf("%d", now);
              }
              else {
                printf("%d", now + c);
              }
            }
            else if (check_seb() != -1) {
              now += check_seb();

              printf("%d", now);
            }
            else {
              printf("%d", now);
              continue;
            }
          }
          else if (check_puluh()){
            now = c*10;

            ADVWORD();
            c = check_satuan();
            if (c == 0) {
              printf("%d", now);
              continue;
            }
            else if (c >= 1){
              printf("%d", now + c);
            }
            else {
              printf("%d", now);
              continue;
            }
          }
          else if (check_belas()) {
            now = 10;
            now += c;

            printf("%d", now);
          }
          else {
            printf("%d", c);
            continue;
          }
        }
      }
    }
    ADVWORD();
  }

  printf("\n");
}