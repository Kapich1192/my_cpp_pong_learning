/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pong.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dmitriy <kapich1192@yandex.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 09:05:24 by Dmitriy           #+#    #+#             */
/*   Updated: 2022/07/24 09:55:54 by Dmitriy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define HEIGTH 25
#define WEIGTH 80
#define FIELD_MARKER 'o'
#define FIELD_SPACE_SYMBOL ' '
#define BOLL 'o'
#define ROCKET '|'
#define COUNT_WIN 21

void printGameField(char array[HEIGTH][WEIGTH]);
void initializeGameField(char array[HEIGTH][WEIGTH]);
void skip(void);
void listenClick(
		char* exit,
		int* rocket1Y,
		int* rocket2Y);
void moveBoll(
		char gameField[HEIGTH][WEIGTH],
		int* bollY,
		int* bollX,
		int* bollVectorX,
		int* bollVectorY,
		int* player1Point,
		int* player2Point);
void fillingGameField(
		char gameField[HEIGTH][WEIGTH],
		int* bollY,
		int* bollX,
		int* bollVectorY,
		int* bollVectorX,
		int rocket1Y,
		int rocket2Y,
		int* player1Point,
		int* player2Point);
void printMessage(int player1Point, int player2Point);
void printInstruction(void);

int main(void) {
  char gameField[HEIGTH][WEIGTH];
  int rocket1Y = 12;
  int rocket2Y = 12;
  int player1Point = 0;
  int player2Point = 0;
  int bollY = 12;
  int bollX = 40;
  int bollVectorX = -1;
  int bollVectorY = 1;
  char exit = 'w';

  initializeGameField(gameField);
  while (exit != 'q') {
	skip();
    fillingGameField(
			gameField,
			&bollY,
			&bollX,
			&bollVectorY,
			&bollVectorX,
			rocket1Y,
			rocket2Y,
			&player1Point,
			&player2Point);
	printMessage(player1Point, player2Point);
    printGameField(gameField);
	printInstruction();
	listenClick(
		&exit,
		&rocket1Y,
	    &rocket2Y);
	if (player1Point == COUNT_WIN) {
		skip();
		printf("\n\n\nPlayer1 Win!!!\n\n\n");
		exit = 'q';
	}
	if (player2Point == COUNT_WIN) {
      skip();
	  printf("\n\n\nPlayer2 Win!!!\n\n\n");
	  exit = 'q';
	}
  }
  return (0);
}

void printMessage(int player1Point, int player2Point) {
  printf("Player1: %d, Player2: %d;\n", player1Point, player2Point);
}

void printInstruction(void) {
  printf("Press q for exit.\na z move rocket1,\nk m move rocket2,\n");
}

void listenClick(
		char* exit,
		int* rocket1Y,
		int* rocket2Y) {
  char temp = getchar();
  if (temp == 'q') {
    *exit = 'q';
  } else if (temp == 'a' && *rocket1Y > 2) {
    *rocket1Y -= 1;
  } else if (temp == 'z' && *rocket1Y < HEIGTH - 3) {
    *rocket1Y += 1;
  } else if (temp == 'k' && *rocket2Y > 2) {
    *rocket2Y -= 1;
  } else if (temp == 'm' && *rocket2Y < HEIGTH - 3) {
    *rocket2Y += 1;
  }
}

void fillingGameField(
		char gameField[HEIGTH][WEIGTH],
		int* bollY,
		int* bollX,
		int* bollVectorY,
		int* bollVectorX,
		int rocket1Y,
		int rocket2Y,
		int* player1Point,
		int* player2Point) {
	/*print fields*/
	for (int y = 0; y < HEIGTH; y++) {
      for (int x = 0; x <WEIGTH; x++) {
		  /*game fields*/
        if (y == 0 || x == 0 || y == HEIGTH - 1 || x == WEIGTH -1)
			gameField[y][x] = FIELD_MARKER;
		 /*rocket1*/
		else if ((y == rocket1Y || y - 1 == rocket1Y || y + 1 == rocket1Y) &&
				x == 2)
			gameField[y][x] = ROCKET;
		 /*rocket2*/
		else if ((y == rocket2Y || y - 1 == rocket2Y || y + 1 == rocket2Y) &&
				x == WEIGTH - 3)
			gameField[y][x] = ROCKET;
		else if (y == *bollY && x == *bollX)
			gameField[y][x] = BOLL;
		else 
			gameField[y][x] = ' ';
	  }
	}

	moveBoll(gameField,
			bollY,
			bollX,
			bollVectorX,
			bollVectorY,
			player1Point,
			player2Point);
}

void moveBoll(
		char gameField[HEIGTH][WEIGTH],
		int* bollY,
		int* bollX,
		int* bollVectorX,
		int* bollVectorY,
		int* player1Point,
		int* player2Point) {
  if (*bollY == 1) {
    *bollVectorY = 1;
  }
  if (*bollY == HEIGTH - 2) {
    *bollVectorY = -1;
  }
  if (*bollX == 2) {
    *player2Point += 1;
	*bollX = WEIGTH / 2;
	*bollY = HEIGTH / 2;
  }
  if (*bollX == WEIGTH - 3) {
    *player1Point += 1;
	*bollX = WEIGTH / 2;
	*bollY = HEIGTH / 2;
  }
  /*Hit rocket*/
  if (gameField[*bollY][*bollX + 1] == ROCKET ||
		  gameField[*bollY][*bollX - 1] == ROCKET) {
    *bollVectorX *= -1;
  }
  /*moving boll*/
  *bollY += *bollVectorY;
  *bollX += *bollVectorX;
}

void skip(void) {
  printf("\e[1;1H\e[2J");
}

void initializeGameField(char array[HEIGTH][WEIGTH]) {
  for (int y = 0; y < HEIGTH; y++) {
    for (int x = 0; x < WEIGTH; x++) {
      array[y][x] = FIELD_SPACE_SYMBOL;
	}
  }
}

void printGameField(char array[HEIGTH][WEIGTH]) {
  for (int y = 0; y < HEIGTH; y++) {
    for (int x = 0; x < WEIGTH; x++) {
      printf("%c", array[y][x]);
	}
	printf("\n");
  }
}
