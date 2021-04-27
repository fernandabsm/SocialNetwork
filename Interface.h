#pragma once
#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h>
#include <stdlib.h>
#include "SocialNetwork.h"
#include "Friendship.h"
#include "Exercises.h"

void MENU_MSG(); /* Menu of options */
void SUBMENU_MSG(int module_number); /* Submenu */
void Module1_Submenu(TSocialNetwork* network, TUser user); /* procedure of the module of user management */
void Module2_Submenu(TSocialNetwork* network, TUser user1, TUser user2); /* procedure of the module of friendship management */
void Exercises_Module(TSocialNetwork* network, TUser user1, TUser user2); /* extra procedure of the module of exercises */

#endif // !INTERFACE_H