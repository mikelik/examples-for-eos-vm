#include <cstdint>

extern "C" {
   __attribute__((eosio_wasm_import))
   void print_number(int32_t);

   void apply(uint64_t, uint64_t, uint64_t) {
      print_number(0);
      print_number(42);
      print_number(-1);
      print_number(-42);
      print_number(-209308208);
   }
}