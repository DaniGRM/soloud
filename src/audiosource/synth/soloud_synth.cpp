/*
SoLoud audio engine
Copyright (c) 2020 Jari Komppa

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

   1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.

   2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.

   3. This notice may not be removed or altered from any source
   distribution.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "soloud_synth.h"
#include "soloud_osc.h"

namespace SoLoud
{

	SynthInstance::SynthInstance(Synth* aParent)
	{
		mOscillator = new Osc(); // Inicializa el oscilador con una frecuencia de muestreo adecuada
		mOscillator->init(aParent->freq);
	}

	SynthInstance::~SynthInstance()
	{
		delete mOscillator; // Libera la memoria del oscilador
	}

	unsigned int SynthInstance::getAudio(float* aBuffer, unsigned int aSamplesToRead, unsigned int /*aBufferSize*/)
	{

		float* sineBlock = mOscillator->getBlock(aSamplesToRead);
		for (unsigned int i = 0; i < aSamplesToRead; i++)
		{
			aBuffer[i] = sineBlock[i]; // Copia la onda seno generada al buffer de salida
		}
		return aSamplesToRead;
	}

	bool SynthInstance::hasEnded()
	{
		return false;
	}

	Synth::Synth()
	{
		mBaseSamplerate = 44100;
		freq = 440.f;
	}

	Synth::~Synth()
	{
		stop();
	}

	AudioSourceInstance* Synth::createInstance()
	{
		return new SynthInstance(this);
	}

	result Synth::setFrequency(float aFreq) {
		if (aFreq <= 0.f || aFreq > static_cast<float>(mBaseSamplerate / 2)) {
			return INVALID_PARAMETER;
		}
		freq = aFreq;

		return SO_NO_ERROR;
	}

};