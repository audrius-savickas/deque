
// deque.c
// Failas, kuriame pateikti deko funkcijų apibrėžimai.

// Dekas turi 9 funkcijų:
// 1 - tuščio deko sukurimas
// 2 - deko atspausdinimas
// 3 - reikšmės pridėjimas į deko priekį
// 4 - reikšmės pridėjimas į deko galą
// 5 - reikšmės išėmimas iš deko priekio
// 6 - reikšmės išėmimas iš deko galo
// 7 - patikrinimas ar dekas tuščias
// 8 - patikrinimas ar dekas pilnas
// 9 - deko sunaikinimas
//
// Virš kiekvienos funkcijos parašyta, ką ta funkcija daro, ką grąžina ir ką pakeičia.


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "deque.h"

// 1 - tuščio deko sukurimas
// Funkcija, gavusi deko pradžios ir pabaigos rodyklių rodykles, nustato pradžios ir galo rodykles į NULL
void createDeque(struct Node **front, struct Node **back) {
    *front = NULL;
    *back = NULL;
    return;
}


// 2 - deko išspausdinimas
// 
// Funkcija, gavusi deko pradžios rodyklės rodyklę ir kintamojo error_code rodyklę,
// patikrina kokį duomenų tipą vartotojas pasirinko 
// ir spausdina deko elementus nuo pradžios iki galo, iki kol prieina NULL adresą.
//
// Jeigu deko pradžia yra NULL, pakeičia error_code į 1 ir grįžta iš funkcijos
void printDeque(struct Node **front, int *error_code, int type) {
    if (*front == NULL) {
        (*error_code) = 1;
        return;
    }

    struct Node* current;
    current = *front;
    printf("Dekas: ");
    while (current != NULL) {
        if (type == 1) {
            printf("%d ", current->data);
        }
        else {
            printf("%f ", current->data);
        }
        current = current->next;
    }
    printf("\n");
    return;
}


// 3 - reikšmės pridėjimas į deko priekį
//
// Funkcija, gavusi pradžios ir galo rodyklių rodykles, sukuria vieną struct Node elementą,
// nustato to elemento data į vartotojo pasirinktą reikšmę value, 
// previous į NULL, nustato next į rodyklės front rodantį elementą, 
// pakeičia front elemento previous į naują sukurtą elementą ir pakeičia front adresą
// į naujai sukurtą elementą.
//
// Jeigu rodyklė front yra NULL, rodyklės front rodamoje vietoje sukurią struct Node elementą,
// nustato to elemento previous ir next į NULL, data į vartotojo pasirinktą reikšmę value,
// pakeičia back rodyklės reikšmę į front ir grįžta iš funkcijos.
void insertFront(struct Node **front, struct Node **back, dataType value) {
    if ((*front) == NULL) {
        (*front) = (struct Node *) malloc (sizeof(struct Node));
        (*front)->data = value;
        (*front)->previous = NULL;
        (*front)->next = NULL;
        (*back) = (*front);
        return;
    }

    struct Node* y = (struct Node *) malloc (sizeof(struct Node));
    y->data = value;
    y->previous = NULL;
    y->next = *front;
    *front = y;

    return;
}


// 4 - reikšmės pridėjimas į deko galą
//
// Funkcija, gavusi pradžios ir galo rodyklių rodykles, sukuria vieną struct Node elementą,
// nustato to elemento data į vartotojo pasirinktą reikšmę value, 
// next į NULL, nustato previous į rodyklės back rodantį elementą, 
// pakeičia back elemento next į naują sukurtą elementą ir pakeičia back adresą
// į naujai sukurtą elementą.
//
// Jeigu rodyklė front yra NULL, rodyklės front rodamoje vietoje sukurią struct Node elementą,
// nustato to elemento previous ir next į NULL, data į vartotojo pasirinktą reikšmę value,
// pakeičia back rodyklės reikšmę į front ir grįžta iš funkcijos.
void insertBack(struct Node **front, struct Node **back, dataType value) {
    if ((*front) == NULL) {
        (*front) = (struct Node *) malloc (sizeof(struct Node));
        (*front)->data = value;
        (*front)->previous = NULL;
        (*front)->next = NULL;
        (*back) = (*front);
        return;
    }

    struct Node* x = (struct Node *) malloc (sizeof(struct Node));
    (*back)->next = x;
    x->data = value;
    x->previous = *back;
    x->next = NULL;
    *back = x;

    return;
}

// 5 - reikšmės išėmimas iš deko priekio
//
// Funkcija, gavusi deko front ir back rodyklių rodykles ir kintamojo error_code rodyklę,
// sukuria dataType value, į kurį įdeda deko priekyje esančią reikšmę. 
// Jeigu deko elementų daugiau nei vienas, front rodyklę pakeičia į 
// front elemento next esančio elemento adresą, atlaisvina atmintį buvusioje front atminties vietoje ir
// nustato front rodyklės previous į NULL ir grąžina dataType value. 
// Jeigu deko elementas vienintelis, atlaisvina atmintį front atminties vietoje, nustato front ir back
// rodykles į NULL ir grąžina dataType value.
// 
// Jeigu dekas yra tuščias, funkcija nustato error_code į 2 ir grąžina iš funkcijos 0.
dataType popFront(struct Node **front, struct Node **back, int *error_code) {
    if ((*front) == NULL) {
        (*error_code) = 2;
        return 0;
    }
    dataType value = (*front)->data;
    if ((*front)->next != NULL) {
        (*front) = (*front)->next;
        free((*front)->previous);
        (*front)->previous = NULL;
    }
    else {
        free(*front);
        *front = NULL;
        *back = NULL;
    }
    return value;
}

// 6 - reikšmės išėmimas iš deko galo
//
// Funkcija, gavusi deko front ir back rodyklių rodykles ir kintamojo error_code rodyklę,
// sukuria dataType value, į kurį įdeda deko gale esančią reikšmę. 
// Jeigu deko elementų daugiau nei vienas, back rodyklę pakeičia į 
// back elemento previous esančio elemento adresą, atlaisvina atmintį buvusioje back atminties vietoje ir
// nustato back rodyklės next į NULL ir grąžina dataType value. 
// Jeigu deko elementas vienintelis, atlaisvina atmintį back atminties vietoje, nustato front ir back
// rodykles į NULL ir grąžina dataType value.
// 
// Jeigu dekas yra tuščias, funkcija nustato error_code į 2 ir grąžina iš funkcijos 0.
dataType popBack(struct Node **front, struct Node **back, int *error_code) {
    if ((*front) == NULL) {
        (*error_code) = 3;
        return 0;
    }
    dataType value = (*back)->data;
    if ((*back)->previous != NULL) {
        (*back) = (*back)->previous;
        free((*back)->next);
        (*back)->next = NULL;
    }
    else {
        free(*back);
        *front = NULL;
        *back = NULL;
    }
    return value;
}

// 7 - patikrinimas ar dekas tuščias
//
// Funkcija, gavusi deko pradžios rodyklę, patikrina ar rodyklė yra NULL, jei taip - grąžina 1
// jei ne - grąžina 0.
int checkIfEmpty(struct Node *front) {
    if (front == NULL) return 1;
    return 0;
}

// 8 - patikrinimas ar dekas tuščias
//
// Funkcija sukuria struct Node* tipo rodyklę, patikrina ar rodyklė yra NULL, jei taip - grąžina 1,
// jei ne - atlaisvina rodyklės rodomą atminties vietą ir grąžina 0.
int checkIfFull() {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    if (temp == NULL) return 1;
    free(temp);
    return 0;
}

// 9 - deko sunaikinimas
//
// Funkcija, gavusi deko priekio ir galo rodyklių rodykles **front ir **back ir rodyklę *error_code,
// eina per visus deko elementus, atlaisvina rodyklės current rodomą atminties vietą ir
// pakeičia current į kitą rodomą elementą iki kol sutinka rodyklę NULL. Tada pakeičia front ir back
// rodykles į NULL.
//
// Jeigu deko pradžios rodyklė rodo į NULL, reiškiasi dekas yra tuščias, nustato error_code į 4
// ir grįžta iš funkcijos.
// Jeigu dekas nėra sukurtas arba jau sunaikintas, error_code nustato į 4 ir grįžta iš funkcijos.
void deleteDeque(struct Node **front, struct Node **back, int *error_code, bool *is_created) {
    if (*is_created == 0) {
        (*error_code) = 4;
        return;
    }
    struct Node* current = *front;
    struct Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *front = NULL;
    *back = NULL;
    (*is_created) = 0;
    return;
}

// Funkcija išspausdina atitinkamą pranešimą pagal error_code kintamąjį
// Klaidų kodai:
// 1 - spausdinant deko reikšmes, dekas yra tuščias
// 2 - išimant reikšmę iš deko priekio, dekas yra tuščias
// 3 - išimant reikšmę iš deko galo, dekas yra tuščias
// 4 - bandant sunaikinti deką, dekas jau yra sunaikintas
void errorExecution(int error_code, char *errors[]) {
    if (error_code == 0) return;
    else if (error_code == 1) {
        printf("%s", errors[0]);
    }
    else if (error_code == 2) {
        printf("%s", errors[1]);
    }
    else if (error_code == 3) {
        printf("%s", errors[2]);
    }
    else if (error_code == 4) {
        printf("%s", errors[3]);
    }
}
