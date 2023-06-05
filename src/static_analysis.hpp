#pragma once

#include <eosio/vm/config.hpp>
#include <eosio/vm/base_visitor.hpp>
#include <eosio/vm/exceptions.hpp>
#include <eosio/vm/opcodes.hpp>
#include <eosio/vm/softfloat.hpp>
#include <eosio/vm/stack_elem.hpp>
#include <eosio/vm/utils.hpp>
#include <eosio/vm/wasm_stack.hpp>

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <limits>

using namespace eosio::vm;

struct static_analysis : base_visitor {
   using base_visitor::operator();

   std::size_t count = 0;

   std::size_t get_count() const { return count; }


   void operator()(const i32_add_t& op) { count++; }
   void operator()(const i64_add_t& op) { count++; }
   void operator()(const f32_add_t& op) { count++; }
   void operator()(const f64_add_t& op) { count++; }

   void operator()(const i32_sub_t& op) { count++; }
   void operator()(const i64_sub_t& op) { count++; }
   void operator()(const f32_sub_t& op) { count++; }
   void operator()(const f64_sub_t& op) { count++; }

   void operator()(const i32_const_t& op) { count++; }
   void operator()(const i64_const_t& op) { count++; }

};