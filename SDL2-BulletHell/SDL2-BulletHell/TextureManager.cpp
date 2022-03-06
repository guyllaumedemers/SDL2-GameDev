#include "TextureManager.h"
#include <iostream>
#include <sstream>
#include <filesystem>
#include "ImageLoader.h"
#include "Util.h"

unordered_map<string, SDL_Texture*> TextureManager::textures;

string TextureManager::path = "../SDL2-BulletHell/Assets/";

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
		std::cout << s_path << std::endl;
		SDL_Texture* temp = ImageLoader::loadGPURendering(ren, s_path);
		std::cout << &temp << std::endl;
		vector<string> tokens;
		Util::Parse(tokens, s_path, "/.png");
		if (temp != nullptr) add(temp, tokens.at(tokens.size() - 1));
	}
}

void TextureManager::destroy()
{
	for (auto& it : textures) {
		SDL_DestroyTexture(it.second);
		it.second = nullptr;
	}
	textures.clear();
	IMG_Quit();
}

SDL_Texture* TextureManager::getTexture(string key)
{
	if (textures.find(key) != textures.end()) return textures[key];
	else return nullptr;
}

//TEXTURE_LOGIC

void TextureManager::add(SDL_Texture* texture, string key)
{
	textures.insert(make_pair(key, texture));
}

void TextureManager::remove(string key)
{
	if (textures.find(key) != textures.end()) {
		SDL_Texture* to_erase = textures[key];
		textures.erase(key);
		SDL_DestroyTexture(to_erase);
		to_erase = nullptr;
	}
}
