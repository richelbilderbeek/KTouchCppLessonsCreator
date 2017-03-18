#include "ktouchcpplessonscreatorhelper.h"

#include <numeric>
#include <set>
#include <sstream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

void ribi_ktclc_helper_test() noexcept
{
  //does_fit
  {
    assert( h.does_fit("a","a"));
    assert(!h.does_fit("b","a"));
    assert( h.does_fit("a","ab"));
    assert( h.does_fit("b","ab"));
    assert( h.does_fit("a","ba"));
    assert( h.does_fit("b","ba"));
  }
  //has_forbidden
  {
    assert(!h.has_forbidden("static_cast"));
    assert(!h.has_forbidden("1 / 2"));
    assert( h.has_forbidden("1 < 2"));
    assert( h.has_forbidden("1 > 2"));
    assert( h.has_forbidden("1 & 2"));
    assert( h.has_forbidden("1 \" 2"));
    assert( h.has_forbidden("1 \' 2"));
  }
  //convert_to_escape
  {
    assert(h.convert_to_escape('a') == "a");
    assert(h.convert_to_escape('A') == "A");
    assert(h.convert_to_escape('!') == "!");
    //assert(h.convert_to_escape('<') == "&lt;");
    assert(h.convert_to_escape('<') == "\\<");
    assert(h.convert_to_escape('>') == "&gt;");
    assert(h.convert_to_escape('&') == "&amp;");
    assert(h.convert_to_escape('\'') == "&apos;");
    assert(h.convert_to_escape('\"') == "&quot;");
  }
  //convert_to_escape
  {
    assert(h.convert_to_escape("a") == "a");
    assert(h.convert_to_escape("A") == "A");
    assert(h.convert_to_escape("!") == "!");
    assert(h.convert_to_escape("<") == "\\<");
    //assert(h.convert_to_escape("<") == "&lt;");
    assert(h.convert_to_escape(">") == "&gt;");
    assert(h.convert_to_escape("&") == "&amp;");
    assert(h.convert_to_escape("\'") == "&apos;");
    assert(h.convert_to_escape("\"") == "&quot;");
  }
  //is_desired
  {
    assert( h.is_desired('a' ,"a"));
    assert( h.is_desired('a' ,"ab"));
    assert(!h.is_desired('a' ,"bc"));
  }
  //calculate_score
  {
    //calculate_score(s,desired)
    assert(h.calculate_score("a","a") == 1);
    assert(h.calculate_score("a","b") == 0);
    assert(h.calculate_score("aa","a") == 2);
    assert(h.calculate_score("aa","b") == 0);
    assert(h.calculate_score("ab","ab") == 2);
    assert(h.calculate_score("ab","abcd") == 2);
    assert(h.calculate_score("abcd","cd") == 2);
    assert(h.calculate_score("" ,"") == 0);
    assert(h.calculate_score("a" ,"") == 0);
    assert(h.calculate_score("" ,"a") == 0);
  }
  //enumerate
  {
    assert(h.enumerate("A") == "A");
    assert(h.enumerate("AB") == "A and B");
    assert(h.enumerate("ABC") == "A, B and C");
    assert(h.enumerate("ABCD") == "A, B, C and D");
    assert(h.enumerate("ABCDE") == "A, B, C, D and E");
  }
  //concatenate
  {
    assert(h.concatenate( {"A","B"}, " ") == "A B");
    assert(h.concatenate( {"A","B","C"}, " ") == "A B C");
    assert(h.concatenate( {"A","B","C"}, "_") == "A_B_C");
    assert(h.concatenate( {"A","B","C"}, "--") == "A--B--C");
    assert(h.concatenate( {"A"}, " ") == "A");
    assert(h.concatenate( {"A"}, "--") == "A");
  }
  //cap_at_sum_length
  {
    const std::vector<std::string> v = {"abc","def","ghi"};
    const std::vector<std::string> w = {"abc","def"};
    const std::vector<std::string> x = {"abc"};
    const std::vector<std::string> y = {};
    assert(h.cap_at_sum_length(v,0) == y);
    assert(h.cap_at_sum_length(v,1) == y);
    assert(h.cap_at_sum_length(v,2) == y);
    assert(h.cap_at_sum_length(v,3) == x);
    assert(h.cap_at_sum_length(v,4) == x);
    assert(h.cap_at_sum_length(v,5) == x);
    assert(h.cap_at_sum_length(v,6) == w);
    assert(h.cap_at_sum_length(v,7) == w);
    assert(h.cap_at_sum_length(v,8) == w);
    assert(h.cap_at_sum_length(v,9) == v);
  }
  //get_sum_length
  {
    const std::vector<std::string> v = {"abc","def","ghi"};
    const std::vector<std::string> w = {"abc","def"};
    const std::vector<std::string> x = {"abc"};
    const std::vector<std::string> y = {};
    assert(h.get_sum_length(v) == 9);
    assert(h.get_sum_length(w) == 6);
    assert(h.get_sum_length(x) == 3);
    assert(h.get_sum_length(y) == 0);
  }
}
