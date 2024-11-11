#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char judul[1000];
    char director[1000];
    char genre[20];
    char negara[20];
    int release;
    int episode;
    struct node *left, *right;
} *root = NULL;

struct node *createNode(char *title, char *director, char *genre, char *negara, int release, int episode)
{
    struct node *curr = (struct node *)malloc(sizeof(struct node));
    strcpy(curr->judul, title);
    strcpy(curr->director, director);
    strcpy(curr->genre, genre);
    strcpy(curr->negara, negara);
    curr->release = release;
    curr->episode = episode;
    curr->left = NULL;
    curr->right = NULL;

    return curr;
}

struct node *insert(struct node *root, char *title, char *director, char *genre, char *negara, int release, int episode)
{
    if (root == NULL)
    {
        return createNode(title, director, genre, negara, release, episode);
    }
    else if (strcmp(title, root->judul) < 0)
    {
        root->left = insert(root->left, title, director, genre, negara, release, episode);
    }
    else if (strcmp(title, root->judul) > 0)
    {
        root->right = insert(root->right, title, director, genre, negara, release, episode);
    }
    else
    {
        return;
    }
    return root;
}

void read()
{
    FILE *p = fopen("pendukung.txt", "r");
    if (p == NULL)
    {
        printf("Failed to open file\n");
        return;
    }
    while (1)
    {
        char judul[1000];
        char director[1000];
        char genre[20];
        char negara[20];
        int release;
        int episode;
        int result = fscanf(p, "%[^#]#%[^#]#%d#%d#%[^#]#%[^\n]\n", judul, director, &release, &episode, genre, negara);
        if (result == EOF)
        {
            break;
        }
        root = insert(root, judul, director, genre, negara, release, episode);
    }
    fclose(p);
}

void search(struct node *root, char *judul)
{
    if (root == NULL)
    {
        printf("Data not Exist\n");
        return;
    }
    else if (strcmp(judul, root->judul) < 0)
    {
        search(root->left, judul);
    }
    else if (strcmp(judul, root->judul) > 0)
    {
        search(root->right, judul);
    }
    else
    {
        printf("Data Exist: %s\n", judul);
        return;
    }
}

struct node *deleteData(struct node *root, char *judul)
{
    if (root == NULL)
    {
        printf("Data not Exist\n");
        return root;
    }
    else if (strcmp(judul, root->judul) < 0)
    {
        root->left = deleteData(root->left, judul);
    }
    else if (strcmp(judul, root->judul) > 0)
    {
        root->right = deleteData(root->right, judul);
    }
    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            struct node *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
            free(temp);
        }
        else
        {
            struct node *temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            strcpy(root->judul, temp->judul);
            strcpy(root->director, temp->director);
            strcpy(root->genre, temp->genre);
            strcpy(root->negara, temp->negara);
            root->release = temp->release;
            root->episode = temp->episode;
            root->right = deleteData(root->right, temp->judul);
        }
    }
    return root;
}

int main()
{
    system("cls");
    int option;
    read();

    while (1)
    {
        printf("1. Search Node\n");
        printf("2. Insert Node\n");
        printf("3. Delete Node\n");
        printf("4. Exit\n");
        printf("--> ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
        {
            printf("Input Title to Search: ");
            char judul[1000];
            scanf(" %[^\n]", judul);
            search(root, judul);
            break;
        }
        case 2:
        {
            char judul[1000];
            char director[1000];
            char genre[20];
            char negara[20];
            int release;
            int episode;
            printf("%-15s : ", "Title");
            scanf(" %[^\n]", judul);
            printf("%-15s : ", "Director");
            scanf(" %[^\n]", director);
            printf("%-15s : ", "Release");
            scanf("%d", &release);
            printf("%-15s : ", "Episode");
            scanf("%d", &episode);
            printf("%-15s : ", "Genre");
            scanf(" %[^\n]", genre);
            printf("%-15s : ", "Negara");
            scanf(" %[^\n]", negara);
            root = insert(root, judul, director, genre, negara, release, episode);
            printf("Data successfully added!\n");
            break;
        }
        case 3:
        {
            char target[1000];
            printf("Input Title to Delete: ");
            scanf(" %[^\n]", target);
            root = deleteData(root, target);
            printf("Data successfully deleted!\n");
            break;
        }
        case 4:
            printf("Thank you and see you again!\n");
            exit(0);
        default:
            printf("Invalid option\n");
        }
    }

    return 0;
}
