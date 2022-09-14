#ifndef _SRC_EIP712_H_
#define _SRC_EIP712_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define EIP712_HASH_SIZE 32

typedef struct _eip712_domain {
  uint8_t chain_id[EIP712_HASH_SIZE];
  char* name;
  uint8_t verifying_contract[20];
  char* version;
} eip712_domain;

typedef struct _eip712_active {
  char* action;
  char* params;
} eip712_active;

typedef struct _eip712_cell {
  char* capacity;
  char* lock;
  char* type;
  char* data;
  char* extra_data;
} eip712_cell;

typedef struct _eip712_data {
  eip712_domain domain;
  eip712_active active;
  char* transaction_das_message;
  char* inputs_capacity;
  char* outputs_capacity;
  char* fee;
  char* digest;

  eip712_cell* inputs;
  size_t inputs_len;
  eip712_cell* outputs;
  size_t outputs_len;
} eip712_data;

int get_eip712_hash(eip712_data* data, uint8_t* out_hash);

typedef enum {
  EIP712_SUC = 0,
  EIP712EER_INVALID_ARG,
  EIP712ERR_GEN_DATA,
  EIP712ERR_ENCODE_TYPE,
  EIP712ERR_ENCODE_ADDRESS,
  EIP712ERR_ENCODE_STRING,
  EIP712ERR_ENCODE_INT,
  EIP712ERR_ENCODE_BOOL,
  EIP712ERR_ENCODE_STRUCT,
  EIP712ERR_ENCODE_BYTES,
  EIP712ERR_ENCODE_MESSAGE,

  EIP712ERR_ENCODE_UNKNOW,
} EIP712RcCode;

#endif  // _SRC_EIP712_H_
