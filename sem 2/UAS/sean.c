#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char artist[100];
    char album[100];
    int year;
} Song;

void displayMenu() {
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                             DATABASE MUSIC SEAN                                                      |\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("| Title                                    | Artist               | Album                                      | Year  |\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
}

void displaySong(Song song) {
    printf("| %-40s | %-20s | %-42s | %-5d |\n", song.title, song.artist, song.album, song.year);
}

void displaySongs(Song songs[], int numSongs) {
    displayMenu();
    for (int i = 0; i < numSongs; i++) {
        char truncatedArtist[21];
        if (strlen(songs[i].artist) > 17) {
            strncpy(truncatedArtist, songs[i].artist, 17);
            truncatedArtist[17] = '\0';
            strcat(truncatedArtist, "...");
        }
        else {
            strcpy(truncatedArtist, songs[i].artist);
        }
        
        char truncatedAlbum[43];
        if (strlen(songs[i].album) > 39) {
            strncpy(truncatedAlbum, songs[i].album, 39);
            truncatedAlbum[39] = '\0';
            strcat(truncatedAlbum, "...");
        }
        else {
            strcpy(truncatedAlbum, songs[i].album);
        }
        
        Song truncatedSong = songs[i];
        strcpy(truncatedSong.artist, truncatedArtist);
        strcpy(truncatedSong.album, truncatedAlbum);
        
        displaySong(truncatedSong);
    }
    printf("------------------------------------------------------------------------------------------------------------------------\n");
}

void bubbleSortByTitle(Song songs[], int numSongs) {
    for (int i = 0; i < numSongs - 1; i++) {
        for (int j = 0; j < numSongs - i - 1; j++) {
            if (strcmp(songs[j].title, songs[j + 1].title) > 0) {
                Song temp = songs[j];
                songs[j] = songs[j + 1];
                songs[j + 1] = temp;
            }
        }
    }
}

void bubbleSortByYear(Song songs[], int numSongs) {
    for (int i = 0; i < numSongs - 1; i++) {
        for (int j = 0; j < numSongs - i - 1; j++) {
            if (songs[j].year > songs[j + 1].year) {
                Song temp = songs[j];
                songs[j] = songs[j + 1];
                songs[j + 1] = temp;
            }
        }
    }
}

int binarySearchByTitle(Song songs[], int low, int high, char searchTitle[]) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (strcmp(songs[mid].title, searchTitle) == 0) {
            return mid;
        }

        if (strcmp(songs[mid].title, searchTitle) > 0) {
            return binarySearchByTitle(songs, low, mid - 1, searchTitle);
        }

        return binarySearchByTitle(songs, mid + 1, high, searchTitle);
    }

    return -1;
}

int main() {
    FILE *file = fopen("database-musik.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    Song songs[100];
    int numSongs = 0;

    // Read data from the file and populate the songs array
    while (fscanf(file, "%[^*]*%[^*]*%[^*]*%d\n", songs[numSongs].title, songs[numSongs].artist, songs[numSongs].album, &songs[numSongs].year) == 4) {
        numSongs++;
    }

    fclose(file);

    int choice;
    do {
        printf("\nDATABASE MUSIC MENU\n");
        printf("1. Display all songs\n");
        printf("2. Sort songs by title\n");
        printf("3. Sort songs by year\n");
        printf("4. Search song by title\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySongs(songs, numSongs);
                break;
            case 2:
                bubbleSortByTitle(songs, numSongs);
                printf("\nSongs sorted by title:\n");
                displaySongs(songs, numSongs);
                break;
            case 3:
                bubbleSortByYear(songs, numSongs);
                printf("\nSongs sorted by year:\n");
                displaySongs(songs, numSongs);
                break;
            case 4:
                char searchTitle[100];
                printf("\nEnter the title to search: ");
                scanf(" %[^\n]", searchTitle);
                bubbleSortByTitle(songs, numSongs);
                int index = binarySearchByTitle(songs, 0, numSongs - 1, searchTitle);
                if (index != -1) {
                    printf("\nSong found at index %d:\n", index);
                    displayMenu();
                    displaySong(songs[index]);
                    printf("------------------------------------------------------------------------------------------------------------------------\n");
                } else {
                    printf("\nSong not found.\n");
                }
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
