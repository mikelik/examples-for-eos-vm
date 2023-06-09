// compile with cdt-cpp -o hello.wasm wasm.cpp
#include <eosio/eosio.hpp>
#include <eosio/print.hpp>

extern "C" {
// [[eosio::wasm_import]] void print_name(const char*);
[[eosio::wasm_import]] void print_num(uint64_t);
// [[eosio::wasm_import]] void print_span(const char*, std::size_t);

void apply(uint64_t a, uint64_t b, uint64_t c)
{
   const char* test_str = "hellohellohello";
   print_num(a);
   print_num(b);
   print_num(c);
   eosio::check(b == c, "Failure B != C");
//    for (uint64_t i = 0; i < a; i++)
//        print_name("eos-vm");
//    print_span(test_str, 5);
//    print_span(test_str, 10);
}
}