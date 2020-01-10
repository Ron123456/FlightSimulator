cmake_minimum_required(VERSION 3.15)
project(FlightSimulator)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

#FILE (GLOB MYFILES RELATIVE

add_executable(FlightSimulator Expressions/BinaryOperator.cpp Expressions/Equal.cpp Expressions/Expression.h Expressions/LeftGreaterEqual.cpp Expressions/Minus.h Expressions/NotEqual.h Expressions/RightGreaterEqual.cpp Expressions/UMinus.h Expressions/UPlus.h Expressions/Variable.h Expressions/BinaryOperator.h Expressions/Equal.h Expressions/Interpreter.cpp Expressions/LeftGreaterEqual.h Expressions/Mul.cpp Expressions/Plus.cpp Expressions/RightGreaterEqual.h Expressions/UnaryOperator.cpp Expressions/Value.cpp Expressions/Div.cpp Expressions/ex1.cpp Expressions/Interpreter.h Expressions/LeftGreater.h Expressions/Mul.h Expressions/Plus.h Expressions/RightGreater.h Expressions/UnaryOperator.h Expressions/Value.h Expressions/Div.h Expressions/ex1.h Expressions/LeftGreater.cpp Expressions/Minus.cpp Expressions/NotEqual.cpp Expressions/RightGreater.cpp Expressions/UMinus.cpp Expressions/UPlus.cpp Expressions/Variable.cpp Command.h Compiler.cpp Compiler.h ConditionParser.cpp ConditionParser.h ConnectCommand.cpp ConnectCommand.h IfCommand.cpp IfCommand.h mitkadem3.cpp openServerCommand.cpp openServerCommand.h SymbolTable.cpp SymbolTable.h Var.h Parser.cpp Parser.h DefineVarCommand.cpp DefineVarCommand.h ChangeVarCommand.cpp ChangeVarCommand.h PrintCommand.cpp PrintCommand.h SleepCommand.cpp SleepCommand.h FunctionCommand.cpp FunctionCommand.h Connection.cpp Connection.h)