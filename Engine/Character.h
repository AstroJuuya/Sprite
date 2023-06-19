#pragma once

#include "Graphics.h"
#include "Animation.h"
#include "FrameTimer.h"

class Character
{
public:
	enum State {
		Moving_Left,
		Moving_Right,
		Moving_Up,
		Moving_Down,
		Standing_Left,
		Standing_Right,
		Standing_Up,
		Standing_Down,
		COUNT
	};
public:
	Character(const Animation& spritesheet, const Vei2& position);
	void Animate(Graphics& gfx);
	void Move(const Vec2& delta);

private:
	Animation animation;
	FrameTimer timer;
	Vei2 position = { 0, 0 };
	Vei2 movement_direction = { 0, 0 };
	static constexpr int speed = 250;

	State animation_state = Standing_Down;
	int current_sprite = 0;
	static constexpr float animation_speed = 0.12f;
	float animation_cycle = 0.0f;
};