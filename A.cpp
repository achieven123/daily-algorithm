#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#define MAX 500
 
typedef struct {
    int term;
    int coef[MAX];
    int degree[MAX];
} polynomial;
 
polynomial poly_input() {
    polynomial p;
    int input_coef, input_degree;
 
    scanf("%d", &p.term);
 
    for (int i = 0; i < p.term; i++) {
        scanf("%d %d", &input_coef, &input_degree);
 
        p.coef[i] = input_coef;
        p.degree[i] = input_degree;
    }
 
    return p;
}
 
polynomial poly_minus(polynomial a, polynomial b) {
    polynomial c;
 
    int pos_a = 0, pos_b = 0, pos_c = 0;
 
    while (pos_a < a.term && pos_b < b.term) {
        if (a.degree[pos_a] > b.degree[pos_b]) {
            c.coef[pos_c] = a.coef[pos_a];
            c.degree[pos_c] = a.degree[pos_a];
 
            pos_a++;
            pos_c++;
        }
        else if (a.degree[pos_a] == b.degree[pos_b]) {
            c.coef[pos_c] = a.coef[pos_a] - b.coef[pos_b];
            c.degree[pos_c] = a.degree[pos_a];
 
            pos_a++;
            pos_b++;
            pos_c++;
        }
        else {
            c.coef[pos_c] = -b.coef[pos_b];
            c.degree[pos_c] = b.degree[pos_b];
 
            pos_b++;
            pos_c++;
        }
    }
     
    if (pos_b == b.term) {
        for (int i = pos_a; i < a.term; i++) {
            c.coef[pos_c] = a.coef[pos_a];
            c.degree[pos_c] = a.degree[pos_a];
 
            pos_a++;
            pos_c++;
        }
    }
 
    if (pos_a == a.term) {
        for (int i = pos_b; i < b.term; i++) {
            c.coef[pos_c] = -b.coef[pos_b];
            c.degree[pos_c] = b.degree[pos_b];
 
            pos_b++;
            pos_c++;
        }
    }
 
    c.term = pos_c;
 
    //printf("term : %d\n", c.term);
    //for (int i = 0; i < c.term; i++) {
    //  printf("%d %d ", c.coef[i], c.degree[i]);
    //}
    //printf("\n");
 
    return c;
}
 
void poly_output(polynomial p) {
    //printf("term : %d\n", p.term);
    //for (int i = 0; i < p.term; i++) {
    //  printf("%d %d ", p.coef[i], p.degree[i]);
    //}
    //printf("\n");
 
    int count = 0;
 
    for (int i = 0; i < p.term; i++) {
        if (p.coef[i] == 0) continue; // 존재하지 않는 항은 건너뜀
 
        if (p.degree[i] > 0) {
            if (p.coef[i] > 0) {
                if (count != 0) printf("+");
                if (p.coef[i] != 1) printf("%d", p.coef[i]);
            }
 
            if (p.coef[i] < 0) {
                if (p.coef[i] == -1) printf("-");
                if (p.coef[i] != -1) printf("%d", p.coef[i]);
            }
 
            if (p.degree[i] == 1) {
                printf("x");
            }
 
            if (p.degree[i] > 1) {
                printf("x^%d", p.degree[i]);
            }
        }
        else {
            if (p.coef[i] > 0) {
                if (count != 0) printf("+");
                printf("%d", p.coef[i]);
            }
 
            if (p.coef[i] < 0) {
                printf("%d", p.coef[i]);
            }
        }
 
        count++;
    }
 
    if (count != 0) printf("\n");
    else printf("0\n");
}
 
int main() {
    int test_case;
 
    scanf("%d", &test_case);
 
    while (test_case--) {
        polynomial a;
        polynomial b;
        polynomial c;
 
        a = poly_input();
        b = poly_input();
        c = poly_minus(a, b);
        poly_output(c);
    }
 
    return 0;
}
