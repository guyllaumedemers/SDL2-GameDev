#include "CApp.h"

bool CApp::OnInit()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s SDL_Init failed - SDL : %s", "[GameApp]", SDL_GetError());
		return false;
	}
	else if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s IMG_Init failed - SDL : %s", "[GameApp]", SDL_GetError());
		return false;
	}
	else if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, NULL, &window, &ren) != 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s window or renderer were not initialize properly - SDL : %s", "[GameApp]", SDL_GetError());
		return false;
	}
	else if (surfaces.size() != FILES) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s vector was not initialize properly - SDL : %s", "[GameApp]", SDL_GetError());
		return false;
	}
	else if (
		CSurface::OnLoad(window, "res/TicTacToe_Board.png") == NULL ||
		CSurface::OnLoad(window, "res/TicTacToe_X.png") == NULL ||
		CSurface::OnLoad(window, "res/TicTacToe_O.png") == NULL)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s file not found - SDL : %s", "[GameApp]", SDL_GetError());
		return false;
	}
	else {
		// Load all surfaces
		surfaces[0].Set(CSurface::OnLoad(window, "res/TicTacToe_Board.png"));
		surfaces[1].Set(CSurface::OnLoad(window, "res/TicTacToe_X.png"));
		surfaces[2].Set(CSurface::OnLoad(window, "res/TicTacToe_O.png"));
		// Initialize Game Values
		ResetGame();
		return true;
	}
}

void CApp::OnEvent(SDL_Event* Event)
{
	CEvent::OnEvent(Event);
}

void CApp::OnLoop()
{
}

void CApp::OnRender()
{
	for (int i = 0; i < (sizeof(Grid) / sizeof(*Grid)); ++i) {
		// TODO
		int x = (i % COL) * (WIDTH / COL);
		int y = (i / ROW) * (HEIGHT / ROW);

		if (Grid[i] == GRID_TYPE_X) {
			CSurface::OnDraw(surfaces[1].Get(), SDL_GetWindowSurface(window), x, y);
		}
		else if (Grid[i] == GRID_TYPE_O) {
			CSurface::OnDraw(surfaces[2].Get(), SDL_GetWindowSurface(window), x, y);
		}
	}
	SDL_UpdateWindowSurface(window);
}

void CApp::OnCleanup()
{
	surfaces.clear();
	SDL_DestroyRenderer(ren);
	ren = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_Quit();
}

CApp::CApp() : isRunning(true), window(nullptr), ren(nullptr), Grid(), fplayer(true), counter(0)
{
	for (int i = 0; i < FILES; ++i) {
		surfaces.push_back(CSurface());
	}
}

CApp::~CApp()
{
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

void CApp::CheckGameStatus()
{
	std::string result = fplayer ? "Player 1 has won" : "Player 2 has won";
	// TODO
	if (HasCompleteRow(GRID_TYPE_X)) {
		OnRender();								// small hack to display the last valid tile, shouldnt be calling OnRender here
		PopupMsg(result);
	}
	else if (HasCompleteRow(GRID_TYPE_O)) {
		OnRender();
		PopupMsg(result);
	}
	else if (HasCompleteColumn(GRID_TYPE_X)) {
		OnRender();
		PopupMsg(result);
	}
	else if (HasCompleteColumn(GRID_TYPE_O)) {
		OnRender();
		PopupMsg(result);
	}
	else if (HasCompleteDiagonal(GRID_TYPE_X)) {
		OnRender();
		PopupMsg(result);
	}
	else if (HasCompleteDiagonal(GRID_TYPE_O)) {
		OnRender();
		PopupMsg(result);
	}
	else if (counter >= (ROW * COL)) {
		OnRender();
		PopupMsg("Draw");
	}
}

void CApp::PopupMsg(const std::string& result)		// can take an lvalue and an rvalue
{
	std::cout << result << std::endl;
	std::cout << "Rematch? [Y/N] : ";
	char c = NULL;
	std::cin >> c;
	if (std::toupper(c) == 'Y') {
		ResetGame();
	}
	else {
		OnExit();
	}
}

bool CApp::HasCompleteRow(int type)
{
	int i = NULL, j = NULL;
	while (i < ROW) {
		int count = 0;
		while (j < COL) {
			if (Grid[j + (i * COL)] == GRID_TYPE_NONE) {
				break;
			}
			else if (Grid[j + (i * COL)] != type) {
				break;
			}
			else {
				++count;
			}
			++j;
		}
		if (count >= ROW) {
			return true;
		}
		++i;
	}
	return false;
}

bool CApp::HasCompleteColumn(int type)
{
	int k = NULL, l = NULL;
	while (k < COL) {
		int count = 0;
		while (l < ROW) {
			if (Grid[k + (l * ROW)] == GRID_TYPE_NONE) {
				break;
			}
			else if (Grid[k + (l * ROW)] != type) {
				break;
			}
			else {
				++count;
			}
			if (count >= COL) {
				return true;
			}
			++l;
		}
		++k;
	}
	return false;
}

bool CApp::HasCompleteDiagonal(int type)
{
	int m = NULL, n = NULL;
	int count = 0;
	while (m < ROW) {
		if (Grid[m + (n * COL)] == GRID_TYPE_NONE) {
			break;
		}
		else if (Grid[m + (n * COL)] != type) {
			break;
		}
		else {
			++count;
		}
		++n;
		++m;
	}
	if (count >= ROW) {
		return true;
	}
	else {
		count = 0;
	}
	// Do inverse process
	m = ROW - 1, n = NULL;
	while (m >= 0) {
		if (Grid[m + (n * COL)] == GRID_TYPE_NONE) {
			break;
		}
		else if (Grid[m + (n * COL)] != type) {
			break;
		}
		else {
			++count;
		}
		++n;
		--m;
	}
	if (count >= ROW) {
		return true;
	}
	return false;
}

void CApp::ResetGame()
{
	// Game Values
	fplayer = true;
	counter = 0;

	// Grid Values
	for (int i = 0; i < (sizeof(Grid) / sizeof(*Grid)); ++i) {
		Grid[i] = GRID_TYPE_NONE;
	}

	// Grid Display
	CSurface::OnDraw(surfaces[0].Get(), SDL_GetWindowSurface(window), NULL, NULL);
}

void CApp::OnExit()
{
	isRunning = false;
}

void CApp::OnLButtonDown(uint16_t mX, uint16_t mY)
{
	// TODO
	int id = (mX / (WIDTH / COL));
	id += ((mY / (HEIGHT / ROW)) * 3);

	if (fplayer) {
		Grid[id] = GRID_TYPE_X;
		++counter;
	}
	else {
		Grid[id] = GRID_TYPE_O;
		++counter;
	}
	CheckGameStatus();
	fplayer = !fplayer;
}