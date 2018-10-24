CC=/usr/bin/gcc
UNITY=/Users/seanlee/TARS/Unity
INCLUDES=-I$(UNITY)/src -I/Users/seanlee/TARS/c/fw_test
CFLAGS=-Wall -Wstack-usage -g $(INCLUDES) 
VPATH=$(UNITY)/src:./test

all: deck testSuite

deck: main.o linkedlist.o
	$(CC) $(CFLAGS) -o $@ $^	
testSuite: TestLinkedList.o linkedlist.o unity.o
	$(CC) $(CFLAGS) -o $@ $^	
%.o: %.c 
	$(CC) $(CFLAGS) -o $@ -c $<
print-%:
	@echo $* = $($*)
clean:
	rm *.o
	rm testSuite
	rm deck
