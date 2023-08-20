#pragma once

#include <string>
#include <vector>
#include <map>


class SqlSelectQueryBuilder final {
public:
    SqlSelectQueryBuilder() = default;
    ~SqlSelectQueryBuilder() {};

    SqlSelectQueryBuilder(const SqlSelectQueryBuilder& other) = delete;
    SqlSelectQueryBuilder(SqlSelectQueryBuilder&& other) noexcept = delete;
    SqlSelectQueryBuilder& operator=(const SqlSelectQueryBuilder& other) = delete;
    SqlSelectQueryBuilder& operator=(SqlSelectQueryBuilder&& other) noexcept = delete;

    SqlSelectQueryBuilder& AddColumn(const std::string& column) noexcept;
    SqlSelectQueryBuilder& AddFrom(const std::string& table) noexcept;
    SqlSelectQueryBuilder& AddWhere(const std::string& key, const std::string& value) noexcept;

    std::string BuildQuery() noexcept;

private:
    std::string m_table;
    std::vector<std::string> m_column;
    std::map<std::string, std::string> m_where;
};
