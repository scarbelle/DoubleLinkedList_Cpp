CXX=g++
CPPFLAGS = -g
LDFLAGS = -g

# C++ pointers
SRCS = dNode.cpp dLList.cpp main.cpp
OBJS = $(subst .cpp,.o,$(SRCS))
TARGET = runlist
TEST = test_runlist

# C++ shared pointers
SRCS_SHDP = dNode_shdp.cpp dLList_shdp.cpp main_shdp.cpp
OBJS_SHDP = $(subst .cpp,.o,$(SRCS_SHDP))
TARGET_SHDP = runlist_shdp
TEST_SHDP = test_runlist_shdp

OBJECTS = $(OBJS) $(OBJS_SHDP)
TARGETS = $(TARGET) $(TARGET_SHDP)
TESTS = $(TEST) $(TEST_SHDP)

all: $(TARGETS)

runlist: $(OBJS)
	$(CXX) $(CPPFLAGS) -o runlist $(OBJS)

runlist_shdp: $(OBJS_SHDP)
	$(CXX) $(CPPFLAGS) -o runlist $(OBJS_SHDP)

test_runlist:
	/usr/bin/valgrind --leak-check=full ./runlist

test_runlist_shdp:
	/usr/bin/valgrind --leak-check=full ./runlist_shdp 

clean:
	rm -f $(OBJECTS)

%.o:%c
	$(CXX) $(CPPFLAGS) -c $<



