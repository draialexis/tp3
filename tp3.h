//
// Created by draia on 05/02/2021.
//

#ifndef TP3_TP3_H
#define TP3_TP3_H


//ex2
void afficheTab(int tab[], int n) {
    for (int i = 0; i < n; ++i) {
        if (i == n - 1) { printf("%d]\n", tab[i]); }
        else if (i == 0) { printf("[%d, ", tab[i]); }
        else { printf("%d, ", tab[i]); }
    }
}

//ex3
void initClavier(int tab[], int n) {
    printf("\nI N I T I A L I Z I N G   W I T H   K E Y B O A R D\n\n[");
    int input = -1;

    for (int i = 0; i < n; ++i) {
        while (input < 1) {
            printf("Veuillez entrer un entier positif :");
            scanf("%d", &input);
        }
        printf("%d : OK\n", input);
        tab[i] = input;
        input = -1;
    }
}

//ex4
void initRandom(int tab[], int n) {
    printf("\nI N I T I A L I Z I N G   R A N D O M L Y\n\n");

    for (int i = 0; i < n; ++i) {
        tab[i] = rand() % 11;
    }
}

//ex6
int rechercheTab(int x, int tab[], int n) {
    printf("\nS E A R C H I N G   A R R A Y\n\n");
    for (int i = 0; i < n; ++i) {
        if (tab[i] == x) {
            return i;
        }
    }
    return -1;
}

//ex7
int maxTab(int tab[], int n) {
    int max;
    printf("\nS E A R C H I N G   F O R   M A X   I N    A R R A Y\n\n");
    for (int i = 0; i < n; ++i) {
        if (i == 0) { max = tab[i]; }
        if (tab[i] > max) {
            max = tab[i];
        }
    }
    return max;
}

int maxTabPairs(int tab[], int n) {
    int max = 0;
    printf("\nS E A R C H I N G   F O R   E V E N   M A X   I N    A R R A Y\n\n");
    for (int i = 0; i < n; ++i) {
        if (tab[i] > max && tab[i] % 2 == 0) {
            max = tab[i];
        }
    }
    return max;
}

//ex8
int maxPosTabV1(int tab[], int n) {
    printf("\nS E A R C H I N G   F O R   P O S I T I O N   O F   M A X   I N    A R R A Y   V 1\n\n");
    int result;
    result = rechercheTab(maxTab(tab, n), tab, n);
    return result;
}

int maxPosTabV2(int tab[], int n) {
    printf("\nS E A R C H I N G   F O R   P O S I T I O N   O F   M A X   I N    A R R A Y   V 2\n\n");
    int iMax;
    for (int i = 0; i < n; ++i) {
        if (i == 0) { iMax = i; }
        if (tab[i] > tab[iMax]) {
            iMax = i;
        }
    }
    return iMax;
}

//ex9
int echangeDernierTab(int tab[], int n, int p) {
    if (p > n - 1 || p < 0) {
        printf("Indice non valide\n");
        return 0;
    } else {
        afficheTab(tab, n);
        printf("\nS W I T C H I N G   T A B [ %d ]   W I T H   T A B [ %d ]\n\n", p, (n - 1));
        int tmp = tab[p];
        tab[p] = tab[n - 1];
        tab[n - 1] = tmp;
        afficheTab(tab, n);
        return 1;
    }
}

//ex10
void sortByMax(int tab[], int n) {
    printf("\n__________let the sorting begin__________\n");
    int maxPos;
    for (int i = n; i > 1; --i) {
        maxPos = maxPosTabV2(tab, i);
        echangeDernierTab(tab, i, maxPos);
    }
    printf("\n__________result__________\n");
    afficheTab(tab, n);
}

//ex11
void bubbleSort(int tab[], int n) {
    int tmp;
    int flags;
    do {
        flags = 0;
        afficheTab(tab, n);
        printf("___new loop___\n");
        for (int i = 0; i < n - 1; ++i) {
            if (tab[i] > tab[i + 1]) {
                printf("moving %d (tab[%d])\n", tab[i], i);
                afficheTab(tab, n);
                tmp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = tmp;
                ++flags;
                --i;
            }
        }
        if (!flags) {
            printf("no out-of-place element found...\n");
        }
    } while (flags);
    printf("\n__________result__________\n");
    afficheTab(tab, n);
}

//ex12-13
void bubbleSortV2(int tab[], int n) {
    int tmp;
    int flags;
    int loops = 0;
    do {
        flags = 0;
        afficheTab(tab, n);
        printf("___new loop___\n");
        for (int i = 0; i < n - 1 - loops; ++i) {
            if (tab[i] > tab[i + 1]) {
                printf("moving %d (tab[%d])\n", tab[i], i);
                afficheTab(tab, n);
                tmp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = tmp;
                ++flags;
                --i;
            }
        }
        ++loops;
        if (!flags) {
            printf("no out-of-place element found...\n");
        }
    } while (flags);
    printf("\n__________result__________\n");
    afficheTab(tab, n);
}

#endif //TP3_TP3_H
