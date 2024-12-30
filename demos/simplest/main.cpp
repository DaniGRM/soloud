/*
SoLoud audio engine
Copyright (c) 2013-2014 Jari Komppa

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

#include "soloud.h"
#include "soloud_speech.h"
#include "soloud_noise.h"
#include "soloud_thread.h"
#include "soloud_synth.h"
#include <conio.h> // Biblioteca para kbhit() y getch()
#include <iostream>
#include <windows.h>
int main() {
    SoLoud::Soloud soloud;
    SoLoud::Synth synth;

    // Inicializa SoLoud
    soloud.init();

    int h = 0; // Manejador del sonido
    bool isPlaying = false; // Indica si el sintetizador está sonando
    float frequencies[8] = { 261.63f, 293.66f, 329.63f, 349.23f, 392.00f, 440.00f, 493.88f, 523.25f };

    std::cout << "Pulsa 'q' o 'w' para cambiar la frecuencia. Pulsa 'ESC' para salir.\n";

    while (true) {
        if (GetAsyncKeyState('Q') & 0x8000) { // Detecta si 'q' está presionada
            if (!isPlaying) {
                synth.setFrequency(frequencies[0]);
                h = soloud.play(synth);
                isPlaying = true;
            }
        }
        else if (GetAsyncKeyState('W') & 0x8000) { // Detecta si 'w' está presionada
            if (!isPlaying) {
                synth.setFrequency(frequencies[1]);
                h = soloud.play(synth);
                isPlaying = true;
            }
        }
        else if (GetAsyncKeyState('E') & 0x8000) { // Detecta si 'w' está presionada
            if (!isPlaying) {
                synth.setFrequency(frequencies[2]);
                h = soloud.play(synth);
                isPlaying = true;
            }
        }
        else if (GetAsyncKeyState('R') & 0x8000) { // Detecta si 'w' está presionada
            if (!isPlaying) {
                synth.setFrequency(frequencies[3]);
                h = soloud.play(synth);
                isPlaying = true;
            }
        }
        else if (GetAsyncKeyState('T') & 0x8000) { // Detecta si 'w' está presionada
            if (!isPlaying) {
                synth.setFrequency(frequencies[4]);
                h = soloud.play(synth);
                isPlaying = true;
            }
        }
        else if (GetAsyncKeyState('Y') & 0x8000) { // Detecta si 'w' está presionada
            if (!isPlaying) {
                synth.setFrequency(frequencies[5]);
                h = soloud.play(synth);
                isPlaying = true;
            }
        }
        else if (GetAsyncKeyState('U') & 0x8000) { // Detecta si 'w' está presionada
            if (!isPlaying) {
                synth.setFrequency(frequencies[6]);
                h = soloud.play(synth);
                isPlaying = true;
            }
        }
        else if (GetAsyncKeyState('I') & 0x8000) { // Detecta si 'w' está presionada
            if (!isPlaying) {
                synth.setFrequency(frequencies[7]);
                h = soloud.play(synth);
                isPlaying = true;
            }
        }
        else {
            // Si ninguna tecla relevante está presionada, detén el sonido
            if (isPlaying) {
                soloud.stop(h); // Detén el sintetizador
                std::cout << "Sonido detenido\n";
                isPlaying = false;
            }
        }

        // Salida del programa al presionar ESC
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            break;
        }
    }

    soloud.deinit(); // Libera los recursos de SoLoud
    std::cout << "Programa terminado.\n";

    return 0;
}
// Entry point
//int main(int argc, char *argv[])
//{
//	// Define a couple of variables
//	SoLoud::Soloud soloud;  // SoLoud engine core
//	SoLoud::Speech speech;  // A sound source (speech, in this case)
//	SoLoud::Noise noise;
//	SoLoud::Synth synth;
//
//
//	//noise.setType(SoLoud::Noise::WHITE);
//	// Configure sound source
//	//speech.setText("1 2 3   1 2 3   Hello world. Welcome to So-Loud.");
//	// initialize SoLoud.
//	soloud.init();
//
//	// Play the sound source (we could do this several times if we wanted)
//	auto h = soloud.play(synth);
//
//	SoLoud::Thread::sleep(1000);
//	soloud.stop(h);
//	synth.setFrequency(523);
//	h = soloud.play(synth);
//	SoLoud::Thread::sleep(1000);
//	soloud.stop(h);
//	// Clean up SoLoud
//	soloud.deinit();
//
//	// All done.
//	return 0;
//}