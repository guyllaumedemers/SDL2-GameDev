#include "CApp.h"

bool CApp::OnInit()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
		return false;
	}
	else if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE, &window, &ren) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
		return false;
	}
	else if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL_image: %s", SDL_GetError());
		return false;
	}
	else if (surfaces.size() != 3 ||
		CSurface::OnLoad(window, "res/TicTacToe_Board.png") == NULL ||
		CSurface::OnLoad(window, "res/TicTacToe_O.png") == NULL ||
		CSurface::OnLoad(window, "res/TicTacToe_X.png") == NULL)
	{
		// Error handled inside the CSurface::OnLoad call
		return false;
	}
	else {
		surfaces[0]->Set(CSurface::OnLoad(window, "res/TicTacToe_Board.png"));
		surfaces[1]->Set(CSurface::OnLoad(window, "res/TicTacToe_O.png"));
		surfaces[2]->Set(CSurface::OnLoad(window, "res/TicTacToe_X.png"));
		GridReset();
		fplayer = true;
		return true;
	}
}

void CApp::OnEvent(SDL_Event* Event)
{
	CEvent::OnEvent(Event);
}

void CApp::OnLoop()
{
	if (OnCompletion()) {
		isRunning = false;
		std::cout << (fplayer ? "Player 1" : "Player 2") << " Win" << std::endl;
	}
}

void CApp::OnRender()
{
	CSurface::OnDraw(surfaces[0]->Get(), SDL_GetWindowSurface(window), NULL, NULL, NULL, NULL, WIDTH, HEIGHT);
	for (int i = 0; i < sizeof(Grid) / sizeof(*Grid); ++i) {
		int x = i % 3;
		int y = i / 3;						// should be rounding down

		if (Grid[i] == GRID_TYPE_X) {
			CSurface::OnDraw(surfaces[1]->Get(), SDL_GetWindowSurface(window), x * WIDTH / 3, y * HEIGHT / 3);
		}
		else if (Grid[i] == GRID_TYPE_O) {
			CSurface::OnDraw(surfaces[2]->Get(), SDL_GetWindowSurface(window), x * WIDTH / 3, y * HEIGHT / 3);		// img size were set in photoshop
		}
	}
	SDL_UpdateWindowSurface(window);		// update the render loop to handle double buffering
}

void CApp::OnCleanup()
{
	SDL_DestroyRenderer(ren);
	ren = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_Quit();
}

CApp::CApp() : isRunning(true), window(nullptr), ren(nullptr), Grid(), fplayer(true)
{
	for (int i = 0; i < 3; ++i) {
		surfaces.push_back(new CSurface());
	}
}

CApp::~CApp()
{
	for (auto i : surfaces) {
		delete i;
	}
	surfaces.clear();
}

int CApp::OnExecute()
{
	if (!OnInit()) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s Initialization failed", "[GameApp]");
		return -1;
	}

	SDL_Event Event;

	while (isRunning) {
		while (SDL_PollEvent(&Event)) {
			OnEvent(&Event);
		}
		OnLoop();
		OnRender();
	}

	OnCleanup();

	return 0;
}

bool CApp::OnCompletion()
{
	// Check Row Type

	// Check Columns Type

	// Check Diagonal Type

	return false;
}

void CApp::GridReset()
{
	for (auto i : Grid) {
		i = GRID_TYPE_NONE;
	}
}

void CApp::SetGridCell(int id, int type)
{
	if (id < 0 || id > sizeof(Grid) / sizeof(*Grid)) {
		throw std::out_of_range("id outside array range");
	}
	else if (type < 0 || type > GRID_TYPE_O) {
		throw std::out_of_range("type outside enum range");
	}
	else {
		Grid[id] = type;
	}
}

void CApp::OnExit()
{
	isRunning = false;
}

void CApp::OnLButtonDown(uint16_t mX, uint16_t mY)
{
	int id = mX / (WIDTH / 3);
	id += mY / (HEIGHT / 3) * 3;

	if (Grid[id] != GRID_TYPE_NONE) {
		std::cout << "Invalid cell" << std::endl;
		return;
	}

	if (fplayer) {
		Grid[id] = GRID_TYPE_X;
		fplayer = !fplayer;
	}
	else {
		Grid[id] = GRID_TYPE_O;
		fplayer = !fplayer;
	}
}
