//---------------------------------------------------------
// file:	main.c
// author:	[NAME]
// email:	[DIGIPEN EMAIL ADDRESS]
//
// brief:	Main entry point for the sample project
//			of the CProcessing library
//
// documentation link:
// https://github.com/DigiPen-Faculty/CProcessing/wiki
//
// Copyright © 6464 DigiPen, All rights reserved.
//---------------------------------------------------------

#include "cprocessing.h"
#include <stdlib.h>
#include <stdio.h>
#include "math.h"
#define MAX_PAIRS 49

CP_Color White = {255, 255, 255, 255};
CP_Image Background;
CP_Font Text;
CP_Image admin_widget;
CP_Image bag_moving_box;
CP_Image banana;
CP_Image barnacle_pod;
CP_Image blockmaker;
CP_Image blockmaker_chassis;
CP_Image blockmaker_engine;
CP_Image blockmaker_plates;
CP_Image bunch_of_grapes;
CP_Image cabbage;
CP_Image carrot;
CP_Image cauldron;
CP_Image cocktail_shaker;
CP_Image dice_12sided;
CP_Image fried_egg;
CP_Image fuelmaker_case;
CP_Image furniture_chair;
CP_Image furniture_smallwindow;
CP_Image irrigator_9000;
CP_Image lips;
CP_Image metalmaker;
CP_Image npc_deimaginator;
CP_Image npc_dumbbot_variant_widgetGreen_x1_move_png_1354836794;
CP_Image npc_fox_fox_orangeFox_x1_iconic_png_1354839585;
CP_Image npc_jabba1;
CP_Image npc_juju_bandit_bandana_red_variant_yellow_x1_iconic_png_1354834188;
CP_Image parsnip;
CP_Image party_atm;
CP_Image piggy_feeder;
CP_Image pineapple;
CP_Image pumpkin_carved_2;
CP_Image pumpkin_lit_5;
CP_Image quest_req_icon;
CP_Image quest_req_icon_letterblock;
CP_Image quill;
CP_Image rock_beryl_1;
CP_Image rock_metal_2;
CP_Image saucepan;
CP_Image sheep_red_wine;
CP_Image shovel;
CP_Image smelter;
CP_Image smoothie;
CP_Image stoot_barfield_pullstring_doll;
CP_Image super_scraper;
CP_Image trophy_street_creator_earth;
CP_Image watering_can;
CP_Image woodworker_chassis;
CP_Image woodworker_fuser;
CP_Image zucchini;

float score = 0;
int cards[14][7] = {0};
int alpha[14][7] = {0};

int firstRow = -1;
int firstCol = -1;
int secondRow = -1;
int secondCol = -1;

int selectedCount = 0;

// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program
void game_init(void) {
	// initialize variables and CProcessing settings for this gamestate
	CP_System_SetWindowSize(1024, 1024);
	Background = CP_Image_Load("./Assets/images/backgroundEmpty.png");
	Text = CP_Font_Load("./Assets/fonts/LuckiestGuy-Regular.ttf");
	admin_widget = CP_Image_Load("./Assets/glitch/admin_widget.png");
	bag_moving_box = CP_Image_Load("./Assets/glitch/bag_moving_box.png");
	banana = CP_Image_Load("./Assets/glitch/banana.png");
	barnacle_pod = CP_Image_Load("./Assets/glitch/barnacle_pod.png");
	blockmaker = CP_Image_Load("./Assets/glitch/blockmaker.png");
	blockmaker_chassis = CP_Image_Load("./Assets/glitch/blockmaker_chassis.png");
	blockmaker_engine = CP_Image_Load("./Assets/glitch/blockmaker_engine.png");
	blockmaker_plates = CP_Image_Load("./Assets/glitch/blockmaker_plates.png");
	bunch_of_grapes = CP_Image_Load("./Assets/glitch/bunch_of_grapes.png");
	cabbage = CP_Image_Load("./Assets/glitch/cabbage.png");
	carrot = CP_Image_Load("./Assets/glitch/carrot.png");
	cauldron = CP_Image_Load("./Assets/glitch/cauldron.png");
	cocktail_shaker = CP_Image_Load("./Assets/glitch/cocktail_shaker.png");
	dice_12sided = CP_Image_Load("./Assets/glitch/dice_12sided.png");
	fried_egg = CP_Image_Load("./Assets/glitch/fried_egg.png");
	fuelmaker_case = CP_Image_Load("./Assets/glitch/fuelmaker_case.png");
	furniture_chair = CP_Image_Load("./Assets/glitch/furniture_chair.png");
	furniture_smallwindow = CP_Image_Load("./Assets/glitch/furniture_smallwindow.png");
	irrigator_9000 = CP_Image_Load("./Assets/glitch/irrigator_9000.png");
	lips = CP_Image_Load("./Assets/glitch/lips.png");
	metalmaker = CP_Image_Load("./Assets/glitch/metalmaker.png");
	npc_deimaginator = CP_Image_Load("./Assets/glitch/npc_deimaginator.png");
	npc_dumbbot_variant_widgetGreen_x1_move_png_1354836794 = 
		CP_Image_Load("./Assets/glitch/npc_dumbbot_variant_widgetGreen_x1_move_png_1354836794.png");
	npc_fox_fox_orangeFox_x1_iconic_png_1354839585 = 
		CP_Image_Load("./Assets/glitch/npc_fox_fox_orangeFox_x1_iconic_png_1354839585.png");
	npc_jabba1 = CP_Image_Load("./Assets/glitch/npc_jabba1.png");
	npc_juju_bandit_bandana_red_variant_yellow_x1_iconic_png_1354834188 = 
		CP_Image_Load("./Assets/glitch/npc_juju_bandit_bandana_red_variant_yellow_x1_iconic_png_1354834188.png");
	parsnip = CP_Image_Load("./Assets/glitch/parsnip.png");
	party_atm = CP_Image_Load("./Assets/glitch/party_atm.png");
	piggy_feeder = CP_Image_Load("./Assets/glitch/piggy_feeder.png");
	pineapple = CP_Image_Load("./Assets/glitch/pineapple.png");
	pumpkin_carved_2 = CP_Image_Load("./Assets/glitch/pumpkin_carved_2.png");
	pumpkin_lit_5 = CP_Image_Load("./Assets/glitch/pumpkin_lit_5.png");
	quest_req_icon = CP_Image_Load("./Assets/glitch/quest_req_icon.png");
	quest_req_icon_letterblock = CP_Image_Load("./Assets/glitch/quest_req_icon_letterblock.png");
	quill = CP_Image_Load("./Assets/glitch/quill.png");
	rock_beryl_1 = CP_Image_Load("./Assets/glitch/rock_beryl_1.png");
	rock_metal_2 = CP_Image_Load("./Assets/glitch/rock_metal_2.png");
	saucepan = CP_Image_Load("./Assets/glitch/saucepan.png");
	sheep_red_wine = CP_Image_Load("./Assets/glitch/sheep_red_wine.png");
	shovel = CP_Image_Load("./Assets/glitch/shovel.png");
	smelter = CP_Image_Load("./Assets/glitch/smelter.png");
	smoothie = CP_Image_Load("./Assets/glitch/smoothie.png");
	stoot_barfield_pullstring_doll = CP_Image_Load("./Assets/glitch/stoot_barfield_pullstring_doll.png");
	super_scraper = CP_Image_Load("./Assets/glitch/super_scraper.png");
	trophy_street_creator_earth = CP_Image_Load("./Assets/glitch/trophy_street_creator_earth.png");
	watering_can = CP_Image_Load("./Assets/glitch/watering_can.png");
	woodworker_chassis = CP_Image_Load("./Assets/glitch/woodworker_chassis.png");
	woodworker_fuser = CP_Image_Load("./Assets/glitch/woodworker_fuser.png");
	zucchini = CP_Image_Load("./Assets/glitch/zucchini.png");
	for (int i = 1; i <= 49; i++) {
		int count = 0;
		// int tile = CP_Random_RangeInt(1, 49);
		while (count < 2) {
			int randPosX = CP_Random_RangeInt(0, 13);
			int randPosY = CP_Random_RangeInt(0, 6);
			if (cards[randPosX][randPosY] == 0) {
				cards[randPosX][randPosY] = i;
				count++;
			}
		}
	}
}

// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void game_update(void) {
	// check input, update simulation, render etc.
	
	// float mouseX = CP_Input_GetMouseX();
	// float mouseY = CP_Input_GetMouseY();
	
	CP_Image_Draw(Background, 512, 512, 1024, 1024, 255);
	char buffer[50];
	sprintf_s(buffer, 50, "Score: %d", (int) score);

	CP_Font_Set(Text);
	CP_Settings_TextSize(25);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Font_DrawText(buffer, 50, 50);

	if (CP_Input_MouseClicked()) {
		int row = (int) floorf((CP_Input_GetMouseY() - 48.f) / 64.f);
		int col = (int) floorf((CP_Input_GetMouseX() - 268.f) / 64.f);
		if (row >= 0 && row < 14 && col >= 0 && col < 7) {
			if (selectedCount == 0) {
				firstRow = row;
				firstCol = col;
				selectedCount = 1;
			} else if (selectedCount == 1) {
				if (row == firstRow && col == firstCol) {
					return;
				}
				secondRow = row;
				secondCol = col;
				selectedCount = 2;
			}
			if (selectedCount == 2) {
				if (cards[firstRow][firstCol] == cards[secondRow][secondCol]) {

					score++;
					alpha[firstRow][firstCol] = 255;
					alpha[secondRow][secondCol] = 255;
				}
				selectedCount = 0;
			}
		}
	}

	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 7; j++) {
			float x = (float) j * 64 + 300;
			float y = (float) i * 64 + 80;
			CP_Settings_Fill(White);
			CP_Graphics_DrawRect(x, y, 64, 64);
			switch (cards[i][j]) {
			case 1:
				CP_Image_Draw(admin_widget, x, y, 64, 64, alpha[i][j]);
				break;
			case 2:
				CP_Image_Draw(bag_moving_box, x, y, 64, 64, alpha[i][j]);
				break;
			case 3:
				CP_Image_Draw(banana, x, y, 64, 64, alpha[i][j]);
				break;
			case 4:
				CP_Image_Draw(barnacle_pod, x, y, 64, 64, alpha[i][j]);
				break;
			case 5:
				CP_Image_Draw(blockmaker, x, y, 64, 64, alpha[i][j]);
				break;
			case 6:
				CP_Image_Draw(blockmaker_chassis, x, y, 64, 64, alpha[i][j]);
				break;
			case 7:
				CP_Image_Draw(blockmaker_engine, x, y, 64, 64, alpha[i][j]);
				break;
			case 8:
				CP_Image_Draw(blockmaker_plates, x, y, 64, 64, alpha[i][j]);
				break;
			case 9:
				CP_Image_Draw(bunch_of_grapes, x, y, 64, 64, alpha[i][j]);
				break;
			case 10:
				CP_Image_Draw(cabbage, x, y, 64, 64, alpha[i][j]);
				break;
			case 11:
				CP_Image_Draw(carrot, x, y, 64, 64, alpha[i][j]);
				break;
			case 12:
				CP_Image_Draw(cauldron, x, y, 64, 64, alpha[i][j]);
				break;
			case 13:
				CP_Image_Draw(cocktail_shaker, x, y, 64, 64, alpha[i][j]);
				break;
			case 14:
				CP_Image_Draw(dice_12sided, x, y, 64, 64, alpha[i][j]);
				break;
			case 15:
				CP_Image_Draw(fried_egg, x, y, 64, 64, alpha[i][j]);
				break;
			case 16:
				CP_Image_Draw(fuelmaker_case, x, y, 64, 64, alpha[i][j]);
				break;
			case 17:
				CP_Image_Draw(furniture_chair, x, y, 64, 64, alpha[i][j]);
				break;
			case 18:
				CP_Image_Draw(furniture_smallwindow, x, y, 64, 64, alpha[i][j]);
				break;
			case 19:
				CP_Image_Draw(irrigator_9000, x, y, 64, 64, alpha[i][j]);
				break;
			case 20:
				CP_Image_Draw(lips, x, y, 64, 64, alpha[i][j]);
				break;
			case 21:
				CP_Image_Draw(metalmaker, x, y, 64, 64, alpha[i][j]);
				break;
			case 22:
				CP_Image_Draw(npc_deimaginator, x, y, 64, 64, alpha[i][j]);
				break;
			case 23:
				CP_Image_Draw(npc_dumbbot_variant_widgetGreen_x1_move_png_1354836794, x, y, 64, 64, alpha[i][j]);
				break;
			case 24:
				CP_Image_Draw(npc_fox_fox_orangeFox_x1_iconic_png_1354839585, x, y, 64, 64, alpha[i][j]);
				break;
			case 25:
				CP_Image_Draw(npc_jabba1, x, y, 64, 64, alpha[i][j]);
				break;
			case 26:
				CP_Image_Draw(npc_juju_bandit_bandana_red_variant_yellow_x1_iconic_png_1354834188, x, y, 64, 64, alpha[i][j]);
				break;
			case 27:
				CP_Image_Draw(parsnip, x, y, 64, 64, alpha[i][j]);
				break;
			case 28:
				CP_Image_Draw(party_atm, x, y, 64, 64, alpha[i][j]);
				break;
			case 29:
				CP_Image_Draw(piggy_feeder, x, y, 64, 64, alpha[i][j]);
				break;
			case 30:
				CP_Image_Draw(pineapple, x, y, 64, 64, alpha[i][j]);
				break;
			case 31:
				CP_Image_Draw(pumpkin_carved_2, x, y, 64, 64, alpha[i][j]);
				break;
			case 32:
				CP_Image_Draw(pumpkin_lit_5, x, y, 64, 64, alpha[i][j]);
				break;
			case 33:
				CP_Image_Draw(quest_req_icon, x, y, 64, 64, alpha[i][j]);
				break;
			case 34:
				CP_Image_Draw(quest_req_icon_letterblock, x, y, 64, 64, alpha[i][j]);
				break;
			case 35:
				CP_Image_Draw(quill, x, y, 64, 64, alpha[i][j]);
				break;
			case 36:
				CP_Image_Draw(rock_beryl_1, x, y, 64, 64, alpha[i][j]);
				break;
			case 37:
				CP_Image_Draw(rock_metal_2, x, y, 64, 64, alpha[i][j]);
				break;
			case 38:
				CP_Image_Draw(saucepan, x, y, 64, 64, alpha[i][j]);
				break;
			case 39:
				CP_Image_Draw(sheep_red_wine, x, y, 64, 64, alpha[i][j]);
				break;
			case 40:
				CP_Image_Draw(shovel, x, y, 64, 64, alpha[i][j]);
				break;
			case 41:
				CP_Image_Draw(smelter, x, y, 64, 64, alpha[i][j]);
				break;
			case 42:
				CP_Image_Draw(smoothie, x, y, 64, 64, alpha[i][j]);
				break;
			case 43:
				CP_Image_Draw(stoot_barfield_pullstring_doll, x, y, 64, 64, alpha[i][j]);
				break;
			case 44:
				CP_Image_Draw(super_scraper, x, y, 64, 64, alpha[i][j]);
				break;
			case 45:
				CP_Image_Draw(trophy_street_creator_earth, x, y, 64, 64, alpha[i][j]);
				break;
			case 46:
				CP_Image_Draw(watering_can, x, y, 64, 64, alpha[i][j]);
				break;
			case 47:
				CP_Image_Draw(woodworker_chassis, x, y, 64, 64, alpha[i][j]);
				break;
			case 48:
				CP_Image_Draw(woodworker_fuser, x, y, 64, 64, alpha[i][j]);
				break;
			case 49:
				CP_Image_Draw(zucchini, x, y, 64, 64, alpha[i][j]);
				break;
			}
		}
	}
}


// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void game_exit(void) {
	// shut down the gamestate and cleanup any dynamic memory
}

// main() the starting point for the program
// CP_Engine_SetNextGameState() tells CProcessing which functions to use for init, update and exit
// CP_Engine_Run() is the core function that starts the simulation
int main(void) {
	CP_Engine_SetNextGameState(game_init, game_update, game_exit);
	CP_Engine_Run();
	return 0;
}
