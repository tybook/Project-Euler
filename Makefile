CFLAGS = -Wall -lpthread -std=gnu++11 -O3

C++ = $(sort $(wildcard prob*.cpp))
OCaml = $(sort $(wildcard prob*.ml))

all: $(patsubst %.cpp,%-C++,$(C++)) $(patsubst %.ml,%-OCaml,$(OCaml))

prob%-C++:
	g++ $(CFLAGS) -o $@ $(patsubst %-C++,%.cpp,$@)

prob%-OCaml:
	ocamlc -o $@ $(patsubst %-OCaml,%.ml,$@)

clean:
	rm -f *-C++ *-OCaml *.cmi *.cmo *.o

.PHONY: all clean
