
// deque.h
// Failas, kuriame pateikti deko funkcijų aprašymai.
// Prieš paleidžiant programą, būtina pakeisti typedef dataType į norimąjį duomenų tipą.

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

// Klaidų kodai:
// 1 - spausdinant deko reikšmes, dekas yra tuščias
// 2 - išimant reikšmę iš deko priekio, dekas yra tuščias
// 3 - išimant reikšmę iš deko galo, dekas yra tuščias
// 4 - bandant sunaikinti deką, dekas jau yra tuščias

#ifndef __FUNC_H_
#define __FUNC_H_

#define MAX_DEQUES 10

//Būtina pakeisti į norimą duomenų tipą.
typedef int dataType;

struct Node {
    dataType data;
    struct Node* next;
    struct Node* previous;
};

void printDeque(struct Node **front, int *error_code, int type);
void createDeque(struct Node **front, struct Node **back);
void insertFront(struct Node **front, struct Node **back, dataType value);
void insertBack(struct Node **front, struct Node **back, dataType value);
dataType popFront(struct Node **front, struct Node **back, int *error_code);
dataType popBack(struct Node **front, struct Node **back, int *error_code);
int checkIfEmpty(struct Node *front);
int checkIfFull();
void deleteDeque(struct Node **front, struct Node **back, int *error_code, bool *is_created);
void errorExecution(int error_code, char *errors[]);

#endif
