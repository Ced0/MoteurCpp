#include "RenderUpdater.h"
#include "GameManager.h"
#include "TransformComponent.h"
#include "RenderComponent.h"
#include "TAccessor.h"

void RenderUpdater::update()
{
	TAccessor<TransformComponent> transforms = TAccessor<TransformComponent>::Instance();
	TAccessor<RenderComponent> renders = TAccessor<RenderComponent>::Instance();
	for (unsigned int i = 0; i < transforms.getComponentsSize(); i++)
	{
		TransformComponent* component = transforms.getComponent(i);
		int index = GameObjectManager::getInstance()->getComponent(component->getgoId(), ComponentEnum::RenderComponent);
		RenderComponent* renderComponent = renders.tryGetComponent(index);
		GameManager::getInstance()->setScreenValue(component->getPosition(), renderComponent->getRender());
	}
}
