#ifndef KTOUCHCPPLESSONSCREATORMENUDIALOG_H
#define KTOUCHCPPLESSONSCREATORMENUDIALOG_H

#include "menudialog.h"

namespace ribi {
namespace ktclc {

///GUI independent TestConceptMap menu dialog
struct menu_dialog final : public ::ribi::MenuDialog
{
  using about = About;
  using help = Help;

  menu_dialog() noexcept;

  static std::vector<std::string> convert_arguments(const int argc, const char * const argv[]) noexcept { return ConvertArguments(argc,argv); }

  int execute(const std::vector<std::string>& args) noexcept { return Execute(args); }

  static about get_about() noexcept { return menu_dialog().GetAbout(); }
  static help get_help() noexcept { return menu_dialog().GetHelp(); }

  static std::string get_version() noexcept;
  static std::vector<std::string> get_version_history() noexcept;

  private:

  int execute_specific(const std::vector<std::string>& args) noexcept;

  int ExecuteSpecific(const std::vector<std::string>& args) noexcept override { return execute_specific(args); }
  about GetAbout() const noexcept override;
  help GetHelp() const noexcept override;
  std::string GetVersion() const noexcept override { return get_version(); }
  std::vector<std::string> GetVersionHistory() const noexcept override { return get_version_history(); }
};

} //~namespace ktclc
} //~namespace ribi


#endif // KTOUCHCPPLESSONSCREATORMENUDIALOG_H
