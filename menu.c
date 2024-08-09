//
// Created by Luvxpluto on 8/9/24.
//

#include "menu.h"
#include "players.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>

void handleUpdatePlayerMenu(PlayersList *players){
    char option[10];

    while(1){
        getInput("\n-- Update player info --\nSelect the update you want to perform:\n1.Update name"
                 "\n2.Update nickname\n3.Update email\n4.Go back\nOption: ",option,sizeof(option),"option");

        int optNum = (int)strtol(option, (char **)NULL, 10);
        switch (optNum) {
            case 1:
                updateName(players);
                break;
            case 2:
                updateNickname(players);
                break;
            case 3:
                updateEmail(players);
                break;
            case 4:
                return;
            default:
                printf("\nSelect a valid option\n");
                break;
        }
    }
}

void handlePlayerMenu(PlayersList *players){
    char option[10];

    while(1){
        getInput("\n-- Player Menu --\nSelect the option you want to perform:\n1.Register player"
                 "\n2.Update player information\n3.Delete player information\n4.View all registered players"
                 "\n5.View specific player\n6.Go back\nOption: ",option,sizeof(option),"option");

        int optNum = (int)strtol(option, (char **)NULL, 10);
        switch (optNum) {
            case 1:
                createPlayer(players);
                break;
            case 2:
                handleUpdatePlayerMenu(players);
                break;
            case 3:
                deletePlayer(players);
                break;
            case 4:
                viewPlayers(players);
                break;
            case 5:
                viewPlayer(players);
                break;
            case 6:
                return;
            default:
                printf("\nSelect a valid option\n");
                break;
        }
    }
}

void handleMainMenu(PlayersList *players){
    char option[10];

    while(1){
        getInput("\n----- Trivia Menu -----\nSelect an option:\n1.Questions\n2.Players\n3.Game\n4.Exit\nOption: ",
                 option, sizeof(option), "option");

        int optNum = (int)strtol(option, (char **)NULL, 10);
        switch (optNum) {
            case 1:
                //Add questions menu
                break;
            case 2:
                handlePlayerMenu(players);
                break;
            case 3:
                //Add game menu
                break;
            case 4:
                exit(0);
            default:
                printf("\nSelect a valid option\n");
                break;
        }
    }
}