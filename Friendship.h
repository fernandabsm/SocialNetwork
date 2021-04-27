#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "SocialNetwork.h"
#include "Exercises.h"

#ifndef FRIENDSHIP_H
#define FRIENDSHIP_H

void Register_Friendship(TSocialNetwork* network, TUser user1, TUser user2); /* procedure that register a new friendship in SocialNetwork making the position in the friendship matrix receive 1*/
int Search_Friendship(TSocialNetwork network, TUser user1, TUser user2); /* function that search if two users are friends looking in the matrix of friendship. If it's true, return 1. */
void Delete_Friendship(TSocialNetwork* network, TUser user1, TUser user2); /* procedure that remove a friendship making the position in the matrix of friendship receive 0 */
void Print_Friendship(TSocialNetwork network, TUser user); /* procedure that print the list of friendship of a user */

#endif // !FRIENDSHIP_H
