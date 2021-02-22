#
# Makefile for "A Programmer's Guide to Sound"
#
# By default, the makefile will compile 'playsnd' for NAS.
# If you don't have NAS, experiment with 'playtoau' instead,
#   which does the same thing, but "plays" to an AU format
#   file on stdout.
#
# Note: If GCC is properly installed (it knows how to find all the
# relevant libraries and headers), you can probably compile
# straight from the CD.  Intermediate files and binaries will go
# to /tmp.
#
SHELL=/bin/sh
BINARIES= playsnd playtoau			\
	 autoau playnote sinetoau playau	\
	 fftmain ifftmain			\
	 logtest testmatrix

# Compiler to use (GCC 2.7.2)
CC=g++

# Options for compiler.
# Enable a lot of GCC warning flags
CFLAGS += -ggdb -I$(SRCDIR) -g -pedantic -W -Wall				\
	-Wpointer-arith -Wwrite-strings		\
	-Wmissing-declarations	\
	-Wredundant-decls -Winline -Woverloaded-virtual

# If your GCC doesn't know where the G++ headers are, uncomment and edit
#CFLAGS += -I/usr/local/app/gcc-2.7.2/lib/g++-include

# Libraries to use
# If GCC doesn't know where the Standard C++ library is, uncomment and edit
#LIBS += /usr/local/app/gcc-2.7.2/lib/libstdc++.a 
# Use GNU malloc (optional)
#LIBS += -lgnumalloc
# Use math library
LIBS += -lm
# Use NAS library
LIBS += -L/usr/local/lib -laudio
# Use Xau library
LIBS += -L/usr/X11/lib -lXau

# Help GNU Make understand 4.4BSD convention
# (Remove this line if you're using BSD make)
>=$^

# Directory to find source files
SRCDIR = ../common
# Directory to put object files
OBJDIR = ./
# Directory to put binary files
BINDIR = ./

###########################################################################
#
# Default and symbolic targets
#
###########################################################################

default: playsnd

all: $(BINARIES)

clean:
	rm *.o ${BINARIES}

###########################################################################
#
# Compile files
#
###########################################################################
PLAYER_HPP = $(SRCDIR)/nasplayr.h

$(OBJDIR)/aiff.o: $(SRCDIR)/aiff.cpp $(SRCDIR)/aiff.h			\
	$(SRCDIR)/audio.h $(SRCDIR)/compress.h $(SRCDIR)/g711.h		\
	$(SRCDIR)/imaadpcm.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/au.o: $(SRCDIR)/au.cpp $(SRCDIR)/au.h $(SRCDIR)/g711.h 	\
	$(SRCDIR)/audio.h $(SRCDIR)/compress.h $(SRCDIR)/aplayer.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/audio.o: $(SRCDIR)/audio.cpp $(SRCDIR)/audio.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/autoau.o: $(SRCDIR)/autoau.cpp $(SRCDIR)/au.h 		\
	$(SRCDIR)/g711.h $(SRCDIR)/audio.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/compress.o: $(SRCDIR)/compress.cpp $(SRCDIR)/compress.h 	\
	$(SRCDIR)/audio.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/dpcm.o: $(SRCDIR)/dpcm.cpp $(SRCDIR)/dpcm.h			\
	$(SRCDIR)/audio.h $(SRCDIR)/compress.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/fft.o: $(SRCDIR)/fft.cpp $(SRCDIR)/fft.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/fftmain.o: $(SRCDIR)/fftmain.cpp $(SRCDIR)/fft.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/g711.o: $(SRCDIR)/g711.cpp $(SRCDIR)/g711.h 			\
	$(SRCDIR)/compress.h $(SRCDIR)/audio.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/iff.o: $(SRCDIR)/iff.cpp $(SRCDIR)/iff.h			\
	 $(SRCDIR)/audio.h $(SRCDIR)/compress.h $(SRCDIR)/dpcm.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/ifftmain.o: $(SRCDIR)/ifftmain.cpp $(SRCDIR)/fft.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/imaadpcm.o: $(SRCDIR)/imaadpcm.cpp $(SRCDIR)/imaadpcm.h	\
	$(SRCDIR)/compress.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/logtest.o: $(SRCDIR)/logtest.cpp $(SRCDIR)/g711.h 	\
	$(SRCDIR)/compress.h $(SRCDIR)/audio.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/nasmain.o: $(SRCDIR)/nasmain.cpp $(SRCDIR)/aplayer.h		\
	$(SRCDIR)/nasplayr.h $(SRCDIR)/audio.h				\
	$(SRCDIR)/open.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/midi.o: $(SRCDIR)/midi.cpp $(SRCDIR)/midi.h $(SRCDIR)/audio.h	\
	$(SRCDIR)/sampled.h $(SRCDIR)/instrumt.h $(SRCDIR)/plucked.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/mod.o: $(SRCDIR)/mod.cpp $(SRCDIR)/mod.h $(SRCDIR)/audio.h\
	$(SRCDIR)/sampled.h $(SRCDIR)/instrumt.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/mpeg.o: $(SRCDIR)/mpeg.cpp $(SRCDIR)/mpeg.h			\
	$(SRCDIR)/compress.h $(SRCDIR)/audio.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/nasplayr.o: $(SRCDIR)/nasplayr.cpp $(SRCDIR)/aplayer.h	\
	$(SRCDIR)/nasplayr.h $(SRCDIR)/audio.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/open.o: $(SRCDIR)/open.cpp $(SRCDIR)/open.h			\
	$(SRCDIR)/audio.h $(SRCDIR)/compress.h $(SRCDIR)/mpeg.h		\
	$(SRCDIR)/au.h $(SRCDIR)/voc.h $(SRCDIR)/wav.h			\
	$(SRCDIR)/aiff.h $(SRCDIR)/iff.h $(SRCDIR)/midi.h		\
	$(SRCDIR)/mod.h $(SRCDIR)/sampled.h $(SRCDIR)/instrumt.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/playau.o: $(SRCDIR)/playau.cpp $(SRCDIR)/au.h 		\
	$(SRCDIR)/aplayer.h $(PLAYER_HPP) $(SRCDIR)/audio.h		\
	$(SRCDIR)/compress.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/aplayer.o: $(SRCDIR)/aplayer.cpp $(SRCDIR)/aplayer.h		\
	$(PLAYER_HPP) $(SRCDIR)/audio.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/playnote.o: $(SRCDIR)/playnote.cpp $(SRCDIR)/audio.h		\
	$(SRCDIR)/instrumt.h $(SRCDIR)/sampled.h $(SRCDIR)/plucked.h	\
	$(SRCDIR)/aplayer.h $(PLAYER_HPP)
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/sinetoau.o: $(SRCDIR)/sinetoau.cpp 			\
	$(SRCDIR)/sinewave.h $(SRCDIR)/audio.h		\
	$(SRCDIR)/aplayer.h $(PLAYER_HPP)
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/playtoau.o: $(SRCDIR)/playtoau.cpp $(SRCDIR)/au.h		\
	$(SRCDIR)/audio.h $(SRCDIR)/open.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/plucked.o: $(SRCDIR)/plucked.cpp $(SRCDIR)/audio.h		\
	$(SRCDIR)/plucked.h $(SRCDIR)/instrumt.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/sampled.o: $(SRCDIR)/sampled.cpp $(SRCDIR)/audio.h		\
	$(SRCDIR)/sampled.h $(SRCDIR)/instrumt.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/sinewave.o: $(SRCDIR)/sinewave.cpp 			\
	$(SRCDIR)/sinewave.h $(SRCDIR)/audio.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/voc.o: $(SRCDIR)/voc.cpp $(SRCDIR)/voc.h			\
	$(SRCDIR)/audio.h $(SRCDIR)/compress.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/wav.o: $(SRCDIR)/wav.cpp $(SRCDIR)/wav.h 			\
	$(SRCDIR)/audio.h $(SRCDIR)/compress.h $(SRCDIR)/imaadpcm.h	\
	$(SRCDIR)/g711.h
	$(CC) -c $(CFLAGS) -o $@ $<

###########################################################################
#
# Actual programs to build
#
###########################################################################
playsnd: $(BINDIR)/playsnd

$(BINDIR)/playsnd: $(OBJDIR)/audio.o					\
	$(OBJDIR)/aplayer.o $(OBJDIR)/nasplayr.o $(OBJDIR)/nasmain.o	\
	$(OBJDIR)/compress.o $(OBJDIR)/g711.o $(OBJDIR)/dpcm.o		\
	$(OBJDIR)/imaadpcm.o $(OBJDIR)/mpeg.o				\
	$(OBJDIR)/au.o $(OBJDIR)/voc.o					\
	$(OBJDIR)/wav.o $(OBJDIR)/aiff.o $(OBJDIR)/iff.o		\
	$(OBJDIR)/plucked.o $(OBJDIR)/sampled.o				\
	$(OBJDIR)/midi.o $(OBJDIR)/mod.o 				\
	$(OBJDIR)/open.o
	$(CC) $(CFLAGS) -o $@ $> $(LIBS)

playtoau: $(BINDIR)/playtoau

$(BINDIR)/playtoau: $(OBJDIR)/audio.o					\
	$(OBJDIR)/aplayer.o $(OBJDIR)/playtoau.o			\
	$(OBJDIR)/compress.o $(OBJDIR)/g711.o $(OBJDIR)/dpcm.o		\
	$(OBJDIR)/imaadpcm.o $(OBJDIR)/mpeg.o				\
	$(OBJDIR)/au.o $(OBJDIR)/voc.o					\
	$(OBJDIR)/wav.o $(OBJDIR)/aiff.o $(OBJDIR)/iff.o		\
	$(OBJDIR)/plucked.o $(OBJDIR)/sampled.o				\
	$(OBJDIR)/midi.o $(OBJDIR)/mod.o 				\
	$(OBJDIR)/open.o
	$(CC) $(CFLAGS) -o $@ $> $(LIBS)

fftmain: $(BINDIR)/fftmain

$(BINDIR)/fftmain: $(OBJDIR)/fftmain.o $(OBJDIR)/fft.o
	$(CC) $(CFLAGS) -o $@ $> $(LIBS)

ifftmain: $(BINDIR)/ifftmain

$(BINDIR)/ifftmain: $(OBJDIR)/ifftmain.o $(OBJDIR)/fft.o
	$(CC) $(CFLAGS) -o $@ $> $(LIBS)

playau: $(BINDIR)/playau

$(BINDIR)/playau: $(OBJDIR)/playau.o $(OBJDIR)/au.o $(OBJDIR)/aplayer.o	\
	$(OBJDIR)/audio.o $(OBJDIR)/compress.o $(OBJDIR)/g711.o		\
	$(OBJDIR)/nasplayr.o
	$(CC) $(CFLAGS) -o $@ $> $(LIBS)

autoau: $(BINDIR)/autoau

$(BINDIR)/autoau: $(OBJDIR)/autoau.o $(OBJDIR)/au.o $(OBJDIR)/audio.o	\
	$(OBJDIR)/g711.o $(OBJDIR)/compress.o $(OBJDIR)/aplayer.o
	$(CC) $(CFLAGS) -o $@ $> $(LIBS)

playnote: $(BINDIR)/playnote

$(BINDIR)/playnote: $(OBJDIR)/playnote.o $(OBJDIR)/aplayer.o 		\
	$(OBJDIR)/audio.o 						\
	$(OBJDIR)/nasplayr.o $(OBJDIR)/sampled.o $(OBJDIR)/plucked.o    \
	$(OBJDIR)/au.o $(OBJDIR)/g711.o $(OBJDIR)/compress.o
	$(CC) $(CFLAGS) -o $@ $> $(LIBS)

sinetoau: $(BINDIR)/sinetoau

$(BINDIR)/sinetoau: $(OBJDIR)/sinetoau.o $(OBJDIR)/sinewave.o 		\
	$(OBJDIR)/aplayer.o						\
	$(OBJDIR)/audio.o $(OBJDIR)/au.o $(OBJDIR)/g711.o 		\
	$(OBJDIR)/compress.o
	$(CC) $(CFLAGS) -o $@ $> $(LIBS)

logtest: $(BINDIR)/logtest

$(BINDIR)/logtest: $(OBJDIR)/logtest.o $(OBJDIR)/audio.o $(OBJDIR)/g711.o
	$(CC) $(CFLAGS) -o $@ $> $(LIBS)

testmatrix: $(BINDIR)/testmatrix

$(BINDIR)/testmatrix: $(SRCDIR)/testmatrix.cpp
	$(CC) $(CFLAGS) -o $@ $> $(LIBS)

###########################################################################
