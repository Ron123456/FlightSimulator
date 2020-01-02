cmake_minimum_required(VERSION 3.15)
project(mitkadem3)

set(CMAKE_CXX_STANDARD 14)

add_executable(mitkadem3 Command.h Compiler.cpp Compiler.h ConditionParser.cpp ConditionParser.h ConnectCommand.cpp ConnectCommand.h IfCommand.cpp IfCommand.h mitkadem3.cpp openServerCommand.cpp openServerCommand.h SymbolTable.cpp SymbolTable.h Var.h)