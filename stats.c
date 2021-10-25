#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    int i;
    float total;
    if(setlength<=0)
    {
    	s.average = 0;
    	s.max =0;
    	s.min =0;
    }
    else
    {
        s.max = numberset[0];
        s.min = numberset[0];
    	for(i=0;i<setlength;i++)
    	{
    		total += numberset[setlength];
    		if(s.max < numberset[setlength])
    		{
    			s.max = numberset[setlength];
    		}
    		else if(s.min > numberset[setlength])
    		{
    			s.min = numberset[setlength];
    		}
    	}
    	s.average = total / (1.0 * setlength);
    }
    return s;
}


void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{

}


void emailAlerter()
{
	emailAlertCallCount++;
}

void ledAlerter()
{
	ledAlertCallCount++;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
