#include "SpawnerUpdater.h"
#include "GameManager.h"
#include "GameObjectManager.h"
#include "TAccessor.h"
#include "TransformComponent.h"
#include "RenderComponent.h"
#include "Utils.h"

void SpawnerUpdater::update()
{
	int quantity = randInt(0, 4);
	GameObjectManager* gameObjectManager = GameObjectManager::getInstance();
	TAccessor<RenderComponent>* renders = TAccessor<RenderComponent>::Instance();
	TAccessor<TransformComponent>* transforms = TAccessor<TransformComponent>::Instance();

	int cpt = 0;
	for (int i = 0; i < quantity && cpt < quantity; i++)
	{
		for (unsigned int j = 0; j < renders->getComponentsSize(); j++)
		{
			RenderComponent* renderComponent = renders->getComponent(j);
			if (!renderComponent->isActive())
			{
				int transformIndex = gameObjectManager->getComponent(renderComponent->getgoId(), ComponentEnum::TransformComponent);
				TransformComponent* transformComponent = transforms->tryGetComponent(transformIndex);
				transformComponent->setPosition(49, randInt(1, 19));
				renderComponent->setIsActive(true);
			}
		}
	}
}
