#ifndef KTOUCHCPPLESSONSCREATORCOURSE_H
#define KTOUCHCPPLESSONSCREATORCOURSE_H

#include <string>
#include <vector>

#include "ktouchcpplessonscreatorlessons.h"

namespace ribi {
namespace ktclc {

///Can create the XML of a KTouch course
struct course
{
  course(const int rng_seed) noexcept;

  static std::string get_version() noexcept;
  static std::vector<std::string> get_version_history() noexcept;

  std::vector<std::string> to_xml() const noexcept;

  private:
  const std::string m_description;
  const lessons m_lessons;
  const std::string m_title;

  static lessons create_lessons(const int rng_seed) noexcept;
};

} //~namespace ktclc
} //~namespace ribi


#endif // KTOUCHCPPLESSONSCREATORCOURSE_H
