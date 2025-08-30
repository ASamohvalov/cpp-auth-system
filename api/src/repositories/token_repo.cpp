#include "token_repo.h"
#include "db/db_connection.h"

#include <string>

namespace repositories::token
{
	void save(const dto::TokenDto& token)
	{
		db::Connection connection;
		const std::string sql = "INSERT INTO tokens (token, user_id)"
														"VALUES (?, ?)";
		connection.execute(sql, { token.token, std::to_string(token.user_id) } );
	}

	void update_token(const dto::TokenModel& token)
	{
		db::Connection connection;
		const std::string sql = "UPDATE tokens SET token = ? WHERE id = ?";
		connection.execute(sql, { token.token, std::to_string(token.id) } );
	}

	std::optional<dto::TokenModel> get_by_token(const std::string& token)
	{
		db::Connection connection;
		const std::string sql = "SELECT * FROM tokens WHERE token = ?";
		auto result = connection.get_single_map(sql, { token } );

		if (result.empty())
			return std::nullopt;

		dto::TokenModel model = { 
			std::stol(result["id"]),
			std::move(result["token"]),
			std::stol(result["user_id"])
		};
		return model;
	}
}
