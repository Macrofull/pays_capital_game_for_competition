#include "manage.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int replay = 1;

	while(replay == 1)
	{
		system("cls");
		game_manager();

		printf("Si vous souhaitez rejouer taper 1 sinon taper 0 pour fermer la session. >> ");
		scanf("%d", &replay);
		flushBuffer();
	}

	return 0;
}
