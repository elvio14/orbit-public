//------------------------------------------------------------------------
// GameTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
//------------------------------------------------------------------------
#include "app\app.h"
//------------------------------------------------------------------------
#include "Player.h"
#include "Planet.h"
#include "Effect.h"
#include "Ball.h"
#include "Launcher.h"
#include "BoostEffect.h"
#include "Grid.h"
#include "Score.h"
//------------------------------------------------------------------------
// Eample data....
//------------------------------------------------------------------------
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
Grid theGrid;
Score theScore;
Player players[2];
std::vector<Planet> planets;
std::vector<std::shared_ptr<Effect>> effects;
float angleIncrement = Utils::fPI / 128.f;

void Init()
{
	planets.push_back(Planet(Utils::app_width / 2.f, Utils::app_height / 4.2f, 12.f));
	planets.push_back(Planet(Utils::app_width / 1.3f, Utils::app_height / 1.1f, 12.f));
	planets.push_back(Planet(Utils::app_width / 2.1f, Utils::app_height / 1.2f, 10.f));
	planets.push_back(Planet(Utils::app_width / 1.4f, Utils::app_height / 2.f, 8.f));
	planets.push_back(Planet(Utils::app_width / 7.f, Utils::app_height / 2.3f, 8.f));
	planets.push_back(Planet(Utils::app_width / 3.f, Utils::app_height / 7.f, 8.f));

	players[0] = Player(0.f);
	players[1] = Player(1.f);
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
	//PROCESS EVENTS-----------------------------------------------------------------------------------
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_BACK, true))
	{
		if (theScore.isWon) {
			theScore.rematch(&theGrid);
			for (auto& player : players) {
				player.pr_launcher.l_angle = Utils::fPI * player.pr_sign;
			}
		}
	}
	if (App::GetController().GetLeftThumbStickX() > 0.5f)
	{
		players[0].addAngle(angleIncrement);
	
	}
	if (App::GetController().GetLeftThumbStickX() < -0.5f)
	{
		players[0].addAngle(-angleIncrement);

	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_LEFT, false))
	{
		players[1].addAngle(-angleIncrement);

	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_RIGHT, false))
	{
		players[1].addAngle(angleIncrement);
	}

	if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, false))//SPACEBAR
	{
		bool active = players[0].isBallActive();
		bool sameX = players[0].pr_ball.b_xpos == players[0].pr_launcher.l_xpos;
		bool sameY = players[0].pr_ball.b_ypos == players[0].pr_launcher.l_ypos;
		if (!active && sameX && sameY && !theScore.getStatus()) {
			players[0].launch();
		}
		else if (!theScore.getStatus())
		{
			players[0].boosting(&effects);
		}
	}

	if (App::GetController().CheckButton(XINPUT_GAMEPAD_START, false))//ENTER
	{
		bool active = players[1].isBallActive();
		bool sameX = players[1].pr_ball.b_xpos == players[1].pr_launcher.l_xpos;
		bool sameY = players[1].pr_ball.b_ypos == players[1].pr_launcher.l_ypos;
		if (!active && sameX && sameY && !theScore.getStatus()) {
			players[1].launch();
		}
		else if (!theScore.getStatus())
		{
			players[1].boosting(&effects);
		}
	}

	//UPDATE FUNCTIONS-----------------------------------------------------------------------------------------
	if (!theScore.getStatus()) {
		for (auto& player : players) {
			player.pr_ball.update();
			if (player.isBallActive()) {
				Physics::updatePos(planets, player.pr_ball, player.pr_launcher, deltaTime);
			}
			else {
				player.pr_launcher.resetBall(player.pr_ball);
			}
		}

		for (auto& effect : effects) {
			effect->update(deltaTime);
		}

		effects.erase(std::remove_if(effects.begin(), effects.end(), [](const auto& effect) {
			return effect->isDone;
			}), effects.end());

		theGrid.update(players);
		theScore.update(&theGrid);
	}

	for (auto& player : players) {
		player.update(theScore.getStatus());
	}
	
}

void Render()
{	
	theGrid.render();

	for (auto& planet : planets) {
		planet.render();
	}

	for (auto& effect : effects) {
		effect->render();
	}

	for (auto& player : players) {
		player.render();
		player.setBoost(1.f);
	}

	theScore.render();
}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{	
	//------------------------------------------------------------------------
	// Example Sprite Code....
	//------------------------------------------------------------------------
}