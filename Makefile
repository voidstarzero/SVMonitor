EXEC ?= ./svmon

CXX ?= g++
CXXFLAGS ?= -std=gnu++17 -O2 -Wall -Wextra
LIBS ?= -lsfml-window -lsfml-system

BUILD_DIR ?= ./build
SRC_DIR ?= ./src

srcs := $(wildcard $(SRC_DIR)/*.cpp)
objs := $(srcs:$(SRC_DIR)/%=$(BUILD_DIR)/%.o)
deps := $(objs:.o=.d)

cpp_flags := $(CPPFLAGS) -MMD -MP
cxx_flags := $(CXXFLAGS)
ld_flags :=  $(LDFLAGS) $(LIBS)

default: $(EXEC)

all: $(EXEC)

$(EXEC): $(objs)
	$(CXX) $(objs) -o $@ $(ld_flags)

$(BUILD_DIR)/%.cpp.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(cpp_flags) $(cxx_flags) -c $< -o $@

.PHONY: clean run

clean:
	rm -rf $(EXEC) $(BUILD_DIR)

run: $(EXEC)
	$(EXEC)

-include $(deps)
