#pragma once

#include <cstdint>
#include <iostream>
#include <string_view>
#include <vector>

#include "SensorData.h"

namespace sensors
{
	class Accelerometer : public SensorData
	{
	private:
		static const float kMinValidAcceleration;
		static const float kMaxValidAcceleration;

	private:
		float m_xAcceleration;
		float m_yAcceleration;
		float m_zAcceleration;

	public:
		Accelerometer(
			std::uint16_t id,
			SensorType type,
			std::string_view timestamp,
			bool status,
			float xAcceleration,
			float yAcceleration,
			float zAcceleration
		);

		std::vector<float> GetValues() const override;
		float GetXAcceleration() const;
		float GetYAcceleration() const;
		float GetZAcceleration() const;

		bool IsMeasurementValid() const override;
	};

	std::ostream& operator<< (std::ostream& out, const Accelerometer& accelerometer);

}
