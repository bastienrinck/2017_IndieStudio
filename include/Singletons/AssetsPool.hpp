/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** AssetsPool.hpp
*/

#ifndef BOMBERMAN_MESHPOOL_HPP
#define BOMBERMAN_MESHPOOL_HPP

#include <irrlicht.h>
#include <string>
#include <map>
#include <ik_ISound.h>
#include <functional>
#include <vector>
#include "IrrManager.hpp"

class AssetsPool {
public:
	static AssetsPool &getInstance();

	enum Assets {
		MENU,
		FINAL
	};

	enum Types {
		SFX,
		MUSIC,
	};
	irr::scene::IMesh *loadMesh(const std::string &file);
	irr::video::ITexture *loadTexture(const std::string &file);
	irrklang::ISound *loadSound(AssetsPool::Assets, bool);

	void unloadSound(AssetsPool::Assets, irrklang::ISound *);
	void setVolume(AssetsPool::Types, irrklang::ik_f32);
private:
	AssetsPool(const std::string &rootModelPath,
	const std::string &rootTextures);

	struct soundInfo {
		AssetsPool::Types type;
		std::string name;
		irrklang::ik_f32 (IrrManager::*vol)(void) const;
	};
	std::string _rootModelPath;
	std::string _rootTexturePath;
	std::map<std::string, irr::scene::IMesh *> _meshs;
	std::map<std::string, irr::video::ITexture *> _textures;
	std::vector<std::vector<irrklang::ISound *>> _sModule;

	//FIXME CONST STATIC
	const std::vector<soundInfo> _sounds = {
			{
				MUSIC,
				"assets/sounds/MenuSong.mp3",
				&IrrManager::getMusicVolume,
			}
	};
	static AssetsPool _meshPool;
};


#endif /* !BOMBERMAN_MESHPOOL_HPP */
