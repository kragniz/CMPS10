CMPS10
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

License
-------

This code is released under the terms of the LGPLv3 license. See `COPYING` for
more details.
