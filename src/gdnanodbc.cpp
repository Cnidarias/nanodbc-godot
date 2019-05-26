#include "gdnanodbc.h"

using namespace godot;

void GDNanodbc::_register_methods()
{
    register_method("connect", &GDNanodbc::connect);
    register_method("execute", &GDNanodbc::execute);
    register_method("fetch", &GDNanodbc::fetch);
}

GDNanodbc::GDNanodbc() {}

GDNanodbc::~GDNanodbc() {}

void GDNanodbc::_init() {}


bool GDNanodbc::connect(String connection_string)
{
    try
    {
        connection = nanodbc::connection(connection_string.utf8().get_data());
    }
    catch (std::runtime_error &error)
    {
        Godot::print_error("Failed Connection: `" + connection_string + "` " + error.what(), __func__, __FILE__, __LINE__);
        return false;
    }
    return true;
}

bool GDNanodbc::execute(String query)
{
    try
    {
        nanodbc::execute(connection, query.utf8().get_data());
    }
    catch (std::runtime_error &error)
    {
        Godot::print_error("Failed Query: `" + query + "` " + error.what(), __func__, __FILE__, __LINE__);
        return false;
    }
    return true;
}

Array GDNanodbc::fetch(String query)
{
    Array result;
    try
    {
        nanodbc::result db_results;
        db_results = nanodbc::execute(connection, query.utf8().get_data());
        
        const short columns = db_results.columns();
        Array columnNames;
        for (short i = 0; i < columns; i++)
        {
            columnNames.append(db_results.column_name(i).c_str());
        }
        result.append(columnNames);

        while (db_results.next())
        {
            Array row;
            for (short col = 0; col < columns; col++)
            {
                row.append(db_results.get<std::string>(col, "NULL").c_str());
            }
            result.append(row);
        }
    }
    catch (std::runtime_error &error)
    {
        Godot::print_error("Failed Query: " + query + " " + error.what(), __func__, __FILE__, __LINE__);
    }
    return result;
}
