/*
 *  _______     ________    ________    ________    __
 * |   __  \   |__    __|  |   _____|  |   _____|  |  |
 * |  |  |  |     |  |     |  |        |  |_____   |  |
 * |  |  |  |     |  |     |  |        |   _____|  |__|
 * |  |__|  |   __|  |__   |  |_____   |  |_____    __
 * |_______/   |________|  |________|  |________|  |__|
 *
 * Dice! QQ Dice Robot for TRPG
 * Copyright (C) 2018 w4123���
 *
 * This program is free software: you can redistribute it and/or modify it under the terms
 * of the GNU Affero General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this
 * program. If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
#ifndef __GETRULE__
#define __GETRULE__
#include <string>
#include <vector>
#include <aws/dynamodb/DynamoDBClient.h>
#include <aws/core/Aws.h>

class GetRule
{
	bool failed = false;
	Aws::SDKOptions options;
	std::unique_ptr<Aws::DynamoDB::DynamoDBClient> client{};
	const std::string ACCESS_KEY = "AKIAI5QK6ZFNW62URGFA";
	const std::string SECRET_ACCESS_KEY = "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";
	std::vector<std::string> rules{};
	const std::map<std::string, std::string> ruleNameReplace
	{
		std::make_pair("5E", "DND5E"),
		std::make_pair("3R", "DND3R"),
		std::make_pair("DND", "DND3R"),
		std::make_pair("D&D", "DND3R"),
		std::make_pair("COC", "COC7")
	};
public:
	GetRule();
	~GetRule();
	bool analyze(std::string& rawStr, std::string& des);
	bool get(const std::string& rule, const std::string& name, std::string& des, bool isUTF8 = false) const;
};
#endif /*__GETRULE__*/
