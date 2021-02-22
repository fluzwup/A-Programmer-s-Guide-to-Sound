/*
   Copyright 1997 Tim Kientzle.  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
      This product includes software developed by Tim Kientzle
      and published in ``The Programmer's Guide to Sound.''
4. Neither the names of Tim Kientzle nor Addison-Wesley
   may be used to endorse or promote products derived from this software
   without specific prior written permission.

THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL TIM KIENTZLE OR ADDISON-WESLEY BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef AUDIO_H_INCLUDED
#define AUDIO_H_INCLUDED

#include <typeinfo>
#include <iostream>
#include <cstddef>

// The following line is necessary if your compiler
//    strictly follows the ANSI C++ Standard (almost none do).
// However, some compilers don't implement this feature at all.
// If your compiler complains about this line,
//   simply comment it out and try again.
using namespace std;

typedef short AudioSample; // A single audio sample
typedef unsigned char AudioByte; // an 8-bit unsigned byte
long ReadIntMsb(istream &in, int bytes);
long BytesToIntMsb(void *buff, int bytes);
long ReadIntLsb(istream &in, int bytes);
long BytesToIntLsb(void *buff, int bytes);
void SkipBytes(istream &in, int bytes);
void WriteIntMsb(ostream &out, long l, int bytes);
void WriteIntLsb(ostream &out, long l, int bytes);

class AudioAbstract {
   
private:
   AudioAbstract *_previous; // object to get data from
   AudioAbstract *_next; // object pulling data from us
public:
   AudioAbstract *Previous(void) { return _previous; }
   void Previous(AudioAbstract *a) { _previous = a; }
   AudioAbstract *Next(void) { return _next; }
   void Next(AudioAbstract *a) {_next = a;}
public:
   AudioAbstract(void) {
      _previous = 0;
      _next = 0;
      _samplingRate = 0;  _samplingRateFrozen = false;
      _channels = 0;      _channelsFrozen = false;
   };
public:
   AudioAbstract(AudioAbstract *audio) {
      _previous = audio;
      _next = 0;
      audio->Next(this);
      _samplingRate = 0;  _samplingRateFrozen = false;
      _channels = 0;      _channelsFrozen = false;
   };
public:
   virtual ~AudioAbstract(void) {};
public:
   // Returns number of samples actually read, 0 on error.
   // This should always return the full request unless there is
   // an error or end-of-data.
   virtual size_t GetSamples(AudioSample *, size_t) = 0;
public:
   virtual size_t ReadBytes(AudioByte * buff, size_t length) {
      return Previous()->ReadBytes(buff,length);
   };
   
private:
   long _samplingRate;
   bool _samplingRateFrozen;
public:
   virtual long SamplingRate(void) {
      if (!_samplingRateFrozen)  // Not frozen?
         NegotiateSamplingRate(); // Go figure it out
      return _samplingRate; // Return it
   };

   virtual void SamplingRate(long s) { // Set the sampling rate
      if (_samplingRateFrozen) {
         cerr << "Can't change sampling rate.\n";
         exit(1);
      }
      _samplingRate = s;
   };
public:
   virtual void NegotiateSamplingRate(void);
public:
   virtual void MinMaxSamplingRate(long *min, long *max, long *prefer);
   virtual void SetSamplingRateRecursive(long s);
   
private:
   long _channels;
   bool _channelsFrozen;
public:
   virtual int Channels(void) {
      if (!_channelsFrozen) NegotiateChannels();
      return _channels;
   };

   virtual void Channels(int ch) {
      if (_channelsFrozen) {
         cerr << "Can't change number of channels.\n";
         exit(1);
      }
      _channels = ch;
   };

   virtual void NegotiateChannels(void);
   virtual void MinMaxChannels(int *min, int *max, int *preferred) ;
   virtual void SetChannelsRecursive(int s);
};

#endif
