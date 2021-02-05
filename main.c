#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tp3.h"

#define N 15
#define M 7
#define L 12


int main() {
    srand(time(NULL));

    int t1[N] = {1};
    int t2[M] = {1};
    int t3[L] = {1};
    initRandom(t1, N);
    afficheTab(t1, N);
    initRandom(t2, M);
    afficheTab(t2, M);
    initRandom(t3, L);
    afficheTab(t3, L);

    printf("7 est dans t1? %d\n", rechercheTab(7, t1, N));
    printf("7 est dans t2? %d\n", rechercheTab(7, t2, M));

    printf("MAX dans t2? %d\n", maxTab(t2, M));
    printf("MAX PAIR dans t2? %d\n", maxTabPairs(t2, M));

    printf("MAX POS dans t2? %d\n", maxPosTabV1(t2, M));
    printf("MAX POS dans t1? %d\n", maxPosTabV2(t1, N));

    echangeDernierTab(t1, N, (rand() % 31));
    echangeDernierTab(t2, M, (rand() % 15));

    sortByMax(t1, N);
    bubbleSort(t2, M);
    bubbleSortV2(t3, L);

    return 0;
}