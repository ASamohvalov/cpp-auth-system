#ifndef TOKEN_H
#define TOKEN_H

#include <string>

namespace dto
{
	struct TokenModel
	{
		long id;
		std::string token;
		long user_id;
	};

	struct TokenDto
	{
		std::string token;
		long user_id;
	};
}

#endif
