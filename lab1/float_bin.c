/*
PROG: floating to bin conversion
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

//Fill in appropriate values
//Fill start
#define ABSOLUTE_WIDTH 31
#define MANTISSA_WIDTH 23	
#define EXPONENT_WIDTH 8
// this is hex notation
// for e.g deciaml number 12 in wrriten as 0xc or 0xcu
#define EXPONENT_MASK 0xff 
#define MANTISSA_MASK 0x7fffff
#define EXPONENT_BIAS 127
//Fill end

union float_bits {
  float f;
  // uint32_t = standard data type for unsigned integer 32 bit wide defined in stdint
  uint32_t bits;
};

void print_float( FILE *output, float f ) {
  // define union with instance name t here
union float_bits t;
  t.f=f;
  uint32_t sign_bit = ( t.bits >> ABSOLUTE_WIDTH );
  uint32_t exponent = (( t.bits >> MANTISSA_WIDTH ) & EXPONENT_MASK );// Fill in
  uint32_t mantissa = ( t.bits & MANTISSA_MASK );// Fill in 

  if( sign_bit != 0 ) {
    fprintf( output, "-" );
  }

  if( exponent > 2 * EXPONENT_BIAS ) { // corner case 1
    fprintf( output, "Inf\n" ); /* Infinity */
    return;
  } else if( exponent == 0 ) { // corner case 2
    fprintf( output, "0." ); /* Zero or Denormal */
    exponent = ( mantissa != 0 ) ? exponent + 1 : exponent;
  } else {
    fprintf( output, "1." ); /* Usual */
  }

  for( int k = MANTISSA_WIDTH - 1; k >= 0; --k ) {
    fprintf( output, "%d", ( mantissa >> k ) & 1 );
  }

  if( exponent != 0 || mantissa != 0 ) {
    fprintf( output, " * 2^%d\n", (int) ( exponent - EXPONENT_BIAS ) );
  }
}

int main() {
  FILE *input  = fopen( "floating.in",  "r" ),
       *output = fopen( "floating.out", "w" );

  size_t N; float f;
  fscanf( input, "%zu", &N );

  for( size_t i = 0; i < N; ++i ) {
    fscanf( input, "%f", &f );
    print_float( output, f );
  }

  fclose( input );
  fclose( output );

  return 0;
}
