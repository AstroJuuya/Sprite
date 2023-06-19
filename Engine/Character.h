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
	void DamageTick();
	void Ghostify();

private:


private:
	Animation animation;
	FrameTimer timer;
	Vei2 position = { 0, 0 };
	Vei2 movement_direction = { 0, 0 };
	static constexpr int speed = 250;

	bool ghostified = false;
	static constexpr int ghostified_alpha = 50;

	bool damage_tick = false;
	static constexpr Color damage_color = Colors::Red;
	static constexpr float damage_duration = 0.06f;
	float damage_cycle = 0.0f;

	State animation_state = Standing_Down;
	int current_sprite = 0;
	static constexpr float animation_speed = 0.12f;
	float animation_cycle = 0.0f;
};