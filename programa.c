#include <stdio.h>
#include <string.h>

int main()
{
    #define num_estudiantes  5
    #define num_asignaturas  3
    char nombres[num_estudiantes][25];
    char materias[num_asignaturas][25];
    float notas[num_estudiantes][num_asignaturas];
    float promEst[num_estudiantes] = {0};
    float promAsig[num_asignaturas] = {0};
    float minEst[num_estudiantes], maxEst[num_estudiantes];
    float minAsig[num_asignaturas], maxAsig[num_asignaturas];
    int apruebanAsig[num_asignaturas] = {0};
    int repruebanAsig[num_asignaturas] = {0};

    printf("Bienvenido/a al sistema de calificacion\n");
    for (int i = 0; i < num_estudiantes; i++)
    {
        printf("Ingrese el nombre del estudiante %d:\n", i + 1);
        fgets(nombres[i], sizeof(nombres), stdin);
        nombres[i][strcspn(nombres[i], "\n")]='\0';
    }

    for (int i = 0; i < num_asignaturas; i++)
    {
        printf("Ingrese el nombre de la asignatura %d:\n", i + 1);
        fgets(materias[i], sizeof(materias), stdin);
    }

    for (int i = 0; i < num_estudiantes; i++)
    {
        for (int j = 0; j < num_asignaturas; j++)
        {
            float nota;
            int ok = 0;
            do
            {
                printf("Ingrese la calificacion de %s en %s", nombres[i], materias[j]);
                
                scanf("%f", &nota);
                if (nota < 0.0f || nota > 10.0f)
                {
                    printf("La calificacion debe estar entre 0 y 10. Intente de nuevo.\n");
                }
                else
                {
                    ok = 1;
                }
            } while (!ok);

            notas[i][j] = nota;
        }
        printf("\n");
    }

    for (int i = 0; i < num_estudiantes; i++)
    {
        minEst[i] = maxEst[i] = notas[i][0];
        for (int j = 0; j < num_asignaturas; j++)
        {
            promEst[i] += notas[i][j];
            if (notas[i][j] < minEst[i])
                minEst[i] = notas[i][j];
            if (notas[i][j] > maxEst[i])
                maxEst[i] = notas[i][j];
        }
        promEst[i] /= num_asignaturas;
    }

    for (int j = 0; j < num_asignaturas; j++)
    {
        minAsig[j] = maxAsig[j] = notas[0][j];
        for (int i = 0; i < num_estudiantes; i++)
        {
            float n = notas[i][j];
            promAsig[j] += n;
            if (n < minAsig[j])
                minAsig[j] = n;
            if (n > maxAsig[j])
                maxAsig[j] = n;
            if (n >= 6.0f)
                apruebanAsig[j]++;
            else
                repruebanAsig[j]++;
        }
        promAsig[j] /= num_estudiantes;
    }

    printf("\nPromedio de calificaciones por estudiante:\n");
    for (int i = 0; i < num_estudiantes; i++)
    {
        printf("%s: %.2f\n", nombres[i], promEst[i]);
    }

    printf("\nPromedio de calificaciones por asignatura:\n");
    for (int j = 0; j < num_asignaturas; j++)
    {
        printf("%s: %.2f\n", materias[j], promAsig[j]);
    }

    printf("\nCalificacion mas alta y mas baja por estudiante:\n");
    for (int i = 0; i < num_estudiantes; i++)
    {
        printf("%s -> Minimo: %.2f | Maximo: %.2f\n", nombres[i], minEst[i], maxEst[i]);
    }

    printf("\nCalificacion mas alta y mas baja por asignatura:\n");
    for (int j = 0; j < num_asignaturas; j++)
    {
        printf("%s -> Minimo: %.2f | Maximo: %.2f\n", materias[j], minAsig[j], maxAsig[j]);
    }

    printf("\nCantidad de aprobados y reprobados por asignatura (nota >= 6):\n");
    for (int j = 0; j < num_asignaturas; j++)
    {
        printf("%s -> Aprobados: %d | Reprobados: %d\n", materias[j], apruebanAsig[j], repruebanAsig[j]);
    }

    printf("\nPresione cualquier tecla para salir...");
    getchar();
    getchar();
    return 0;
}
