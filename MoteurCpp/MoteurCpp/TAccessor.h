#pragma once
#include "Component.h"
#include <vector>

constexpr auto MAX_COMPONENT = 3000;

template<typename T>
class TAccessor
{
private:
	static TAccessor<T> singleton;
	std::vector<T> components;

	TAccessor<T>()
	{
		components = std::vector<T>(MAX_COMPONENT);
	}

public:
	static TAccessor<T>* Instance();

	T* getComponent(int index);

	T* tryGetComponent(int id);

	int getComponentsSize();

	void Add(T component);

	void remove(T component);

	void remove(int id);
	
};

template<typename T>
inline TAccessor<T>* TAccessor<T>::Instance()
{
	static TAccessor<T> singleton = TAccessor<T>();
	return &singleton;
}

template<typename T>
inline T* TAccessor<T>::getComponent(int index)
{
	return &components[index];
}

template<typename T>
inline T* TAccessor<T>::tryGetComponent(int id)
{
	for (int i = 0; i < components.size(); i++)
	{
		if (components[i].getId() == id)
			return &components[i];
	}
	return nullptr;
}

template<typename T>
inline int TAccessor<T>::getComponentsSize()
{
	return components.size();
}

template<typename T>
inline void TAccessor<T>::Add(T component)
{
	components.push_back(component);
}

template<typename T>
inline void TAccessor<T>::remove(T component)
{
	for (int i = 0; i < components.size(); i++)
	{
		if (components[i] == component)
		{
			components[i].~T();
			break;
		}
	}
}

template<typename T>
inline void TAccessor<T>::remove(int id)
{
	for (int i = 0; i < components.size(); i++)
	{
		if (components[i].getId() == id)
			components[i].~T();
	}
}
