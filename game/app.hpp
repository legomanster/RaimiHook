#pragma once

#include "singleton.hpp"
#include "game.hpp"

#define SM3_FIXED_DELTA_TIME 0.033333335f
#define SM3_MIN_FIXED_DELTA_TIME 0.0000001f

#pragma pack(push, 1)
/// <summary>
/// Game's application class. This is where everything begins
/// </summary>
class app : public singleton<app, 0xDE7DA4>
{
private:
	void* unk1, *unk2, *unk3;
public:
	/// <summary>
	/// same as game::inst()
	/// </summary>
	game* game_inst;

	/// <summary>
	/// Current framerate of the game
	/// </summary>
	static float& fps;

	/// <summary>
	/// The fixed delta time of the game's engine
	/// </summary>
	static float& fixed_delta_time;

	/// <summary>
	/// Gets the current delta time of the game
	/// </summary>
	inline static float get_delta_time() { return 1 / app::fps; }
};
#pragma pack(pop)