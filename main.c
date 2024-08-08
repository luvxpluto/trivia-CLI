//
// Created by Luvxpluto on 8/3/24.
//
#include "players.h"

int main(){
    PlayersList *players = newPlayersList();

    createPlayer(players);
    viewPlayers(players);
}
