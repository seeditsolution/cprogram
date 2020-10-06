#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int letter_fill(char, char[], char[]);
void init_unknown(char[], char[]);

int main()
{
    char unknown[80];
    char letter;
    int num_of_wrong_guesses = 0;
    int MAX_TRIES = 5;
    char word[80];
    char words[][80] = 
    {
        "INDIA", "PAKISTAN", "NEPAL", "MALAYSIA", "PHILIPPINES", "AUSTRALIA", 
            "IRAN", "ETHIOPIA", "OMAN", "INDONESIA"
    };

    /* choose and copy a word from array of words randomly */
    srand(time(NULL));
    int n = rand() % 10;
    strcpy(word, words[n]);

    /* Initialize the secret word with the * character. */
    init_unknown(word, unknown);

    /* welcome the user */
    printf("\n\nWelcome to hangman...Guess a country Name");
    printf("\n\nEach letter is represented by a star.");
    printf("\n\nYou have to type only one letter in one try");
    printf("\n\nYou have %d tries to try and guess the word.", MAX_TRIES);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    /* Loop until the guesses are used up */
    while (num_of_wrong_guesses < MAX_TRIES)
    {
        printf("\n\n%s", unknown);
        printf("\n\nGuess a letter: ");
        scanf("%c", &letter);
        letter = toupper(letter);
        fflush(stdin);

        /* Fill secret word with letter if the guess is correct,
        otherwise increment the number of wrong guesses. */
        if (letter_fill(letter, word, unknown) == 0)
        {
            printf("\nWhoops! That letter isn't in there!\n");
            num_of_wrong_guesses++;
        }
        else
        {
            printf("\nYou found a letter! Isn't that exciting!\n");
        }

        /* Tell user how many guesses has left. */
        printf("You have %d", MAX_TRIES - num_of_wrong_guesses);
        printf(" guesses left.\n");

        /* Check if they guessed the word. */
        if (strcmp(word, unknown) == 0)
        {
            printf("%s\n", word);
            printf("Yeah! You got it!");
            break;
        }
    }
    if (num_of_wrong_guesses == MAX_TRIES)
    {
        printf("\nSorry, you lose...you've been hanged.\n");
        printf("The word was : %s\n", word);
    }
    getch();
    return 0;
}

/* Take a one character guess and the secret word, and fill in the
unfinished guessword. Returns number of characters matched.
Also, returns zero if the character is already guessed. */

int letter_fill(char guess, char secretword[], char guessword[])
{
    int i;
    int matches = 0;
    for (i = 0; secretword[i] != '\0'; i++)
    {
        /* Did we already match this letter in a previous guess? */
        if (guess == guessword[i])
            return 0;
        /* Is the guess in the secret word? */
        if (guess == secretword[i])
        {
            guessword[i] = guess;
            matches++;
        }
    }
    return matches;
}


/* Initialize the unknown word */
void init_unknown(char word[], char unknown[])
{
    int i;
    int length = strlen(word);
    for (i = 0; i < length; i++)
        unknown[i] = '*';
    unknown[i] = '\0';
}
