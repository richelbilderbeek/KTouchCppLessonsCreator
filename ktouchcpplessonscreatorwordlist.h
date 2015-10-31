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
#ifndef KTOUCHCPPLESSONSCREATORWORDLIST_H
#define KTOUCHCPPLESSONSCREATORWORDLIST_H

#include <string>
#include <vector>

namespace ribi {
namespace ktclc {

///All words used
struct word_list
{
  word_list() noexcept;

  ///Get all the words I want to train
  const std::vector<std::string>& get_all() const noexcept { return m_all; }

  ///Get all the words that can currently be handled ky KTouch
  const std::vector<std::string>& get_all_legal() const noexcept { return m_all_legal; }

  static std::string get_version() noexcept;
  static std::vector<std::string> get_version_history() noexcept;

  private:
  const std::vector<std::string> m_all;
  const std::vector<std::string> m_all_legal;

  ///Get all the words I want to train
  static std::vector<std::string> create_all() noexcept;

  ///Get all the words that can currently be handled ky KTouch
  static std::vector<std::string> create_all_legal() noexcept;

  #ifndef NDEBUG
  static void test() noexcept;
  #endif
};

} //~namespace ktclc
} //~namespace ribi


#endif // KTOUCHCPPLESSONSCREATORWORDLIST_H
