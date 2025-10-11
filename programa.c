#include <stdio.h>

#define NUM_EST 5
#define NUM_ASIG 3

float leer_calificacion(int est, int asig) {
    float x;
    int ok = 0;
    do {
        printf("Ingrese calificación del Estudiante %d - Asignatura %d [0..10]: ", est + 1, asig + 1);
        if (scanf("%f", &x) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Entrada no válida. Intente de nuevo.\n");
            continue;
        }
        if (x < 0.0f || x > 10.0f) {
            printf("La calificación debe estar entre 0 y 10. Intente de nuevo.\n");
        }
        else {
            ok = 1;
        }
    } while (!ok);
    return x;
}

int main(void) {
    float notas[NUM_EST][NUM_ASIG];
    float promEst[NUM_EST] = { 0 };
    float promAsig[NUM_ASIG] = { 0 };
    float minEst[NUM_EST], maxEst[NUM_EST];
    float minAsig[NUM_ASIG], maxAsig[NUM_ASIG];
    int apruebanAsig[NUM_ASIG] = { 0 };
    int repruebanAsig[NUM_ASIG] = { 0 };

    for (int i = 0; i < NUM_EST; i++) {
        for (int j = 0; j < NUM_ASIG; j++) {
            notas[i][j] = leer_calificacion(i, j);
        }
        printf("\n");
    }

    for (int i = 0; i < NUM_EST; i++) {
        minEst[i] = maxEst[i] = notas[i][0];
        for (int j = 0; j < NUM_ASIG; j++) {
            promEst[i] += notas[i][j];
            if (notas[i][j] < minEst[i]) minEst[i] = notas[i][j];
            if (notas[i][j] > maxEst[i]) maxEst[i] = notas[i][j];
        }
        promEst[i] /= NUM_ASIG;
    }

    for (int j = 0; j < NUM_ASIG; j++) {
        minAsig[j] = maxAsig[j] = notas[0][j];
        for (int i = 0; i < NUM_EST; i++) {
            float n = notas[i][j];
            promAsig[j] += n;
            if (n < minAsig[j]) minAsig[j] = n;
            if (n > maxAsig[j]) maxAsig[j] = n;
            if (n >= 6.0f) apruebanAsig[j]++;
            else repruebanAsig[j]++;
        }
        promAsig[j] /= NUM_EST;
    }

    printf("\nPromedio de calificaciones por estudiante:\n");
    for (int i = 0; i < NUM_EST; i++) {
        printf("Estudiante %d: %.2f\n", i + 1, promEst[i]);
    }

    printf("\nPromedio de calificaciones por asignatura:\n");
    for (int j = 0; j < NUM_ASIG; j++) {
        printf("Asignatura %d: %.2f\n", j + 1, promAsig[j]);
    }

    printf("\nCalificación más alta y más baja por estudiante:\n");
    for (int i = 0; i < NUM_EST; i++) {
        printf("Estudiante %d -> Mínimo: %.2f | Máximo: %.2f\n", i + 1, minEst[i], maxEst[i]);
    }

    printf("\nCalificación más alta y más baja por asignatura:\n");
    for (int j = 0; j < NUM_ASIG; j++) {
        printf("Asignatura %d -> Mínimo: %.2f | Máximo: %.2f\n", j + 1, minAsig[j], maxAsig[j]);
    }

    printf("\nCantidad de aprobados y reprobados por asignatura (nota >= 6):\n");
    for (int j = 0; j < NUM_ASIG; j++) {
        printf("Asignatura %d -> Aprobados: %d | Reprobados: %d\n", j + 1, apruebanAsig[j], repruebanAsig[j]);
    }

    printf("\nPresione cualquier tecla para salir...");
    getchar(); getchar();
    return 0;
}
