#include "ScrollerUpdater.h"
#include "GameManager.h"
#include "ScrollerComponent.h"
#include "TransformComponent.h"
#include "TAccessor.h"

void ScrollerUpdater::update()
{
	GameManager* gameManager = GameManager::getInstance();
	TAccessor<ScrollerComponent>* scrollers = TAccessor<ScrollerComponent>::Instance();
	TAccessor<TransformComponent>* transforms = TAccessor<TransformComponent>::Instance();
	for (unsigned int i = 0; i < scrollers->getComponentsSize(); i++)
	{
		ScrollerComponent* component = scrollers->getComponent(i);
		if (component == nullptr) continue;
		int transformId = GameObjectManager::getInstance()->getComponent(component->getgoId(), ComponentEnum::TransformComponent);
		if (transformId < 0) continue;
		TransformComponent* transformComponent = transforms->tryGetComponent(transformId);
		if (transformComponent == nullptr) continue;
		transformComponent->setPositionX(component->move(transformComponent->getPosition()));

	}
}
