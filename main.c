#include <stdio.h>
#include <stdlib.h>
#include "SocialNetwork.h"
#include "Interface.h"
#include "Exercises.h"

int main()
{
	TUser user, user1;
	TSocialNetwork network;
	user.ID = 0;
	user1.ID = 0;
	Initialize(&network);

	int option = 0;
	do
	{
		system("cls");
		MENU_MSG();
		printf("\n\nType an option: \n");
		scanf("%d", &option);
		setbuf(stdin, NULL);
		switch (option)
		{
		case 1:
			Module1_Submenu(&network, user);
			break;
		case 2:
			Module2_Submenu(&network, user, user1);
			break;
		case 3:
			Exercises_Module(&network, user, user1);
			break;
		case 4:
			system("cls");
			printf("\n\n\n\t>>>>>>>>>>>> Exiting the program! <<<<<<<<<<<<");
			break;
		default:
			system("cls");
			printf("\n\n\n\t>>>>>>>>>>>> Type an valid option! <<<<<<<<<<<<\n\n");
			system("PAUSE");
		}
	} while (option != 4);
	return 0;
}

