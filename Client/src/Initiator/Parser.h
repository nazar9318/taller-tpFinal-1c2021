#ifndef _PARSER_H
#define _PARSER_H

#include <string>
#include "TypeOfLine.h"

#define SIZE_CREATE 5
#define CREATE "crear"
#define LIST "listar"
#define SIZE_JOIN 6
#define JOIN "unirse"
#define NAME_POS_CREATE 6
#define NAME_POS_JOIN 7

class Parser {

	public:
		Parser();

    TypeOfLine type_of_line(const std::string& line) const;

		~Parser();

	private:
		Parser(const Parser &other) = delete;
		Parser& operator=(const Parser &other) = delete;
};


#endif
