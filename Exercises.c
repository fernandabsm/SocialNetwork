#include <stdio.h>
#include <stdlib.h>
#include "Exercises.h"

/* Exercise a) */
/* Function that return the user with more friends */
int Count_Friends(TSocialNetwork network)
{
	int count = 0, countMax = 0, idMax = 0;
	for (int row = 0; row < network.index; row++)
	{
		for (int column = 0; column < network.index; column++)
		{
			if (network.matrix[row][column] == 1)
				count++;
		}
		if (count > countMax)
		{
			countMax = count;
			idMax = row;
		}
		count = 0;
	}
	return (idMax);
}

/* Exercise b) */
/* function that return amount mutual friends of two non-friends */
int Mutual_Friends_NotFriends(TSocialNetwork network, int id1, int id2)
{
	if (network.matrix[id1][id2] == 0 && network.matrix[id2][id1] == 0)
	{
		int count = 0, i;
		for (i = 0; i < network.index; i++)
		{
			if (network.matrix[id1][i] == 1 && network.matrix[id2][i] == 1)
				count++;
		}
		return (count);
	}
	else
		return -1;
}

/* auxiliary function */
/* auxiliary function that return amount of mutual friends of two friends or non-friends */
int Mutual_Friends(TSocialNetwork network, int id1, int id2)
{
	int count = 0;
	for (int i = 0; i < network.index; i++)
	{
		if (network.matrix[id1][i] == 1 && network.matrix[id2][i] == 1)
			count++;
	}
	return (count);
}

/* Exercise c) */
/* procedure that create a matrix with amount mutual friends of the users in position row / column */
void Matrix_Mutual_Friends(TSocialNetwork* network)
{
	int row, column;
	for (row = 0; row < 100; row++)
	{
		for (column = 0; column < 100; column++)
		{
			network->mutual_friends[row][column] = 0;
		}
	}
	for (row = 0; row < network->index; row++)
	{
		for (column = 0; column < network->index; column++)
		{
			network->mutual_friends[row][column] = Mutual_Friends(*network, row, column);
		}
	}
}

/* auxiliary function */
/* auxiliary function that print the matrix of mutual friends */
void Print_amount_MutualFriends(TSocialNetwork network)
{
	for (int row = 0; row < network.index; row++)
	{
		for (int column = 0; column < network.index; column++)
		{
			printf("\t%d\t", network.mutual_friends[row][column]);
		}
		printf("\n");
	}
}

/* Exercise d) */
/* procedure that checks if two users do not have mutual friends and if that is true, put the ids in the SocialNetwotk struct */
void No_Mutual_Friends(TSocialNetwork* network, int id1, int id2)
{
	network->no_mutual_friends[0] = -1;
	network->no_mutual_friends[1] = -1;
	if (network->mutual_friends[id1][id2] == 0)
	{
		network->no_mutual_friends[0] = id1;
		network->no_mutual_friends[1] = id2;
	}

}

/* Exercise e) */
/* function that search for a intermediate friend of two users and return his id */
int Level1_Relationship(TSocialNetwork network, int id1, int id2)
{
	int mutual_friends;
	mutual_friends = Mutual_Friends_NotFriends(network, id1, id2);
	if (mutual_friends >= 1)
	{
		for (int i = 0; i < network.index; i++)
		{
			if (network.matrix[id1][i] == 1 && network.matrix[id2][i] == 1)
			{
				return (i);
			}
		}
	}
	return -1;
}

/* Exercise f) */
/* function that search for two intermediate friends of two users and return his ids */
void Level2_Relationship(TSocialNetwork network, int id1, int id2, int* id_i1, int* id_i2)
{
	if (network.matrix[id1][id2] == 0 && network.matrix[id2][id1] == 0)
	{
		*id_i1 = -1;
		*id_i2 = -1;
		int count = 0, column = 0, i = 0;


		while(count < 1 && column < network.index)
		{
			if (network.matrix[id1][column] == 1)
			{
				while(count < 1 && i < network.index)
				{
					if (network.matrix[column][i] == 1 && network.matrix[id2][i] == 1)
					{
						*id_i1 = column;
						*id_i2 = i;
						count++;
					}
					i++;
				}
				i = 0;
			}
			column++;
		}
	}
	else
	{
		system("cls");
		printf("\n\n\t>>>>>>>>>> This users are friends! <<<<<<<<<<");
	}
}