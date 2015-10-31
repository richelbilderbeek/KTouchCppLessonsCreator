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
  ///Create a word list that
  /// - contains the characters taught in the lesson
  /// - has a preference for the new characters
  word_list(
    const std::string& chars_in_lesson,
    const std::string& new_characters
  ) noexcept;

  ///Get all the words I want to train
  const std::vector<std::string>& get_all() const noexcept { return m_all; }

  ///Get all the words that can currently be handled ky KTouch
  const std::vector<std::string>& get_all_legal() const noexcept { return m_all_legal; }

  ///Get all the words that can currently be handled ky KTouch
  const std::vector<std::string>& get_all_legal_and_fitting() const noexcept { return m_all_legal_and_fitting; }

  ///Get all the words that can currently be handled ky KTouch and are new in this lesson
  const std::vector<std::string>& get_all_legal_and_fitting_and_new() const noexcept { return m_all_legal_and_fitting_and_new; }

  const std::string& get_chars_in_lesson() const noexcept { return m_chars_in_lesson; }

  static std::string get_version() noexcept;
  static std::vector<std::string> get_version_history() noexcept;

  private:
  const std::vector<std::string> m_all;
  const std::vector<std::string> m_all_legal;
  const std::vector<std::string> m_all_legal_and_fitting;
  const std::vector<std::string> m_all_legal_and_fitting_and_new;
  const std::string m_chars_in_lesson;

  ///Create all the words I want to train
  static std::vector<std::string> create_all() noexcept;

  ///Create all the words that can currently be handled ky KTouch
  static std::vector<std::string> create_all_legal() noexcept;

  ///Create all the words that can currently be handled ky KTouch
  ///and contain the characters in this lesson
  static std::vector<std::string> create_all_legal_and_fitting(
    const std::string& chars_in_lesson
  ) noexcept;

  ///Create all the words that can currently be handled ky KTouch
  ///and contain the characters in this lesson
  ///and contain the new characters
  static std::vector<std::string> create_all_legal_and_fitting_and_new(
    const std::string& chars_in_lesson,
    const std::string& new_characters
  ) noexcept;

  #ifndef NDEBUG
  static void test() noexcept;
  #endif
};

///Determine the lesson index from the word list
///Simple the number of keys, divided by two
int get_lesson_index(const word_list& a_word_list) noexcept;

} //~namespace ktclc
} //~namespace ribi


#endif // KTOUCHCPPLESSONSCREATORWORDLIST_H
