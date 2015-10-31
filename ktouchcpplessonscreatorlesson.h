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
#ifndef KTOUCHLEVEL_H
#define KTOUCHLEVEL_H

#include <random>
#include <string>
#include <vector>

namespace ribi {
namespace ktclc {

struct lesson
{
  lesson(
    const std::string& chars,
    const std::string& new_chars,
    const std::string& title,
    std::mt19937& rng_engine
  ) noexcept;
  std::vector<std::string> to_xml() const noexcept;

  private:
  const std::string m_line;
  const std::string m_new_chars;
  const std::string m_title;

  static std::string create_line(
    const std::string& chars,
    std::mt19937& rng_engine
  ) noexcept;

  constexpr static const int n_characters_per_lesson = 1000;

  #ifndef NDEBUG
  static void test() noexcept;
  #endif
};

} //~namespace ktclc
} //~namespace ribi

#endif // KTOUCHLEVEL_H
