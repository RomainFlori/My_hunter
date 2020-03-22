/*
** EPITECH PROJECT, 2019
** directory
** File description:
** Lejeu
*/

#include "my.h"

sfVector2f sourissprite(sfVector2i vect2i)
{
    sfVector2f vect2f = {0, 0};
    vect2f.x = vect2i.x;
    vect2f.y = vect2i.y;
    return (vect2f);
}

int my_game(sfRenderWindow* window)
{
    struct prototyp a;
    sfTexture* cursortext = sfTexture_createFromFile("cursorone.png", NULL);
    sfSprite* cursorsprite = sfSprite_create();
    sfSprite_setTexture(cursorsprite, cursortext, sfTrue);
    sfWindow_setMouseCursorVisible((sfWindow *) window, sfFalse);
    sfVector2f sca = {1, 1};
    sfSprite_scale(cursorsprite, sca);
    sfVector2f score = {275, 010};
    sfVector2f vievect = {1850, 000};
    sfVector2f vievectext = {1600, 00};
    sfClock *horloge = sfClock_create();
    int buffer = 0;
    int number = 0;
    int intvie = 5;
    float speed = 0.2;
    sfVector2f pos = {-400, 20};
    a.vect = sfTexture_createFromFile("fantom1.png", NULL);
    a.second = sfTexture_createFromFile("fantom2.png", NULL);
    a.third = sfTexture_createFromFile("fantom3.png", NULL);
    a.vecteur = sfSprite_create();
    a.texture = sfTexture_createFromFile("backg.jpg", NULL);
    a.fond_ecran = sfSprite_create();
    sfSprite_setTexture(a.fond_ecran, a.texture, sfTrue);
    a.font = sfFont_createFromFile("horrendo.ttf");
    a.text_hautpage = sfText_create();
    sfText_setString(a.text_hautpage, "Your score : ");
    sfText_setFont(a.text_hautpage, a.font);
    sfText_setCharacterSize(a.text_hautpage, 50);
    sfText_setColor(a.text_hautpage, sfBlack);
    a.viefont = sfFont_createFromFile("viefontlol.ttf");
    a.vie = sfText_create();
    sfText_setString(a.vie, nb_tochar(intvie));
    sfText_setFont(a.vie, a.viefont);
    sfText_setPosition(a.vie, vievect);
    sfText_setCharacterSize(a.vie, 100);
    sfText_setColor(a.vie, sfColor_fromRGB(148, 0, 211));
    a.points = sfText_create();
    sfText_setFont(a.points, a.font);
    sfText_setCharacterSize(a.points, 55);
    sfText_setString(a.points, nb_tochar(number));
    sfText_setPosition(a.points, score);
    sfText_setColor(a.points, sfColor_fromRGB(255, 255, 255));
    a.vietext = sfText_create();
    sfText_setFont(a.vietext, a.viefont);
    sfText_setCharacterSize(a.vietext, 90);
    sfText_setString(a.vietext, "Life :");
    sfText_setPosition(a.vietext, vievectext);
    sfText_setColor(a.vietext, sfColor_fromRGB(255, 255, 255));
    while (sfRenderWindow_isOpen(window)) {
        sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
        while (sfRenderWindow_pollEvent(window, &a.event)) {
            if (a.event.type == sfEvtMouseMoved) {
                sfVector2f cursor = sourissprite(sfMouse_getPositionRenderWindow(window));
                sfSprite_setPosition(cursorsprite, cursor);
            }
            if (a.event.type == sfEvtClosed ||
                sfKeyboard_isKeyPressed(sfKeyEscape))
                sfRenderWindow_close(window);
            if (a.event.type == sfEvtMouseButtonPressed) {
                if (mouse.x > pos.x && mouse.x < pos.x + 290 && mouse.y > pos.y
                && mouse.y < pos.y + 150) {
                    pos.x = - 330;
                    pos.y = rand() % 800;
                    sfSprite_setPosition(a.vecteur, pos);
                    number = number + 50;
                    sfText_setString(a.points, nb_tochar(number));
                    speed = speed + 0.04;
                }
            }
        }
        if (intvie == 0) {
            gameover(number);
            sfSprite_destroy(a.fond_ecran);
            sfSprite_destroy(a.vecteur);
            sfTexture_destroy(a.vect);
            sfTexture_destroy(a.texture);
            sfText_destroy(a.text_hautpage);
            sfFont_destroy(a.font);
            return (0);
        }
        if (number >= 500)
            sfText_setColor(a.points, sfColor_fromRGB(255, 165, 0));
        if (number >= 1000)
            sfText_setColor(a.points, sfColor_fromRGB(255, 0, 0));
        sfRenderWindow_drawText(window, a.points, NULL);
        sfRenderWindow_drawText(window, a.text_hautpage, NULL);
        sfRenderWindow_drawText(window, a.vie, NULL);
        sfRenderWindow_drawText(window, a.vietext, NULL);
        for (int i = 0; i < 10; i++) {
            sfSprite_setPosition(a.vecteur, pos);
            pos.x = pos.x + speed;
        }
        if (pos.x > 1950) {
            pos.x = - 10;
            pos.y = rand() % 700;
            intvie = intvie - 1;
            sfText_setString(a.vie, nb_tochar(intvie));
        }
        sfRenderWindow_drawSprite(window, cursorsprite, NULL);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, a.fond_ecran, NULL);
        sfRenderWindow_drawSprite(window, a.vecteur, NULL);
        if (sfTime_asSeconds(sfClock_getElapsedTime(horloge)) >= 0.3) {
            if (buffer == 0) {
                sfSprite_setTexture(a.vecteur, a.vect, sfTrue);
                buffer = buffer + 1;
            }
            else if (buffer == 1) {
                sfSprite_setTexture(a.vecteur, a.second, sfTrue);
                buffer = buffer + 2;
            }
            else if (buffer == 3) {
                sfSprite_setTexture(a.vecteur, a.third, sfTrue);
                buffer = 0;
            }
            sfClock_restart(horloge);
        }
    }
    sfSprite_destroy(a.fond_ecran);
    sfSprite_destroy(a.vecteur);
    sfTexture_destroy(a.vect);
    sfTexture_destroy(a.texture);
    sfText_destroy(a.text_hautpage);
    sfFont_destroy(a.font);
    return (0);
}