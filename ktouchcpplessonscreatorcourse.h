//---------------------------------------------------------------------------
/*
KTouchCppLessonsCreator, create KTouch lessons for C++ programmers
Copyright (C) 2013-2015 Richel Bilderbeek

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
//---------------------------------------------------------------------------
//From http://www.richelbilderbeek.nl/ToolKTouchCppLessonsCreator.htm
//---------------------------------------------------------------------------
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

  static lessons create_levels(const int rng_seed) noexcept;

  #ifndef NDEBUG
  static void test() noexcept;
  #endif
};

} //~namespace ktclc
} //~namespace ribi


#endif // KTOUCHCPPLESSONSCREATORCOURSE_H
