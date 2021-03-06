#pragma once

#include <Shadow/Utils/StateManager.h>
#include <Shadow/Utils/GameState.h>
#include "components/Panorama.hpp"
#include <Shadow/Audio/AudioManager.hpp>
#include <Shadow/Utils/Timer.hpp>
#include <Shadow/Graphics/Sprite.h>
#include <json/json.h>
#include <pspmath.h>

#include <Shadow/Graphics/RenderManager.h>
#include <string>
#include <fstream>
#include "../Version.hpp"
#include <sstream>

#include <Shadow/System/Input.h>
#include <Shadow/System/Ram.h>
#include "../Common/Translations.hpp"
#include "../Common/Options.hpp"
#include <Shadow/Utils/Logger.h>
#include <iostream>
#define PSP_MENU_SIZE 1.0

using namespace Shadow::System;
using namespace Shadow::Audio;
using namespace Shadow::Utils;

namespace Minecraft::Menus{

	enum MenuStates{
		MENU_STATE_TITLE = 0,
		MENU_STATE_LANGUAGE = 1,
		MENU_STATE_OPTIONS_MAIN = 2,
		MENU_STATE_SKIN_CUSTOMIZATION = 3,
		MENU_STATE_MUSIC = 4,
		MENU_STATE_VIDEO = 5,
		MENU_STATE_CHAT_SETTINGS = 6,
		MENU_STATE_SNOOPER = 7,
		MENU_STATE_MULTIPLAYER = 8,
		MENU_STATE_RESOURCE_PACK = 9,
		MENU_STATE_PLAY_GENERATE = 10,
		MENU_STATE_LOAD_SELECT = 11,
	};

    class MenuState : public GameState{
    public:
	    MenuState();
	    ~MenuState();

	    void Init();
	    void Enter();
	    void CleanUp();

	    void Pause();
	    void Resume();

	    void Update(StateManager* sManager);
	    void Draw(StateManager* sManager);
    private:
        void menuPass();
        void panoramaPass();

		void titleScreenDraw();
		void titleScreenUpdate(StateManager* sManager);

		void languageScreenDraw();
		void languageScreenUpdate();

		void optionsMainScreenDraw();
		void optionsMainScreenUpdate();

		void optionsSkinScreenDraw();
		void optionsSkinScreenUpdate();

		void optionsMusicScreenDraw();
		void optionsMusicScreenUpdate();

		void optionsVideoScreenDraw();
		void optionsVideoScreenUpdate();

		void optionsChatScreenDraw();
		void optionsChatScreenUpdate();

		void optionsSnooperScreenDraw();
		void optionsSnooperScreenUpdate();

		void optionsMultiplayerScreenDraw();
		void optionsMultiplayerScreenUpdate(StateManager* sManager);

		void optionsResourceScreenDraw();
		void optionsResourceScreenUpdate();

		void playGenerateDraw();
		void playGenerateUpdate(StateManager* sManager);
		
		void playSelectDraw();
		void playSelectUpdate(StateManager* sManager);

        OSL_SOUND* bgm, *button;
		Panorama* panorama;
		Timer t;

		Texture* logo;
		Sprite* Minecraft1, *Minecraft2;

		Texture *widgets, *options_bg;

		std::string splashText;

		bool tryConnect, connected;

		int gm;
		std::string username, ipaddr;
		float splashSize, dt, elapsed;

		Sprite *selected, *unselected, *disabled, *lang, *hlang;
		Sprite *opt_sel, *opt_unsel, *opt_dis;
		Sprite *miniSel, *miniUnSel, *miniDis;
		Sprite *tinySel, *tinyUnSel, *tinyDis;
		Sprite *options_tile;

		Sprite *slider, *slider_sel;

		Sprite *mega_slider;

		int selectPosY, selectPosX;

		int selectRegion, langPos, langPosSel, langPosMax;

		int loadPos, loadPosSel, loadPosMax;

		MenuStates menu_states, previous_states;

		std::string worldName, seedName;

        std::vector<std::string> entries;
    };
}