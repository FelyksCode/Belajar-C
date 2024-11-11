#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char judul[1000];
    char director[1000];
    char genre[20];
    char negara[20];
    int release;
    int episode;
} Film;

typedef struct {
    Film *data;
    int size;
    int capacity;
} MaxHeap;

// Function prototypes
void initHeap(MaxHeap *heap, int capacity);
void insertHeap(MaxHeap *heap, Film value);
Film extractMaxHeap(MaxHeap *heap);
void maxHeapify(MaxHeap *heap, int i);
void swap(Film *a, Film *b);
void printWatchLater(MaxHeap *heap);
void deleteFromHeap(MaxHeap *heap, const char* title);
void freeHeap(MaxHeap *heap);

int main() {
    Film film[100];
    int size = 0, i = 0;

    // Read data from file
    FILE *p = fopen("pendukung.txt", "r");
    while (!feof(p)) {
        fscanf(p, "%[^#]#%[^#]#%d#%d#%[^#]#%[^\n]\n", film[i].judul, film[i].director, &film[i].release, &film[i].episode, film[i].genre, film[i].negara);
        i++;
    }
    size = i;
    fclose(p);
    
    MaxHeap watchLater;
    initHeap(&watchLater, 100);

    int option;
    
    do {
        puts("--------------Database Film---------------");
        puts("1. Show Film");
        puts("2. Tambah Film");
        puts("3. Cari Berdasarkan Tahun Rilis");
        puts("4. Cari Berdasarkan Episode");
        puts("5. Cari Berdasarkan Direktor");
        puts("6. Cari Berdasarkan Genre");
        puts("7. Cari Berdasarkan Negara Asal");
        puts("8. Cari Berdasarkan Judul Film");
        puts("9. Export Film Data");
        puts("10. Print Watch Later List");
        puts("11. Remove Film from Watch Later List");
        printf("12.Exit\n");
        puts("------------------------------------------");
        printf("Pilih : ");
        scanf("%d", &option);
        
        while (option < 1 || option > 12) {
            puts("--------------Database Film---------------");
            puts("1. Show Film");
            puts("2. Tambah Film");
            puts("3. Cari Berdasarkan Tahun Rilis");
            puts("4. Cari Berdasarkan Episode");
            puts("5. Cari Berdasarkan Direktor");
            puts("6. Cari Berdasarkan Genre");
            puts("7. Cari Berdasarkan Negara Asal");
            puts("8. Cari Berdasarkan Judul Film");
            puts("9. Export Film Data");
            puts("10. Print Watch Later List");
            puts("11. Remove Film from Watch Later List");
            printf("12.Exit\n");
            puts("------------------------------------------");
            printf("Pilih : ");
            scanf("%d", &option);
        }
        
        int choice;
        int year, eps, k;
        char dir[50];
        char country[50];
        char Joedoel[50];
        char genree[50];
        char save[50];
        
        if(option == 1){
            for (i = 1; i <= size; i++) {
                printf("Page %d/%d\n", i, size);
                puts("===========================================");
                printf("%-15s: %s\n", "Title", film[i - 1].judul);
                printf("%-15s: %s\n", "Director", film[i - 1].director);
                printf("%-15s: %d\n", "Release", film[i - 1].release);
                printf("%-15s: %d\n", "Episode", film[i - 1].episode);
                printf("%-15s: %s\n", "Genre", film[i - 1].genre);
                printf("%-15s: %s\n", "Negara", film[i - 1].negara);
                puts("===========================================");
                puts("1. Previous");
                puts("2. Next");
                puts("3. Save to Watch Later");
                puts("4. Exit");
                printf("Pilih : ");
                scanf("%d", &choice);
                if(choice == 1){
                    if(i > 1){
                        i = i-1;
                    }
                    else if(i == 1 && size > 1){
                        i = size-1;
                    }
                }
                else if(choice == 2){
                    if(i < size){
                        continue;
                    }
                    else if(i == size){
                        i = 0;
                    }
                }
                else if(choice == 3){
                    insertHeap(&watchLater, film[i-1]);
                    printf("Film berhasil ditambahkan ke Watch Later!\n");
                    i = i-1;
                }
                else if(choice == 4){
                    break;
                }
            }
        }
        else if(option == 2){
            p = fopen("pendukung.txt", "a");
            printf("%-10s\t: ","Judul");
            scanf(" %[^\n]", film[size].judul);
            printf("%-10s\t: ","Director");
            scanf(" %[^\n]", film[size].director);
            printf("%-10s\t: ","Rilis");
            scanf("%d", &film[size].release);
            fflush(stdin);
            printf("%-10s\t: ","Episode");
            scanf("%d", &film[size].episode);
            fflush(stdin);
            printf("%-10s\t: ","Genre");
            scanf("%[^\n]", film[size].genre);  
            fflush(stdin);         
            printf("%-10s\t: ","Negara");
            scanf("%[^\n]", film[size].negara);
            fflush(stdin);
            fprintf(p,"\n%s#%s#%d#%d#%s#%s", film[size].judul, film[size].director,film[size].release,film[size].episode,film[size].genre,film[size].negara);
            size++;
            fclose(p);
            puts("Film berhasil ditambahkan\n");
        }
        else if(option == 3){
            printf("Masukan Tahun : ");
            scanf("%d",&year);
            printf("Film yang rilis pada tahun %d\n",year);
            FILE *f = fopen ("History.txt","a");
            fprintf(f,"%d\n",year);
            for(k=0;k<size;k++){
                if(year==film[k].release){
                    puts("===========================================");
                    printf("%-15s: %s\n", "Title", film[k].judul);
                    printf("%-15s: %s\n", "Director", film[k].director);
                    printf("%-15s: %d\n", "Release", film[k].release);
                    printf("%-15s: %d\n", "Episode", film[k].episode);
                    printf("%-15s: %s\n", "Genre", film[k].genre);
                    printf("%-15s: %s\n", "Negara", film[k].negara);
                    puts("===========================================");
                }
            }
            fclose(f);
        }
        else if(option == 4){
            printf("Masukan Jumlah Episode : ");
            scanf("%d",&eps);
            printf("Film yang memiliki jumlah episode %d\n",eps);
            FILE *f = fopen ("History.txt","a");
            fprintf(f,"%d\n",eps);
            for(k=0;k<size;k++){
                if(eps==film[k].episode){
                    puts("===========================================");
                    printf("%-15s: %s\n", "Title", film[k].judul);
                    printf("%-15s: %s\n", "Director", film[k].director);
                    printf("%-15s: %d\n", "Release", film[k].release);
                    printf("%-15s: %d\n", "Episode", film[k].episode);
                    printf("%-15s: %s\n", "Genre", film[k].genre);
                    printf("%-15s: %s\n", "Negara", film[k].negara);
                    puts("===========================================");
                }
            }
            fclose(f);
        }
        else if(option == 5){
            fflush(stdin);
            printf("Masukan Nama Direktor : ");
            scanf("%[^\n]",dir); getchar();
            printf("Film yang diproduksi oleh %s\n",dir);
            FILE *f = fopen ("History.txt","a");
            fprintf(f,"%s\n",dir);
            for(k=0;k<size;k++){
                if(strcmp(dir,film[k].director)==0){
                    puts("===========================================");
                    printf("%-15s: %s\n", "Title", film[k].judul);
                    printf("%-15s: %s\n", "Director", film[k].director);
                    printf("%-15s: %d\n", "Release", film[k].release);
                    printf("%-15s: %d\n", "Episode", film[k].episode);
                    printf("%-15s: %s\n", "Genre", film[k].genre);
                    printf("%-15s: %s\n", "Negara", film[k].negara);
                    puts("===========================================");
                }
            }
            fclose(f);
        }
        else if(option == 6){
            fflush(stdin);
            printf("Masukan Genre Film : ");
            scanf("%[^\n]",genree);
            printf("Film yang memiliki genre %s\n",genree);
            FILE *f = fopen ("History.txt","a");
            fprintf(f,"%s\n",genree);
            for(k=0;k<size;k++){
                if(strcmp(genree,film[k].genre)==0){
                    puts("===========================================");
                    printf("%-15s: %s\n", "Title", film[k].judul);
                    printf("%-15s: %s\n", "Director", film[k].director);
                    printf("%-15s: %d\n", "Release", film[k].release);
                    printf("%-15s: %d\n", "Episode", film[k].episode);
                    printf("%-15s: %s\n", "Genre", film[k].genre);
                    printf("%-15s: %s\n", "Negara", film[k].negara);
                    puts("===========================================");
                }
            }
            fclose(f);
        }
        else if(option == 7){
            fflush(stdin);
            printf("Masukan Negara Asal : ");
            scanf("%[^\n]",country);
            printf("Film yang berasal dari negara %s\n",country);
            FILE *f = fopen ("History.txt","a");
            fprintf(f,"%s\n",country);
            for(k=0;k<size;k++){
                if(strcmp(country,film[k].negara)==0){
                    puts("===========================================");
                    printf("%-15s: %s\n", "Title", film[k].judul);
                    printf("%-15s: %s\n", "Director", film[k].director);
                    printf("%-15s: %d\n", "Release", film[k].release);
                    printf("%-15s: %d\n", "Episode", film[k].episode);
                    printf("%-15s: %s\n", "Genre", film[k].genre);
                    printf("%-15s: %s\n", "Negara", film[k].negara);
                    puts("===========================================");
                }
            }
            fclose(f);
        }
        else if(option == 8){
            fflush(stdin);
            printf("Masukan Judul Film : ");
            scanf("%[^\n]",Joedoel);
            printf("Film yang berjudul %s\n",Joedoel);
            FILE *f = fopen ("History.txt","a");
            fprintf(f,"%s\n",Joedoel);
            for(k=0;k<size;k++){
                if(strcmp(Joedoel,film[k].judul)==0){
                    puts("===========================================");
                    printf("%-15s: %s\n", "Title", film[k].judul);
                    printf("%-15s: %s\n", "Director", film[k].director);
                    printf("%-15s: %d\n", "Release", film[k].release);
                    printf("%-15s: %d\n", "Episode", film[k].episode);
                    printf("%-15s: %s\n", "Genre", film[k].genre);
                    printf("%-15s: %s\n", "Negara", film[k].negara);
                    puts("===========================================");
                }
            }
            fclose(f);
        }
        else if(option == 9){
            printf("Masukan nama file (ekstensi .txt) : ");
            scanf("%s", save);
            FILE *fp;
            fp = fopen(save, "w");
            for (i = 0; i < size; i++) {
                fprintf(fp, "%s\n", film[i].judul);
                fprintf(fp, "%s\n", film[i].director);
                fprintf(fp, "%d\n", film[i].release);
                fprintf(fp, "%d\n", film[i].episode);
                fprintf(fp, "%s\n", film[i].genre);
                fprintf(fp, "%s\n", film[i].negara);
                fprintf(fp, "\n");
            }
            fclose(fp);
            printf("Film data exported to %s successfully!\n", save);
        }
        else if(option == 10){
            printWatchLater(&watchLater);
        }
        else if(option == 11){
            fflush(stdin);
            char deleteTitle[100];
            printf("Masukan judul film yang ingin dihapus dari Watch Later List: ");
            scanf("%[^\n]", deleteTitle);
            deleteFromHeap(&watchLater, deleteTitle);
        }
    } while(option != 12);
    
    freeHeap(&watchLater);
    return 0;
}

// Initialize the heap
void initHeap(MaxHeap *heap, int capacity) {
    heap->data = (Film *)malloc(capacity * sizeof(Film));
    heap->size = 0;
    heap->capacity = capacity;
}

// Insert a value into the heap
void insertHeap(MaxHeap *heap, Film value) {
    if (heap->size >= heap->capacity) {
        heap->capacity *= 2;
        heap->data = (Film *)realloc(heap->data, heap->capacity * sizeof(Film));
    }
    int i = heap->size++;
    while (i && value.release > heap->data[(i - 1) / 2].release) {
        heap->data[i] = heap->data[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->data[i] = value;
}

// Extract the maximum value from the heap
Film extractMaxHeap(MaxHeap *heap) {
    Film max = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    maxHeapify(heap, 0);
    return max;
}

// Max-heapify function to maintain the heap property
void maxHeapify(MaxHeap *heap, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->data[left].release > heap->data[largest].release)
        largest = left;

    if (right < heap->size && heap->data[right].release > heap->data[largest].release)
        largest = right;

    if (largest != i) {
        swap(&heap->data[i], &heap->data[largest]);
        maxHeapify(heap, largest);
    }
}

// Swap two elements
void swap(Film *a, Film *b) {
    Film temp = *a;
    *a = *b;
    *b = temp;
}

// Print the films in the Watch Later list
void printWatchLater(MaxHeap *heap) {
    printf("Watch Later List:\n");
    int i;
    for (i = 0; i < heap->size; i++) {
        printf("%-15s: %s\n", "Title", heap->data[i].judul);
        printf("%-15s: %s\n", "Director", heap->data[i].director);
        printf("%-15s: %d\n", "Release", heap->data[i].release);
        printf("%-15s: %d\n", "Episode", heap->data[i].episode);
        printf("%-15s: %s\n", "Genre", heap->data[i].genre);
        printf("%-15s: %s\n", "Negara", heap->data[i].negara);
        puts("===========================================");
    }
}

// Delete a film from the heap by title
void deleteFromHeap(MaxHeap *heap, const char* title) {
	int i;
    for (i = 0; i < heap->size; i++) {
        if (strcmp(heap->data[i].judul, title) == 0) {
            heap->data[i] = heap->data[--heap->size];
            maxHeapify(heap, i);
            printf("Film \"%s\" berhasil dihapus dari Watch Later List!\n", title);
            return;
        }
    }
    printf("Film \"%s\" tidak ditemukan dalam Watch Later List.\n", title);
}

// Free the heap memory
void freeHeap(MaxHeap *heap) {
    free(heap->data);
}

