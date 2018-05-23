# Lesson 0: Introduction to the Particle Photon

The Particle Photon is a programmable microprocessor board that is great for IoT (Internet of Things) projects.

It can be programmed in several ways, but the recommended way to program it (by Nathan) is to use Atom and po.
More about that soon.

Much like Arduino, every Photon sketch must contain a `setup()` function and a `loop()` function. `setup()` runs once when the Photon is powered up (via USB, battery, etc.), and `loop()` continuously runs repeatedly after `setup()` until the Photon is powered down.

At a low level, the Photon's behavior can be summarized as the control of its pins. There are many pins on the Photon, and many of them can be controlled by programs to do different functions.
