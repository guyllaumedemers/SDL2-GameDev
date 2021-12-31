#include "Rendering.h"

SDL_Window* Rendering::m_Window = nullptr;

SDL_Renderer* Rendering::m_Renderer = nullptr;

void Rendering::initializeWindow(const int& width, const int& height)
{
	m_Window = SDL_CreateWindow(
		"Minesweeper",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		0
	);

	if (m_Window == nullptr) {
		SDL_Log("Cannot initalize SDL_Window : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

void Rendering::initializeRendering()
{
	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);

	if (m_Renderer == nullptr) {
		SDL_Log("Cannot initalize SDL_Renderer : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

void Rendering::initializeIMG()
{
	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF | IMG_INIT_WEBP) == 0) {
		SDL_Log("Cannot initalize SDL_image : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

void Rendering::initialize(const int& width, const int& height)
{
	initializeWindow(width, height);
	initializeRendering();
	initializeIMG();
}

void Rendering::setWindowSize(const int& x, const int& y)
{
	SDL_SetWindowSize(m_Window, Tile::width * x, Tile::height * y);
}

void Rendering::update(Tile** map, const int& arrX, const int& arrY)
{
	SDL_RenderClear(m_Renderer);
	for (int i = 0; i < arrX; ++i) {
		for (int j = 0; j < arrY; ++j) {

			int x = j * Tile::width;
			int y = i * Tile::height;

			SDL_Rect dest{
				x,
				y,
				Tile::width,
				Tile::height
			};

			Tile* tile = &map[i][j];

			SDL_Texture* target = SDL_CreateTexture(m_Renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, Tile::width, Tile::height);
			SDL_Texture* dstRGBA = (*tile).getTexture();

			SDL_SetRenderTarget(m_Renderer, target);

			SDL_RenderClear(m_Renderer);
			SDL_RenderCopy(m_Renderer, dstRGBA, NULL, NULL);

			SDL_Texture* srcRGBA = nullptr;

			if (((*tile).getBitmaskValue() & TileBitMask::Flag) == TileBitMask::Flag) {
				srcRGBA = ImageLoader::loadGPURendering(m_Renderer, SDL_GetWindowSurface(m_Window), "../SDL2-Minesweeper/Assets/Flag.png");
				SDL_SetTextureBlendMode(srcRGBA, SDL_BLENDMODE_BLEND);
				SDL_RenderCopy(m_Renderer, srcRGBA, NULL, NULL);
			}
			else if (((*tile).getBitmaskValue() & TileBitMask::Numbered) == TileBitMask::Numbered) {
				char buffer[50];
				sprintf_s(buffer, "../SDL2-Minesweeper/Assets/%d.png", (*tile).getValue());

				srcRGBA = ImageLoader::loadGPURendering(m_Renderer, SDL_GetWindowSurface(m_Window), buffer);
				SDL_SetTextureBlendMode(srcRGBA, SDL_BLENDMODE_BLEND);
				SDL_RenderCopy(m_Renderer, srcRGBA, NULL, NULL);
			}

			if (((*tile).getBitmaskValue() & (TileBitMask::Uncovered | TileBitMask::Bomb)) == (TileBitMask::Uncovered | TileBitMask::Bomb)) {
				srcRGBA = ImageLoader::loadGPURendering(m_Renderer, SDL_GetWindowSurface(m_Window), "../SDL2-Minesweeper/Assets/Bomb.png");
				SDL_SetTextureBlendMode(srcRGBA, SDL_BLENDMODE_BLEND);
				SDL_RenderCopy(m_Renderer, srcRGBA, NULL, NULL);
			}

			SDL_SetRenderTarget(m_Renderer, NULL);
			SDL_RenderCopy(m_Renderer, target, NULL, &dest);

			SDL_DestroyTexture(target);
			target = nullptr;

			dstRGBA = nullptr;
			SDL_DestroyTexture(dstRGBA);

			SDL_DestroyTexture(srcRGBA);
			srcRGBA = nullptr;

			tile = nullptr;
			delete tile;
		}
	}
	SDL_RenderPresent(m_Renderer);
}

void Rendering::clear()
{
	SDL_DestroyRenderer(m_Renderer);
	m_Renderer = nullptr;
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	IMG_Quit();
}
