#pragma once
#include "lib.hpp"

namespace axl {
namespace math {
namespace Orders {

enum class Transform {
	STR,	// Scale then Translate then Rotate
	SRT,	// Scale then Rotate then Translate
	TSR,	// Translat then, Scale then Rotate
	TRS,	// Translate then Rotate then Scale
	RST,	// Rotate then Scale then Translate
	RTS 	// Rotate then Translate then Scale
};
enum class Rotation {
	NONE,	// No rotation
	XYZ,	// Rotate by X-axis then by Y-axis then by Z-axis
	XZY,	// Rotate by X-axis then by Z-axis then by Y-axis
	YXZ,	// Rotate by Y-axis then by X-axis then by Z-axis
	YZX,	// Rotate by Y-axis then by Z-axis then by X-axis
	ZXY,	// Rotate by Z-axis then by X-axis then by Y-axis
	ZYX,	// Rotate by Z-axis then by Y-axis then by X-axis
	XY,		// Rotate by X-axis then by Y-axis. *Ignores Z-axis
	XZ, 	// Rotate by X-axis then by Z-axis. *Ignores Y-axis
	YX, 	// Rotate by Y-axis then by X-axis. *Ignores Z-axis
	YZ, 	// Rotate by Y-axis then by Z-axis. *Ignores X-axis
	ZX, 	// Rotate by Z-axis then by X-axis. *Ignores Y-axis
	ZY, 	// Rotate by Z-axis then by Y-axis. *Ignores X-axis	
	X, 		// Rotate by X-axis. *Ignores Y-axis and Z-axis
	Y, 		// Rotate by Y-axis. *Ignores X-axis and Z-axis
	Z 		// Rotate by Z-axis. *Ignores X-axis and Y-axis	
};

AXLMATHAPI Transform DefaultTransformOrder;
AXLMATHAPI Rotation DefaultRotationOrder;

} // axl.math.Orders
} // axl.math
} // axl
