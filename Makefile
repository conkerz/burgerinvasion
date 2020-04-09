CXX = gcc
CXXFLAGS = -lm -ldl -Wall -Werror -Wextra -pedantic -std=c++1y
LDFLAGS = -lstdc++ -lsfml-graphics -lsfml-window -lsfml-system

SRC = main.cc game-info.cc my-sprite.cc matrix.cc sprite-db.cc hud.cc \
      moving-sprite.cc peons/enemy.cc wave.cc bullet.cc button.cc menu.cc


# TOWERS
SRC += towers/tower.cc towers/fastower.cc towers/stronkower.cc


SRCDIR = src/
OBJ = $(SRC:.cc=.o)
OBJ2 = $(addprefix $(SRCDIR), $(OBJ))
PROJECT = burgerinvasion

all: $(PROJECT)

$(PROJECT): $(OBJ2)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

debug: CXXFLAGS += -g3
debug: $(OBJ2)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o debug $^

clean:
	rm -f $(PROJECT)
	rm -f $(OBJ2)
	rm -f debug
