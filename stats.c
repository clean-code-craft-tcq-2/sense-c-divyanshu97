#include "stats.h"
#include <math.h>

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    int i;
    float total = 0;
    if(setlength<=0)
    {
    	s.average = NAN;
    	s.max = NAN;
    	s.min = NAN;
    }
    else
    {
        s.max = numberset[0];
        s.min = numberset[0];
    	for(i=0;i<setlength;i++)
    	{
    		total += numberset[i];
    		if(s.max < numberset[i])
    		{
    			s.max = numberset[i];
    		}
    		else if(s.min > numberset[i])
    		{
    			s.min = numberset[i];
    		}
    	}
    	s.average = total / (1.0 * setlength);
    }
    return s;
}


void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
	if(maxThreshold < computedStats.max)
	{
		alerters[0]();
		alerters[1]();
	}
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
