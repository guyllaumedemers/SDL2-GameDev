#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <unordered_map>
#include <string>

using namespace std;
class TextureManager
{
private:

	//FIELDS

	static unordered_map<string, SDL_Texture*> textures;

	static string path;

	//TEXTURE_LOGIC

	static void add(string key, SDL_Texture* texture);

	static void remove(string key);

public:

	//GAME_LOGIC

	static void create(SDL_Renderer*);

	static void destroy();

	static SDL_Texture* getTexture(string key);
};

