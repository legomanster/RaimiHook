#pragma once

#include "IGOFrontEnd.hpp"

#pragma pack(push, 1)
/// <summary>
/// Front-End Manager class
/// </summary>
class FEManager
{
private:
	void* unk0[23];
public:
	/// <summary>
	/// Current IGO Front-End instance
	/// </summary>
	const IGOFrontEnd* IGO;

	/// <summary>
	/// Draws the Front-End
	/// </summary>
	/// <returns>Status code</returns>
	int DrawIGO();
};
#pragma pack(pop)