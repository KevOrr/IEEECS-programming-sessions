#!/usr/bin/env python
import sys

adults = int(raw_input())

babies_0_to_14 = 0
babies_15_to_29 = 0
in_forest = 0

for i in range(365):
    just_matured = 0
    if i>0 and not i%15:
        just_matured = babies_15_to_29      // Babies mature after 30 days
        babies_15_to_29 = babies_0_to_14    // Become 15 days older after 15 days
        babies_0_to_14 = int(adults * 0.9)  // Bunnies double (-10% stillborn)

        in_forest += int(0.3 * just_matured)
        adults += int(0.7 * just_matured)

    if i>0 and not i%30:
        adults -= int(0.25 * adults)

    if i == 365 or not (adults or babies_15_to_29 or babies_0_to_14):
        break

sys.stdout.write(str(adults))
