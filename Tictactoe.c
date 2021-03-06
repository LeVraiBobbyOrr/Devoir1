/*
 * Tictactoe.c
 *
 *  Created on: Oct 3, 2017
 *      Author: David-Gabriel Verrette et Antoine Fortin
 */

#include "Tictactoe.h"
#include <stdio.h>

void imprimer() {
	/*for (i = 0; i < 3; i++) {
	 if ((i % 2) != 0 && i != 1) {
	 printf("-----------\n");
	 }
	 for (int j = 0; j < 3; j++) {
	 printf(" %c ", tab[i][j]);
	 printf("|");
	 }
	 printf("\n");
	 }*/
	printf("\n");
	printf(" %c | %c | %c\n", tab[0][0], tab[0][1], tab[0][2]);
	printf("-----------\n");
	printf(" %c | %c | %c\n", tab[1][0], tab[1][1], tab[1][2]);
	printf("-----------\n");
	printf(" %c | %c | %c\n", tab[2][0], tab[2][1], tab[2][2]);
}
char aQuiLeTour() {
	if (tour % 2 == 0)
		return JOUEUR2;
	else
		return JOUEUR1;
}
/*Permet de d�finir quand est-ce que la partie est termin�e*/
int gagnantPartie() {
	for (i = 0; i < 3; i++) {
		// V�rifie les rang�es.
		if (tab[i][0] == tab[i][1] && tab[i][1] == tab[i][2]
				&& (tab[i][0] == JOUEUR1 || tab[i][0] == JOUEUR2)) {
			return 1;
		}
		// V�rifie les colonnes.
		if (tab[0][i] == tab[1][i] && tab[1][i] == tab[2][i]
				&& (tab[0][i] == JOUEUR1 || tab[0][i] == JOUEUR2)) {
			return 1;
		}
		// V�rifie la diagonale du bas � gauche vers le haut � droite du
		// tableau.
		if (tab[2][0] == tab[1][1] && tab[1][1] == tab[0][2]
				&& (tab[2][0] == JOUEUR1 || tab[2][0] == JOUEUR2)) {
			return 1;
		}
		// V�rifie la diagonale du bas � droite vers le haut � gauche du
		// tableau.
		if (tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2]
				&& (tab[0][0] == JOUEUR1 || tab[0][0] == JOUEUR2)) {
			return 1;
		}

	}
	return 0;
}
int egalite() {
	if (gagnantPartie() == 0 && tab[0][0] != '1' && tab[0][1] != '2'
			&& tab[0][2] != '3' && tab[1][0] != '4' && tab[1][1] != '5'
			&& tab[1][2] != '6' && tab[2][0] != '7' && tab[2][1] != '8'
			&& tab[2][2] != '9') {
		return 1;
	}
	return 0;
}
void remplirTab() {
	char n = '1';
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			tab[i][j] = n;
			n++;
		}
	}
}
void initialiserManche() {
	for (partie = 1; partie <= NBMAX; partie++) {
		printf("\nD�but de la partie #%d:\n", partie);
		remplirTab();
		initialiserPartie();
	}
}
void initialiserPartie() {
	imprimer();
	do {
		printf("\nVeuillez choisir une case parmi les 9 suivantes:");
		scanf("%d", &choixJoueur);
		if (choixJoueur > 0 && choixJoueur < 10) {
			choixJoueur--;
			if (tab[choixJoueur / 3][choixJoueur % 3] != 'X'
					&& tab[choixJoueur / 3][choixJoueur % 3] != 'O') {
				tab[choixJoueur / 3][choixJoueur % 3] = aQuiLeTour();
				imprimer();
				tour++;
			}
		}
	} while (gagnantPartie() == 0 && egalite() == 0);
	tour--;
	if (gagnantPartie() == 1) {
		if (aQuiLeTour() == JOUEUR1) {
			printf("Le JOUEUR 1 a gagn� la manche !");
		} else if (aQuiLeTour() == JOUEUR2) {
			printf("Le JOUEUR 2 a gagn� la manche!");
		}
	}
	if (egalite() == 1) {
		printf("�galit� !");
	}
}
int main() {
	setbuf(stdout, NULL);
	printf("Bienvenue au Jeu Tic-Tac-Toe !\n");
	printf("Le JOUEUR 1 joue les X et le JOUEUR 2 joue les O\n");
	initialiserManche();
	return 0;
}
