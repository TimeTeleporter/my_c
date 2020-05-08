#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char name[32];
    int dim;
    float component[3];
} Vector3D;

void vec3D__init__(Vector3D*, char*);
void vec3Dscan(Vector3D*);
void vec3Dprint(Vector3D);
float scalarproduct(Vector3D, Vector3D);
void crossproduct(Vector3D, Vector3D, Vector3D*);

int main() {
    /* Input */
    Vector3D v1;
    vec3D__init__(&v1, "v1");
    printf("Enter the components of the first vector:\n");
    vec3Dscan(&v1);
    vec3Dprint(v1);
    
    Vector3D v2;
    vec3D__init__(&v2, "v2");
    printf("Enter the components of the second vector:\n");
    vec3Dscan(&v2);
    vec3Dprint(v2);

    /* Logic */
    float scalar = scalarproduct(v1, v2);

    Vector3D cross;
    vec3D__init__(&cross, "v1xv2");
    crossproduct(v1, v2, &cross);

    return 0;
}

void vec3D__init__(Vector3D* ptr, char* name) {
    strcpy(ptr->name, name);
    ptr->dim = 3;
    for(int i = 0; i<ptr->dim; i++) ptr->component[i] = 0;
}

void vec3Dscan(Vector3D* ptr) {
    for(int i = 0; i<ptr->dim; i++) {
        float value = 0;
        scanf("%f", &value);
        ptr->component[i] = value;
    }
}

void vec3Dprint(Vector3D v) {
    printf("%s: (%.2f, %.2f, %.2f)\n", v.name ,v.component[0], v.component[1], v.component[2]);
}

float scalarproduct(Vector3D a, Vector3D b) {
    float sum = 0;
    for(int i = 0; i<a.dim; i++) sum += a.component[i]*b.component[i];
    printf("The scalarproduct of %s and %s is %.2f\n", a.name, b.name, sum);
    return sum;
}

void crossproduct(Vector3D a, Vector3D b, Vector3D* x) {
    for(int i = 0; i<a.dim; i++) x->component[i] = a.component[(i+1)%3]*b.component[(i+2)%3] - b.component[(i+1)%3]*a.component[(i+2)%3];
    printf("The crossproduct of %s and %s is ", a.name, b.name);
    vec3Dprint(*x);
}