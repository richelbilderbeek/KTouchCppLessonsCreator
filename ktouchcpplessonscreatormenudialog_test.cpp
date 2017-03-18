#include "ktouchcpplessonscreatormenudialog.h"

#include <fstream>
#include <iostream>
#include <iterator>

#include "fileio.h"

#include "ktouchcpplessonscreatorwordlist.h"
#include "ktouchcpplessonscreatorhelper.h"
#include "ktouchcpplessonscreatorcourse.h"

void ribi_ktclc_menu_dialog_test() noexcept
{
  menu_dialog d;
  const std::string tmp_filename{f.GetTempFileName(".xml")};
  d.Execute( { "KTouchCppLessonsCreator", "-o", tmp_filename, "-r" , "42", "--silent" } );
  assert(f.IsRegularFile(tmp_filename));
  f.DeleteFile(tmp_filename);
  assert(!f.IsRegularFile(tmp_filename));
}

