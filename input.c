//
// Created by Luvxpluto on 8/7/24.
//
#include <stdio.h>
#include <string.h>
#include "input.h"

void getInput(char *prompt, char *buffer, size_t size, char *description) {
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, size, stdin) != NULL) {
            size_t len = strlen(buffer);
            if (len > 0 && buffer[len - 1] == '\n') {
                buffer[len - 1] = '\0';
                len--;
            }
            if (len == 0) {
                printf("Enter a valid %s\n",description);
            } else {
                break;
            }
        } else {
            printf("Error reading input\n");
        }
    }
}