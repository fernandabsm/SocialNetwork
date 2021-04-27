#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "SocialNetwork.h"
#include "Friendship.h"

#ifndef EXERCISES_H
#define EXERCISES_H

int Count_Friends(TSocialNetwork network); /* Function that return the user with more friends */
int Mutual_Friends_NotFriends(TSocialNetwork network, int id1, int id2); /* function that return amount mutual friends of two non-friends */
int Mutual_Friends(TSocialNetwork network, int id1, int id2); /* auxiliary function that return amount of mutual friends of two friends or non-friends */
void Matrix_Mutual_Friends(TSocialNetwork* network); /* procedure that create a matrix with amount mutual friends of the users in position row / column */
void Print_amount_MutualFriends(TSocialNetwork network); /* auxiliary function that print the matrix of mutual friends */
void No_Mutual_Friends(TSocialNetwork* network, int id1, int id2); /* procedure that checks if two users do not have mutual friends and if that is true, put the ids in the SocialNetwotk struct */
int Level1_Relationship(TSocialNetwork network, int id1, int id2); /* function that search for a intermediate friend of two users and return his id */
void Level2_Relationship(TSocialNetwork network, int id1, int id2, int* id_i1, int* id_i2); /* function that search for two intermediate friends of two users and return his ids */

#endif // !EXERCISES_H