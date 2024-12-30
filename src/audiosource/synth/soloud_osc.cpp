#include "soloud_osc.h"

namespace SoLoud
{
	Osc::Osc()
	{
		freq = 440.f;
		sampleRate = 44100;
		init(freq);
	}
	result Osc::init(float aFreq)
	{
		if (aFreq <= 0.f || aFreq > static_cast<float>(sampleRate / 2)) {
			return INVALID_PARAMETER;
		}
		freq = aFreq;
		delta = (2 * M_PI * freq) / static_cast<float>(sampleRate);
		phase = 0.f;
		mData = nullptr;
		return SO_NO_ERROR;
	}

	Osc::~Osc() {
		delete[] mData;
	}

	result Osc::setFrequency(unsigned int aFreq) {
		if (freq <= 0.f || freq > static_cast<float>(sampleRate / 2)) {
			return INVALID_PARAMETER;
		}
		freq = aFreq;
		delta = (2 * M_PI * freq) / static_cast<float>(sampleRate);
		return SO_NO_ERROR;
	}


	float* Osc::getBlock(unsigned int size) {

		if (mData) {
			delete[] mData;
		}

		mData = new float[size];

		for (unsigned int i = 0; i < size; i++) {
			mData[i] = sin(phase);
			phase = phase + delta;
			if (phase >= 2 * M_PI) {
				phase -= 2 * M_PI;
			}


		}
		return mData;
	}
}