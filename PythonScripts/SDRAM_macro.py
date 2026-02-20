import math

times = {
    "tRCD" : 15, 
    "tRP" : 15,
    "tWR" : 22, # 2 clk is just under 23 ns
    "tRC" : 63,
    "tRAS" : 42,
    "tXSR" : 70,
    "tMRD" : 22, # 2 clk is just under 23 ns
    }

CPU_CLK_HZ = 180_000_000
SDRAM_CLK_HZ = CPU_CLK_HZ // 2

SDRAM_CLK_PERIOD_NSEC = 1_000_000_000 // (SDRAM_CLK_HZ // 1000) # expected 11,111 us

# print(SDRAM_CLK_PERIOD_NSEC)

def ns_to_SDRAM_cycles(ns):
    return ns * 1000 // (SDRAM_CLK_PERIOD_NSEC) + 1

for time in times:
    print(f"{time} {str(times[time])} = {ns_to_SDRAM_cycles(times[time])}")
    # print(f"Real: {(times[time] * 1000) // (SDRAM_CLK_PERIOD_NSEC) + 1}")

# print(ns_to_SDRAM_cycles(tRCD))