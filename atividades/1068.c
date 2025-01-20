#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int isBalanced(const char* expression) {
    int balance = 0;
    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(') {
            balance++;
        } else if (expression[i] == ')') {
            balance--;
            if (balance < 0) {
                return 0;
            }
        }
    }
    return balance == 0;
}

int main() {
    char expression[MAX_LENGTH + 1];
    
    while (fgets(expression, sizeof(expression), stdin)) {
        expression[strcspn(expression, "\n")] = '\0';
        
        if (isBalanced(expression)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
