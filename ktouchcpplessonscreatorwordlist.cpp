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
#include "ktouchcpplessonscreatorwordlist.h"

#include <algorithm>
#include <cassert>

#include "testtimer.h"
#include "ktouchcpplessonscreatorhelper.h"

ribi::ktclc::word_list::word_list(
  const std::string& chars_in_lesson,
  const std::string& new_characters
) noexcept
  : m_all{create_all()},
    m_all_legal{create_all_legal()},
    m_all_legal_and_fitting{create_all_legal_and_fitting(chars_in_lesson)},
    m_all_legal_and_fitting_and_new{create_all_legal_and_fitting_and_new(chars_in_lesson,new_characters)},
    m_chars_in_lesson{chars_in_lesson}

{
  #ifndef NDEBUG
  test();
  #endif
}

std::vector<std::string> ribi::ktclc::word_list::create_all() noexcept
{
  return {
    " ",
    "==",
    "<=",
    ">=",
    "!=",
    "^=",
    "<<",
    ">>",
    "&&",
    "||",
    "//",
    "/*",
    "*/",
    "++a",
    "++b",
    "a!=b",
    "a==b",
    "alignas",
    "alignof",
    "asm",
    "auto",
    "bool",
    "boost::bimap",
    "boost::lexical_cast",
    "boost::scoped_ptr",
    "boost::shared_ptr",
    "boost::timer",
    "boost::xpressive",
    "boost::weak_ptr",
    "break;",
    "break",
    "C++11",
    "C++11",
    "C++98",
    "C++98",
    "case:",
    "case",
    "catch",
    "char",
    "char16_t",
    "char32_t",
    "class",
    "const",
    "const_cast",
    "const_cast<const double>",
    "const_cast<const int>",
    "const_cast<const std::string>",
    "const_cast<double>",
    "const_cast<int>",
    "const_cast<std::string>",
    "constexpr",
    "continue;",
    "continue",
    "decltype",
    "default:",
    "default",
    "#define",
    "delete",
    "do",
    "double",
    "dynamic_cast",
    "dynamic_cast<const T*>",
    "dynamic_cast<const T*>",
    "dynamic_cast<const T* const>",
    "dynamic_cast<T*>",
    "dynamic_cast<T* const>",
    "#elif",
    "#else",
    "else",
    "enum",
    "explicit",
    "export",
    "extern",
    "false",
    "final",
    "float",
    "for",
    "friend",
    "goto",
    "if",
    "++i",
    "++j",
    "i!=j",
    "i==j",
    "#ifdef",
    "#ifndef",
    "#include",
    "inline",
    "int",
    "long",
    "mutable",
    "namespace",
    "new",
    "noexcept",
    "nullptr",
    "operator==",
    "operator-=",
    "operator--",
    "operator/=",
    "operator",
    "operator*=",
    "operator+=",
    "operator++",
    "private:",
    "private",
    "protected:",
    "protected",
    "public:",
    "public",
    "register",
    "reinterpret_cast",
    "reinterpret_cast<T*>",
    "return",
    "short",
    "signed",
    "sizeof",
    "static",
    "static_assert",
    "static_cast",
    "static_cast<double>",
    "static_cast<int>",
    "std::accumulate",
    "std::adjacent_find",
    "std::all_of",
    "std::any_of",
    "std::array",
    "std::array",
    "std::array<int,1>",
    "std::array<int,2>",
    "std::array<int,3>",
    "std::array<double,4>",
    "std::array<double,5>",
    "std::array<double,6>",
    "std::array<std::string,7>",
    "std::array<std::array<int,8>,9>",
    "std::array<std::array<double,10>,10>",
    "std::array<std::array<std::string,10>,10>",
    "std::begin",
    "std::binary_search",
    "std::bitset",
    "std::bit_vector",
    "std::copy",
    "std::copy_backward",
    "std::copy_if",
    "std::copy_n",
    "std::count",
    "std::count_if",
    "std::deque",
    "std::deque<int>",
    "std::deque<double>",
    "std::deque<std::string>",
    "std::end",
    "std::equal",
    "std::equal_range",
    "std::fill",
    "std::find",
    "std::find_end",
    "std::find_first_of",
    "std::find_if",
    "std::find_if_not",
    "std::for_each",
    "std::generate",
    "std::generate_n",
    "std::hash",
    "std::hash_map",
    "std::hash_multimap",
    "std::hash_multiset",
    "std::hash_set",
    "std::includes",
    "std::inplace_merge",
    "std::iota",
    "std::is_heap",
    "std::is_heap_until",
    "std::is_sorted",
    "std::is_sorted_until",
    "std::iter_swap",
    "std::lexicographical_compare",
    "std::list",
    "std::list<int>",
    "std::list<double>",
    "std::list<std::string>",
    "std::lower_bound",
    "std::make_heap",
    "std::map",
    "std::map<int,int>",
    "std::map<double,double>",
    "std::map<std::string,std::string>",
    "std::max",
    "std::max_element",
    "std::merge",
    "std::min",
    "std::min_element",
    "std::minmax",
    "std::minmax_element",
    "std::mismatch",
    "std::move",
    "std::move_backward",
    "std::multimap",
    "std::multiset",
    "std::next_permutation",
    "std::none_of",
    "std::nth_element",
    "std::pair",
    "std::pair<int,int>",
    "std::pair<double,double>",
    "std::pair<std::string,std::string>",
    "std::partial_sort",
    "std::partial_sort_copy",
    "std::partition",
    "std::partition_copy",
    "std::partition_point",
    "std::pop_heap",
    "std::prev_permutation",
    "std::priority_queue",
    "std::push_heap",
    "std::queue",
    "std::queue<int>",
    "std::queue<double>",
    "std::queue<std::string>",
    "std::random_shuffle",
    "std::random_shuffle(std::begin(v),std::end(v))",
    "std::remove",
    "std::remove_copy",
    "std::remove_copy_if",
    "std::remove_if",
    "std::replace",
    "std::replace_copy",
    "std::replace_copy_if",
    "std::replace_if",
    "std::reverse",
    "std::reverse_copy",
    "std::rope",
    "std::rotate",
    "std::rotate_copy",
    "std::search",
    "std::search_n",
    "std::set",
    "std::set<int>",
    "std::set<std::string>",
    "std::set_difference",
    "std::set_intersection",
    "std::set_symmetric_difference",
    "std::set_union",
    "std::slist",
    "std::sort",
    "std::sort(std::begin(v),std::end(v))",
    "std::sort_heap",
    "std::stable_partition",
    "std::stable_sort",
    "std::stack",
    "std::stack<int>",
    "std::stack<double>",
    "std::stack<std::string>",
    "std::string",
    "std::swap",
    "std::swap_ranges",
    "std::transform",
    "std::unique",
    "std::unique_copy",
    "std::upper_bound",
    "std::valarray",
    "std::vector",
    "std::vector<int>",
    "std::vector<double>",
    "std::vector<std::string>",
    "std::vector<std::vector<int>>",
    "std::vector<std::vector<double>>",
    "std::vector<std::vector<std::string>>",
    "s.empty()",
    "s.size()",
    "s.at(0)",
    "s[0]",
    "struct",
    "switch",
    "t.empty()",
    "t.size()",
    "t.at(0)",
    "t[0]",
    "template",
    "this",
    "thread_local",
    "throw",
    "true",
    "try",
    "typedef",
    "typeid",
    "typename",
    "union",
    "unsigned",
    "using",
    "v.empty()",
    "v.size()",
    "v.at(0)",
    "v[0]",
    "virtual",
    "void",
    "volatile",
    "wchar_t",
    "while"
  };
}

std::vector<std::string> ribi::ktclc::word_list::create_all_legal() noexcept
{
  const auto v = create_all();
  std::vector<std::string> w;
  std::copy_if(
    std::begin(v),
    std::end(v),
    std::back_inserter(w),
    [](const std::string& s) { return !helper().has_forbidden(s); }
  );
  return w;
}

std::vector<std::string> ribi::ktclc::word_list::create_all_legal_and_fitting(
  const std::string& chars_in_lesson
) noexcept
{
  const auto v = create_all_legal();
  std::vector<std::string> w;
  std::copy_if(
    std::begin(v),
    std::end(v),
    std::back_inserter(w),
    [chars_in_lesson](const std::string& s)
    {
      return helper().does_fit(s,chars_in_lesson);
    }
  );
  return w;
}

std::vector<std::string> ribi::ktclc::word_list::create_all_legal_and_fitting_and_new(
  const std::string& chars_in_lesson,
  const std::string& new_characters
) noexcept
{
  const auto v = create_all_legal_and_fitting(chars_in_lesson);

  //Tally the new_characters a word has
  std::vector<int> tally;
  std::transform(
    std::begin(v),
    std::end(v),
    std::back_inserter(tally),
    [chars_in_lesson,new_characters](const std::string& s)
    {
      return helper().calculate_score(s,new_characters);
    }
  );
  assert(v.size() == tally.size());

  //Copy the words in the resulting vector 'tally' times
  std::vector<std::string> w;
  const int sz{static_cast<int>(v.size())};
  for (int i=0; i!=sz; ++i)
  {
    assert(i >= 0);
    assert(i < static_cast<int>(tally.size()));
    assert(i < static_cast<int>(v.size()));
    const int n = tally[i];
    const std::string& s = v[i];
    for (int j=0; j!=n; ++j)
    {
      w.push_back(s);
    }
  }
  return w;
}

int ribi::ktclc::get_lesson_index(const word_list& a_word_list) noexcept
{
  const int lesson_index = static_cast<int>(a_word_list.get_chars_in_lesson().size()) / 2;
  return lesson_index;
}

std::string ribi::ktclc::word_list::get_version() noexcept
{
  return "1.0";
}

std::vector<std::string> ribi::ktclc::word_list::get_version_history() noexcept
{
  return {
    "2013-12-18: version 1.0: initial version",
  };
}

#ifndef NDEBUG
void ribi::ktclc::word_list::test() noexcept
{
  {
    static bool is_tested = false;
    if (is_tested) return;
    is_tested = true;
  }
  const test_timer my_test_timer(__func__,__FILE__,10.0);
  const word_list w("abcdefghijklmnopqrstuvwxyz","ab");
  assert(!w.get_all().empty());
}
#endif
