//
// Created by Luvxpluto on 8/3/24.
//
#include "players.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


PlayersList *newPlayersList(void){
    PlayersList *players = (PlayersList*) malloc(sizeof (PlayersList));
    if (players == NULL){
        fprintf(stderr,"Error allocating memory for PLayers list\n");
        exit(EXIT_FAILURE);
    }
    players->start = NULL;
    return players;
}

void addPlayer(PlayersList *players, Player p){
    Node *new = (Node *) malloc(sizeof(Node));
    if(new == NULL){
        fprintf(stderr,"Error allocating memory for player node");
        exit(EXIT_FAILURE);
    }
    new->Player = p;
    new->next = NULL;

    if(players->start == NULL){
        players->start = new;
    }
    else{
        Node *current = players->start;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new;
    }
}

void viewPlayers(PlayersList *players){
    if (players->start== NULL) {
        printf("No players registered\n");
        return;
    }
    printf("Players list:\n\n");
    Node *i;
    for (i = players->start; i != NULL; i = i->next) {
        printf("Player Id: %s\n", i->Player.id ? i->Player.id : "N/A");
        printf("Player Name: %s\n", i->Player.name ? i->Player.name : "N/A");
        printf("Player Nickname: %s\n", i->Player.nickname ? i->Player.nickname : "N/A");
        printf("Player Email: %s\n", i->Player.email ? i->Player.email : "N/A");
        printf("----------------------------\n");
    }
}

void viewPlayer(PlayersList *players){
    if (players->start == NULL) {
        printf("No players registered\n");
        return;
    }
    char id[25];
    while(1){
        printf("Enter the player id\n");
        if(fgets(id,sizeof(id),stdin) !=NULL){
            size_t len = strlen(id);
            if (len>0 && id[len-1]=='\n'){
                id[len-1] = '\0';
            }
            if(strlen(id)==0){
                printf("Enter a valid ID\n");
            }
            else{
                break;
            }
        }
        else{
            printf("Error reading input");
            return;
        }
    }
    Node *i;
    for(i=players->start;i!=NULL;i=i->next){
        if(strcmp(id,i->Player.id)==0){
            printf("Player Id: %s\n", i->Player.id ? i->Player.id : "N/A");
            printf("Player Name: %s\n", i->Player.name ? i->Player.name : "N/A");
            printf("Player Nickname: %s\n", i->Player.nickname ? i->Player.nickname : "N/A");
            printf("Player Email: %s\n", i->Player.email ? i->Player.email : "N/A");
            printf("----------------------------\n");
            return;
        }
    }
    printf("Player not found");
}

void deletePlayer(PlayersList *players) {
    if (players->start == NULL) {
        printf("No players registered\n");
        return;
    }
    char id[25];
    while (1) {
        printf("Enter the player ID: ");
        if (fgets(id, sizeof(id), stdin) != NULL) {
            size_t len = strlen(id);
            if (len > 0 && id[len - 1] == '\n') {
                id[len - 1] = '\0';
                len--;
            }
            if (len == 0) {
                printf("Enter a valid ID\n");
            } else {
                break;
            }
        } else {
            printf("Error reading input\n");
            return;
        }
    }

    Node *current = players->start, *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->Player.id, id) == 0) {
            if (previous == NULL) {
                players->start = current->next;
            } else {
                previous->next = current->next;
            }
            printf("The player %s was deleted\n", current->Player.id);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Player not found\n");
}

void updateName(PlayersList *players) {
    char id[25];
    char name[50];

    if (players->start == NULL) {
        printf("No players registered\n");
        return;
    }

    while (1) {
        printf("Enter the player ID: ");
        if (fgets(id, sizeof(id), stdin) != NULL) {
            size_t len = strlen(id);
            if (len > 0 && id[len - 1] == '\n') {
                id[len - 1] = '\0';
                len--;
            }
            if (len == 0) {
                printf("Enter a valid ID\n");
            } else {
                break;
            }
        } else {
            printf("Error reading input\n");
            return;
        }
    }

    while (1) {
        printf("Enter the new name: ");
        if (fgets(name, sizeof(name), stdin) != NULL) {
            size_t len = strlen(name);
            if (len > 0 && name[len - 1] == '\n') {
                name[len - 1] = '\0';
                len--;
            }
            if (len == 0) {
                printf("Enter a valid name\n");
            } else {
                break;
            }
        } else {
            printf("Error reading input\n");
            return;
        }
    }

    Node *i;
    for (i = players->start; i != NULL; i = i->next) {
        if (strcmp(i->Player.id, id) == 0) {
            strcpy(i->Player.name, name);
            printf("Name changed successfully\n");
            return;
        }
    }
    printf("Player not found\n");
}

void updateNickname(PlayersList *players) {
    char id[25];
    char nickname[50];

    if (players->start == NULL) {
        printf("No players registered\n");
        return;
    }

    while (1) {
        printf("Enter the player ID: ");
        if (fgets(id, sizeof(id), stdin) != NULL) {
            size_t len = strlen(id);
            if (len > 0 && id[len - 1] == '\n') {
                id[len - 1] = '\0';
                len--;
            }
            if (len == 0) {
                printf("Enter a valid ID\n");
            } else {
                break;
            }
        } else {
            printf("Error reading input\n");
            return;
        }
    }

    while (1) {
        printf("Enter the new name: ");
        if (fgets(nickname, sizeof(nickname), stdin) != NULL) {
            size_t len = strlen(nickname);
            if (len > 0 && nickname[len - 1] == '\n') {
                nickname[len - 1] = '\0';
                len--;
            }
            if (len == 0) {
                printf("Enter a valid name\n");
            } else {
                break;
            }
        } else {
            printf("Error reading input\n");
            return;
        }
    }

    Node *i;
    for (i = players->start; i != NULL; i = i->next) {
        if (strcmp(i->Player.id, id) == 0) {
            strcpy(i->Player.nickname, nickname);
            printf("Name changed successfully\n");
            return;
        }
    }
    printf("Player not found\n");
}

void updateEmail(PlayersList *players) {
    char id[25];
    char email[50];

    if (players->start == NULL) {
        printf("No players registered\n");
        return;
    }

    while (1) {
        printf("Enter the player ID: ");
        if (fgets(id, sizeof(id), stdin) != NULL) {
            size_t len = strlen(id);
            if (len > 0 && id[len - 1] == '\n') {
                id[len - 1] = '\0';
                len--;
            }
            if (len == 0) {
                printf("Enter a valid ID\n");
            } else {
                break;
            }
        } else {
            printf("Error reading input\n");
            return;
        }
    }

    while (1) {
        printf("Enter the new name: ");
        if (fgets(email, sizeof(email), stdin) != NULL) {
            size_t len = strlen(email);
            if (len > 0 && email[len - 1] == '\n') {
                email[len - 1] = '\0';
                len--;
            }
            if (len == 0) {
                printf("Enter a valid name\n");
            } else {
                break;
            }
        } else {
            printf("Error reading input\n");
            return;
        }
    }

    Node *i;
    for (i = players->start; i != NULL; i = i->next) {
        if (strcmp(i->Player.id, id) == 0) {
            strcpy(i->Player.email, email);
            printf("Name changed successfully\n");
            return;
        }
    }
    printf("Player not found\n");
}