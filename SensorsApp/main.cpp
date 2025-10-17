#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

#include "Accelerometer.h"
#include "Thermometer.h"

bool comparatorTimestamp(const sensors::SensorData* s1, const sensors::SensorData* s2)
{
	return s1->GetTimestamp() > s2->GetTimestamp();
}

int main()
{
	using sensors::ISensor;
	using sensors::SensorData;
	using sensors::SensorType;
	using sensors::ToSensorType;
	using sensors::Accelerometer;
	using sensors::Thermometer;

	std::vector<ISensor*> sensors;

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
		{
		file >> value1 >> value2 >> value3 >> status_str;
		sensors.push_back(new Accelerometer{ id,type,timestamp,status_str == "OK",value1,value2,value3 });
		}
		else
		{
		file >> value1 >> status_str;
		sensors.push_back(new Thermometer{ id,type,timestamp,status_str == "OK",value1 });
		}
	}
	for (auto sensor : sensors)
	{
		auto tempPtr = dynamic_cast<Thermometer*>(sensor);

			if (tempPtr != nullptr&&sensor->IsMeasurementValid() && tempPtr->GetMonth() >= 9u && tempPtr->GetMonth() <= 11u)
				//sensor->GetType() == SensorType::TEMP)
			std::cout << *tempPtr << '\n'<<'\n';
	}
	/*std::sort(sensors.begin(), sensors.end(), comparatorTimestamp);
	for (auto sensor : sensors)
		std::cout << *sensor << '\n';*/

	return 0;
}

