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

GameState::GameState(AStateShare &_share) : AState(_share), _inc(0)
{
	_share.pushMusic(AssetsPool::getInstance().loadSound(AssetsPool::GAME, true));
	_emap.generate(_share.getIAState());
}

GameState::GameState(AStateShare &_share, std::string &filename) : GameState(_share)
{
	_share.popMusic(AssetsPool::GAME);
//	SaveManager::save(_emap, filename);
}

void GameState::update()
{
	animCam();
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

void GameState::animCam()
{
	auto step = static_cast<irr::f32>((2.0 * M_PI) / 1000.0);
	irr::f32 min = static_cast<irr::f32>(100);
	irr::f32 max = static_cast<irr::f32>(105);
	auto &cam = dynamic_cast<irr::scene::ICameraSceneNode &>(_share.getSharedNode("cam"));
	auto camPos = cam.getPosition();

	_inc += step;
	camPos.Y = static_cast<irr::f32>((sinf(_inc) - -1.0) * (max - min) / (1.0 - -1.0) + min);
	cam.setPosition(camPos);
}
