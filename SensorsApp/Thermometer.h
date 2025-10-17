#pragma once

#include <cstdint>
#include <iostream>
#include <string_view>
#include <vector>

#include "SensorData.h"

namespace sensors
{
	class Thermometer : public SensorData
	{
	private:
		static const float kMinValidTemperature;
		static const float kMaxValidTemperature;

	private:
		float m_temperature;

	public:
		Thermometer(std::uint16_t id, SensorType type, std::string_view timestamp, bool status, float temperature);

		std::vector<float> GetValues() const override;
		float GetTemperature() const;

		bool IsMeasurementValid() const override;

	};

	std::ostream& operator<< (std::ostream& out, const Thermometer& thermometer);

}
