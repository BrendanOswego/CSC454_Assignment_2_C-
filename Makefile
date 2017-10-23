main = ./main.cpp
store = ./Store/Store.cpp
output = ./Output/Output.cpp
input = ./Input/Input.cpp
lambda = ./Lambda/Lambda.cpp
delta = ./Delta/Delta.cpp
utils = ./Utils/Utils.cpp
exception = ./ChangeException/ChangeException.cpp

LFLAGS = -g -std=c++11

make:
	g++ $(LFLAGS) $(utils) $(main) $(lambda) $(delta) $(input) $(output) $(store)
