//WAP in C to encrypt a text file. the encryption involves shifting each character one position to left in alphabetical order, eg. A becomes B, Z becomes A. The encrypted file should be stored as another text file. You may also add an decryptor in it. 


#include <stdio.h>

// Function to check if a character is alphabetic
int isAlphabetic(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

// Function to encrypt a text string
void encrypt(char *text) {
    while (*text) {
        if (isAlphabetic(*text)) {
            if (*text == 'z' || *text == 'Z') {
                *text -= 25; // Wrap around for 'z' or 'Z'
            } else {
                (*text)++;
            }
        }
        text++;
    }
}

// Function to decrypt an encrypted text string
void decrypt(char *text) {
    while (*text) {
        if (isAlphabetic(*text)) {
            if (*text == 'a' || *text == 'A') {
                *text += 25; // Wrap around for 'a' or 'A'
            } else {
                (*text)--;
            }
        }
        text++;
    }
}

int main() {
    char inputFilename[50];
    char outputFilename[50];
    char text[1000];

    printf("Enter the input filename (including extension): ");
    scanf("%s", inputFilename);

    FILE *inputFile = fopen(inputFilename, "r");

    if (inputFile == NULL) {
        printf("Error opening the input file. Make sure the file exists and try again.\n");
        return 1;
    }

    // Read text from the input file
    fgets(text, sizeof(text), inputFile);

    fclose(inputFile);

    printf("Do you want to encrypt or decrypt? (E/D): ");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'E' || choice == 'e') {
        encrypt(text);
    } else if (choice == 'D' || choice == 'd') {
        decrypt(text);
    } else {
        printf("Invalid choice. Please enter 'E' or 'D'.\n");
        return 1;
    }

    printf("Enter the output filename (including extension): ");
    scanf("%s", outputFilename);

    FILE *outputFile = fopen(outputFilename, "w");

    if (outputFile == NULL) {
        printf("Error opening the output file. Make sure you have write permissions and try again.\n");
        return 1;
    }

    // Write the result to the output file
    fprintf(outputFile, "%s", text);

    fclose(outputFile);

    printf("Operation completed successfully. Result saved in %s.\n", outputFilename);

    return 0;
}
