#include "SpawnerUpdater.h"
#include "GameManager.h"
#include "GameObjectManager.h"
#include "TAccessor.h"
#include "TransformComponent.h"
#include "RenderComponent.h"
#include "Utils.h"

void SpawnerUpdater::update()
{
	int quantity = randInt(5, 10);
	GameObjectManager* gameObjectManager = GameObjectManager::getInstance();
	TAccessor<RenderComponent>* renders = TAccessor<RenderComponent>::Instance();
	TAccessor<TransformComponent>* transforms = TAccessor<TransformComponent>::Instance();

	for (int i = 0; i < quantity; i++)
	{
		for (unsigned int j = 0; j < renders->getComponentsSize(); j++)
		{
			RenderComponent* renderComponent = renders->getComponent(j);
			if (renderComponent == nullptr) continue;
			if (!renderComponent->isActive())
			{
				int transformIndex = gameObjectManager->getComponent(renderComponent->getgoId(), ComponentEnum::TransformComponent);
				if (transformIndex < 0) continue;
				TransformComponent* transformComponent = transforms->tryGetComponent(transformIndex);
				if (transformComponent == nullptr) continue;
				transformComponent->setPosition(49, randInt(1, 19));
				renderComponent->setIsActive(true);
			}
		}
	}
}
