#include "manage.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
/*-----------------------------------------------------------------------------------------*/
signed char pays_list[NBRE_LIGNE][NBRE_COLONE][TAILLE_MAX_MOT] =
{
	{"Afghanistan", "Kaboul"},
	{"Afrique du sud", "Pretoria"},
	{"Albanie", "Tirana"},
	{"Algerie", "Alger"},
	{"Allemagne", "Berlin"},
	{"Andorre", "Andorre-la-vieille"},
	{"Angola", "Luanda"},
	{"Antigua-et-barbuda", "Saint john's"},
	{"Arabie saoudite", "Riyad"},
	{"Argentine", "Buenos aires"},
	{"Armenie", "Erevan"},
	{"Australie", "Canberra"},
	{"Autriche", "Vienne"},
	{"Azerbaidjan", "Bakou"},
	{"Bahanas", "Nassau"},
	{"Bahrein", "Manama"},
	{"Bangladesh", "Dacca"},
	{"Barbade", "Bridgetown"},
	{"Belgique", "Bruxelles"},
	{"Belize", "Belmopan"},
	{"Benin", "Porto-novo"},
	{"Bhoutan", "Thimbu"},
	{"Bielorussie", "Minsk"},
	{"Birmanie", "Naypyidaw"},
	{"Bolivie", "La Paz et Sucre"},
	{"Bosnie-Herzegovine", "Sarajevo"},
	{"Botswana", "Gaborone"},
	{"Bresil", "Brasilia"},
	{"Brunei", "Bandar Seri Begawan"},
	{"Bulgarie", "Sofia"},
	{"Burkina Faso", "Ouagadougou"},
	{"Burundi", "Bujumbura"},
	{"Cambodge", "Phnom Penh"},
	{"Cameroun", "Yaounde"},
	{"Canada", "Ottawa"},
	{"Cap-Vert", "Praia"},
	{"Chili", "Santiago"},
	{"Chine", "Pekin"},
	{"Chypre", "Nicosie"},	
	{"Colombie", "Bogota"},
	{"Comores", "Moroni"},	
	{"Congo", "Brazzaville"},
	{"Coree du Nord", "Pyongyang"},
	{"Coree du Sud", "Seoul"},
	{"Costa Rica", "San Jose"},
	{"Cote d'Ivoire", "Yamoussokro"},
	{"Croatie", "Zagreb"},
	{"Cuba", "La Havane"},
	{"Danemark", "Copenhague"},	
	{"Djibouti", "Djibouti"},
	{"Dominique", "Roseau"},
	{"Egypte", "Le Caire"},
	{"Emirats Arabes Unis", "Abu Dhabi"},
	{"Equateur", "Quito"},
	{"Erythree", "Asmara"},
	{"Espagne", "Madrid"},
	{"Estonie", "Tallinn"},
	{"Etats-Unis", "Washington"},
	{"Ethiopie", "Addis-Abeba"},
	{"Fidji", "Suva"},
	{"Finlande", "Helsinki"},
	{"France", "Paris"},
	{"Gabon", "Libreville"},
	{"Gambie", "Banjul"},
	{"Geogie", "Tbilissi"},
	{"Ghana", "Accra"},
	{"Grece", "Athenes"},
	{"Grenade", "Saint George's"},
	{"Guatemala", "Guatemala"},
	{"Guinee", "Conakry"},
	{"Guinee equatoriale", "Malabo"},
	{"Guinee-Bissau", "Bissau"},
	{"Guyana", "Georgetown"},
	{"Haiti", "Port-au-Prince"},
	{"Honduras", "Tegucigalpa"},
	{"Hongrie", "Budapest"},
	{"Ile Maurice", "Port Louis"},
	{"Inde", "New Delhi"},
	{"Indonesie", "Jakarta"},
	{"Irak", "Bagdad"},
	{"Iran", "Teheran"},
	{"Irlande", "Dublin"},
	{"Islande", "Reykjavik"},
	{"Israel", "Jerusalem"},
	{"Italie", "Rome"},
	{"Jamaique", "Kingston"},
	{"Japon", "Tokyo"},	
	{"Jordanie", "Amman"},
	{"Kazakhstan", "Astana"},
	{"Kenya", "Nairobi"},	
	{"Kirghizistan", "Bichkek"},
	{"Kiribati", "Tarawa"},
	{"Kosovo", "Pristina"},
	{"Koweit", "Koweit"},
	{"Laos", "Vientiane"},
	{"Lesotho", "Maseru"},
	{"Lettonie", "Riga"},
	{"Liban", "Beyrouth"},
	{"Liberia", "Monrovia"},
	{"Libye", "Tripoli"},
	{"Liechtenstein", "Vaduz"},
	{"Lituanie", "Vilnius"},
	{"Luxembourg", "Luxembourg"},
	{"Macedoine", "Skopje"},
	{"Madagascar", "Antananarivo"},	
	{"Malaisie", "Kuala Lumpur"},
	{"Malawi", "Lilogwe"},
	{"Maldives", "Male"},	
	{"Mali", "Bamako"},
	{"Malte", "La Valette"},
	{"Maroc", "Rabat"},
	{"Marshall", "Majuro"},
	{"Mauritanie", "Nouakchott"},		
	{"Mexique", "Mexico"},
	{"Micronesie", "Palikir"},
	{"Moldavie", "Chisinau"},
	{"Monaco", "Monaco"},
	{"Mongolie", "Oulan-Bator"},
	{"Montenegro", "Podgorica"},
	{"Mozambique", "Maputo"},
	{"Namibie", "Windhoek"},	
	{"Nauru", "Yaren"},	
	{"Nepal", "Katmandou"},
	{"Nicaragua", "Managua"},
	{"Niger", "Niamey"},
	{"Nigeria", "Abuja"},
	{"Norvege", "Oslo"},
	{"Nouvelle-Zelande", "Wellington"},	
	{"Oman", "Mascate"},
	{"Ouganda", "Kampala"},
	{"Ouzbekistan", "Tachkent"},
	{"Pakistan", "Islamabad"},
	{"Palaos", "Melekeok"},
	{"Palestine", "Jerusalem-Est"},	
	{"Panama", "Panama"},
	{"Papouasie-Nouvelle-Guinee", "Port Moresby"},
	{"Paraguay", "Asuncion"},
	{"Pays-Bas", "Amsterdam"},
	{"Perou", "Lima"},
	{"Philippines", "Manille"},
	{"Pologne", "Varsovie"},
	{"Portugal", "Lisbonne"},
	{"Qatar", "Doha"},
	{"Republique Centrafricaine", "Bangui"},
	{"Republique Democratique du Congo", "Kinshasa"},
	{"Republique Dominicaine", "Saint-Domingue"},
	{"Republique Tcheque", "Prague"},
	{"Roumanie", "Bucarest"},
	{"Royaume-Uni", "Londres"},
	{"Russie", "Moscou"},
	{"Rwanda", "Kigali"},
	{"Saint-Kitts-et-Nevis", "Basseterre"},
	{"Saint-Marin", "Saint-Marin"},
	{"Saint-Vincent-et-les-Grenadines", "Kingstown"},
	{"Sainte-Lucie", "Castries"},
	{"Salomon", "Honiara"},
	{"Salvador", "San Salvador"},
	{"Samoa", "Apia"},
	{"Sao tome et Principe", "Sao tome"},				
	{"Senegal", "Dakar"},
	{"Serbie", "Belgrade"},
	{"Seychelles", "Victoria"},
	{"Sierra Leonne", "Freetown"},
	{"Singapour", "Singapour"},
	{"Slovaquie", "Bratislava"},
	{"Slovenie", "Ljubljana"},
	{"Somalie", "Mogadiscio"},
	{"Soudan", "Khartoum"},
	{"Soudan du sud", "Djouba"},
	{"Sri lanka", "Colombo"},
	{"Suede", "Stockholm"},
	{"Suisse", "Berne"},
	{"Suriname", "Paramaribo"},
	{"Swaziland", "Mbabane"},
	{"Syrie", "Damas"},
	{"Tadjikistan", "Douchanbe"},
	{"Taiwan", "Taipei"},
	{"Tanzanie", "Dodoma"},
	{"Tchad", "N'Djamena"},
	{"Thailande", "Bangkok"},
	{"Timor-Orientale", "Dili"},
	{"Togo", "Lome"},
	{"Tonga", "Nukualofa"},
	{"Trinite-et-Tobago", "Port of Spain"},	
	{"Tunisie", "Tunis"},
	{"Turkmenistan", "Achgabat"}, 	
	{"Tuvalu", "Funafuti"},	
	{"Uruguay", "Montevideo"}	
};
/*-----------------------------------------------------------------------------------------*/
void game_manager(void)
{
	int elect_number = 0, number_choice = 0, tally = 0, elmt_black_list = 1, num_candidat = 0;
	int  nbr_de_pays_actu = NBRE_LIGNE, eff_actu_elect = 0;
	int *pt_tally = &tally;
	int black_list[NBRE_LIGNE] = {0};
	int elect_list[MAX_USER] = {0};
	int nbr_to_choice[NBRE_MAX] = {0};
	int tab_score[MAX_USER] = {0};
	signed char play_again = 'o';


	printf("\n");
	elect_number = user_id(elect_list);
	eff_actu_elect = elect_number;
	system("cls");
	srand(time(NULL));

	do
	{
		for(int p = 0; p < eff_actu_elect; p++)
		{
			system("cls");
			num_candidat = elect_list[p];
			show_user_id(num_candidat);	
			init_list_number(nbr_to_choice);
			show_list(nbr_to_choice);
			number_choice = choice_number(nbr_to_choice);
			check_choice(black_list, &number_choice, elmt_black_list);
			elmt_black_list = add_in_black_list(number_choice, black_list);
			delay(500);
			system("cls");
			chrono(num_candidat, number_choice, tab_score[p]);
			show_user_id(num_candidat);
			catalog(number_choice);
			answer(number_choice);
			score(pt_tally);
			tab_score[p] += tally; 
			tally = 0;
			show_score(tab_score[p]);
			nbr_de_pays_actu--;	
			system("pause");
		}

		int eff_actu_elect_av = eff_actu_elect;

		eff_actu_elect = check_tally(eff_actu_elect, tab_score, elect_list, elect_number);

		int elect_disc = eff_actu_elect_av - eff_actu_elect;

		if(elect_disc >= 1)
		{	
			system("cls");
			show_tallies(tab_score, elect_list, elect_number);
			int cmpt_start = elect_number - 1;
			printf("\nNUMEROS DES CANDIDATS DEJA ELMINES : ");
			elect_disc = elect_number - eff_actu_elect;
			for(int t = 0; t < elect_disc; t++)
			{
				printf("%d ", elect_list[cmpt_start]);
				cmpt_start--;
			}

			delay(5000);
			if(elect_disc != elect_number - 1)
			{
				printf("\n\n");
				system("pause");
			}
		}

		if(nbr_de_pays_actu < eff_actu_elect || eff_actu_elect <= 1)
		{
			play_again = 'n';
		}
		else
		{
			printf("\n");
			printf("Souhaitez vous continuer ? (o/n) >> ");
			scanf("%c", &play_again);
			flushBuffer();
		}

		if(tolower(play_again) == 'n')
		{
			system("cls");
			delay(1000);
			printf("\n");
			show_tallies(tab_score, elect_list, elect_number);
			printf("\n\n\t\t===FIN DE LA PARTIE!!!===\n\n");
		}
	}
	while(tolower(play_again) == 'o');
}
/*-----------------------------------------------------------------------------------------*/
int user_id(int elect_list[])
{
	int cpt = 0, elect_id = -1;
	int a_other_elect = 1, ask_again = 0;

	do
	{
	 	ask_again = 0;
		if(a_other_elect == 1)
		{
			printf("Candidat numero ? >> ");
			scanf("%d", &elect_id);
			flushBuffer();

			for(int i = 0; i < cpt; i++)
				if(elect_id == elect_list[i])
					ask_again = 1;

			if(ask_again == 1)
			{
				printf("Le candidat numero %d existe deja modifier votre numero!!!\n", elect_id);
			}
			else
			{
				elect_list[cpt] = elect_id;
				cpt++;
			}	
		}

		if(cpt < MAX_USER && ask_again == 0)
		{
			printf("Un autre candidat ? (1/0) >> ");
			scanf("%d", &a_other_elect);
			flushBuffer(); 
		}

		if(a_other_elect == 0 && cpt == 1)
		{
			printf("Enregistre au moins 2 candidats\n");
			a_other_elect = 1;
		}
	}
	while(a_other_elect == 1 && cpt < MAX_USER);

	return cpt;
}
/*-----------------------------------------------------------------------------------------*/
void show_user_id(int elect_nbre)
{
	printf("\n");
	printf("\t****candidat numero %d****\n", elect_nbre);
}
/*-----------------------------------------------------------------------------------------*/
void init_list_number(int list_number[])
{
	int al_nbr = 0, change = 0;

	for(int j = 0; j < NBRE_MAX; j++)
	{
		al_nbr = (rand() % (UPPER - LOWER +1)) + LOWER + 1;

		do
		{
			change = 0;

			for(int i = 0; i < j; i++)
				if(al_nbr == list_number[i])
					change = 1;

			if(change != 1)
			{
				list_number[j] = al_nbr;
			}
			else
				al_nbr = (rand() % (UPPER - LOWER +1)) + LOWER + 1;
		}
		while(change == 1);
	}
}
/*-----------------------------------------------------------------------------------------*/
void show_list(int list_number[])
{
	printf("NOMBRES : ");
	for(int i = 0; i < NBRE_MAX; i++)
		printf("%d ", list_number[i]);

	printf("\n");
}
/*-----------------------------------------------------------------------------------------*/
int choice_number(int list_number[])
{
	int result = 0;
	int again = 1;

	do
	{
		printf("Veuillez piocher votre nombre >> ");
		scanf("%d", &result);
		flushBuffer();

		for(int i = 0; i < NBRE_MAX; i++)
		{
			if(result == list_number[i])
				again--;
		}

		if(again == 1)
			printf("Le nombre n'appartient pas a la liste propose\n");
	}
	while(again == 1);

	//srand(time(NULL));
	result = (rand() % (UPPER - LOWER +1)) + LOWER;

	return result;
}
/*-----------------------------------------------------------------------------------------*/
void check_choice(int black_list[], int *user_choice, int total_black_list)
{
	int k = 0;

	do
	{
		if(*user_choice == black_list[k])
		{
			*user_choice = (rand() % (UPPER - LOWER +1)) + LOWER;
			k = 0;
		}
		else
			k++;
	}
	while(black_list[k] == *user_choice || k < total_black_list);
	
}
/*-----------------------------------------------------------------------------------------*/
void catalog(int user_choice)
{
	printf("Pays choisi : %s\n", pays_list[user_choice - 1][0]);
	printf("Quelle est la capitale du pays que vous avez choisi ?\n");
}
/*-----------------------------------------------------------------------------------------*/
int add_in_black_list(int user_choice, int black_list[])
{
	static int cmpt = 0;

	black_list[cmpt] = user_choice;
	cmpt++;

	return cmpt;
}
/*-----------------------------------------------------------------------------------------*/
void delay(int ms)
{	
	clock_t timeDelay = ms + clock();	
	while(timeDelay > clock());
}
/*-----------------------------------------------------------------------------------------*/
void chrono(int entrant_nbr, int nbr_choice, int sc)
{
	int time = 10;

	for(time == 10; time >= 0; time--)
	{
		show_user_id(entrant_nbr);
		catalog(nbr_choice);
		printf("Reflechiser a la reponse le temps que le chronometre decompte!!!\n");
		show_score(sc);
		printf("\t\tTemps : %d\n", time);
		delay(1000);
		system("cls");
	}
}
/*-----------------------------------------------------------------------------------------*/
void answer(int user_choice)
{
	signed char show_answer = 'a';

	printf("Afficher la reponse?(o/n) >> ");
	scanf("%c", &show_answer);
	flushBuffer();

	if(tolower(show_answer) == 'o')
		printf("Capitale du pays choisi : %s\n", pays_list[user_choice - 1][1]);
}
/*-----------------------------------------------------------------------------------------*/
void score(int *pt_sc)
{
	signed char descision = 'a';

	printf("Avis membre du juri? (o/n) >> ");
	scanf("%c", &descision);
	flushBuffer();

	if(tolower(descision) == 'o')
		*pt_sc += 10;
}
/*-----------------------------------------------------------------------------------------*/
void show_score(int score)
{
	printf("\nScore : %d\n\n", score);
}
/*-----------------------------------------------------------------------------------------*/
void show_tallies(int tab_score[], int elect_list[], int nbr_of_tally)
{
	int j;

	printf("\t\t\t***SCORES***\n");
	printf("\t__Numero candidat-------------Score______\n");
	for(j = 0; j < nbr_of_tally; j++)
		printf("\t|\t%d\t\t\t%d\t|\n", elect_list[j], tab_score[j]);

	printf("\t_________________________________________\n");
}
/*-----------------------------------------------------------------------------------------*/
int check_tally(int eff_actu_elect, int tab_score[], int elect_list[], int elect_number)
{
	int i = 0, j = 0, k = 0, supp = 0, tmp_sc = 0, tmp_elect = 0;

	do
	{
		j = 0;
		do
		{
			if(tab_score[j] - tab_score[i] >= 50)
			{
				supp = 1;
			}
			else
				j++;
		}
		while(j < eff_actu_elect && supp == 0);

		if(supp == 1)
		{
		 	tmp_sc = tab_score[i];	
		 	tmp_elect = elect_list[i];

			tab_score[i] = tab_score[eff_actu_elect - 1];
			elect_list[i] = elect_list[eff_actu_elect - 1];

			tab_score[eff_actu_elect - 1] = tmp_sc;
			elect_list[eff_actu_elect - 1] = tmp_elect;
			eff_actu_elect--;

			if(eff_actu_elect > 1)
			{
				tmp_sc = tab_score[i];	
	 			tmp_elect = elect_list[i];

	 			for(k = i; k < eff_actu_elect - 1; k++)
	 			{
	 				tab_score[k] = tab_score[k + 1];
	 				elect_list[k] = elect_list[k + 1];
	 			}

	 			tab_score[k] = tmp_sc;
 				elect_list[k] = tmp_elect;

			}

			supp = 0;
		}
		else
			i++;
		
	}
	while(i < eff_actu_elect && eff_actu_elect > 1);

	return eff_actu_elect;
}
/*-----------------------------------------------------------------------------------------*/
void flushBuffer(void)
{
	int c = 0;
	while(c != '\n' && c != EOF)
		c = getchar(); // recuperation du caractere '\n' par c et buffer actuellement vide
}
/*-----------------------------------------------------------------------------------------*/