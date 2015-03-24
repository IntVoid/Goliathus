#include "TurretSystem.h"

using namespace std;

// Experimental Implementation of Hash Map using <unordered_map>
// Might be more conventional to create own Hash Map functionality

struct EnumClassHash {
	template<typename T>
	size_t operator() (T t) const {
		return static_cast<size_t>(t);
	}
};

template <typename Key>
using HashType = typename conditional<is_enum<Key>::value, 
	EnumClassHash, hash<Key>>::type;

template <typename Key, typename T>
using MyUnorderedMap = unordered_map < Key, T, HashType<Key> > ;

//MyUnorderedMap<MyEnum, MyClass> myMap;

ShipTurretSystem::ShipTurretSystem() {
	
}

ShipTurretSystem::~ShipTurretSystem() {

}

void ShipTurretSystem::addTurret() {

}

void ShipTurretSystem::removeTurret() {

}

void ShipTurretSystem::changeTurret() {

}

void ShipTurretSystem::allocateTurret() {

}

void ShipTurretSystem::getTurret() {

}