#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

// Function prototypes
void printWelcomeMessage();
int getUserChoice();
int getComputerChoice();
void determineWinner(int userChoice, int computerChoice, int *userScore, int *computerScore);
void printChoice(int choice);
void printScores(int userScore, int computerScore);

int main() {
    // Seed the random number generator
    srand(time(0));
    
    int userScore = 0;
    int computerScore = 0;
    char playAgain;
    
    printWelcomeMessage();
    
    do {
        // Get choices from user and computer
        int userChoice = getUserChoice();
        int computerChoice = getComputerChoice();
        
        // Display choices
        printf("\nYour choice: ");
        printChoice(userChoice);
        printf("Computer's choice: ");
        printChoice(computerChoice);
        
        // Determine and display the winner
        determineWinner(userChoice, computerChoice, &userScore, &computerScore);
        
        // Display current scores
        printScores(userScore, computerScore);
        
        // Ask if user wants to play again
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
        playAgain = tolower(playAgain);
        
        // Clear input buffer
        while(getchar() != '\n');
        
    } while(playAgain == 'y');
    
    printf("\nFinal Scores:\n");
    printScores(userScore, computerScore);
    printf("\nThanks for playing! Goodbye!\n");
    
    return 0;
}

// Prints the welcome message and game instructions
void printWelcomeMessage() {
    printf("================================\n");
    printf("   ROCK, PAPER, SCISSORS GAME   \n");
    printf("================================\n\n");
    printf("Game Rules:\n");
    printf("- Rock beats Scissors\n");
    printf("- Scissors beat Paper\n");
    printf("- Paper beats Rock\n\n");
}

// Gets and validates the user's choice
int getUserChoice() {
    char input[20];
    int valid = 0;
    int choice;
    
    do {
        printf("\nEnter your choice (rock, paper, scissors): ");
        scanf("%s", input);
        
        // Convert input to lowercase for comparison
        for(int i = 0; input[i]; i++) {
            input[i] = tolower(input[i]);
        }
        
        // Determine the choice
        if(strcmp(input, "rock") == 0) {
            choice = 0;
            valid = 1;
        }
        else if(strcmp(input, "paper") == 0) {
            choice = 1;
            valid = 1;
        }
        else if(strcmp(input, "scissors") == 0) {
            choice = 2;
            valid = 1;
        }
        else {
            printf("Invalid choice. Please enter rock, paper, or scissors.\n");
        }
    } while(!valid);
    
    return choice;
}

// Generates a random choice for the computer (0=rock, 1=paper, 2=scissors)
int getComputerChoice() {
    return rand() % 3; // Returns 0, 1, or 2
}

// Prints the choice in words
void printChoice(int choice) {
    switch(choice) {
        case 0: printf("Rock\n"); break;
        case 1: printf("Paper\n"); break;
        case 2: printf("Scissors\n"); break;
        default: printf("Unknown\n"); break;
    }
}

// Determines the winner and updates scores
void determineWinner(int userChoice, int computerChoice, int *userScore, int *computerScore) {
    // All possible outcomes
    if(userChoice == computerChoice) {
        printf("\nIt's a tie!\n");
    }
    else if((userChoice == 0 && computerChoice == 2) ||  // Rock beats scissors
            (userChoice == 1 && computerChoice == 0) ||  // Paper beats rock
            (userChoice == 2 && computerChoice == 1)) {   // Scissors beat paper
        printf("\nYou win this round!\n");
        (*userScore)++;
    }
    else {
        printf("\nComputer wins this round!\n");
        (*computerScore)++;
    }
}

// Prints the current scores
void printScores(int userScore, int computerScore) {
    printf("\nCurrent Scores:\n");
    printf("You: %d\n", userScore);
    printf("Computer: %d\n", computerScore);
}
