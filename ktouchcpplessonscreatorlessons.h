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
#ifndef KTOUCHLEVELS_H
#define KTOUCHLEVELS_H

#include <random>
#include <string>
#include <vector>
#include "ktouchcpplessonscreatorlesson.h"

namespace ribi {
namespace ktclc {

struct lessons
{
  lessons(std::mt19937& rng_engine) noexcept;
  std::vector<std::string> to_xml() const noexcept;

  private:

  const std::vector<lesson> m_v;
  static std::vector<lesson> create_levels(std::mt19937& rng_engine) noexcept;

  #ifndef NDEBUG
  static void test() noexcept;
  #endif
};

} //~namespace ktclc
} //~namespace ribi

#endif // KTOUCHLEVELS_H
