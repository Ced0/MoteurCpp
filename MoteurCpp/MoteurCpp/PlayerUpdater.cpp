#include "PlayerUpdater.h"
#include "GameManager.h"
#include "GameObjectManager.h"
#include "TAccessor.h"
#include "TransformComponent.h"
#include "PlayerBehavior.h"

void PlayerUpdater::update()
{
	char input = GameManager::getInstance()->getInput();
	TAccessor<PlayerBehavior> transforms = TAccessor<PlayerBehavior>::Instance();
	for (unsigned int i = 0; i < transforms.getComponentsSize(); i++)
	{
		PlayerBehavior* component = transforms.getComponent(i);

	}
}