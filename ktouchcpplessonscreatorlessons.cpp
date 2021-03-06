#include "ktouchcpplessonscreatorlessons.h"

#include <algorithm>
#include <cassert>
#include <numeric>
#include <sstream>

#include "ktouchcpplessonscreatorhelper.h"
#include "ktouchcpplessonscreatorwordlist.h"

ribi::ktclc::lessons::lessons(std::mt19937& rng_engine) noexcept
  : m_lesson(create_lessons(rng_engine))
{

}

std::vector<ribi::ktclc::lesson> ribi::ktclc::lessons::create_lessons(
  std::mt19937& rng_engine
) noexcept
{
  const std::vector<std::string> new_chars
  {
    "fjdksla;gh", //Home
    "cnvmb,.xz/", //Low
    "euritoypwq[]", //Top
    "0123456789-=", "`\\", //Numbers
    "{}", //Top
    "?:", //Home
    "+_","()","!*","|^","#~","%@$" //Shift + Numbers
  };
  #ifndef NDEBUG
  {
    const std::string all_chars = "`1234567890-=qwertyuiop[]asdfghjkl;zxcvbnm,.~!@#$%^*()_+{}:?|\\/";
    assert(!helper().has_forbidden(all_chars));
    const std::string all_chars_sorted = helper().sort(all_chars);

    std::string new_chars_str;
    std::for_each(
      std::begin(new_chars),
      std::end(new_chars),
      [&new_chars_str](const std::string& s) { new_chars_str+=s; }
    );
    assert(!helper().has_forbidden(new_chars_str));

    const std::string new_chars_str_sorted
      = helper().sort(new_chars_str);

    #ifndef NDEBUG
    //All the characters in new_chars must be in all_chars
    {
      std::string difference;
      std::set_difference(
        std::begin(new_chars_str_sorted),
        std::end(  new_chars_str_sorted),
        std::begin(all_chars_sorted),
        std::end(  all_chars_sorted),
        std::back_inserter(difference)
      );
      assert(difference.empty());
    }
    #endif
    assert(new_chars_str.size() == all_chars.size()); //Follows from difference being empty

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
      assert(from >= 0);
      assert(from < static_cast<int>(new_chars.size()));
      assert(from < static_cast<int>(all_chars.size()));
      const std::string to_append = all_chars[from];
      for (int to=from+1; to!=sz; ++to)
      {
        assert(to >= 0);
        assert(to < static_cast<int>(all_chars.size()));
        all_chars[to]+=new_chars[from];
      }
    }
  }

  assert(all_chars.size() == new_chars.size());
  const int sz = all_chars.size();

  std::vector<lesson> lessons;

  for (int i=0; i!=sz; ++i)
  {
    assert(i >= 0);
    assert(i < static_cast<int>(all_chars.size()));
    assert(i < static_cast<int>(new_chars.size()));
    const word_list word_list_for_this_lesson(
      all_chars[i],
      new_chars[i],
      rng_engine
    );
    lesson this_lesson(
      new_chars[i],
      "Lesson "
        + std::to_string(i + 1) // Human counting
        + ": "
        + helper().enumerate(new_chars[i]),
      rng_engine,
      word_list_for_this_lesson
    );
    lessons.push_back(this_lesson);

  }
  return lessons;
}

std::string ribi::ktclc::lessons::get_version() noexcept
{
  return "2.1";
}

std::vector<std::string> ribi::ktclc::lessons::get_version_history() noexcept
{
  return {
    "2013-12-18: version 1.0: initial version",
    "2015-10-31: version 2.0: works with KTouch version 2.3.0, use C++ Core Guideline coding standards",
    "2015-10-31: version 2.1: accept forward slash"
  };
}

std::vector<std::string> ribi::ktclc::lessons::to_xml() const noexcept
{
  std::vector<std::string> v;
  v.push_back("  <lessons>");
  {
    std::for_each(
      std::begin(m_lesson),
      std::end(m_lesson),
      [&v](const lesson& lesson)
      {
        //m_lesson must supply the correct indentation.
        //Note that the XML text tag has an indentation level of zero
        const auto w = lesson.to_xml();
        std::copy(
          std::begin(w),
          std::end(w),
          std::back_inserter(v)
        );
      }
    );
  }
  v.push_back("  </lessons>");
  return v;
}
