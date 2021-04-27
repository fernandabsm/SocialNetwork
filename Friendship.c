#include <stdio.h>
#include <stdlib.h>
#include "Friendship.h"
#include "SocialNetwork.h"
#include "Exercises.h"

/* procedure that register a new friendship in SocialNetwork making the position in the friendship matrix receive 1*/
void Register_Friendship(TSocialNetwork* network, TUser user1, TUser user2)
{
	int index_user1, index_user2;
	index_user1 = Search(*network, user1);
	index_user2 = Search(*network, user2);
	system("cls");
	if (index_user1 != -1 && index_user2 != -1)
	{
		network->matrix[index_user1][index_user2] = 1;
		network->matrix[index_user2][index_user1] = 1;
		printf("\n\n\t>>>>>>>>>> MSG: Friendship successfully registered! <<<<<<<<<<\n");
	}
	else 
	{
		printf("\n\n\t>>>>>>>>>> MSG: Error! One of the users was not found in the social network. <<<<<<<<<<\n");
	}
}

/* function that search if two users are friends looking in the matrix of friendship. If it's true, return 1. */
int Search_Friendship(TSocialNetwork network, TUser user1, TUser user2)
{
	int index_user1, index_user2;
	index_user1 = Search(network, user1);
	index_user2 = Search(network, user2);
	if (index_user1 != -1 && index_user2 != -1)
	{
		if (network.matrix[index_user1][index_user2] == 1 && network.matrix[index_user2][index_user1] == 1)
		{
			return 1;
		}
	}
	return 0;
}

/* procedure that remove a friendship making the position in the matrix of friendship receive 0 */
void Delete_Friendship(TSocialNetwork* network, TUser user1, TUser user2)
{
	int index_user1, index_user2;
	index_user1 = Search(*network, user1);
	index_user2 = Search(*network, user2);
	if (index_user1 != -1 && index_user2 != -1)
	{
		if (network->matrix[index_user1][index_user2] == 1 && network->matrix[index_user2][index_user1] == 1)
		{
			network->matrix[index_user1][index_user2] = 0;
			network->matrix[index_user2][index_user1] = 0;
			printf("\n\n\t>>>>>>>>>> MSG: Friendship successfully deleted! <<<<<<<<<<\n");
		}
		else
			printf("\n\n\t>>>>>>>>>> MSG: This users aren't friends! <<<<<<<<<<\n");
	}
	else
	{
		system("cls");
		printf("\n\n\t>>>>>>>>>> MSG: Error! One of the users was not found in the social network. <<<<<<<<<<\n");
	}
}

/* procedure that print the list of friendship of a user */
void Print_Friendship(TSocialNetwork network, TUser user)
{
	int index_user;
	index_user = Search(network, user);
	if (index_user != -1)
	{
		for (int i = 0; i < network.index; i++)
		{
			if (network.matrix[index_user][i] == 1)
			{
				Print(network.vector[i]);
				printf("\n\n");
			}
		}
	}
	else
	{
		system("cls");
		printf("\n\n\t>>>>>>>>>> MSG: Error! The user was not found in the social network. <<<<<<<<<<\n");
	}
}