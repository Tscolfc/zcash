// Copyright (c) 2015 The Bitcoin Core developers
// Copyright (c) 2020-2023 The Zcash developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or https://www.opensource.org/licenses/mit-license.php .

#include "bench.h"
#include "main.h"
#include "util/time.h"

// Sanity test: this should loop ten times, and
// min/max/average should be close to 200ms.
static void Sleep100ms(benchmark::State& state)
{
    while (state.KeepRunning()) {
        MilliSleep(100);
    }
}

BENCHMARK(Sleep100ms);

// Extremely fast-running benchmark:
#include <math.h>

volatile double sum = 10.0; // volatile, global so not optimized away

static void Trig(benchmark::State& state)
{
    double d = 0.01;
    while (state.KeepRunning()) {
        sum += sin(d);
        d += 10.000001;
    }
}

BENCHMARK(Trig);
