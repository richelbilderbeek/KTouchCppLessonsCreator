#include "ktouchcpplessonscreatorcourse.h"

#include <algorithm>
#include <cassert>
#include <sstream>

#include "ktouchcpplessonscreatorhelper.h"

ribi::ktclc::course::course(const int rng_seed) noexcept
  : m_description("KTouch lessons file created by KTouchCppLessonsCreator (using seed " + std::to_string(rng_seed) + "), www.richelbilderbeek.nl/ToolKTouchCppLessonsCreator.htm"),
    m_lessons(create_lessons(rng_seed)),
    m_title("C++")
{

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
    "2015-10-31: version 2.0: works with KTouch version 2.3.0, use C++ Core Guideline coding standards"
  };
}

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

