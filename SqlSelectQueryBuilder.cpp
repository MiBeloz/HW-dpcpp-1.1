#include "SqlSelectQueryBuilder.hpp"


SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::string& column) noexcept {
    auto m_it = std::find(m_column.begin(), m_column.end(), column);
    if (m_it != m_column.end()) return *this;

    m_column.push_back(column);
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(const std::string& table) noexcept {
    m_table = table;
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::string& key, const std::string& value) noexcept {
    m_where[key] = value;
    return *this;
}

std::string SqlSelectQueryBuilder::BuildQuery() noexcept {
    if (m_table.empty()) {
        m_column.clear();
        m_where.clear();
        return "";
    }

    std::string query = "\"SELECT ";

    if (m_column.empty()) {
        query += "* ";
    }
    else {
        for (size_t i = 0; i < m_column.size(); ++i) {
            query += m_column[i];
            if (i == m_column.size() - 1) {
                query += ' ';
            }
            else {
                query += ", ";
            }
        }
    }

    query += "FROM " + m_table;

    if (m_where.empty()) {
        query += ";\"";
    }
    else {
        query += " WHERE ";
        size_t i = 0;
        for (const auto& it : m_where) {
            i++;
            query += it.first + '=' + it.second;
            if (i == m_where.size()) {
                query += ";\"";
            }
            else {
                query += " AND ";
            }
        }
    }

    m_table.clear();
    m_column.clear();
    m_where.clear();
    return query;
}
