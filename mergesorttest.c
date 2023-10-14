#include <stdio.h>
#include <time.h>
int delay = 2;
void merge(int array[], int inicio, int meio, int fim)
{
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int array_esquerda[n1], array_direita[n2];

    // copia conteudo do array original para os subarrays
    for (int i = 0; i < n1; i++)
    {
        array_esquerda[i] = array[inicio + i];
    }

    for (int i = 0; i < n2; i++)
    {
        array_direita[i] = array[meio + 1 + i];
    }
    // Printa array

    printf("Array esquerda: ");
    printf("[ ");

    for (int i = 0; i < n1; i++)
    {
        printf("%d ", array_esquerda[i]);
    }
    printf("]");

    printf("\n\n");

    // Printa array
    printf("Array direita: ");
    printf("[ ");
    for (int i = 0; i < n2; i++)
    {
        printf("%d ", array_direita[i]);
    }
    printf("]");

    printf("\n\n");

    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2)
    {
        sleep(delay);
        printf("%d <= %d? ", array_esquerda[i], array_direita[j]);
        if (array_esquerda[i] <= array_direita[j])
        {
            printf("Sim\n\n");
            sleep(delay);
            printf("array[%d] = array_esquerda[%d]: %d\n\n", k, i, array_esquerda[i]);

            array[k] = array_esquerda[i];
            i++;
        }
        else
        {

            printf("Nao\n\n");
            sleep(delay);
            printf("array[%d] = array_direita[%d]: %d\n\n", k, j, array_direita[j]);

            array[k] = array_direita[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        sleep(delay);
        // enquanto o indice de i for menor que o tamanho do array da esquerda
        printf("Ha apenas elementos restante no array da esquerda, nao ha nada para comparar\n\n");
        sleep(delay);

        printf("array[%d] = array_esquerda[%d]: %d\n\n", k, i, array_esquerda[i]);
        array[k] = array_esquerda[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        sleep(delay);
        // enquanto o indice de j for menor que o tamanho do array da direita
        printf("Ha apenas elemento restante no array da direita, nao ha nada para comparar\n\n");
        sleep(delay);

        printf("array[%d] = array_direita[%d]: %d\n\n", k, i, array_direita[k]);
        sleep(delay);

        array[k] = array_direita[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        printf("- Dividindo o array: inicio=%d, meio=%d, fim=%d -\n\n", inicio, meio, fim);
        sleep(delay);
        printf("[ ");
        for (int i = inicio; i < fim + 1; i++)
        {
            printf("%d ", array[i]);
        }

        printf("]\n\n");

        mergeSort(array, inicio, meio);
        mergeSort(array, meio + 1, fim);

        printf("- Unindo os subarrays: inicio=%d, meio=%d, fim=%d -\n\n", inicio, meio, fim);
        sleep(delay);
        merge(array, inicio, meio, fim);
    }
}

int main()
{
    int array[] = {6, 5, 4, 3, 2, 1};
    int tamanho_array = sizeof(array) / sizeof(array[0]);

    printf("Array original: ");
    sleep(1);
    printf("[ ");
    for (int i = 0; i < tamanho_array; i++)
    {
        printf("%d ", array[i]);
    }
    printf("]");
    printf("\n\n");

    mergeSort(array, 0, tamanho_array - 1);
    sleep(1);

    printf("Array ordenado: ");
    printf("[ ");

    for (int i = 0; i < tamanho_array; i++)
    {
        printf("%d ", array[i]);
    }
    printf("]");

    printf("\n");

    return 0;
}
