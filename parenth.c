//You are given a string consisting of only '(' and ')' characters. Your task is to determine whether the parentheses are balanced. A string of parentheses is considered balanced if every opening parenthesis has a corresponding closing parenthesis and they occur in the correct order.


#include <stdio.h>

int isBalanced(char* s) {
    int count = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == '(') {
            count++;
        } else if (s[i] == ')') {
            count--;
            if (count < 0) {
                return 0; // Unbalanced parentheses
            }
        }
    }
    return count == 0;
}

int main() {
    char str[100];
    printf("Enter a string of parentheses: ");
    scanf("%s", str);

    if (isBalanced(str)) {
        printf("The parentheses are balanced.\n");
    } else {
        printf("The parentheses are not balanced.\n");
    }

    return 0;
}
