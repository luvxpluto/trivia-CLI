//
// Created by Luvxpluto on 8/3/24.
//
#include "players.h"
#include "input.h"
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
    getInput("Enter the player ID: ",id,sizeof(id),"id");

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
    getInput("Enter the player ID: ",id,sizeof(id),"id");
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

void updateName(PlayersList *players)  {
    if (players->start == NULL) {
        printf("No players registered\n");
        return;
    }

    char id[25], name[50];
    getInput("Enter the player ID: ",id,sizeof(id),"id");
    getInput("Enter the new name: ",name,sizeof(name),"name");

    Node *i;
    for (i = players->start; i != NULL; i = i->next) {
        if (strcmp(i->Player.id, id) == 0) {
            i->Player.name = strdup(name);
            printf("Name changed successfully\n");
            return;
        }
    }
    printf("Player not found\n");
}

void updateNickname(PlayersList *players) {
    if (players->start == NULL) {
        printf("No players registered\n");
        return;
    }

    char id[25],nickname[50];
    getInput("Enter the player ID: ",id,sizeof(id),"id");
    getInput("Enter the new nickname: ",nickname,sizeof(nickname),"nickname");

    Node *i;
    for (i = players->start; i != NULL; i = i->next) {
        if (strcmp(i->Player.id, id) == 0) {
            i->Player.nickname = strdup(nickname);
            printf("Nickname changed successfully\n");
            return;
        }
    }
    printf("Player not found\n");
}

void updateEmail(PlayersList *players) {
    if (players->start == NULL) {
        printf("No players registered\n");
        return;
    }

    char id[25],email[50];
    getInput("Enter the player ID: ",id,sizeof(id),"id");
    getInput("Enter the new email: ",email,sizeof(email),"email");

    Node *i;
    for (i = players->start; i != NULL; i = i->next) {
        if (strcmp(i->Player.id, id) == 0) {
            i->Player.email = strdup(email);
            printf("Email changed successfully\n");
            return;
        }
    }
    printf("Player not found\n");
}

Player getPlayerData(){
    char id[25],name[50],nickname[30],email[50];

    getInput("Enter the player ID: ",id,sizeof(id),"id");
    getInput("Enter the player name: ",name,sizeof(name),"name");
    getInput("Enter the player nickname: ",nickname,sizeof(nickname),"nickname");
    getInput("Enter the player email: ",email,sizeof(email),"email");

    Player player;
    player.id = strdup(id);
    player.name = strdup(name);
    player.nickname = strdup(nickname);
    player.email = strdup(email);
    return player;
}

void createPlayer(PlayersList *players){
    Player player = getPlayerData();
    addPlayer(players,player);
}