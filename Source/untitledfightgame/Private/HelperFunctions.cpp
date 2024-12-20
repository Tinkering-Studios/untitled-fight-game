// Copyright - Tinkering Studios


#include "HelperFunctions.h"

bool UHelperFunctions::IsEditor()
{
#if WITH_EDITOR
	return true;
#else
	return false;
#endif
}
