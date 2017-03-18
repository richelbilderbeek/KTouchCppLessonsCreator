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
  assert(!helper().has_forbidden(m_uuid));
  assert(!helper().has_forbidden(m_title));
  assert(!helper().has_forbidden(m_new_chars));
}

std::string ribi::ktclc::lesson::create_line(
  std::mt19937& rng_engine,
  const word_list& any_word_list
) noexcept
{
  //Always add one new_chars word
  std::vector<std::string> v;
  {
    const std::vector<std::string> w
      = helper().shuffle(
        any_word_list.get_new_char_words(),
        rng_engine
      );
    assert(!w.empty());
    v.push_back(w[0]);
  }

  //Collect the new words
  {
    const std::vector<std::string> w
      = helper().shuffle(
          any_word_list.get_all_legal_and_fitting_and_new(),
          rng_engine
        );
    std::copy(
      std::begin(w),
      std::end(w),
      std::back_inserter(v)
    );
  }

  //If there are no new words, just use a random subset of old ones
  if (helper().get_sum_length(v) < n_characters_per_line)
  {
    const std::vector<std::string> w
      = helper().shuffle(
        any_word_list.get_all_legal_and_fitting(),
        rng_engine
      );
    std::copy(
      std::begin(w),
      std::end(w),
      std::back_inserter(v)
    );
  }

  //If there are no new and old words, just use a random new characters
  while (helper().get_sum_length(v) < n_characters_per_line)
  {
    const std::vector<std::string> w
      = helper().shuffle(
        any_word_list.get_new_char_words(),
        rng_engine
      );
    std::copy(
      std::begin(w),
      std::end(w),
      std::back_inserter(v)
    );
  }

  v = helper().cap_at_sum_length(v,n_characters_per_line);

  std::shuffle(std::begin(v),std::end(v),rng_engine);

  const std::string result = helper().concatenate(v," ");
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
    "2015-10-31: version 2.0: works with KTouch version 2.3.0, use C++ Core Guideline coding standards"
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
      [](const std::string& t) { return helper().convert_to_escape(t); }
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
