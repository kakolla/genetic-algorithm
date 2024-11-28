CXX = g++
CPPFLAGS = -Wall -g
BIN_DIR = exe


all: $(BIN_DIR)/.dirstamp $(BIN_DIR)/program

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp

$(BIN_DIR)/main.o: main.cpp
	$(CXX) $(CPPFLAGS) -c $^ -o $@

$(BIN_DIR)/program: $(BIN_DIR)/main.o
	$(CXX) $(CPPFLAGS) $^ -o $@

.PHONY: clean
clean: 
	rm -rf $(BIN_DIR)