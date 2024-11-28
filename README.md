# Atmega32_sine_wave_generator

Generating a sine wave with an ATmega32 is not practically possible without an external DAC; however, another solution is using the ATmega32 as a pulse modulator. In this sense, the code in Atmel Studio uses a predefined pattern of bytes, which serves as a pulse-modulated signal for a sine wave. After passing through a differentiator, these pulses can be shaped into a sequence of impulses in the form of a sine wave. By integrating these impulses, an approximate sine wave is produced at the output. Consequently, we can use a band-pass filter to achieve the desired output. This project has been practically tested in the laboratory.

Overall, while working on this project, I had the chance to apply some theories from my communication circuits course and reduce the hardware needed. Although there might be better ways to generate a sine wave.
