#include "Character.h"

Character::Character(const Animation& spritesheet, const Vei2& position)
	:
	animation(spritesheet),
	timer(),
	position(position)
{
}

void Character::Animate(Graphics& gfx)
{
	// get the sprite to draw
	// first column are standing variants
	// and moving sprites of that direction in rows
	Vec2 sprite_at;
	if (animation_state >= 4) {
		sprite_at.x = 0;
		sprite_at.y = animation_state - 4;
	}
	else if (animation_state < 4) {
		sprite_at.x = 1 + current_sprite;
		sprite_at.y = animation_state;
	}
	if (damage_tick) {
		gfx.DrawSpriteSubstitute(
			(int)position.x,
			(int)position.y,
			gfx.GetScreenRect(),
			animation.GetSpriteRect(sprite_at),
			animation.spritesheet,
			animation.chroma,
			damage_color);
		return;
	}
	if (ghostified) {
		gfx.DrawSpriteTransparent(
			(int)position.x,
			(int)position.y,
			gfx.GetScreenRect(),
			animation.GetSpriteRect(sprite_at),
			animation.spritesheet,
			ghostified_alpha,
			animation.chroma);
	}
	else {
		gfx.DrawSprite(
			(int)position.x,
			(int)position.y,
			gfx.GetScreenRect(),
			animation.GetSpriteRect(sprite_at),
			animation.spritesheet,
			animation.chroma);
	}
}

void Character::Move(const Vec2& delta)
{
	float deltatime = timer.Mark();
	position += delta.GetNormalized() * speed * deltatime;

	animation_cycle += deltatime;
	if (animation_cycle > animation_speed) {
		current_sprite += 1;
		animation_cycle = 0;
	}
	if (current_sprite > 3) {
		current_sprite = 0;
	}

	if (damage_tick) {
		damage_cycle += deltatime;
		if (damage_cycle > damage_duration) {
			damage_cycle = 0;
			damage_tick = false;
		}
	}

	// sets moving animation state only if not also moving perpendicular to it
	// to facilitate fluid diagonal movement
	if (delta.x == 0 && delta.y == 0) {
		if (animation_state < Standing_Left) {
			animation_state = State(animation_state + Standing_Left);
		}
		current_sprite = 0;
		animation_cycle = 0;
	}
	else if (delta.x == -1) {
		if (animation_state != Moving_Up && animation_state != Moving_Down || delta.y == 0) {
			animation_state = Moving_Left;
		}
	}
	else if (delta.x == 1) {
		if (animation_state != Moving_Up && animation_state != Moving_Down || delta.y == 0) {
			animation_state = Moving_Right;
		}
	}
	else if (delta.y == -1) {
		if (animation_state != Moving_Left && animation_state != Moving_Right || delta.x == 0) {
			animation_state = Moving_Up;
		}
	}
	else if (delta.y == 1) {
		if (animation_state != Moving_Left && animation_state != Moving_Right || delta.x == 0) {
			animation_state = Moving_Down;
		}
	}
}

void Character::DamageTick()
{
	damage_tick = true;
}

void Character::Ghostify()
{
	if (!ghostified) {
		ghostified = true;
	}
	else if (ghostified) {
		ghostified = false;
	}
}
