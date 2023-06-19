/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	link(
		Animation(link_sprite,
			link_spritesize.x,
			link_spritesize.y,
			link_chroma),
		Vei2(200.0f, 200.0f))
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	Vec2 movement_delta = { 0,0 };
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		movement_delta.x = -1;
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		movement_delta.x = 1;
	}
	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		movement_delta.y = -1;
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		movement_delta.y = 1;
	}
	if (wnd.kbd.KeyIsPressed(VK_SPACE) && !key_is_pressed) {
		link.DamageTick();
		key_is_pressed = true;
	}
	if (wnd.kbd.KeyIsPressed(VK_TAB) && !key_is_pressed) {
		link.Ghostify();
		key_is_pressed = true;
	}
	if (!wnd.kbd.KeyIsPressed(VK_SPACE) && !wnd.kbd.KeyIsPressed(VK_TAB)) {
		key_is_pressed = false;
	}
	link.Move(movement_delta);
}

void Game::ComposeFrame()
{
	gfx.DrawSprite(100, 100, marle_sprite);
	message.Draw(gfx, "This is some\nbullshit!11!11!!", 100, 100);
	link.Animate(gfx);
}
