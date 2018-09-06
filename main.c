#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "konief.h"

#define Dl_im 20
struct konie {
    char nazwa_konia[Dl_im];
    int pozycja;
};

int main(void) {
    int liczba_koni = 0;
    int i = 0;
    int los;
    int tymcz = 0;
    bool wygrana = false;
    char ch;
    
    puts("Podaj ilość koni:");
    scanf("%d", &liczba_koni);
    
    struct konie Konie[liczba_koni];
    char wczytane[Dl_im];
    
    puts("Podaj imię pierwszego konia:");
    while (scanf("%s", wczytane) == 1 && wczytane[0] != '0' ) {
        strcpy(Konie[i].nazwa_konia, wczytane);
        Konie[i].pozycja = 0;
        i++;
        if(i>=liczba_koni)
        break;
        puts("Podaj imię kolejnego konia:");
    }
    
    while (getchar() != '\n') {
        continue;
    }
    
    srand((unsigned int)time(0));
    printf("META: %d punktów. \n", liczba_koni*5);
    puts("Nastąpi losowanie, kliknij [enter] aby losować.");
    
    while (wygrana == false && (ch=getchar() == '\n')){
        puts("\n");
        for (int k = 0; k<liczba_koni; k++){
        los = rand() % liczba_koni + 1;
        tymcz = los;
        Konie[k].pozycja += los;
        }
        for (int i=0; i<liczba_koni; i++) {
            printf("Koń %d: %s, Punkty: %d \n", i+1, Konie[i].nazwa_konia, Konie[i].pozycja );
        }
        for(int a=0; a<liczba_koni; a++)
        {
            if(Konie[a].pozycja >= (liczba_koni*5))
            {
                printf("Wygrał Koń %d!\n", a+1);
                if (wygrana == true)
                    puts("TO JEST REMIS!");
                else
                wygrana = true;
            }
        }
    }
    return 0;
}
