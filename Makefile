CXX = g++
CPPFLAGS = -Wall -g
BIN_DIR = exe


all: $(BIN_DIR)/.dirstamp $(BIN_DIR)/program

# create folder if it doesn't exist
$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp

# compile files, target: dependencies
$(BIN_DIR)/main.o: main.cpp
	$(CXX) $(CPPFLAGS) -c $^ -o $@

$(BIN_DIR)/individual.o: individual.cpp
	$(CXX) $(CPPFLAGS) -c $^ -o $@

$(BIN_DIR)/population.o: population.cpp
	$(CXX) $(CPPFLAGS) -c $^ -o $@

# link
$(BIN_DIR)/program: $(BIN_DIR)/main.o $(BIN_DIR)/individual.o $(BIN_DIR)/population.o 
	$(CXX) $(CPPFLAGS) $^ -o $@

.PHONY: clean
clean: 
	rm -rf $(BIN_DIR)