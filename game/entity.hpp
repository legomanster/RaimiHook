#pragma once

#include <type_traits>
#include <math.h>

#include "singleton.hpp"
#include "numerics.hpp"
#include "player_interface.hpp"

#define ENTIY_DATA_ID_HEALTH 0
#define ENTIY_DATA_ID_INTERFACE 11

/// <summary>
/// Entity collider flags
/// </summary>
enum class E_ENTITY_COLLIDER_FLAGS : int
{
	/// <summary>
	/// Collider default value
	/// </summary>
	E_DEFAULT = 803700,

	/// <summary>
	/// Collider is disabled
	/// </summary>
	E_DISABLED = 17564528
};

#pragma pack(push, 1)
/// <summary>
/// Entity health data class
/// </summary>
class entity_health_data
{
private:
	char unk0[272];
public:
	/// <summary>
	/// Current health value
	/// </summary>
	int health;

	/// <summary>
	/// Minimum health value
	/// </summary>
	int min_health;

	/// <summary>
	/// Maximum health value
	/// </summary>
	int max_heath;

	/// <summary>
	/// Sends damage to the current entity
	/// </summary>
	/// <param name="damage">The amount of damage</param>
	void apply_damage(const int& damage);
};
#pragma pack(pop)

#pragma pack(push, 1)
/// <summary>
/// Entity transform properties struct
/// </summary>
struct entity_transform
{
	float rotation_matrix[12];

	/// <summary>
	/// The world position of the entity
	/// </summary>
	vector3d position;
};
#pragma pack(pop)

#pragma pack(push, 1)
/// <summary>
/// Entity class
/// </summary>
class entity
{
private:
	void* unk0[4];
public:
	/// <summary>
	/// Transform properties
	/// </summary>
	entity_transform* transform;
public:
	E_ENTITY_COLLIDER_FLAGS collider_flags;
private:
	char unk1[4];
	void* data_ptr;

private:
	void* get_data(const char& id) const;

public:
	/// <summary>
	/// Gets the health data of the entity
	/// </summary>
	/// <returns>The health data of the entity</returns>
	entity_health_data* get_health_data() const;

	/// <summary>
	/// Sets the relative world position of the entity
	/// </summary>
	/// <param name="position">The target position</param>
	void set_rel_position(vector3d position);

	/// <summary>
	/// Gets the 2D interface of the entity
	/// </summary>
	/// <typeparam name="T">Target player interface</typeparam>
	/// <returns>The 2D interface of the entity</returns>
	template <typename T = player_interface>
	T* get_interface()
	{
		static_assert(std::is_base_of<player_interface, T>::value, "'T' is not a valid player_interface type.");
		return reinterpret_cast<T*>(this->get_data(ENTIY_DATA_ID_INTERFACE));
	}
};
#pragma pack(pop)

#pragma pack(push, 1)
/// <summary>
/// Entity base struct
/// </summary>
struct entity_base
{
	void* unk[48];

	/// <summary>
	/// The entity
	/// </summary>
	entity* entity;
};
#pragma pack(pop)

#pragma pack(push, 1)
/// <summary>
/// Entity linked list class
/// </summary>
struct entity_node
{
	/// <summary>
	/// Next node
	/// </summary>
	entity_node* next;

	/// <summary>
	/// Previous node
	/// </summary>
	entity_node* previous;

	void* unk;

	/// <summary>
	/// Current entity base
	/// </summary>
	entity_base* base;
};
#pragma pack(pop)