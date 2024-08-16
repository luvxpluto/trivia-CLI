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
            addAllPlayersCSV(players);
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

    Node *i;
    for (i = players->start; i != NULL; i = i->next) {
        if (strcmp(i->Player.id, id) == 0) {
            getInput("Enter the new name: ",name,sizeof(name),"name");
            i->Player.name = strdup(name);
            printf("Name changed successfully\n");
            addAllPlayersCSV(players);
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

    Node *i;
    for (i = players->start; i != NULL; i = i->next) {
        if (strcmp(i->Player.id, id) == 0) {
            getInput("Enter the new nickname: ",nickname,sizeof(nickname),"nickname");
            i->Player.nickname = strdup(nickname);
            printf("Nickname changed successfully\n");
            addAllPlayersCSV(players);
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

    Node *i;
    for (i = players->start; i != NULL; i = i->next) {
        if (strcmp(i->Player.id, id) == 0) {
            getInput("Enter the new email: ",email,sizeof(email),"email");
            i->Player.email = strdup(email);
            printf("Email changed successfully\n");
            addAllPlayersCSV(players);
            return;
        }
    }
    printf("Player not found\n");
}

Player getPlayerData(PlayersList *players){
    char id[25],name[50],nickname[30],email[50];

    int validInput = 0;
    while(!validInput){
        getInput("Enter the player ID: ", id, sizeof(id), "id");
        if (searchId(players, id)) {
            printf("There's already a player with that ID, please enter a different one.\n");
        } else {
            validInput = 1;
        }
    }

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

void addPlayerCSV(Player p){
    FILE *file;
    file = fopen("Players.csv","a");
    fprintf(file,"%s,%s,%s,%s\n",p.id,p.name,p.nickname,p.email);
    fclose(file);
}

void addAllPlayersCSV(PlayersList *players){
    FILE *file ;
    file = fopen("Players.csv","w");
    for(Node *i = players->start; i != NULL; i = i->next){
        fprintf(file,"%s,%s,%s,%s\n",i->Player.id,i->Player.name,i->Player.nickname,i->Player.email);
    }
    fclose(file);
}

void loadPlayersFromCSV(PlayersList *players) {
    FILE *file = fopen("Players.csv", "r");

    // Check if the file exists
    if (file == NULL) {
        // Create the file if it doesn't exist
        file = fopen("Players.csv", "a");
        if (file == NULL) {
            fprintf(stderr, "Error creating file\n");
            return;
        }
        fclose(file);
        return; // Exit after creating an empty file
    }

    // Proceed if the file is successfully opened for reading
    char line[200];  // Buffer to hold each line from the file
    while (fgets(line, sizeof(line), file)) {
        Player p;
        char *token;

        // Remove the newline character if present
        line[strcspn(line, "\n")] = '\0';

        // Read the ID
        token = strtok(line, ",");
        if (token) p.id = strdup(token);

        // Read the name
        token = strtok(NULL, ",");
        if (token) p.name = strdup(token);

        // Read the nickname
        token = strtok(NULL, ",");
        if (token) p.nickname = strdup(token);

        // Read the email
        token = strtok(NULL, "\n");
        if (token) p.email = strdup(token);

        // Add the player to the list
        addPlayer(players, p);
    }
    fclose(file);
}

int searchId(PlayersList *players, char *id){
    for(Node *i=players->start; i!=NULL; i = i->next){
        if(strcmp(i->Player.id,id)==0){
            return 1;
        }
    }
    return 0;
}

void createPlayer(PlayersList *players){
    Player player = getPlayerData(players);
    addPlayer(players,player);
    addPlayerCSV(player);
}