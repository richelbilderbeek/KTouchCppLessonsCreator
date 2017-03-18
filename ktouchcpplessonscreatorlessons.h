#ifndef KTOUCHCPPLESSONSCREATORLESSONS_H
#define KTOUCHCPPLESSONSCREATORLESSONS_H

#include <random>
#include <string>
#include <vector>
#include "ktouchcpplessonscreatorlesson.h"

namespace ribi {
namespace ktclc {

///Can create the XML of KTouch lesson series
struct lessons
{
  lessons(std::mt19937& rng_engine) noexcept;
  std::vector<std::string> to_xml() const noexcept;

  static std::string get_version() noexcept;
  static std::vector<std::string> get_version_history() noexcept;

  private:

  const std::vector<lesson> m_lesson;
  static std::vector<lesson> create_lessons(std::mt19937& rng_engine) noexcept;
};

} //~namespace ktclc
} //~namespace ribi

#endif // KTOUCHCPPLESSONSCREATORLESSONS_H
