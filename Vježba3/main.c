#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float x;
    float y;
    float z;
} Tocka;

typedef struct {
    Tocka normala;
    Tocka vrh_a;
    Tocka vrh_b;
    Tocka vrh_c;
    unsigned short broj;
} Trokut;

typedef struct {
    int n;
    Trokut *niz;
} Objekt3D;

Objekt3D *createObjectBin() {
    FILE *fp = fopen("primjerbin.stl", "r");

    if (!fp) perror("No file found!");
    
    fseek(fp, 80, SEEK_SET);

    Objekt3D *object = (Objekt3D*)malloc(sizeof(Objekt3D));

    int n = 0;

    fread(&n, sizeof(int), 1, fp);

    object->n = n;

    Trokut *tmp = (Trokut*)malloc(object->n*sizeof(Trokut));

    for (int i = 0; i < (object->n); i++) {
        fread(&(tmp[i]), 50, 1, fp);
    }

    object->niz = tmp;

    fclose(fp);

    return object;
}

void createTxtFile(Objekt3D *object) {
    FILE *fp = fopen("objektobject.stl", "wt");

    fprintf(fp, "solid \n");

    for (int i = 0; i < (object->n); i++) {
        fprintf(fp, "facet normal %f %f %f\n", object->niz[i].normala.x, object->niz[i].normala.y, object->niz[i].normala.z);
        fprintf(fp, "outer loop\n");
        fprintf(fp, "vertex %f %f %f\n", object->niz[i].vrh_a.x, object->niz[i].vrh_a.y, object->niz[i].vrh_a.z);
        fprintf(fp, "vertex %f %f %f\n", object->niz[i].vrh_b.x, object->niz[i].vrh_b.y, object->niz[i].vrh_b.z);
        fprintf(fp, "vertex %f %f %f\n", object->niz[i].vrh_c.x, object->niz[i].vrh_c.y, object->niz[i].vrh_c.z);
        fprintf(fp, "endloop\n");
        fprintf(fp, "endfacet\n");
    }

    fclose(fp);
}

void createBinFile(Objekt3D *object) {
    FILE *fp = fopen("objektbin.stl", "wb");

    char header[80] = { 0 };

    fwrite(header, sizeof(char), 80, fp);
    fwrite(&(object->n), sizeof(int), 1, fp);

    for (int i = 0; i < object->n; i++) {
        fwrite(&(object->niz[i]), 50, 1, fp);
    }

    fclose(fp);
}

void deleteObject(Objekt3D *object) {
    free(object);
}

int main(void) {

    Objekt3D *object_1 = createObjectBin();

    createBinFile(object_1);
    createTxtFile(object_1);
    deleteObject(object_1);

    return 0;
}
