#pragma once

#include "singleton.hpp"
#include "entity.hpp"
#include "region.hpp"
#include "FEManager.hpp"
#include "camera.hpp"

#define SM3_REGIONS_COUNT 560

#define SM3_SPAWN_PONTS_COUNT 13

typedef size_t spawn_point_index_t;
typedef float mission_checkpoint_t;

#pragma pack(push, 1)
/// <summary>
/// Game class
/// </summary>
class game : public singleton<game, 0xDE7A1C>
{
private:
	char unk0[72];
public:
	/// <summary>
	/// If the game is paused
	/// </summary>
	bool paused;
private:
	char unk1[7];
public:
	/// <summary>
	/// Possibly camera settings
	/// </summary>
	camera_settings* camera_settings;
private:
	char unk2[8];
public:
	/// <summary>
	/// Main camera object instance
	/// </summary>
	camera* spider_camera;
private:
	char unk3[16];
public:
	/// <summary>
	/// Current pause type
	/// </summary>
	int pause_type;

	/// <summary>
	/// Gets the list of entities
	/// </summary>
	/// <returns>The list of entitites</returns>
	static entity_node* get_entities();

	/// <summary>
	/// Gets the list of pedestrian entities
	/// </summary>
	/// <returns>The list of pedestrians</returns>
	static entity_node* get_pedestrians();

	/// <summary>
	/// Gets the list of regions
	/// </summary>
	/// <returns>The list of regions</returns>
	static region* get_regions();

	/// <summary>
	/// Pauses or resumes the game
	/// </summary>
	void toggle_pause(const int& type);
};
#pragma pack(pop)

/// <summary>
/// Simple clock struct
/// </summary>
struct game_clock
{
	DWORD hours;
	DWORD minutes;
	DWORD seconds;
};

/// <summary>
/// Static instance of the Front-End Manager
/// </summary>
static const FEManager* const g_femanager = reinterpret_cast<const FEManager*>(0xE87950);

/// <summary>
/// 
/// </summary>
static const char** const global_game_entities = reinterpret_cast<const char**>(0xD13938);

/// <summary>
/// 
/// </summary>
enum class E_GLOBAL_GAME_ENTITY_INDEX : size_t
{
	ACTOR,
	CAMERA,
	BASE,
	ENTITY,
	MARKER,
	MIC,
	LIGHT_SOURCE,
	PARTICLE,
	ITEM,
	CONGLOMERATE,
	CONGLOMERATE_CLONE,
	DYNAMIC_CONGLOMERATE_CLONE,
	BEAM,
	SKY,
	POLYTUBE,
	NEOLIGHT,
	GAME_CAMERA,
	SPIDERMAN_CAMERA,
	MARKY_CAMERA,
	ANIMATED_CAMERA,
	SNIPER_CAMERA,
	AI_CAMERA,
	ANCHOR_MARKER,
	LINE_ANCHOR,
	SIGN,
	AI_COVER_MARKER,
	LIGHTCONTAINER,
	null,
	IGNORE_FLAVOR
};