This is the famous ``One Small Step'' quote from the Apollo 11
landing. I've converted this file into every format I could find a
converter for (including many formats not discussed in the book), to
provide a library of test files.

Original File

The original WAV-format file is original.wav (also available from the
NASA web site). It's an 8-bit linear file, recorded at an 11025 hertz
sampling rate, monophonic.  I first converted it into wav/pcm8.wav by
increasing the amplitude by 1.5.  I then converted wav/pcm8.wav into
each of the other formats.  (Most are single-step conversions.)

Organization

There's a directory for each format.  Within that directory are files
in various sub-formats (different compression methods, sample widths,
etc).

Note that many of the file extensions have been truncated.
(aiff to aif, for instance)

Directories:
        au - Sun/NeXT AU format
        aiff - Apple Audio Interchange File Format
        HCOM - Apple HCOM format
        MPEG - MPEG audio stream
        quicktim - Apple QuickTime
        sd1 - Sound Designer 1
        sd2 - Sound Designer 2
        sf - IRCAM Sound Format
        system 7 - Apple System 7 sound file
        voc - Creative Labs' VOC
        wav - Microsoft RIFF/WAV

