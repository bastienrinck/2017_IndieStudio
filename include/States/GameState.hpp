/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** GameState.hpp
*/

#ifndef BOMBERMAN_GAMESTATE_HPP
	#define BOMBERMAN_GAMESTATE_HPP


#include "../Abstracts/AState.hpp"
#include "../Game/EntitiesMap.hpp"
#include "../Game/Entities/PlayerEntity.hpp"

class GameState : public AState {
public:
	GameState(AStateShare &_share);
	GameState(AStateShare &_share, std::string &);
	void load() override;
	void update() override;
	void updateRender() override;

private:
	EntitiesMap _emap;
	PlayerEntity *_entity;
};


#endif /* !BOMBERMAN_GAMESTATE_HPP */