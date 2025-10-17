#include "Thermometer.h"
#include <format>

namespace sensors
{
	const float Thermometer::kMinValidTemperature{ 50 };
	const float Thermometer::kMaxValidTemperature{ 200 };

	Thermometer::Thermometer(std::uint16_t id, SensorType type, std::string_view timestamp, bool status, float temperature)
		: SensorData(id, type, timestamp, status), m_temperature{ temperature }
	{
	}

	std::vector<float> Thermometer::GetValues() const
	{
		return { m_temperature };
	}

	float Thermometer::GetTemperature() const
	{
		return m_temperature;
	}

	bool sensors::Thermometer::IsMeasurementValid() const
	{
		return GetStatus()
			&& kMinValidTemperature < m_temperature
			&& m_temperature < kMaxValidTemperature;
	}

	std::ostream& operator<< (std::ostream& out, const Thermometer& thermometer)
	{
		return out << std::format(
			"Thermometer(id={}, type={}, timestamp={}, status={}, temperature={})",
			thermometer.GetId(),
			ToString(thermometer.GetType()),
			thermometer.GetTimestamp(),
			(thermometer.GetStatus() ? "OK" : "BROKEN"),
			thermometer.GetTemperature()
		);
	}
}
