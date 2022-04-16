#include "TextureManager.h"
#include <iostream>
#include <sstream>
#include <filesystem>
#include "ImageLoader.h"
#include "Util.h"

unordered_map<string, SDL_Texture*> TextureManager::m_Textures;

string TextureManager::path = "../SDL2-Minesweeper/Assets/";

//GAME_LOGIC

void TextureManager::create(SDL_Renderer* ren)
{
	if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)) {
		SDL_Log("ERROR::IMG_INIT::FAILED : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	for (const auto& file : filesystem::directory_iterator(path)) {
		filesystem::path path = file.path();
		string s_path = path.generic_u8string();
		SDL_Texture* temp = ImageLoader::loadGPURendering(ren, s_path);
		vector<string> tokens;
		Util::Parse(tokens, s_path, "/");
		if (temp != nullptr) add(tokens.at(tokens.size() - 1), temp);
	}
}

void TextureManager::destroy()
{
	for (auto& it : m_Textures) {
		SDL_DestroyTexture(it.second);
		it.second = nullptr;
	}
	m_Textures.clear();
	IMG_Quit();
}

SDL_Texture* TextureManager::getTexture(string key)
{
	if (m_Textures.find(key) != m_Textures.end()) return m_Textures[key];
	else return nullptr;
}

//TEXTURE_LOGIC

void TextureManager::add(string key, SDL_Texture* texture)
{
	m_Textures.insert(make_pair(key, texture));
}

void TextureManager::remove(string key)
{
	if (m_Textures.find(key) != m_Textures.end()) {
		SDL_Texture* to_erase = m_Textures[key];
		m_Textures.erase(key);
		SDL_DestroyTexture(to_erase);
		to_erase = nullptr;
	}
}
