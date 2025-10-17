#include "Accelerometer.h"
#include <format>

namespace sensors
{
	const float Accelerometer::kMinValidAcceleration{ -5'000 };
	const float Accelerometer::kMaxValidAcceleration{ 5'000 };

	Accelerometer::Accelerometer(
		std::uint16_t id,
		SensorType type,
		std::string_view timestamp,
		bool status,
		float xAcceleration,
		float yAcceleration,
		float zAcceleration
	)
		: SensorData(id, type, timestamp, status)
		, m_xAcceleration{ xAcceleration }
		, m_yAcceleration{ yAcceleration }
		, m_zAcceleration{ zAcceleration }
	{
	}

	std::vector<float> Accelerometer::GetValues() const
	{
		return { m_xAcceleration, m_yAcceleration, m_zAcceleration };
	}

	float Accelerometer::GetXAcceleration() const
	{
		return m_xAcceleration;
	}

	float Accelerometer::GetYAcceleration() const
	{
		return m_yAcceleration;
	}

	float Accelerometer::GetZAcceleration() const
	{
		return m_zAcceleration;
	}

	bool sensors::Accelerometer::IsMeasurementValid() const
	{
		return GetStatus()
			&& kMinValidAcceleration < m_xAcceleration
			&& m_xAcceleration < kMaxValidAcceleration
			&& kMinValidAcceleration < m_yAcceleration
			&& m_yAcceleration < kMaxValidAcceleration
			&& kMinValidAcceleration < m_zAcceleration
			&& m_zAcceleration < kMaxValidAcceleration;
	}

	std::ostream& operator<< (std::ostream& out, const Accelerometer& accelerometer)
	{
		return out << std::format(
			"Accelerometer(id={}, type={}, timestamp={}, status={}, xAcceleration={}, yAcceleration={}, zAcceleration={})",
			accelerometer.GetId(),
			ToString(accelerometer.GetType()),
			accelerometer.GetTimestamp(),
			(accelerometer.GetStatus() ? "OK" : "BROKEN"),
			accelerometer.GetXAcceleration(),
			accelerometer.GetYAcceleration(),
			accelerometer.GetZAcceleration()
		);
	}
}
