#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include <GuiState.h>
#include <EventListener.h>
#include <Button.h>
#include <Label.h>

class MainMenuState :
    public StiGame::Gui::GuiState,
    public StiGame::EventListener
{
    public:
        MainMenuState();
        void handleEvent(StiGame::EventThrower *src, StiGame::EventArgs *args);
        virtual ~MainMenuState();
    protected:
        StiGame::Gui::Label lblTitle;
        StiGame::Gui::Button btnNewGame;
        StiGame::Gui::Button btnQuit;
    private:
        void initComponents(void);
};

#endif // MAINMENUSTATE_H
