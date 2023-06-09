#pragma once

#include <eosio/vm/interpret_visitor.hpp>
#include <iostream>
#include <map>

std::map<std::string, uint32_t> frequency;
uint32_t total_memops = 0;

#define DBG_VISIT(name, code)                                                                                          \
   void operator()(const EOS_VM_OPCODE_T(name)& op) {                                                                  \
      frequency[#name]++;                                                                                             \
      interpret_visitor<ExecutionCTX>::operator()(op);                                                                 \
   }

#define DBG_MEM_VISIT(name, code)                                                                                          \
   void operator()(const EOS_VM_OPCODE_T(name)& op) {                                                                  \
      frequency[#name]++;    \
      total_memops++;                                                                                         \
      interpret_visitor<ExecutionCTX>::operator()(op);                                                                 \
   }

#define DBG2_VISIT(name, code)                                                                                         \
   void operator()(const EOS_VM_OPCODE_T(name)& op) { std::cout << "Found " << #name << "\n"; }

namespace eosio { namespace vm {

template <typename ExecutionCTX>
struct my_visitor : public interpret_visitor<ExecutionCTX> {
   using interpret_visitor<ExecutionCTX>::operator();
   my_visitor(ExecutionCTX& ctx) : interpret_visitor<ExecutionCTX>(ctx) {}
   ExecutionCTX& get_context() { return interpret_visitor<ExecutionCTX>::get_context(); }
   EOS_VM_CONTROL_FLOW_OPS(DBG_VISIT)
   EOS_VM_BR_TABLE_OP(DBG_VISIT)
   EOS_VM_RETURN_OP(DBG_VISIT)
   EOS_VM_CALL_OPS(DBG_VISIT)
   EOS_VM_CALL_IMM_OPS(DBG_VISIT)
   EOS_VM_PARAMETRIC_OPS(DBG_VISIT)
   EOS_VM_VARIABLE_ACCESS_OPS(DBG_VISIT)
   EOS_VM_MEMORY_OPS(DBG_MEM_VISIT)
   EOS_VM_I32_CONSTANT_OPS(DBG_VISIT)
   EOS_VM_I64_CONSTANT_OPS(DBG_VISIT)
   EOS_VM_F32_CONSTANT_OPS(DBG_VISIT)
   EOS_VM_F64_CONSTANT_OPS(DBG_VISIT)
   EOS_VM_COMPARISON_OPS(DBG_VISIT)
   EOS_VM_NUMERIC_OPS(DBG_VISIT)
   EOS_VM_CONVERSION_OPS(DBG_VISIT)
   EOS_VM_EXIT_OP(DBG_VISIT)
   EOS_VM_ERROR_OPS(DBG_VISIT)
};

struct my_visitor2 {
   EOS_VM_CONTROL_FLOW_OPS(DBG2_VISIT)
   EOS_VM_BR_TABLE_OP(DBG2_VISIT)
   EOS_VM_RETURN_OP(DBG2_VISIT)
   EOS_VM_CALL_OPS(DBG2_VISIT)
   EOS_VM_CALL_IMM_OPS(DBG2_VISIT)
   EOS_VM_PARAMETRIC_OPS(DBG2_VISIT)
   EOS_VM_VARIABLE_ACCESS_OPS(DBG2_VISIT)
   EOS_VM_MEMORY_OPS(DBG2_VISIT)
   EOS_VM_I32_CONSTANT_OPS(DBG2_VISIT)
   EOS_VM_I64_CONSTANT_OPS(DBG2_VISIT)
   EOS_VM_F32_CONSTANT_OPS(DBG2_VISIT)
   EOS_VM_F64_CONSTANT_OPS(DBG2_VISIT)
   EOS_VM_COMPARISON_OPS(DBG2_VISIT)
   EOS_VM_NUMERIC_OPS(DBG2_VISIT)
   EOS_VM_CONVERSION_OPS(DBG2_VISIT)
   EOS_VM_EXIT_OP(DBG2_VISIT)
   EOS_VM_ERROR_OPS(DBG2_VISIT)
};
#undef DBG_VISIT
#undef DBG2_VISIT

#undef DBG_VISIT
#undef DBG2_VISIT

}} // ns eosio::wasm_backend
