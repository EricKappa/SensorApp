#pragma once

#include <cstdint>
#include <string>
#include <string_view>

namespace sensors
{
	enum class SensorType : std::uint8_t
	{
		TEMP,
		ACCM,
	};

	SensorType ToSensorType(std::string_view str);

	std::string ToString(SensorType type);
}
