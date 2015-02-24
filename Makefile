# @file Makefile
# @author Tomas Sykora, jr. tomas.sykora@fit.cvut.cz
#-------------------------------------------------------#
CXXFLAGS=-Wall -pedantic -Wno-long-long -O0 -ggdb
CLIBS=-lcurses
CXX=g++
RM=rm -rf
OBJECTS=bin/objects/main.o bin/objects/DNCell.o bin/objects/DNDumbBotPlayer.o bin/objects/DNGame.o bin/objects/DNHumanPlayer.o bin/objects/DNLogService.o bin/objects/DNMap.o bin/objects/DNNetworkConnection.o bin/objects/DNPlayer.o bin/objects/DNRemoteHumanPlayer.o bin/objects/DNSmarterBotPlayer.o bin/objects/DNWindow.o
DOXY=Doxyfile
BIN=./TicTacToe

#generates final binary and documentation
all: $(OBJECTS)
	make compile
	make doc

#build all objects and merge them into final binary
compile: $(BIN)

doc:
	doxygen $(DOXY) #>/dev/null 2>/dev/null # uncomment to hide doxygen output
	
#run program
run: $(BIN)
	$(BIN)

#delete all folders with binary files (including documentation)
clean:
	$(RM) bin $(BIN) doc log.txt

#rules to make objects ----------------------------------------------------------------------------------
$(BIN): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(BIN) $(CLIBS)




bin/objects/main.o: src/main.cpp src/DNWindow.h src/DNCellState.h
	mkdir -p bin/objects
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o bin/objects/main.o $(CLIBS)

bin/objects/DNCell.o: src/DNCell.cpp src/DNCell.h src/DNCellState.h
	mkdir -p bin/objects
	$(CXX) $(CXXFLAGS) -c src/DNCell.cpp -o bin/objects/DNCell.o $(CLIBS)

#bin/objects/DNCellState.o: src/DNCellState.h
#	mkdir -p bin/objects
#	$(CXX) $(CXXFLAGS) -c src/DNCellState.h -o bin/objects/DNCellState.o $(CLIBS)
#
bin/objects/DNDumbBotPlayer.o: src/DNDumbBotPlayer.cpp src/DNDumbBotPlayer.h src/DNPlayer.h src/DNCellState.h src/DNMap.h src/DNCell.h src/DNWindow.h src/DNLogService.h
	mkdir -p bin/objects
	$(CXX) $(CXXFLAGS) -c src/DNDumbBotPlayer.cpp -o bin/objects/DNDumbBotPlayer.o $(CLIBS)

bin/objects/DNGame.o: src/DNGame.cpp src/DNGame.h src/DNPlayer.h src/DNCellState.h src/DNMap.h src/DNCell.h src/DNSmarterBotPlayer.h src/DNWindow.h src/DNLogService.h src/DNHumanPlayer.h src/DNDumbBotPlayer.h src/DNRemoteHumanPlayer.h src/DNNetworkConnection.h
	mkdir -p bin/objects
	$(CXX) $(CXXFLAGS) -c src/DNGame.cpp -o bin/objects/DNGame.o $(CLIBS)

bin/objects/DNHumanPlayer.o: src/DNHumanPlayer.cpp src/DNHumanPlayer.h src/DNPlayer.h src/DNCellState.h src/DNMap.h src/DNCell.h src/DNWindow.h
	mkdir -p bin/objects
	$(CXX) $(CXXFLAGS) -c src/DNHumanPlayer.cpp -o bin/objects/DNHumanPlayer.o $(CLIBS)

bin/objects/DNLogService.o: src/DNLogService.cpp src/DNLogService.h
	mkdir -p bin/objects
	$(CXX) $(CXXFLAGS) -c src/DNLogService.cpp -o bin/objects/DNLogService.o $(CLIBS)

bin/objects/DNMap.o: src/DNMap.cpp src/DNMap.h src/DNCell.h src/DNCellState.h src/DNPlayer.h src/DNLogService.h
	mkdir -p bin/objects
	$(CXX) $(CXXFLAGS) -c src/DNMap.cpp -o bin/objects/DNMap.o $(CLIBS)

bin/objects/DNNetworkConnection.o: src/DNNetworkConnection.cpp src/DNNetworkConnection.h src/DNLogService.h src/DNWindow.h src/DNCellState.h
	mkdir -p bin/objects
	$(CXX) $(CXXFLAGS) -c src/DNNetworkConnection.cpp -o bin/objects/DNNetworkConnection.o $(CLIBS)

bin/objects/DNPlayer.o: src/DNPlayer.cpp src/DNPlayer.h src/DNCellState.h src/DNMap.h src/DNCell.h
	mkdir -p bin/objects
	$(CXX) $(CXXFLAGS) -c src/DNPlayer.cpp -o bin/objects/DNPlayer.o $(CLIBS)

bin/objects/DNRemoteHumanPlayer.o: src/DNRemoteHumanPlayer.cpp src/DNRemoteHumanPlayer.h src/DNHumanPlayer.h src/DNPlayer.h src/DNCellState.h src/DNMap.h src/DNCell.h src/DNLogService.h src/DNNetworkConnection.h src/DNWindow.h
	mkdir -p bin/objects
	$(CXX) $(CXXFLAGS) -c src/DNRemoteHumanPlayer.cpp -o bin/objects/DNRemoteHumanPlayer.o $(CLIBS)

bin/objects/DNSmarterBotPlayer.o: src/DNSmarterBotPlayer.cpp src/DNSmarterBotPlayer.h src/DNPlayer.h src/DNCellState.h src/DNMap.h src/DNCell.h src/DNWindow.h
	mkdir -p bin/objects
	$(CXX) $(CXXFLAGS) -c src/DNSmarterBotPlayer.cpp -o bin/objects/DNSmarterBotPlayer.o $(CLIBS)

bin/objects/DNWindow.o: src/DNWindow.cpp src/DNWindow.h src/DNCellState.h src/DNGame.h src/DNPlayer.h src/DNMap.h src/DNCell.h src/DNSmarterBotPlayer.h src/DNLogService.h
	mkdir -p bin/objects
	$(CXX) $(CXXFLAGS) -c src/DNWindow.cpp -o bin/objects/DNWindow.o $(CLIBS)