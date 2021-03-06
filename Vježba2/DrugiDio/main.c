#include <stdlib.h>
#include <stdio.h>

typedef struct {
    float x;
    float y;
} Tocka;

typedef struct {
    Tocka *vrh;
    int n;
} Polygon;

Polygon *novi_poligon(float *niz_x, float *niz_y, int n) {

    Polygon *my_polygon = (Polygon*)malloc(sizeof(Polygon));

    my_polygon->vrh = (Tocka*)malloc(n * sizeof(Tocka));

    for (int i = 0; i < n; i++) {
        my_polygon->vrh[i].x = niz_x[i];
        my_polygon->vrh[i].y = niz_y[i];
    }

    return my_polygon;
}

Tocka **pozitivni(Polygon *p, int *np) {

    int counter = 0;

    for (int i = 0; i < (p->n); i++) {
        if ((p->vrh[i].x > 0) && (p->vrh[i].y > 0)) counter++;
    }

    Tocka** pt = (Tocka**)malloc(sizeof(Tocka*) * counter);

    for (int i = 0, j = 0; i < (p->n); i++) {
        if ((p->vrh[i].x > 0) && (p->vrh[i].y > 0)) {
            pt[j] = &(p->vrh[i]);
            j++;
        }
    }

    *np = counter;

    return pt;
}

void main() {
    float nizX[] = { 3, 5, -4, 7 };
    float nizY[] = { 5, -4, 3, -1 };

    int n = sizeof(nizX) / sizeof(nizX[0]);
    int np;

    Tocka **my_dot;
    Polygon *my_polygon = novi_poligon(nizX, nizY, n);

    my_polygon->n = n;

    for (int i = 0; i < n; i++) {
        printf("x: %0.2f, y: %0.2f\n", my_polygon->vrh[i].x, my_polygon->vrh[i].y);
    }

    my_dot = pozitivni(my_polygon, &np);
    
    for (int i = 0; i < np; i++) {
        printf("%d \n", my_dot[i]);
    }

    free(my_dot);
    free(my_polygon->vrh);
    free(my_polygon);
}
