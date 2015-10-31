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

  #ifndef NDEBUG
  static void test() noexcept;
  #endif

  int ExecuteSpecific(const std::vector<std::string>& args) noexcept override { return execute_specific(args); }
  about GetAbout() const noexcept override;
  help GetHelp() const noexcept override;
  std::string GetVersion() const noexcept override { return get_version(); }
  std::vector<std::string> GetVersionHistory() const noexcept override { return get_version_history(); }
};

} //~namespace ktclc
} //~namespace ribi


#endif // KTOUCHCPPLESSONSCREATORMENUDIALOG_H
