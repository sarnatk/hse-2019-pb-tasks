CXX = g++
CXXFLAGS = -O2 -Wall -Werror -std=c++11 -Iinclude
LDFLAGS =

EXE = hw_02
SRCDIR = src
OBJDIR = obj

TEST_EXE = test_hw_02
TESTDIR = test

OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(wildcard $(SRCDIR)/*.cpp))
TEST_OBJECTS = $(patsubst $(TESTDIR)/%.cpp,$(OBJDIR)/test/%.o,$(wildcard $(TESTDIR)/*.cpp))

all: $(EXE) $(TEST_EXE)

$(EXE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXE) $(LDFLAGS)

$(TEST_EXE): $(TEST_OBJECTS)
	$(CXX) $(TEST_OBJECTS) $(filter-out $(OBJDIR)/main.o,$(OBJECTS)) -o $(TEST_EXE) $(LDFLAGS)
	
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -MMD -o $@ $<

$(OBJDIR)/test/%.o: $(TESTDIR)/%.cpp | $(OBJDIR)/test
	$(CXX) $(CXXFLAGS) -c -MMD -o $@ $<

include $(wildcard $(OBJDIR)/*.d) 

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/test:
	mkdir -p $(OBJDIR)/test

clean:
	rm -rf $(OBJDIR) $(EXE) $(TEST_EXE)

.PHONY: clean all
