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
#include "ktouchcpplessonscreatorcourse.h"

#include <algorithm>

#include <sstream>
#include "ktouchcpplessonscreatorhelper.h"

ribi::ktclc::course::course(const int rng_seed) noexcept
  : m_description("KTouch lessons file created by KTouchCppLessonsCreator, www.richelbilderbeek.nl/ToolKTouchCppLessonsCreator.htm"),
    m_levels(create_levels(rng_seed)),
    m_title("C++")
{
  #ifndef NDEBUG
  test();
  #endif
}

ribi::ktclc::lessons ribi::ktclc::course::create_levels(const int rng_seed) noexcept
{
  std::mt19937 rng_engine(rng_seed);
  return lessons(rng_engine);
}

#ifndef NDEBUG
void ribi::ktclc::course::test() noexcept
{
  {
    static bool is_tested = false;
    if (is_tested) return;
    is_tested = true;
  }
  helper();
}
#endif

std::vector<std::string> ribi::ktclc::course::to_xml() const noexcept
{
  std::vector<std::string> v;
  v.push_back("<?xml version=\"1.0\"?>");
  v.push_back("<course>");
  v.push_back("  <id>" + helper().create_uuid() + "</id>");
  v.push_back("  <title>"+m_title+"</title>");
  v.push_back("  <description>" + m_description + "</description>");
  v.push_back("  <keyboardLayout>us</keyboardLayout>");
  const std::vector<std::string> w = m_levels.to_xml();
  std::transform(std::begin(w),std::end(w),std::back_inserter(v),
    [](const std::string& s)
    {
      return std::string("  ") + s;
    }
  );
  v.push_back("</course>");
  return v;
}

