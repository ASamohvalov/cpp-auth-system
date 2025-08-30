#ifndef TOKEN_REPO_H
#define TOKEN_REPO_H

#include "dto/token_dto.h"

#include <string>
#include <optional>

namespace repositories::token
{
	void save(const dto::TokenDto& token);
	void update_token(const dto::TokenModel& token);
	std::optional<dto::TokenModel> get_by_token(const std::string& token);
}

#endif
