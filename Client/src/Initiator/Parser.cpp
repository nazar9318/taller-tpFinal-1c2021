#include "Parser.h"

Parser::Parser(){}

TypeOfLine Parser::type_of_line(const std::string& line) const {
  if ((line.length() > SIZE_CREATE + 2) && (line.substr(0, SIZE_CREATE) == CREATE))
    return TypeOfLine::Create;

  if (line == LIST)
    return TypeOfLine::List;

  if ((line.length() > SIZE_JOIN + 2) && (line.substr(0, SIZE_JOIN) == JOIN))
    return TypeOfLine::Join;
    
  return TypeOfLine::Undefined;
}

Parser::~Parser(){}
