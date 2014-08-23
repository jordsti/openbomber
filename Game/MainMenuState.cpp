#include "MainMenuState.h"
#include "GameState.h"

using namespace StiGame;
using namespace Gui;

MainMenuState::MainMenuState() : GuiState()
{
    //ctor
    initComponents();
}

void MainMenuState::initComponents()
{

    btnNewGame.setCaption("New Game");
    btnNewGame.setPoint(20, 20);

    btnQuit.setCaption("Quit");
    btnQuit.setPoint(20, 80);

    lblTitle.setCaption("Open Bomber !");
    lblTitle.setPoint(300, 20);

    btnQuit.subscribe(this);
    btnNewGame.subscribe(this);

    add(&btnNewGame);
    add(&btnQuit);
    add(&lblTitle);
}

void MainMenuState::handleEvent(StiGame::EventThrower *src, StiGame::EventArgs *args)
{
    if(src == &btnNewGame)
    {
        GameState *gs = new GameState();
        getViewport()->push(gs);
    }
    else if(src == &btnQuit)
    {
        running = false;
    }
}

MainMenuState::~MainMenuState()
{
    //dtor
}
