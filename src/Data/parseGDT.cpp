#include <stdint.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Data/data.h"
#include "Parser/endian.h"
#include "Parser/parser.h"

namespace Data
{
int
parseGDT (Roll *roll, const std::string &filepath)
{
  std::ifstream file (filepath, std::ios::in);
  std::stringstream buffer;
  if (!file.good ())
    {
      file.close ();
      return 1;
    }
  buffer << file.rdbuf ();
  file.close ();

  Parser::Parser parser (buffer.str ());

  if (parser.active ())
    {
      parser.ignoreTill ("gdt");
      parser.parseInt32 ();
      parser.parseInt32 ();
      parser.parseInt32 ();

      // CONTINUE
    }
  else
    {
      return 1;
    }
  return 0;
}
} // namespace Data
