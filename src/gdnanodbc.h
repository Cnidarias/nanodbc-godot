#ifndef GDNANODBC_H
#define GDNANODBC_H

#include <Godot.hpp>
#include <Reference.hpp>

#include "nanodbc.h"

namespace godot
{

class GDNanodbc : public Reference
{
    GODOT_CLASS(GDNanodbc, Reference)

private:
    nanodbc::connection connection;

public:
    static void _register_methods();

    GDNanodbc();
    ~GDNanodbc();

    void _init(); // our initializer called by Godot

    bool connect(String connection_string);
    bool close();
    Variant what();
    
    bool execute(String query);
    Array fetch(String query);
};

} // namespace godot

#endif
