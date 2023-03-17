#include "PlayerUpdater.h"
#include "GameManager.h"
#include "GameObjectManager.h"
#include "TAccessor.h"
#include "TransformComponent.h"
#include "PlayerBehavior.h"

void PlayerUpdater::update()
{
	GameManager* gameManager = GameManager::getInstance();
	char input = gameManager->getInput();
	TAccessor<PlayerBehavior>* behaviors = TAccessor<PlayerBehavior>::Instance();
	TAccessor<TransformComponent>* transforms = TAccessor<TransformComponent>::Instance();
	for (unsigned int i = 0; i < behaviors->getComponentsSize(); i++)
	{
		PlayerBehavior* component = behaviors->getComponent(i);
		if (component == nullptr) continue;
		int transformId = GameObjectManager::getInstance()->getComponent(component->getgoId(), ComponentEnum::TransformComponent);
		if (transformId < 0) continue;
		TransformComponent* transformComponent = transforms->tryGetComponent(transformId);
		if (transformComponent == nullptr) continue;
		transformComponent->setPositionY(component->playerMove(transformComponent->getPosition(), input));
		if (component->isGameOver(gameManager->getScreenValue(transformComponent->getPosition())))
		{
			gameManager->gameOver();
		}
	}
}