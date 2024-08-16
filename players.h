//
// Created by Luvxpluto on 8/3/24.
//

#ifndef TRIVIA_CLI_PLAYERS_H
#define TRIVIA_CLI_PLAYERS_H

typedef struct Node Node;
typedef struct Player Player;
typedef struct PlayersList PlayersList;

struct PlayersList{
    Node *start;
};

struct Player{
    char* id;
    char* name;
    char* nickname;
    char* email;
};

struct Node{
    Player Player;
    Node *next;
};

PlayersList *newPlayersList(void);
void addPlayer(PlayersList *players, Player p);
void viewPlayers(PlayersList *players);
void viewPlayer(PlayersList *players);
void deletePlayer(PlayersList *players);
void updateName(PlayersList *players);
void updateNickname(PlayersList *players);
void updateEmail(PlayersList *players);
Player getPlayerData(PlayersList *players);
void createPlayer(PlayersList *players);
void loadPlayersFromCSV(PlayersList *players);
void freePlayerList(PlayersList * player);
int searchId(PlayersList *players, char *id);
#endif //TRIVIA_CLI_PLAYERS_H
