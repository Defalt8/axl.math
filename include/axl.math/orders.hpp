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
	XYZ,	// Rotate by X-axis then by Y-axis then by Z-axis
	XZY,	// Rotate by X-axis then by Z-axis then by Y-axis
	YXZ,	// Rotate by Y-axis then by X-axis then by Z-axis
	YZX,	// Rotate by Y-axis then by Z-axis then by X-axis
	ZXY,	// Rotate by Z-axis then by X-axis then by Y-axis
	ZYX 	// Rotate by Z-axis then by Y-axis then by X-axis
};

AXLMATHAPI Transform DefaultTransformOrder;
AXLMATHAPI Rotation DefaultRotationOrder;

} // axl.math.Orders
} // axl.math
} // axl
