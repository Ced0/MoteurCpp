#include "PlayerBehavior.h"

float PlayerBehavior::playerMove(glm::vec2 playerPosition, char key)
{
    if(key == 'z')
        return playerPosition.y++;
    if(key == 's')
        return playerPosition.y--;
}

bool PlayerBehavior::isGameOver(char screenValue)
{
    return screenValue == 'X';
}
