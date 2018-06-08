/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** GameState.cpp
*/

#include "../../include/States/GameState.hpp"
#include "../../include/Singletons/IrrManager.hpp"
#include "../../include/Singletons/EventReceiver.hpp"
#include "../../include/Singletons/StateMachine.hpp"
#include "../../include/Singletons/AssetsPool.hpp"
#include "../../include/Game/SaveManager.hpp"
#include "../../include/Game/BKeyboardController.hpp"
#include "../../include/States/PauseState.hpp"

GameState::GameState(AStateShare &_share) : AState(_share)
{
	_emap.generate();
}

GameState::GameState(AStateShare &_share, std::string &filename) : GameState(_share)
{
//	SaveManager::save(_emap, filename);
}

void GameState::update()
{
	if (getSharedResources().isKeyPressed(irr::KEY_ESCAPE))
		StateMachine::getInstance().push(new PauseState(getSharedResources()), false);
	else
		_emap.update();
}

void GameState::load()
{
}

void GameState::updateRender()
{
	_emap.updateRender();
	AState::updateRender();
}
