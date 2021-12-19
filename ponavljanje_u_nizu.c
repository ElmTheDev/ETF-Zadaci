/**
 * @file ponavljanje_u_nizu.c
 * @author Elmedin Turkeš (elmedin@parallaxis.solutions)
 * @brief Program koji provjerava da li je neki broj u nizu ponavljan tačno jednom.
 * @version 0.1
 * @date 2021-12-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/*
    Korisnik najprije unosi broj N koji predstavlja broj članova niza (najviše 100), pri čemu je do-while petljom osigurano da je ovaj broj u opsegu koji ima smisla. Zatim se unose realni brojevi koji su članovi niza.

    Program treba ispisati DA ako se svaki član niza ponavlja tačno jednom (ukupno se javlja dvaput u nizu), a u suprotnom treba ispisati NE. (Za poređenje nije potrebno koristiti epsilon.)

    Primjeri:


    Unesite broj clanova niza: 6
    Unesite niz: 1.1 2.2 3.3 3.3 2.2 1.1
    DA
    Unesite broj clanova niza: 5
    Unesite niz: 0.1 0.2 0.1 0.2 0.1
    NE
    Napomena: Rješenje koje uvijek ispisuje DA ili NE ili hardcodira rješenja (npr. ako je niz jednak nekom iz autotesta uvijek ispisuje DA ili NE) biće bodovana sa 0 bodova bez obzira na potencijalno ispravne dijelove koda!
*/

#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;

    // Unos pomoću do-while petlje
    // Provjerava se da li je uneseni broj manji od 0 ili veći od 100
    // U slučaju da jeste ponavlja se unos
    do {
        printf("Unesite broj clanova niza: ");
        scanf("%d", &n);
        if(n < 1 || n > 100) {
            printf("Broj clanova niza mora biti u opsegu [1, 100]!\n");
        }

    } while(n < 1 || n > 100);

    if(n < 2) {
        printf("NE\n");
        return 0;
    }
    
    
    float niz[100];
    int i, j;

    printf("Unesite niz: ", i);
    for(i = 0; i < n; i++) {
        scanf("%f", &niz[i]);
    }
    
    // Provjera ponavljanja
    for(i = 0; i < n; i++) {
        bool daLiSePonavlja = false;

        // Prođi kroz svaki element niza
        for(j = 0; j < n; j++) {
            // Ako je trenutni element u nizu jednak traženom elementu i ako njegova lokacija u nizu nije jednaka trenutnoj lokaciji u nizu
            if(i != j && niz[i] == niz[j]) {
                // Postavi da se ponavlja, ako nije već postavljeno, ukoliko se ponavlja više puta ispisati NE jer uslov zadatka nije zadovoljen
                // Ukoliko se ponavlja samo jednom nastaviti sa izvržavanjem koda
                if(daLiSePonavlja) {
                    printf("NE\n");
                    return 0;
                } else {
                    daLiSePonavlja = true;
                }
            }
        }

        if(!daLiSePonavlja) {
            printf("NE\n");
            return 0;
        }
    }

    // Ako ni jedan element nije imao grešku ispisati DA
    printf("DA\n");

    return 0;
}
