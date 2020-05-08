PEDERROR = -pedantic-errors -std=c++11

richMan_bankrupt.o: richMan_bankrupt.cpp richMan_bankrupt.h richMan_struct.h
	g++ $(PEDERROR) -c $<

richMan_rule.o: richMan_rule.cpp richMan_rule.h
	g++ $(PEDERROR) -c $<

temp.o: temp.cpp temp.h richMan_struct.h
	g++ $(PEDERROR) -c $<

richMan_display.o: richMan_display.cpp richMan_display.h richMan_struct.h
	g++ $(PEDERROR) -c $<

richMan_mapEffect.o: richMan_mapEffect.cpp richMan_mapEffect.h richMan_display.h richMan_randomevent.h
	g++ $(PEDERROR) -c $<


richMan_randomevent.o: richMan_randomevent.cpp richMan_randomevent.h richMan_load.h richMan_struct.h
	g++ $(PEDERROR) -c $<

richMan_struct.o: richMan_struct.cpp richMan_struct.h
	g++ $(PEDERROR) -c $<

richMan_save.o: richMan_save.cpp richMan_save.h richMan_struct.h
	g++ $(PEDERROR) -c $<

richMan_load.o: richMan_load.cpp richMan_load.h richMan_struct.h
	g++ $(PEDERROR) -c $<

richMan_main.o: richMan_main.cpp richMan_randomevent.h richMan_mapEffect.h richMan_display.h richMan_save.h richMan_load.h richMan_struct.h richMan_bankrupt.h richMan_rule.h
	g++ $(PEDERROR) -c $<

richMan: richMan_main.o richMan_display.o richMan_mapEffect.o richMan_struct.o richMan_save.o richMan_load.o richMan_bankrupt.o richMan_randomevent.o temp.o richMan_rule.o
	g++ $(PEDERROR) $^ -o $@

clean:
	rm -f richMan richMan_main.o richMan_display.o richMan_mapEffect.o richMan_struct.o richMan_save.o richMan_load.o richMan_bankrupt.o richMan_randomevent.o temp.o richMan_rule.o richMan.tgz

tar:
	tar -czvf richMan.tgz *.cpp *.h

.PHONY: clean tar
