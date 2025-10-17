#include "SensorData.h"
#include <format>
#include <ranges>
#include <regex>
#include <sstream>

namespace sensors
{
	SensorData::SensorData(std::uint16_t id, SensorType type, std::string_view timestamp, bool status)
		: m_id{ id }, m_type{ type }, m_timestamp{ timestamp }, m_status{ status }
	{
	}

	std::uint16_t SensorData::GetId() const
	{
		return m_id;
	}

	SensorType SensorData::GetType() const
	{
		return m_type;
	}

	const std::string& SensorData::GetTimestamp() const
	{
		return m_timestamp;
	}

	bool SensorData::GetStatus() const
	{
		return m_status;
	}

	std::uint16_t SensorData::GetMonth() const
	{
		// Regex variant
		//std::regex month_regex{ R"(\d{4}-(\d{2})-\d{2}T\d{2}:\d{2}:\d{2})" };
		//if (std::smatch match; std::regex_match(m_timestamp, match, month_regex))
		//{
		//	return std::stoi(match[1].str());
		//}

		return std::stoi(m_timestamp.substr(5, 2));
	}

	std::ostream& operator<< (std::ostream& out, const SensorData& data)
	{
		std::ostringstream values_stream;
		values_stream << data.GetValues().front();
		for (const auto& value : data.GetValues() | std::ranges::views::drop(1))
		{
			values_stream << ", " << value;
		}

		return out << std::format(
			"SensorData(id={}, type={}, timestamp={}, values=[{}], status={})",
			data.GetId(),
			ToString(data.GetType()),
			data.GetTimestamp(),
			values_stream.str(),
			(data.GetStatus() ? "OK" : "BROKEN")
		);
	}

	bool operator< (const SensorData& s1, const SensorData& s2)
	{
		return s1.GetId() < s2.GetId();
	}
}
