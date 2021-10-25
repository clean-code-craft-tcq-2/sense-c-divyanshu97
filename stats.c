#include "stats.h"
#include <math.h>

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats returnStats;
    int loopCntr;
    float total = 0;
    if(setlength<=0)
    {
    	returnStats.average = NAN;
    	returnStats.max = NAN;
    	returnStats.min = NAN;
    }
    else
    {
        returnStats.max = numberset[0];
        returnStats.min = numberset[0];
    	for(loopCntr=0;loopCntr<setlength;loopCntr++)
    	{
    		total += numberset[loopCntr];
    		if(returnStats.max < numberset[loopCntr])
    		{
    			returnStats.max = numberset[loopCntr];
    		}
    		else if(returnStats.min > numberset[loopCntr])
    		{
    			returnStats.min = numberset[loopCntr];
    		}
    	}
    	returnStats.average = total / (1.0 * setlength);
    }
    return returnStats;
}


void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
	if(maxThreshold < computedStats.max)
	{
		alerters[0]();
		alerters[1]();
	}
}