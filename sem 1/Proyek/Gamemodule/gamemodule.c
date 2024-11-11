// C program for the above approach
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 
// Function to implement the game
int game(char you, char computer)
{
    // If both the user and computer
    // has chose the same thing
    if (you == computer)
        return -1;

    // If user's choice is stone and
    // computer's choice is paper
    else if (you == 'r' && computer == 'p')
        return 0;
 
            // If user's choice is paper and
            // computer's choice is stone
            else if (you == 'p' && computer == 'r') 
                return 1;
 
    // If user's choice is stone and
    // computer's choice is scissor
    if (you == 'r' && computer == 's')
        return 1;
 
    // If user's choice is scissor and
    // computer's choice is stone
    else if (you == 's' && computer == 's')
        return 0;
 
    // If user's choice is paper and
    // computer's choice is scissor
    if (you == 'p' && computer == 's')
        return 0;
 
    // If user's choice is scissor and
    // computer's choice is paper
    else if (you == 's' && computer == 'p')
        return 1;
}
 
// Driver Code
int main()
{
    int life = 3;\
    int userPoint = 0;
    while(life != 0){
            // Stores the random number
            int n;
        
            char you, computer, result;
        
			 printf("Enter r for ROCK, p for PAPER and s for SCISSOR\n");
        
            // input from the user
            scanf("%c", &you), getchar();

            // Chooses the random number
            // every time
            srand(time(NULL));
        
            // Make the random number less
            // than 10, divided it by 10
            n = rand() % 10;
        
            // Using simple probability 10 is
            // roughly divided among stone,
            // paper, and scissor
            if (n < 3)
        
                // s is denoting Rock
                computer = 'r';
        
            else if (n > 3 && n < 6)
        
                // p is denoting Paper
                computer = 'p';
        
            // z is denoting Scissor
            else
                computer = 's';
           
        
            // Function Call to play the game
            result = game(you, computer);
        
            if (result == -1) {
                printf("\nGame Draw!\n");
            }
            else if (result == 1) {
                printf("\nWow! You have won the game!\n");
                userPoint += 1;
            }
            else {
                printf("\nOh! You have lost the game!\n");
                life -= 1;
            }
                printf("\nYou choose : %c and Computer choose : %c\n",you, computer);
                printf("\nLife = %d, Point = %d\n\n\n", life, userPoint);
			if (life==0) {
				 printf("GAME OVER!");
			}
    }
    return 0;
}