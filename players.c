//
// Created by Luvxpluto on 8/3/24.
//
#include "players.h"
#include <stdio.h>
#include <stdlib.h>


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

void viewPlayers(PlayersList *players) {
    Node *i = players->start;
    if (i == NULL) {
        printf("No players registered\n");
    } else {
        printf("Players list:\n\n");
        for (i = players->start; i != NULL; i = i->next) {
            printf("Player Id: %s\n", i->Player.id ? i->Player.id : "N/A");
            printf("Player Name: %s\n", i->Player.name ? i->Player.name : "N/A");
            printf("Player Nickname: %s\n", i->Player.nickname ? i->Player.nickname : "N/A");
            printf("Player Email: %s\n", i->Player.mail ? i->Player.mail : "N/A");
            printf("----------------------------\n");
        }
    }
}
