
// Audrius Savickas 4 grupė 2 pogrupis
// audrius.savickas@mif.stud.vu.lt

// Tai yra programa, kuri realizuoja ADT - deką
// Prieš paleidžiant programą, deque.h faile pakeiskite typedef į norimą duomenų tipą - int arba float

// Programos paleidimas:
// make
// .\main

// Programa turi 10 funkcijų:
// 1 - tuščio deko sukurimas, nurodant duomenų tipą
// 2 - deko atspausdinimas
// 3 - reikšmės pridėjimas į deko priekį
// 4 - reikšmės pridėjimas į deko galą
// 5 - reikšmės išėmimas iš deko priekio
// 6 - reikšmės išėmimas iš deko galo
// 7 - patikrinimas, ar dekas tuščias
// 8 - patikrinimas, ar dekas pilnas
// 9 - deko sunaikinimas
// 10 - programos baigimas

// Kintamųjų paaiškinimai:
// define MAX_DEQUES - skaičius, nurodantis kiek skirtingų dekų galima sukurti
// struct Deques - struktūra, skirta laikyti deko priekio ir galo rodyklėms
// struct Deques deques - struktūrų masyvas, skirtas laikyti dekams
// int error_code - kintamasis, skirtas laikyti error kodams, kurį pakeičia funkcijos, jeigu įvyksta klaida
// int choice - kintamasis, skirtas laikyti vartotojo pasirinkimui
// int type - kintamasis, skirtas laikyti duomenu tipo pasirinkimui: 1 - int, 2 - float
// dataType value - kintamasis, skirtas laikyti vartotojo įdedamai/išemamai reikšmei
// int number_of_deques - kintamasis, skirtas laikyti sukurtų dekų skaičiui
// int which_deque - kintamasis, skirtas laikyti vartotojo pasirinkto deko indeksui nuo 1 iki number_of_deques

// Klaidų kodai:
// 1 - spausdinant deko reikšmes, dekas yra tuščias
// 2 - išimant reikšmę iš deko priekio, dekas yra tuščias
// 3 - išimant reikšmę iš deko galo, dekas yra tuščias
// 4 - bandant sunaikinti deką, dekas jau yra sunaikintas

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "deque.h"

struct Deques {
    struct Node* front;
    struct Node* back;
};

int main () {
    struct Deques deques[MAX_DEQUES];
    bool is_created[MAX_DEQUES] = {0};
    int error_code = 0;
    int choice = -1;
    int type = 0;
    dataType value;
    int number_of_deques = 0;
    int which_deque = 0;
    char *errors[] = {"KLAIDA 1: Nepavyko atspausdinti deko: dekas yra tuscias.\n", 
        "KLAIDA 2: Nepavyko isimti reiksmes is deko priekio: dekas yra tuscias.\n", 
        "KLAIDA 3: Nepavyko isimti reiksmes is deko galo: dekas yra tuscias.\n", 
        "KLAIDA 4: Nepavyko sunaikinti deko: dekas jau yra sunaikintas.\n"};

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PROGRAMOS APRASYMAS:\n\n\n");
    printf("Audrius Savickas 4gr.\n\n");
    printf("Programa realizuoja deko duomenu tipa.\n");
    printf("Pries paleidziant programa reikia \"deque.h\" faile pakeisti typedef i norima duomenu tipa int arba float.\n\n");
    printf("Programa susideda is 3 daliu:\n");
    printf("main.c - testavimo aplinka ir interfeisas dekui.\n");
    printf("deque.h - deko duomenu tipo funkciju aprasymai.\n");
    printf("deque.c - deko duomenu tipo funciju apibrezimai.\n\n");
    printf("Testavimo aplinka turi sias funkcijas:\n");
    printf("1 - deko sukurimas\n");
    printf("2 - deko atspausdinimas\n");
    printf("3 - reiksmes pridejimas i deko prieki\n");
    printf("4 - reiksmes pridejimas i deko gala\n");
    printf("5 - reiksmes isemimas is deko priekio\n");
    printf("6 - reiksmes isemimas is deko priekio\n");
    printf("7 - patikrinimas, ar dekas tuscias\n");
    printf("8 - patikrinimas, ar dekas pilnas\n");
    printf("9 - deko sunaikinimas\n");
    printf("10 - programos baigimas\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nTESTAVIMAS:\n\n\n");
    printf("Kokio duomenu tipo deko noretumete?:\n");
    printf("1 - int\n");
    printf("2 - float\n");
    while ((scanf("%d", &type) != 1 && getchar() != '\n') || (type != 1 && type != 2)) {
        printf("Netinkamas pasirinkimas, pasirinkite dar karta.\n");
    }
    printf("\n");

    while (choice != 10) {
        error_code = 0;
        printf("Ka norite daryti?:\n");
        printf("1 - sukurti deka\n");
        printf("2 - atspausdinti deka\n");
        printf("3 - prideti reiksme i deko prieki\n");
        printf("4 - prideti reiksme i deko gala\n");
        printf("5 - isimti reiksme is deko priekio\n");
        printf("6 - isimti reiksme is deko galo\n");
        printf("7 - patikrinti ar dekas tuscias\n");
        printf("8 - patikrinti ar dekas pilnas\n");
        printf("9 - sunaikinti deka\n");
        printf("10 - baigti programa\n");
        scanf("%d", &choice);

        if (choice < 1 || choice > 10) {
            printf("Nera tokio pasirinkimo. Bandykite dar karta.\n\n");
        }
        else if (choice == 10) {
            return 0;
        }
        else if (choice == 1) {
            if (number_of_deques == MAX_DEQUES){
                printf("Pasiekete maksimalu deku skaiciu. Negalima sukurti deko.\n\n");
            }
            else {
                createDeque(&(deques[number_of_deques].front), &(deques[number_of_deques].back));
                is_created[number_of_deques] = 1;
                number_of_deques++;
                printf("\n");
            }
            continue;
        }

        printf("Kuriam dekui? ");
        while (scanf("%d", &which_deque) != 1 || which_deque < 1 || which_deque > number_of_deques) {
            printf("Tokio deko nera. Bandykite dar karta. ");
        }
        which_deque--;

        if (choice == 2) {
            printDeque(&(deques[which_deque].front), &error_code, type);
        }
        else if (choice == 3) {
            printf("Kokia reiksme norite prideti? ");
            if (type == 1) {
                while (scanf("%d", &value) != 1 && getchar() != '\n') {
                    printf("Netinkamas skaiciaus formatas, irasykite reiksme dar karta.\n");
                    scanf("%*[^\n]");
                }
            }
            else {
                while (scanf("%f", &value) != 1 && getchar() != '\n') {
                    printf("Netinkamas skaiciaus formatas, irasykite reiksme dar karta.\n");
                    scanf("%*[^\n]");
                }
            }
            insertFront(&(deques[which_deque].front), &(deques[which_deque].back), value);
        }
        else if (choice == 4) {
            printf("Kokia reiksme norite prideti? ");
            if (type == 1) {
                while (scanf("%d", &value) != 1 && getchar() != '\n') {
                    printf("Netinkamas skaiciaus formatas, irasykite reiksme dar karta.\n");
                    scanf("%*[^\n]");
                }
                insertBack(&(deques[which_deque].front), &(deques[which_deque].back), value);
            }
            else {
                while (scanf("%f", &value) != 1 && getchar() != '\n') {
                    printf("Netinkamas skaiciaus formatas, irasykite reiksme dar karta.\n");
                    scanf("%*[^\n]");
                }
                insertBack(&(deques[which_deque].front), &(deques[which_deque].back), value);
            }
        }
        else if (choice == 5) {
            if (type == 1) {
                value = popFront(&(deques[which_deque].front), &(deques[which_deque].back), &error_code);
                if (error_code != 2) {
                    printf("Isimta reiksme yra: %d\n", value);
                }
            }
            else {
                value = popFront(&(deques[which_deque].front), &(deques[which_deque].back), &error_code);
                if (error_code != 2) {
                    printf("Isimta reiksme yra: %f\n", value);
                }
            }
        }
        else if (choice == 6) {
            if (type == 1) {
                value = popBack(&(deques[which_deque].front), &(deques[which_deque].back), &error_code);
                if (error_code != 3) {
                    printf("Isimta reiksme yra: %d\n", value);
                }
            }
            else {
                value = popBack(&(deques[which_deque].front), &(deques[which_deque].back), &error_code);
                if (error_code != 3) {
                    printf("Isimta reiksme yra: %f\n", value);
                }
            }
        }
        else if (choice == 7) {
            if (checkIfEmpty(deques[which_deque].front) == 1) printf("Dekas yra tuscias.\n");
            else printf("Dekas nera tuscias.\n");
        }
        else if (choice == 8) {
            if (checkIfFull() == 1) printf("Dekas yra pilnas.\n");
            else printf("Dekas nera pilnas.\n");
        }
        else if (choice == 9) {
            deleteDeque(&(deques[which_deque].front), &(deques[which_deque].back), &error_code, &(is_created[which_deque]));
        }
        errorExecution(error_code, errors);
        printf("\n");
    }
}
