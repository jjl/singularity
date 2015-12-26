# libsingularity

Improving security and benchmarking

## What does it do?

C and C++ would be a lot less annoying if we didn't care about
performance. The optimisers in modern compilers will generally do
everything they can to make things fast, even if that means something
we don't want to happen will happen.

This module provides workarounds for the optimiser for two use cases:

* Benchmarking
* Zeroing out data


```C
/**
 * May stop your compiler from optimising out some code
 * 
 * Useful to make benchmarks more reliable
 * 
 * @param void *p pointer to your obj
 * @return void *
 */
void *singularity(void *p);
/**
 * Zeroes out the memory pointed to by *p and returns p
 * 
 * A cop-out for platforms that don't support secure keyboard input
 * 
 * @param void *p pointer to your obj
 * @return void *
 */
 void *eat(void *p, size_t count);
 ```
 
## How does it work?

* Builds without optimisations
* (ab)uses volatile and asm

## What platforms does it run on?

In theory, just about anything that supports C. In practice, I've
tested it on Linux and would expect it to work also on FreeBSD, OSX
and Windows.

## This is pointless

No, it *would* be pointless, except the entire C toolchain is shit.

## Building/using (with Boost Build, recommended

First you need to pick the code for your compiler:

```
| Code    | Name                    |
| `clang` | Clang/LLVM              |
| `gcc`   | GNU Compiler Collection |
| `msvc`  | Microsoft Visual C++    |
```

There are a handful of other supported compilers here: http://www.boost.org/build/doc/html/bbv2/reference/tools.html#bbv2.reference.tools.compilers

We'll use clang for these examples, just swap the compiler code if you
use a different compiler.

1. Build shared library and run tests:

```
    b2 toolset=clang
```
2. Build static library
```
    b2 link=static singularity toolset=clang
```
Built files can be found in 'bin'.

## I don't like Boost Build

I'd love to support cmake as well (which can generate visual studio
project files). If you have expertise, please submit a pull request!

## Author and License

Written by James Laver, 2015

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

