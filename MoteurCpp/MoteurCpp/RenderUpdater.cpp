#include "RenderUpdater.h"
#include "GameManager.h"
#include "TransformComponent.h"
#include "RenderComponent.h"
#include "TAccessor.h"

void RenderUpdater::update()
{
	GameObjectManager* gameObjectManager = GameObjectManager::getInstance();
	TAccessor<TransformComponent>* transforms = TAccessor<TransformComponent>::Instance();
	TAccessor<RenderComponent>* renders = TAccessor<RenderComponent>::Instance();
	for (unsigned int i = 0; i < transforms->getComponentsSize(); i++)
	{
		TransformComponent* component = transforms->getComponent(i);
		if (component == nullptr) continue;
		int index = gameObjectManager->getComponent(component->getgoId(), ComponentEnum::RenderComponent);
		if (index < 0) continue;
		RenderComponent* renderComponent = renders->tryGetComponent(index);
		if (renderComponent == nullptr) continue;
		bool isActive = GameManager::getInstance()->setScreenValue(component->getPosition(), renderComponent->getRender());
		renderComponent->setIsActive(isActive);

	}
}
