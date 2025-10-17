#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

#include "Accelerometer.h"
#include "Thermometer.h"


int main()
{
	using sensors::ISensor;
	using sensors::SensorData;
	using sensors::SensorType;
	using sensors::ToSensorType;
	using sensors::Accelerometer;
	using sensors::Thermometer;


	for (std::ifstream file{ "sensors.log" }; !file.eof(); /* EMPTY */)
	{
		if (!file)
		{
			std::cout << "ifstream not in a good state!";
		}

		std::string id_str, typeStr, timestamp;
		file >> id_str >> typeStr >> timestamp;
		std::uint16_t id{ static_cast<std::uint16_t>(std::stoi(id_str.substr(1, 3))) };
		SensorType type{ ToSensorType(typeStr) };

		float value1, value2, value3;
		std::string status_str;

		if (type == SensorType::ACCM)
			file >> value1 >> value2 >> value3 >> status_str;
		else
			file >> value1 >> status_str;
	}

	return 0;
}

