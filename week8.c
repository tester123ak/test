#include <stdio.h>
#include <string.h>

#define SIZE 100

// Function prototypes
void input(char *str);
int is_valid(char *str);
int is_upper(char c);
int is_lower(char c);
int is_digit(char c);
void display(char *str, int res);

int main() {
    char password[SIZE];
    int result;

    input(password);
    result = is_valid(password);
    display(password, result);

    return 0;
}

// Function to input password
void input(char *str) {
    printf("Enter your password: ");
    fgets(str, SIZE, stdin);

    // Remove newline character if present
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }
}

// Function to check if the password is valid
int is_valid(char *str) {
    int has_upper = 0, has_lower = 0, has_digit = 0;

    if (strlen(str) < 8)
        return 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_upper(str[i])) has_upper = 1;
        else if (is_lower(str[i])) has_lower = 1;
        else if (is_digit(str[i])) has_digit = 1;
    }

    return has_upper && has_lower && has_digit;
}

// Sub function: check for uppercase
int is_upper(char c) {
    return (c >= 'A' && c <= 'Z');
}

// Sub function: check for lowercase
int is_lower(char c) {
    return (c >= 'a' && c <= 'z');
}

// Sub function: check for digit
int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

// Function to display result
void display(char *str, int res) {
    if (res)
        printf("Password \"%s\" is VALID.\n", str);
    else
        printf("Password \"%s\" is INVALID.\n", str);
}
