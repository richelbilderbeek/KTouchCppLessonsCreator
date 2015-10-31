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
#ifndef KTOUCHCPPLESSONSCREATORLESSON_H
#define KTOUCHCPPLESSONSCREATORLESSON_H

#include <random>
#include <string>
#include <vector>

namespace ribi {
namespace ktclc {

struct word_list;

///Can create the XML of a KTouch lesson
struct lesson
{
  ///chars: character that can be assumed to be mastered
  ///new_chars: new character that are to be mastered in this lesson
  ///title: title of this lesson
  ///rng_engine: RNG engine
  lesson(
    const std::string& new_chars,
    const std::string& title,
    std::mt19937& rng_engine,
    const word_list& any_word_list
  ) noexcept;

  static std::string get_version() noexcept;
  static std::vector<std::string> get_version_history() noexcept;

  std::vector<std::string> to_xml() const noexcept;

  private:
  const std::vector<std::string> m_lines;
  const std::string m_new_chars;
  const std::string m_title;
  const std::string m_uuid;

  static std::string create_line(
    std::mt19937& rng_engine,
    const word_list& any_word_list
  ) noexcept;

  static std::vector<std::string> create_lines(
    std::mt19937& rng_engine,
    const word_list& any_word_list
  ) noexcept;

  constexpr static const int n_characters_per_line = 60;
  constexpr static const int n_characters_per_lesson = 1000;
  constexpr static const int n_lines_per_lesson = n_characters_per_lesson / n_characters_per_line;

  #ifndef NDEBUG
  static void test() noexcept;
  #endif
};

} //~namespace ktclc
} //~namespace ribi

#endif // KTOUCHCPPLESSONSCREATORLESSON_H
