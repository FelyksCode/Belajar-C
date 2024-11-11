#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char title[200];
    char director[100];
    char genre[20];
    char country[20];
    int release;
    int episode;
} Film;

void swap(Film *a, Film *b)
{
    Film temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Film films[], int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            // int cmp = strcmp(tolower(films[j].title), tolower(films[j + 1].title)); // Ini bikin error di bubble Sort (Variable ga dipake juga)
            if (strcmp(films[j].title, films[j + 1].title) > 0)
            {
                swap(&films[j], &films[j + 1]);
            }
        }
    }
}

int partition(Film films[], int low, int high)
{
    char pivot[1000];
    strcpy(pivot, films[high].title);
    int i = low - 1;
    int j;
    for (j = low; j <= high - 1; j++)
    {
        int cmp = strcmp(tolower(films[j].title), tolower(pivot));
        if (cmp < 0)
        {
            i++;
            swap(&films[i], &films[j]);
        }
    }
    swap(&films[i + 1], &films[high]);
    return (i + 1);
}

void quickSort(Film films[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(films, low, high);
        quickSort(films, low, pi - 1);
        quickSort(films, pi + 1, high);
    }
}

void readFilmsFromFile(Film films[], int *size)
{
    FILE *p = fopen("pendukung.txt", "r");
    if (!p)
    {
        printf("Error opening file.\n");
        exit(1);
    }
    int i = 0;
    while (fscanf(p, "%[^#]#%[^#]#%d#%d#%[^#]#%[^\n]\n", films[i].title, films[i].director, &films[i].release, &films[i].episode, films[i].genre, films[i].country) != EOF)
    {
        i++;
    }
    *size = i;
    fclose(p);
}

void printFilms(Film films[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("Title: %s\n", films[i].title);
    }
}

void showFilm(Film films[], int size)
{
    int choice, i;
    for (i = 0; i < size; i++)
    {
        printf("Page %d/%d\n", i + 1, size);
        puts("===========================================");
        printf("%-15s: %s\n", "Title", films[i].title);
        printf("%-15s: %s\n", "Director", films[i].director);
        printf("%-15s: %d\n", "Release", films[i].release);
        printf("%-15s: %d\n", "Episode", films[i].episode);
        printf("%-15s: %s\n", "Genre", films[i].genre);
        printf("%-15s: %s\n", "Country", films[i].country);
        puts("===========================================");
        puts("1. Previous");
        puts("2. Next");
        puts("3. Save to Watch Later");
        puts("4. Exit");
        printf("Choose: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (i > 0)
            {
                i -= 2;
            }
            else
            {
                i = size - 2;
            }
        }
        else if (choice == 2)
        {
            continue;
        }
        else if (choice == 3)
        {
            FILE *f = fopen("WatchLater.txt", "a");
            fprintf(f, "%s#%s#%d#%d#%s#%s\n", films[i].title, films[i].director, films[i].release, films[i].episode, films[i].genre, films[i].country);
            fclose(f);
            printf("Film added to Watch Later!\n");
            i--;
        }
        else if (choice == 4)
        {
            break;
        }
    }
}

void addFilm(Film films[], int *size)
{
    FILE *p = fopen("pendukung.txt", "a");
    printf("%-10s\t: ", "Title");
    scanf(" %[^\n]", films[*size].title);
    printf("%-10s\t: ", "Director");
    scanf(" %[^\n]", films[*size].director);
    printf("%-10s\t: ", "Release");
    scanf("%d", &films[*size].release);
    fflush(stdin);
    printf("%-10s\t: ", "Episode");
    scanf("%d", &films[*size].episode);
    fflush(stdin);
    printf("%-10s\t: ", "Genre");
    scanf("%[^\n]", films[*size].genre);
    fflush(stdin);
    printf("%-10s\t: ", "Country");
    scanf("%[^\n]", films[*size].country);
    fflush(stdin);
    fprintf(p, "%s#%s#%d#%d#%s#%s\n", films[*size].title, films[*size].director, films[*size].release, films[*size].episode, films[*size].genre, films[*size].country);
    (*size)++;
    fclose(p);
    puts("Film added successfully\n");
}

void searchByYear(Film films[], int size)
{
    int year;
    printf("Enter Year: ");
    scanf("%d", &year);
    printf("Films released in %d\n", year);
    FILE *f = fopen("History.txt", "a");
    fprintf(f, "Year: %d\n", year);
    int i;
    for (i = 0; i < size; i++)
    {
        if (films[i].release == year)
        {
            puts("===========================================");
            printf("%-15s: %s\n", "Title", films[i].title);
            printf("%-15s: %s\n", "Director", films[i].director);
            printf("%-15s: %d\n", "Release", films[i].release);
            printf("%-15s: %d\n", "Episode", films[i].episode);
            printf("%-15s: %s\n", "Genre", films[i].genre);
            printf("%-15s: %s\n", "Country", films[i].country);
            puts("===========================================");
        }
    }
    fclose(f);
}

void searchByEpisode(Film films[], int size)
{
    int episode;
    printf("Enter Episode Count: ");
    scanf("%d", &episode);
    printf("Films with %d episodes\n", episode);
    FILE *f = fopen("History.txt", "a");
    fprintf(f, "Episode: %d\n", episode);
    int i;
    for (i = 0; i < size; i++)
    {
        if (films[i].episode == episode)
        {
            puts("===========================================");
            printf("%-15s: %s\n", "Title", films[i].title);
            printf("%-15s: %s\n", "Director", films[i].director);
            printf("%-15s: %d\n", "Release", films[i].release);
            printf("%-15s: %d\n", "Episode", films[i].episode);
            printf("%-15s: %s\n", "Genre", films[i].genre);
            printf("%-15s: %s\n", "Country", films[i].country);
            puts("===========================================");
        }
    }
    fclose(f);
}

void searchByDirector(Film films[], int size)
{
    char director[1000];
    printf("Enter Director Name: ");
    scanf(" %[^\n]", director);
    printf("Films directed by %s\n", director);
    FILE *f = fopen("History.txt", "a");
    fprintf(f, "Director: %s\n", director);
    int i;
    for (i = 0; i < size; i++)
    {
        if (strcmp(films[i].director, director) == 0)
        {
            puts("===========================================");
            printf("%-15s: %s\n", "Title", films[i].title);
            printf("%-15s: %s\n", "Director", films[i].director);
            printf("%-15s: %d\n", "Release", films[i].release);
            printf("%-15s: %d\n", "Episode", films[i].episode);
            printf("%-15s: %s\n", "Genre", films[i].genre);
            printf("%-15s: %s\n", "Country", films[i].country);
            puts("===========================================");
        }
    }
    fclose(f);
}

void searchByGenre(Film films[], int size)
{
    char genre[20];
    printf("Enter Genre: ");
    scanf(" %[^\n]", genre);
    printf("Films in genre %s\n", genre);
    FILE *f = fopen("History.txt", "a");
    fprintf(f, "Genre: %s\n", genre);
    int i;
    for (i = 0; i < size; i++)
    {
        if (strcmp(films[i].genre, genre) == 0)
        {
            puts("===========================================");
            printf("%-15s: %s\n", "Title", films[i].title);
            printf("%-15s: %s\n", "Director", films[i].director);
            printf("%-15s: %d\n", "Release", films[i].release);
            printf("%-15s: %d\n", "Episode", films[i].episode);
            printf("%-15s: %s\n", "Genre", films[i].genre);
            printf("%-15s: %s\n", "Country", films[i].country);
            puts("===========================================");
        }
    }
    fclose(f);
}

void searchByCountry(Film films[], int size)
{
    char country[20];
    printf("Enter Country: ");
    scanf(" %[^\n]", country);
    printf("Films from %s\n", country);
    FILE *f = fopen("History.txt", "a");
    fprintf(f, "Country: %s\n", country);
    int i;
    for (i = 0; i < size; i++)
    {
        if (strcmp(films[i].country, country) == 0)
        {
            puts("===========================================");
            printf("%-15s: %s\n", "Title", films[i].title);
            printf("%-15s: %s\n", "Director", films[i].director);
            printf("%-15s: %d\n", "Release", films[i].release);
            printf("%-15s: %d\n", "Episode", films[i].episode);
            printf("%-15s: %s\n", "Genre", films[i].genre);
            printf("%-15s: %s\n", "Country", films[i].country);
            puts("===========================================");
        }
    }
    fclose(f);
}

void searchByTitle(Film films[], int size)
{
    char title[1000];
    printf("Enter Title: ");
    scanf(" %[^\n]", title);
    printf("Films with title %s\n", title);
    FILE *f = fopen("History.txt", "a");
    fprintf(f, "Title: %s\n", title);
    int i;
    for (i = 0; i < size; i++)
    {
        if (strcmp(films[i].title, title) == 0)
        {
            puts("===========================================");
            printf("%-15s: %s\n", "Title", films[i].title);
            printf("%-15s: %s\n", "Director", films[i].director);
            printf("%-15s: %d\n", "Release", films[i].release);
            printf("%-15s: %d\n", "Episode", films[i].episode);
            printf("%-15s: %s\n", "Genre", films[i].genre);
            printf("%-15s: %s\n", "Country", films[i].country);
            puts("===========================================");
        }
    }
    fclose(f);
}

void exportFilms(Film films[], int size)
{
    char fileName[100];
    printf("Enter file name: ");
    scanf("%s", fileName);
    FILE *p = fopen(fileName, "w");
    int i;
    for (i = 0; i < size; i++)
    {
        fprintf(p, "%s#%s#%d#%d#%s#%s\n", films[i].title, films[i].director, films[i].release, films[i].episode, films[i].genre, films[i].country);
    }
    fclose(p);
    printf("Data exported to %s\n", fileName);
}

int main()
{
    Film films[100];
    int size = 0, i = 0;

    FILE *p = fopen("pendukung.txt", "r");
    if (!p)
    {
        printf("Error opening file.\n");
        return 1;
    }
    while (fscanf(p, "%[^#]#%[^#]#%d#%d#%[^#]#%[^\n]\n", films[i].title, films[i].director, &films[i].release, &films[i].episode, films[i].genre, films[i].country) != EOF)
    {
        i++;
    }
    size = i;
    fclose(p);

    int option;

    do
    {
        puts("--------------Film Database---------------");
        puts("1. Show Films");
        puts("2. Add Film");
        puts("3. Search by Release Year");
        puts("4. Search by Episode Count");
        puts("5. Search by Director");
        puts("6. Search by Genre");
        puts("7. Search by Country");
        puts("8. Search by Title");
        puts("9. Export Film Data");
        puts("10. Sort Titles (Bubble Sort)");
        puts("11. Sort Titles (Quick Sort)");
        printf("12. Exit\n");
        puts("------------------------------------------");
        printf("Choose: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            showFilm(films, size);
            break;
        case 2:
            addFilm(films, &size);
            break;
        case 3:
            searchByYear(films, size);
            break;
        case 4:
            searchByEpisode(films, size);
            break;
        case 5:
            searchByDirector(films, size);
            break;
        case 6:
            searchByGenre(films, size);
            break;
        case 7:
            searchByCountry(films, size);
            break;
        case 8:
            searchByTitle(films, size);
            break;
        case 9:
            exportFilms(films, size);
            break;
        case 10:
            readFilmsFromFile(films, &size);
            bubbleSort(films, size);
            printFilms(films, size);
            printf("Films sorted by title using Bubble Sort.\n\n");
            break;
        case 11:
            readFilmsFromFile(films, &size);
            quickSort(films, 0, size - 1);
            printFilms(films, size);
            printf("Films sorted by title using Quick Sort.\n\n");
            break;
        case 12:
            puts("Saving...");
            printf("Exiting\n");
            break;
        default:
            printf("Invalid option. Try again.\n");
        }

    } while (option != 12);

    return 0;
}
