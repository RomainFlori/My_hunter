/*
** EPITECH PROJECT, 2019
** directory
** File description:
** my_hunter
*/

#include "my.h"

int main(int ac, char **av)
{
    if (ac >= 3)
        return (84);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("Hellx Players\nHere are the rules :");
        my_putstr("1: Dxnt lxse tx much lives\n2: And KILL all xf the ghxst");
        my_putstr("And the mxst IMPXRTANT thing : HAVE FUN !!");
        return (0);
    }
    struct prototyp a;
    sfVideoMode mode = {1920, 1080, 32};
    sfVector2f titreposition = {9, 000};
    sfVector2f playposition = {500, 705};
    sfVector2f storypos = {160, 428};
    a.texture = sfTexture_createFromFile("80s.png", NULL);
    a.fond_ecran = sfSprite_create();
    sfSprite_setTexture(a.fond_ecran, a.texture, sfTrue);
    a.window = sfRenderWindow_create(mode, "My Ghost Hunter", sfResize |
    sfClose, NULL);
    a.font = sfFont_createFromFile("28Later.ttf");
    a.playpolic = sfFont_createFromFile("28Later.ttf");
    a.stor = sfFont_createFromFile("space.ttf");
    a.text_hautpage = sfText_create();
    a.story = sfText_create();
    a.play = sfText_create();
    sfText_setString(a.text_hautpage,
    "My Hunter mais je reste contre la chasse");
    sfText_setString(a.story, "My Hanted Hunter");
    sfText_setString(a.play, "Press PLay");
    sfSprite_setPosition(a.text_hautpage, titreposition);
    sfSprite_setPosition(a.story, storypos);
    sfSprite_setPosition(a.play, playposition);
    sfText_setFont(a.text_hautpage, a.font);
    sfText_setFont(a.story, a.stor);
    sfText_setFont(a.play, a.playpolic);
    sfText_setCharacterSize(a.text_hautpage, 50);
    sfText_setCharacterSize(a.story, 120);
    sfText_setCharacterSize(a.play, 200);
    sfText_setColor(a.text_hautpage, sfColor_fromRGB(255, 255, 255));
    sfText_setColor(a.story, sfColor_fromRGB(138, 43, 226));
    sfText_setColor(a.play, sfColor_fromRGB(200, 43, 176));
    a.music = sfMusic_createFromFile("exorcist.ogg");
    sfMusic_setLoop(a.music, sfTrue);
    sfMusic_play(a.music);
    while (sfRenderWindow_isOpen(a.window)) {
        sfVector2i mouse = sfMouse_getPositionRenderWindow(a.window);
        while (sfRenderWindow_pollEvent(a.window, &a.event)) {
            if (a.event.type == sfEvtClosed) {
                sfRenderWindow_close(a.window);
            }
            if (a.event.type == sfEvtMouseButtonPressed) {
                if (mouse.x > playposition.x && mouse.x < playposition.x + 950
                && mouse.y > playposition.y && mouse.y < playposition.y + 200) {
                    my_game(a.window);
                }
            }
            if (a.event.type == sfEvtClosed ||
                sfKeyboard_isKeyPressed(sfKeyEscape))
                sfRenderWindow_close(a.window);
        }
        sfRenderWindow_drawText(a.window, a.text_hautpage, NULL);
        sfRenderWindow_drawText(a.window, a.play, NULL);
        sfRenderWindow_drawText(a.window, a.story, NULL);
        sfRenderWindow_display(a.window);
        sfRenderWindow_clear(a.window, sfBlack);
        sfRenderWindow_drawSprite(a.window , a.fond_ecran, NULL);
    }
    sfMusic_destroy(a.music);
    sfText_destroy(a.text_hautpage);
    sfText_destroy(a.play);
    sfText_destroy(a.story);
    sfFont_destroy(a.playpolic);
    sfFont_destroy(a.font);
    sfRenderWindow_destroy(a.window);
    return (0);
}