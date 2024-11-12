#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Friend {
    char name[50];
    struct Friend *next;
};

void push(char new_friend[50], struct Friend **head_ref) {

    struct Friend *new_f = malloc(sizeof(struct Friend));
    strcpy(new_f->name, new_friend);
    new_f->next = NULL;

    
    if (*head_ref == NULL) {
        *head_ref = new_f;
    } else {

        struct Friend *pointer_new_friend = *head_ref;
        while (pointer_new_friend->next != NULL) {
            pointer_new_friend = pointer_new_friend->next;
        }
        
        pointer_new_friend->next = new_f;
    }

}

struct Friend* find(char friend_to_find[50], struct Friend *head_ref) {
    struct Friend *current = head_ref;
    while (current->next != NULL) {
        if (strcmp(current->next->name, friend_to_find) == 0) {
            return current;
        } else if (strcmp(current->name, friend_to_find) == 0) {
            struct Friend *new_f = malloc(sizeof(struct Friend));
            strcpy(new_f->name, "None");
            new_f->next = current;
            return new_f;
        }

        current = current->next;
    }

    return NULL;
}

int main() {
    char L[500];
    char N[500];
    char S[50];

    gets(L);
    gets(N);
    gets(S);

    struct Friend *head_friend_list = NULL;
    char *token = strtok(L, " ");
    while (token != NULL) {
        push(token, &head_friend_list);
        token = strtok(NULL, " ");
    }

    struct Friend *head_new_friends = NULL;
    token = strtok(N, " ");
    while (token != NULL) {
        push(token, &head_new_friends);
        token = strtok(NULL, " ");
    }
    
    if (strcmp(S, "nao") != 0) {
        struct Friend *current = find(S, head_friend_list);

        if (current != NULL) {
            struct Friend *next_of_current = current->next;
            current->next = head_new_friends;

            if (strcmp(current->name, "None") == 0) {
                head_friend_list = current->next;
            }

            while (current->next != NULL) {
                current = current->next;
            }

            current->next = next_of_current;
        }
    } else {
        struct Friend *current = head_friend_list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = head_new_friends;
    }

    struct Friend *current = head_friend_list;
    while (current != NULL) {
        printf("%s", current->name);
        if (current->next != NULL) {
            printf(" ");
        }
        current = current->next;
    }

    printf("\n");
}