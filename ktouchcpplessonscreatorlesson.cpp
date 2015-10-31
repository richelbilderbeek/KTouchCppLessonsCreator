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
#include "ktouchcpplessonscreatorlesson.h"

#include <algorithm>
#include <cassert>
#include <numeric>
#include <set>
#include <sstream>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "ktouchcpplessonscreatorhelper.h"
#include "ktouchcpplessonscreatorwordlist.h"
#include "testtimer.h"

ribi::ktclc::lesson::lesson(
  const std::string& new_chars,
  const std::string& title,
  std::mt19937& rng_engine,
  const word_list& any_word_list
)  noexcept
  : m_lines{create_lines(rng_engine,any_word_list)},
    m_new_chars{new_chars},
    m_title{title},
    m_uuid{helper().create_uuid()}
{
  #ifndef NDEBUG
  test();
  #endif
  assert(!helper().has_forbidden(m_uuid));
  assert(!helper().has_forbidden(m_title));
  assert(!helper().has_forbidden(m_new_chars));
}

std::string ribi::ktclc::lesson::create_line(
  std::mt19937& rng_engine,
  const word_list& any_word_list
) noexcept
{
  std::vector<std::string> w = any_word_list.get_all_legal_and_fitting_and_new();
  std::shuffle(std::begin(w),std::end(w),rng_engine);

  //Keep the first 30 chars of words
  {
    const int sz = static_cast<int>(w.size());
    int sum = 0;
    for (int i=0; i!=sz; ++i)
    {
      assert(i >= 0);
      assert(i < static_cast<int>(w.size()));
      sum += static_cast<int>(w[i].size());
      if (sum > 30)
      {
        w.resize(i);
        break;
      }
    }
  }
  //Add words until n_characters_per_line chars is reached
  const int n_chars_used = std::accumulate(
    std::begin(w),
    std::end(w),
    0,
    [](int& init, const std::string& s)
    {
      return init + static_cast<int>(s.size());
    }
  );
  // - a lesson have about n_characters_per_line chars
  const int n_chars_extra = n_characters_per_line - n_chars_used;
  const int level = get_lesson_index(any_word_list);
  for (int i=0; i!=n_chars_extra; ++i)
  {
    // - word length = 2 + (level / 3)
    const int word_length = 2 + (level / 3);
    if (i % word_length == 0) { w.push_back(""); }
    const int index = std::rand() % static_cast<int>(any_word_list.get_chars_in_lesson().size());
    w.back()+=any_word_list.get_chars_in_lesson()[index];
  }

  std::shuffle(std::begin(w),std::end(w),rng_engine);

  std::string result;
  std::for_each(
    std::begin(w),
    std::end(w),
    [&result](const std::string& s)
    {
      result += (s + std::string(" "));
    }
  );
  //Remove trailing whitespace
  result.resize(result.size()-1);

 return result;
}

std::vector<std::string> ribi::ktclc::lesson::create_lines(
  std::mt19937& rng_engine,
  const word_list& any_word_list
) noexcept
{
  std::vector<std::string> v;
  const int n_lines = n_lines_per_lesson;
  for (int i=0; i!=n_lines; ++i)
  {
    v.push_back(create_line(rng_engine,any_word_list));
  }
  return v;
}

std::string ribi::ktclc::lesson::get_version() noexcept
{
  return "2.0";
}

std::vector<std::string> ribi::ktclc::lesson::get_version_history() noexcept
{
  return {
    "2013-12-18: version 1.0: initial version",
    "2015-02-18: version 2.0: works with KTouch version 2.3.0, use C++ Core Guideline coding standards"
  };
}

std::vector<std::string> ribi::ktclc::lesson::to_xml() const noexcept
{
  assert(!helper().has_forbidden(m_uuid));
  assert(!helper().has_forbidden(m_title));
  assert(!helper().has_forbidden(m_new_chars));

  std::vector<std::string> v;
  v.push_back("    <lesson>");
  v.push_back("      <id>" + m_uuid + "</id>");
  v.push_back("      <title>" + m_title + "</title>");
  v.push_back("      <newCharacters>" + m_new_chars + "</newCharacters>");
  {
    //There must be no spaces in the text:
    //
    // BAD:
    // <lesson>
    //   <text>
    //     fjfj fjfj fjfj fjfj
    //     fjfj fjfj fjfj fjfj
    //   </text>
    // </lesson>
    //
    // GOOD:
    // <lesson>
    //   <text>fjfj fjfj fjfj fjfj
    // fjfj fjfj fjfj fjfj</text>
    // </lesson>
    //
    // If the space is in the text,
    // KTouch interprets it as a long
    // series of spaces that need to be typed
    std::stringstream s;
    s << "      <text>";
    //The string is converted to non-invasive XML here, i.e.
    // '<' becomes '&lt;'
    std::transform(
      std::begin(m_lines),
      std::end(m_lines),
      std::ostream_iterator<std::string>(s,"\n"),
      [](const std::string& s) { return helper().convert_to_escape(s); }
    );
    std::string text = s.str();
    assert(!text.empty());
    text.pop_back(); //Pop the trailing '\n' to direct append the </text>
    text += "</text>";
    v.push_back(text);
  }
  v.push_back("    </lesson>");
  return v;
}

#ifndef NDEBUG
void ribi::ktclc::lesson::test() noexcept
{
  {
    static bool is_tested = false;
    if (is_tested) return;
    is_tested = true;
  }
  {
    helper();
    word_list("abcdefghijklmnopqrstuvwxyz","ab");
  }
  const test_timer test_timer(__func__,__FILE__,1.0);
  const word_list a_word_list("abcdefghijklmnopqrstuvwxyz","ab");
  {
    constexpr int rng_seed = 42;
    std::mt19937 rng_engine(rng_seed);
    const lesson a(
      "AB",
      "test title",
      rng_engine,
      a_word_list
    );
    assert(!a.to_xml().empty());
  }
}
#endif
