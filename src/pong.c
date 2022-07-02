/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pong.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dmitriy <kapich1192@yandex.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 09:05:24 by Dmitriy           #+#    #+#             */
/*   Updated: 2022/07/02 09:19:40 by Dmitriy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#define HEIGTH 25
#define WEIGTH 80
#define FIELD_MARKER '='

void printGameField(char **array, int heigth, int weigth);
void initializeGameField(char **array, int heigth, int weigth);

int main(void) {

  return (0);
}

void initializeGameField(char **array, int heigth, int weigth) {
  for (int y = 0; y < heigth, y++) {
    for (int x = 0; x < weigth) {
      array[y][x] = ' ';
	}
  }
}

void printGameField(char **array, int heigth, int weigth) {
  for (int y = 0; y < heigth; y++) {
    for (int x = 0; x < weigth; x++) {
      printf("%c", array[y][x]);
	}
	printf("\n");
  }
}
