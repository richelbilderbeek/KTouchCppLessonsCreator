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
#include "ktouchcpplessonscreatorlessons.h"

#include <algorithm>
#include <cassert>
#include <numeric>

#include "ktouchcpplessonscreatorhelper.h"
#include "testtimer.h"
#include "trace.h"

ribi::ktclc::lessons::lessons(std::mt19937& rng_engine) noexcept
  : m_v(create_levels(rng_engine))
{
  #ifndef NDEBUG
  test();
  #endif
}

std::vector<ribi::ktclc::lesson> ribi::ktclc::lessons::create_levels(
  std::mt19937& rng_engine
) noexcept
{
  const std::vector<std::string> new_chars
  {
    //Cannot allow / because file will mess up
    //Cannot allow < because file will mess up
    //Cannot allow & because file will mess up
    "fj","dk","sl","a;","gh'", //Home
    "cn","vm","b,",".x","z\\", //Low
    "eu","ri","to","yp","w[","q]", //High
    "39","48","57","60","2-","1=","`", //Numbers
    "FJ","DK","SL","A:","GH\"", //Shift + Home
    "CN","VM","B",">X","Z?", //Shift + Low
    "EU","RI","TO","YP","W{","Q}", //Shift + High
    "#(","$*","%","^)","@_","!+","~|" //Shift + Numbers
  };
  #ifndef NDEBUG
  {
    const std::string all_chars = "`1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./~!@#$%^*()_+QWERTYUIOP{}ASDFGHJKL:\"ZXCVBNM>?|";
    const std::string all_chars_sorted = helper().sort(all_chars);

    std::string new_chars_str;
    std::for_each(
      std::begin(new_chars),
      std::end(new_chars),
      [&new_chars_str](const std::string& s) { new_chars_str+=s; }
    );
    const std::string new_chars_str_sorted = helper().sort(new_chars_str);

    std::string difference;
    std::set_difference(
      std::begin(new_chars_str_sorted),
      std::end(new_chars_str_sorted),
      std::begin(all_chars_sorted),
      std::end(all_chars_sorted),
      std::back_inserter(difference)
    );
    //TRACE(difference);


    assert(new_chars_str.size() == all_chars.size());
    assert(
      std::accumulate(
        std::begin(new_chars),
        std::end(new_chars),
        0,
        [](const int init, const std::string& t)
        {
          return init + static_cast<int>(t.size());
        }
      )
      == static_cast<int>(all_chars.size())
      && "All characters must be present"
    );
  }
  #endif
  std::vector<std::string> all_chars = new_chars;
  if (all_chars.size() > 1)
  {
    const int sz = static_cast<int>(all_chars.size());
    for (int from=0; from!=sz-1; ++from)
    {
      const std::string to_append = all_chars.at(from);
      for (int to=from+1; to!=sz; ++to)
      {
        all_chars.at(to)+=new_chars.at(from);
      }
    }
  }

  assert(all_chars.size() == new_chars.size());
  const int sz = all_chars.size();

  std::vector<lesson> levels;

  for (int i=0; i!=sz; ++i)
  {
    lesson level(
      all_chars.at(i),
      new_chars.at(i),
      "Lesson " + std::to_string(i),
      rng_engine
    );
    levels.push_back(level);

  }
  return levels;
}

std::string ribi::ktclc::lessons::get_version() noexcept
{
  return "2.0";
}

std::vector<std::string> ribi::ktclc::lessons::get_version_history() noexcept
{
  return {
    "2013-12-18: version 1.0: initial version",
    "2015-02-18: version 2.0: works with KTouch version 2.3.0, use C++ Core Guideline coding standards"
  };
}

#ifndef NDEBUG
void ribi::ktclc::lessons::test() noexcept
{
  {
    static bool is_tested = false;
    if (is_tested) return;
    is_tested = true;
  }
  helper();
  const test_timer my_test_timer(__func__,__FILE__,1.0);
  {
    constexpr int rng_seed = 42;
    std::mt19937 rng_engine(rng_seed);
    const lessons a(rng_engine);
    assert(!a.to_xml().empty());
  }
}
#endif

std::vector<std::string> ribi::ktclc::lessons::to_xml() const noexcept
{
  std::vector<std::string> v;
  v.push_back("<lessons>");
  {
    std::for_each(
      std::begin(m_v),
      std::end(m_v),
      [&v](const lesson& level)
      {
        const auto w = level.to_xml();
        std::transform(
          std::begin(w),
          std::end(w),
          std::back_inserter(v),
          [](const std::string& s)
          {
            return std::string("  ") + s;
          }
        );
      }
    );
  }
  v.push_back("</lessons>");
  return v;
}
