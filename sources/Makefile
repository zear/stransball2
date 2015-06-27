ifeq ($(PLATFORM), gcw0)
CXX	:= /opt/gcw0-toolchain/usr/bin/mipsel-linux-g++
STRIP	:= /opt/gcw0-toolchain/usr/bin/mipsel-linux-strip
endif

CXX	?= g++
STRIP	?= strip
SYSROOT	:= $(shell $(CXX) --print-sysroot)
TARGET	:= stransball2
OBJS	:= \
	auxiliar.o           configuration.o     encoder.o \
	enemies.o            fonts.o       	 game.o \
	main.o               maps.o              replays.o \
	state_changepack.o   state_chooseship.o  state_endsequence.o \
	state_game.o         state_gameover.o    state_instructions.o \
	state_interphase.o   state_keyredefinition.o \
	state_levelfinished.o state_logo.o       state_mainmenu.o \
	state_replay.o       state_replaymanager.o \
	state_typetext.o     tiles.o             transball.o \

all: $(TARGET)

%.o: %.cpp
	$(CXX) -c -g3 -O3 $< -o $@ `$(SYSROOT)/usr/bin/sdl-config --cflags`

# dynamically linked binary:
$(TARGET): $(OBJS)
	$(CXX) $^ -o $@ `$(SYSROOT)/usr/bin/sdl-config --libs` -lSDL_image -lSDL_mixer -lSDL_sound -lSDL_sound -lSGE
ifndef DEBUG
	$(STRIP) $(TARGET)
endif
	mv ./$(TARGET) ..

clean:
	rm -f ../$(TARGET)
	rm -f *.o
