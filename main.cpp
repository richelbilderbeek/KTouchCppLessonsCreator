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
#include "ktouchcpplessonscreatorcourse.h"

#include <fstream>
#include <iterator>

#include "trace.h"

#include <cstdlib>
#include <ctime>

//Version:
//YYYY-MM-DD: Vx.y: [description]
//2013-02-18: V1.0: initial version
//2015-10-31: V2.0: initial version

int main()
{
  //Guidelines:
  // - a lesson must have about 1000 chars
  // - level = number_of_chars / 2
  // - word length = 2 + (level / 3)
  // - every level must have about two new characters
  // - I do not care if words exist
  // - if a C++ construct exists, add it
  // - use all keys in the final level
  START_TRACE();
  const int rng_seed = 42;
  const auto v = ribi::ktclc::course(rng_seed).to_xml();
  std::ofstream f("cpp.ktouch.xml");
  std::copy(
    std::begin(v),
    std::end(v),
    std::ostream_iterator<std::string>(f,"\n")
  );
  // Under Lubuntu, lessons are here:
  ///usr/share/kde4/apps/ktouch/courses
}
