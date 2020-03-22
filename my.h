/*
** EPITECH PROJECT, 2019
** directory
** File description:
** my
*/

#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

int main(int ac, char **av);
int my_game(sfRenderWindow* window);
int gameover(int number);
char *nb_tochar(int i);
int my_putstr(char const *str);
void my_putchar(char c);

struct prototyp {
    sfMusic* music;
    sfRenderWindow* window;
    sfTexture* texture;
    sfTexture* vect;
    sfSprite* fond_ecran;
    sfSprite* vecteur;
    sfFont* font;
    sfFont* viefont;
    sfFont* playpolic;
    sfFont* stor;
    sfText* text_hautpage;
    sfText* story;
    sfText* play;
    sfEvent event;
    sfTexture* second;
    sfTexture* third;
    sfText* points;
    sfText* vie;
    sfText* vietext;
};