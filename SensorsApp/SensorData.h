#pragma once

#include <cstdint>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

#include "ISensor.h"
#include "SensorType.h"

namespace sensors
{
	class SensorData : public ISensor
	{
	private:
		std::uint16_t m_id;
		SensorType m_type;
		std::string m_timestamp;
		bool m_status;

	public:
		SensorData(std::uint16_t id, SensorType type, std::string_view timestamp, bool status);

		std::uint16_t GetId() const;
		SensorType GetType() const;
		const std::string& GetTimestamp() const;
		virtual std::vector<float> GetValues() const = 0;
		bool GetStatus() const;

		std::uint16_t GetMonth() const;

	};

	std::ostream& operator<< (std::ostream& out, const SensorData& data);

}
