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
#include <cassert>
#include <sstream>

#include "ktouchcpplessonscreatorhelper.h"
#include "testtimer.h"

ribi::ktclc::course::course(const int rng_seed) noexcept
  : m_description("KTouch lessons file created by KTouchCppLessonsCreator (using seed " + std::to_string(rng_seed) + "), www.richelbilderbeek.nl/ToolKTouchCppLessonsCreator.htm"),
    m_lessons(create_lessons(rng_seed)),
    m_title("C++")
{
  #ifndef NDEBUG
  test();
  #endif
}

ribi::ktclc::lessons ribi::ktclc::course::create_lessons(const int rng_seed) noexcept
{
  std::mt19937 rng_engine(rng_seed);
  return lessons(rng_engine);
}

std::string ribi::ktclc::course::get_version() noexcept
{
  return "2.0";
}

std::vector<std::string> ribi::ktclc::course::get_version_history() noexcept
{
  return {
    "2013-12-18: version 1.0: initial version",
    "2015-02-18: version 2.0: works with KTouch version 2.3.0, use C++ Core Guideline coding standards"
  };
}

#ifndef NDEBUG
void ribi::ktclc::course::test() noexcept
{
  {
    static bool is_tested = false;
    if (is_tested) return;
    is_tested = true;
  }
  {
    helper();
  }
  //Trigger lessons
  {
    constexpr int rng_seed = 42;
    std::mt19937 rng_engine(rng_seed);
    const lessons a(rng_engine);
    assert(!a.to_xml().empty());
  }
  const test_timer my_test_timer(__func__,__FILE__,1.0);
  {
    constexpr int rng_seed = 42;
    const course a(rng_seed);
    assert(!a.to_xml().empty());
  }
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
  //m_lessons must supply the correct indentation. Note that
  //XML text tag has an indentation level of zero
  const std::vector<std::string> w = m_lessons.to_xml();
  std::copy(
    std::begin(w),
    std::end(w),
    std::back_inserter(v)
  );
  v.push_back("</course>");
  return v;
}

