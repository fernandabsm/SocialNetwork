#include <stdio.h>
#include <stdlib.h>
#include "Interface.h"

/* Menu of options */
void MENU_MSG()
{
	printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>>>>  MENU:  <<<<<<<<<<<<<<<<<<<<<<<<<");
	printf("\n\n\t1.  MODULE 1 - USER MANAGEMENT");
	printf("\n\n\t2.  MODULE 2 - FRIENDSHIP MANAGEMENT");
	printf("\n\n\t3.  MODULE 3 - EXERCISES");
	printf("\n\n\t4.  EXIT");
}

/* Submenu */
void SUBMENU_MSG(int module_number)
{
	system("cls");
	if (module_number == 1)
	{
		printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>>>>  MODULE: %d  <<<<<<<<<<<<<<<<<<<<<<<<<", module_number);
		printf("\n\n\t1.  REGISTER");
		printf("\n\t2.  SEARCH");
		printf("\n\t3.  MAKE CHANGE");
		printf("\n\t4.  DELETE");
		printf("\n\t5.  PRINT");
		printf("\n\t6.  EXIT");
	}
	else if(module_number == 2)
	{
		printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>>>>  MODULE: %d  <<<<<<<<<<<<<<<<<<<<<<<<<", module_number);
		printf("\n\n\t1.  REGISTER FRIENDSHIP");
		printf("\n\t2.  SEARCH FRIENDSHIP");
		printf("\n\t3.  DELETE FRIENDSHIP");
		printf("\n\t4.  PRINT LIST OF FRIENDSHIP");
		printf("\n\t5.  EXIT");
	}
	else
	{
		printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>>>>  MODULE: %d  <<<<<<<<<<<<<<<<<<<<<<<<<", module_number);
		printf("\n\n\t1.  USER WITH MORE FRIENDS");
		printf("\n\t2.  AMOUNT OF MUTUAL FRIENDS BETWEEN NON-FRIENDS");
		printf("\n\t3.  CREATE MATRIX OF MUTUAL FRIENDS");
		printf("\n\t4.  CHECK IF TWO USERS HAVE NO MUTUAL FRIENDS");
		printf("\n\t5.  FIND LEVEL 1 INTERMEDIARY FRIEND");
		printf("\n\t6.  FIND LEVEL 2 INTERMEDIARY FRIENDS");
		printf("\n\t7.  EXIT");
	}
	

}

/* procedure of the module of user management */
void Module1_Submenu(TSocialNetwork* network, TUser user)
{
	int option = 0, result_search;
	do
	{
		system("cls");
		SUBMENU_MSG(1);
		printf("\n\nType an option: \n");
		scanf("%d", &option);
		setbuf(stdin, NULL);
		switch (option)
		{
		case 1:
			system("cls");
			printf("\n\n\t>>>>>>>>>> MSG: Registering a new user <<<<<<<<<<\n\n");
			Read(&user);
			Register(network, user);
			break;
		case 2:
			system("cls");
			printf("\n\n\t>>>>>>>>>> MSG: Searching user <<<<<<<<<<\n\n");
			printf("Type the user name that you wish search: \n");
			fgets(user.name, 100, stdin);
			setbuf(stdin, NULL);
			result_search = Search(*network, user);
			if (result_search != -1)
			{
				system("cls");
				Print(network->vector[result_search]);
				system("PAUSE");
			}
			else
			{
				system("cls");
				printf(">>>>>>>>>> MSG: User not found. <<<<<<<<<<\n");
				system("PAUSE");
			}
			break;
		case 3:
			system("cls");
			printf("\n\n\t>>>>>>>>>> MSG: Changing user <<<<<<<<<<\n\n");
			printf("Type the user name that you wish change: \n");
			fgets(user.name, 100, stdin);
			setbuf(stdin, NULL);
			result_search = Search(*network, user);
			if (result_search != -1)
			{
				Read(&user);
				Change(network, user, result_search);
				system("PAUSE");
			}
			else
			{
				printf(">>>>>>>>>> MSG: User not found <<<<<<<<<<\n");
				system("PAUSE");
			}
			break;
		case 4:
			system("cls");
			printf("\n\n\t>>>>>>>>>> MSG: Deleting user <<<<<<<<<<\n\n");
			printf("Type the user name that you wish delete: \n");
			fgets(user.name, 100, stdin);
			setbuf(stdin, NULL);
			result_search = Search(*network, user);
			if (result_search != -1)
			{
				Delete(network, result_search);
				system("PAUSE");
			}
			else
			{
				printf(">>>>>>>>>> MSG: User not found <<<<<<<<<<\n");
				system("PAUSE");
			}
			break;
		case 5:
			system("cls");
			printf("\n\n\t>>>>>>>>>> MSG: Printing user <<<<<<<<<<\n\n");
			Print_2(*network);
			system("PAUSE");
			break;
		case 6:
			system("cls");
			printf("\n\n\n\t>>>>>>>>>>>> Exiting the module! <<<<<<<<<<<<\n\n");
			system("PAUSE");
			break;
		default:
			system("cls");
			printf("\n\n\n\t>>>>>>>>>>>> Type an valid option! <<<<<<<<<<<<\n\n");
			system("PAUSE");
		}
	} while (option != 6);
}

/* procedure of the module of friendship management */
void Module2_Submenu(TSocialNetwork* network, TUser user1, TUser user2)
{
	int option = 0, result_search, count, id_i1 = -1, id_i2 = -1;
	do
	{
		system("cls");
		SUBMENU_MSG(2);
		printf("\n\nType an option: \n");
		scanf("%d", &option);
		setbuf(stdin, NULL);
		switch (option)
		{
		case 1:
			system("cls");
			printf("\n\n\t>>>>>>>>>> MSG: Registering a new friendship <<<<<<<<<<\n\n");
			printf("Enter a username: \n");
			fgets(user1.name, 100, stdin);
			setbuf(stdin, NULL);
			printf("Enter another username: \n");
			fgets(user2.name, 100, stdin);
			setbuf(stdin, NULL);
			Register_Friendship(network, user1, user2);
			system("PAUSE");
			break;
		case 2:
			system("cls");
			printf("\n\n\t>>>>>>>>>> MSG: Searching friendship <<<<<<<<<<\n\n");
			printf("Enter a username: \n");
			fgets(user1.name, 100, stdin);
			setbuf(stdin, NULL);
			printf("Enter another username: \n");
			fgets(user2.name, 100, stdin);
			setbuf(stdin, NULL);
			result_search = Search_Friendship(*network, user1, user2);
			if (result_search == 1)
			{
				system("cls");
				printf("\n\n\t>>>>>>>>>> MSG: Found friendship <<<<<<<<<<\n\n");
				system("PAUSE");
			}
			else
			{
				system("cls");
				printf("\n\n\t>>>>>>>>>> MSG: Friendship not found <<<<<<<<<<\n\n");
				system("PAUSE");
			}
			break;
		case 3:
			system("cls");
			printf("\n\n\t>>>>>>>>>> MSG: Deleting friendship <<<<<<<<<<\n\n");
			printf("Enter a username: \n");
			fgets(user1.name, 100, stdin);
			setbuf(stdin, NULL);
			printf("Enter another username: \n");
			fgets(user2.name, 100, stdin);
			setbuf(stdin, NULL);
			Delete_Friendship(network, user1, user2);
			system("PAUSE");
			break;
		case 4:
			system("cls");
			printf("\n\n\t>>>>>>>>>> MSG: Printing friendships <<<<<<<<<<\n\n");
			printf("Enter the username: \n");
			fgets(user1.name, 100, stdin);
			setbuf(stdin, NULL);
			system("cls");
			printf("\n\n\t>>>>>>>>>> List of friendships <<<<<<<<<<\n\n");
			Print_Friendship(*network, user1);
			system("PAUSE");
			break;
		case 5:
			system("cls");
			printf("\n\n\n\t>>>>>>>>>>>> Exiting the module! <<<<<<<<<<<<\n\n");
			system("PAUSE");
			break;
 		default:
			system("cls");
			printf("\n\n\n\t>>>>>>>>>>>> Type an valid option! <<<<<<<<<<<<\n\n");
			system("PAUSE");
		}
	} while (option != 5);
}


/* extra procedure of the module of exercises */
void Exercises_Module(TSocialNetwork* network, TUser user1, TUser user2)
{
	int option = 0, count, id1, id2, id_i1, id_i2;
	do
	{
		system("cls");
		SUBMENU_MSG(3);
		printf("\n\nType an option: \n");
		scanf("%d", &option);
		setbuf(stdin, NULL);
		switch (option)
		{
			/* Cases 1 to 6, refer to the exercises given */
		case 1:
			system("cls");
			printf("\n\n\t>>>>>>>>>> MSG: Performing the count <<<<<<<<<<\n");
			count = Count_Friends(*network);
			printf("The people with more friends is the ID: %d \n\n", count);
			system("PAUSE");
			break;
		case 2:
			system("cls");
			printf("\n\n\t >>>>>>>>>> MSG: Checking mutual friends of two non-friends <<<<<<<<<<\n\n");
			printf("Enter a username: \n");
			fgets(user1.name, 100, stdin);
			setbuf(stdin, NULL);
			printf("Enter another username: \n");
			fgets(user2.name, 100, stdin);
			setbuf(stdin, NULL);
			id1 = Search(*network, user1);
			id2 = Search(*network, user2);
			system("cls");
			if (id1 != -1 && id2 != -1)
			{
				count = Mutual_Friends_NotFriends(*network, id1, id2);
				if (count != -1)
					printf("The number of mutual friends between the users is: %d\n", count);
				else
					printf("\n\n\t >>>>>>> This users are friends. <<<<<<< \n");
			}
			else
				printf("\n\n\t>>>>>>>>>> MSG: Error! One of the users was not found in the social network. <<<<<<<<<<\n");
			system("PAUSE");
			break;
		case 3:
			system("cls");
			printf("\n\n\t>>>>>> MSG: Creating the matrix of mutual friends <<<<<< \n\n");
			Matrix_Mutual_Friends(network);
			system("PAUSE");
			printf("\n\n\t >>>>>>>>>> MSG: Printing the matrix amount of mutual friends <<<<<<<<<<\n\n");
			Print_amount_MutualFriends(*network);
			system("PAUSE");
			break;
		case 4:
			system("cls");
			printf("\n\n\t >>>>>>>>>> MSG: Checking mutual friends <<<<<<<<<<\n\n");
			printf("Enter a username: \n");
			fgets(user1.name, 100, stdin);
			setbuf(stdin, NULL);
			printf("Enter another username: \n");
			fgets(user2.name, 100, stdin);
			setbuf(stdin, NULL);
			id1 = Search(*network, user1);
			id2 = Search(*network, user2);
			system("cls");
			if (id1 != -1 && id2 != -1)
			{
				No_Mutual_Friends(network, id1, id2);
				if (network->no_mutual_friends[0] != -1 && network->no_mutual_friends[1] != -1)
					printf("This users don't have mutual friends.\n");
				else
					printf("This users have mutual friends.\n");
			}
			else
				printf("\n\n\t>>>>>>>>>> MSG: Error! One of the users was not found in the social network. <<<<<<<<<<\n");
			system("PAUSE");
			break;

		case 5:
			system("cls");
			printf("\n\n\t>>>>>> MSG: Looking for the intermediary friend <<<<<< \n\n");
			printf("Enter a username: \n");
			fgets(user1.name, 100, stdin);
			setbuf(stdin, NULL);
			printf("Enter another username: \n");
			fgets(user2.name, 100, stdin);
			setbuf(stdin, NULL);
			id1 = Search(*network, user1);
			id2 = Search(*network, user2);
			system("cls");
			if (id1 != -1 && id2 != -1)
			{
				count = Level1_Relationship(*network, id1, id2);
				if (count != -1)
					printf("The ID of the intermediary friend is: %d\n", count);
				else
					printf("\n\n\t >>>>>>>>>> MSG: Error. Don't was found level 1 intermediary friend. <<<<<<<<<< \n");
			}
			else
				printf("\n\n\t>>>>>>>>>> MSG: Error! One of the users was not found in the social network. <<<<<<<<<<\n");
			system("PAUSE");
			break;
		case 6:
			system("cls");
			printf("\n\n\t>>>>>> MSG: Looking for the intermediary friends <<<<<< \n\n");
			printf("Enter a username: \n");
			fgets(user1.name, 100, stdin);
			setbuf(stdin, NULL);
			printf("Enter another username: \n");
			fgets(user2.name, 100, stdin);
			setbuf(stdin, NULL);
			id1 = Search(*network, user1);
			id2 = Search(*network, user2);
			system("cls");
			if (id1 != -1 && id2 != -1)
			{
				Level2_Relationship(*network, id1, id2, &id_i1, &id_i2);
				if (id1 != -1 && id_i2 != -1)
					printf("The IDs of the intermediary friends are: %d and %d\n", id_i1, id_i2);
				else
					printf("\n\n\t >>>>>>>>>> MSG: Don't was found level 2 intermediary friends. <<<<<<<<<< \n");
			}
			else
				printf("\n\n\t>>>>>>>>>> MSG: Error! One of the users was not found in the social network. <<<<<<<<<<\n");
			system("PAUSE");
			break;
		case 7:
			system("cls");
			printf("\n\n\n\t>>>>>>>>>>>> Exiting the module! <<<<<<<<<<<<\n\n");
			system("PAUSE");
			break;
		default:
			system("cls");
			printf("\n\n\n\t>>>>>>>>>>>> Type an valid option! <<<<<<<<<<<<\n\n");
			system("PAUSE");
		}
	} while (option != 7);
}

