/* _____UTILITY MACROS_______________________________________________________ */
/**
@def lowWord(ww) ((uint16_t) ((ww) & 0xFFFF))
Macro to return low word of a 32-bit integer.
*/
#define lowWord(ww) ((uint16_t) ((ww) & 0xFFFF))

/**
@def highWord(ww) ((uint16_t) ((ww) >> 16))
Macro to return high word of a 32-bit integer.
*/
#define highWord(ww) ((uint16_t) ((ww) >> 16))


#define LONG(hi, lo) ((uint32_t) ((hi) << 16 | (lo)))

#define lowByte(w)					 ((w) & 0xFF)
#define highByte(w)					(((w) >> 8) & 0xFF)
#define bitRead(value, bit)			(((value) >> (bit)) & 0x01)
#define bitSet(value, bit)			 ((value) |= (1UL << (bit)))
#define bitClear(value, bit)		   ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))
