# -*- mode: Makefile; -*-
# -----------------------------------------
# project Vinland_Trail


export PATH := /opt/wx/2.8/bin:$(PATH)
export LD_LIBRARY_PATH := /opt/wx/2.8/lib:$(LD_LIBRARY_PATH)

_WX = /home/gr/projects/gui/codeblocks/wx
_WX.LIB = $(_WX)/lib
_WX.INCLUDE = $(_WX)/include

_CB = /home/gr/projects/gui/codeblocks/cb/src
_CB.INCLUDE = $(_CB)/include
_CB.LIB = $(_CB)/devel



CFLAGS_C = $(filter-out -include "sdk.h",$(CFLAGS))

# -----------------------------------------

# MAKE_DEP = -MMD -MT $@ -MF $(@:.o=.d)

CFLAGS = -Wall `sdl-config --cflags` 
INCLUDES = 
LDFLAGS = `sdl-config --libs`  -s
RCFLAGS = 
LDLIBS = $(T_LDLIBS) -lSDL -lSDL_ttf -lSDL_mixer -lSDL_image -lSDL_gfx  -lstdc++

LINK_exe = gcc -o $@ $^ $(LDFLAGS) $(LDLIBS)
LINK_con = gcc -o $@ $^ $(LDFLAGS) $(LDLIBS)
LINK_dll = gcc -o $@ $^ $(LDFLAGS) $(LDLIBS) -shared
LINK_lib = rm -f $@ && ar rcs $@ $^
COMPILE_c = gcc $(CFLAGS_C) -o $@ -c $< $(MAKEDEP) $(INCLUDES)
COMPILE_cpp = g++ $(CFLAGS) -o $@ -c $< $(MAKEDEP) $(INCLUDES)
COMPILE_rc = windres $(RCFLAGS) -J rc -O coff -i $< -o $@ -I$(dir $<)

%.o : %.c ; $(COMPILE_c)
%.o : %.cpp ; $(COMPILE_cpp)
%.o : %.cxx ; $(COMPILE_cpp)
%.o : %.rc ; $(COMPILE_rc)
.SUFFIXES: .o .d .c .cpp .cxx .rc

all: all.before all.targets all.after

all.before :
	-
all.after : $(FIRST_TARGET)
	
all.targets : Release_target 

clean :
	rm -fv $(clean.OBJ)
	rm -fv $(DEP_FILES)

.PHONY: all clean distclean

# -----------------------------------------
# Release_target

Release_target.BIN = VinlandTrail
Release_target.OBJ = buy_at_landmark.o buy_stuff.o calculate_score.o change_health.o choose_class.o clean_up.o clear_screen.o game_over.o go_fishing_or_whaling.o high_seas.o how_many_alive.o landmark_reached.o load_media.o main.o main_menu.o name_party_members.o pillage_city.o print_full_picture.o put_text_at.o random_event.o read_history.o repair_boat.o show_intro.o vinland_reached.o 
DEP_FILES += buy_at_landmark.d buy_stuff.d calculate_score.d change_health.d choose_class.d clean_up.d clear_screen.d game_over.d go_fishing_or_whaling.d high_seas.d how_many_alive.d landmark_reached.d load_media.d main.d main_menu.d name_party_members.d pillage_city.d print_full_picture.d put_text_at.d random_event.d read_history.d repair_boat.d show_intro.d vinland_reached.d 
clean.OBJ += $(Release_target.BIN) $(Release_target.OBJ)

Release_target : Release_target.before $(Release_target.BIN) Release_target.after_always
Release_target : CFLAGS += -O2  -Os
Release_target : INCLUDES += 
Release_target : RCFLAGS += 
Release_target : LDFLAGS += -s   
Release_target : T_LDLIBS = 
ifdef LMAKE
Release_target : CFLAGS -= -O1 -O2 -g -pipe
endif

Release_target.before :
	
	
Release_target.after_always : $(Release_target.BIN)
	
$(Release_target.BIN) : $(Release_target.OBJ)
	$(LINK_exe)
	

# -----------------------------------------
ifdef MAKE_DEP
-include $(DEP_FILES)
endif
