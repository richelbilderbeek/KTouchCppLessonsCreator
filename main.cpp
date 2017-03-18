#include "ktouchcpplessonscreatormenudialog.h"

int main(int argc, char* argv[])
{
  const auto args = ribi::ktclc::menu_dialog::convert_arguments(argc,argv);
  return ribi::ktclc::menu_dialog().execute(args);
}
