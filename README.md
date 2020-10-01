# ir_bitbang
## Arduino Sketches for bit banging infrared signals

These sketches were written to "bit bang" iR signals.  They were developed specifically for a Roku XD media streamer, 
which uses an NEC-like protocol with a 2-byte address followed by a 1-byte instruction and the 1-byte inverse of the instruction.
See https://www.sbprojects.net/knowledge/ir/nec.php for more information on this and other common iR protocols.

There are four sketches:
roku_home_POC.ino          -> Initial proof of concept which sends the equivalent of pressing "home" on the remote
roku_fuzz_address.ino      -> Tries each possible address
roku_fuzz_instructions.ino -> Tries each possible instruction
roku_flood.ino             -> Spams instructions as quickly as possible

These sketches were written for and tested on a 3.3v Pro Micro MCU

Twitter: @tdotfish

Github:  https://github.com/tdotfishtdotfish
