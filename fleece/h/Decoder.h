/**
 * See fleece/COPYRIGHT for copyright information.
 *
 * This file is a part of Fleece.
 *
 * Fleece is free software; you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 3.0 of the License, or (at your option)
 * any later version.
 *  
 * This software is distributed in the hope that it will be useful, but WITHOUT 
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software; if not, see www.gnu.org/licenses
 */


#ifndef _DECODER_H_
#define _DECODER_H_

#define DECODING_BUFFER_SIZE 1024

#include <vector>
#include <ctype.h>

class Decoder {
public:
   Decoder(int (*decodeFunc)(char*, int, char*, int),
           int (*initFunc)(void),
           void (*normFunc)(char*, int),
           const char* name,
           const char* arch);
   int decode(char* inst, int nBytes, char* buf, int bufLen);
   void normalize (char* buf, int bufLen);
   int getNumBytesUsed(char* inst, int nBytes);
   const char* getName(void);
   const char* getArch(void);
   static void initAllDecoders(void);
   static void destroyAllDecoders(void);
   static std::vector<Decoder> getAllDecoders(void);
   static std::vector<Decoder> getDecoders(char* arch, char* names);
   static void printAllNames(void);
   unsigned long getTotalNormalizeTime(void);
   unsigned long getTotalDecodeTime(void);
   unsigned long getTotalDecodedInsns(void);
   const char* name;
   const char* arch;

private:

   void (*normFunc)(char*, int);
   int (*func)(char*, int, char*, int);

   unsigned long totalDecodeTime;
   unsigned long totalNormTime;

   unsigned long totalDecodedInsns;
};

extern int xedInit(void);
extern int LLVMInit(void);

extern int  xed_x86_64_decode     (char*, int, char*, int);
extern void xed_x86_64_norm       (char*, int);

extern int  dyninst_x86_64_decode (char*, int, char*, int);
extern void dyninst_x86_64_norm   (char*, int);

extern int  dyninst_aarch64_decode(char*, int, char*, int);
extern void dyninst_aarch64_norm  (char*, int);
extern int  dyninst_aarch64_init  (void);

extern int  gnu_x86_64_decode     (char*, int, char*, int);
extern void gnu_x86_64_norm       (char*, int);

extern int  gnu_aarch64_decode    (char*, int, char*, int);
extern void gnu_aarch64_norm      (char*, int);

extern int  llvm_x86_64_decode    (char*, int, char*, int);
extern void llvm_x86_64_norm      (char*, int);

extern int  llvm_aarch64_decode   (char*, int, char*, int);
extern void llvm_aarch64_norm     (char*, int);

extern int  capstone_x86_64_decode    (char*, int, char*, int);
extern void capstone_x86_64_norm      (char*, int);

extern int  capstone_aarch64_decode   (char*, int, char*, int);
extern void capstone_aarch64_norm     (char*, int);

extern int  null_aarch64_decode   (char*, int, char*, int);
extern void null_aarch64_norm     (char*, int);

extern int  null_x86_64_decode    (char*, int, char*, int);
extern void null_x86_64_norm      (char*, int);

extern Decoder* dec_xed_x86_64;

extern Decoder* dec_dyninst_x86_64;
extern Decoder* dec_dyninst_aarch64;

extern Decoder* dec_gnu_x86_64;
extern Decoder* dec_gnu_aarch64;

extern Decoder* dec_llvm_x86_64;
extern Decoder* dec_llvm_aarch64;

extern Decoder* dec_capstone_x86_64;
extern Decoder* dec_capstone_aarch64;

extern Decoder* dec_null_x86_64;
extern Decoder* dec_null_aarch64;


#endif /* _DECODER_H_ */
