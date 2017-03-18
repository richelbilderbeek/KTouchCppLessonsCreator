#include "ktouchcpplessonscreatorwordlist.h"

#include <algorithm>
#include <cassert>

#include "ktouchcpplessonscreatorhelper.h"

ribi::ktclc::word_list::word_list(
  const std::string& chars_in_lesson,
  const std::string& new_characters,
  std::mt19937& rng_engine
) noexcept
  : //m_all{create_all()},
    //m_all_legal{create_all_legal()},
    m_all_legal_and_fitting{create_all_legal_and_fitting(chars_in_lesson)},
    m_all_legal_and_fitting_and_new{create_all_legal_and_fitting_and_new(chars_in_lesson,new_characters)},
    m_chars_in_lesson{chars_in_lesson},
    m_new_char_words{create_new_char_words(new_characters,10,get_lesson_index(chars_in_lesson),rng_engine)}

{
}

std::vector<std::string> ribi::ktclc::word_list::create_all() noexcept
{
  return {
    "^=",
    "<<",
    "<=",
    "==",
    ">=",
    ">>",
    "||",
    "!=",
    "//",
    "/*",
    "{0}",
    "{1}",
    "*/",
    "&&",
    "++a",
    "a==b",
    "a!=b",
    "alignas",
    "alignof",
    "assert",
    "asm",
    ".at",
    ".at(i)",
    "auto",
    "++b",
    "bool",
    "boost::bimap",
    "boost::lexical_cast",
    "boost::scoped_ptr",
    "boost::shared_ptr",
    "boost::timer",
    "boost::weak_ptr",
    "boost::xpressive",
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
    ".empty",
    ".empty()",
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
    "++i",
    "if",
    "#ifdef",
    "#ifndef",
    "i==j",
    "i!=j",
    "#include",
    "inline",
    "int",
    "++j",
    "long",
    "mutable",
    "\\n",
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
    "s[0]",
    "s.at(0)",
    "s.empty()",
    "s.size()",
    "short",
    "signed",
    ".size",
    ".size()",
    "sizeof",
    "s.size()",
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
    "std::array<double,4>",
    "std::array<double,5>",
    "std::array<double,6>",
    "std::array<int,1>",
    "std::array<int,2>",
    "std::array<int,3>",
    "std::array<std::array<double,10>,10>",
    "std::array<std::array<int,8>,9>",
    "std::array<std::array<std::string,10>,10>",
    "std::array<std::string,7>",
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
    "std::deque<double>",
    "std::deque<int>",
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
    "std::list<double>",
    "std::list<int>",
    "std::list<std::string>",
    "std::lower_bound",
    "std::make_heap",
    "std::map",
    "std::map<double,double>",
    "std::map<int,int>",
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
    "std::pair<double,double>",
    "std::pair<int,int>",
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
    "std::queue<double>",
    "std::queue<int>",
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
    "std::set_difference",
    "std::set<int>",
    "std::set_intersection",
    "std::set<std::string>",
    "std::set_symmetric_difference",
    "std::set_union",
    "std::slist",
    "std::sort",
    "std::sort_heap",
    "std::sort(std::begin(v),std::end(v))",
    "std::stable_partition",
    "std::stable_sort",
    "std::stack",
    "std::stack<double>",
    "std::stack<int>",
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
    "std::vector<double>",
    "std::vector<int>",
    "std::vector<std::string>",
    "std::vector<std::vector<double>>",
    "std::vector<std::vector<int>>",
    "std::vector<std::vector<std::string>>",
    "struct",
    "switch",
    "t[0]",
    "t.at(0)",
    "template",
    "t.empty()",
    "this",
    "thread_local",
    "throw",
    "true",
    "try",
    "t.size()",
    "typedef",
    "typeid",
    "typename",
    "union",
    "unsigned",
    "using",
    "v[0]",
    "v[1]",
    "v.at(0)",
    "v.at(1)",
    "v.empty()",
    "v.size()",
    "virtual",
    "void",
    "volatile",
    "w[0]",
    "w.at(0)",
    "w.empty()",
    "w.size()",
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

std::vector<std::string> ribi::ktclc::word_list::create_new_char_words(
  const std::string& new_characters,
  const int how_many,
  const int level,
  std::mt19937& rng_engine
) noexcept
{
  assert(!new_characters.empty());
  const int word_length = 2 + (level / 3);
  //Create a string of word_length
  const int n_additions = word_length / static_cast<int>(new_characters.size());
  std::string s = new_characters;
  for (int i=0; i!=n_additions; ++i)
  {
    s += new_characters;
  }
  std::vector<std::string> v;
  for (int i=0; i!=how_many; ++i)
  {
    std::shuffle(std::begin(s),std::end(s),rng_engine);
    v.push_back(s);
  }
  return v;
}

int ribi::ktclc::get_lesson_index(const word_list& a_word_list) noexcept
{
  const int lesson_index = get_lesson_index(a_word_list.get_chars_in_lesson());
  return lesson_index;
}

int ribi::ktclc::get_lesson_index(const std::string& chars_in_lesson) noexcept
{
  const int lesson_index = static_cast<int>(chars_in_lesson.size()) / 2;
  return lesson_index;
}

std::string ribi::ktclc::word_list::get_version() noexcept
{
  return "1.0";
}

std::vector<std::string> ribi::ktclc::word_list::get_version_history() noexcept
{
  return {
    "2015-10-31: version 1.0: initial version",
  };
}
