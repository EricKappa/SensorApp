#include "SensorType.h"

namespace sensors
{
	SensorType ToSensorType(std::string_view str)
	{
		using enum SensorType;
		if (str == "TEMP")
		{
			return TEMP;
		}
		else if (str == "ACCM")
		{
			return ACCM;
		}
		else
		{
			throw std::exception{ "Incorrect string value to parse a SensorType" };
		}
	}

	std::string ToString(SensorType type)
	{
		using enum SensorType;
		switch (type)
		{
		case TEMP:
			return "TEMP";
		case ACCM:
			return "ACCM";
		default:
			throw std::exception{ "Undefined value for enum SensorType" };
		}
	}
}
