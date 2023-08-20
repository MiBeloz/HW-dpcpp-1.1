#include <iostream>

#include "SqlSelectQueryBuilder.hpp"


int main() {
#if _WIN32
    setlocale(LC_ALL, "ru_RU.UTF-8");
#endif
    std::cout << "\tРеализация SqlSelectQueryBuilder\n" << std::endl;

    SqlSelectQueryBuilder query_builder;

	std::cout << "Вызов методов:\n"
		"\t~.AddColumn(\"name\").AddColumn(\"phone\");\n"
		"\t~.AddFrom(\"students\");\n"
		"\t~.AddWhere(\"id\", \"42\").AddWhere(\"name\", \"John\");\n"
		<< std::endl;
	query_builder.AddColumn("name").AddColumn("phone");
	query_builder.AddFrom("students");
	query_builder.AddWhere("id", "42").AddWhere("name", "John");
	std::cout << "\tBuild запрос:" << std::endl;
	std::cout << "\t" << query_builder.BuildQuery() << std::endl << std::endl << std::endl;

	std::cout << "Вызов методов:\n"
		"\t~.AddColumn(\"name\").AddColumn(\"phone\");\n"
		"\t~.AddFrom(\"people\");\n"
		"\t~.AddFrom(\"students\");\n"
		"\t~.AddWhere(\"id\", \"42\").AddWhere(\"name\", \"John\");\n"
		<< std::endl;
	query_builder.AddColumn("name").AddColumn("phone");
	query_builder.AddFrom("people");
	query_builder.AddFrom("students");
	query_builder.AddWhere("id", "42").AddWhere("name", "John");
	std::cout << "\tBuild запрос:" << std::endl;
	std::cout << "\t" << query_builder.BuildQuery() << std::endl << std::endl << std::endl;

	std::cout << "Вызов методов:\n"
		"\t~.AddWhere(\"id\", \"42\").AddWhere(\"name\", \"John\");\n"
		"\t~.AddFrom(\"students\");\n"
		"\t~.AddColumn(\"name\").AddColumn(\"phone\");\n"
		<< std::endl;
	query_builder.AddWhere("id", "42").AddWhere("name", "John");
	query_builder.AddFrom("students");
	query_builder.AddColumn("name").AddColumn("phone");
	std::cout << "\tBuild запрос:" << std::endl;
	std::cout << "\t" << query_builder.BuildQuery() << std::endl << std::endl << std::endl;

	std::cout << "Вызов методов:\n"
		"\t~.AddFrom(\"students\");\n"
		"\t~.AddWhere(\"id\", \"42\").AddWhere(\"name\", \"John\");\n"
		<< std::endl;
	query_builder.AddFrom("students");
	query_builder.AddWhere("id", "42").AddWhere("name", "John");
	std::cout << "\tBuild запрос:" << std::endl;
	std::cout << "\t" << query_builder.BuildQuery() << std::endl << std::endl << std::endl;

	std::cout << "Вызов методов:\n"
		"\t~.AddFrom(\"students\");\n"
		"\t~.AddColumn(\"name\").AddColumn(\"phone\");\n"
		<< std::endl;
	query_builder.AddFrom("students");
	query_builder.AddColumn("name").AddColumn("phone");
	std::cout << "\tBuild запрос:" << std::endl;
	std::cout << "\t" << query_builder.BuildQuery() << std::endl;

    std::cin.get();
    return 0;
}