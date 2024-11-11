#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>

typedef struct Order // Implementasi Double Linked List
{
    char makanan[50];
    int harga;
    int jumlah;
    struct Order *next, *prev;
} Order;
void createNewNodeOrder(char *nama, int harga, int jumlah, Order **head, Order **tail)
{
    Order *newNode = (Order *)malloc(sizeof(Order));

    strcpy(newNode->makanan, nama);
    newNode->harga = harga;
    newNode->jumlah = jumlah;
    newNode->next = NULL;

    if (*tail == NULL)
    {
        // This is the first node, so it's both the head and the tail
        newNode->prev = NULL; // No previous node
        *head = newNode;      // Head points to the new node
    }
    else
    {
        newNode->prev = *tail;
        (*tail)->next = newNode;
    }
    *tail = newNode;
}
void headDeletionOrder(Order **head)
{
    if (*head == NULL)
        return;

    Order *trash = *head;
    *head = trash->next;
    (*head)->prev = NULL;
    trash->next = NULL;
    free(trash);
}
void tailDeletionOrder(Order **head, Order **tail)
{
    if (*tail == NULL)
        return;

    Order *trash = *tail;
    *tail = trash->prev;

    if (*tail != NULL)
    {
        (*tail)->next = NULL;
    }
    else
    {
        *head = NULL; // The list is now empty
    }

    free(trash);
}
void middleDeletionOrder(Order **head, int target)
{
    Order *trash = *head, *tempBefore, *tempAfter;
    for (int i = 0; i < target; i++)
    {
        trash = trash->next;
    }

    tempBefore = trash->prev;
    tempAfter = trash->next;

    tempBefore->next = tempAfter;
    tempAfter->prev = tempBefore;

    trash->prev = NULL;
    trash->next = NULL;
    free(trash);
}
void deleteOrder(Order **head, Order **tail, int position)
{
    if (*head == NULL)
        return; // Empty list, nothing to delete

    if (position == 1)
    { // Deleting the head
        headDeletionOrder(head);
        if (*head == NULL)
            *tail = NULL;
        return;
    }

    Order *temp = *head;
    int i;
    for (i = 1; temp != NULL && i < position; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
        return; // Position is out of bounds

    if (temp->next == NULL)
    { // Deleting the tail
        tailDeletionOrder(head, tail);
    }
    else if (temp->prev != NULL)
    { // Deleting somewhere in the middle
        Order *tempBefore = temp->prev;
        Order *tempAfter = temp->next;

        tempBefore->next = tempAfter;
        tempAfter->prev = tempBefore;

        free(temp);
    }
}
void printOrder(Order *head, int *totalHarga)
{
    *totalHarga = 0; // Reset total price
    Order *temp = head;
    int i = 1;
    printf("No |          Makanan         | Jumlah |     Harga     \n");
    while (temp != NULL)
    {
        int itemTotal = temp->harga * temp->jumlah;
        printf("%-2d | %-24s | %-6d |     %-14d \n", i, temp->makanan, temp->jumlah, itemTotal);
        *totalHarga += itemTotal;
        temp = temp->next;
        i++;
    }
    printf("Total Harga: %d\n", *totalHarga);
}

typedef struct ListMakanan // Queue
{
    char namaMakanan[50];
    int harga;
} ListMakanan;

void enqueueMakanan(int *rearMakanan, ListMakanan listMakanan[], char *nama, int harga)
{
    if (*rearMakanan < 49)
    {
        (*rearMakanan)++;
        strcpy(listMakanan[*rearMakanan].namaMakanan, nama);
        listMakanan[*rearMakanan].harga = harga;
    }
    else
    {
        printf("Queue Overflow!\n");
    }
}
void dequeueMakanan(int rearMakanan, int frontMakanan, ListMakanan listMakanan[])
{
    if (frontMakanan <= rearMakanan)
    {
        printf("Dequeued: %s, Harga: %d\n", listMakanan[frontMakanan].namaMakanan, listMakanan[frontMakanan].harga);
        frontMakanan++;
    }
    else
    {
        printf("Queue Underflow!\n");
    }
}
void printListMakanan(int rearMakanan, int frontMakanan, ListMakanan listMakanan[])
{
    if (rearMakanan >= frontMakanan)
    {
        printf("No |          Makanan         |     Harga     \n");
        for (int i = frontMakanan; i <= rearMakanan; i++)
        {
            printf("%-2d | %-24s |     %-14d \n", i + 1 - frontMakanan, listMakanan[i].namaMakanan, listMakanan[i].harga);
        }
    }
    else
    {
        printf("List Makanan is empty.\n");
    }
    printf("\n");
}

typedef struct ListFavorit // Stack
{
    char namaMakanan[50];
    struct ListFavorit *prev, *next;
} ListFavorit;
void pushFavorit(int *topFavorit, ListFavorit listFavorit[], char *nama)
{
    if (*topFavorit < 49)
    {
        *topFavorit = *topFavorit + 1;
        strcpy(listFavorit[*topFavorit].namaMakanan, nama);
    }
    else
    {
        printf("Stack Overflow!\n");
    }
}
void popFavorit(int *topFavorit, ListFavorit listFavorit[])
{
    if (*topFavorit >= 0)
    {
        printf("Popped: %s\n\n", listFavorit[*topFavorit].namaMakanan);
        *topFavorit = *topFavorit - 1;
    }
    else
    {
        printf("Stack Underflow!\n\n");
    }
}
void printListFavorit(int topFavorit, ListFavorit listFavorit[])
{
    if (topFavorit >= 0)
    {
        printf("List Favorit Stack:\n");
        for (int i = topFavorit; i >= 0; i--)
        {
            printf("%-2d: %s\n", topFavorit - i + 1, listFavorit[i].namaMakanan);
        }
    }
    else
    {
        printf("List Favorit is empty.\n");
    }
    printf("\n");
}

void printMenu()
{
    printf("=========================\n");
    printf("  Welcome to McDonald's  \n");
    printf("=========================\n");
    printf("1. Lihat Menu\n");
    printf("2. Add Favorite Menu\n");
    printf("3. Kelola Favorite\n");
    printf("4. Order Menu\n");
    printf("5. Kelola Order\n");
    printf("6. Purchase Order\n");
    printf("0. Exit Program\n");
    printf("Pilihan: ");
}

int main()
{
    struct Order *headOrder, *tailOrder;
    headOrder = tailOrder = NULL;
    struct ListMakanan listMakanan[50];
    int frontMakanan = 0; // Initialize front of queue to 0
    int rearMakanan = -1; // Initialize rear of queue to -1 (empty)

    struct ListFavorit listFavorit[50];
    int topFavorit = -1; // Initialize top of stack to -1 (empty)

    FILE *fplm = fopen("ListMakananMcdy.txt", "r");
    while (!feof(fplm))
    {
        int harga;
        char nama[50];
        fscanf(fplm, "%[^#]#%d\n", nama, &harga);
        enqueueMakanan(&rearMakanan, listMakanan, nama, harga);
    }
    fclose(fplm);

    FILE *fplf = fopen("ListFavorit.txt", "r");
    while (!feof(fplf))
    {
        int no;
        char nama[50];
        fscanf(fplf, "%[^#]#%[^\n]\n", &no, nama);
        pushFavorit(&topFavorit, listFavorit, nama);
    }
    fclose(fplf);

    int totalHarga = 0;

    int pilih;
    do
    {
        printMenu();
        scanf("%d", &pilih);
        switch (pilih)
        {
        case 1: // Lihat Menu
            printListMakanan(rearMakanan, frontMakanan, listMakanan);
            printf("Press any key to continue . . . \n");
            getch();
            break;

        case 2: // Add Favorite
            printListMakanan(rearMakanan, frontMakanan, listMakanan);
            printf("Tambah Favorite\n");
            printf("Pilih No: ");
            int pilihMakanan;
            scanf("%d", &pilihMakanan);
            if (pilihMakanan >= 0 && pilihMakanan <= rearMakanan)
            {
                int udahAda = 0;
                for (int i = 0; i <= topFavorit; i++)
                {
                    if (strcmp(listFavorit[i].namaMakanan, listMakanan[pilihMakanan - 1].namaMakanan) == 0)
                    {
                        udahAda = 1;
                        break;
                    }
                }
                if (udahAda == 0)
                {
                    pushFavorit(&topFavorit, listFavorit, listMakanan[pilihMakanan - 1].namaMakanan);
                    printf("%s Berhasil terdaftar pada favorite\n\n", listMakanan[pilihMakanan - 1].namaMakanan);
                    FILE *fplf = fopen("ListFavorit.txt", "a");
                    fprintf(fplf, "%d#%s\n", topFavorit + 1, listMakanan[pilihMakanan - 1].namaMakanan);
                    fclose(fplf);
                }
                else
                {
                    printf("Item sudah ada\n\n");
                }
            }
            else
            {
                printf("tidak ada item no %d\n", pilihMakanan);
            }
            break;

        case 3: // Kelola Favorite
            int opsi;
            do
            {
                printListFavorit(topFavorit, listFavorit);
                printf("Opsi\n");
                printf("1. Pop\n");
                printf("0. Cancel\n");
                printf("Pilihan: ");
                scanf("%d", &opsi);
                if (opsi == 1)
                {
                    popFavorit(&topFavorit, listFavorit);
                    FILE *fplf = fopen("ListFavorit.txt", "w");
                    if (topFavorit == 0)
                    {
                        fprintf(fplf, "");
                    }
                    else
                    {
                        for (int i = 0; i < topFavorit; i++)
                        {
                            fprintf(fplf, "%d#%s\n", i + 1, listMakanan[pilihMakanan - 1].namaMakanan);
                        }
                    }

                    fclose(fplf);
                }
                else if (opsi == 0)
                {
                    printf("Canceled Kelola Favorite \n");
                    break;
                }
                else
                {
                    printf("Salah input\n");
                }
            } while (opsi != 0);

            break;

        case 4: // Order Menu
            printListMakanan(rearMakanan, frontMakanan, listMakanan);
            printf("Order Makanan\n");
            printf("Pilihan: ");
            int pilihOrder;
            scanf("%d", &pilihOrder);
            if (pilihOrder >= 0 && pilihOrder <= rearMakanan + 1)
            {
                int jumlah;
                printf("Jumlah Item: ");
                scanf("%d", &jumlah);
                createNewNodeOrder(listMakanan[pilihOrder - 1].namaMakanan, listMakanan[pilihOrder - 1].harga, jumlah, &headOrder, &tailOrder);
                printf("%s Berhasil terdaftar pada order\n", listMakanan[pilihOrder - 1].namaMakanan);
            }
            else
            {
                printf("tidak ada item no %d\n", pilihOrder);
            }
            break;

        case 5: // Kelola Order
            printOrder(headOrder, &totalHarga);
            printf("Opsi\n");
            printf("1. Hapus\n");
            printf("0. Done\n");
            printf("Pilihan: ");
            int opsiOrder;
            scanf("%d", &opsiOrder);
            if (opsiOrder == 0)
                break;
            else
            {
                int no;
                do
                {
                    printOrder(headOrder, &totalHarga);
                    printf("No yang akan dihapus (ketik 0 untuk selesai): ");
                    scanf("%d", &no);
                    if (no == 0)
                    {
                        printf("Selesai\n");
                        break;
                    }
                    else
                    {
                        deleteOrder(&headOrder, &tailOrder, no);
                    }
                    printf("\n");
                } while (no != 0);
            }

            break;

        case 6: // Purchase Order
            printOrder(headOrder, &totalHarga);
            printf("Confirm Purchase?\n");
            printf("1. Yes\n");
            printf("2. Use 20% Discount\n");
            printf("0. No\n");
            printf("Pilihan: ");
            int purchase;
            scanf("%d", &purchase);
            switch (purchase)
            {
            case 1: // Confirm Purchase
                printf("Purchase confirmed!\n\n");
                FILE *fpPurchase = fopen("bon.txt", "w");
                Order *temp = headOrder;
                int i = 1;
                int totalHarga = 0; // Initialize total price

                fprintf(fpPurchase, "=======================================================\n");
                fprintf(fpPurchase, "No |          Makanan         | Jumlah |     Harga     \n");
                while (temp != NULL)
                {
                    fprintf(fpPurchase, "%-2d | %-24s | %-6d |     %-14d \n", i, temp->makanan, temp->jumlah, temp->harga * temp->jumlah);
                    totalHarga += temp->harga * temp->jumlah;
                    temp = temp->next;
                    i++;
                }
                fprintf(fpPurchase, "=======================================================\n");
                fprintf(fpPurchase, "Total Harga: %d\n", totalHarga);
                fclose(fpPurchase);

                while (headOrder != NULL)
                {
                    Order *toDelete = headOrder;
                    headOrder = headOrder->next;
                    free(toDelete);
                }
                tailOrder = NULL; // Reset tail pointer since list is empty

                break;

            case 2:
            {

                FILE *fpPurchase = fopen("bon.txt", "w");
                Order *temp = headOrder;
                int i = 1;
                int totalHarga = 0; // Initialize total price

                fprintf(fpPurchase, "=======================================================\n");
                fprintf(fpPurchase, "No |          Makanan         | Jumlah |     Harga     \n");
                while (temp != NULL)
                {
                    fprintf(fpPurchase, "%-2d | %-24s | %-6d |     %-14d \n", i, temp->makanan, temp->jumlah, temp->harga * temp->jumlah);
                    totalHarga += temp->harga * temp->jumlah;
                    temp = temp->next;
                    i++;
                }
                fprintf(fpPurchase, "=======================================================\n");
                double discountRate = 0.2; // 20% discount
                double discountedTotal = totalHarga * discountRate;
                printf("Total after discount: %.2f\n", (totalHarga - discountedTotal));
                printf("Purchase confirmed with discount!\n\n");
                fprintf(fpPurchase, "Total Harga: %d\n", totalHarga);
                fprintf(fpPurchase, "Total Harga setelah Diskon: %.0f\n", (totalHarga - discountedTotal));
                fclose(fpPurchase);

                while (headOrder != NULL)
                {
                    Order *toDelete = headOrder;
                    headOrder = headOrder->next;
                    free(toDelete);
                }
                tailOrder = NULL; // Reset tail pointer since list is empty

                break;
            }

            case 0: // No
                printf("Purchase cancelled.\n");
                break;

            default:
                printf("Invalid option.\n");
                break;
            }

            break;

        case 0:
            break;

        default:
            break;
        }

    } while (pilih != 0);

    // Free Memory
    while (headOrder != NULL)
    {
        Order *toDelete = headOrder;
        headOrder = (headOrder)->next;
        free(toDelete);
    }
    tailOrder = NULL;

    return 0;
}
