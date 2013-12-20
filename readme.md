CMPS10-arduino
======

Library to read data from a
[CMPS10](http://www.robot-electronics.co.uk/htm/cmps10doc.htm)
tilt-compensating compass with an Arduino.

Installing
----------

Clone this repository

    $ git clone https://github.com/kragniz/CMPS10.git

Copy the files into the Arduino library directory

    $ cp -r CMPS10 ~/sketchbook/libraries/CMPS10

Usage
-----

![axes](https://raw.github.com/kragniz/CMPS10/master/examples/axes.png)

To use this library, include the header file:

```cpp
#include <CMPS10.h>
```

Then create an instance of the compass

```cpp
CMPS10 my_compass;
```

You can now access the bearing of the compass with

```cpp
my_compass.bearing();
```

Methods
-------

Return the bearing in degrees as a float, 0-359.9:

```cpp
float bearing()
```

Return the bearing as a byte, 0-255:

```cpp
int bearing_byte()
```

```cpp
int8_t pitch()

int8_t roll()
```

```cpp
float acceleration()
```

```cpp
float acceleration_x()

float acceleration_y()

float acceleration_z()
```

License
-------

This code is released under the terms of the LGPLv3 license. See `COPYING` for
more details.
