## Process this file with automake to produce Makefile.in

## Created by Anjuta

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(GAMEHELPER_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = gamehelper

gamehelper_SOURCES = \
	main.cc \
	game-helper.cc \
	game-helper.h \
	game-helper_handleEvents.cc \
	game-helper_init.cc \
	game-helper_cleanUp.cxx \
	axa-surface.cc \
	axa-surface.h \
	axa-event.cc \
	axa-event.h \
	axa-animation.cc \
	axa-animation.h \
	axa-entity.cc \
	axa-entity.h \
	define.h \
	axa-tile.cc \
	axa-tile.h

gamehelper_LDFLAGS = 

gamehelper_LDADD = $(GAMEHELPER_LIBS)

