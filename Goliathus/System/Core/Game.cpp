#include "Game.h"

using namespace ShipBuilderType;

namespace GAME {

	// Singleton
	extern Ship* playerShip = nullptr;
	
	EnemyFactory* enemyFactory;
	vector<Ship*> _beginnerShipsVector;

	int input = 0;

	bool RunGame() {
		SETUP::PLAYER::InitializePlayer();
		
		return true;
	}

	namespace SETUP {

		namespace PLAYER {
			// Singleton Design Pattern, there is only one Player
			void InitializePlayer() {
				// If player does not exist, create the player
				if (!playerShip) {
					InitializeBeginnerShips();
					CreatePlayerShip();
					OutfitPlayerShip();
				}

				return;
			}
			
			// Initializes beginner ships and stores them into a list
			void InitializeBeginnerShips() {
	
				// Ensure that the list is empty to begin with.
				if (_beginnerShipsVector.size() != 0)
					_beginnerShipsVector.clear();
	
				ShipCreator shipCreator;
				ShipBuilder* frigateBuilder(new FrigateBuilder);
				shipCreator.setShipBuilder(frigateBuilder);
				shipCreator.createShip();
				Ship* frigateShip = shipCreator.getShip();
				_beginnerShipsVector.push_back(frigateShip);
		
				delete frigateBuilder;
				frigateBuilder = nullptr;
		
				ShipBuilder* cruiserBuilder(new CruiserBuilder);
				shipCreator.setShipBuilder(cruiserBuilder);
				shipCreator.createShip();
				Ship* cruiserShip = shipCreator.getShip();
				_beginnerShipsVector.push_back(cruiserShip);
		
				delete cruiserBuilder;
				cruiserBuilder = nullptr;
		
				ShipBuilder* destroyerBuilder(new DestroyerBuilder);
				shipCreator.setShipBuilder(destroyerBuilder);
				shipCreator.createShip();
				Ship* destroyerShip = shipCreator.getShip();
				_beginnerShipsVector.push_back(destroyerShip);
		
				delete destroyerBuilder;
				destroyerBuilder = nullptr;
	
				return;
			}
	
			// Creates player ship depending on choice provided
			void CreatePlayerShip() {
				input = MENU::PLAYERCREATIONMENU::ShipSelectionMenu();
				string shipChoice = "nothing";
				
				switch (input) {
				case 1: // Frigate
					for (int i = 0; i < _beginnerShipsVector.size(); ++i) {
						Ship* temp = _beginnerShipsVector[i];
						if (temp->getShipType() == ShipType::Frigate) {
							playerShip = temp;
						}
					}
					break;
				case 2: // Cruiser
					for (int i = 0; i < _beginnerShipsVector.size(); ++i) {
						Ship* temp = _beginnerShipsVector[i];
						if (temp->getShipType() == ShipType::Cruiser) {
							playerShip = temp;
						}
					}
					break;
				case 3: // Destroyer
					for (int i = 0; i < _beginnerShipsVector.size(); ++i) {
						Ship* temp = _beginnerShipsVector[i];
						if (temp->getShipType() == ShipType::Destroyer) {
							playerShip = temp;
						}
					}
					break;
				}
	
				cout << "You have chosen the " << endl;
				playerShip->getShipTypeName();
				cout << "\nIs this correct?"
					<< "\n1. Yes, this is the ship I want."
					<< "\n2. Wait, let me look over my options again."
					<< endl;
				int choice = 2;
				input = MENU::ReadNumericOption(choice);
				switch (input) {
				case 1: return;
				case 2: break;
				}
			}
	
			void OutfitPlayerShip() {
				cout << "Generating Enemy Ship" << endl;
				Ship* enemyFrigate = enemyFactory->NewEnemyShip(ShipType::Frigate, ShipDesignation::Offense);
				enemyFrigate->ShipReadout();
				cout << "Finished Generating Enemy Ship" << endl;
				system("pause");
			}
		}
	}

	void InitializeShipSubSystems(Ship _ship) {
		_ship.SetShipPower();
	}

	

}