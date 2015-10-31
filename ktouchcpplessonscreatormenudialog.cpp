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
#include "ktouchcpplessonscreatormenudialog.h"

#include <fstream>
#include <iostream>
#include <iterator>

#include "fileio.h"
#include "testtimer.h"
#include "trace.h"

#include "ktouchcpplessonscreatorhelper.h"
#include "ktouchcpplessonscreatorcourse.h"

ribi::ktclc::menu_dialog::menu_dialog() noexcept
{
  #ifndef NDEBUG
  test();
  #endif
}

int ribi::ktclc::menu_dialog::execute_specific(const std::vector<std::string>& args) noexcept
{
  const int argc = static_cast<int>(args.size());
  assert(argc >= 1);

  //Silent
  bool silent{false};
  if (std::count(std::begin(args),std::end(args),"-e") || std::count(std::begin(args),std::end(args),"--silent"))
  {
    silent = true;
  }

  //RNG seed
  int rng_seed = 42;
  for (int i=1; i < argc-1; ++i) // < because argc can be 0
  {
    assert(i >= 0);
    assert(i < argc);
    if (args[i] == "-r" || args[i] == "--rng_seed")
    {
      const int j{i+1};
      assert(j < argc);
      try
      {
        rng_seed = std::stoi(args[j]);
      }
      catch (std::exception&)
      {
        std::cout
          << "Please specify an RNG seed, "
          << "by supplying a number after the -r or --rng_seed flag,"
          << "for example '42'"
          << std::endl
        ;
        return 1;
      }
      break;
    }
  }
  if (!silent)
  {
    std::cout << "RNG seed: " << rng_seed << std::endl;
  }

  //Output filename
  std::string output_filename = "";
  assert(output_filename.empty());
  for (int i=1; i < argc-1; ++i) // < because argc can be 0
  {
    assert(i >= 0);
    assert(i < argc);
    if (args[i] == "-o" || args[i] == "--output_file"|| args[i] == "--output_filename")
    {
      const int j{i+1};
      assert(j < argc);
      output_filename = args[j];
      break;
    }
  }
  if (!silent)
  {
    if (!output_filename.empty())
    {
      std::cout << "Output filename: " << output_filename << std::endl;
    }
  }

  const auto v = ribi::ktclc::course(rng_seed).to_xml();

  //To file or to screen
  if (!output_filename.empty())
  {
    std::ofstream f(output_filename);
    std::copy(
      std::begin(v),
      std::end(v),
      std::ostream_iterator<std::string>(f,"\n")
    );
    if (!silent)
    {
      std::cout << "Successfully created file " << output_filename << std::endl;
    }
  }
  else
  {
    std::copy(
      std::begin(v),
      std::end(v),
      std::ostream_iterator<std::string>(std::cout,"\n")
    );
  }
  return 0;
}

ribi::About ribi::ktclc::menu_dialog::GetAbout() const noexcept
{
  About a(
    "Richel Bilderbeek",
    "KTouchCppLessonsCreator",
    "create KTouch lessons for C++ programmers",
    "on the 31st of October 2015",
    "2013-2015",
    "http://www.richelbilderbeek.nl/ToolKTouchCppLessonsCreator.htm",
    GetVersion(),
    GetVersionHistory());

  a.AddLibrary("apfloat version: 2.4.1");
  a.AddLibrary("FileIo version: " + fileio::FileIo().GetVersion());
  a.AddLibrary("test_timer version: " + test_timer::GetVersion());
  a.AddLibrary("Trace version: " + Trace::GetVersion());

  a.AddLibrary("ribi::ktclc::course version: " + ribi::ktclc::course::get_version());
  a.AddLibrary("ribi::ktclc::helper version: " + ribi::ktclc::helper::get_version());
  a.AddLibrary("ribi::ktclc::lesson version: " + ribi::ktclc::lesson::get_version());
  a.AddLibrary("ribi::ktclc::lessons version: " + ribi::ktclc::lessons::get_version());

  return a;
}

ribi::Help ribi::ktclc::menu_dialog::GetHelp() const noexcept
{
  return ribi::Help(
    this->GetAbout().GetFileTitle(),
    this->GetAbout().GetFileDescription(),
    {
      Help::Option('e',"silent","Produce no output"),
      Help::Option('o',"output_file","output filename, output sent to STDOUT if none specified"),
      Help::Option('r',"rng_seed","Random number seed, 0 if none specified"),
    },
    {
      "KTouchCppLessonsCreator",
      "KTouchCppLessonsCreator -o ktouch.cpp.xml",
      "KTouchCppLessonsCreator --output_file ktouch.cpp.xml",
      "KTouchCppLessonsCreator -r 42",
      "KTouchCppLessonsCreator --rng_seed 42",
      "KTouchCppLessonsCreator -e",
      "KTouchCppLessonsCreator --silent",
    }
  );
}

std::string ribi::ktclc::menu_dialog::get_version() noexcept
{
  return "2.0";
}

std::vector<std::string> ribi::ktclc::menu_dialog::get_version_history() noexcept
{
  return {
    "2013-12-18: version 1.0: initial version",
    "2015-02-18: version 2.0: works with KTouch version 2.3.0, added menu dialog, use C++ Core Guideline coding standards",
    "2015-02-18: version 2.1: added menu"
  };
}

#ifndef NDEBUG
void ribi::ktclc::menu_dialog::test() noexcept
{
  {
    static bool is_tested{false};
    if (is_tested) return;
    is_tested = true;
  }
  {
    fileio::FileIo();
    helper();
    course(42);
  }
  const test_timer my_test_timer(__func__,__FILE__,1.0);
  const fileio::FileIo f;
  {
    menu_dialog d;
    const std::string tmp_filename{f.GetTempFileName(".xml")};
    d.Execute( { "KTouchCppLessonsCreator", "-o", tmp_filename, "--silent" } );
    assert(f.IsRegularFile(tmp_filename));
    f.DeleteFile(tmp_filename);
    assert(!f.IsRegularFile(tmp_filename));
  }
  {
    menu_dialog d;
    const std::string tmp_filename{f.GetTempFileName(".xml")};
    d.Execute( { "KTouchCppLessonsCreator", "-o", tmp_filename, "-r" , "42", "--silent" } );
    assert(f.IsRegularFile(tmp_filename));
    f.DeleteFile(tmp_filename);
    assert(!f.IsRegularFile(tmp_filename));
  }
}
#endif

