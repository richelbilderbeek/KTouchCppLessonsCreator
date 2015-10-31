#ifndef KTOUCHCPPLESSONSCREATORHELPER_H
#define KTOUCHCPPLESSONSCREATORHELPER_H

#include <algorithm>
#include <string>

namespace ribi {
namespace ktclc {

struct helper
{
  helper() noexcept;

  //Score how much desired_characters are in string
  int calculate_score(
    const std::string& s,
    const std::string& desired_characters
  ) const noexcept;

  ///Resize the vector before the sum of strings exceeds the sum_length,
  ///Examples:
  ///cap_at_sum_length( {"abc","def","ghi"},5 ) == {"abc"}
  ///cap_at_sum_length( {"abc","def","ghi"},7 ) == {"abc","def"}
  std::vector<std::string> cap_at_sum_length(std::vector<std::string> v, const int sum_length) const noexcept;

  std::string concatenate(const std::vector<std::string>& v,const std::string seperator) const noexcept;

  ///Convert to escaped character sequence
  ///Convert "<>" to "&lt;&gt;"
  std::string convert_to_escape(const std::string& s) const noexcept;

  ///Convert to escaped character sequence
  ///Convert '<' to '&lt'
  std::string convert_to_escape(const char c) const noexcept;

  std::string create_uuid() const noexcept;

  ///Are all chars in s present in all?
  bool does_fit(const std::string& s, const std::string all) const noexcept;

  ///Convert 'ab' to 'a and b'
  ///Convert 'abc' to 'a, b and c'
  std::string enumerate(const std::string& s) const noexcept;

  int get_sum_length(const std::vector<std::string>& v) const noexcept;

  static std::string get_version() noexcept;
  static std::vector<std::string> get_version_history() noexcept;

  bool has_forbidden(const std::string& s) const noexcept;

  //Is the character desired
  bool is_desired(
    const char c,
    const std::string& desired_characters
  ) const noexcept;

  template <class T, class R>
  T shuffle(T t, R& rng_engine) const noexcept
  {
    std::shuffle(std::begin(t),std::end(t),rng_engine);
    return t;
  }

  template <class T>
  T sort(T t) const noexcept
  {
    std::sort(std::begin(t),std::end(t));
    return t;
  }

  private:
  #ifndef NDEBUG
  static void test() noexcept;
  #endif
};

} //~namespace ktclc
} // ~namespace ribi

#endif // KTOUCHCPPLESSONSCREATORHELPER_H
