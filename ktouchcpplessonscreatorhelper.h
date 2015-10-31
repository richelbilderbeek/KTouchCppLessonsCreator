#ifndef KTOUCHCPPLESSONSCREATORHELPER_H
#define KTOUCHCPPLESSONSCREATORHELPER_H

#include <algorithm>
#include <string>

namespace ribi {
namespace ktclc {

struct helper
{
  helper() noexcept;

  std::string create_uuid() const noexcept;

  ///Are all chars in s present in all?
  bool does_fit(const std::string& s, const std::string all) const noexcept;

  static std::string get_version() noexcept;
  static std::vector<std::string> get_version_history() noexcept;

  bool has_forbidden(const std::string& s) const noexcept;

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
