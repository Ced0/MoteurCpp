#include "PlayerBehavior.h"
#include "TAccessor.h"

PlayerBehavior::PlayerBehavior(int ogId) : Component(ogId)
{
    TAccessor<PlayerBehavior>::Instance()->Add(*this);
}

float PlayerBehavior::playerMove(glm::vec2 playerPosition, char key)
{
    if(key == 'z')
        return playerPosition.y++;
    if(key == 's')
        return playerPosition.y--;
    return playerPosition.y;
}

bool PlayerBehavior::isGameOver(char screenValue)
{
    return screenValue == 'X';
}
