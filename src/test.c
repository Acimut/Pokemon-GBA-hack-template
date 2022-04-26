#include "global.h"
#include "event_data.h"


void test_func(void)
{
    u16 species;

    gSpecialVar_0x8004 = 0;

    if (FlagGet(FLAG_0x0AF))
    {
        gSpecialVar_0x8004 = 2;
        return;
    }

    if (gPlayerPartyCount)
    {
        for (int i = 0; i < gPlayerPartyCount; i++)
        {
            species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL);
            if (species == SPECIES_SQUIRTLE)
            {
                FlagSet(FLAG_0x0AF);
                gSpecialVar_0x8004 = 1;
                return;
            }
        }
    }
}

