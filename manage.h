#ifndef __MANAGER_H__
#define __MANAGER_H__
/*------------------------------------------*/
#define NBRE_LIGNE 189
#define NBRE_COLONE 2
#define TAILLE_MAX_MOT 50
#define MAX_USER 5
#define NBRE_MAX MAX_USER
#define LOWER  0
#define UPPER  NBRE_LIGNE
/*------------------------------------------*/
void game_manager(void);
int user_id(int elect_list[]);
void show_user_id(int elect_nbre);
void init_list_number(int list_number[]);
void show_list(int list_number[]);
int choice_number(int list_number[]);
void check_choice(int black_list[], int *user_choice, int total_black_list);
void catalog(int user_choice);
int add_in_black_list(int user_choice, int black_list[]);
void delay(int ms);
void chrono(int entrant_nbr, int nbr_choice, int sc);
void answer(int user_choice);
void score(int *pt_sc);
void show_score(int score);
void show_tallies(int tab_score[], int elect_list[], int nbr_of_tally);
int check_tally(int eff_actu_elect, int tab_score[], int elect_list[], int elect_number);
void flushBuffer(void);
/*------------------------------------------*/

#endif