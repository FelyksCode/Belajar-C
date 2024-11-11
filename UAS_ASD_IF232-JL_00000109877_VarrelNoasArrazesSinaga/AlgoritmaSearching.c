#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Film
{
    char judul[50];
    char director[100];
    char genre[20];
    char tipe[20];
    int release;
    int episode;
} Film;

int binarySearchFilm(Film *film, int size, char *judul)
{
    int low, mid, high;

    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (strcmp(film[mid].judul, judul) == 0)
        {
            return mid;
        }
        else if (strcmp(film[mid].judul, judul) < 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int interpolationSearchbeta(Film *film, int size, char *judul)
{
    int low, pos, high, check;
    low = 0;
    int test;
    high = size - 1;
    printf("\nsizeof arr = %d\n", high);
    do
    {

        pos = (strcmp(judul, film[low].judul) * (high - low) / strcmp(film[high].judul, film[low].judul)) + low;
        if (strcmp(film[pos].judul, judul) == 0)
        {
            return pos;
        }
        else if (strcmp(film[pos].judul, judul) > 0)
        {
            high = pos - 1;
        }
        else if (strcmp(film[pos].judul, judul) < 0)
        {
            low = pos + 1;
        }
    } while (strcmp(judul, film[pos].judul) < 0);
    return -1;
}

void swap(Film *a, Film *b)
{
    Film temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Film *film, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            int cmp = strcmp(tolower(film[j].judul), tolower(film[j + 1].judul));
            if (strcmp(film[j].judul, film[j + 1].judul) > 0)
            {
                swap(&film[j], &film[j + 1]);
            }
        }
    }
}

int main()
{
    struct Film film[100];
    int Jum_Film = 0;
    int i = 0;
    char JudulS[60];
    int option;
    char judulCari[50];
    int hasil = -1;

    FILE *p = fopen("pendukung.txt", "r");
    while (!feof(p))
    {
        fscanf(p, "%[^#]#%[^#]#%d#%d#%[^#]#%[^\n]\n", film[i].judul, film[i].director, &film[i].release, &film[i].episode, film[i].genre, film[i].tipe);
        fflush(stdin);
        i++;
        Jum_Film++;
    }
    fclose(p);

    do
    {
        puts("--------------Film Database---------------");
        puts("1. Show Films");
        puts("2. Searching Film using Interpolation Search");
        puts("3. Searching Film using Binary Search");
        printf("4. Exit\n");
        puts("------------------------------------------");
        printf("Pilih: ");
        fflush(stdin);
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            for (i = 0; i < Jum_Film; i++)
            {
                printf("%s\n", film[i].judul);
            }
            break;
        case 2:
            bubbleSort(film, Jum_Film);
            printf("Judul film telah diurutkan berdasarkan abjad.\n");
            printf("Masukkan judul film yang ingin dicari: ");
            fflush(stdin);
            scanf("%[^\n]s", judulCari);
            fflush(stdin);
            hasil = interpolationSearchbeta(film, Jum_Film, judulCari);
            if (hasil != -1)
            {
                printf("Judul film %s ditemukan pada index %d.\n\n", judulCari, hasil);
            }
            else
            {
                printf("Judul film %s tidak ditemukan di dalam daftar.\n\n", judulCari);
            }
            break;
        case 3:
            bubbleSort(film, Jum_Film);
            printf("Judul film telah diurutkan berdasarkan abjad.\n");
            printf("Masukkan judul film yang ingin dicari: ");
            fflush(stdin);
            scanf("%[^\n]s", judulCari);
            fflush(stdin);
            hasil = binarySearchFilm(film, Jum_Film, judulCari);
            if (hasil != -1)
            {
                printf("Judul film %s ditemukan pada index %d.\n\n", judulCari, hasil);
            }
            else
            {
                printf("Judul film %s tidak ditemukan di dalam daftar.\n\n", judulCari);
            }
            break;
        }
    } while (option != 4);
    return 0;
}
