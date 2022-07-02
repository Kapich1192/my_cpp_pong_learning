/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pong.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dmitriy <kapich1192@yandex.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 09:05:24 by Dmitriy           #+#    #+#             */
/*   Updated: 2022/07/02 18:00:11 by Dmitriy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define HEIGTH 25
#define WEIGTH 80
#define FIELD_MARKER '='
#define FIELD_SPACE_SYMBOL '.'
#define BOLL 'o'
#define ROCKET '|'

void printGameField(char array[HEIGTH][WEIGTH]);
void initializeGameField(char array[HEIGTH][WEIGTH]);
void skip(void);
void listenClick(
		char* exit,
		int* rocket1Y,
		int* rocket2Y);
void moveBoll(
		int* bollY,
		int* bollX,
		int* bollVectorX,
		int* bollVectorY);
void fillingGameField(
		char gameField[HEIGTH][WEIGTH],
		int* bollY,
		int* bollX,
		int* bollVectorY,
		int* bollVectorX,
		int rocket1Y,
		int rocket2Y);
void restart(void);

int main(void) {
  char gameField[HEIGTH][WEIGTH];
  int rocket1Y = 12;
  int rocket2Y = 12;
  int player1Point = 0;
  int player2Point = 0;
  int bollY = 12;
  int bollX = 40;
  int bollVectorX = 1;
  int bollVectorY = 1;
  char exit = 'w';

  initializeGameField(gameField);
  //while (exit != 'q') {
    listenClick(
			&exit,
			&rocket1Y,
			&rocket2Y);
	skip();
    fillingGameField(
			gameField,
			&bollY,
			&bollX,
			&bollVectorY,
			&bollVectorX,
			rocket1Y,
			rocket2Y);
    printGameField(gameField);
	if ()
    //skip();
  //}
  return (0);
}

void listenClick(
		char* exit,
		int* rocket1Y,
		int* rocket2Y) {
  char temp = getchar();
  if (temp == 'q') {
    *exit = 'q';
  } else if (temp == 'a' && *rocketY1 > 2) {
    *rocketY1--;
  } else if (temp == 'z' && *rocketY1 < 77) {
    *rocketY1++;
  } else if (temp == 'k' && *rocketY2 > 2) {
    *rocketY2--;
  } else if (temp == 'm' && *rocketY2 < 77) {
    *rocketY2++;
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
	/*print rocket1*/
	/*print rocket2*/
	/*print boll*/
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
  if (*bollY == 23) {
    *bollVectorY = -1;
  }
  if (*bollX == 2) {
    *player2Point++;
	*bollX = 40;
	*bollY = 12;
  }
  if (*bollX == 77) {
    *player1Point++;
	*bollX = 40;
	*bollY = 12;
  }
  /*Hit rocket*/
  if (gameField[*bollY][*bollX + 1] == ROCKET)
  /*moving boll*/
  *bollY += *bollVectorY;
  *bollX += *bollVectorX
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
