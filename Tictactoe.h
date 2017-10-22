/*
 * Tictactoe.h

 *
 *  Created on: Oct 3, 2017
 *      Author: David-Gabriel Verrette et Antoine Fortin
 */
#ifndef TICTACTOE_H_
#define TICTACTOE_H_
#define NBMAX 3

/*Déclarations de variables globales*/
int i, j;
int tour = 1;
int partie;
const char JOUEUR1 = 'X';
const char JOUEUR2 = 'O';
int choixJoueur = 0;
char tab[3][3] = { { '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' } };

/*Déclarations des méthodes*/
void imprimer();
void initialiserManche();
void initialiserPartie();
void remplirTab();
char aQuiLeTour();
int gagnantPartie();
int egalite();

#endif /* TICTACTOE_H_ */

