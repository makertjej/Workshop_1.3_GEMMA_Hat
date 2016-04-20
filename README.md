MAKERTJEJ.se’s 
## Workshop_1.3_GEMMAs Hat
***
*(Svenska)*

Source kod för att skapa [Gemma’s Hat] (http://globalgamejam.org/2016/games/gemmas-hat), först skapade under Global Game Jam 2016 i Stockholm, Sverige.

#### Att installera på datorn:

* Adafruit Arduino IDE Package (det enda som behövs är egentligen NeoPixel-biblioteket, och drivrutiner och inställningar för Gemma, men detta går snabbare och ger en möjlighet att jobba med andra saker från Adafruit)
  * [1.6.x](https://learn.adafruit.com/adafruit-arduino-ide-setup/arduino-1-dot-6-x-ide)
  * [1.0.x](https://learn.adafruit.com/adafruit-arduino-ide-setup/arduino-1-dot-0-x-ide)

* “Gemma_Hat_AlignPixels.ino” används under byggande för att rikta dem olika neopixel ringar.

* “Gemma_Hat_Game.ino” är själva spel-koden.

Extra program:

* “Gemma_Hat_PixelPosition.ino” tänder pixlar en åt gången, från position 0 till 51.

* “Gemma_Hat_Tables.ino” tänder pixlar i varje tabell/runda med en unik färg.

Glöm inte micro eller mini-USB kabel (beror på vilken version av GEMMA man har).

***

*(English)*

Source code to make [Gemma’s Hat] (http://globalgamejam.org/2016/games/gemmas-hat), first created during Global Game Jam 2016 in Stockholm, Sweden.

#### To install on your computer:

* Adafruit Arduino IDE Package (the only thing you really need is the NeoPixel library,  and control routines for GEMMA, but this is fastest and works well with other Adafruit products)
  * [1.6.x](https://learn.adafruit.com/adafruit-arduino-ide-setup/arduino-1-dot-6-x-ide)
  * [1.0.x](https://learn.adafruit.com/adafruit-arduino-ide-setup/arduino-1-dot-0-x-ide)

* “Gemma_Hat_AlignPixels.ino” is used when assembling your hat to align the neopixel rings.

* “Gemma_Hat_Game.ino” is the game code.

Extra programs:

* “Gemma_Hat_PixelPosition.ino” lights up pixels one at a time, from position 0 to 51.

* “Gemma_Hat_Tables.ino” lights up each table/round with a different color.

Don’t forget the micro or mini-USB cable (depends which version of GEMMA you have).
