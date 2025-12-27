# --- Toolchain and flags ---
CXX      := g++
CXXFLAGS := -std=cpp20 -O2 -Wall -Wextra -Iinclude
LDFLAGS  :=
LDLIBS   :=

# --- Paths and names ---
SRC_DIR  := src
OBJ_DIR  := build
BIN_DIR  := bin
TARGET   := $(BIN_DIR)/myapp

# --- Sources and derived lists ---
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# --- Default rule ---
.PHONY: all
all: $(TARGET)

# --- Link step ---
$(TARGET): $(OBJS) | $(BIN_DIR)
    $(CXX) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@

# --- Compile step (pattern rule) ---
# $< = first prerequisite, $@ = target
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
    $(CXX) $(CXXFLAGS) -c $< -o $@
j
# --- Auto-create output directories ---
$(OBJ_DIR) $(BIN_DIR):
    mkdir -p $@

# --- Clean ---
.PHONY: clean
clean:
    rm -rf $(OBJ_DIR) $(BIN_DIR)

# --- Convenience targets ---
.PHONY: run
run: all
        $(TARGET)

.PHONY: debug
debug:
