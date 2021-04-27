#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SocialNetwork.h"

/* procedure that read the data of a user */
void Read(TUser* user)
{
	printf("Enter the user name: \n");
	fgets(user->name, 100, stdin);
	setbuf(stdin, NULL);
	printf("Enter email: \n");
	fgets(user->email, 200, stdin);
	setbuf(stdin, NULL);
	printf("Enter the login: \n");
	fgets(user->login, 50, stdin);
	setbuf(stdin, NULL);
	printf("Enter the password: \n");
	fgets(user->password, 50, stdin);
	setbuf(stdin, NULL);
	printf("Enter the date of birth: \n\tDay: ");
	scanf("%d", &user->date_of_birth.day);
	setbuf(stdin, NULL);
	printf("\tMonth: ");
	scanf("%d", &user->date_of_birth.month);
	setbuf(stdin, NULL);
	printf("\tYear: ");
	scanf("%d", &user->date_of_birth.year);
	setbuf(stdin, NULL);
}

/* procedure that print the data of a user */
void Print(TUser user)
{
	printf("User name: %s\n", user.name);
	printf("User email: %s\n", user.email);
	printf("User login: %s\n", user.login);
	printf("User password: %s\n", user.password);
	printf("User ID: %d\n\n", user.ID);
	printf("User date of birth: \n");
	printf("\tDay: %d\n", user.date_of_birth.day);
	printf("\tMonth: %d\n", user.date_of_birth.month);
	printf("\tYear: %d\n", user.date_of_birth.year);
}

/* procedure that initialize the social network and make the index receive 0 
and the positions in the matrix of friendship receive 0*/
void Initialize(TSocialNetwork* network)
{
	network->index = 0;
	for (int row = 0; row < 100; row++)
	{
		for (int column = 0; column < 100; column++)
		{
			network->matrix[row][column] = 0;
		}
	}
}

/* procedure that register a new user in the social network */
void Register(TSocialNetwork* network, TUser user)
{
	if (network->index < 100)
	{
		user.ID = network->index;
		network->vector[network->index] = user;
		network->index++;
	}
	else
		printf("Error! Full user list.");
}

/* procedure that print all users in social network */
void Print_2(TSocialNetwork network)
{
	for (int count = 0; count < network.index; count++)
	{
		if(network.vector[count].ID != -1)
			Print(network.vector[count]);
	}
}

/* function that search for a user in social network through your name */
int Search(TSocialNetwork network, TUser user)
{
	for (int i = 0; i < network.index; i++)
	{
		if (strcmp(network.vector[i].name, user.name) == 0)
		{
			return i;
		}
	}
	return -1;

}

/* procedure that change the data of a user */
void Change(TSocialNetwork* network, TUser user, int id)
{
	network->vector[id] = user;
}

/* procedure that delete a user from the social network and make his id 0 and his friendship list positions 0 */
void Delete(TSocialNetwork* network, int id)
{
	network->vector[id].ID = -1;
	for (int row = 0; row < network->index; row++)
	{
		if (network->matrix[row][id] == 1)
		{
			network->matrix[row][id] = 0;
			network->matrix[id][row] = 0;
		}
	}

		

}
