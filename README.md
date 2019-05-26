# Nanodbc Godot

This repository provides [https://github.com/nanodbc/nanodbc](nanodbc) wrapper for [https://github.com/godotengine/godot](Godot)

It is still very much WIP and only has basic support for connecting to a DB, executing some SQL and retrieving some rows

## Compiling

The project uses scons to build so just run 

```
scons -j12 platform=linux
```

This project has not yet been compiled on windows/osx (it should be fairly easy to do so but the odbc linking will have to be adjusted)



