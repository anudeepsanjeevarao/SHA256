/*
 * sha256_cpu.h - CPU Implementation of SHA256 Hashing (Host-Side)
 *
 * Declares the public API for batch SHA-256 hashing on CPU.
 * This implementation processes hashes in batches with identical logic
 * to the GPU version (all batch slots compute SHA256 on the identical input).
 *
 * Based on the public domain Reference Implementation in C, by Brad Conte.
 * This file is released into the Public Domain.
 */

#pragma once

#include "config.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * mcm_cpu_sha256_hash_batch - Compute SHA256 hashes on CPU
 *
 * Parameters:
 *   in      - Input data buffer (shared by all hashes in batch)
 *   inlen   - Length of input data in bytes
 *   out     - Output buffer for hashes (must be at least n_batch * 32 bytes)
 *   n_batch - Number of hashes to compute (batch size)
 *
 * Returns:
 *   0       - Success
 *   non-zero - Error (e.g., out of memory)
 *
 * Hash Layout:
 *   - out[i*32 .. i*32+31] = SHA256(in) for each slot i in 0 .. n_batch-1
 *     (Every batch item contains the hash of the original input)
 */
int mcm_cpu_sha256_hash_batch(const BYTE* in, SHA_WORD inlen, BYTE* out, SHA_WORD n_batch);

#ifdef __cplusplus
}
#endif

