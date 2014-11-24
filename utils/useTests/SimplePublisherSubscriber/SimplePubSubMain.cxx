/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * fastrtps_LICENSE file included in this fastrtps distribution.
 *
 *************************************************************************
 * 
 * @file SimplePubSubMain.cpp
 * This file acts as a main entry point to the application.
 *
 * This file was generated by the tool fastrtpsgen.
 */


#include "fastrtps/rtps_all.h"
#include "SimplePublisher.h"
#include "SimpleSubscriber.h"
#include "SimplePubSubType.h"

int main(int argc, char** argv)
{
	RTPSLog::setVerbosity(EPROSIMA_WARNING_VERB_LEVEL);
	cout << "Starting " << endl;
	int type = 1;
	if (argc > 1)
	{
		if (strcmp(argv[1], "publisher") == 0)
		{
			type = 1;
		}
		else if (strcmp(argv[1], "subscriber") == 0)
		{
			type = 2;
		}
	}
	else
	{
		cout << "publisher OR subscriber argument needed" << endl;
		return 0;
	}
	
	// Register the type being used
	
	SimplePubSubType myType;
	RTPSDomain::registerType((TopicDataType*) &myType);
	
	switch(type)
	{
		case 1:
		{
			SimplePublisher mypub;
			if (mypub.init())
			{
				mypub.run();
			}
			break;
		}
		case 2:
		{
			SimpleSubscriber mysub;
			if (mysub.init())
			{
				mysub.run();
			}
			break;
		}
	}
	
	RTPSDomain::stopAll();
	
	return 0;
}
