CC = g++
OBJS = urbanTrainOptimization.o station.o train.o passenger.o daq.o optimization.o simTime.o
OBJS_1 = urbanTrainOptimization.o station.o metro.o parser.o
DEPS = train.hh
CXXFLAGS = station.hh metro.hh parser.hh
#CXXFLAGS = -msse4 -lm -O2
#OPTS = -Wno-write-strings -std=gnu++11 -fno-exceptions

compile: urbanTrainOptimization.o station.o train.o passenger.o daq.o optimization.o simTime.o
	$(CC) -o UrbanTrainOptimization $(OBJS) $(CXXFLAGS)

StationTest: $(OBJS_1)
	$(CC) -o $@ $(OBJS_1)


urbanTrainOptimization.o: main.cc 
	$(CC) -c -o $@ $< 
#	$(CC) -c $< $(CXXFLAGS)

station.o: station.cc
	$(CC) -c $<

parser.o: parser.cc
	$(CC) -c $<

metro.o: metro.cc
	$(CC) -c $<

train.o: train.cc
	$(CC) -c $< $(CXXFLAGS)

passenger.o: passenger.cc
	$(CC) -c $< $(CXXFLAGS)

simTime.o: simTime.cc
	$(CC) -c $< $(CXXFLAGS)

daq.o: daq.cc
	$(CC) -c $< $(CXXFLAGS)

optimization.o: optimization.cc
	$(CC) -c $< $(CXXFLAGS)

edit: superclean
	- \emacs  *.cc Makefile &

# edit: superclean
# 	- \emacs  urbanTrainOptimization.* station.* train.* passenger.* daq.* optimization.* simTi
#me* Makefile &

run: compile
	./UrbanTrainOptimization

.PHONY: clean

clean:
	- \rm -f UrbanTrainOptimization
	- \rm -f *.o
	- \rm -f core

superclean: clean
	- \rm -f *~
	- \rm -f *\#
