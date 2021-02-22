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
#ifndef SINEWAVE_H_INCLUDED
#define SINEWAVE_H_INCLUDED

#include "audio.h"

class SineWave: public AudioAbstract {
   
protected:
   void MinMaxChannels(int *min, int *max, int *preferred) {
      *min = *max = *preferred = 1;
   };
protected:
   size_t GetSamples(AudioSample *buff, size_t bytesWanted);
private:
   AudioSample *sine; // table of sine values
   int length; // length of above table
   int pos; // current position in table
   int frequency; // desired output frequency
public:
   void Frequency(int f) { frequency = f; }
private:
   void Init(void) {
      sine = (AudioSample *)0;
      length=0; pos=0; frequency=1;
   }
public:
   SineWave(void):AudioAbstract() { Init(); }

   SineWave(int f):AudioAbstract() {
      Init();
      Frequency(f);
   };

   ~SineWave(void) {
      if (sine) delete [] sine;
   }
private:
   void BuildTable(long rate);
public:
   void SamplingRate(long rate) {
      AudioAbstract::SamplingRate(rate);
      BuildTable(rate);
   }
};
#endif
